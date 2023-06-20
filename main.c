#include <stdio.h>
#include"splash.h"
#include"login.h"

int main(void)
{
    recursive_loading(0);
    splash();
    system("cls");
    login();
    return 0;
}
