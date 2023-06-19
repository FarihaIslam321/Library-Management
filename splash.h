#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<dos.h>

void recursive_loading(int progress)
{
    //Loading bar
    if(progress > 100)
    {
        return;
    }

    //Code to be executed
    printf("Project Loading in [%d%%], progress");
    fflush(stdout);
    usleep(10000);
    printf("\r");

    //Recursion call to the function
    recursive_loading(progress + 1);
}



void splash (void)
{
    system("cls");
    printf("........................Project Loading Complete!........................\n\n\n");
    sleep(1);
    getchar();


char wel[] = "\n"
"                       /$$      /$$           /$$                                               \n"
"                      | $$  /$ | $$          | $$                                               \n"
"                      | $$ /$$$| $$  /$$$$$$ | $$  /$$$$$$$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$    \n"
"                      | $$/$$ $$ $$ /$$__  $$| $$ /$$_____/ /$$__  $$| $$_  $$_  $$ /$$__  $$   \n"
"                      | $$$$_  $$$$| $$$$$$$$| $$| $$      | $$  \\ $$| $$ \\ $$ \\ $$| $$$$$$$$   \n"
"                      | $$$/ \\  $$$| $$_____/| $$| $$      | $$  | $$| $$ | $$ | $$| $$_____/   \n"
"                      | $$/   \\  $$|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$ | $$ | $$|  $$$$$$$   \n"
"                      |__/     \\__/ \\_______/|__/ \\_______/ \\______/ |__/ |__/ |__/ \\_______/   \n";



//Showing Ascii text
    for(int i=0;i<strlen(wel);i++)
    {
        printf("%c",wel[i]);
        if(wel[i]=='\n')
        {
            usleep(353535);
        }
    }
    printf("\n\n");
    sleep(1);
    printf("--------------------Press any key to continue--------------------\n");
    getchar();

    FILE*sp;
    sp=fopen("image.txt","r");
    char img[1000];

    //reading image from text file

    while(!feof(sp))
    {
        fgets(img,sizeof(sp),sp);
        printf("%s",img);
    }
printf("\n\n");
    fclose(sp);

char lib[]="\n"
"                     __ _ _  \n"
"                    / /(_) |__  _ __ __ _ _ __ _   _  \n"
"                   / / | | '_ \\| '__/ _` | '__| | | | \n"
"                  / /__| | |_) | | | (_| | |  | |_| | \n"
"                  \\____/_|_.__/|_|  \\__,_|_|   \\__, | \n"
"                                               |___/ \n"
"                                                             _ \n"
"          /\\/\\   __ _ _ __   __ _  __ _ _ __ ___   ___ _ __ | |_  \n"
"         /    \\ / _` | '_ \\ / _` |/ _` | '_ ` _ \\ / _ \\ '_ \\| __| \n"
"        / /\\/\\ \\ (_| | | | | (_| | (_| | | | | | |  __/ | | | |_  \n"
"        \\/    \\/\\__,_|_| |_|\\__,_|\\__, |_| |_| |_|\\___|_| |_|\\__| \n"
"                                  |___/                           \n";

     for(int i=0;i<strlen(lib);i++)
     {
         printf("%c",lib[i]);
         if(lib[i]=='\n')
         {
             usleep(353535);
         }
     }
     printf("\n\n\n");
     sleep(1);
     printf("...................Press any key to continue...................\n");
     getchar();






}
