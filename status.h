#ifndef UAPI_STATUS_VERSION
#define UAPI_STATUS_VERSION 1
#endif

#if UAPI_STATUS_VERSION != 1
#error status.h API version mismatch, make sure all uDrivers are using the same base
#endif

#ifndef UAPI_STATUS_INCLUDED
#define UAPI_STATUS_INCLUDED

#include "platform/types.h"
#include "platform/compiler.h"

UAPI_BEGIN_DECLS

#ifndef UAPI_STATUS_BASE
#define UAPI_STATUS_BASE 0
#endif

typedef enum uapi_status {
    UAPI_STATUS_OK = UAPI_STATUS_BASE,
    UAPI_STATUS_MAPPING_FAILED,
    UAPI_STATUS_OUT_OF_MEMORY,
    UAPI_STATUS_BAD_CHECKSUM,
    UAPI_STATUS_NOT_FOUND,
    UAPI_STATUS_INVALID_ARGUMENT,
    UAPI_STATUS_UNIMPLEMENTED,
    UAPI_STATUS_ALREADY_EXISTS,
    UAPI_STATUS_INTERNAL_ERROR,
    UAPI_STATUS_TIMEOUT,
} uapi_status;

UAPI_END_DECLS

#endif
