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

typedef struct uapi_pci_address {
    uapi_u16 segment;
    uapi_u8 bus;
    uapi_u8 device;
    uapi_u8 function;
} uapi_pci_address;

UAPI_END_DECLS

#endif
