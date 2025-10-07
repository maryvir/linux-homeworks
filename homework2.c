#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* next;
};

struct Node* first = NULL;
struct Node* last = NULL;

void enqueue(int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = NULL;

    if (last == NULL)
    {
        first = last = newNode;
    }
    else
    {
        last->next = newNode;
        last = newNode; 
    }

    printf("Enqueued %d\n", val);
}

void dequeue()
{
    if (first == NULL)
    {
        printf("empty\n");
        return;
    }

    struct Node* temp = first;
    printf("Dequeued %d\n", first->value);
    first = first->next;

    if (first == NULL)
        last = NULL;

    free(temp);
}

int firstNode()
{
    if (first == NULL)
    {
        printf("empty\n");
        return -1;
    }
    return first->value;
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("First element is %d\n", firstNode());

    dequeue();
    printf("First element is %d\n", firstNode());

    return 0;
}
