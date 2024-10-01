// Creating a Single Linked List
// To store n values on a linked list reading the data from keyboard.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;                 // Data part
    struct node *next;        // Address part
} *header;

void createList(int n);       // Function to create list

int main() {
    int n;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    return 0;
}
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL) {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node1: ");
        scanf("%d', &data");

        newNode->data = data;        // Links the data field with data
        newNode->next = NULL;        // Links the address field with NULL
        header = newNode;            // Header points to the first node
        temp = newNode;              // First node is the current node
        
        for(i=2; i <= n; i++)
        {
            newNode = (struct node*)malloc(sizeof(struct node));

            if(newNode == NULL) {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data;     // Links the data field of newNode with data
                newNode->next = NULL;     // Links the address field of newNode with NULL

                temp->next = newNode;     // Links previous node i.e. temp to the newNode
                temp = temp->next;
            }
        }
        printf("\n\n Memory Allocation Success.");
    }
}
