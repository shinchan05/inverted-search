#ifndef INVERT_H
#define INVERT_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 1
#define FAILURE 0 

typedef struct s_node
{
    char *f_name;
    int w_count;
    struct s_node *next;
}sub_node;

typedef struct m_node
{
    char *word;
    int f_count;
    struct m_node *next;
    struct s_node *link;
}main_node;

typedef struct f_node
{
    char *f_name;
    struct f_node *link;
}file_node;

extern  main_node *name[28];



int create_db( main_node *name[], char *valid_files[],int count);
int search_word(main_node *name[], char *word);
int display(main_node *name[]);
int save(main_node *name[]);
int update(main_node *name[]);






#endif

