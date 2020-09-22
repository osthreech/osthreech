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

typedef enum _utrit {
    FAX,
    FIX,
    FOX
} utrit;

typedef enum _btrit {
    FALSE,
    UNKNOWN,
    TRUE
} btrit;

typedef struct _tritlist {
    unsigned char *trits;
    unsigned size;
} tritlist;

tritlist *new_tritlist() {
    tritlist *a = malloc(sizeof(tritlist));
    a->trits = NULL;
    a->size = 0;
    return a;
}

char *trit_to_string(utrit trit) {
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

void set(tritlist *list, unsigned trit, utrit value) {
    if(!list) return;    
    unsigned byte = trit / (CHAR_BIT / TRIT_BIT);
    unsigned bit = CHAR_BIT - 1 - trit * TRIT_BIT % CHAR_BIT;
    switch(value) {
        case FAX:
            list->trits[byte] &= ~(1 << bit);
            list->trits[byte] &= ~(1 << bit - 1);
        break;
        case FIX:
            list->trits[byte] &= ~(1 << bit);
            list->trits[byte] |= 1 << bit - 1;
        break;
        case FOX:
            list->trits[byte] |= 1 << bit;
            list->trits[byte] &= ~(1 << bit - 1);
        break;
    }
}

void put(tritlist **list, unsigned trit, utrit value) {
    if(!list) return;
    if(trit >= (*list)->size * (CHAR_BIT / TRIT_BIT)) {
        unsigned listBytes = ((*list)->size > 0) * (((*list)->size - 1) / (CHAR_BIT / TRIT_BIT) + 1);
        unsigned requiredBytes = trit / (CHAR_BIT / TRIT_BIT) + 1;

        if(listBytes < requiredBytes) {
            tritlist *a = new_tritlist();
            a->size = trit + 1;
            a->trits = calloc(requiredBytes, sizeof(unsigned char));
            
            int i;
            for(i = 0; i < listBytes; i++)
                a->trits[i] = (*list)->trits[i];

            free((*list)->trits);
            free(*list);
            *list = a;
        } else (*list)->size = trit + 1;
    }	
    set(*list, trit, value);
}

utrit get(tritlist *list, unsigned trit) {
    if(!list) return -1;
    if(list->trits[trit / (CHAR_BIT / TRIT_BIT)] & (1 << CHAR_BIT - 1 - trit * TRIT_BIT % CHAR_BIT))
        return FOX;
    if(list->trits[trit / (CHAR_BIT / TRIT_BIT)] & (1 << CHAR_BIT - 1 - trit * TRIT_BIT % CHAR_BIT - 1))
        return FIX;
    return FAX;
}