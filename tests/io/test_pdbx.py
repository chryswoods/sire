import sire as sr

import pytest


def _assert_equal(v0, v1, tol):
    assert v0.x() == pytest.approx(v1.x(), tol)
    assert v0.y() == pytest.approx(v1.y(), tol)
    assert v0.z() == pytest.approx(v1.z(), tol)


@pytest.mark.skipif(
    "gemmi" not in sr.convert.supported_formats(), reason="gemmi not available"
)
def test_pdbx(tmpdir, ala_mols):
    mols = ala_mols

    dir = tmpdir.mkdir("test_pdbx")

    f = sr.save(mols, dir.join("test"), format=["pdbx"])

    mols2 = sr.load(f)

    assert mols.num_molecules() == mols2.num_molecules()
    assert mols.num_atoms() == mols2.num_atoms()

    assert len(mols.bonds()) == len(mols2.bonds())

    for atom0, atom1 in zip(mols.atoms(), mols2.atoms()):
        assert atom0.name() == atom1.name()
        assert atom0.number() == atom1.number()
        assert atom0.element() == atom1.element()
        assert atom0.residue().name() == atom1.residue().name()
        assert atom0.residue().number() == atom1.residue().number()
        _assert_equal(atom0.coordinates(), atom1.coordinates(), 1e-6)
