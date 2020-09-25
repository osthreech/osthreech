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

    put(&t, 15, unbalance(and(FALSE, FALSE)));
    put(&t, 16, unbalance(and(FALSE, UNKNOWN)));
    put(&t, 17, unbalance(and(FALSE, TRUE)));

    put(&t, 18, unbalance(and(UNKNOWN, FALSE)));
    put(&t, 19, unbalance(and(UNKNOWN, UNKNOWN)));
    put(&t, 20, unbalance(and(UNKNOWN, TRUE)));
    
    put(&t, 21, unbalance(and(TRUE, FALSE)));
    put(&t, 22, unbalance(and(TRUE, UNKNOWN)));
    put(&t, 23, unbalance(and(TRUE, TRUE)));

    put(&t, 24, unbalance(or(FALSE, FALSE)));
    put(&t, 25, unbalance(or(FALSE, UNKNOWN)));
    put(&t, 26, unbalance(or(FALSE, TRUE)));

    put(&t, 27, unbalance(or(UNKNOWN, FALSE)));
    put(&t, 28, unbalance(or(UNKNOWN, UNKNOWN)));
    put(&t, 29, unbalance(or(UNKNOWN, TRUE)));
    
    put(&t, 30, unbalance(or(TRUE, FALSE)));
    put(&t, 31, unbalance(or(TRUE, UNKNOWN)));
    put(&t, 32, unbalance(or(TRUE, TRUE)));

    put(&t, 33, unbalance(nand(FALSE, FALSE)));
    put(&t, 34, unbalance(nand(FALSE, UNKNOWN)));
    put(&t, 35, unbalance(nand(FALSE, TRUE)));

    put(&t, 36, unbalance(nand(UNKNOWN, FALSE)));
    put(&t, 37, unbalance(nand(UNKNOWN, UNKNOWN)));
    put(&t, 38, unbalance(nand(UNKNOWN, TRUE)));
    
    put(&t, 39, unbalance(nand(TRUE, FALSE)));
    put(&t, 40, unbalance(nand(TRUE, UNKNOWN)));
    put(&t, 41, unbalance(nand(TRUE, TRUE)));
    
    put(&t, 42, unbalance(nor(FALSE, FALSE)));
    put(&t, 43, unbalance(nor(FALSE, UNKNOWN)));
    put(&t, 44, unbalance(nor(FALSE, TRUE)));

    put(&t, 45, unbalance(nor(UNKNOWN, FALSE)));
    put(&t, 46, unbalance(nor(UNKNOWN, UNKNOWN)));
    put(&t, 47, unbalance(nor(UNKNOWN, TRUE)));
    
    put(&t, 48, unbalance(nor(TRUE, FALSE)));
    put(&t, 49, unbalance(nor(TRUE, UNKNOWN)));
    put(&t, 50, unbalance(nor(TRUE, TRUE)));

    printf("is_false(false) = %s\n", btrit_to_string(balance(get(t, 0))));
    printf("is_false(unknown) = %s\n", btrit_to_string(balance(get(t, 1))));
    printf("is_false(true) = %s\n", btrit_to_string(balance(get(t, 2))));
    printf("\n");
    printf("is_unknown(false) = %s\n", btrit_to_string(balance(get(t, 3))));
    printf("is_unknown(unknown) = %s\n", btrit_to_string(balance(get(t, 4))));
    printf("is_unknown(true) = %s\n", btrit_to_string(balance(get(t, 5))));
    printf("\n");
    printf("is_true(false) = %s\n", btrit_to_string(balance(get(t, 6))));
    printf("is_true(unknown) = %s\n", btrit_to_string(balance(get(t, 7))));
    printf("is_true(true) = %s\n", btrit_to_string(balance(get(t, 8))));
    printf("\n");
    printf("clamp_down(false) = %s\n", btrit_to_string(balance(get(t, 9))));
    printf("clamp_down(unknown) = %s\n", btrit_to_string(balance(get(t, 10))));
    printf("clamp_down(true) = %s\n", btrit_to_string(balance(get(t, 11))));
    printf("\n");
    printf("clamp_up(false) = %s\n", btrit_to_string(balance(get(t, 12))));
    printf("clamp_up(unknown) = %s\n", btrit_to_string(balance(get(t, 13))));
    printf("clamp_up(true) =  %s\n", btrit_to_string(balance(get(t, 14))));
    printf("\n");
    printf("and(false, false) = %s\n", btrit_to_string(balance(get(t, 15))));
    printf("and(false, unknown) = %s\n", btrit_to_string(balance(get(t, 16))));
    printf("and(false, true) = %s\n", btrit_to_string(balance(get(t, 17))));
    printf("\n");
    printf("and(unknown, false) = %s\n", btrit_to_string(balance(get(t, 18))));
    printf("and(unknown, unknown) = %s\n", btrit_to_string(balance(get(t, 19))));
    printf("and(unknown, true) = %s\n", btrit_to_string(balance(get(t, 20))));
    printf("\n");
    printf("and(true, false) = %s\n", btrit_to_string(balance(get(t, 21))));
    printf("and(true, unknown) = %s\n", btrit_to_string(balance(get(t, 22))));
    printf("and(true, true) = %s\n", btrit_to_string(balance(get(t, 23))));
    printf("\n");
    printf("or(false, false) = %s\n", btrit_to_string(balance(get(t, 24))));
    printf("or(false, unknown) = %s\n", btrit_to_string(balance(get(t, 25))));
    printf("or(false, true) = %s\n", btrit_to_string(balance(get(t, 26))));
    printf("\n");
    printf("or(unknown, false) = %s\n", btrit_to_string(balance(get(t, 27))));
    printf("or(unknown, unknown) = %s\n", btrit_to_string(balance(get(t, 28))));
    printf("or(unknown, true) = %s\n", btrit_to_string(balance(get(t, 29))));
    printf("\n");
    printf("or(true, false) = %s\n", btrit_to_string(balance(get(t, 30))));
    printf("or(true, unknown) = %s\n", btrit_to_string(balance(get(t, 31))));
    printf("or(true, true) = %s\n", btrit_to_string(balance(get(t, 32))));
    printf("\n");
    printf("nand(false, false) = %s\n", btrit_to_string(balance(get(t, 33))));
    printf("nand(false, unknown) = %s\n", btrit_to_string(balance(get(t, 34))));
    printf("nand(false, true) = %s\n", btrit_to_string(balance(get(t, 35))));
    printf("\n");
    printf("nand(unknown, false) = %s\n", btrit_to_string(balance(get(t, 36))));
    printf("nand(unknown, unknown) = %s\n", btrit_to_string(balance(get(t, 37))));
    printf("nand(unknown, true) = %s\n", btrit_to_string(balance(get(t, 38))));
    printf("\n");
    printf("nand(true, false) = %s\n", btrit_to_string(balance(get(t, 39))));
    printf("nand(true, unknown) = %s\n", btrit_to_string(balance(get(t, 40))));
    printf("nand(true, true) = %s\n", btrit_to_string(balance(get(t, 41))));
    printf("\n");
    printf("nor(false, false) = %s\n", btrit_to_string(balance(get(t, 42))));
    printf("nor(false, unknown) = %s\n", btrit_to_string(balance(get(t, 43))));
    printf("nor(false, true) = %s\n", btrit_to_string(balance(get(t, 44))));
    printf("\n");
    printf("nor(unknown, false) = %s\n", btrit_to_string(balance(get(t, 45))));
    printf("nor(unknown, unknown) = %s\n", btrit_to_string(balance(get(t, 46))));
    printf("nor(unknown, true) = %s\n", btrit_to_string(balance(get(t, 47))));
    printf("\n");
    printf("nor(true, false) = %s\n", btrit_to_string(balance(get(t, 48))));
    printf("nor(true, unknown) = %s\n", btrit_to_string(balance(get(t, 49))));
    printf("nor(true, true) = %s\n", btrit_to_string(balance(get(t, 50))));
}
