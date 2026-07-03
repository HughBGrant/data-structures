#include "array_list.h"

AL *AL_CreateList(size_t Capacity)
{
    AL *List = malloc(sizeof(AL));
    if (List == NULL) {
        return NULL;
    }
    List->Array = malloc(sizeof(AL_DataType) * Capacity);
    if (List->Array == NULL) {
        free(List);
        return NULL;
    }
    List->Capacity = Capacity;
    List->Count = 0;

    return List;
}
void AL_AppendTail(AL *List, AL_DataType NewData)
{
    if (List == NULL || List->Count >= List->Capacity) {
        return;
    }
    List->Array[List->Count] = NewData;
    List->Count++;
}
void AL_Insert(AL *List, size_t Location, AL_DataType NewData)
{
    if (List == NULL || Location > List->Count ||
        List->Count >= List->Capacity) {
        return;
    }
    for (size_t i = List->Count; i > Location; i--) {
        List->Array[i] = List->Array[i - 1];
    }
    List->Array[Location] = NewData;
    List->Count++;
}
void AL_Remove(AL *List, size_t Location)
{
    if (List == NULL || Location >= List->Count) {
        return;
    }
    for (size_t i = Location; i < List->Count - 1; i++) {
        List->Array[i] = List->Array[i + 1];
    }
    List->Count--;
}
void AL_DestroyList(AL *List)
{
    if (List == NULL) {
        return;
    }
    free(List->Array);
    free(List);
}
size_t AL_GetSize(AL *List)
{
    if (List == NULL) {
        return 0;
    }
    return List->Count;
}