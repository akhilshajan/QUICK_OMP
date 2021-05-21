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

#include <string>
#include <vector>

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
    // templates to transfer data from f90 arrays into C++ vectors
    template <typename T> 
    static std::vector<T>* Transfer(T *f90data, int length1=1, int length2=1);
    
};


// This class represents a molecule and stores its properties.
class molecule: public dataOperator{

  public:
    // Fields 
    unsigned int natoms;                     // number of atoms
    std::vector<std::string> *atom_labels;   // list of atomic symbols
    std::vector<double> *coordinates;        // vector of cartesian coordinates, (3*natoms)
    double molecular_charge;                 // total charge of the molecule

    // constructors
    molecule(void);
    molecule(int natoms, char *atom_labels, double *coordinates, double molecular_charge);

    // destructor
    ~molecule(void);

};


}

