#include "array_list.h"
#include "circular_linked_list.h"
#include "doubly_linked_list.h"
#include "linked_list.h"

void al_test(void)
{
    size_t i = 0;

    AL *list = AL_CreateList(10);

    for (int i = 0; i < 5; i++) {
        AL_AppendTail(list, i);
    }
    AL_AppendTail(list, -1);
    AL_AppendTail(list, -2);
    for (i = 0; i < AL_GetSize(list); i++) {
        printf("List[%zu] : %d\n", i, list->Array[i]);
    }

    printf("\nInserting 3000 At [2]...\n\n");
    AL_Insert(list, 2, 3000);
    for (i = 0; i < AL_GetSize(list); i++) {
        printf("List[%zu] : %d\n", i, list->Array[i]);
    }

    printf("\nRemoving Node at [2]...\n\n");
    AL_Remove(list, 2);
    for (i = 0; i < AL_GetSize(list); i++) {
        printf("List[%zu] : %d\n", i, list->Array[i]);
    }

    printf("\nDestroying List...\n");
    AL_DestroyList(list);
}
void ll_test(void)
{
    size_t i = 0;

    linked_list *list = ll_create();

    for (int i = 0; i < 5; i++) {
        ll_append(list, i);
    }
    ll_append(list, -1);
    ll_append(list, -2);

    for (i = 0; i < ll_size(list); i++) {
        printf("List[%zu] : %d\n", i, ll_get(list, i)->data);
    }

    printf("\nInserting 3000 At [2]...\n\n");
    ll_insert(list, 2, 3000);

    for (i = 0; i < ll_size(list); i++) {
        printf("List[%zu] : %d\n", i, ll_get(list, i)->data);
    }

    printf("\nDestroying List...\n");

    ll_destroy(list);
}
void cll_test(void)
{
    size_t i = 0;

    circular_linked_list *list = cll_create();

    for (int i = 0; i < 5; i++) {
        cll_append(list, i);
    }
    cll_append(list, -1);
    cll_append(list, -2);

    for (i = 0; i < cll_size(list); i++) {
        printf("List[%zu] : %d\n", i, cll_get(list, i)->data);
    }

    printf("\nInserting 3000 At [2]...\n\n");
    cll_insert(list, 2, 3000);

    for (i = 0; i < cll_size(list); i++) {
        printf("List[%zu] : %d\n", i, cll_get(list, i)->data);
    }

    printf("\nDestroying List...\n");

    cll_destroy(list);
}
void dll_test(void)
{
    size_t i = 0;
    DLL_Node *current = NULL;

    DLL *List = DLL_CreateList();

    for (int i = 0; i < 5; i++) {
        DLL_AppendTail(List, i);
    }
    for (i = 0; i < DLL_GetSize(List); i++) {
        printf("List[%zu] : %d\n", i, DLL_GetNodeAt(List, i)->Data);
    }

    printf("\nInserting 3000 At [3]...\n\n");
    DLL_Insert(List, 3, 3000);

    printf("\nRemoving Node at [2]...\n\n");
    DLL_RemoveNode(List, 2);

    for (i = 0; i < DLL_GetSize(List) * 2; i++) {
        if (i == 0) {
            current = List->Head;
        } else {
            current = current->NextNode;
        }
        printf("List[%zu] : %d\n", i, current->Data);
    }
    printf("\nDestroying List...\n");

    DLL_DestroyList(List);
}
int main(void)
{
    int ListNumber = 1;

    switch (ListNumber) {
    case 0:
        al_test();
        break;
    case 1:
        ll_test();
        break;
    case 2:
        cll_test();
        break;
    case 3:
        dll_test();
        break;
    }
    return 0;
}
