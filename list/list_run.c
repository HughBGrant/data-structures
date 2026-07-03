#include "array_list.h"
#include "circular_linked_list.h"
#include "doubly_linked_list.h"
#include "singly_linked_list.h"

void TestAL(void)
{
    size_t i = 0;

    ArrayList *List = AL_CreateList(10);

    for (int i = 0; i < 5; i++) {
        AL_AppendTail(List, i);
    }
    AL_AppendTail(List, -1);
    AL_AppendTail(List, -2);
    for (i = 0; i < AL_GetSize(List); i++) {
        printf("List[%zu] : %d\n", i, List->Array[i]);
    }

    printf("\nInserting 3000 At [2]...\n\n");
    AL_Insert(List, 2, 3000);
    for (i = 0; i < AL_GetSize(List); i++) {
        printf("List[%zu] : %d\n", i, List->Array[i]);
    }

    printf("\nRemoving Node at [2]...\n\n");
    AL_Remove(List, 2);
    for (i = 0; i < AL_GetSize(List); i++) {
        printf("List[%zu] : %d\n", i, List->Array[i]);
    }

    printf("\nDestroying List...\n");
    AL_DestroyList(List);
}
void TestSLL(void)
{
    size_t i = 0;

    SinglyLinkedList *List = SLL_CreateList();

    for (int i = 0; i < 5; i++) {
        SLL_AppendTail(List, i);
    }
    SLL_AppendTail(List, -1);
    SLL_AppendTail(List, -2);

    for (i = 0; i < SLL_GetSize(List); i++) {
        printf("List[%zu] : %d\n", i, SLL_GetNodeAt(List, i)->Data);
    }

    printf("\nInserting 3000 At [2]...\n\n");
    SLL_Insert(List, 2, 3000);

    for (i = 0; i < SLL_GetSize(List); i++) {
        printf("List[%zu] : %d\n", i, SLL_GetNodeAt(List, i)->Data);
    }

    printf("\nDestroying List...\n");

    SLL_DestroyList(List);
}
void TestDLL(void)
{
    size_t i = 0;

    DoublyLinkedList *List = DLL_CreateList();

    for (int i = 0; i < 5; i++) {
        DLL_AppendTail(List, i);
    }
    for (i = 0; i < DLL_GetSize(List); i++) {
        printf("List[%zu] : %d\n", i, DLL_GetNodeAt(List, i)->Data);
    }

    printf("\nInserting 3000 At [3]...\n\n");
    DLL_Insert(List, 3, 3000);
    for (i = 0; i < DLL_GetSize(List); i++) {
        printf("List[%zu] : %d\n", i, DLL_GetNodeAt(List, i)->Data);
    }

    printf("\nDestroying List...\n");
    while (List->Count > 0) {
        DLL_RemoveNode(List, 0);
    }
    DLL_DestroyList(List);
}
void TestCLL(void)
{
    size_t i = 0;
    CLL_Node *Current = NULL;

    CircularLinkedList *List = CLL_CreateList();

    for (int i = 0; i < 5; i++) {
        CLL_AppendTail(List, i);
    }
    for (i = 0; i < CLL_GetSize(List); i++) {
        printf("List[%zu] : %d\n", i, CLL_GetNodeAt(List, i)->Data);
    }

    printf("\nInserting 3000 At [3]...\n\n");
    CLL_Insert(List, 3, 3000);

    printf("\nRemoving Node at [2]...\n\n");
    CLL_RemoveNode(List, 2);

    for (i = 0; i < CLL_GetSize(List) * 2; i++) {
        if (i == 0) {
            Current = List->Head;
        } else {
            Current = Current->NextNode;
        }
        printf("List[%zu] : %d\n", i, Current->Data);
    }
    printf("\nDestroying List...\n");

    CLL_DestroyList(List);
}
int main(void)
{
    int ListNumber = 0;

    switch (ListNumber) {
    case 0:
        TestAL();
        break;
    case 1:
        TestSLL();
        break;
    case 2:
        TestDLL();
        break;
    case 3:
        TestCLL();
        break;
    }
    return 0;
}
