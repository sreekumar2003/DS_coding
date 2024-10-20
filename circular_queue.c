#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Define the size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;  // Initialize front and rear
void enqueue();
void dequeue();
void display();
int main() {
    int choice;
    
    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice! Please enter again.\n");
        }
    }
    return 0;
}
void enqueue() {
    int value;
    
    if ((rear + 1) % SIZE == front) {
        printf("Queue is Full! Insertion not possible.\n");
    } else {
        printf("Enter the value to insert: ");
        scanf("%d", &value);
        
        if (front == -1) {
            front = 0;  // Set front when inserting the first element
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Function to delete an element from the queue
void dequeue() {
    if (front == -1) {
        printf("Queue is Empty! Deletion not possible.\n");
    } else {
        printf("Deleted %d\n", queue[front]);
        
        if (front == rear) {
            front = rear = -1;  // Queue is now empty after deletion
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

// Function to display the queue
void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
    } else {
        int i;
        printf("Queue elements: ");
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[i]);  // Display the last element
    }
}

