#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list *list_new(int maxsize) {
  /*COMPLETAR*/
}

bool list_isempty(list *L) {
  /*COMPLETAR*/
}

bool list_isfull(list *L) {
  /*COMPLETAR*/
}

int list_length(list *L) {
  /*COMPLETAR*/
}

t_elem list_get(list *L, int index) {
  /*COMPLETAR*/
}

int list_search(list *L, t_elem elem) {
  /*COMPLETAR*/
}

void list_insert(list *L, int index, t_elem elem) {
  /*COMPLETAR*/
}

void list_delete(list *L, int index) {
  /*COMPLETAR*/
}

void list_traverse(list *L, bool look(t_elem elem, int index, void *ctx), void *ctx) {
  list_node *node = L->head;
  int index = 0;

  while (node != NULL && look(node->value, index, ctx)) {
    node = node->next;
    index++;
  }
}