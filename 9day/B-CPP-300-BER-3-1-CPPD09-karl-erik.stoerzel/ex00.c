/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD09_karl_erik_stoerzel
** File description:
** ex00.c
*/

#include "ex00.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//general
static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend);
static void cthulhu_initializer(cthulhu_t *this);

static void cthulhu_initializer(cthulhu_t *this)
{
    this->m_name = strdup("Cthulhu");
    this->m_power = 42;
    printf("Building %s\n", this->m_name);
}

cthulhu_t *new_cthulhu()
{
    printf("----\n");
    cthulhu_t *this = malloc(sizeof(cthulhu_t));
    cthulhu_initializer(this);
    return this;
}

void print_power(cthulhu_t *this)
{
    printf("Power => %i\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42)
    {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->m_name);
    }
    else
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void sleeping(cthulhu_t *this)
{
    printf("%s sleeps\n", this->m_name);
    this->m_power += 42000;
}

static void koala_initializer(koala_t *this, char *name, char _is_A_Legend)
{
    this->m_is_a_legend = _is_A_Legend;
    this->m_parent = *new_cthulhu();
    free(this->m_parent.m_name);
    this->m_parent.m_name = strdup(name);
    if (_is_A_Legend == 0)
        this->m_parent.m_power = 0;
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *this = malloc(sizeof(koala_t));
    koala_initializer(this, name, is_a_legend);
    printf("Building %s\n", this->m_parent.m_name);
    return this;
}

void eat(koala_t *this)
{
    this->m_parent.m_power += 42;
    printf("%s eats\n", this->m_parent.m_name);
}

//int main ()
//{
//    koala_t * _lkoala = new_koala ("Legend", 1) ;
//    koala_t * _nlkoala = new_koala ("NotLegend", 0) ;
//    cthulhu_t * _cthulhu = new_cthulhu () ;
//    printf (" ----Start - - - -\n") ;
//    print_power ( _cthulhu ) ;
//    print_power (& _lkoala -> m_parent ) ;
//    print_power (& _nlkoala -> m_parent ) ;
//    attack ( _cthulhu ) ;
//    attack (& _lkoala -> m_parent ) ;
//    attack (& _nlkoala -> m_parent ) ;
//    eat ( _nlkoala ) ;
//    attack ( _cthulhu ) ;
//    sleeping ( _cthulhu ) ;
//    print_power ( _cthulhu ) ;
//    attack (& _nlkoala -> m_parent ) ;
//    return 0;
//}