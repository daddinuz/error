# Error

Immutable singleton instance to represent errors.

```c

#include <stdio.h>
#include <error.h>

Error divide(const double dividend, const double divisor, double *const out) {
    if (NULL == out) {
        return NullReferenceError;
    } else if (0 == divisor) {
        return MathError;
    } else {
        *out = dividend / divisor;
        return Ok;
    }
}

int main() {
    double result = 0;
    Error error = divide(5, 0, &result);

    if (Ok == error) {
        printf("Result: %f\n", result);
    } else {
        printf("Error: %s\n", Error_explain(error));
    }

    return 0;
}

```
