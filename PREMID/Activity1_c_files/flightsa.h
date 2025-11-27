#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "flights.h"

Flight createFlight(int id){
    Flight nfly;
    nfly.id = id;
    strcpy(nfly.origin, "Manila");
    strcpy(nfly.destination, "Los Angeles");
    nfly.departure_time.hours = 1;
    nfly.departure_time.minutes = 23;
    nfly.arrival_time.hours = 5;
    nfly.arrival_time.minutes = 19;
    return nfly;
}

void addFlight(Flights *flight_list, Flight f){
    int cnt = flight_list->count++;
    flight_list->flights[cnt] = f;
}

Flight removeFlight(Flights *flightlist, int flightid){
    Flight temp;
    int q = -1;
    for(int i = 0; i < LIMIT; i++){
        if(flightlist->flights[i].id == flightid){
            flightlist->flights[i] = flightlist->flights[i+1];
            flightlist->count--;
            q = 0;
            break;
        }
    }

    if(q == -1){
        temp.id = -1;
        return temp;
    }
}

void showFlights(Flights flight_list){
    int max = flight_list.count;
    printf("\n=========Flight for today=========\n");
    for(int i = 0; i < max; i++){
        if(flight_list.flights[i].id != -1){
            printf("Flight Number:%d\n", flight_list.flights[i].id);
        }
    }
}

void displayFlightInfo(Flights f, int q){
    int max = f.count;
    for(int i = 0; i < max; i++){
        if(f.flights[i].id == q){
            printf("\n========Flight Details of %d============\n", q);
            printf("%s ===>", f.flights[i].origin);
            printf(" %s\n", f.flights[i].destination);
            printf("Departure Time: %d:%d\n", f.flights[i].departure_time.hours, f.flights[i].departure_time.minutes);
            printf("Arrival Time: %d:%d\n", f.flights[i].arrival_time.hours, f.flights[i].arrival_time.minutes);
            printf("\n=========================================\n");
        }
    }
}

void displayCurrtime(Time t){
    printf("Current Time: %d:%d AM\n", t.hours, t.minutes);
}

Time createTime(int h, int m){
    Time s;
    s.hours = h;
    s.minutes = m;
    return s;
}
