#pragma once

/*
 * Compiler-specific attributes/macros go here. This is the default placeholder
 * that should work for MSVC/GCC/clang.
 */

#ifdef UAPI_OVERRIDE_COMPILER
#include "uapi_compiler.h"
#else

#ifdef __cplusplus
#define UAPI_BEGIN_DECLS extern "C" {
#define UAPI_END_DECLS }
#else
#define UAPI_BEGIN_DECLS
#define UAPI_END_DECLS
#endif

#define UAPI_ALIGN(x) __declspec(align(x))

#ifdef _MSC_VER
    #include <intrin.h>

    #define UAPI_ALWAYS_INLINE __forceinline

    #define UAPI_PACKED(decl)  \
        __pragma(pack(push, 1)) \
        decl;                   \
        __pragma(pack(pop))
#else
    #define UAPI_ALWAYS_INLINE inline __attribute__((always_inline))
    #define UAPI_PACKED(decl) decl __attribute__((packed));
#endif

#ifdef __GNUC__
    #define uapi_unlikely(expr) __builtin_expect(!!(expr), 0)
    #define uapi_likely(expr)   __builtin_expect(!!(expr), 1)

    #if __has_attribute(__fallthrough__)
        #define UAPI_FALLTHROUGH __attribute__((__fallthrough__))
    #endif

    #define UAPI_MAYBE_UNUSED __attribute__ ((unused))

    #define UAPI_NO_UNUSED_PARAMETER_WARNINGS_BEGIN             \
        _Pragma("GCC diagnostic push")                           \
        _Pragma("GCC diagnostic ignored \"-Wunused-parameter\"")

    #define UAPI_NO_UNUSED_PARAMETER_WARNINGS_END \
        _Pragma("GCC diagnostic pop")

    #ifdef __clang__
        #define UAPI_PRINTF_DECL(fmt_idx, args_idx) \
            __attribute__((format(printf, fmt_idx, args_idx)))
    #else
        #define UAPI_PRINTF_DECL(fmt_idx, args_idx) \
            __attribute__((format(gnu_printf, fmt_idx, args_idx)))
    #endif
#else
    #define uapi_unlikely(expr) expr
    #define uapi_likely(expr)   expr

    #define UAPI_MAYBE_UNUSED

    #define UAPI_NO_UNUSED_PARAMETER_WARNINGS_BEGIN
    #define UAPI_NO_UNUSED_PARAMETER_WARNINGS_END

    #define UAPI_PRINTF_DECL(fmt_idx, args_idx)
#endif

#ifndef UAPI_FALLTHROUGH
    #define UAPI_FALLTHROUGH do {} while (0)
#endif

#ifndef UAPI_POINTER_SIZE
    #ifdef _WIN32
        #ifdef _WIN64
            #define UAPI_POINTER_SIZE 8
        #else
            #define UAPI_POINTER_SIZE 4
        #endif
    #elif defined(__GNUC__)
        #define UAPI_POINTER_SIZE __SIZEOF_POINTER__
    #else
        #error Failed to detect pointer size
    #endif
#endif

#endif
