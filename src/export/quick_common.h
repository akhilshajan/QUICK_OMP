/*
  !---------------------------------------------------------------------!
  ! Written by Madu Manathunga on 05/28/2021                            !
  !                                                                     !
  ! Copyright (C) 2020-2021 Merz lab                                    !
  ! Copyright (C) 2020-2021 Götz lab                                    !
  !                                                                     !
  ! This Source Code Form is subject to the terms of the Mozilla Public !
  ! License, v. 2.0. If a copy of the MPL was not distributed with this !
  ! file, You can obtain one at http://mozilla.org/MPL/2.0/.            !
  !_____________________________________________________________________!

  !---------------------------------------------------------------------!
  ! This header file contains common variables and preprocessor flags   !
  ! useful for other source code.                                       !
  !---------------------------------------------------------------------!
*/
#ifndef QUICK_COMMON
#define QUICK_COMMON

#define SAFE_DELETE(pointer) if( pointer != NULL) { delete pointer; pointer = NULL;}

#endif
