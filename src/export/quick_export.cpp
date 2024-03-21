/*
  !---------------------------------------------------------------------!
  ! Written by Madu Manathunga on 05/18/2020                            !
  !                                                                     !
  ! Copyright (C) 2020-2021 Merz lab                                    !
  ! Copyright (C) 2020-2021 Götz lab                                    !
  !                                                                     !
  ! This Source Code Form is subject to the terms of the Mozilla Public !
  ! License, v. 2.0. If a copy of the MPL was not distributed with this !
  ! file, You can obtain one at http://mozilla.org/MPL/2.0/.            !
  !_____________________________________________________________________!

  !---------------------------------------------------------------------!
  ! Driver for exporting data into different formats.                   !
  !---------------------------------------------------------------------!
*/

#include <iostream>
#include <fstream>
#include "quick_classes.h"

using namespace std;
using namespace qk;

ofstream *expstream = NULL;
quick *qkobj = NULL;


// function to initialize exporter
extern "C" void export_init_(char *fname){

  expstream = new ofstream();
  expstream->open(fname);

  qkobj = new quick("QUICK-21.03");

}


// funtion to finalize exporter
extern "C" void export_finalize_(){

  expstream -> close();
  delete expstream;
  delete qkobj;

}

