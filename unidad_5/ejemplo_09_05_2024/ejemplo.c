#include <stdio.h>
#include <stdlib.h>

/*
    _1_____
 _2_      __3__
4   5    6    _7
             8
*/

typedef struct _btn {
    int value;
    struct _btn *left;
    struct _btn *right;
} btn;

int main(void)
{
    btn* nodes[8];

    for (int i = 0; i < 8; i++)
    {
        nodes[i] = btn_new(i+1);
    }
    nodes[0]->left = nodes[1]->value;
    nodes[1]->right = nodes[2]->value;
    nodes[2]->left = nodes[3]->value;
    nodes[2]->right = nodes[4]->value;
    nodes[3]->left = nodes[5]->value;
    nodes[3]->right = nodes[6]->value;
    nodes[6]->left = nodes[7]->value;
}

void sort_tree(btn* node)
{
    while ((node->left != NULL) || (node->right))
    {
        
    }
    
}

btn* btn_new(int value) {
    btn* new_node = (btn*) malloc(sizeof(btn));

    if (NULL != new_node)
    {
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}