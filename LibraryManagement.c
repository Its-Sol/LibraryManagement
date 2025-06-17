/*Make a struct with user's names and borrowed books
Make a struct with book author, title, release year and status
Make a function add books
another to remove books
and a last one to assign borrowed books to a user
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct{
char name[50], borrowed[3][50];
}ArrayUsers;

typedef struct{
char author[50], title[50], status[10];;
int year;
}Library;

void add_book(Library Books[],  int size){
    char title[50], author[50], status[10];
    int year, found = 0;

    printf("What's the title of the book you wanna add?\n");
    fgets(title, 50, stdin);
    title[strlen(title) - 1] = '\0';
    snprintf(title, 50, "%s" ,strlwr(title));
    

    for(int i = 0; i < size; i++){
        if(strncmp(title, Books[i].title, 50) == 0){
            printf("Book is alredy in list.\n");
            found = 1;
        }
    }
    if (!found){
    printf("What's the author's name?\n");
    fgets(author, 50, stdin);
    author[strlen(author) - 1] = '\0';
    snprintf(author, 50, "%s", strlwr(author));
    
    printf("What's the year of release?\n");
    scanf("%5d", &year);
    getchar();

    snprintf(Books[size - 1].title, 50, "%s", title);
    snprintf(Books[size - 1].author, 50, "%s", author);
    Books[size - 1].year = year;
    snprintf(Books[size - 1].status, 10, "Available");
    printf("Book added to library.");}
    Sleep(3000);
}

void remove_book(Library Books[], int size){
    char title[50];
    int found = 0;
    
    printf("What's the name of the book you wanna remove?\n");
    fgets(title, 50, stdin);
    title[strlen(title) - 1] = '\0';
    snprintf(title, 50, "%s", strlwr(title));
    
    for (int i = 0; i < size; i++){
        if(strncmp(Books[i].title, title, 50) == 0){
            int index = i; found = 1;
        for(int j = index; j < size - 1; j++){
        Books[i] = Books[i + 1];}
        printf("Book removed\n");}
    }
    if(!found){
            printf("Book wasn't found.\n");}
            Sleep(3000);
    }    

void add_user(ArrayUsers Users[], int size){
    char name[50], borrowed[3][50];
    int found = 0;
    printf("What's the name of the user?\n");
    fgets(name, 50, stdin);
    name[strlen(name) - 1] = '\0';
    snprintf(name, 50, "%s", strlwr(name));

    for(int i = 0; i < size; i++){
        if(strncmp(Users[i].name, name, 50) == 0){
            printf("User is already in list.\n");
            found = 1;
        }
        if(!found){
            snprintf(Users[size - 1].name, 50, "%s", name);
            snprintf(Users[size - 1].borrowed[0], 50, "");
            snprintf(Users[size - 1].borrowed[1], 50, "");
            snprintf(Users[size - 1].borrowed[2], 50, "");
            }
    }
    printf("User added to data base.");
    Sleep(3000);
} 

void remove_user(ArrayUsers Users[], int size){
    char name[50];
    int found = 0;
    printf("What user do you wanna remove?");
    fgets(name, 50, stdin);
    name[strlen(name)- 1] = '\0';
    snprintf(name, 50, "%s", name);
    
    for(int i = 0; i < size; i++){
        if(strncmp(Users[i].name, name, 50) == 0){
            found = 1;
            for(int j = i; j < size; j++){
            Users[i] = Users[i + 1];}
}
}
printf("User removed.");
Sleep(3000);
}

void choose_user(ArrayUsers Users[], ArrayUsers CurrentUser, int size){
    char name[50];
    printf("What's your username?\n");
    fgets(name, 50, stdin);
    name[strlen(name) - 1] = '\0';
    snprintf(name, 50, "%s", strlwr(name));

    for(int i = 0; i < size; i++){
        if(strncmp(Users[i].name, name, 50) == 0){
            snprintf(CurrentUser.name, 50, "%s", Users[i].name);
            snprintf(CurrentUser.borrowed[0], 50, "%s", Users[i].borrowed[0]);
            snprintf(CurrentUser.borrowed[1], 50, "%s", Users[i].borrowed[1]);
            snprintf(CurrentUser.borrowed[2], 50, "%s", Users[i].borrowed[2]);
            printf("You've logged in as %s." 
            " Here's your borrowed books:\n%s\n%s\n%s\n", CurrentUser.name,
            CurrentUser.borrowed[0], CurrentUser.borrowed[1], CurrentUser.borrowed[2]);
        }else{("You're not a user. Please make an account before borrowing.\n");}}
        Sleep(3000);
}

void borrow_book(Library Books[], ArrayUsers Users[], int size, ArrayUsers CurrentUser){
char title[50];
	
    printf("What book do you wanna borrow?\n");
    fgets(title, 50, stdin);
    title[strlen(title) - 1] = '\0';

    for(int i = 0; i < size; i++){
    if(strncmp(Books[i].status, "Available", 10) == 0 && strncmp(Books[i].title, title, 50) == 0)
    for(int j = 0; j < 3; j++){
    if(strncmp(CurrentUser.borrowed[j], "", 50) == 0)
    snprintf(CurrentUser.borrowed[j], 50, "%s", Books[i].title);}}
    for(int i = 0; i < size; i++){
        if(strncmp(CurrentUser.name, Users[i].name, 50) == 0){
            for(int j = 0; j < 3; j++){
                if(strncmp(CurrentUser.borrowed[j], Users[i].borrowed[j], 50) != 0){
                    snprintf(Users[i].borrowed[j], 50, "%s", CurrentUser.borrowed[j]);}
}
    }
}

    printf("Books borrowed");
    Sleep(3000);
}


void return_book(Library Books[], ArrayUsers Users[], int size, ArrayUsers CurrentUser){
    int found = 0;
    char title[50];

    printf("What book do you wanna return?\n");
    fgets(title, 50, stdin);
    title[strlen(title) - 1] = '\0';

    for(int i = 0; i = size; i++){
    if(strncmp(Books[i].title, title, 50) == 0){
        for(int j = 0; j < 3; j++){
        if(strncmp(CurrentUser.borrowed[j], title, 50) == 0){
        snprintf(CurrentUser.borrowed[j], 50, "");
        snprintf(Books[i].status, 10, "Available");
        printf("Book returned to library");}
        else{printf("User didn't borrow this book.\n");}}}
    }
    Sleep(3000);
}

void print_books(Library Books[], int size){
    if (size == 0){
        printf("Library is empty.\n");}
    for(int i = 0; i < size; i++){
        printf("\nAuthor: %s Title: %s\n" 
        "Status: %s Year: %d",
        Books[i].author, Books[i].title, Books[i].status, Books[i].year);}
    Sleep(3000);
}

void print_users(ArrayUsers Users[], int size){
    if (size == 0){
        printf("User list is empty.\n");}
    for(int i = 0; i < size; i++){
        printf("Username: %s Borrowed books: %s\n",
        Users[i].name, Users[i].borrowed);}
    Sleep(3000);
}

int main(){
    Library *Books = NULL;
    ArrayUsers *Users = NULL;
    int num_books = 0;
    int num_users = 0;
    int choice;
    ArrayUsers CurrentUser = {"", ""};

    printf("Welcome to the library, please stay quiet,"
    " people are reading.\n");

    do{;printf("\n\nMenu: Choose an option.\n"
    "1. Add book.\n2. Remove book.\n3. Add user.\n4. Remove user.\n" 
    "5. Choose user\n6. Borrow book.\n7. Return book.\n" 
    "8. See all users\n9. See all books.\n10. quit.\n");
    scanf("%2d", &choice);
    getchar();

        if(choice == 1){
            num_books++;
            Books = realloc(Books, num_books * sizeof(Library));

        if (Books == NULL){
            printf("Memory allocation failed.\n");}

            add_book(Books, num_books);}

   else if(choice == 2){
        num_books--;
        Books = realloc(Books, num_books * sizeof(Library));

    if (Books == NULL){
            printf("Memory allocation failed.\n");}

            remove_book(Books, num_books);}

    else if(choice == 3){
        num_users++;
        Users = realloc(Users, num_users * sizeof(ArrayUsers));

        if (Users == NULL){
            printf("Memory allocation failed.\n");}

        add_user(Users, num_users);}

    else if(choice == 4){
        num_users--;
        Users = realloc(Users, num_users * sizeof(ArrayUsers));
        
        if(Users == NULL){
            printf("Memory allocation failed.\n");}

        remove_user(Users, num_users);}

    else if(choice == 5){
        choose_user(Users, CurrentUser, num_users);}
    
    else if(choice == 6){
        borrow_book(Books, Users, num_books, CurrentUser);}
    
    else if(choice == 7){
        return_book(Books, Users, num_books, CurrentUser);}

    else if(choice == 8){
        print_users(Users, num_users);}

    else if(choice == 9){
        print_books(Books, num_books);}

    else if(choice != 10){
        printf("Invalid choice.\n");}

}while (choice != 10);
free(Users);
free(Books);
printf("Goodbye.");

    return 0;
}
