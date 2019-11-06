/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Davide Di Carlo
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(__GNUC__) || defined(__clang__))
__attribute__(...)
#endif

/**
 * Represents errors that may occur at runtime.
 * The lifetime of every error is the whole program duration.
 * In order to check if two errors are equal a simple comparison between pointers can be done.
 */
struct Error {
    const char *const message;
};

/**
 * Macro used to define custom error types.
 * @attention must be used in the global scope (outside functions bodies) to ensure the proper lifetime for the error.
 */
#define Error_define(msg) \
    ((const struct Error *)(&((const struct Error) {.message=(msg)})))

/**
 * Built-in errors
 */
extern const struct Error *const Ok;                    // Notifies a successful execution.
extern const struct Error *const DomainError;           // Indicates that a function has been passed illegal or inappropriate arguments
extern const struct Error *const IllegalState;          // A function has been invoked at an illegal or inappropriate time
extern const struct Error *const LookupError;           // A key or index used on a mapping or sequence is invalid
extern const struct Error *const MathError;             // Arithmetic errors e.g. zero division
extern const struct Error *const MemoryError;           // Memory related error, e.g. overlapping memory. Note: should not be used to notify OOM
extern const struct Error *const NullPointerError;      // Got a null pointer.
extern const struct Error *const OutOfMemory;           // The program ran out of memory
extern const struct Error *const SystemError;           // System-related errors e.g. file not found
extern const struct Error *const StopIteration;         // Indicates that the end of a sequence has been reached

#ifdef __cplusplus
}
#endif
