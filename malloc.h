#ifndef UAPI_MALLOC_VERSION
#define UAPI_MALLOC_VERSION 1
#endif

#if UAPI_MALLOC_VERSION != 1
#error malloc.h API version mismatch, make sure all uDrivers are using the same base
#endif

#ifndef UAPI_MALLOC_INCLUDED
#define UAPI_MALLOC_INCLUDED

#ifndef UAPI_KERNEL_API
#error this header should not be included directly, use kernel_api.h
#endif

#ifndef UAPI_WANTS_MALLOC
#error malloc.h is not used by any of the included uDrivers and should not be included
#endif

#include "platform/types.h"
#include "platform/compiler.h"

UAPI_BEGIN_DECLS

/*
 * Allocate a block of memory of 'size' bytes.
 * The contents of the allocated memory are unspecified.
 */
void *uapi_kernel_alloc(uapi_size size);

/*
 * Allocate a block of memory of 'count' * 'size' bytes.
 * The returned memory block is expected to be zero-filled.
 */
void *uapi_kernel_calloc(uapi_size count, uapi_size size);

/*
 * Free a previously allocated memory block.
 *
 * 'mem' might be a NULL pointer. In this case, the call is assumed to be a
 * no-op.
 *
 * An optionally enabled 'size_hint' parameter contains the size of the original
 * allocation. Note that in some scenarios this incurs additional cost to
 * calculate the object size.
 */
#ifndef UAPI_SIZED_FREES
void uapi_kernel_free(void *mem);
#else
void uapi_kernel_free(void *mem, uapi_size size_hint);
#endif

UAPI_END_DECLS

#endif
