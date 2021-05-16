//
//  add_Octal.c
//  DS_midterm
//
//  Created by ∏Õ√§¡§ on 2020/5/6.
//  Copyright ? 2020 ∏Õ√§¡§. All rights reserved.
//

/*

#include<stdio.h>
#include<stdlib.h>

// Linked list node
struct Node
{
    int num;
    struct Node* next_1;
};

// Function to create a new node with given data
struct Node *newNode(int data)
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->num = data;
    new_node->next_1 = NULL;
    return new_node;
}

// insert a node at the beginning of the Singly Linked List
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = newNode(new_data);
    new_node->next_1 = (*head_ref);
    (*head_ref)    = new_node;
}

// Add contents of two linked lists and return the head node of resultant list
struct Node* addTwoLists (struct Node* first_L, struct Node* second_L)
{
    struct Node* res = NULL; // res is head node of the resultant list
    struct Node *temp = NULL; 
    struct Node *prev = NULL;
    int carry = 0, sum;

    while (first_L != NULL || second_L != NULL)
    {
     
        sum = carry + (first_L? first_L->num: 0) + (second_L? second_L->num: 0);

        // update carry for next calulation
        carry = (sum >= 10)? 1 : 0;

        // update sum if it is greater than 10
        sum = sum % 8;

        // Create a new node with sum as data
        temp = newNode(sum);

        // if this is the first node then set it as head of the resultant list
        if(res == NULL)
            res = temp;
        else // If this is not the first node then connect it to the rest.
            prev->next_1 = temp;

        // Set prev for next insertion
        prev  = temp;

        // Move first and second pointers to next nodes
        if (first_L) first_L = first_L->next_1;
        if (second_L) second_L = second_L->next_1;
    }

    if (carry > 0)
      temp->next_1 = newNode(carry);

    return res;
}

// print a linked list
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->num);
        node = node->next_1;
    }
    printf("\n");
}

int main(void)
{
    struct Node* res = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;

    // create first list 7->5->9->4->2
    push(&first, 2);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    printList(first);

    // create second list 8->2
    push(&second, 2);
    push(&second, 8);
    printf("Second List is ");
    printList(second);

    // Add the two lists and see result
    res = addTwoLists(first, second);
    printf("Resultant list is ");
    printList(res);

   return 0;
}



*/