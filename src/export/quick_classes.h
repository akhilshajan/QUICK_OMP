/*
  !---------------------------------------------------------------------!
  ! Written by Madu Manathunga on 05/19/2020                            !
  !                                                                     !
  ! Copyright (C) 2020-2021 Merz lab                                    !
  ! Copyright (C) 2020-2021 Götz lab                                    !
  !                                                                     !
  ! This Source Code Form is subject to the terms of the Mozilla Public !
  ! License, v. 2.0. If a copy of the MPL was not distributed with this !
  ! file, You can obtain one at http://mozilla.org/MPL/2.0/.            !
  !_____________________________________________________________________!

  !---------------------------------------------------------------------!
  ! This header file contains class declarations of QUICK namespace.    !
  ! Note that we use OOP paradigm with STL in order to make use of nice !
  ! C++ libraries out there. Class definitions are given in             !
  ! quick_classes.cpp source file.                                      !
  !---------------------------------------------------------------------!
*/

#ifndef QUICK_CLASSES_H
#define QUICK_CLASSES_H
#include <string>
#include <vector>
#include "quick_common.h"
#include "quick_constants.h"

namespace qk{

class quick{

  // private fields
  std::string quick_version;
   
  public:
    // constructor
    quick(void);

    //destructor
    ~quick(void);

};


class dataOperator{

  public:
    // template to transfer data from f90 arrays into C++ vectors
    template <typename T> 
    static std::vector<T>* Transfer(T *f90data, int length1=1, int length2=1);
    
    // get a list of string/char symbols when a list of integers from f90 array is given
    static std::vector<std::string>* GetAtomSymbol(int *f90data, int length);
};


// This class represents a molecule and stores its properties.
class molecule: public dataOperator{

  public:
    // Fields 
    unsigned int natoms;                     // number of atoms
    std::vector<std::string> *atom_labels;   // list of atomic symbols
    std::vector<double> *coordinates;        // vector of cartesian coordinates, (3*natoms)
    double molecular_charge;                 // total charge of the molecule
    double molecular_multiplicity;           // the overall multiplicity of molecule

    // constructors
    molecule(void);
    molecule(int natoms, int *iattype, double *coordinates, double molecular_charge);

    // destructor
    ~molecule(void);

};


// structure tags required for properties class
// calculation information
struct calcInfoStruct{
  int nbasis;
  int nmo;
  int nalpha;
  int nbeta;
};

// hf/dft scf information
struct scfInfoStruct{
  double scf_one_electron_energy;
  double scf_two_electron_energy;
  double nuclear_repulsion_energy;
  double scf_xc_energy;
  std::vector<double> *scf_dipole_moment;
  double scf_total_energy;
  int scf_iterations;
};

// mp2 information
struct mp2InfoStruct{
  double mp2_correlation_energy;
  double mp2_total_energy;  
};

// class for valid quantum chemistry properties
class property: public dataOperator{
  public:
    // fields
    calcInfoStruct *calc;
    scfInfoStruct *scf_prop;
    mp2InfoStruct *mp2;

    //constructors
    property(void);

    // constructor with basic calculation information
    property(int nbasis, int nmo, int nalpha, int nbeta);

    // construct with hf information
    property(int nbasis, int nmo, int nalpha, int nbeta, double scf_one_electron_energy,\
             double scf_two_electron_energy, double nuclear_repulsion_energy, double scf_total_energy,\
             int scf_iterations, int natoms, double *scf_dipole_moment);

    // construct with dft information
    property(int nbasis, int nmo, int nalpha, int nbeta, double scf_one_electron_energy,\
             double scf_two_electron_energy, double nuclear_repulsion_energy, double scf_xc_energy,\
             double scf_total_energy, int scf_iterations, int natoms, double *scf_dipole_moment);

   // construct with mp2 information
    property(int nbasis, int nmo, int nalpha, int nbeta, double scf_one_electron_energy,\
             double scf_two_electron_energy, double nuclear_repulsion_energy, double scf_total_energy, \
             int scf_iterations, double mp2_correlation_energy, int natoms, double *scf_dipole_moment);

    //destructor;
    ~property(void);

};

// class for wavefunction properties
class wavefunction{
  public:
    std::vector<double> *scf_orbitals_a;    // SCF alpha-spin orbitals in the AO basis.
    std::vector<double> *scf_orbitals_b;    // SCF beta-spin orbitals in the AO basis.	
    std::vector<double> *scf_density_a;     // SCF alpha-spin density in the AO basis.	
    std::vector<double> *scf_density_b;     // SCF beta-spin density in the AO basis.	
    std::vector<double> *scf_eigenvalues_a; // SCF alpha-spin orbital eigenvalues.	
    std::vector<double> *scf_eigenvalues_b; // SCF beta-spin orbital eigenvalues.	
    std::vector<double> *scf_occupations_a; // SCF alpha-spin orbital occupations.	
    std::vector<double> *scf_occupations_b; // SCF beta-spin orbital occupations.	

};

class hamiltonian{

  public:
    std::vector<double> *core_a;     // Alpha-spin core (one-electron) Hamiltonian in the AO basis.	
    std::vector<double> *core_b;     // Beta-spin core (one-electron) Hamiltonian in the AO basis.
    std::vector<double> *fock_a;     // SCF alpha-spin Fock matrix in the AO basis.      
    std::vector<double> *fock_b;     // SCF beta-spin Fock matrix in the AO basis.     

};


class basisSet{


};

}

#endif
