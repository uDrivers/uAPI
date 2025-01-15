#pragma once

/*
 * Platform-specific types go here. This is the default placeholder using
 * types from the standard headers.
 */

#ifdef UAPI_OVERRIDE_TYPES
#include "uapi_types.h"
#else

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

#include "../utilities/static_assert.h"

typedef uint8_t uapi_u8;
typedef uint16_t uapi_u16;
typedef uint32_t uapi_u32;
typedef uint64_t uapi_u64;

typedef uapi_u8 uapi_le8;
typedef uapi_u16 uapi_le16;
typedef uapi_u32 uapi_le32;
typedef uapi_u64 uapi_le64;

typedef uapi_u8 uapi_be8;
typedef uapi_u16 uapi_be16;
typedef uapi_u32 uapi_be32;
typedef uapi_u64 uapi_be64;

typedef int8_t uapi_i8;
typedef int16_t uapi_i16;
typedef int32_t uapi_i32;
typedef int64_t uapi_i64;

#define UAPI_TRUE true
#define UAPI_FALSE false
typedef bool uapi_bool;

#define UAPI_NULL NULL

typedef uintptr_t uapi_uintptr;
typedef uapi_uintptr uapi_phys_addr;
typedef uapi_uintptr uapi_virt_addr;
typedef size_t uapi_size;

typedef va_list uapi_va_list;
#define uapi_va_start va_start
#define uapi_va_end va_end
#define uapi_va_arg va_arg

typedef char uapi_char;

#define uapi_offsetof offsetof

/*
 * We use unsignd long long for 64-bit number formatting because 64-bit types
 * don't have a standard way to format them. The inttypes.h header is not
 * freestanding therefore it's not practical to force the user to define the
 * corresponding PRI macros. Moreover, unsigned long long  is required to be
 * at least 64-bits as per C99.
 */
UAPI_BUILD_BUG_ON_WITH_MSG(
    sizeof(unsigned long long) < 8,
    "unsigned long long must be at least 64 bits large as per C99"
);
#define UAPI_PRIu64 "llu"
#define UAPI_PRIx64 "llx"
#define UAPI_PRIX64 "llX"
#define UAPI_FMT64(val) ((unsigned long long)(val))

#endif
