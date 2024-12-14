#pragma once

#define UAPI_ALIGN_UP_MASK(x, mask) (((x) + (mask)) & ~(mask))
#define UAPI_ALIGN_UP(x, val, type) UAPI_ALIGN_UP_MASK(x, (type)(val) - 1)

#define UAPI_ALIGN_DOWN_MASK(x, mask) ((x) & ~(mask))
#define UAPI_ALIGN_DOWN(x, val, type) UAPI_ALIGN_DOWN_MASK(x, (type)(val) - 1)

#define UAPI_IS_ALIGNED_MASK(x, mask) (((x) & (mask)) == 0)
#define UAPI_IS_ALIGNED(x, val, type) UAPI_IS_ALIGNED_MASK(x, (type)(val) - 1)

#define UAPI_IS_POWER_OF_TWO(x, type) UAPI_IS_ALIGNED(x, x, type)
