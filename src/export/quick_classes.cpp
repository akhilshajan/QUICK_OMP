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
  ! This header file contains functions implementing the activities  of !
  ! classes in QUICK namespace.                                         !
  !---------------------------------------------------------------------!
*/
#include "quick_classes.h"

using namespace qk;

// functions belonging to quick class
quick::quick(void){quick_version="";}

// functions belonging to dataOperator class
template <typename T> 
std::vector<T>* dataOperator::Transfer(T *f90data, int length1, int length2){

  std::vector<T>* vec=new std::vector<T>(length1*length2);

  int idxf90=0;

  for(int j=0;j<length2;++j){
    for(int i=0;i<length1;++i){
      vec[ j * length1 + i ] = f90data[idxf90++];
    }
  }

  return vec;

}

// functions belonging to molecule class
// default constructor
molecule::molecule(void){
  molecule::natoms=0;
  molecule::atom_labels=NULL;
  molecule::coordinates=NULL;
  molecule::molecular_charge=0.0;
}


molecule::molecule(int natoms, char *atom_labels, double *coordinates, double molecular_charge){
  
}

