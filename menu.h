#include<stdio.h>

void displayMenu(void)
{
    printf("\n\n\t\t\t\t\t\t\t~~~~Library Management System~~~~\n");
    printf("1. Add Book\n");
    printf("2. Book List\n");
    printf("3. Search Book\n");
    printf("4. Remove Book\n");
    printf("5. Exit\n\n\n");
    printf("Enter Your Choice: ");
}

void getChoice(int choice)
{
    switch(choice)
    {
    case 1:
        printf("Adding a book ...\n");
        break;
    case 2:
        printf("Displaying all book ...\n");
        break;
    case 3:
        printf("Searching a book ...\n");
        break;
    case 4:
        printf("Removing a book ...\n");
        break;
    case 5:
        printf("Exiting program ...\n");
        break;
    default:
        printf("Invalid choice. Please try again,\n");
        break;
    }
}
