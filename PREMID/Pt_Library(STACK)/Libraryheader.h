#ifndef LIBRARYHEADER_H
#define LIBRARYHEADER_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define STACK_SIZE 20

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int    id;
    char   title[100];
    char   author[50];
    Date   borrowed_on;
    Date   due_date;
} Book;

typedef struct {
    Book stack[STACK_SIZE];
    int top;
} BookStack;


bool isEmpty(BookStack s);
bool isFull(BookStack s);
void init(BookStack *s);
bool push(BookStack *s, Book n);
bool pop(BookStack *s);
bool print(BookStack s);


Book createBook(int id,char *t,char *a,Date b, Date dd );
int removeOverdue(BookStack *s, Date today);
int duplicateBooksByAuthor(BookStack *s,char *author);
int moveBooksBorrowedBefore(BookStack *src, BookStack *dest, int year);
void sortByDueDate(BookStack *s);




#endif