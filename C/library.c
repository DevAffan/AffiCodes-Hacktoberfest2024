#include<stdio.h>
#include <string.h>

char titles[100][100];
char authors[100][100];
int available[100];
int count = 0;

void displaybook() {
    if(count == 0) {
        printf("Library is empty.\n");
        return;
    }
    printf("Availablle book(s): ");
    for(int i = 0; i < count; i++) {
        printf("%d- Title: %s\n, Author: %s\n, Available: %s\n", i + 1, titles[i], authors[i], available[i] ? "Yes" : "No");
    }
}

void addbook() {
    if(count >= 100) {
        printf("Library is full.\n");
        return;
    }
    printf("Enter the title: ");
    scanf("%s", &titles[count]);
    printf("Enter the authot name: ");
    scanf("%s", &authors[count]);
    available[count] = 1;
    printf("Book is added.\n");
    count++;
}

void deletebook() {
    if(count == 0) {
        printf("Library is empty can'nt delete anything.\n");
        return;
    }
    int index;
    printf("Enter the number of the book which you want to delete.");
    scanf("%d", &index);
    if(index >= 1 && index <= count) {
        for(int i = index - 1; i <= count - 1; i++) {
            strcpy(titles[i], titles[i + 1]);
            strcpy(authors[i], authors[i + 1]);
            available[i] = available[i + 1];
        }
        count--;
        printf("Book is deleted.\n");
    } 
    else {
        printf("Invalid entry.\n");
    }
}

void borrowbook() {
    if(count == 0) {
        printf("Library is empty can'nt borrow anything.\n");
        return;
    }
    int index;
    printf("Enter the book number which you want to borrow: ");
    scanf("%d", &index);
    if(index >= 1 && index <= count) {
        if(available[index - 1]) {
            available[index - 1];
        }
        else {
            printf("Book is not avaiable.\n");
        }
    }
    else {
        printf("Invalid entry.\n");
    }
}

int main() {
    int choice;
    do {
        printf("Welcome to E-Library\n");
        printf("1. Display all the book.\n");
        printf("2. Add new book.\n");
        printf("3. Delete book.\n");
        printf("4. Borrow book.\n");
        printf("5. Exit\n");
        printf("---------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
            displaybook();
            break;
            case 2:
            addbook();
            break;
            case 3:
            deletebook();
            break;
            case 4:
            borrowbook();
            break;
            case 5:
            printf("Thanks for visiting us!!\n    Visit us again:)");
            break;
            default:
            printf("Invalid input.\n");
        }
    }
    while(choice != 5);
    return 0;
}