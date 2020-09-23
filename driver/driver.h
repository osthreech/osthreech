#ifndef TRIT_H
#define TRIT_H
#include "trit.h"
#endif

// Trit list struct
typedef struct _tritlist {
    unsigned char *bytes;
    unsigned size;
} tritlist;

// New trit list
tritlist *new_tritlist() {
    tritlist *a = malloc(sizeof(tritlist));
    a->bytes = NULL;
    a->size = 0;
    return a;
}

// Set unbalanced trit on list
void set(tritlist *list, unsigned trit, utrit value) {
    if(!list) return;    
    unsigned byte = trit / (CHAR_BIT / TRIT_BIT);
    unsigned bit = CHAR_BIT - 1 - trit * TRIT_BIT % CHAR_BIT;
    switch(value) {
        case FAX:
            list->bytes[byte] &= ~(1 << bit);
            list->bytes[byte] &= ~(1 << bit - 1);
        break;
        case FIX:
            list->bytes[byte] &= ~(1 << bit);
            list->bytes[byte] |= 1 << bit - 1;
        break;
        case FOX:
            list->bytes[byte] |= 1 << bit;
            list->bytes[byte] &= ~(1 << bit - 1);
        break;
    }
}

// Put trit on list
void put(tritlist **list, unsigned trit, utrit value) {
    if(!list) return;
    if(trit >= (*list)->size * (CHAR_BIT / TRIT_BIT)) {
        unsigned listBytes = ((*list)->size > 0) * (((*list)->size - 1) / (CHAR_BIT / TRIT_BIT) + 1);
        unsigned requiredBytes = trit / (CHAR_BIT / TRIT_BIT) + 1;

        if(listBytes < requiredBytes) {
            tritlist *a = new_tritlist();
            a->size = trit + 1;
            a->bytes = calloc(requiredBytes, sizeof(unsigned char));
            
            int i;
            for(i = 0; i < listBytes; i++)
                a->bytes[i] = (*list)->bytes[i];

            free((*list)->bytes);
            free(*list);
            *list = a;
        } else (*list)->size = trit + 1;
    }	
    set(*list, trit, value);
}

// Read trit from list
utrit get(tritlist *list, unsigned trit) {
    if(!list) return -1;
    if(list->bytes[trit / (CHAR_BIT / TRIT_BIT)] & (1 << CHAR_BIT - 1 - trit * TRIT_BIT % CHAR_BIT))
        return FOX;
    if(list->bytes[trit / (CHAR_BIT / TRIT_BIT)] & (1 << CHAR_BIT - 1 - trit * TRIT_BIT % CHAR_BIT - 1))
        return FIX;
    return FAX;
}