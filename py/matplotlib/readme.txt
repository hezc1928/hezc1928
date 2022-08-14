/*
partqgp is the particle list in QGP phase; parthg is the one in HG phase.
The first index in those two lists represents partice id for differnt particles.
The meanings of the second index is :
 0 for particle mass; MeV
 1 for baryon number;
 2 for isospin;
 3 for spin;
 4 for signature of Boson and Fermion: value -1 for boson, value 1 for fermion.
 5 for signature of the antiparticle; 0 no, 1 yes;
 6 for degeneracy of the particles. Even if for some particles the degeneracy can
   be derived from isospin and spin, we give the degeneracy explictly.
*/
