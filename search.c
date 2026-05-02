#include"invert.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int search_word(main_node *name[], char *word)
{
    if (word == NULL || word[0] == '\0')// check for null or empty string
    return FAILURE;
   int index=tolower(word[0]) - 'a';// calculate index based on first character of word
     if (index < 0 || index >= 26)
    index = 26; 
    main_node *mtemp=name[index];// loop through main nodes for the calculated index
    while(mtemp!=NULL)
    {
        if(strcmp(mtemp->word,word)==0)
        {
            printf("word %s found in %d files\n",word,mtemp->f_count);// print message for word found and file count
             sub_node *stemp=mtemp->link;// loop through sub nodes linked to main node
            while(stemp!=NULL)
            {
                printf("File name:%s,word count:%d\n",stemp->f_name,stemp->w_count);// print file name and word count for each sub node
                stemp=stemp->next;
            }
            return SUCCESS;
        }
        mtemp=mtemp->next;// move to next main node
    }
    printf("word not found %s\n",word);// print message for word not found
    return FAILURE;
}