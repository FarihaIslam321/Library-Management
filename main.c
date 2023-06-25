#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"splash.h"
#include"login.h"
#include"menu.h"

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_STUDENT_LENGTH 100
#define MAX_DATE_LENGTH 20

struct Book {
    int bookId;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char studentName[MAX_STUDENT_LENGTH];
    char dateOfIssue[MAX_DATE_LENGTH];
};

int main()
{
    recursive_loading(0);
    splash();
    system("cls");
    login();
    system("D:\\LIBRARY.jpg");
    system("cls");
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                printf("\n\nAdding a book ...\n\n");
                sleep(1);
                printf("ADDED BOOK SUCCESSFULLY!!!\n");
                sleep(2);
                system("cls");
                break;
            case 2:
                displayFile("library.txt");
                printf("\n\nDisplaying all books ...\n\n");
                sleep(4);
                system("cls");
                break;
            case 3: {
                char searchTitle[MAX_TITLE_LENGTH];
                printf("\n\nEnter the title of the book to search: ");
                getchar(); // Consume the newline character left in the input buffer
                fgets(searchTitle, sizeof(searchTitle), stdin);
                searchTitle[strcspn(searchTitle, "\n")] = '\0'; // Remove the trailing newline
                searchBook(searchTitle);
                printf("\n\nSearching book ...\n\n");
                sleep(1);
                printf("SEARCHED BOOK SUCCESSFULLY!!!\n");
                sleep(3);
                system("cls");
                break;
            }
            case 4:
                {
                int bookId;
                printf("\n\nEnter the ID of the book to delete: ");
                scanf("%d", &bookId);
                deleteBook(bookId);
                printf("\n\nDeleting a book ...\n\n");
                sleep(1);
                printf("DELETED BOOK SUCCESSFULLY\n");
                sleep(2);
                system("cls");
                break;
            }
            case 5:
                printf("\n\nExiting the program ...\n\n");
                sleep(1);
                printf("                 ...THANK YOU FOR USING OUR MANAGEMENT SYSTEM...\n");
                sleep(3);
                system("cls");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}


void addBook() {
    struct Book book;

    printf("\t\tENTER YOUR DETAILS BELOW: \n");
    printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("Book ID: ");
    scanf("%d", &book.bookId);
    printf("Book Title: ");
    getchar(); // Consume the newline character left in the input buffer
    fgets(book.title, sizeof(book.title), stdin);
    book.title[strcspn(book.title, "\n")] = '\0'; // Remove the trailing newline
    printf("Book Author: ");
    fgets(book.author, sizeof(book.author), stdin);
    book.author[strcspn(book.author, "\n")] = '\0'; // Remove the trailing newline
    printf("Student Name: ");
    fgets(book.studentName, sizeof(book.studentName), stdin);
    book.studentName[strcspn(book.studentName, "\n")] = '\0'; // Remove the trailing newline
    printf("Date of Issue: ");
    fgets(book.dateOfIssue, sizeof(book.dateOfIssue), stdin);
    book.dateOfIssue[strcspn(book.dateOfIssue, "\n")] = '\0'; // Remove the trailing newline

    FILE* file = fopen("library.txt", "a");
    if (file == NULL) {
        printf("\n\nError opening the file.\n");
        return;
    }

    fwrite(&book, sizeof(struct Book), 1, file);

    fclose(file);
}

void displayFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("\n\nError opening the file.\n");
        return;
    }

    struct Book book;

    printf("%-10s %-40s %-20s %-15s %-15s\n", "Book ID", "Title", "Author", "Student Name", "Date of Issue");

    while (fread(&book, sizeof(struct Book), 1, file) == 1) {
        printf("%-10d %-40s %-20s %-15s %-15s\n", book.bookId, book.title, book.author, book.studentName, book.dateOfIssue);
    }

    fclose(file);
}

void searchBook(const char* searchTitle) {
    FILE* file = fopen("library.txt", "r");
    if (file == NULL) {
        printf("\n\nError opening the file.\n");
        return;
    }

    struct Book book;
    int found = 0;

    printf("Search Results:\n\n\n");
    printf("%-10s %-40s %-20s %-15s %-15s\n", "Book ID", "Title", "Author", "Student Name", "Date of Issue");

    while (fread(&book, sizeof(struct Book), 1, file) == 1) {
        if (strcmp(book.title, searchTitle) == 0) {
            printf("%-10d %-40s %-20s %-15s %-15s\n", book.bookId, book.title, book.author, book.studentName, book.dateOfIssue);
            found = 1;
        }
    }
       if (!found) {
        printf("\n\nNo books found with the given title.\n");
    }

    fclose(file);
}

void deleteBook(int bookId) {
    FILE* file = fopen("library.txt", "r");
    if (file == NULL) {
        printf("\n\nError opening the file.\n");
        return;
    }

    FILE* tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("\n\nError creating temporary file.\n");
        fclose(file);
        return;
    }
    struct Book book;

    while (fread(&book, sizeof(struct Book), 1, file) == 1) {
        if (book.bookId != bookId) {
            fwrite(&book, sizeof(struct Book), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (remove("library.txt") != 0) {
        printf("\n\nError deleting the file.\n");
        return;
    }

    if (rename("temp.txt", "library.txt") != 0) {
        printf("\n\nError renaming the file.\n");
        return;
    }
}
