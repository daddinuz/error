# Error

Immutable singleton instance to represent errors.

```c
#include <stdio.h>
#include <error.h>

const struct Error *divide(const double dividend, const double divisor, double *const out) {
    if (NULL == out) {
        return NullPointerError;
    } else if (0 == divisor) {
        return MathError;
    } else {
        *out = dividend / divisor;
        return Ok;
    }
}

int main() {
    double result = 0;
    const struct Error *error = divide(5, 0, &result);
    (Ok == error) ? printf("Result: %f\n", result) : printf("Error: %s\n", error->message);
    return 0;
}
```
