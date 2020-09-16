#ifndef DRIVER_H
#define DRIVER_H
#include "driver/driver.h"
#endif

#ifndef TRIT_H
#define TRIT_H
#include "driver/trit.h"
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

int main() {
    tritlist *t = new_tritlist();
    put(&t, 0, FIX);
    put(&t, 1, FOX);
    put(&t, 4, FAX);
    put(&t, 100, FIX);
    put(&t, 6, FOX);
    put(&t, 87, FAX);
    put(&t, 92, FIX);
    put(&t, 13, FOX);
    put(&t, 86, FIX);
    put(&t, 37, FIX);
    put(&t, 25, FOX);
    put(&t, 50, FOX);

    utrit u;
    u = get(t, 0);
    printf("Trit 0: %s\n", trit_to_string(u));
    u = get(t, 1);
    printf("Trit 1: %s\n", trit_to_string(u));
    u = get(t, 4);
    printf("Trit 4: %s\n", trit_to_string(u));
    u = get(t, 3);
    printf("Trit 3: %s\n", trit_to_string(u));
    u = get(t, 100);
    printf("Trit 100: %s\n", trit_to_string(u));
    u = get(t, 6);
    printf("Trit 6: %s\n", trit_to_string(u));
    u = get(t, 87);
    printf("Trit 87: %s\n", trit_to_string(u));
    u = get(t, 92);
    printf("Trit 92: %s\n", trit_to_string(u));
    u = get(t, 13);
    printf("Trit 13: %s\n", trit_to_string(u));
    u = get(t, 86);
    printf("Trit 86: %s\n", trit_to_string(u));
    u = get(t, 37);
    printf("Trit 37: %s\n", trit_to_string(u));
    u = get(t, 25);
    printf("Trit 25: %s\n", trit_to_string(u));
    u = get(t, 50);
    printf("Trit 50: %s\n", trit_to_string(u));

    printf("Byte 0 = %hhu\n", t->trits[0]);
}
