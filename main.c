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
    put(&t, 0, unbalance(is_false(FALSE)));
    put(&t, 1, unbalance(is_false(UNKNOWN)));
    put(&t, 2, unbalance(is_false(TRUE)));
    put(&t, 3, unbalance(is_unknown(FALSE)));
    put(&t, 4, unbalance(is_unknown(UNKNOWN)));
    put(&t, 5, unbalance(is_unknown(TRUE)));
    put(&t, 6, unbalance(is_true(FALSE)));
    put(&t, 7, unbalance(is_true(UNKNOWN)));
    put(&t, 8, unbalance(is_true(TRUE)));
    put(&t, 9, unbalance(clamp_down(FALSE)));
    put(&t, 10, unbalance(clamp_down(UNKNOWN)));
    put(&t, 11, unbalance(clamp_down(TRUE)));
    put(&t, 12, unbalance(clamp_up(FALSE)));
    put(&t, 13, unbalance(clamp_up(UNKNOWN)));
    put(&t, 14, unbalance(clamp_up(TRUE)));

    printf("Trit 0 = %s\n", btrit_to_string(balance(get(t, 0))));
    printf("Trit 1 = %s\n", btrit_to_string(balance(get(t, 1))));
    printf("Trit 2 = %s\n", btrit_to_string(balance(get(t, 2))));
    printf("\n");
    printf("Trit 3 = %s\n", btrit_to_string(balance(get(t, 3))));
    printf("Trit 4 = %s\n", btrit_to_string(balance(get(t, 4))));
    printf("Trit 5 = %s\n", btrit_to_string(balance(get(t, 5))));
    printf("\n");
    printf("Trit 6 = %s\n", btrit_to_string(balance(get(t, 6))));
    printf("Trit 7 = %s\n", btrit_to_string(balance(get(t, 7))));
    printf("Trit 8 = %s\n", btrit_to_string(balance(get(t, 8))));
    printf("\n");
    printf("Trit 9 = %s\n", btrit_to_string(balance(get(t, 9))));
    printf("Trit 10 = %s\n", btrit_to_string(balance(get(t, 10))));
    printf("Trit 11 = %s\n", btrit_to_string(balance(get(t, 11))));
    printf("\n");
    printf("Trit 12 = %s\n", btrit_to_string(balance(get(t, 12))));
    printf("Trit 13 = %s\n", btrit_to_string(balance(get(t, 13))));
    printf("Trit 14 = %s\n", btrit_to_string(balance(get(t, 14))));
}
