// Name Y.manjunath reddy
// roll no:25026A-009
// project:Inverted index



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"invert.h"


main_node *name[28]={NULL};

int main(int argc,char *argv[])
{
    int flag=1,count=0;
     //if arguments are less than 2 then print error message and exit

    if(argc<2)
    {
        printf("Insufficient arguments\n");
        return FAILURE;
    }

    //check for duplicate files
    for(int i=1;i<argc;i++)
    {
        for(int j=i+1;j<argc;j++)
        {
        if(strcmp(argv[i],argv[j])==0)
        {
            printf("%s duplicate found",argv[i]);
            return FAILURE;
        }
        }
    }
    //check for valid files and store in valid_files array
        char *valid_files[200];
        int valid_count=0;
    for(int i=1;i<argc;i++)
    {
       
       char s[5]={".txt"};
       char *ptr;
        (ptr=strstr(argv[i],s));
        
            if((ptr==NULL)||((strcmp(ptr,s)!=0)|| strlen(ptr) != strlen(s)))
            {
                printf("%s extension should be filename<.txt>\n",argv[i]);
                //return FAILURE;
                continue;
            }    
                FILE *fp =fopen(argv[i],"r");
                if(fp==NULL)
                {
                  printf("%s file not found\n",argv[i]); 
                  //return FAILURE;
                    continue;
                }
                fclose(fp);
                    valid_files[valid_count++]=argv[i];
                    
                    //return SUCCESS;
        
    
    }
    //create linked list of valid files
    file_node *head=NULL,*new,*temp;
    
    for(int i=0;i<valid_count;i++)
    {
    new=(file_node*)malloc(sizeof(file_node));
       new->f_name = malloc(50); 
      strcpy(new->f_name,valid_files[i]);
      new->link=NULL;
      if(head==NULL)
      {
        head=temp=new;
      }
      else
      {
          temp->link=new;
          temp=new;
      }
    }
    temp = head;
    while(temp)
    {
        //printf("%s -> ", temp->name);
        temp = temp->link;
    }
    //printf("NULL\n");
    if(valid_count==0)
    {
        printf("No valid files to process\n");
        return FAILURE;
    }

    while(1)
    {
        printf("select your choice\n");
        printf("1.Create Data base\n2.Display data base\n3.Search database\n4.Save database\n5.update database\n6.Exit\n");
        printf("Enter your choice: ");
        int choice; 
        scanf("%d",&choice);// read user choice
        switch(choice)
        {
            case 1:
            if(count==1)
            {
                printf("Already it is an updated file cant create again\n");
                return FAILURE;
            } 
            else { 
                if(create_db(name,valid_files,valid_count)==FAILURE)// create database
                {
                    printf("Error creating database\n");
                }

                else
                {
                    printf("Database created successfully\n");
                }
            }   
               
                break;
            case 2:
                if(display(name)==FAILURE)
                {
                    printf("Error displaying database\n");// display database
                }
                else
                {
                    printf("Database displayed successfully\n");
                }
                break;
            case 3:
            char word[50];// read word to search

                printf("Enter word to search:\n");
                scanf("%s",word);
                if(search_word(name,word)==FAILURE)
                {
                    printf("Word %s not found in database\n",word);// search database
                }
                else 
                {
                    printf("Word %s found in database\n",word);
                }
                break;
             case 4:
                 if(save(name)==FAILURE)  // save database               
                 {
                     printf("Error saving database\n");
                 }
                 else
                 {
                     printf("Database saved successfully\n");
                 }
                 break;
            case 5:
            if(flag==1)
            {
                if(update(name)==FAILURE)// update database
                {
                    printf("Error updating database\n");
                }
                else
                {
                    printf("Database updated successfully\n");
                    flag=0;
                    count=1;
                }
            }
                break;
            case 6:
            printf("Exiting........\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("do you want to continue? (y/n): ");
        char cont;// read user choice to continue or exit
        scanf(" %c",&cont);
        if(cont=='n' || cont=='N')
        {
            printf("Exiting...\n");
            break;
        }
        else if(cont!='y' && cont!='Y')
        {
            printf("Invalid input, exiting...\n");
            break;
        }
    }




}