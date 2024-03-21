#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int info;
    int *rchild;
    int *lchild;
};

typedef struct Node *NODE;

int main()
{
    NODE root = NULL;
    int choice, data, key;

    NODE CREATE_NODE(NODE, int);
    void INORDER(NODE), POSTORDER(NODE), PREORDER(NODE);
    NODE SEARCH_NODE(NODE, int);

    while(1)
    {
        printf("\n1. CREATE NODE\n2. TRAVERSAL\n3. SEARCH NODE\n4. EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the Data to Create and Insert the Node: ");
                scanf("%d", &data);
                root = CREATE_NODE(root, data);
                break;

            case 2:
                if(root == NULL)
                {
                    printf("Tree is Empty!\n");
                
                }
                else
                {
                    printf("INORDER Display: \n");
                    INORDER(root);

                    printf("PREORDER Display: \n");
                    PREORDER(root);

                    printf("POSTORDER Display: \n");
                    POSTORDER(root);
                }
                break;

            case 3:
                printf("Enter the Key to be Searched: ");
                scanf("%d", &key);

                SEARCH_NODE(root, key);
                break;

            case 4:
                exit(0);
        }
    }
    return 0;
}

NODE CREATE_NODE(NODE root, int data)
{
    NODE newNode, x, parent;
    newNode = (NODE)malloc(sizeof(NODE));
    newNode->rchild = newNode->lchild = NULL;
    newNode->info = data;
    if(root == NULL)
    {
        root = newNode;
    }
    else
    {
        x = root;
        while(x != NULL)
        {
            parent = x;
            if(x->info < data)
                x = x->rchild;
            else if(x->info > data)
                x = x->lchild;
            else
            {
                printf("The Node is already Present!\n");
                return root;
            }
        }
        if(parent->info < data)
            parent->rchild = newNode;
        else
            parent->lchild = newNode;

    }
    return root;
}

void INORDER(NODE root)
{
    if(root != NULL)
    {
        INORDER(root->lchild);
        printf("%d", root->info);
        INORDER(root->rchild);
    }
}

void PREORDER(NODE root)
{
    if(root != NULL)
    {
        printf("%d", root->info);
        PREORDER(root->lchild);
        PREORDER(root->rchild);
    }
}

void POSTORDER(NODE root)
{
    if(root != NULL)
    {
        POSTORDER(root->lchild);
        POSTORDER(root->rchild);
        printf("%d", root->info);
    }
}

NODE SEARCH_NODE(NODE root, int key)
{
    NODE cur, parent, q, succesor;
    if(root == NULL)
    {
        printf("Tree is Empty!\n");
        return root;
    }
    cur = root;
    while(cur != NULL)
    {
        if(key == cur->info)
            break;
        parent = cur;
        cur = (key < cur->info) ? cur->lchild : cur->rchild;
    }
    if(cur == NULL)
    {
        printf("Data Not Found!!!\n");
        return root;
    }
    printf("Data %d is Found!\n", key);
}

