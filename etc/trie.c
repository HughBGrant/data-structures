#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TrieNode {
    struct TrieNode *children[26];
    bool isEnd;
} TrieNode;

TrieNode *newNode(void)
{
    return calloc(1, sizeof(TrieNode)); // zeroed links and isEnd
}

void insert(TrieNode *root, const char *word)
{
    for (; *word; word++) {
        int i = *word - 'a';
        if (root->children[i] == NULL)
            root->children[i] = newNode();
        root = root->children[i];
    }
    root->isEnd = true;
}

// Follow the path for s; NULL if a link is missing
TrieNode *walk(TrieNode *root, const char *s)
{
    for (; *s; s++) {
        root = root->children[*s - 'a'];
        if (root == NULL)
            return NULL;
    }
    return root;
}

bool search(TrieNode *root, const char *word)
{
    TrieNode *node = walk(root, word);
    return node != NULL && node->isEnd;
}

bool startsWith(TrieNode *root, const char *prefix)
{
    return walk(root, prefix) != NULL;
}

// int main(void)
//{
//     TrieNode *root = newNode();
//     const char *words[] = {"car", "card", "care", "dog"};
//     for (int i = 0; i < 4; i++)
//         insert(root, words[i]);
//     printf("search(card): %s\n", search(root, "card") ? "true" : "false");
//     printf("search(ca): %s\n", search(root, "ca") ? "true" : "false");
//     printf("startsWith(ca): %s\n", startsWith(root, "ca") ? "true" : "false");
//     printf("startsWith(dot): %s\n", startsWith(root, "dot") ? "true" : "false");
//     return 0;
// }