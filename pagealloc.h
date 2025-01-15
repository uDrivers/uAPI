#ifndef UAPI_PAGEALLOC_VERSION
#define UAPI_PAGEALLOC_VERSION 1
#endif

#if UAPI_PAGEALLOC_VERSION != 1
#error pagealloc.h API version mismatch, make sure all uDrivers are using the same base
#endif

#ifndef UAPI_PAGEALLOC_INCLUDED
#define UAPI_PAGEALLOC_INCLUDED

#ifndef UAPI_KERNEL_API
#error this header should not be included directly, use kernel_api.h
#endif

#ifndef UAPI_WANTS_PAGEALLOC
#error pagealloc.h is not used by any of the included uDrivers and should not be included
#endif

#include "platform/types.h"
#include "platform/compiler.h"

UAPI_BEGIN_DECLS

/*
 * Allocate 'count' physical pages with an alignment of 'align'.
 * 'max_phys_addr' specifies the maximum acceptible address of the
 * end of the last allocated page.
 */
uapi_phys_addr uapi_kernel_allocate_pages(
    uapi_size count, uapi_size align, uapi_phys_addr max_phys_addr
);

#ifndef UAPI_SIZED_FREES
void uapi_kernel_free_pages(uapi_phys_addr);
#else
void uapi_kernel_free_pages(uapi_phys_addr, uapi_size count_hint);
#endif

UAPI_END_DECLS

#endif
