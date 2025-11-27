#include "flightsheader.h"

Time createTime(int h, int m)
{
    Time t = {h, m};
    return t;
}

Flight createFlight(int id, const char *orig, const char *dest,
                    Time dep, Time arr)
{
    Flight temp;
    temp.id = id;
    strcpy(temp.origin, orig);
    strcpy(temp.destination, dest);
    temp.departure = dep;
    temp.arrival = arr;
    return temp;
}

void displayTime(Time t)
{
    int hh = t.hours % 12;
    if (hh == 0)
        hh = 12;
    printf("%02d:%02d %s", hh, t.minutes, (t.hours < 12 ? "AM" : "PM"));
}

void displayFlight(Flight f)
{
    printf("Flight #%d %s -> %s | Dep: ", f.id, f.origin, f.destination);
    displayTime(f.departure);
    printf("  Arr: ");
    displayTime(f.arrival);
    printf("\n");
}

/* --- Stack operations --- */
void initStack(List *s)
{
    *s = NULL;
}

bool isStackEmpty(List s)
{
    return s == NULL;
}

bool isStackFull(List s)
{
    return false;
}

bool pushFlight(List *s, Flight f)
{
    if (isStackFull(*s))
    {
        return false;
    }
    List nnode = malloc(sizeof(Node));
    nnode->data = f;
    nnode->add = *s;
    *s = nnode;
}

bool popFlight(List *s)
{
    if (isStackEmpty(*s))
    {
        printf("NO POP!");
        return false;
    }

    List curr = *s;
    *s = curr->add;
    free(curr);
    return true;
}

Flight peekFlight(List s)
{
    return s->data;
}

void printStack(List s)
{

    for(;s != NULL; s = s->add){
        Flight f = peekFlight(s);
        displayFlight(f);
    }
}

// Remove every flight whose destination == dest.
// Preserve the order of the remaining flights.
// Return how many flights were removed.
int removeAllByDestination(FlightStack *s, const char *dest) {
    // TODO: use an auxiliary stack to filter, then restore to 's' preserving order.
    // Hint: pop -> keep or discard -> rebuild with another temp stack to restore order.
    FlightStack temp;
    int tempcnt =0;
    int cnt =0;

    for(int i =(*s).top; i != -1;i--){
        Flight g = popFlight(s);

       if(strcmp(g.destination, dest) == 0){
           cnt++;
       }else{
           temp.stack[tempcnt++]= g;
       }
    }
    for(int i =tempcnt-1; i != -1;i--){
        pushFlight(s,temp.stack[i]);
    }

    return cnt;
}

// // Remove flights that are NOT morning departures.
// // Return how many were removed. Preserve order of those kept.
// int keepOnlyMorning(FlightStack *s) {

//     int cnt = 0;
//     FlightStack btemp;
//     int bcnt = 0;
//     for(int i =s->top; i !=-1;i--){
//         Flight b = popFlight(s);

//         if(b.departure.hours > 12){
//             cnt++;
//         }else{
//             btemp.stack[bcnt++] = b;
//         }

//     }

//     for(int i =bcnt-1; i!= -1; i--){
//         pushFlight(s,btemp.stack[i]);
//     }

//         return cnt;
// }

// // Pop up to k flights into 'out' (out[0] = former top), return how many actually popped.
// int popTopK(FlightStack *s, Flight out[], int k) {
//     int i =0;
//     int tempt = 0;

//     for(i =0;i<k; i++){

//         out[tempt] = popFlight(s);
//         printf("%d\n",out[tempt].id);
//         tempt++;
//     }

//     return i;
// }
// int duplicateTop(FlightStack *s) {
//     Flight g = peekFlight(*s);
//     if(s->top == -1)return 0;
//     pushFlight(s,g);
//     return 1;
// }

// typedef struct {
//     int  id;
//     char origin[50];
//     char destination[50];
//     Time departure;
//     Time arrival;
// } Flight;

// typedef struct {
//     Flight stack[STACK_SIZE];
//     int top;
// } FlightStack;

// typedef struct {
//     int hours;   // 0-23
//     int minutes; // 0-59
// } Time;
