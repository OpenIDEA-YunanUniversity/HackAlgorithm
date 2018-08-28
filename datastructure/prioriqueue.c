
#include <stdio.h>
#include <stdlib.h>

// Node
typedef struct node {
    int data;
    int priority;

    struct node* next;

} Node;

Node* newNode(int d, int p)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

// Return the value at head
int peek(Node** head)
{
    return (*head)->data;
}

// Removes the element with the
// highest priority form the list
void pop(Node** head)
{
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

// Function to push according to priority
void push(Node** head, int d, int p)
{
    Node* start = (*head);
    Node* temp = newNode(d, p);
    if ((*head)->priority < p) {

        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;
    }
    else {
        while (start->next != NULL &&
               start->next->priority > p) {
            start = start->next;
        }

        temp->next = start->next;
        start->next = temp;
    }
}

int isEmpty(Node** head)
{
    return (*head) == NULL;
}


int main()
{

    int n;
    int i=0, pri, val;

    printf("请输入病人数量：");
    scanf("%d", &n);
    printf("请输入病人id和病重等级(等级递增)(整型):");
    scanf("%d %d",&val,&pri);
    Node* pq = newNode(val,pri);


    for(i=1;i<n;i++){
        printf("请输入病人id和病重等级(等级递增)(整型):");
        scanf("%d %d",&val,&pri);
        push(&pq, val, pri);

    }


    while (!isEmpty(&pq)) {
        printf("%d ", peek(&pq));
        pop(&pq);
    }

    return 0;
}
