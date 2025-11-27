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

typedef struct {
    Flight stack[STACK_SIZE];
    int top;   
} FlightStack;


Time createTime(int h, int m); 
Flight createFlight(int id, const char *orig, const char *dest,Time dep, Time arr); 
void displayTime(Time t); 
void displayFlight(Flight f);
void initStack(FlightStack *s);
bool isStackEmpty(FlightStack s);
bool isStackFull(FlightStack s);
bool pushFlight(FlightStack *s, Flight f);
Flight popFlight(FlightStack *s);
Flight peekFlight(FlightStack s);
void printStack(FlightStack s);
int removeAllByDestination(FlightStack *s, const char *dest);
int keepOnlyMorning(FlightStack *s);
int popTopK(FlightStack *s, Flight out[], int k);
int duplicateTop(FlightStack *s);
#endif
