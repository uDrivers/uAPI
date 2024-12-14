#ifndef UAPI_LOG_VERSION
#define UAPI_LOG_VERSION 1
#endif

#if UAPI_LOG_VERSION != 1
#error log.h API version mismatch, make sure all uDrivers are using the same base
#endif

#ifndef UAPI_LOG_INCLUDED
#define UAPI_LOG_INCLUDED

#ifndef UAPI_KERNEL_API
#error this header should not be included directly, use kernel_api.h
#endif

#ifndef UAPI_WANTS_LOG
#error log.h is not used by any of the included uDrivers and should not be included
#endif

#include "platform/types.h"
#include "platform/compiler.h"

UAPI_BEGIN_DECLS

typedef enum uapi_log_level {
    UAPI_LOG_DEBUG = 5,
    UAPI_LOG_TRACE = 4,
    UAPI_LOG_INFO  = 3,
    UAPI_LOG_WARN  = 2,
    UAPI_LOG_ERROR = 1,
} uapi_log_level;

#ifndef UAPI_FORMATTED_LOGGING
void uapi_kernel_log(uapi_log_level, const uapi_char*);
#else
UAPI_PRINTF_DECL(2, 3)
void uapi_kernel_log(uapi_log_level, const uapi_char*, ...);
void uapi_kernel_vlog(uapi_log_level, const uapi_char*, uapi_va_list);
#endif

UAPI_END_DECLS

#endif
