__all__ = [
    "boresch",
    "bond",
    "distance",
    "positional",
]


def _to_atoms(mols, atoms):
    """
    Internal function used to convert `mols[atoms]` into a list
    of atoms
    """
    from ..mol import selection_to_atoms

    return selection_to_atoms(mols, atoms)


def boresch(
    mols,
    receptor,
    ligand,
    kr=None,
    ktheta=None,
    kphi=None,
    name: str = None,
    map=None,
):
    """
    Create a set of Boresch restraints that will hold the passed
    ligand in a its relative binding mode relative to the
    passed receptor. All of the atoms in both 'ligand' and
    'receptor' must be contained in 'mols'.

    The BoreschRestraint will be a set of six restraints between
    three identified ligand atoms, and three identified receptor
    atoms.

    1. A single distance restraint, with specified kr and r0 parameters
    2. Two angle restraints, with the specified two ktheta and theta0
       parameters
    3. Three torsion restraints, with the specified three kphi and phi0
       parameters

    This will create a single BoreschRestraint, which will be passed
    back in a BoreschRestraints object.

    If the force constants (kr, ktheta and kphi) are None, then they
    will have default values of 150 kcal mol-1 A-2 and
    150 kcal mol-1 rad-2

    The equilibium distances and angles are based on the current coordinates
    of that atoms
    """
    from .. import u
    from ..base import create_map
    from ..mm import BoreschRestraint, BoreschRestraints

    map = create_map(map)

    receptor = _to_atoms(mols, receptor)
    ligand = _to_atoms(mols, ligand)

    if len(receptor) != 3 or len(ligand) != 3:
        # Eventually will choose the best atoms from the receptor
        # and ligand...
        raise ValueError(
            "You need to provide 3 receptor atoms and 3 ligand atoms"
        )

    if kr is None:
        kr = u("150 kcal mol-1 A-2")
    else:
        kr = u(kr)

    _default_k = u("150 kcal mol-1 rad-2")

    if ktheta is None:
        ktheta = [_default_k, _default_k]
    elif type(ktheta) is not list:
        ktheta = 2 * [u(ktheta)]
    else:
        if len(ktheta) == 0:
            ktheta = [_default_k, _default_k]
        if len(ktheta) < 2:
            ktheta = 2 * [u(ktheta[0])]
        else:
            ktheta = [u(x) for x in ktheta[0:2]]

    if kphi is None:
        kphi = [_default_k, _default_k, _default_k]
    elif type(kphi) is not list:
        kphi = 3 * [u(kphi)]
    else:
        if len(kphi) == 0:
            kphi = [_default_k, _default_k, _default_k]
        elif len(kphi) == 1:
            kphi = 3 * [u(kphi[0])]
        elif len(kphi) == 2:
            kphi = [u(kphi[0]), u(kphi[1]), u(kphi[1])]
        else:
            kphi = [u(x) for x in kphi[0:3]]

    # r is | Ligand1 - Receptor1 | = distance(P1, P4)
    # thetaA = angle(R2, R1, L1) = angle(P2, P1, P4)
    # thetaB = angle(R1, L1, L2) = angle(P1, P4, P5)
    # phiA = dihedral(R3, R2, R1, L1) = dihedral(P3, P2, P1, P4)
    # phiB = dihedral(R2, R1, L1, L2) = dihedral(P2, P1, P4, P5)
    # phiC = dihedral(R1, L1, L2, L3) = dihedral(P1, P4, P5, P6)
    from .. import measure

    r0 = measure(ligand[0], receptor[0])
    theta0 = [
        measure(receptor[1], receptor[0], ligand[0]),
        measure(receptor[0], ligand[0], ligand[1]),
    ]
    phi0 = [
        measure(receptor[2], receptor[1], receptor[0], ligand[0]),
        measure(receptor[1], receptor[0], ligand[0], ligand[1]),
        measure(receptor[0], ligand[0], ligand[1], ligand[2]),
    ]

    mols = mols.atoms()

    b = BoreschRestraint(
        receptor=mols.find(receptor),
        ligand=mols.find(ligand),
        r0=r0,
        theta0=theta0,
        phi0=phi0,
        kr=kr,
        ktheta=ktheta,
        kphi=kphi,
    )

    if name is None:
        return BoreschRestraints(b)
    else:
        return BoreschRestraint(name, b)


def distance(
    mols, atoms0, atoms1, r0=None, k=None, name: str = None, map=None
):
    """
    Create a set of distance restraints from all of the atoms in 'atoms0'
    to all of the atoms in 'atoms1' where all atoms are
    contained in the container 'mols', using the
    passed values of the force constant 'k' and equilibrium
    bond length r0.

    These restraints will be per atom-atom distance. If a list of k and/or r0
    values are passed, then different values could be used for
    different atom-atom distances (assuming the same number as the number of
    atom-atom distances). Otherwise, all atom-atom distances will use the
    same parameters.

    If r0 is None, then the current atom-atom distance for
    each atom-atom pair will be used as the equilibium value.

    If k is None, then a default value of 150 kcal mol-1 A-2 will be used
    """
    from .. import u
    from ..base import create_map
    from ..mm import BondRestraint, BondRestraints

    map = create_map(map)

    if k is None:
        k = [u("150 kcal mol-1 A-2")]
    elif type(k) is list:
        k = [u(x) for x in k]
    else:
        k = [u(k)]

    atoms0 = _to_atoms(mols, atoms0)
    atoms1 = _to_atoms(mols, atoms1)

    if atoms0.is_empty() or atoms1.is_empty():
        raise ValueError("We need at least one atom in each group")

    while len(atoms0) < len(atoms1):
        atoms0 += atoms0[-1]

    while len(atoms1) < len(atoms0):
        atoms1 += atoms1[-1]

    if r0 is None:
        # calculate all of the current distances
        from .. import measure

        r0 = []
        for atom0, atom1 in zip(atoms0, atoms1):
            r0.append(measure(atom0, atom1))
    elif type(r0) is list:
        r0 = [u(x) for x in r0]
    else:
        r0 = [u(r0)]

    mols = mols.atoms()

    if name is None:
        restraints = BondRestraints()
    else:
        restraints = BondRestraints(name=name)

    for i, (atom0, atom1) in enumerate(zip(atoms0, atoms1)):
        idxs0 = mols.find(atom0)
        idxs1 = mols.find(atom1)

        if type(idxs0) is int:
            idxs0 = [idxs0]

        if type(idxs1) is int:
            idxs1 = [idxs1]

        if len(idxs0) == 0:
            raise KeyError(
                f"Could not find atom {atom0} in the molecules. Please ensure "
                "that 'mols' contains all of that atoms, or else we can't "
                "add the positional restraints."
            )

        if len(idxs1) == 0:
            raise KeyError(
                f"Could not find atom {atom1} in the molecules. Please ensure "
                "that 'mols' contains all of that atoms, or else we can't "
                "add the positional restraints."
            )

        if i < len(k):
            ik = k[i]
        else:
            ik = k[-1]

        if i < len(r0):
            ir0 = r0[i]
        else:
            ir0 = r0[-1]

        restraints.add(BondRestraint(idxs0[0], idxs1[0], ik, ir0))

    return restraints


def bond(*args, **kwargs):
    """
    Synonym for distance(), as a bond restraint is treated the same
    as a distance restraint
    """
    return distance(*args, **kwargs)


def positional(
    mols, atoms, k=None, r0=None, position=None, name: str = None, map=None
):
    """
    Create a set of position restraints for the atoms specified in
    'atoms' that are contained in the container 'mols', using the
    passed values of the force constant 'k' and flat-bottom potential
    well-width 'r0' for the restraints.

    These restraints will be per atom. If a list of k and/or r0
    values are passed, then different values could be used for
    different atoms (assuming the same number as the number of
    atoms). Otherwise, all atoms will use the same parameters.

    If 'r0' is not specified, then a simple harmonic restraint
    is used.

    If 'k' is not specified, then a default of 150 kcal mol-1 A-2
    will be used.
    """
    from .. import u
    from ..base import create_map
    from ..mm import PositionalRestraint, PositionalRestraints

    map = create_map(map)

    if k is None:
        k = [u("150 kcal mol-1 A-2")]
    elif type(k) is list:
        k = [u(x) for x in k]
    else:
        k = [u(k)]

    if r0 is None:
        r0 = [u("0")]
    elif type(r0) is list:
        r0 = [u(x) for x in r0]
    else:
        r0 = [u(r0)]

    atoms = _to_atoms(mols, atoms)

    mols = mols.atoms()

    if name is None:
        restraints = PositionalRestraints()
    else:
        restraints = PositionalRestraints(name=name)

    coords_prop = map["coordinates"]

    if position is not None:
        from ..maths import Vector

        if type(position) is not list:
            position = len(atoms) * [Vector.to_vector(position)]
        else:
            position = [Vector.to_vector(x) for x in position]

    for i, atom in enumerate(atoms.atoms()):
        idxs = mols.find(atom)

        if type(idxs) is int:
            idxs = [idxs]

        elif len(idxs) == 0:
            raise KeyError(
                f"Could not find atom {atom} in the molecules. Please ensure "
                "that 'mols' contains all of that atoms, or else we can't "
                "add the positional restraints."
            )

        if i < len(k):
            ik = k[i]
        else:
            ik = k[-1]

        if i < len(r0):
            ir0 = r0[i]
        else:
            ir0 = r0[-1]

        if position is None:
            restraints.add(
                PositionalRestraint(
                    idxs[0], atom.property(coords_prop), ik, ir0
                )
            )
        else:
            restraints.add(PositionalRestraint(idxs[0], position[i], ik, ir0))

    return restraints
