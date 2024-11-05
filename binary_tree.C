#include <stdio.h>
#include <stdlib.h>

// Define a simple node structure for the binary tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Global root pointer
struct node* root = NULL;

// Function to create a new node with given data
struct node* create_node(int item) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node in the binary tree
void insert_node() {
    int item;
    printf("Enter item for new node: ");
    scanf("%d", &item);

    // Create the new node
    struct node* new_node = create_node(item);

    // If the tree is empty, make the new node the root
    if (root == NULL) {
        root = new_node;
        printf("%d was inserted as the root\n", item);
        return;
    }

    // Otherwise, insert the node in the tree
    struct node* temp = root;

    // Traverse the tree to find a spot for the new node
    while (1) {
        // If the value is less than the current node, go to the left
        if (item < temp->data) {
            if (temp->left == NULL) {
                temp->left = new_node;
                printf("%d was inserted to the left of %d\n", item, temp->data);
                return;
            } else {
                temp = temp->left; // Move left if there's already a node
            }
        }
        // If the value is greater than or equal, go to the right
        else {
            if (temp->right == NULL) {
                temp->right = new_node;
                printf("%d was inserted to the right of %d\n", item, temp->data);
                return;
            } else {
                temp = temp->right; // Move right if there's already a node
            }
        }
    }
}

// Delete a node from the tree
void delete_node() {
    int item;
    printf("Enter the item to delete: ");
    scanf("%d", &item);

    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    struct node* temp = root;
    struct node* parent = NULL;

    // Find the node to delete
    while (temp != NULL && temp->data != item) {
        parent = temp;
        if (item < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    // If the node is not found
    if (temp == NULL) {
        printf("%d not found in the tree\n", item);
        return;
    }

    // Case 1: Node has no children (leaf node)
    if (temp->left == NULL && temp->right == NULL) {
        if (parent == NULL) {
            root = NULL;  // The root is the node to be deleted
        } else if (parent->left == temp) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(temp);
        printf("%d was deleted\n", item);
        return;
    }

    // Case 2: Node has one child
    if (temp->left == NULL || temp->right == NULL) {
        struct node* child = (temp->left != NULL) ? temp->left : temp->right;
        if (parent == NULL) {
            root = child;  // If the root is to be deleted, promote the child
        } else if (parent->left == temp) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        free(temp);
        printf("%d was deleted\n", item);
        return;
    }

    // Case 3: Node has two children (we won't handle this case for simplicity)
    printf("Deleting node with two children is not implemented in this simplified version\n");
}

// Inorder traversal of the binary tree (left-root-right)
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal (root-left-right)
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (left-right-root)
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function to control the flow of the program
int main() {
    int choice;

    while (1) {
        printf("\n1. Insert a Node\n");
        printf("2. Delete a Node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_node();
                break;
            case 2:
                delete_node();
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}