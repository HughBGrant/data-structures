#include "linked_list.h"
#include "doubly_linked_list.h"
#include "circular_doubly_linked_list.h"

void TestLL(void)
{
    size_t i = 0;

    LinkedList *List = LL_CreateList();

    for (int i = 0; i < 5; i++)
    {
        LL_AppendTail(List, i);
    }
    LL_AppendTail(List, -1);
    LL_AppendTail(List, -2);

    for (i = 0; i < LL_GetSize(List); i++)
    {
        printf("List[%zu] : %d\n", i, LL_GetNodeAt(List, i)->Data);
    }
    printf("\nInserting 3000 Before [2]...\n\n");
    LL_InsertBefore(List, 2, 3000);

    for (i = 0; i < LL_GetSize(List); i++)
    {
        printf("List[%zu] : %d\n", i, LL_GetNodeAt(List, i)->Data);
    }
    printf("\nInserting 2000 After [2]...\n\n");
    LL_InsertAfter(List, 2, 2000);

    for (i = 0; i < LL_GetSize(List); i++)
    {
        printf("List[%zu] : %d\n", i, LL_GetNodeAt(List, i)->Data);
    }
    printf("\nDestroying List...\n");

    LL_DestroyList(List);
}
void TestDLL(void)
{
    size_t i = 0;

    DoublyLinkedList *List = DLL_CreateList();

    for (int i = 0; i < 5; i++)
    {
        DLL_AppendTail(List, i);
    }
    for (i = 0; i < DLL_GetSize(List); i++)
    {
        printf("List[%zu] : %d\n", i, DLL_GetNodeAt(List, i)->Data);
    }
    printf("\nInserting 3000 After [2]...\n\n");
    DLL_InsertAfter(List, 2, 3000);

    for (i = 0; i < DLL_GetSize(List); i++)
    {
        printf("List[%zu] : %d\n", i, DLL_GetNodeAt(List, i)->Data);
    }
    printf("\nDestroying List...\n");

    while (List->Count > 0)
    {
        DLL_RemoveNode(List, 0);
    }
    DLL_DestroyList(List);
}
void TestCDLL(void)
{
    size_t i = 0;
    CDLL_Node *Current = NULL;

    CircularDoublyLinkedList *List = CDLL_CreateList();

    for (int i = 0; i < 5; i++)
    {
        CDLL_AppendTail(List, i);
    }
    for (i = 0; i < CDLL_GetSize(List); i++)
    {
        printf("List[%zu] : %d\n", i, CDLL_GetNodeAt(List, i)->Data);
    }
    printf("\nInserting 3000 After [2]...\n\n");
    CDLL_InsertAfter(List, 2, 3000);

    printf("\nRemoving Node at [2]...\n\n");
    CDLL_RemoveNode(List, 2);

    for (i = 0; i < CDLL_GetSize(List) * 2; i++)
    {
        if (i == 0)
        {
            Current = List->Head;
        }
        else
        {
            Current = Current->NextNode;
        }
        printf("List[%zu] : %d\n", i, Current->Data);
    }
    printf("\nDestroying List...\n");

    CDLL_DestroyList(List);
}
int main(void)
{
    int ListNumber = 2;

    switch (ListNumber)
    {
        case 0:
        {
            TestLL();
            break;
        }
        case 1:
        {
            TestDLL();
            break;
        }
        case 2:
        {
            TestCDLL();
            break;
        }
    }
    return 0;
}
