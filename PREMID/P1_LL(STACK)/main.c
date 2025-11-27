#include "flightsheader.h"

int main(){
     FlightStack S; initStack(&S);

    // Static flights (no typing)
    Flight f1 = createFlight(1001, "CEB", "MNL", createTime(6,30),  createTime(8,5));
    Flight f2 = createFlight(1002, "MNL", "DVO", createTime(9,45),  createTime(11,15));
    Flight f3 = createFlight(1003, "DVO", "ILO", createTime(14,10), createTime(15,50));
    Flight f4 = createFlight(1004, "MNL", "MNL", createTime(10, 0), createTime(10,45));
    Flight f5 = createFlight(1005, "CEB", "ILO", createTime(7,20),  createTime(8,30));

    pushFlight(&S, f1);
    pushFlight(&S, f2);
    pushFlight(&S, f3);
    pushFlight(&S, f4);
    pushFlight(&S, f5);

    printf("=== Initial stack (top first) ===\n");
    printStack(S);

    printf("\n=== A) removeAllByDestination(dest = \"ILO\") ===\n");
    int remA = removeAllByDestination(&S, "ILO");
    printf("removed: %d\n", remA);
    printStack(S);

    printf("\n=== B) keepOnlyMorning() ===\n");
    int remB = keepOnlyMorning(&S);
    printf("removed: %d\n", remB);
    printStack(S);

    printf("\n=== C) popTopK(k=2) ===\n");
    Flight popped[3];
    int got = popTopK(&S, popped, 2);
    printf("popped count: %d\n", got);
    for (int i = 0; i < got; ++i) displayFlight(popped[i]);
    printf("stack after popTopK:\n");
    printStack(S);

    printf("\n=== D) duplicateTop() ===\n");
    printf("dup ok? %s\n", duplicateTop(&S) ? "yes" : "no");
    printStack(S);

    // printf("\n=== E) moveByOrigin(fromCity = \"CEB\") to T ===\n");
    // FlightStack T; initStack(&T);
    // int moved = moveByOrigin(&S, &T, "CEB");
    // printf("moved: %d\n", moved);
    // printf("S after move:\n"); printStack(S);
    // printf("T after move:\n"); printStack(T);

    // printf("\n=== F) findById(1002) (non-destructive) ===\n");
    // Flight found = findById(&S, 1002);
    // if (found.id != -1) displayFlight(found); else printf("not found\n");
    // printf("S after find (should be unchanged):\n");
    // printStack(S);

    return 0;
}

