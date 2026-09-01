#include "red_black_tree.h"
#include <string.h>

extern rbt_node *Nil;

rbt_node *rbt_node_create(rbt_item NewData)
{
    rbt_node *NewNode = (rbt_node *)malloc(sizeof(rbt_node));
    NewNode->parent = NULL;
    NewNode->left = NULL;
    NewNode->right = NULL;
    NewNode->data = NewData;
    NewNode->Color = BLACK;

    return NewNode;
}

void rbt_node_destroy(rbt_node *Node)
{
    free(Node);
}

void rbt_destroy(rbt_node *Tree)
{
    if (Tree->right != Nil)
        rbt_destroy(Tree->right);

    if (Tree->left != Nil)
        rbt_destroy(Tree->left);

    Tree->left = Nil;
    Tree->right = Nil;

    rbt_node_destroy(Tree);
}

rbt_node *rbt_node_search(rbt_node *Tree, rbt_item Target)
{
    if (Tree == Nil)
        return NULL;

    if (Tree->data > Target)
        return rbt_node_search(Tree->left, Target);
    else if (Tree->data < Target)
        return rbt_node_search(Tree->right, Target);
    else
        return Tree;
}

rbt_node *rbt_node_search_min(rbt_node *Tree)
{
    if (Tree == Nil)
        return Nil;

    if (Tree->left == Nil)
        return Tree;
    else
        return rbt_node_search_min(Tree->left);
}

void rbt_node_insert(rbt_node **Tree, rbt_node *NewNode)
{
    rbt_node_insert_helper(Tree, NewNode);

    NewNode->Color = RED;
    NewNode->left = Nil;
    NewNode->right = Nil;

    rbt_rebuild_after_insert(Tree, NewNode);
}

void rbt_node_insert_helper(rbt_node **Tree, rbt_node *NewNode)
{
    if ((*Tree) == NULL)
        (*Tree) = NewNode;

    if ((*Tree)->data < NewNode->data) {
        if ((*Tree)->right == Nil) {
            (*Tree)->right = NewNode;
            NewNode->parent = (*Tree);
        } else
            rbt_node_insert_helper(&(*Tree)->right, NewNode);

    } else if ((*Tree)->data > NewNode->data) {
        if ((*Tree)->left == Nil) {
            (*Tree)->left = NewNode;
            NewNode->parent = (*Tree);
        } else
            rbt_node_insert_helper(&(*Tree)->left, NewNode);
    }
}

void rbt_rotate_right(rbt_node **Root, rbt_node *Parent)
{
    rbt_node *LeftChild = Parent->left;

    Parent->left = LeftChild->right;

    if (LeftChild->right != Nil)
        LeftChild->right->parent = Parent;

    LeftChild->parent = Parent->parent;

    if (Parent->parent == NULL)
        (*Root) = LeftChild;
    else {
        if (Parent == Parent->parent->left)
            Parent->parent->left = LeftChild;
        else
            Parent->parent->right = LeftChild;
    }

    LeftChild->right = Parent;
    Parent->parent = LeftChild;
}

void rbt_rotate_left(rbt_node **Root, rbt_node *Parent)
{
    rbt_node *RightChild = Parent->right;

    Parent->right = RightChild->left;

    if (RightChild->left != Nil)
        RightChild->left->parent = Parent;

    RightChild->parent = Parent->parent;

    if (Parent->parent == NULL)
        (*Root) = RightChild;
    else {
        if (Parent == Parent->parent->left)
            Parent->parent->left = RightChild;
        else
            Parent->parent->right = RightChild;
    }

    RightChild->left = Parent;
    Parent->parent = RightChild;
}

void rbt_rebuild_after_insert(rbt_node **Root, rbt_node *X)
{
    while (X != (*Root) && X->parent->Color == RED) {
        if (X->parent == X->parent->parent->left) {
            rbt_node *Uncle = X->parent->parent->right;
            if (Uncle->Color == RED) {
                X->parent->Color = BLACK;
                Uncle->Color = BLACK;
                X->parent->parent->Color = RED;

                X = X->parent->parent;
            } else {
                if (X == X->parent->right) {
                    X = X->parent;
                    rbt_rotate_left(Root, X);
                }

                X->parent->Color = BLACK;
                X->parent->parent->Color = RED;

                rbt_rotate_right(Root, X->parent->parent);
            }
        } else {
            rbt_node *Uncle = X->parent->parent->left;
            if (Uncle->Color == RED) {
                X->parent->Color = BLACK;
                Uncle->Color = BLACK;
                X->parent->parent->Color = RED;

                X = X->parent->parent;
            } else {
                if (X == X->parent->left) {
                    X = X->parent;
                    rbt_rotate_right(Root, X);
                }

                X->parent->Color = BLACK;
                X->parent->parent->Color = RED;
                rbt_rotate_left(Root, X->parent->parent);
            }
        }
    }

    (*Root)->Color = BLACK;
}

rbt_node *rbt_node_delete(rbt_node **Root, rbt_item Data)
{
    rbt_node *Removed = NULL;
    rbt_node *Successor = NULL;
    rbt_node *Target = rbt_node_search((*Root), Data);

    if (Target == NULL)
        return NULL;

    if (Target->left == Nil || Target->right == Nil) {
        Removed = Target;
    } else {
        Removed = rbt_node_search_min(Target->right);
        Target->data = Removed->data;
    }

    if (Removed->left != Nil)
        Successor = Removed->left;
    else
        Successor = Removed->right;

    Successor->parent = Removed->parent;

    if (Removed->parent == NULL)
        (*Root) = Successor;
    else {
        if (Removed == Removed->parent->left)
            Removed->parent->left = Successor;
        else
            Removed->parent->right = Successor;
    }

    if (Removed->Color == BLACK)
        rbt_rebuild_after_delete(Root, Successor);

    return Removed;
}

void rbt_rebuild_after_delete(rbt_node **Root, rbt_node *Successor)
{
    rbt_node *Sibling = NULL;

    while (Successor->parent != NULL && Successor->Color == BLACK) {
        if (Successor == Successor->parent->left) {
            Sibling = Successor->parent->right;

            if (Sibling->Color == RED) {
                Sibling->Color = BLACK;
                Successor->parent->Color = RED;
                rbt_rotate_left(Root, Successor->parent);
            } else {
                if (Sibling->left->Color == BLACK &&
                    Sibling->right->Color == BLACK) {
                    Sibling->Color = RED;
                    Successor = Successor->parent;
                } else {
                    if (Sibling->left->Color == RED) {
                        Sibling->left->Color = BLACK;
                        Sibling->Color = RED;

                        rbt_rotate_right(Root, Sibling);
                        Sibling = Successor->parent->right;
                    }

                    Sibling->Color = Successor->parent->Color;
                    Successor->parent->Color = BLACK;
                    Sibling->right->Color = BLACK;
                    rbt_rotate_left(Root, Successor->parent);
                    Successor = (*Root);
                }
            }
        } else {
            Sibling = Successor->parent->left;

            if (Sibling->Color == RED) {
                Sibling->Color = BLACK;
                Successor->parent->Color = RED;
                rbt_rotate_right(Root, Successor->parent);
            } else {
                if (Sibling->right->Color == BLACK &&
                    Sibling->left->Color == BLACK) {
                    Sibling->Color = RED;
                    Successor = Successor->parent;
                } else {
                    if (Sibling->right->Color == RED) {
                        Sibling->right->Color = BLACK;
                        Sibling->Color = RED;

                        rbt_rotate_left(Root, Sibling);
                        Sibling = Successor->parent->left;
                    }

                    Sibling->Color = Successor->parent->Color;
                    Successor->parent->Color = BLACK;
                    Sibling->left->Color = BLACK;
                    rbt_rotate_right(Root, Successor->parent);
                    Successor = (*Root);
                }
            }
        }
    }

    Successor->Color = BLACK;
}

void rbt_node_print(rbt_node *Node, int Depth, int BlackCount)
{
    int i = 0;
    char c = 'X';
    int v = -1;
    char cnt[100];

    if (Node == NULL || Node == Nil)
        return;

    if (Node->Color == BLACK)
        BlackCount++;

    if (Node->parent != NULL) {
        v = Node->parent->data;

        if (Node->parent->left == Node)
            c = 'L';
        else
            c = 'R';
    }

    if (Node->left == Nil && Node->right == Nil)
        sprintf(cnt, "--------- %d", BlackCount);
    else
        strncpy(cnt, "", sizeof(cnt));

    for (i = 0; i < Depth; i++)
        printf("  ");

    printf("%d %s [%c,%d] %s\n", Node->data,
           (Node->Color == RED) ? "RED" : "BLACK", c, v, cnt);

    rbt_node_print(Node->left, Depth + 1, BlackCount);
    rbt_node_print(Node->right, Depth + 1, BlackCount);
}
