#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct triples {
  uint16_t a, b, c;
  struct triples *next;
} triples_t;

triples_t *createnode(void) {
  triples_t *node = calloc(1, sizeof(*node));
  node->next = NULL;
  return node;
}

triples_t *triplets_with_sum(uint16_t *count, uint16_t sum) {
  uint16_t a, b, c;
  triples_t *current = createnode();
  for(; sum > 0; sum--) {
    uint16_t max_a = sum / 3;
    for(a = 1; a < max_a ; a++) {
      b = (sum * (sum - (2 * a))) / (2 * (sum - a));
      c = sum - a - b;
      if((a * a) + (b * b) == (c * c)) {
        triples_t *node = createnode();
        node->a = a;
        node->b = b;
        node->c = c;
        node->next = current->next;
        current->next = node;
        *count += 1;
      }
    }
  }
  return current;
}

void freeall(triples_t *list) {
  triples_t *freed = list;
  triples_t *next = list->next;
  if(!freed) {
    free(freed);
    if(!next){
      freed = next;
      next = freed->next;
    }
  }
}

int main(void) {
  puts("This program will print out all the pythagorean triples from 1 to N");
  puts("Where a + b + c = N and a^2 + b^2 = c^2\n");
  puts("      /| ");
  puts("     / | ");
  puts("  c /  | b ");
  puts("   /   | ");
  puts("  /____| ");
  puts("     a   \n");

  puts("Enter a whole number greater than 0 and no greater than 65535");
  uint16_t N, count;
  scanf(" %hd", &N);
  count = 0;
  triples_t *first = triplets_with_sum(&count, N);
  triples_t *savefirst = first;
  printf("There are %d pythagorean triplets from 1 to %d\n", count, N);
  for(; first->next != NULL; first = first->next) {
    printf("{a: %d, b: %d, c: %d} for %d\n", first->a, first->b, first->c, first->a + first->b + first->c);
  }
  first = savefirst;
  freeall(first);
  return 0;
}
