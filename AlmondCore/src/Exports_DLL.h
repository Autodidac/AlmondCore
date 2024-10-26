// Exports_DLL.h
#pragma once

#ifdef _WIN32
// To build Irrlicht as a static library, you must define _IRR_STATIC_LIB_ in both the
// Irrlicht build, *and* in the user application, before #including <irrlicht.h>
    #ifndef ENTRYPOINT_STATICLIB
        #ifdef ENTRYPOINT_DLL_EXPORTS
            #define ENTRYPOINTLIBRARY_API __declspec(dllexport)
        #else
            #define ENTRYPOINTLIBRARY_API __declspec(dllimport)
        #endif
    #else
        #define ENTRYPOINTLIBRARY_API
    #endif
#endif

/*
// Declare the calling convention.
#if defined(_STDCALL_SUPPORTED)
    #define ALECALLCONV __stdcall
#else
    #define ALECALLCONV __cdecl
#endif // STDCALL_SUPPORTED

// Force symbol export in shared libraries built with gcc.
#if (__GNUC__ >= 4) && !defined(ENTRYPOINT_STATICLIB) && defined(ENTRYPOINT_DLL_EXPORTS)
    #define ALMOND_API __attribute__ ((visibility("default")))
#else
    #define ALMOND_API
#endif
*/
