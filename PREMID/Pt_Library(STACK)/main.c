#include "Libraryheader.h"



// // typedef struct {
// //     int day;
// //     int month;
// //     int year;
// // } Date;

// // typedef struct {
// //     int    id;
// //     char   title[100];
// //     char   author[50];
// //     Date   borrowed_on;
// //     Date   due_date;
// // } Book;

// // typedef struct {
// //     Book stack[STACK_SIZE];
// //     int top;
// // } BookStack;

// Book createBook(int id,char *t,char *a,Date b, Date dd ){
//     Book b;
//     strcpy(b.title,t);
//     strcpy(b.author,a);
//     b.borrowed_on = b;
//     b.due_date = dd;



//     return b;
// }

int main(){
    Book b1 = createBook(101,"CocoAndFriends","Kernighan",(Date){1,9,2024},(Date){15,9,2025});
    Book b2 = createBook(102,"AmericanPie","CLRS",(Date){2,9,2024},(Date){30,9,2025});
    Book b3 = createBook(103,"PuffPie","Gamma",(Date){10,8,2024},(Date){20,8,2025});
    Book b4 = createBook(104,"Creampie","CLRS",(Date){5,9,2024},(Date){12,9,2025});
    

    BookStack books;
    init(&books);
    
    push(&books,b1);
    push(&books,b2);
    push(&books,b3);
    push(&books,b4);
 
    // int removed = removeOverdue(&books,(Date){14,9,2025});
    // printf("Removed: %d\n",removed);
    // print(books);

    int dupe = duplicateBooksByAuthor(&books,"CLRS");
    printf("\nDuplicated: %d\n",dupe);
    print(books);

    return 0;
}