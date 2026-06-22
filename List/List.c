#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularDoublyLinkedList.h"

void TestSLL(void)
{
    size_t i = 0;

    SLLNode* Head = NULL;

    for (int i = 0; i < 5; i++)
    {
        SLL_AppendNode(&Head, i);
    }
    SLL_AppendNode(&Head, -1);
    SLL_AppendNode(&Head, -2);

    for (i = 0; i < SLL_GetNodeCount(Head); i++)
    {
        printf("Head[%zu] : %d\n", i, SLL_GetNodeAt(Head, i)->Data);
    }
    printf("\nInserting 3000 Before [2]...\n\n");
    SLL_InsertBefore(&Head, 2, 3000);

    for (i = 0; i < SLL_GetNodeCount(Head); i++)
    {
        printf("Head[%zu] : %d\n", i, SLL_GetNodeAt(Head, i)->Data);
    }
    printf("\nInserting 2000 After [2]...\n\n");
    SLL_InsertAfter(Head, 2, 2000);

    for (i = 0; i < SLL_GetNodeCount(Head); i++)
    {
        printf("Head[%zu] : %d\n", i, SLL_GetNodeAt(Head, i)->Data);
    }
    printf("\nDestroying Head...\n");

    while (Head != NULL)
    {
        SLL_RemoveNode(&Head, 0);
    }
}
void TestDLL(void)
{
    size_t i = 0;

    DLLNode* List = NULL;

    for (i = 0; i < 5; i++)
    {
        DLL_AppendNode(&List, i);
    }
    for (i = 0; i < DLL_GetNodeCount(List); i++)
    {
        printf("List[%zu] : %d\n", i, DLL_GetNodeAt(List, i)->Data);
    }
    printf("\nInserting 3000 After [2]...\n\n");
    DLL_InsertAfter(List, 2, 3000);

    for (i = 0; i < DLL_GetNodeCount(List); i++)
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

    CDLLNode* List = NULL;
    CDLLNode* Current = NULL;

    for (i = 0; i < 5; i++)
    {
        CDLL_AppendNode(&List, i);
    }
    for (i = 0; i < CDLL_GetNodeCount(List); i++)
    {
        printf("List[%zu] : %d\n", i, CDLL_GetNodeAt(List, i)->Data);
    }
    printf("\nInserting 3000 After [2]...\n\n");
    CDLL_InsertAfter(List, 2, 3000);

    printf("\nRemoving Node at [2]...\n\n");
    CDLL_RemoveNode(&List, 2);

    for (i = 0; i < CDLL_GetNodeCount(List) * 2; i++)
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
    int ListNumber = 2;

    switch (ListNumber)
    {
        case 0:
        {
            TestSLL();
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
