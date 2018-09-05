// Copyright (c) Microsoft Open Technologies, Inc.  All rights reserved.  
// Licensed under the BSD 2-Clause License.  
// See License.txt in the project root for license information.

#include "pch.h"

#include "LightningCAPIs.h"

HRESULT __cdecl MBMVerifyPinFunction(unsigned int mappedPin, unsigned int function, unsigned int lockAction)
{
    auto res = g_pins.verifyPinFunction(mappedPin, function, static_cast<BoardPinsClass::FUNC_LOCK_ACTION>(lockAction));
    return res;
}
