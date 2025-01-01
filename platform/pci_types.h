#pragma once

#include "../platform/types.h"

typedef void *uapi_pci_handle;

typedef struct uapi_pci_address {
    uapi_u16 segment;
    uapi_u8 bus;
    uapi_u8 device;
    uapi_u8 function;
} uapi_pci_address;
