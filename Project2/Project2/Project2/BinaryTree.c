
/*
#include <stdio.h>
#include <stdlib.h>

struct btnode
{
    int val;
    struct btnode* left;
    struct btnode* right;
}*root_1 = NULL, * temp1 = NULL, * t2, * t1;

void delete_1();
void insert();
void delete();

void create();
void search(struct btnode* t);

void inorderBT(struct btnode* t);
void preorderBT(struct btnode* t);
void postorderBT(struct btnode* t);

void search_1(struct btnode* t, int data);
int small(struct btnode* t);
int large(struct btnode* t);

int flag = 1;

void main()
{
    int char_1;

    printf("\n--MENU--");
    printf("\n1 : Insert an element into tree\n");
    printf("2 : Delete an element from the tree\n");
    printf("3 : Inorder Traversal\n");
    printf("4 : Preorder Traversal\n");
    printf("5 : Postorder Traversal\n");
    printf("6 : Exit\n");
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &char_1);
        switch (char_1)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            inorderBT(root_1);
            break;
        case 4:
            preorderBT(root_1);
            break;
        case 5:
            postorderBT(root_1);
            break;
        case 6:
            exit(0);
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}

// To insert a node in the tree 
void insert()
{
    create();
    if (root_1 == NULL)
        root_1 = temp1;
    else
        search(root_1);
}

// create a node 
void create()
{
    int data;

    printf("Enter data of node to be inserted : ");
    scanf("%d", &data);
    temp1 = (struct btnode*)malloc(1 * sizeof(struct btnode));
    temp1->val = data;
    temp1->left = temp1->right = NULL;
}

//search the appropriate position to insert the new node 
void search(struct btnode* t)
{
    if ((temp1->val > t->val) && (t->right != NULL))      //value more than root node value insert at right 
        search(t->right);
    else if ((temp1->val > t->val) && (t->right == NULL))
        t->right = temp1;
    else if ((temp1->val < t->val) && (t->left != NULL))    //value less than root node value insert at left 
        search(t->left);
    else if ((temp1->val < t->val) && (t->left == NULL))
        t->left = temp1;
}

//inorder traversal of tree 
void inorderBT(struct btnode* t)
{
    if (root_1 == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    if (t->left != NULL)
        inorderBT(t->left);
    printf("%d -> ", t->val);
    if (t->right != NULL)
        inorderBT(t->right);
}

// To check for the deleted node 
void delete()
{
    int data;

    if (root_1 == NULL)
    {
        printf("No elements in a tree to delete");
        return;
    }
    printf("Enter the data to be deleted : ");
    scanf("%d", &data);
    t1 = root_1;
    t2 = root_1;
    search_1(root_1, data);
}

// preorder traversal 
void preorderBT(struct btnode* t)
{
    if (root_1 == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    printf("%d -> ", t->val);
    if (t->left != NULL)
        preorderBT(t->left);
    if (t->right != NULL)
        preorderBT(t->right);
}

// postorder traversal 
void postorderBT(struct btnode* t)
{
    if (root_1 == NULL)
    {
        printf("No elements in a tree to display ");
        return;
    }
    if (t->left != NULL)
        postorderBT(t->left);
    if (t->right != NULL)
        postorderBT(t->right);
    printf("%d -> ", t->val);
}

// Search for the appropriate position to insert the new node 
void search_1(struct btnode* t, int data)
{
    if ((data > t->val))
    {
        t1 = t;
        search_1(t->right, data);
    }
    else if ((data < t->val))
    {
        t1 = t;
        search_1(t->left, data);
    }
    else if ((data == t->val))
    {
        delete_1(t);
    }
}

// delete a node 
void delete_1(struct btnode* t)
{
    int k;

    // delete leaf node 
    if ((t->left == NULL) && (t->right == NULL))
    {
        if (t1->left == t)
        {
            t1->left = NULL;
        }
        else
        {
            t1->right = NULL;
        }
        t = NULL;
        free(t);
        return;
    }

    // delete node having one left hand child 
    else if ((t->right == NULL))
    {
        if (t1 == t)
        {
            root_1 = t->left;
            t1 = root_1;
        }
        else if (t1->left == t)
        {
            t1->left = t->left;

        }
        else
        {
            t1->right = t->left;
        }
        t = NULL;
        free(t);
        return;
    }

    // delete node having right hand child 
    else if (t->left == NULL)
    {
        if (t1 == t)
        {
            root_1 = t->right;
            t1 = root_1;
        }
        else if (t1->right == t)
            t1->right = t->right;
        else
            t1->left = t->right;
        t == NULL;
        free(t);
        return;
    }

    // delete node having two child 
    else if ((t->left != NULL) && (t->right != NULL))
    {
        t2 = root_1;
        if (t->right != NULL)
        {
            k = small(t->right);
            flag = 1;
        }
        else
        {
            k = large(t->left);
            flag = 2;
        }
        search_1(root_1, k);
        t->val = k;
    }

}

// find the smallest element in the right sub tree 
int small(struct btnode* t)
{
    t2 = t;
    if (t->left != NULL)
    {
        t2 = t;
        return(small(t->left));
    }
    else
        return (t->val);
}

// find the largest element in the left sub tree 
int large(struct btnode* t)
{
    if (t->right != NULL)
    {
        t2 = t;
        return(large(t->right));
    }
    else
        return(t->val);
}


*/