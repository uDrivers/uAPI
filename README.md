# uAPI
Common set of headers used by all uDrivers

# Recommended uDriver project layout

The general include directory layout is recommended to follow this idea:
```
|- include
    |- udrv
        |- {uAPI module}
        |- internal
            |- <internal headers & implementation details>
        |- kernel_api.h
```

Where kernel_api.h is the aggregator of all uAPI used by the project:
```c
$ cat include/udrv/kernel_api.h
#ifndef UAPI_KERNEL_API
#define UAPI_KERNEL_API
#endif

#ifndef UAPI_WANTS_MEMORY
#define UAPI_WANTS_MEMORY
#endif

#ifndef UAPI_WANTS_PCI
#define UAPI_WANTS_PCI
#endif

#ifndef UAPI_WANTS_IRQ
#define UAPI_WANTS_IRQ
#endif

#include <udrv/uapi/uapi.h>
```

Note that all headers residing in udrv/ are considered public API, and it's the
user's expectation that they may include and use any headers inside there.

All internal udrv APIs and implementation-specific headers should go into
udrv/internal/, which the host is not allowed to include directly.

# Adding a new header into uAPI

All uAPI headers have the following layout:
```c
// Header-specific API version, incremented for each API break
#ifndef UAPI_FOO_VERSION
#define UAPI_FOO_VERSION 1
#endif

// Verify the version in case there's already a foo.h included from a different u-driver
#if UAPI_FOO_VERSION != 1
#error foo.h API version mismatch, make sure all uDrivers are using the same base
#endif

// Standard include guard, note that we don't use pragma once to protect against
// multiple includes of the same header from different submodule paths, and
// instead stick to the legacy header guards.
#ifndef UAPI_FOO_INCLUDED
#define UAPI_FOO_INCLUDED

// Make sure the user doesn't accidentally include this header directly
// We do this to make sure there's no confusion as to which headers to
// implement.
#ifndef UAPI_KERNEL_API
#error this header should not be included directly, use kernel_api.h
#endif

// A sanity check that this header is explicitly requested by the u-driver to be
// implemented. This saves extra work for the host and prevents confusion as to
// which headers to implement.
#ifndef UAPI_WANTS_FOO
#error foo.h is not used by any of the included uDrivers and should not be included
#endif

// All uAPI host functions start with uapi_kernel_*
void uapi_kernel_foo();

#endif
```
