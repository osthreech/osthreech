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

// Get bit from unsigned integer
unsigned char bit(unsigned n, unsigned bit) {
    return (n & (1 << bit)) >> bit;
}

// Unbalanced trit to string
char *utrit_to_string(utrit u) {
    switch(u) {
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
char *btrit_to_string(btrit b) {
    switch(b) {
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
btrit balance(utrit u) {
    return nmod(u, 3) - 1;
}

// Unbalance trit
utrit unbalance(btrit b) {
    return nmod(b + 1, 3);
}

// Negate trit
// xy
// 00 | 2
// 01 | 0
// 11 | X
// 10 | 1
btrit negate(btrit b) {
    return b * -1;
}

// Increment trit
// xy
// 00 | 1
// 01 | 2
// 11 | X
// 10 | 0
btrit increment(btrit b) {
    return balance(unbalance(b + 1));
}

// Decrement trit
// xy
// 00 | 2
// 01 | 0
// 11 | X
// 10 | 1
btrit decrement(btrit b) {
    return balance(unbalance(b - 1));
}

// Check if trit is true
// xy
// 00 | 0
// 01 | 0
// 11 | X
// 10 | 2
btrit is_true(btrit b) {
    utrit u = unbalance(b);
    unsigned char x, y;
    x = bit(u, 1);
    y = bit(u, 0);
    return balance(2 * (x & (y^1)));
}

// Check if trit is false
// xy
// 00 | 2
// 01 | 0
// 11 | X
// 10 | 0
btrit is_false(btrit b) {
    utrit u = unbalance(b);
    unsigned char x, y;
    x = bit(u, 1);
    y = bit(u, 0);
    return balance(2 * ((x^1) & (y^1)));
}

// Check if trit is unknown
// xy
// 00 | 0
// 01 | 2
// 11 | X
// 10 | 0
btrit is_unknown(btrit b) {
    utrit u = unbalance(b);
    unsigned char x, y;
    x = bit(u, 1);
    y = bit(u, 0);
    return balance(2 * ((x^1) & y));
}

// Clamp trit down
// xy
// 00 | 0
// 01 | 1
// 11 | X
// 10 | 1
btrit clamp_down(btrit b) {
    utrit u = unbalance(b);
    unsigned char x, y;
    x = bit(u, 1);
    y = bit(u, 0);
    return balance(x | y);
}

// Clamp trit up
// xy
// 00 | 1
// 01 | 1
// 11 | X
// 10 | 2
btrit clamp_up(btrit b) {
    utrit u = unbalance(b);
    unsigned char x;
    x = bit(u, 1);
    return balance(2*x + (x^1));
}

// Min or And
// zw  00 01 11 10
// xy  -----------
// 00 | 0  0  X  0
// 01 | 0  1  X  1
// 11 | X  X  X  X
// 10 | 0  1  x  2
btrit and(btrit b1, btrit b2) {
    utrit u1 = unbalance(b1);
    utrit u2 = unbalance(b2);
    unsigned char x, y, z, w;
    x = bit(u1, 1);
    y = bit(u1, 0);
    z = bit(u2, 1);
    w = bit(u2, 0);
    return balance(x*(2*z + w) + y*(w + z));
}

// Max or Or
// zw  00 01 11 10
// xy  -----------
// 00 | 0  1  X  2
// 01 | 1  1  X  2
// 11 | X  X  X  X
// 10 | 2  2  x  2
btrit or(btrit b1, btrit b2) {
    utrit u1 = unbalance(b1);
    utrit u2 = unbalance(b2);
    unsigned char x, y, z, w;
    x = bit(u1, 1);
    y = bit(u1, 0);
    z = bit(u2, 1);
    w = bit(u2, 0);
    return balance(2*(x + z*(x^1)) + (x^1)*w + y*(z^1)*(w^1));
}

// Antimin or Nand
// zw  00 01 11 10
// xy  -----------
// 00 | 2  2  X  2
// 01 | 2  1  X  1
// 11 | X  X  X  X
// 10 | 2  1  x  0
btrit nand(btrit b1, btrit b2) {
    utrit u1 = unbalance(b1);
    utrit u2 = unbalance(b2);
    unsigned char x, y, z, w;
    x = bit(u1, 1);
    y = bit(u1, 0);
    z = bit(u2, 1);
    w = bit(u2, 0);
    return balance(2*((z^1)*(w^1) + (x^1)*(y^1)*(w + z)) + y*(z + w) + x*w);
}

// Antimax or Nor
// zw  00 01 11 10
// xy  -----------
// 00 | 2  1  X  0
// 01 | 1  1  X  0
// 11 | X  X  X  X
// 10 | 0  0  x  0
btrit nor(btrit b1, btrit b2) {
    utrit u1 = unbalance(b1);
    utrit u2 = unbalance(b2);
    unsigned char x, y, z, w;
    x = bit(u1, 1);
    y = bit(u1, 0);
    z = bit(u2, 1);
    w = bit(u2, 0);
    return balance((z^1)*(w^1)*(y + 2*(x^1)*(y^1)) + (x^1)*w);
}

// Exclusive Or or Xor
// zw  00 01 11 10
// xy  -----------
// 00 | 0  1  X  2
// 01 | 1  1  X  1
// 11 | X  X  X  X
// 10 | 2  1  x  0
btrit xor(btrit b1, btrit b2) {
    utrit u1 = unbalance(b1);
    utrit u2 = unbalance(b2);
    unsigned char x, y, z, w;
    x = bit(u1, 1);
    y = bit(u1, 0);
    z = bit(u2, 1);
    w = bit(u2, 0);
    return balance(2*(x*(z^1)*(w^1) + (x^1)*(y^1)*z) + w + y*(w^1));
}

// Sum
// zw  00 01 11 10
// xy  -----------
// 00 | 2  0  X  1
// 01 | 0  1  X  2
// 11 | X  X  X  X
// 10 | 1  2  x  0
btrit sum(btrit b1, btrit b2) {
    utrit u1 = unbalance(b1);
    utrit u2 = unbalance(b2);
    unsigned char x, y, z, w;
    x = bit(u1, 1);
    y = bit(u1, 0);
    z = bit(u2, 1);
    w = bit(u2, 0);
    return balance(2*(y*z + x*w + (x^1)*(y^1)*(z^1)*(w^1)) + w*y + x*(z^1)*(w^1) + (x^1)*(y^1)*z);
}

// Consensus
// zw  00 01 11 10
// xy  -----------
// 00 | 0  1  X  1
// 01 | 1  1  X  1
// 11 | X  X  X  X
// 10 | 1  1  x  2
btrit cons(btrit b1, btrit b2) {
    utrit u1 = unbalance(b1);
    utrit u2 = unbalance(b2);
    unsigned char x, y, z, w;
    x = bit(u1, 1);
    y = bit(u1, 0);
    z = bit(u2, 1);
    w = bit(u2, 0);
    return balance(2*(x*z) + (z^1)*(w^1)*(x + y) + w + (x^1)*z);
}

// Accept Anything
// zw  00 01 11 10
// xy  -----------
// 00 | 0  0  X  1
// 01 | 0  1  X  2
// 11 | X  X  X  X
// 10 | 1  2  x  2
btrit any(btrit b1, btrit b2) {
    utrit u1 = unbalance(b1);
    utrit u2 = unbalance(b2);
    unsigned char x, y, z, w;
    x = bit(u1, 1);
    y = bit(u1, 0);
    z = bit(u2, 1);
    w = bit(u2, 0);
    return balance(2*(x*(z + w) + y*z) + y*w + (x^1)*(y^1)*z + x*(z^1)*(w^1));
}

// Comparison
// zw  00 01 11 10
// xy  -----------
// 00 | 2  0  X  0
// 01 | 0  2  X  0
// 11 | X  X  X  X
// 10 | 0  0  x  2
btrit comp(btrit b1, btrit b2) {
    utrit u1 = unbalance(b1);
    utrit u2 = unbalance(b2);
    unsigned char x, y, z, w;
    x = bit(u1, 1);
    y = bit(u1, 0);
    z = bit(u2, 1);
    w = bit(u2, 0);
    return balance(2*(y*w + x*z + (x^1)*(y^1)*(z^1)*(w^1)));
}
