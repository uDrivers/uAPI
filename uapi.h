#ifndef UAPI_KERNEL_API
#error this header should not be included directly, use kernel_api.h
#endif

#ifdef UAPI_WANTS_LOG
#include "log.h"
#endif

#ifdef UAPI_WANTS_MALLOC
#include "malloc.h"
#endif

#ifdef UAPI_WANTS_PAGEALLOC
#include "pagealloc.h"
#endif

#ifdef UAPI_WANTS_PCI
#include "pci.h"
#endif

#ifdef UAPI_WANTS_VM
#include "vm.h"
#endif
