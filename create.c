#include"invert.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int create_db( main_node *name[], char *files[],int count)
{
    for (int i = 0; i < count; i++)   // loop through files
    {
        FILE *fp=fopen(files[i],"r");
        if(fp==NULL)
        {
            printf("File not found: %s\n", files[i]);
            //return FAILURE;
            continue;
        }
        else
        {
            char ch[256];
            while(fscanf(fp,"%s",ch)!=EOF)
            {
                //create main node and sub node
                int index;
                if(ch[0]>='a' && ch[0]<='z')
                    index=ch[0]-'a';
                else if(ch[0]>='A' && ch[0]<='Z')
                    index=ch[0]-'A';
                else if(ch[0]>='0' && ch[0]<='9')
                    index=26;
                else
                    index=27;

                //main node creation
                main_node *mtemp=name[index];
                main_node *mprev=NULL;
                //search for the word in main node
                while(mtemp!=NULL)
                {
                    if((strcmp(mtemp->word,ch)==0))
                    {
                        //word found in main node
                        break;
                    }
                    mprev=mtemp;  
                    mtemp=mtemp->next;
                    
                }
                //word not found in main node
                if(mtemp==NULL)
                {
                    //create new main node
                    main_node *mnew = malloc(sizeof(main_node));
                   mnew->word = malloc(strlen(ch) + 1);
                    strcpy(mnew->word, ch);
                    mnew->f_count = 1; 
                    mnew->next= NULL;
                    mnew->link = NULL;
                    if(mprev==NULL)
                    {
                        name[index]=mnew;
                    }
                    else
                    {
                        mprev->next=mnew;
                    }
                    mtemp=mnew;
                    sub_node *snew = malloc(sizeof(sub_node));// create new sub node for the new main node
                    snew->f_name = malloc(strlen(files[i]) + 1);// allocate memory for file name in sub node
                     strcpy(snew->f_name, files[i]);
                snew->w_count = 1;
                snew->next = NULL;
                mtemp->link = snew;
                }
                //word found in main node
                else 
                {
                    sub_node *stemp = mtemp->link;
                sub_node *sprev = NULL;

                while (stemp != NULL)
                {
                    if (strcmp(stemp->f_name, files[i]) == 0)
                    {
                        stemp->w_count++;
                        break;
                    }

                    sprev = stemp;
                    stemp = stemp->next;
                }

                /* File not found in sub list */
                if (stemp == NULL)
                {
                    sub_node *snew = malloc(sizeof(sub_node));
                        snew->f_name = malloc(strlen(files[i]) + 1);
                        strcpy(snew->f_name, files[i]);
                        snew->w_count = 1;
                        snew->next = NULL;
                        mtemp->f_count++;
                        if (sprev == NULL)
                            mtemp->link = snew;
                        else
                            sprev->next = snew;
                }
                  }
            }
        }
        fclose(fp);
    }  
    return SUCCESS; 
    
}
