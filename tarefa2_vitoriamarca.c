/*
Vitória Marca Santa Lucia - 23200577
Algoritmos e Estruturas de Dados I 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct SeatManager {
    int *nodes; //nodes array
    int size;
    int total_size;
} SeatManager;

SeatManager* seatManagerCreate( int n ) {
    SeatManager *current = malloc ( sizeof( *current ) );
    if ( !current ) {
        printf("Error Allocating memory.\n");
        exit( 1 );
    }

    current -> total_size = n;
    current -> nodes = malloc ( n * sizeof( int )); //allocating enough memory to SeatManager's size
    current -> size = n; 

    for ( int i = 0; i < n; i++ ) {
        current->nodes[i] = i + 1;  // filling the seat list
    }

    return current;
}

int seatManagerReserve( SeatManager* obj ) {
    if ( obj -> size == 0 ) return -1; // avoiding error by trying to access unexistent seat

    //we have to reorganize the nodes to make sure this position is always the position of the smallest seat/number
    int min = obj -> nodes[0]; // smallest seat is on top

    obj -> nodes[0] = obj -> nodes[obj -> size - 1]; // switch top element with bottom one (size - 1)
    obj -> size--; // decreasing seatManager's size

    /*if an element is on index i:

    its left sun is at 2*i + 1
    its right sun is at 2*i + 2
    its parent is at (i-1)/2 (integer division) */

    int i = 0; //heap index
    while (1) {
        //reorganizing nodes
        int left = 2 * i + 1; 
        int right = 2 * i + 2;
        int smallest = i;

        //if left < size and left < parent, switch them (bc left actually is the smallest)
        if ( left < obj -> size && obj -> nodes[left] < obj -> nodes[smallest] ) {
            smallest = left;
        }

        //if right < size and right < parent, switch them (bc right actually is the smallest)
        if ( right < obj -> size && obj -> nodes[right] < obj -> nodes[smallest] ) {
            smallest = right;
        }

        //if smallest isn't the parent anymore, we have to switch them    
        if ( smallest != i ) {
            int temp = obj -> nodes[i];
            obj -> nodes[i] = obj -> nodes[smallest];
            obj -> nodes[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
    return min;
}

void seatManagerUnreserve( SeatManager* obj, int seatNumber ) {
    if ( obj -> size == obj -> total_size ) return; // avoiding buffer overflow 

    obj -> nodes[obj -> size] = seatNumber; // adding the seat at the end of the heap
    int i = obj -> size;
    obj -> size++;

    //now we reorganize the heap with the new seat 
    while ( i > 0 ) {
        int parent = ( i - 1 ) / 2; //parent of the index we're analysing
        if ( obj -> nodes[i] < obj -> nodes[parent] ) { //if "i" < "i's parent" (we don't want it)
            //switch them ( bc the smallest number has to be parent)
            int temp = obj -> nodes[i];
            obj -> nodes[i] = obj -> nodes[parent];
            obj -> nodes[parent] = temp;
            i = parent;
        } else {
            break;
        }
    }
}

void seatManagerFree( SeatManager* obj ) {
    free( obj->nodes ); //nodes
    free( obj ); //SeatManager
}

int main(){
    SeatManager* sm = seatManagerCreate(5);

    printf("Reservado: %d\n", seatManagerReserve(sm));
    printf("Reservado: %d\n", seatManagerReserve(sm));

    seatManagerUnreserve(sm, 1);
    printf("Reservado: %d\n", seatManagerReserve(sm));

    seatManagerFree(sm);
    return 0;
}