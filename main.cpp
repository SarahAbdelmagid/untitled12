#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int id;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;  // Pointer to the front of the queue
    struct Node* rear;   // Pointer to the rear of the queue
};

// Function to initialize the queue
void initializeQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Function to enqueue a person based on their ID
void enqueue(struct Queue* q, int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = id;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        // Check the ID and add to the queue accordingly
        if (id == 3) {
            // Senior citizen, add to the top of the queue
            newNode->next = q->front;
            q->front = newNode;
        } else if (id == 2) {
            // Special customer, add 2 behind the person at the head of the queue
            newNode->next = q->front->next;
            q->front->next = newNode;
            if (newNode->next == NULL) {
                q->rear = newNode;
            }
        } else {
            // Ordinary customer, add to the end of the queue
            q->rear->next = newNode;
            q->rear = newNode;
        }
    }

    printf("ID%d added to the queue.\n", id);
}

// Function to dequeue a person from the front of the queue
void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = q->front;
    q->front = temp->next;

    printf("ID%d processed.\n", temp->id);

    free(temp);

    if (q->front == NULL) {
        q->rear = NULL;
    }
}

// Function to display the contents of the queue
void displayQueue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front part of the queue: ");
    struct Node* current = q->front;
    while (current != NULL) {
        printf("ID%d ", current->id);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initializeQueue(&q);

    int choice, id;

    do {
        printf("\nMenu:\n");
        printf("1. Add person to the queue\n");
        printf("2. Process person from the queue\n");
        printf("3. View the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID number of the person: ");
                scanf("%d", &id);
                enqueue(&q, id);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                displayQueue(&q);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
