#pragma once

#define UACPI_COMPARE(x, y, op) ((x) op (y) ? (x) : (y))
#define UACPI_MIN(x, y) UACPI_COMPARE(x, y, <)
#define UACPI_MAX(x, y) UACPI_COMPARE(x, y, >)
