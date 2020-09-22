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
    put(&t, 0, FOX);
    put(&t, 1, FAX);
    put(&t, 2, FIX);
    put(&t, 3, FOX);
    put(&t, 4, FAX);
    put(&t, 5, FIX);
    put(&t, 6, FOX);
    put(&t, 7, FAX);
    put(&t, 25, FIX);
    put(&t, 18, FOX);
    put(&t, 105, FAX);
    put(&t, 31, FIX);
    put(&t, 94, FOX);
    put(&t, 10, FAX);
    put(&t, 106, FIX);
    put(&t, 99, FOX);

    printf("Trit 0 = %s\n", trit_to_string(get(t, 0)));
    printf("Trit 1 = %s\n", trit_to_string(get(t, 1)));
    printf("Trit 2 = %s\n", trit_to_string(get(t, 2)));
    printf("Trit 3 = %s\n", trit_to_string(get(t, 3)));
    printf("Trit 4 = %s\n", trit_to_string(get(t, 4)));
    printf("Trit 5 = %s\n", trit_to_string(get(t, 5)));
    printf("Trit 6 = %s\n", trit_to_string(get(t, 6)));
    printf("Trit 7 = %s\n", trit_to_string(get(t, 7)));
    printf("Trit 25 = %s\n", trit_to_string(get(t, 25)));
    printf("Trit 18 = %s\n", trit_to_string(get(t, 18)));
    printf("Trit 105 = %s\n", trit_to_string(get(t, 105)));
    printf("Trit 31 = %s\n", trit_to_string(get(t, 31)));
    printf("Trit 94 = %s\n", trit_to_string(get(t, 94)));
    printf("Trit 10 = %s\n", trit_to_string(get(t, 10)));
    printf("Trit 10 = %s\n", trit_to_string(get(t, 10)));
    printf("Trit 106 = %s\n", trit_to_string(get(t, 106)));
    printf("Trit 99 = %s\n", trit_to_string(get(t, 99)));
}
