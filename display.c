#include "invert.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int display(main_node *name[])
{
   printf("index\tword\tfilecount\tfilename\twcount\n");// print header for display
    for(int i=0;i<28;i++)
    {
        main_node *mtemp=name[i];// loop through main nodes for each index
       
        while(mtemp!=NULL)
        {  
        
            
            sub_node *stemp=mtemp->link;// loop through sub nodes linked to main node
            int first =1;
            while(stemp!=NULL)
            {
                if(first)
                {
                printf("%d\t%s\t%d\t\t%s\t\t%d\n",i,mtemp->word,mtemp->f_count,stemp->f_name,stemp->w_count);// print index, word, file count, file name and word count for first sub node
                first=0;
                }
                else
                {
                    printf("\t\t\t\t%s\t\t%d\n",stemp->f_name,stemp->w_count);
                    first=1;
                    
                }
                stemp=stemp->next;
            }
            mtemp = mtemp->next;// move to next main node
            // printf("\n");
        }
       
    }
    return SUCCESS;
}