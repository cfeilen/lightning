// Copyright (c) Microsoft Open Technologies, Inc.  All rights reserved.  
// Licensed under the BSD 2-Clause License.  
// See License.txt in the project root for license information.

#pragma once

#include <Windows.h>
#include "Lightning.h"
#include "BoardPins.h"

extern "C" {

/// Verify the function of each MBM pin
LIGHTNING_DLL_API HRESULT __cdecl MBMVerifyPinFunction(unsigned int mappedPin, unsigned int function, unsigned int lockAction);

} // extern "C"
