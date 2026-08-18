#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 8

// Separate chaining: each bucket is a linked list of entries
typedef struct Entry {
    char key[16];
    int value;
    struct Entry *next;
} Entry;

Entry *buckets[CAPACITY];

unsigned int hash(const char *key)
{
    unsigned int h = 5381; // djb2, then modulo the bucket count
    for (; *key; key++)
        h = h * 33 + (unsigned char)*key;
    return h % CAPACITY;
}

void set(const char *key, int value)
{
    unsigned int i = hash(key);
    for (Entry *e = buckets[i]; e != NULL; e = e->next) {
        if (strcmp(e->key, key) == 0) {
            e->value = value; // update existing key
            return;
        }
    }
    Entry *e = malloc(sizeof(Entry));
    strcpy(e->key, key);
    e->value = value;
    e->next = buckets[i];
    buckets[i] = e;
}

int *get(const char *key)
{
    for (Entry *e = buckets[hash(key)]; e != NULL; e = e->next) {
        if (strcmp(e->key, key) == 0)
            return &e->value;
    }
    return NULL;
}

void removeKey(const char *key)
{
    Entry **link = &buckets[hash(key)];
    while (*link != NULL) {
        if (strcmp((*link)->key, key) == 0) {
            Entry *old = *link;
            *link = old->next;
            free(old);
            return;
        }
        link = &(*link)->next;
    }
}

void printBuckets(void)
{
    for (int i = 0; i < CAPACITY; i++) {
        printf("bucket %d:", i);
        for (Entry *e = buckets[i]; e != NULL; e = e->next) {
            printf(" (%s=%d)", e->key, e->value);
        }
        printf("\n");
    }
}

// int main(void)
//{
//     set("apple", 3);
//     set("banana", 7);
//     set("apple", 4); // overwrites the old value
//     set("grape", 9);
//     printBuckets();
//     int *value = get("apple");
//     printf("get(apple): %d\n", value ? *value : -1);
//     removeKey("banana");
//     printf("banana after remove: %s\n", get("banana") ? "found" : "not found");
//     return 0;
// }