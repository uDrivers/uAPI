#ifndef UAPI_PCI_VERSION
#define UAPI_PCI_VERSION 1
#endif

#if UAPI_PCI_VERSION != 1
#error pci.h API version mismatch, make sure all uDrivers are using the same base
#endif

#ifndef UAPI_PCI_INCLUDED
#define UAPI_PCI_INCLUDED

#ifndef UAPI_KERNEL_API
#error this header should not be included directly, use kernel_api.h
#endif

#ifndef UAPI_WANTS_PCI
#error pci.h is not used by any of the included uDrivers and should not be included
#endif

#include "platform/types.h"
#include "platform/compiler.h"
#include "types.h"
#include "status.h"

UAPI_BEGIN_DECLS

/*
 * Open a PCI device at 'address'. The returned 'out_handle' may be used for
 * all compiled-in uAPI PCI functions.
 */
uapi_status uapi_kernel_pci_device_open(
    uapi_pci_address *address, uapi_handle *out_handle
);

/*
 * Read & write PCI configuration space for a previously open PCI device handle.
 *
 * NOTE:
 * 'byte_width' is ALWAYS one of 1, 2, 4. Since PCI registers are 32 bits wide
 * this must be able to handle e.g. a 1-byte access by reading at the nearest
 * 4-byte aligned offset below, then masking the value to select the target
 * byte.
 */
uapi_status uapi_kernel_pci_cfg_read(
    uapi_handle, uapi_size offset, uapi_u8 byte_width, uapi_u64 *value
);
uapi_status uapi_kernel_pci_cfg_write(
    uapi_handle, uapi_size offset, uapi_u8 byte_width, uapi_u64 value
);

/*
 * Attach an opaque private context 'ctx' to a pci device handle,
 * which can be retrieved later via the getter.
 */
uapi_status uapi_kernel_pci_set_ctx(uapi_handle, void *ctx);
void *uapi_kernel_pci_get_ctx(uapi_handle);

UAPI_END_DECLS

#endif
