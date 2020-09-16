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
    if(!list || trit >= list->size) return;    
    unsigned byte = trit / (CHAR_BIT / TRIT_BIT);
    unsigned bit = CHAR_BIT - (trit * TRIT_BIT - byte * CHAR_BIT) - 1;
    switch (value) {
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
    
    if(trit >= (*list)->size) {
        if((*list)->size / (CHAR_BIT / TRIT_BIT) <
            (trit + 1) / (CHAR_BIT / TRIT_BIT) + 1) {
            tritlist *a = new_tritlist();
            a->size = trit + 1;
            a->trits = malloc(((trit + 1) / (CHAR_BIT / TRIT_BIT) + 1) * sizeof(unsigned char));
            int i;
            for(i = 0; i < (*list)->size / (CHAR_BIT / TRIT_BIT); i++)
                a->trits[i] = (*list)->trits[i];
            
            for(i = (*list)->size * TRIT_BIT; i < a->size * TRIT_BIT; i++)
                a->trits[i / CHAR_BIT] &= ~(1 << (CHAR_BIT - 1 - (i % CHAR_BIT)));
            
            free((*list)->trits);
            free(*list);
            *list = a;
        } else (*list)->size = trit + 1;
    }
    set(*list, trit, value);
}

utrit get(tritlist *list, unsigned trit) {
    trit *= TRIT_BIT;
    if(list->trits[trit / CHAR_BIT] & (1 << (CHAR_BIT - 1 - (trit % CHAR_BIT))))
        return FIX;
    if(list->trits[(trit + 1) / CHAR_BIT] & (1 << (CHAR_BIT - 1 - (trit + 1) % CHAR_BIT)))
        return FOX;
    return FAX;
}