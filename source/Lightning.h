#pragma once

// Common Lightning macros and declarations

#if defined(LIGHTNING_DLL_EXPORTS) && !defined(LIGHTNING_DLL_API)
#define LIGHTNING_DLL_API __declspec(dllexport) 
#elif !defined(LIGHTNING_DLL_API)
#define LIGHTNING_DLL_API __declspec(dllimport) 
#endif

#if defined(LIGHTNING_CAPI_DLL_EXPORTS) && !defined(LIGHTNING_CAPI_DLL_API)
#define LIGHTNING_CAPI_DLL_API __declspec(dllexport) 
#elif !defined(LIGHTNING_CAPI_DLL_API)
#define LIGHTNING_CAPI_DLL_API __declspec(dllimport) 
#endif
