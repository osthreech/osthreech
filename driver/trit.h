#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef LIMITS_H
#define LIMITS_H
#include <limits.h>
#endif

#define TRIT_BIT 2

// Unbalanced trit struct
typedef enum _utrit {
    FAX,
    FIX,
    FOX
} utrit;

// Balanced trit struct
typedef enum _btrit {
    FALSE = -1,
    UNKNOWN,
    TRUE
} btrit;

// Euclidean modulo for negative integers
unsigned nmod(int x, int y){
    int a = x % y;
    return a + y * (a < 0);
}

// Unbalanced trit to string
char *utrit_to_string(utrit trit) {
    switch(trit) {
        case FAX:
        return "FAX";
        case FIX:
        return "FIX";
        case FOX:
        return "FOX";
    }
    return NULL;
}

// Balanced trit to string
char *btrit_to_string(btrit trit) {
    switch(trit) {
        case FALSE:
        return "false";
        case UNKNOWN:
        return "unknown";
        case TRUE:
        return "true";
    }
    return NULL;
}

// Balance trit
btrit balance(utrit trit) {
    return nmod(trit, 3) - 1;
}

// Unbalance trit
utrit unbalance(btrit trit) {
    return nmod(trit + 1, 3);
}

// Negate trit
btrit negate(btrit trit) {
    return trit * -1;
}

// Increment trit
btrit increment(btrit trit) {
    return balance(unbalance(trit + 1));
}

// Decrement trit
btrit decrement(btrit trit) {
    return balance(unbalance(trit - 1));
}

// Check if trit is true
btrit is_true(btrit trit) {
    utrit u = unbalance(trit);
    return balance(2 * ((u & 2) >> 1 & (~u & 1)));
}

// Check if trit is false
btrit is_false(btrit trit) {
    utrit u = unbalance(trit);
    return balance(2 * ((~u & 2) >> 1 & (~u & 1)));
}

// Check if trit is unknown
btrit is_unknown(btrit trit) {
    utrit u = unbalance(trit);
    return balance(2 * ((~u & 2) >> 1 & (u & 1)));
}

// Clamp trit down
btrit clamp_down(btrit trit) {
    utrit u = unbalance(trit);
    return balance(((u & 2) >> 1 | (u & 1)));
}

// Clamp trit up
btrit clamp_up(btrit trit) {
    utrit u = unbalance(trit);
    return balance(((~u & 2) >> 1) + 2 * ((u & 2) >> 1));
}

