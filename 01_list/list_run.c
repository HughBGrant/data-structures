#include "array_list.h"
#include "circular_doubly_linked_list.h"
#include "circular_linked_list.h"
#include "doubly_linked_list.h"
#include "singly_linked_list.h"

void al_test(void)
{
    array_list *list = al_create(32);
    size_t i = 0;

    for (int i = 0; i < 5; i++) {
        al_insert(list, al_size(list), i);
    }
    al_insert(list, al_size(list), -1);
    al_insert(list, al_size(list), -2);
    al_printf(list);

    printf("\nInserting 3000 At [2]...\n\n");
    al_insert(list, 2, 3000);
    al_printf(list);

    printf("\nRemoving Node at [2]...\n\n");
    al_delete(list, 2);
    al_printf(list);

    al_destroy(list);
}
void sll_test(void)
{
    singly_linked_list *list = sll_create();
    size_t i = 0;

    for (int i = 5; i > 0; i--) {
        sll_insert(list, sll_size(list), i);
    }
    sll_insert(list, sll_size(list), -1);
    sll_insert(list, sll_size(list), -2);

    for (i = 0; i < sll_size(list); i++) {
        printf("List[%zu] : %d\n", i, *sll_get(list, i));
    }

    printf("\nInserting 3000 At [2]...\n\n");
    sll_insert(list, 2, 3000);

    for (i = 0; i < sll_size(list); i++) {
        printf("List[%zu] : %d\n", i, *sll_get(list, i));
    }

    printf("\nDestroying List...\n");

    sll_destroy(list);
}
void cll_test(void)
{
    circular_linked_list *list = cll_create();
    size_t i = 0;
    cll_node *current = NULL;

    for (int i = 5; i > 0; i--) {
        cll_insert(list, cll_size(list), i);
    }
    cll_insert(list, cll_size(list), -1);
    cll_insert(list, cll_size(list), -2);

    for (i = 0; i < cll_size(list); i++) {
        printf("List[%zu] : %d\n", i, *cll_get(list, i));
    }

    printf("\nInserting 3000 At [2]...\n\n");
    cll_insert(list, 2, 3000);

    for (i = 0; i < cll_size(list); i++) {
        printf("List[%zu] : %d\n", i, *cll_get(list, i));
    }

    printf("tail->next : %d\n", list->tail->next->data);

    printf("\nDestroying List...\n");
    cll_destroy(list);
}
void dll_test(void)
{
    doubly_linked_list *list = dll_create();
    size_t i = 0;
    dll_node *current = NULL;

    for (int i = 5; i > 0; i--) {
        dll_insert(list, dll_size(list), i);
    }
    dll_insert(list, dll_size(list), -1);
    dll_insert(list, dll_size(list), -2);

    for (i = 0; i < dll_size(list); i++) {
        printf("List[%zu] : %d\n", i, *dll_get(list, i));
    }

    printf("\nInserting 3000 At [2]...\n\n");
    dll_insert(list, 2, 3000);

    for (i = 0; i < dll_size(list); i++) {
        printf("List[%zu] : %d\n", i, *dll_get(list, i));
    }

    printf("tail->next : %d\n", list->tail->next->data);

    printf("\nDestroying List...\n");
    dll_destroy(list);
}
void cdll_test(void)
{
    c_d_linked_list *list = cdll_create();
    size_t i = 0;

    for (int i = 5; i > 0; i--) {
        cdll_insert(list, cdll_size(list), i);
    }
    for (i = 0; i < cdll_size(list); i++) {
        printf("List[%zu] : %d\n", i, *cdll_get(list, i));
    }

    printf("\nInserting 3000 At [3]...\n\n");
    cdll_insert(list, 3, 3000);

    printf("\nRemoving Node at [2]...\n\n");
    cdll_delete(list, 2);

    for (i = 0; i < cdll_size(list); i++) {
        printf("List[%zu] : %d\n", i, *cdll_get(list, i));
    }

    printf("Head->Prev[%zu] : %d\n", i, list->head->prev->data);

    printf("\nDestroying List...\n");
    cdll_destroy(list);
}
int main(void)
{
    int list_number = 0;

    switch (list_number) {
    case 0:
        al_test();
        break;
    case 1:
        sll_test();
        break;
    case 2:
        cll_test();
        break;
    case 3:
        dll_test();
        break;
    case 4:
        cdll_test();
        break;
    }
    return 0;
}
