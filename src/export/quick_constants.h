/*
  !---------------------------------------------------------------------!
  ! Written by Madu Manathunga on 05/21/2021                            !
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

#ifndef QUICK_CONSTANTS_H 
#define QUICK_CONSTANTS_H
#include <string>

namespace qk{
const std::string atom_symbols[92]={"H",                                                                                              "He", 
                  "Li", "B",                                                                    "C", "N", "O", "F", "NE",
                  "Na", "Mg",                                                           "Al", "Si", "P", "S", "Cl", "Ar",
                  "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe","Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", 
                  "Rb", "Sr", "Y", "Zr", "Nb", "Mo","Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te",  "I", "Xe", 
                  "Cs", "Ba", "La", 
                                  "Ce","Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy","Ho", "Er", "Tm", "Yb", "Lu", 
                                  "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", 
                  "Fr", "Ra", "Ac", 
                  "Th", "Pa", "U" };

}
#endif
