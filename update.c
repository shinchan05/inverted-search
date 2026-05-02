#include"invert.h"
#include<stdio.h>
int update(main_node *name[])
{
    printf("Enter the file name to update ending with.txt ");// read file name to update database
    char c[100];
    scanf("%s",c);
    char s[5]={".txt"};// check for valid file nam
       char *ptr;
        (ptr=strstr(c,s));
        
            if((ptr==NULL)||((strcmp(ptr,s)!=0)|| strlen(ptr) != strlen(s)))// check for valid file extension
            {
                printf("%s extension should be filename<.txt>\n",c);
                return FAILURE;
            }


    FILE *fp=fopen(c,"r");
            printf("Updating database from file %s...\n",c);// print message for updating database
    if(fp==NULL)    
    {
        printf("Error opening file %s\n",c);// check for file opening error
        return FAILURE;
    }
   if (fgetc(fp) == EOF)
{
    printf("File is empty\n");
    return FAILURE;
}
fseek(fp, 0, SEEK_SET);
    char line[256];
   
    while(fgets(line, sizeof(line), fp) != NULL)// read each line from file
    {
        char *token=strtok(line,"#;");
        if(token==NULL)
            continue;

            int index=atoi(token);// get index from file
        
            token=strtok(NULL,";");
            if(token==NULL)
                continue;
              main_node *mnew = malloc(sizeof(main_node));// create new main node
              if(mnew == NULL) return FAILURE;
        mnew->word = malloc(strlen(token)+1);// allocate memory for word in main node
        strcpy(mnew->word, token);
            token=strtok(NULL,";");
            if(token == NULL)
                {
                    free(mnew);
                    continue;
                }
            mnew->f_count = atoi(token);// get file count from file
        mnew->next = NULL;
        mnew->link = NULL;
        sub_node *stemp = NULL;// create sub node for each file linked to main node
        while((token=strtok(NULL,";"))!=NULL)
        {
            if(token == NULL)
            {
                free(mnew);
                break;
            }
            sub_node *snew = malloc(sizeof(sub_node));// allocate memory for sub node
            snew->f_name = malloc(strlen(token)+1);// allocate memory for file name in sub node
            strcpy(snew->f_name, token);
            token=strtok(NULL,";");
            if(token == NULL)
                {
                    free(snew);
                    break;
                }
            snew->w_count=atoi(token);// get word count from file
            snew->next=NULL;
            if(stemp==NULL)
            {
                mnew->link=snew;
                stemp=snew;
            }
            else
            {
                stemp->next=snew;
                stemp=snew;
            }
        }
        if(index < 0 || index >= 28)   // change 28 to your hash size
            {
                free(mnew);
                continue;
            }
        if(name[index] == NULL)
        {
            name[index] = mnew;
        }
        else
        {
            main_node *temp = name[index];
            while(temp->next)
                temp = temp->next;

            temp->next = mnew;
        }    
    }
    fclose(fp);
    //`printf("Database updated successfully\n");
    return SUCCESS;
               

}