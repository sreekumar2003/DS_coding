#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL; // Initialize the top of the stack
struct node *temp; // Temporary node pointer

void push();
void pop();
void display();

int main() {
    int ch;
    
    while (1) {
        printf("\n\nStack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);  // Exit the program
            default: printf("\tInvalid choice\n");
        }
    }
    
    return 0;
}

// Function to push an element onto the stack
void push() {
    struct node *nw = (struct node*)malloc(sizeof(struct node)); // Create a new node
    int x;
    printf("\tEnter a value to be pushed: ");
    scanf("%d", &x);
    
    nw->data = x;
    nw->next = top;  // Link the new node with the top
    top = nw;  // Update the top to point to the new node
    
    printf("\t%d pushed onto the stack\n", x);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("\tStack is empty! Cannot pop.\n");
    } else {
        temp = top;  // Set temp to the top node
        printf("\tThe popped element is %d\n", temp->data);
        top = top->next;  // Move the top to the next node
        free(temp);  // Free the popped node
    }
}

// Function to display the stack
void display() {
    if (top == NULL) {
        printf("\tStack is empty!\n");
    } else {
        printf("\tThe Stack elements are: ");
        for (temp = top; temp != NULL; temp = temp->next) {
            printf("%d -> ", temp->data);
        }
        printf("NULL\n");  // End of the stack
    }
}
