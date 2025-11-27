#include "flights.h"

int main(){
    Flights n;
    n.count = 0;
    n.max = LIMIT;
    Flight *q = malloc(sizeof(Flight) * LIMIT);
    n.flights = q;

    displayCurrtime(createTime(9, 10));

    Flight f1 = createFlight(101);
    Flight f2 = createFlight(104);
    Flight f3 = createFlight(102);

    addFlight(&n, f1);
    addFlight(&n, f2);
    addFlight(&n, f3);

    showFlights(n);
    printf("\n");

    displayFlightInfo(n, 101);

    int rid = 102;
    printf("\nREMOVING FLIGHT: %d\n", rid);
    removeFlight(&n, rid);
    printf("\n");

    showFlights(n);

    free(q);
    return 0;
}
