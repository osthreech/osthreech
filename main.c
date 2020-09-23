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
    put(&t, 0, unbalance(TRUE));
    put(&t, 1, unbalance(FALSE));
    put(&t, 2, unbalance(UNKNOWN));
    put(&t, 3, unbalance(TRUE));

    printf("Trit 0 = %s\n", btrit_to_string(balance(get(t, 0))));
    printf("Trit 1 = %s\n", btrit_to_string(balance(get(t, 1))));
    printf("Trit 2 = %s\n", btrit_to_string(balance(get(t, 2))));
    printf("Trit 3 = %s\n", btrit_to_string(balance(get(t, 3))));
}
