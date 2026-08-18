#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKETS 16

typedef struct Node {
    char key[24];
    int value;
    struct Node *next;
} Node;

// A small string -> int hash map with a reusable put/get/remove API
typedef struct {
    Node *buckets[BUCKETS];
    int size;
} HashMap;

unsigned int hashKey(const char *key)
{
    unsigned int h = 5381;
    for (; *key; key++)
        h = h * 33 + (unsigned char)*key;
    return h % BUCKETS;
}

void mapPut(HashMap *map, const char *key, int value)
{
    unsigned int i = hashKey(key);
    for (Node *n = map->buckets[i]; n != NULL; n = n->next) {
        if (strcmp(n->key, key) == 0) {
            n->value = value;
            return;
        }
    }
    Node *n = malloc(sizeof(Node));
    strcpy(n->key, key);
    n->value = value;
    n->next = map->buckets[i];
    map->buckets[i] = n;
    map->size++;
}

bool mapGet(const HashMap *map, const char *key, int *out)
{
    for (Node *n = map->buckets[hashKey(key)]; n != NULL; n = n->next) {
        if (strcmp(n->key, key) == 0) {
            *out = n->value;
            return true;
        }
    }
    return false;
}

void mapRemove(HashMap *map, const char *key)
{
    Node **link = &map->buckets[hashKey(key)];
    while (*link != NULL) {
        if (strcmp((*link)->key, key) == 0) {
            Node *old = *link;
            *link = old->next;
            free(old);
            map->size--;
            return;
        }
        link = &(*link)->next;
    }
}

int main(void)
{
    HashMap map = {0};
    mapPut(&map, "alice", 30);
    mapPut(&map, "bob", 25);
    mapPut(&map, "carol", 41);
    mapPut(&map, "alice", 31); // updates the existing key
    int age;
    if (mapGet(&map, "bob", &age))
        printf("bob is %d\n", age);
    printf("has dave: %s\n", mapGet(&map, "dave", &age) ? "yes" : "no");
    mapRemove(&map, "carol");
    printf("size: %d\n", map.size);
    return 0;
}