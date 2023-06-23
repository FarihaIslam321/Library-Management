#include <stdio.h>
#include"splash.h"
#include"login.h"
#include"menu.h"

int main(void)
{
    recursive_loading(0);
    splash();
    system("cls");
    login();
    system("cls");
    displayMenu();
    void getChoice(int choice);
    return 0;
}
