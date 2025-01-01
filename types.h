#ifndef UAPI_TYPES_VERSION
#define UAPI_TYPES_VERSION 1
#endif

#if UAPI_TYPES_VERSION != 1
#error types.h API version mismatch, make sure all uDrivers are using the same base
#endif

#ifndef UAPI_TYPES_INCLUDED
#define UAPI_TYPES_INCLUDED

#include "platform/types.h"
#include "platform/compiler.h"

UAPI_BEGIN_DECLS

typedef void *uapi_handle;

UAPI_END_DECLS

#endif
