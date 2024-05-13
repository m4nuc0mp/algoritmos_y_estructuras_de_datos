#include "btree_base.h"

/**************************************************************/
/*                       NOMENCLATURAS                        */
/**************************************************************/
/**
 * BT - Binary Tree: Árbol binario.
 * BTN - binary tree node: nodo de árbol binario.
 * SBT - Search Binary Tree: ABB - Árbol binario de búsqueda.
 * AVL - AVL Tree: Árbol AVL.
 * root: nodo raíz del árbol.
 * parent node: nodo padre.
 * child node: nodo hijo.
 * internal node,
 * inner node,
 * inode,
 * branch node: nodo interno, que tiene hijos.
 * external node,
 * leaf node,
 * outer node,
 * terminal node: nodo hoja de un árbol.
 */
/**************************************************************/


/**************************************************************/
/*                     ÁRBOLES BINARIOS                       */
/**************************************************************/

/**
 * Crea un nodo de un BTN en base a un valor t_elem_btree
 */
btn* btn_new(t_elem_btree value) {
    /**** COMPLETAR ****/
    btn* newnodo = (btn*) malloc(sizeof(btn));

    if (NULL != newnodo)
    {
        newnodo->value = value;
        newnodo->left = NULL;
        newnodo->right = NULL;
    }
    return newnodo;
}

/**
 * Elimina un nodo, si tiene hijos elimina sus hijos también.
 */
void btn_free(btn** node) {
    /**** COMPLETAR ****/
    if (NULL != *node)
    {
        btn_free(&(*node)->left);
        btn_free(&(*node)->right);
        free(*node);
    }
}

/** 
 * Busca un nodo con un determinado elemento y devuelve su referencia
 * Se busca el nodo en pre-order (debe recorrer todo el árbol no hay un criterio de ordenamiento)
 * Debe devolver la referencia a la ubicación del puntero al nodo. Si no existe, devuelve NULL
 */ 
btn** btn_find(btn** node, t_elem_btree value, int cmp(t_elem_btree, t_elem_btree)) {
    /**** COMPLETAR ****/
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

/**
 * Devuelve 1 si el nodo es una hoja.
 * Devuelve 0 si no es una hoja.
 */
int btn_isLeaf(btn *node) {
    /**** COMPLETAR ****/
    int is_a_leaf = 0;

    if ( (NULL == node->left) && (NULL == node->right) )
    {
        is_a_leaf = 1;
    }
    return is_a_leaf;
}

/**
 * Cuenta la cantidad de nodos de un árbol binario.
 */
int btn_count(btn *node) {
    int result = 0;
    if (node != NULL) {
        result = 1 + btn_count(node->left) + btn_count(node->right);
    }
    return result;
}

/**
 * Agrega un nodo en un árbol binario con el siguiente criterio:
 * - Si el subárbol es nulo se agrega ahí,
 * - Si no es NULL lo agrega en el hijo con menor cantidad de nodos,
 * - Si sus hijos tienen la misma cantidad de nodos lo agrega a la izquierda.
 */
int btn_insert(btn **node, btn *newNode) {
    /**** COMPLETAR ****/
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

/**
 * Agrega un valor a un BT con el criterio:
 * - Si el subárbol es nulo se agrega ahí,
 * - Si no es NULL lo agrega en el hijo con menor cantidad de nodos,
 * - Si sus hijos tienen la misma cantidad de nodos lo agrega a la izquierda.
 */
int btn_insert_value(btn **node, int value) {
    /**** COMPLETAR ****/
    btn* newnodo = btn_new(value);

    return btn_insert(node, newnodo);
}


/**
 * Determinar el nivel de un nodo.
 * - Recibe como entrada la raíz, un valor y una función de comparación de valores.
 */
int _btn_level(btn *node, t_elem_btree value, int level, int cmp(t_elem_btree, t_elem_btree)) {
    /**** COMPLETAR ****/

    // Consultar!!
}

int btn_level(btn* root, t_elem_btree value, int cmp(t_elem_btree, t_elem_btree)) {
    /**** COMPLETAR ****/

    // Consultar!!
}

/**
 * Comparar dos valores
 * - Devuelve -1 si a < b, 0 si son iguales, 1 si a > b 
 */
int cmp(t_elem_btree value_a, t_elem_btree value_b)
{
    if (value_a > value_b)
    {
        return 1;
    }
    else if (value_a < value_b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}


/**
 * Devuelve el valor máximo entre 2 enteros.
 * Función auxiliar utilizada en height.
 */
int _max(int a, int b) { return (a > b) ? a : b; }

/**
 * Devuelve la altura de un BTN
 */
t_elem_btree btn_height(btn *node) {
    int result = -1;
    /**** COMPLETAR ****/
    
    return result;
}

/**
 * Recorrido de un BT en inorden
 */
void btn_inorder(btn *node, void btn_do(btn*, void*), void* ctx) {
    if (!node) return;

    /**** COMPLETAR ****/
    btn_inorder(node->left, btn_do, ctx);
    btn_do(node, ctx);
    btn_inorder(node->right, btn_do, ctx);
}

/**
 * Recorrido de un BT en postorder
 */
void btn_postorder(btn *node, void btn_do(btn*, void*), void* ctx) {
    if (!node) return;

    /**** COMPLETAR ****/
    btn_postorder(node->left, btn_do, ctx);
    btn_postorder(node->right, btn_do, ctx);
    btn_do(node, ctx);
}

/**
 * Recorrido de un BT en preorder
 */
void btn_preorder(btn *node, void btn_do(btn*, void*), void* ctx) {
    if (!node) return;

    /**** COMPLETAR ****/
    bnt_do(node, ctx);
    btn_preorder(node->left, btn_do, ctx);
    btn_preorder(node->right, btn_do,ctx);
}

void btn_do(btn* node, void* ctx) {
    char* format = (char*) ctx;

    printf("%*d", format, node->value);
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






