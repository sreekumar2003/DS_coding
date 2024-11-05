#include<stdio.h>
#include<stdlib.h>

int count = 0;

struct node {
    int data;
    struct node* next;
};

struct node* start = NULL;

void create();
void insb();
void inse();
void insp();
void delb();
void dele();
void delp();
void display();

int main()
{
    int ch;
    while (1)
    {
		printf("\n1. Creation\n2. Insert at beginning \n3. Insert at end \n4. Insert at position \n");
		printf("5. Delete from beginning \n6. Delete from end \n7. Delete from position \n8. Display \n9. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);

		switch (ch)
		{
			case 1:
			create();
			break;
			case 2:
			insb();
			break;
			case 3:
			inse();
			break;
			case 4:
			insp();
			break;
			case 5:
			delb();
			break;
			case 6:
			dele();
			break;
			case 7:
			delp();
			break;
			case 8:
			display();
			break;
			case 9:
			exit(0);
			default:
			printf("\nInvalid choice");
		}
    }
}

void create() 
{
    int n, item, i = 0;
    struct node *ptr, *temp;

    if (count == 0) 
	{
		printf("\nEnter the number of nodes to be inserted: ");
		scanf("%d", &n);

		if (n == 0)
		{
			printf("\nNo nodes to create.");
			return;
		}

		while (i < n)
		{
			printf("\nEnter value to insert: ");
			scanf("%d", &item);

			ptr = (struct node*) malloc(sizeof(struct node));
			ptr->data = item;

			if (count == 0) 
			{
				start = ptr;
				start->next = NULL;
				temp = start;
			}
			else 
			{
				temp->next = ptr;
				temp = temp->next;
				temp->next = NULL;
			}

			count++;
			i++;
		}
    } 
	else 
	{
		printf("\nList already created.");
    }
}

void insb()
{
    int data;
    struct node* ptr;

    printf("\nEnter value to insert: ");
    scanf("%d", &data);

    ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = data;

    if (start == NULL) 
	{
		start = ptr;
		start->next = NULL;
    } 
	else 
	{
		ptr->next = start;
		start = ptr;
    }
    count++;
}

void inse() 
{
    struct node *ptr, *temp;
    int item;

    ptr = (struct node*) malloc(sizeof(struct node));

    printf("\nEnter value: ");
    scanf("%d", &item);

    ptr->data = item;
    ptr->next = NULL;

    if (start == NULL) 
	{
		start = ptr;
    } 
	else 
	{
		temp = start;
		while (temp->next != NULL)
		{
	    	temp = temp->next;
		}
		temp->next = ptr;
    }
    count++;
    printf("\nNode inserted.");
}

void insp() {
    int item, pos, i;
    struct node *ptr, *temp;

    printf("\nEnter value: ");
    scanf("%d", &item);
    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count + 1) 
	{
		printf("\nInvalid position!");
		return;
    }

    ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = item;

    if (pos == 1) 
	{
		ptr->next = start;
		start = ptr;
    } 
	else 
	{
		temp = start;
		for (i = 1; i < pos - 1; i++) 
		{
			temp = temp->next;
		}
		ptr->next = temp->next;
		temp->next = ptr;
    }
    count++;
    printf("\nNode inserted.");
}

void delb() {
    struct node* temp;

    if (start == NULL) 
	{
		printf("\nList is empty.");
    } 
	else
	{
		temp = start;
		start = temp->next;
		free(temp);
		count--;
		printf("\nNode deleted.");
    }
}

void dele() {
    struct node *temp, *ptr;

    if (start == NULL) 
	{
		printf("\nList is empty.");
    } 
	else if (start->next == NULL)
	{
		temp = start;
		start = NULL;
		free(temp);
		count--;
		printf("\nNode deleted.");
    } 
	else 
	{
		temp = start;
		while (temp->next->next != NULL) 
		{
			temp = temp->next;
		}
		ptr = temp->next;
		temp->next = NULL;
		free(ptr);
		count--;
		printf("\nNode deleted.");
    }
}

void delp() 
{
    struct node *temp, *ptr;
    int pos, i;

    if (start == NULL) 
	{
		printf("\nList is empty.");
		return;
    }

    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count)
	{
		printf("\nInvalid position!");
		return;
    }

    if (pos == 1) 
	{
		temp = start;
		start = temp->next;
		free(temp);
    } 
	else 
	{
		temp = start;
		for (i = 1; i < pos - 1; i++) 
		{
			temp = temp->next;
		}
		ptr = temp->next;
		temp->next = ptr->next;
		free(ptr);
    }
    count--;
    printf("\nNode deleted.");
}
void display() 
{
    struct node* ptr;

    if (start == NULL) 
	{
		printf("\nList is empty.");
		return;
    }

    printf("\nList: ");
    ptr = start;
    while (ptr != NULL) 
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
    }
    printf("NULL\n");
}