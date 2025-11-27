#ifndef FLIGHTS_H
#define FLIGHTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 5

typedef struct {
    int hours;
    int minutes;
} Time;

typedef struct {
    int id;
    char origin[50];
    char destination[50];
    Time departure_time;
    Time arrival_time;
} Flight;

typedef struct {
    Flight *flights;
    int count;
    int max;
} Flights;

// Function prototypes
Flight createFlight(int id);
void addFlight(Flights *flight_list, Flight f);
Flight removeFlight(Flights *flightlist, int flightid);
void showFlights(Flights flight_list);
void displayFlightInfo(Flights f, int q);
void displayCurrtime(Time t);
Time createTime(int h, int m);

#endif
