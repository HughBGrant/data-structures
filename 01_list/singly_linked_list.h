#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stddef.h>

typedef int sll_item;
typedef struct singly_linked_list sll_list;

void sll_insert(sll_list *list, size_t pos, sll_item data);
void sll_remove(sll_list *list, size_t pos);
sll_item *sll_get(sll_list *list, size_t pos);
void sll_print(sll_list *list);
size_t sll_size(sll_list *list);

sll_list *sll_create(void);
void sll_destroy(sll_list *list);

#endif
