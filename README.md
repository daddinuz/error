# Error

Immutable singleton instance to represent errors.

```c

#include <stdio.h>
#include <error.h>

Error div(int a, int b, int *out) {
    if (NULL == out) {
        return DomainError;
    } else if (0 == b) {
        return MathError;
    } else {
        *out = a / b;
        return Ok;
    }
}

int main() {
    int result = 0;
    Error error = div(5, 0, &result);

    if (Ok == error) {
        printf("Result: %d\n", result);
    } else {
        printf("Error: %s\n", Error_explain(error));
    }

    return 0;
}

```
