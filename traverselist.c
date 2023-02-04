#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

struct triplets {
    uint16_t a, b, c;
    struct triplets *next;
};

struct list {
    uint16_t count;
    struct triplets *first;
};

struct list *createlist(void) {
    struct list *list = malloc(sizeof(*list));
    assert(list);
    list->count = 0;
    list->first = NULL;
    return list;    
};

void findtriples(struct list *list, uint16_t N) {
    uint16_t a, b, c, max_a;
    max_a = N / 3;
    for(uint16_t i = N; i > 0; i--) {
        for(a = 1; a <= max_a; a++) {
            b = ((N * (N - (2 * a))) / (2 * (N - a)));
            c = N - a - b;
            if((a * a) + (b * b) == (c * c)) {
                struct triplets *triplet = malloc(sizeof(*triplet));
                assert(triplet);
                triplet->a = a;
                triplet->b = b;
                triplet->c = c;
                triplet->next = list->first;
                list->first = triplet;
                list->count += 1;
            }
        }
    }
}

int main(void) {
    uint16_t N;
    scanf(" %hd", &N);
    struct list *tripletlist = createlist();
    findtriples(tripletlist, N);
    printf("There are %d triplets from 1 to %d\n", tripletlist->count, N);
    struct triplets *triplet = tripletlist->first;
    for(int i = 0; triplet != NULL; i++, triplet = triplet->next) {
        printf("%d. {a: %d, b: %d, c: %d} for %d\n", i + 1, triplet->a, triplet->b, triplet->c, triplet->a + triplet->b + triplet->c);
    }
    return 0;
}
