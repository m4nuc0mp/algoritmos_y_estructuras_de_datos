#include "btree_base.h"

#define t_elem_btree int

typedef struct _btn
{
    t_elem_btree value;
    struct _btn *left;
    struct _btn *right;
} btn;

btn*
btn_new(t_elem_btree value)
{
    btn* new_node = (btn*) malloc(sizeof(btn));

    if (NULL != new_node)
    {
        new_node->value = value;
        
        new_node->left = NULL;

        new_node->right = NULL;
    }

    return new_node;    
}

void
btn_free(btn** node)
{
    if (NULL != *node)
    {
        btn_free(&(*node)->left);

        btn_free(&(*node)->right);
        
        free(*node);
    }    
}

btn**
btn_find(btn** node, t_elem_btree value, int cmp(t_elem_btree, t_elem_btree))
{
    if ((NULL == *node) || cmp(value, (*node)->value))
    {
        return node;
    }
    else if (value < (*node)->value)
    {
        btn_find(&(*node)->left, value, cmp);
    }
    else
    {
        btn_find(&(*node)->right, value, cmp);
    }
}

int
btn_isLeaf(btn *node)
{
    int is_a_leaf = 0;

    if ( (NULL == node->left) && (NULL == node->right) )
    {
        is_a_leaf = 1;
    }

    return is_a_leaf;
}

int
btn_count(btn *node)
{
    int result = 0;
    
    if (node != NULL)
    {
        result = 1 + btn_count(node->left) + btn_count(node->right);
    }

    return result;
}

int
btn_insert(btn **node, btn *newNode)
{
    int success = 1;
    int left_childs = btn_count((*node)->left);
    int right_childs = btn_count((*node)->right);

    if (NULL == *node)
    {
        *node = newNode;
    }
    else if (left_childs <= right_childs)
    {
        btn_insert(&(*node)->left, newNode);
    }
    else if (left_childs > right_childs)
    {
        btn_insert(&(*node)->right, newNode);
    }
    else
    {
        success = 0;
    }
    return success;
}

int
btn_insert_value(btn **node, int value)
{
    btn* new_node = btn_new(value);

    return btn_insert(node, new_node);
}

int
_btn_level(btn *node, t_elem_btree value, int level, int cmp(t_elem_btree, t_elem_btree)) {
    /**** COMPLETAR ****/
}

int
btn_level(btn* root, t_elem_btree value, int cmp(t_elem_btree, t_elem_btree))
{
    // if (NULL == root)
    // {
    //     return 0;
    // }
    // else if ()
    // {

    // }
}

int
cmp(t_elem_btree value_a, t_elem_btree value_b)
{
    
}

int
_max(int a, int b)
{
    return (a > b) ? a : b;
}

t_elem_btree
btn_height(btn *node)
{
    int result = -1;
    /**** COMPLETAR ****/

    return result;
}

void
btn_inorder(btn *node, void btn_do(btn*, void*), void* ctx)
{
    if (!node) return;

    /**** COMPLETAR ****/
}

void
btn_postorder(btn *node, void btn_do(btn*, void*), void* ctx)
{
    if (!node) return;

    /**** COMPLETAR ****/
}

void
btn_preorder(btn *node, void btn_do(btn*, void*), void* ctx)
{
    if (!node) return;

    /**** COMPLETAR ****/
}


/**************************************************************/
/*                         ADICIONALES                        */
/**************************************************************/

/**
 * DE USO INTERNO para dibujar un árbol.
 */
int _btn_print(btn *tree, int is_left, int offset, int depth, char s[20][255], void toStr (btn*, char*)) {
    char b[200];
    int width = 5;

    if (!tree) return 0;
    toStr(tree, b);
    //sprintf(b, "%s", str);
    

    int left = _btn_print(tree->left, 1, offset, depth + 1, s, toStr);
    int right = _btn_print(tree->right, 0, offset + left + width, depth + 1, s, toStr);

    // for (int i = 0; i < width; i++) s[2 * depth][offset + left + i] = b[i];
    for (int i = 0; i < strlen(b); i++) s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {
        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

    } else if (depth && !is_left) {
        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset - width / 2 - 1] = '+';
    }
    
    return left + width + right;
}

/**
 * Dibuja un árbol binario con caracteres
 * (Los valores de los nodos deben estar entre 0 y 999).
 */
void btn_print(btn *tree, void toStr (btn*, char*)) {
    char s[20][255];
    for (int i = 0; i < 20; i++) sprintf(s[i], "%80s", " ");

    _btn_print(tree, 0, 0, 0, s, toStr);

    for (int i = 0; i < 20; i++) {
        int j = 0;
        while (s[i][j] != '\0' && s[i][j] == ' ') {
            j++;
        }
        if (s[i][j] != '\0') {
            printf("%s\n", s[i]);
        }
    }
}






