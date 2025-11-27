#ifndef FLIGHTSHEADER_H
#define FLIGHTSHEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STACK_SIZE 10   


typedef struct {
    int hours;   // 0-23
    int minutes; // 0-59
} Time;

typedef struct {
    int  id;
    char origin[50];
    char destination[50];
    Time departure;
    Time arrival;
} Flight;

typedef struct List{
    Flight data;
    struct List *add;
    int top;   
} Node, *List;


Time createTime(int h, int m); 
Flight createFlight(int id, const char *orig, const char *dest,Time dep, Time arr); 
void displayTime(Time t); 
void displayFlight(Flight f);
void initStack(List *s);
bool isStackEmpty(List s);
bool isStackFull(List s);
bool pushFlight(List *s, Flight f);
bool popFlight(List *s);
Flight peekFlight(List s);
void printStack(List s);
int removeAllByDestination(List *s, const char *dest);
int keepOnlyMorning(List *s);
int popTopK(List *s, Flight out[], int k);
int duplicateTop(List *s);


#endif
