#include"invert.h"
#include<stdio.h>
int save(main_node *name[])
{
    top:// label for goto statement to ask user for file name again if file is not empty and user chooses not to overwrite
    printf("Enter the the Backup file name ending with.txt   ");// read file name to save database
    char c[100];
    scanf("%s",c);
    char s[5]={".txt"};
       char *ptr;
        (ptr=strstr(c,s));
        
            if((ptr==NULL)||((strcmp(ptr,s)!=0)|| strlen(ptr) != strlen(s)))// check for valid file extension
            {
                printf("%s extension should be filename<.txt>\n",c);
                return FAILURE;
            }
    FILE *fp=fopen(c,"w");
    if(fp==NULL)    
    {
        printf("Error opening file %s\n",c);// check for file opening error
        return FAILURE;
    }
    if (fgetc(fp) == EOF)
        {
            printf("saving to an empty file\n");
            
        }
        else
        {
           printf("File is not empty,Enter 'y' to overwrite or 'n' to cancel: ");// check if file is empty or not and ask user for confirmation to overwrite
            char cont;
            scanf(" %c",&cont);
            if(cont=='n' || cont=='N')
            {
                printf("Save cancelled,Enter diffrent file name \n");
                fclose(fp);
                goto top;
            }
            else if(cont!='y' && cont!='Y')
            {
                printf("Invalid input, save cancelled Enter diffrent file name\n");
                fclose(fp);
                goto top;
            }
        }
fseek(fp, 0, SEEK_SET);
    for(int i=0;i<27;i++)
    {
        main_node *mtemp=name[i];
        while(mtemp!=NULL)
        {
            fprintf(fp,"#%d;%s;%d;",i,mtemp->word,mtemp->f_count);// write index, word and file count to file
            sub_node *stemp=mtemp->link;
            while(stemp!=NULL)
            {
                fprintf(fp,"%s;%d;",stemp->f_name,stemp->w_count);// write file name and word count to file
                stemp=stemp->next;
            }
            fprintf(fp,"#\n");// write separator for each main node
            mtemp=mtemp->next;
        }
    }
    fclose(fp);
    return SUCCESS;   
}