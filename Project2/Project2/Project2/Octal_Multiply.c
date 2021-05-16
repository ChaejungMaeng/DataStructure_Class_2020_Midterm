
//  Created by ∏Õ√§¡§ on 2020/5/6.
//  Copyright ? 2020 ∏Õ√§¡§. All rights reserved.
//
// C program to Multiply two numbers
// represented as linked lists



#include <stdio.h>
#include <stdlib.h>

// Linked list Node
struct Node {
    int num;
    struct Node* next_1;
};

// create a new Node

struct Node* newNode(int data)
{
    struct Node* new_node =
        (struct Node*)malloc(sizeof(struct Node));
    new_node->num = data;
    new_node->next_1 = NULL;
    return new_node;
}

// insert a Node at the Linked List
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = newNode(new_data);
    new_node->next_1 = (*head_ref);
    (*head_ref) = new_node;
}

// reverse the linked list and return

int reverse(struct Node** head_ref)
{
    struct Node* lastone = NULL;
    struct Node* current1 = *head_ref;
    struct Node* next;
    int length = 0;
    while (current1 != NULL) {
        length++;
        next = current1->next_1;
        current1->next_1 = lastone;
        lastone = current1;
        current1 = next;
    }
    *head_ref = lastone;
    return length;
}

// make an empty linked list of

struct Node* make_emptylist(int size)
{
    struct Node* head = NULL;
    while (size--)
        push(&head, 0);
    return head;
}

// Multiply contents of two linked lists
struct Node* multiplyTwoLists(struct Node* first_L,
                           struct Node* second_L)
{
    // reverse the lists to muliply from end
    int m = reverse(&first_L), n = reverse(&second_L);

    // make a result list
    // m+n+1 : max size of the list
    struct Node* result = make_emptylist(m + n + 1);

    struct Node *second_ptr = second_L,
          *result_ptr1 = result, *result_ptr2, *first_ptr;

    // multiply each Node of second list with first
    while (second_ptr) {

        int carry1 = 0;

        result_ptr2 = result_ptr1;

        first_ptr = first_L;

        while (first_ptr) {

            // multiply a first list's digit and second list's digit
            int multi = first_ptr->num * second_ptr->num
                      + carry1;

            result_ptr2->num += multi % 8;

            carry1 = multi / 8 + result_ptr2->num / 8;
            result_ptr2->num = result_ptr2->num % 8;

            first_ptr = first_ptr->next_1;
            result_ptr2 = result_ptr2->next_1;
        }

        // if carry is remaining from last multiplication
        if (carry1 > 0) {
            result_ptr2->num += carry1;
        }

        result_ptr1 = result_ptr1->next_1;
        second_ptr = second_ptr->next_1;
    }

    // reverse the result_list 
    reverse(&result);
    reverse(&first_L);
    reverse(&second_L);

    // remove if there are zeros at starting
    while (result->num == 0) {
        struct Node* temp = result;
        result = result->next_1;
        free(temp);
    }

    // Return head of multiplication list
    return result;
}

// print a linked list
void print_List(struct Node* Node)
{
    while (Node != NULL) {
        printf("%d", Node->num);
        if (Node->next_1)
            printf("->");
        Node = Node->next_1;
    }
    printf("\n");
}

int main(void)
{
    struct Node* first = NULL;
    struct Node* second = NULL;

    // create first list 
    push(&first, 4);
    push(&first, 3);
    push(&first, 2);
    push(&first, 1);
//    push(&first, 9);

    printf("First List is: ");
    print_List(first);

    // create second list 
    push(&second, 4);
    push(&second, 3);
//    push(&second, 8);
//    push(&second, 9);

    printf("Second List is: ");
    print_List(second);

    // Multiply the two lists and print result
    struct Node* result = multiplyTwoLists(first, second);
    printf("Resultant list is: ");
    print_List(result);

    return 0;
}


