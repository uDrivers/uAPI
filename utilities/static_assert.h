#pragma once

#ifdef __cplusplus
#define UAPI_STATIC_ASSERT static_assert
#else
#define UAPI_STATIC_ASSERT _Static_assert
#endif

#define UAPI_BUILD_BUG_ON_WITH_MSG(expr, msg) UAPI_STATIC_ASSERT(!(expr), msg)

#define UAPI_BUILD_BUG_ON(expr) \
    UAPI_BUILD_BUG_ON_WITH_MSG(expr, "BUILD BUG: " #expr " evaluated to true")

#define UAPI_EXPECT_SIZEOF(type, size)                        \
    UAPI_BUILD_BUG_ON_WITH_MSG(sizeof(type) != size,          \
                               "BUILD BUG: invalid type size")
