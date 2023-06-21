#include<stdio.h>

void login(void)
{
    char username[50],password[25],userfile[50],passfile[25];

    FILE *log;
    log = fopen("login.txt","r");

    //saving the username and password from file
    fscanf(log,"%s%s",userfile,passfile);

    while(1)
    {
        printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t\t\t\t~~~~                                ~~~~\n");
        printf("\t\t\t\t\t\t\t\t~~~~          LOGIN PANEL           ~~~~\n");
        printf("\t\t\t\t\t\t\t\t~~~~                                ~~~~\n");
        printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");

           printf("ENTER USER NAME: \n");
           fflush(stdin);
           fgets(username,sizeof(username),stdin);
           username[strlen(username)-1]='\0';

           printf("ENTER PASSWORD: \n");
           fflush(stdin);
           fgets(password,sizeof(password),stdin);
           password[strlen(password)-1]='\0';

           //Match password and username
           if((strcmp(userfile,username)==0) && (strcmp(passfile,password)==0))
           {
               system("cls");
               printf("\t\t\t\t\t\t.......................LOGIN SUCCESSFUL!!!...........................\n\n\n\n");
               printf("\t\t\t\t\t\t--------------------Press any key to continue--------------------\n");
               getchar();
               break;
           }
           else
           {
               system("cls");
               printf("\t\t\t\t\t\t\t!!!!!!!!!!!!!!!!!!!LOGIN UNSUCCESSFUL!!!!!!!!!!!!!!!!!\n\n");
               printf("\t\t\t\t\t\t\t_____________________Try Again______________________\n\n\n");
               sleep(2);
               system("cls");
           }

    }
    fclose(log);
}
