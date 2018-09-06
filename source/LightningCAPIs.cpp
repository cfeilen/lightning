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

HRESULT __cdecl MBMSetPinMode(unsigned int mappedPin, unsigned int mode, bool pullUp)
{
    auto res = g_pins.setPinMode(mappedPin, mode, pullUp);
    return res;
}

HRESULT __cdecl MBMSetPinState(unsigned int mappedPin, unsigned int state)
{
    auto res = g_pins.setPinState(mappedPin, state);
    return res;
}

HRESULT __cdecl MBMGetPinState(unsigned int mappedPin, unsigned int *state)
{
    ULONG value = 0;
    auto res = g_pins.getPinState(mappedPin, value);
    *state = value;
    return res;
}
