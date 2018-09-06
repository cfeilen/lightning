// Copyright (c) Microsoft Open Technologies, Inc.  All rights reserved.  
// Licensed under the BSD 2-Clause License.  
// See License.txt in the project root for license information.

#pragma once

#include <Windows.h>
#include "Lightning.h"
#include "BoardPins.h"

extern "C" {

/// Verify the function of each MBM pin
LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMVerifyPinFunction(unsigned int mappedPin, unsigned int function, unsigned int lockAction);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMSetPinMode(unsigned int mappedPin, unsigned int mode, bool pullUp);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMSetPinState(unsigned int mappedPin, unsigned int state);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMGetPinState(unsigned int mappedPin, unsigned int *state);

} // extern "C"
