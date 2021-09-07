/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD02A_karl_erik_stoerzel
** File description:
** test_main.c
*/

#include <lzma.h>
#include <stdlib.h>
#include "tree_traversal.h"
#include "stack.h"
#include "queue.h"
#include "generic_list.h"
#include <stdio.h>
#include <string.h>

void dump_int ( void * data )
{
    printf ("%s\n", ( char *) data) ;

}
bool generic_push_stack ( void * container , void * data )
{
    return stack_push (( stack_t *) container , data ) ;
}
void * generic_pop_stack ( void * container )
{
    void * data = stack_top (*( stack_t *) container ) ;
    stack_pop (( stack_t *) container ) ;
    return data ;
}
bool generic_push_queue ( void * container , void * data )
{
    return queue_push (( queue_t *) container , data ) ;
}
void * generic_pop_queue ( void * container )
{
    void * data = queue_front (*( queue_t *) container ) ;
    queue_pop (( queue_t *) container ) ;
    return data ;
}
static void test_depth ( tree_t tree )
{
    container_t container ;
    stack_t stack = NULL ;
    printf (" Depth walk :\n") ;
    container . container = & stack ;
    container . push_func = & generic_push_stack ;
    container . pop_func = & generic_pop_stack ;
    tree_traversal ( tree , & container , & dump_int ) ;
}
static void test_width ( tree_t tree )
{
    container_t container ;
    queue_t queue = NULL ;
    printf (" Width walk :\n") ;
    container . container = & queue ;
    container . push_func = & generic_push_queue ;
    container . pop_func = & generic_pop_queue ;
    tree_traversal ( tree , & container , &dump_int ) ;
}

static void fill_tree ( tree_t tree )
{
    char *val_a = strdup("1");
//    char val_a = 1;
    char *val_aa = strdup("11");
//    int val_aa = 11;
    char *val_b = strdup("2");
//    int val_b = 2;
    char *val_c = strdup("3");
//    int val_c = 3;
    char *val_ca = strdup("31");
//    int val_ca = 31;
    char *val_cb = strdup("32");
//    int val_cb = 32;
    char *val_cc = strdup("33");
//    int val_cc = 33;
    tree_node_t *node = NULL;
    node = tree_add_child(tree, val_a);
    tree_add_child(node, val_aa);
    tree_add_child(tree, val_b);
    node = tree_add_child(tree, val_c);
    tree_add_child(node, val_ca);
    tree_add_child(node, val_cb);
    tree_add_child(node, val_cc);
}

int main ( void )
{
    char *val_0 = strdup("0");
    tree_t tree = NULL ;
    init_tree (& tree , val_0 ) ;
    fill_tree ( tree ) ;
    test_depth(tree);
    test_width(tree);
    tree_destroy(&tree);
//    int g = *(int *)((tree_t)tree->children->next->value)->data;
//    (&dump_int)(&g);
//    (&dump_int)(((tree_t)tree->children->next->value)->data);
return 0;
}
//
//int int_comparator ( void * first , void * second )
//{
//    int val1 = *( int *) first ;
//    int val2 = *( int *) second ;
//    return ( val1 - val2 ) ;
//}
//
//int cmp(void * first, void * second)
//{
//    return strcmp(first, second);
//}
//
//int main ( void )
//{
//    map_t map = NULL ;
////    int first_key = 1;
//    char *first_key = "1";
////    int second_key = 2;
//    char *second_key = "2";
////    int third_key = 3;
//    char *third_key = "3";
//    char * first_value = " first ";
//    char * first_value_rw = " first_rw ";
//    char * second_value = " nice ";
//    char * third_value = " third ";
//    char * data = NULL ;
//    map_add_elem (& map ,  first_key ,  first_value , & cmp ) ;
//    map_add_elem (& map ,  first_key ,  first_value_rw , & cmp ) ;
//    map_add_elem (& map ,  second_key ,  second_value , & cmp ) ;
//    map_add_elem (& map ,  third_key ,  third_value , & cmp ) ;
//    map_add_elem (& map ,  second_key ,  second_value , & cmp ) ;
//    data = ( char *) map_get_elem ( map ,  second_value , & cmp ) ;
//    for (; map; map = map->next)
//        printf ("The key [%s] maps to value [%s]\n",
//                (char* )((pair_t *)map->value)->key ,(char *)((pair_t *)
//                map->value)->key
//        ) ;
//
//    printf ("The key [%s] maps to value [%s]\n", second_key , data == NULL ?
//    "null" : data) ;
//    return 0;
//}