#include "Libraryheader.h"

// typedef struct {
//     int day;
//     int month;
//     int year;
// } Date;

// typedef struct {
//     int    id;
//     char   title[100];
//     char   author[50];
//     Date   borrowed_on;
//     Date   due_date;
// } Book;

// typedef struct {
//     Book stack[STACK_SIZE];
//     int top;
// } BookStack;
void init(BookStack *s)
{
    s->top = -1;
}
Book createBook(int id, char *t, char *a, Date brw, Date dd)
{
    Book b;
    b.id = id;
    strcpy(b.title, t);
    strcpy(b.author, a);
    b.borrowed_on = brw;
    b.due_date = dd;

    return b;
}
bool isFull(BookStack s)
{
    return s.top == STACK_SIZE;
}

bool isEmpty(BookStack s)
{
    return s.top == -1;
}

bool push(BookStack *s, Book n)
{
    if (isFull(*s))
    {
        printf("FULL!");
        return false;
    }

    s->stack[++s->top] = n;
    return true;
}

bool pop(BookStack *s)
{
    if (isEmpty(*s))
    {
        printf("Empty!");
        return false;
    }
    s->top--;
}

Book peek(BookStack s)
{
    if (isEmpty(s))
    {
        printf("No data to peek");
    }
    else
    {
        return s.stack[s.top];
    }
}

bool print(BookStack s)
{

    for (; s.top != -1;)
    {
        Book temp = peek(s);
        printf("||  %d  ||\n", temp.id);
        pop(&s);
    }
}

int removeOverdue(BookStack *s, Date today)
{
    if (isEmpty(*s))
    {
        return 1;
    }

    BookStack temp;
    int tempcnt = 0;
    int cnt = 0;

    for (; s->top != -1;){
    Book current = peek(*s);

    if (current.due_date.month <= today.month && current.due_date.year <= today.year && current.due_date.day <= today.day){
        cnt++;
        pop(s);
    }else if(current.due_date.day >= today.day && current.due_date.month < today.month){
        cnt++;
        pop(s);
        
    }else{
        temp.stack[tempcnt++] = current;
        pop(s);
    }

        
    }

    for (int i = 0; i < tempcnt; i++)
    {

        push(s, temp.stack[i]);
    }
    return cnt;
}
int duplicateBooksByAuthor(BookStack *s,char *author){

    BookStack temp = *s;
    int tempcnt =0;
    int cnt =0;
    Book dupe;
    
    for(;temp.top != -1;){
        Book current = peek(temp);
        if(strcmp(current.author,author)==0){
             dupe = current;
             push(s,dupe);
             cnt++;
        }
       
        pop(&temp);
    }



return cnt;

}
int moveBooksBorrowedBefore(BookStack *src, BookStack *dest, int year);
void sortByDueDate(BookStack *s);