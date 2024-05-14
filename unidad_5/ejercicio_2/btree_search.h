#ifndef BTREE_SEARCH_H_INCLUDED
#define BTREE_SEARCH_H_INCLUDED

#include "btree_base.h"

t_elem_btree _max_elem (
    t_elem_btree a, t_elem_btree b, int cmp (t_elem_btree, t_elem_btree));

int sbt_insert_node(
    btn **node, btn *newNode, int cmp (t_elem_btree, t_elem_btree));

int sbt_insert_value(
    btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));

btn** sbt_get_min_node(btn **node);

t_elem_btree sbt_min(btn *node);

btn** sbt_get_max_node(btn **node);

t_elem_btree sbt_get_max_value(btn *node);

btn* sbt_findr(
    btn *node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));

btn *sbt_findi(
    btn *node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));

btn** sbt_find_node(
    btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));

btn** sbt_findii(
    btn** node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));

int sbt_in(
    btn* node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));

btn* sbt_remove_node(btn **node,  int cmp (t_elem_btree, t_elem_btree));

btn* sbt_remove_node2(btn **node);

btn *sbt_remove_node_smart(btn **node);

int sbt_remove_value(
    btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));

int sbt_remove_value2(
    btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));

int sbt_remove_value_smart(
    btn **node, int value, int cmp (t_elem_btree, t_elem_btree));


#endif // BTREE_SEARCH_H_INCLUDED