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
    if (flight_list->count >= flight_list->max) return;
    flight_list->flights[flight_list->count++] = f;
}

Flight removeFlight(Flights *flightlist, int flightid){
    Flight notFound = { .id = -1 };
    int idx = -1;
    for(int i = 0; i < flightlist->count; i++){
        if(flightlist->flights[i].id == flightid){
            idx = i;
            break;
        }
    }
    if (idx == -1) return notFound;

    Flight removed = flightlist->flights[idx];
    for (int i = idx + 1; i < flightlist->count; i++){
        flightlist->flights[i - 1] = flightlist->flights[i];
    }
    flightlist->count--;
    return removed;
}

void showFlights(Flights flight_list){
    printf("\n=========Flight for today=========\n");
    for(int i = 0; i < flight_list.count; i++){
        if(flight_list.flights[i].id != -1){
            printf("Flight Number:%d\n", flight_list.flights[i].id);
        }
    }
}

void displayFlightInfo(Flights f, int q){
    for(int i = 0; i < f.count; i++){
        if(f.flights[i].id == q){
            printf("\n========Flight Details of %d============\n", q);
            printf("%s ===> %s\n", f.flights[i].origin, f.flights[i].destination);
            printf("Departure Time: %d:%d\n", f.flights[i].departure_time.hours, f.flights[i].departure_time.minutes);
            printf("Arrival Time: %d:%d\n", f.flights[i].arrival_time.hours, f.flights[i].arrival_time.minutes);
            printf("=========================================\n");
            return;
        }
    }
}

void displayCurrtime(Time t){
    printf("Current Time: %02d:%02d AM\n", t.hours, t.minutes);
}

Time createTime(int h, int m){
    Time s = { h, m };
    return s;
}
