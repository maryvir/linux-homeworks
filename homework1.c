#include <stdio.h>
#include <stdlib.h>


struct Node 
{
    int value;
    struct Node* next;
};

struct Node* topNode = NULL;

void push(int val) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = topNode;
    topNode = newNode;
    printf("Pushed %d \n", val);
}

void pop() {
    if (topNode == NULL) 
    {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = topNode;
    printf("Popped %d \n", topNode->value);
    topNode = topNode->next;
}

int top() 
{
    if (topNode == NULL) 
    {
        printf("empty!\n");
        return -1;
    }
    return topNode->value;
}

int main() 
{
    push(1);
    push(2);
    push(3);
    printf("Top element is %d\n", top());

    pop();
    printf("Top element is %d\n", top());
    pop();
    pop();
    printf("Top element is %d\n", top());

    return 0;
}
