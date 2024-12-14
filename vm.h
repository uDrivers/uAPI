#ifndef UAPI_VM_VERSION
#define UAPI_VM_VERSION 1
#endif

#if UAPI_VM_VERSION != 1
#error vm.h API version mismatch, make sure all uDrivers are using the same base
#endif

#ifndef UAPI_VM_INCLUDED
#define UAPI_VM_INCLUDED

#ifndef UAPI_KERNEL_API
#error this header should not be included directly, use kernel_api.h
#endif

#ifndef UAPI_WANTS_VM
#error vm.h is not used by any of the included uDrivers and should not be included
#endif

#include "platform/types.h"
#include "platform/compiler.h"

UAPI_BEGIN_DECLS

typedef enum uapi_caching {
    /*
     * Automatically deduce caching type by inspecting the system memory map.
     * (e.g. if the region happens to reside inside normal RAM, map as WB)
     */
    UAPI_CACHING_AUTO = 0,

    UAPI_CACHING_WB,
    UAPI_CACHING_WT,
    UAPI_CACHING_WC,
    UAPI_CACHING_UC,

    UAPI_CACHING_MMIO,

    /*
     * A stronger version of CACHING_MMIO, with an arch-specific implementation.
     * E.g. for the ARM architecture you may map MMIO as follows:
     * CACHING_MMIO -> nGnRE
     * CACHING_MMIO_STRONG -> nGnRnE
     */
    UAPI_CACHING_MMIO_STRONG,
} uapi_caching;

typedef enum uapi_access_type {
    UAPI_ACCESS_TYPE_READ = 1 << 0,
    UAPI_ACCESS_TYPE_WRITE = 1 << 1,
    UAPI_ACCESS_TYPE_EXECUTE = 1 << 2,
} uapi_access_type;

/*
 * Map physical memory at 'addr' of 'len' bytes with requested caching mode and
 * a permission bitmask.
 */
void *uapi_kernel_map(
    uapi_phys_addr addr, uapi_size len,
    uapi_caching, uapi_access_type
);
void uapi_kernel_unmap(void *addr, uapi_size len);

UAPI_END_DECLS

#endif
