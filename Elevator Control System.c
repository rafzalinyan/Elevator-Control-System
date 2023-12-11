#include <stdio.h>
#include <stdlib.h>

// Define the structure for a request node
typedef struct RequestNode {
    int floor;
    struct RequestNode* next;
} RequestNode;

// Define a structure for the elevator
typedef struct Elevator {
    int current_floor;
    RequestNode* request_queue;
} Elevator;

// Create a new request node
RequestNode* createRequestNode(int floor) {
    RequestNode* newNode = (RequestNode*)malloc(sizeof(RequestNode));
    newNode->floor = floor;
    newNode->next = NULL;
    return newNode;
}

// Insert a request into the elevator's request queue (linked list) in ascending order
void insertRequest(Elevator* elevator, int floor) {
    RequestNode* newNode = createRequestNode(floor);

    if (elevator->request_queue == NULL || floor < elevator->request_queue->floor) {
        // Insert at the beginning if the queue is empty or the new request is at a lower floor
        newNode->next = elevator->request_queue;
        elevator->request_queue = newNode;
    } else {
        // Insert in ascending order
        RequestNode* current = elevator->request_queue;
        RequestNode* prev = NULL;
        while (current != NULL && current->floor < floor) {
            prev = current;
            current = current->next;
        }
        newNode->next = current;
        if (prev == NULL) {
            elevator->request_queue = newNode;
        } else {
            prev->next = newNode;
        }
    }
}

// Move the elevator to a target floor and serve requests
void moveToFloor(Elevator* elevator, int target_floor) {
    printf("Moving from Floor %d to Floor %d\n", elevator->current_floor, target_floor);
    elevator->current_floor = target_floor;
    printf("Opening doors on Floor %d\n", target_floor);

    // Serve requests for the current floor
    RequestNode* current = elevator->request_queue;
    RequestNode* prev = NULL;
    while (current != NULL) {
        if (current->floor == target_floor) {
            printf("Serving request on Floor %d\n", target_floor);

            // Modify to serve multiple requests at the same target floor
            while (current != NULL && current->floor == target_floor) {
                RequestNode* temp = current;
                if (prev == NULL) {
                    elevator->request_queue = current->next;
                } else {
                    prev->next = current->next;
                }
                current = current->next;
                free(temp);
            }
        } else {
            prev = current;
            current = current->next;
        }
    }

    printf("Closing doors on Floor %d\n", target_floor);
}

int main() {
    char run_again;

    do {
        Elevator elevator;
        elevator.current_floor = 0;
        elevator.request_queue = NULL;

        int num_floors, num_people;

        printf("Enter the number of floors: ");
        scanf("%d", &num_floors);

        printf("Enter the number of people: ");
        scanf("%d", &num_people);

        // Simulate passengers entering the elevator
        for (int i = 0; i < num_people; ++i) {
            int target_floor;
            printf("Person %d: Enter the target floor (0 to %d): ", i + 1, num_floors - 1);
            scanf("%d", &target_floor);

            if (target_floor < 0 || target_floor >= num_floors) {
                printf("Invalid floor selection. Please enter a floor between 0 and %d.\n", num_floors - 1);
                --i; // Decrement i to repeat the input for the same person
            } else {
                insertRequest(&elevator, target_floor);
            }
        }

        // Process requests and move the elevator
        while (elevator.request_queue != NULL) {
            moveToFloor(&elevator, elevator.request_queue->floor);
        }

        printf("Simulation completed.\n");

        // Ask if the user wants to run another simulation
        printf("Do you want to run another simulation? (y/n): ");
        scanf(" %c", &run_again);

    } while (run_again == 'y' || run_again == 'Y');

    return 0;
}
