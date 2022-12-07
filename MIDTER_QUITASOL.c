#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mainMenu();
void inBook();
void searchBook();
void deleteBook();
void editBook();
void appExit();
//Number of Student
int i = 0;
//Date of Birth
typedef struct
{
    char firstName[20];
    char lastName[20];
}fullName;

typedef struct
{
    int dd;
    int mm;
    int yy;
}date;
//Student Information
struct bookInfo
{
    fullName bookAuthor;
    char bookPublisher[20];
    char bookTitle[20];
    int bookId;
    date datePub;
}book[20];
//Main Menu
void mainMenu()
{
    system("cls");
    int choice;
    printf(" Number of books stored: %d", i );//Check kung may laman
    printf("\n =============================");
    printf("\n Book Management System");
    printf("\n =============================");
    printf("\n [1] Insert Book");
    printf("\n [2] Search Book");
    printf("\n [3] Delete Book");
    printf("\n [4] Edit Book Information");
    printf("\n [5] Exit");
    printf("\n =============================");
    printf("\n Choice: ");
    scanf(" %d",&choice);
    switch(choice)
    {
    case 1://insert a book
        system("cls");
        inBook();
        break;
    case 2://search a book
        system("cls");
        searchBook();
        mainMenu();
        break;
    case 3://delete a book
        system("cls");
        deleteBook();
        mainMenu();
        break;
    case 4://edit a book
        system("cls");
        editBook();
        break;
    case 5://Exit the app
        appExit();
        break;
    default://If invalid input
        printf("\n Invalid input!");
        mainMenu();
        break;
    }
}
//Function: add a book
void inBook()
{
    ++i;//add number of student
    printf("\n =============================");
    printf("\n Insert a Book");
    printf("\n =============================\n");
    printf(" Book ID: ");
    scanf("%d",&book[i].bookId);
    printf(" Book Title: ");
    scanf("%s",&book[i].bookTitle);
    printf(" Book Author First Name: ");
    scanf("%s",&book[i].bookAuthor.firstName);
    printf(" Book Author Last Name: ");
    scanf(" %s",&book[i].bookAuthor.lastName);
    printf(" Date of Publication(dd): ");
    scanf(" %d",&book[i].datePub.dd);
    printf(" Date of Publication(mm): ");
    scanf(" %d",&book[i].datePub.mm);
    printf(" Date of Publication(yy): ");
    scanf(" %d",&book[i].datePub.yy);
    printf(" Publisher: ");
    scanf("%s", &book[i].bookPublisher);

    printf("\n =============================");
    printf("\n Book position #: %d",i);
    printf("\n Press Any Key to Continue on Main Menu...");
    getch();//continue to main menu
    mainMenu();
}
//Function: search a book
void searchBook()
{
    int num;
    printf("\n =============================");
    printf("\n Search a Book");
    printf("\n =============================\n");
    printf(" Enter the Book ID: "); //Find via book id
    scanf(" %d", &num);
    for (int j = 1; j <= i; j++)
    {
        if (num == book[j].bookId)
        {
            printf("\n =============================\n");
            printf(" The Book Details");
            printf("\n =============================\n");
            printf(" Title: %s",book[j].bookTitle);
            printf("\n Book ID: %d",book[j].bookId);
            printf("\n Author: %s %s",book[j].bookAuthor.firstName,book[j].bookAuthor.lastName);
            printf("\n Publisher: %s",book[j].bookPublisher);
            printf("\n Date of Publication (dd/mm/yy): %d / %d / %d",book[j].datePub.dd,book[j].datePub.mm,book[j].datePub.yy);

            printf("\n =============================");
            printf("\n Press Any Key to Continue...");
            getch();
            mainMenu();
        }
        else // if no student found
        {
            char in;
            printf("\n =============================\n");
            printf("\n No Book Found");
            printf("\n =============================\n");
            printf("\n Enter Any Key to Try Again or Press (Y) go back to Main Menu: ");
            scanf("%s",&in);
            if(in == 'Y' || in == 'y')
            {
                system("cls");
                mainMenu();
            }
            else
            {
                system("cls");
                searchBook();
            }
        }
    }

}
void deleteBook()//delete a book
{
    int j, num,pos;
    printf("\n =============================");
    printf("\n Delete a Book");
    printf("\n =============================");
    printf("\n Enter the Book Position (Book #):");
    scanf("%d", &pos);
         if(pos < 0 || pos > i)
            {
                printf("\n =============================");
                printf("\n Invalid position! Please enter position between 1 to %d", i);
            }
        else
            {
                for(j=pos-1; j<i-1; j++)
                    {
                        book[j] = book[j + 1];
                    }
                    i--;
            }
    printf(" DELETED SUCCESSFULLY.");
    printf("\n =============================");
    printf("\n Press Any Key to Continue...");
    getch();
    mainMenu();
}
//Function: edit a book
void editBook()
{
    printf("\n =============================");
    printf("\n Search a Book");
    printf("\n =============================");
    printf("\n Enter the Book ID: ");
    int num;
    scanf(" %d", &num);
    for (int j = 1; j <= i; j++)//Find book Number
        {
        if (num == book[j].bookId)
        {
                printf("\n =============================");
                printf("\n Edit Your New Data\n");
                printf("\n =============================");
                printf(" Book ID: ");
                    scanf("%d",&book[i].bookId);
                printf(" Book Title: ");
                    scanf("%s",&book[i].bookTitle);
                printf(" Book Author First Name: ");
                    scanf("%s",&book[i].bookAuthor.firstName);
                printf(" Book Author Last Name: ");
                    scanf("%s",&book[i].bookAuthor.lastName);
                printf(" Date of Publication(dd): ");
                    scanf(" %d",&book[i].datePub.dd);
                printf(" Date of Publication(mm): ");
                    scanf(" %d",&book[i].datePub.mm);
                printf(" Date of Publication(yy): ");
                    scanf(" %d",&book[i].datePub.yy);
                printf(" Publisher: ");
                    scanf("%s", &book[i].bookPublisher);

                printf(" UPDATED SUCCESSFULLY.");
                printf("\n =============================");
                printf("\n Press Any Key to Continue...");
                getch();
                mainMenu();
            }
            else// if no book found
            {
                char in;
                printf("\n =============================");
                printf("\n No Book Found");
                printf("\n =============================\n");
                printf("\n Enter Any Key to Try Again "
                       "or Press (Y) Go back to Main Menu: ");
                scanf("%s",&in);
                if(in == 'Y' || in == 'y')
                {
                    system("cls");//clear screen and go to main menu
                    mainMenu();
                }
                else // go back
                    {
                    system("cls");
                    editBook();
                    }
            }
        }
}
// Exit the App
void appExit()
{
    printf("\n Thank You for Using the App.\n");
}
//MAIN
int main()
{
    mainMenu();
    return 0;
}
