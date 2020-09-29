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

    put(&t, 51, unbalance(xor(FALSE, FALSE)));
    put(&t, 52, unbalance(xor(FALSE, UNKNOWN)));
    put(&t, 53, unbalance(xor(FALSE, TRUE)));

    put(&t, 54, unbalance(xor(UNKNOWN, FALSE)));
    put(&t, 55, unbalance(xor(UNKNOWN, UNKNOWN)));
    put(&t, 56, unbalance(xor(UNKNOWN, TRUE)));
    
    put(&t, 57, unbalance(xor(TRUE, FALSE)));
    put(&t, 58, unbalance(xor(TRUE, UNKNOWN)));
    put(&t, 59, unbalance(xor(TRUE, TRUE)));

    put(&t, 60, unbalance(sum(FALSE, FALSE)));
    put(&t, 61, unbalance(sum(FALSE, UNKNOWN)));
    put(&t, 62, unbalance(sum(FALSE, TRUE)));

    put(&t, 63, unbalance(sum(UNKNOWN, FALSE)));
    put(&t, 64, unbalance(sum(UNKNOWN, UNKNOWN)));
    put(&t, 65, unbalance(sum(UNKNOWN, TRUE)));
    
    put(&t, 66, unbalance(sum(TRUE, FALSE)));
    put(&t, 67, unbalance(sum(TRUE, UNKNOWN)));
    put(&t, 68, unbalance(sum(TRUE, TRUE)));
    
    put(&t, 69, unbalance(cons(FALSE, FALSE)));
    put(&t, 70, unbalance(cons(FALSE, UNKNOWN)));
    put(&t, 71, unbalance(cons(FALSE, TRUE)));

    put(&t, 72, unbalance(cons(UNKNOWN, FALSE)));
    put(&t, 73, unbalance(cons(UNKNOWN, UNKNOWN)));
    put(&t, 74, unbalance(cons(UNKNOWN, TRUE)));
    
    put(&t, 75, unbalance(cons(TRUE, FALSE)));
    put(&t, 76, unbalance(cons(TRUE, UNKNOWN)));
    put(&t, 77, unbalance(cons(TRUE, TRUE)));

    put(&t, 78, unbalance(any(FALSE, FALSE)));
    put(&t, 79, unbalance(any(FALSE, UNKNOWN)));
    put(&t, 80, unbalance(any(FALSE, TRUE)));

    put(&t, 81, unbalance(any(UNKNOWN, FALSE)));
    put(&t, 82, unbalance(any(UNKNOWN, UNKNOWN)));
    put(&t, 83, unbalance(any(UNKNOWN, TRUE)));
    
    put(&t, 84, unbalance(any(TRUE, FALSE)));
    put(&t, 85, unbalance(any(TRUE, UNKNOWN)));
    put(&t, 86, unbalance(any(TRUE, TRUE)));

    put(&t, 87, unbalance(comp(FALSE, FALSE)));
    put(&t, 88, unbalance(comp(FALSE, UNKNOWN)));
    put(&t, 89, unbalance(comp(FALSE, TRUE)));

    put(&t, 90, unbalance(comp(UNKNOWN, FALSE)));
    put(&t, 91, unbalance(comp(UNKNOWN, UNKNOWN)));
    put(&t, 92, unbalance(comp(UNKNOWN, TRUE)));
    
    put(&t, 93, unbalance(comp(TRUE, FALSE)));
    put(&t, 94, unbalance(comp(TRUE, UNKNOWN)));
    put(&t, 95, unbalance(comp(TRUE, TRUE)));

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
    printf("\n");
    printf("xor(false, false) = %s\n", btrit_to_string(balance(get(t, 51))));
    printf("xor(false, unknown) = %s\n", btrit_to_string(balance(get(t, 52))));
    printf("xor(false, true) = %s\n", btrit_to_string(balance(get(t, 53))));
    printf("\n");
    printf("xor(unknown, false) = %s\n", btrit_to_string(balance(get(t, 54))));
    printf("xor(unknown, unknown) = %s\n", btrit_to_string(balance(get(t, 55))));
    printf("xor(unknown, true) = %s\n", btrit_to_string(balance(get(t, 56))));
    printf("\n");
    printf("xor(true, false) = %s\n", btrit_to_string(balance(get(t, 57))));
    printf("xor(true, unknown) = %s\n", btrit_to_string(balance(get(t, 58))));
    printf("xor(true, true) = %s\n", btrit_to_string(balance(get(t, 59))));
    printf("\n");
    printf("sum(false, false) = %s\n", btrit_to_string(balance(get(t, 60))));
    printf("sum(false, unknown) = %s\n", btrit_to_string(balance(get(t, 61))));
    printf("sum(false, true) = %s\n", btrit_to_string(balance(get(t, 62))));
    printf("\n");
    printf("sum(unknown, false) = %s\n", btrit_to_string(balance(get(t, 63))));
    printf("sum(unknown, unknown) = %s\n", btrit_to_string(balance(get(t, 64))));
    printf("sum(unknown, true) = %s\n", btrit_to_string(balance(get(t, 65))));
    printf("\n");
    printf("sum(true, false) = %s\n", btrit_to_string(balance(get(t, 66))));
    printf("sum(true, unknown) = %s\n", btrit_to_string(balance(get(t, 67))));
    printf("sum(true, true) = %s\n", btrit_to_string(balance(get(t, 68))));
    printf("\n");
    printf("cons(false, false) = %s\n", btrit_to_string(balance(get(t, 69))));
    printf("cons(false, unknown) = %s\n", btrit_to_string(balance(get(t, 70))));
    printf("cons(false, true) = %s\n", btrit_to_string(balance(get(t, 71))));
    printf("\n");
    printf("cons(unknown, false) = %s\n", btrit_to_string(balance(get(t, 72))));
    printf("cons(unknown, unknown) = %s\n", btrit_to_string(balance(get(t, 73))));
    printf("cons(unknown, true) = %s\n", btrit_to_string(balance(get(t, 74))));
    printf("\n");
    printf("cons(true, false) = %s\n", btrit_to_string(balance(get(t, 75))));
    printf("cons(true, unknown) = %s\n", btrit_to_string(balance(get(t, 76))));
    printf("cons(true, true) = %s\n", btrit_to_string(balance(get(t, 77))));
    printf("\n");
    printf("any(false, false) = %s\n", btrit_to_string(balance(get(t, 78))));
    printf("any(false, unknown) = %s\n", btrit_to_string(balance(get(t, 79))));
    printf("any(false, true) = %s\n", btrit_to_string(balance(get(t, 80))));
    printf("\n");
    printf("any(unknown, false) = %s\n", btrit_to_string(balance(get(t, 81))));
    printf("any(unknown, unknown) = %s\n", btrit_to_string(balance(get(t, 82))));
    printf("any(unknown, true) = %s\n", btrit_to_string(balance(get(t, 83))));
    printf("\n");
    printf("any(true, false) = %s\n", btrit_to_string(balance(get(t, 84))));
    printf("any(true, unknown) = %s\n", btrit_to_string(balance(get(t, 85))));
    printf("any(true, true) = %s\n", btrit_to_string(balance(get(t, 86))));
    printf("\n");
    printf("comp(false, false) = %s\n", btrit_to_string(balance(get(t, 87))));
    printf("comp(false, unknown) = %s\n", btrit_to_string(balance(get(t, 88))));
    printf("comp(false, true) = %s\n", btrit_to_string(balance(get(t, 89))));
    printf("\n");
    printf("comp(unknown, false) = %s\n", btrit_to_string(balance(get(t, 90))));
    printf("comp(unknown, unknown) = %s\n", btrit_to_string(balance(get(t, 91))));
    printf("comp(unknown, true) = %s\n", btrit_to_string(balance(get(t, 92))));
    printf("\n");
    printf("comp(true, false) = %s\n", btrit_to_string(balance(get(t, 93))));
    printf("comp(true, unknown) = %s\n", btrit_to_string(balance(get(t, 94))));
    printf("comp(true, true) = %s\n", btrit_to_string(balance(get(t, 95))));
    
    
}
