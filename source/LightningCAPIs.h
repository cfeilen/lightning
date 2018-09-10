// Copyright (c) Microsoft Open Technologies, Inc.  All rights reserved.  
// Licensed under the BSD 2-Clause License.  
// See License.txt in the project root for license information.

#pragma once

#include <Windows.h>
#include "Lightning.h"
#include "BoardPins.h"

extern "C" {

LIGHTNING_CAPI_DLL_API HRESULT __cdecl IsLightningEnabled(bool *result);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMVerifyPinFunction(unsigned int mappedPin, unsigned int function, unsigned int lockAction);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMSetPinMode(unsigned int mappedPin, unsigned int mode, bool pullUp);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMSetPinState(unsigned int mappedPin, unsigned int state);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMGetPinState(unsigned int mappedPin, unsigned int *state);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMI2cInit(unsigned int busNumber, int slaveAddress, bool fastMode, int *handle);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMI2cClose(int handle);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMI2cWrite(int handle, unsigned char *buffer, int length);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMI2cWritePartial(int handle, unsigned char *buffer, int length, unsigned int *bytesTransferred, unsigned int *status);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMI2cRead(int handle, unsigned char *buffer, int length);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMI2cReadPartial(int handle, unsigned char *buffer, int length, unsigned int *bytesTransferred, unsigned int *status);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMI2cWriteRead(int handle, unsigned char *writeBuffer, int writeBufferLength, unsigned char *readBuffer, int readBufferLength);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMI2cWriteReadPartial(int handle, unsigned char *writeBuffer, int writeBufferLength, unsigned char *readBuffer, int readBufferLength,
    unsigned int *bytesTransferred, unsigned int *status);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMSpiInit(unsigned int mode, int clockFrequency, int dataBitLength, int *handle);

LIGHTNING_CAPI_DLL_API HRESULT __cdecl MBMSpiClose(int handle);

} // extern "C"
