#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct element {
  char c;
  struct element *next;
  struct element *prev;
} td_element;

typedef struct dbllnk {
  td_element *head;
  td_element *tail;
} td_dblink;

td_dblink *createnewlist(void) {
  td_dblink *list = malloc(sizeof(*list));
  assert(list);
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void pushchar(td_dblink *list, char c) {
  td_element *element = malloc(sizeof(*element));
  assert(element);
  element->c = c;
  element->next = list->head;
  element->prev = NULL;
  if(!list->tail) {
    list->tail = list->head = element;
  } else {
    list->head->prev = element;
    list->head = element;
  }
}

void freeall(td_dblink *list) {
  for(td_element *index = list->head; index != NULL; index = list->head) {
    list->head = list->head->next;
    free(index);
  }
  free(list);
}

int main(void) {
  puts("This is just practice with double linked list");
  puts("A string is created by the linked structs therefore that is no '\\0' char at the end of the string");
  puts("I cannot think of where this might be practical just practice with the double linkedlist datastructure");
  puts("Enter a string of any size to print in reverse.");
  td_dblink *list = createnewlist();
  char c = '\0';
  while(c != '\n') {
    c = fgetc(stdin);
    pushchar(list, c);
  }
  puts("");
  puts("You typed: ");
  for(td_element *index = list->tail; index != NULL; index = index->prev) {
    printf("%c", index->c);
  }
  puts("");
  puts("In reverse is: ");
  for(td_element *index = list->head; index != NULL; index = index->next) {
    printf("%c", index->c);
  }
  puts("\n");
  freeall(list);
  return 0;
}
