/*
  !---------------------------------------------------------------------!
  ! Written by Madu Manathunga on 05/19/2021                            !
  !                                                                     !
  ! Copyright (C) 2020-2021 Merz lab                                    !
  ! Copyright (C) 2020-2021 Götz lab                                    !
  !                                                                     !
  ! This Source Code Form is subject to the terms of the Mozilla Public !
  ! License, v. 2.0. If a copy of the MPL was not distributed with this !
  ! file, You can obtain one at http://mozilla.org/MPL/2.0/.            !
  !_____________________________________________________________________!

  !---------------------------------------------------------------------!
  ! This header file contains functions implementing the activities  of !
  ! classes in QUICK namespace.                                         !
  !---------------------------------------------------------------------!
*/
#include "quick_classes.h"

using namespace qk;

/*
  ---------------------------- functions belonging to quick class -----------------------------
*/

// constructor
quick::quick(void){quick_version="";}

// destructor
quick::~quick(void){}

/*
  ------------------------ functions belonging to dataOperator class --------------------------
*/

template <typename T> 
std::vector<T>* dataOperator::Transfer(T *f90data, int length1, int length2){

  std::vector<T>* vec=NULL;

  if(f90data != NULL){

    vec = new std::vector<T>(length1*length2);
 
    int idxf90=0;
 
    for(int j=0;j<length2;++j){
      for(int i=0;i<length1;++i){
        vec->push_back(f90data[idxf90++]);
      }
    }

  }

  return vec;

}

/* get a list of symbols when a list of integers from f90 is given. Note that we correct
   the index by deducting each index by one. */
std::vector<std::string>* dataOperator::GetAtomSymbol(int *f90data, int length){

  std::vector<std::string>* vec=new std::vector<std::string>(length);

  for(int i=0; i<length; ++i){
    vec->push_back(atom_symbols[f90data[i]-1]);
  }  

}

/*
  -------------------------- functions belonging to molecule class -------------------------------
*/

// default constructor
molecule::molecule(void){
  molecule::natoms=0;
  molecule::atom_labels=NULL;
  molecule::coordinates=NULL;
  molecule::molecular_charge=0.0;
}

/* construct with number of atoms, atom types, cartesian coordinates, molecular charge and multiplicity.
*/
molecule::molecule(int natoms, int *iattype, double *coordinates, double molecular_charge){

  this->natoms=natoms; 
  this->atom_labels=GetAtomSymbol(iattype, natoms);  
  this->coordinates=Transfer(coordinates, natoms, 3);
  this->molecular_charge=molecular_charge;

}

// destructor
molecule::~molecule(void){
  SAFE_DELETE(this->atom_labels);
  SAFE_DELETE(this->coordinates);
}

/*
  -------------------------- functions belonging to property class -------------------------------
*/

// default constructor
property::property(void){
  property::calc = NULL;
  property::scf_prop = NULL;
  property::mp2 = NULL;
}

/* construct object with only calculation information where nbasis, nmo, nalpha, nbeta stand for
   number of basis functions, number of molecular orbitals, number of alpha and beta electrons.
   Note that we are using constructor delegation here. */
property::property(int nbasis, int nmo, int nalpha, int nbeta) : property::property(){
  property::calc= new calcInfoStruct{nbasis, nmo, nalpha, nbeta};
}

/* construct object with calculation and hf information where nbasis, nmo, nalpha, nbeta stand for
   number of basis functions, number of molecular orbitals, number of alpha and beta electrons.
   For dipole moment, number of atoms must be also specified. */
property::property(int nbasis, int nmo, int nalpha, int nbeta, double scf_one_electron_energy,\
                   double scf_two_electron_energy, double nuclear_repulsion_energy, double scf_total_energy,\
                   int scf_iterations, int natoms=0, double *scf_dipole_moment=NULL) : property::property(nbasis, \
                   nmo, nalpha, nbeta){

  property::scf_prop = new scfInfoStruct{scf_one_electron_energy, scf_two_electron_energy, nuclear_repulsion_energy,\
                                         0.0, NULL, scf_total_energy, scf_iterations};
  if(scf_dipole_moment != NULL){
    property::scf_prop -> scf_dipole_moment = Transfer(scf_dipole_moment, natoms, 3);
  }

}

/* construct object with calculation and dft information where nbasis, nmo, nalpha, nbeta stand for
   number of basis functions, number of molecular orbitals, number of alpha and beta electrons.
   For dipole moment, number of atoms must be also specified. */
property::property(int nbasis, int nmo, int nalpha, int nbeta, double scf_one_electron_energy,\
                   double scf_two_electron_energy, double nuclear_repulsion_energy, double scf_xc_energy,\
                   double scf_total_energy, int scf_iterations, int natoms=0, double *scf_dipole_moment=NULL)\
                   : property::property(nbasis, nmo, nalpha, nbeta, scf_one_electron_energy, scf_two_electron_energy,\
                     nuclear_repulsion_energy, scf_total_energy, scf_iterations, natoms, scf_dipole_moment){

  property::scf_prop -> scf_xc_energy = scf_xc_energy;
 
}

/* construct object with calculation and mp2 information where nbasis, nmo, nalpha, nbeta stand for
   number of basis functions, number of molecular orbitals, number of alpha and beta electrons.
   For dipole moment, number of atoms must be also specified. */
property::property(int nbasis, int nmo, int nalpha, int nbeta, double scf_one_electron_energy,\
                   double scf_two_electron_energy, double nuclear_repulsion_energy, double scf_total_energy, \
                   int scf_iterations, double mp2_correlation_energy, int natoms=0, double *scf_dipole_moment=NULL)\
                   : property::property(nbasis, nmo, nalpha, nbeta, scf_one_electron_energy, scf_two_electron_energy,\
                     nuclear_repulsion_energy, scf_total_energy, scf_iterations, natoms, scf_dipole_moment){

  property::mp2 = new mp2InfoStruct{mp2_correlation_energy, (mp2_correlation_energy+scf_total_energy)};

}

// destructor
property::~property(){

  SAFE_DELETE(property::calc);
  SAFE_DELETE(property::scf_prop -> scf_dipole_moment);  
  SAFE_DELETE(property::scf_prop);
  SAFE_DELETE(property::mp2);

}
