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

    DLL_Node* List = NULL;

    for (int i = 0; i < 5; i++)
    {
        DLL_AppendNode(&List, i);
    }
    for (i = 0; i < DLL_GetNodeSize(List); i++)
    {
        printf("List[%zu] : %d\n", i, DLL_GetNodeAt(List, i)->Data);
    }
    printf("\nInserting 3000 After [2]...\n\n");
    DLL_InsertAfter(List, 2, 3000);

    for (i = 0; i < DLL_GetNodeSize(List); i++)
    {
        printf("List[%zu] : %d\n", i, DLL_GetNodeAt(List, i)->Data);
    }
    printf("\nDestroying List...\n");

    while (List != NULL)
    {
        DLL_RemoveNode(&List, 0);
    }
}
void TestCDLL(void)
{
    size_t i = 0;

    CDLL_Node* List = NULL;
    CDLL_Node* Current = NULL;

    for (int i = 0; i < 5; i++)
    {
        CDLL_AppendNode(&List, i);
    }
    for (i = 0; i < CDLL_GetNodeSize(List); i++)
    {
        printf("List[%zu] : %d\n", i, CDLL_GetNodeAt(List, i)->Data);
    }
    printf("\nInserting 3000 After [2]...\n\n");
    CDLL_InsertAfter(List, 2, 3000);

    printf("\nRemoving Node at [2]...\n\n");
    CDLL_RemoveNode(&List, 2);

    for (i = 0; i < CDLL_GetNodeSize(List) * 2; i++)
    {
        if (i == 0)
        {
            Current = List;
        }
        else
        {
            Current = Current->NextNode;
        }
        printf("List[%zu] : %d\n", i, Current->Data);
    }
    printf("\nDestroying List...\n");

    while (List != NULL)
    {
        CDLL_RemoveNode(&List, 0);
    }
}
int main(void)
{
    int ListNumber = 0;

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
