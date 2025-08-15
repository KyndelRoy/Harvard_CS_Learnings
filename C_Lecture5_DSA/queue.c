#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_QUEUE_SIZE 100

typedef struct 
{
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
} Person;

typedef struct 
{
    Person people[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// Function prototypes
void initialize_queue(Queue *queue);
void enqueue(Queue *q, const char *name, const char *surname);

void main(void)
{
    Queue queue = { .size = 0 };
}

void initialize_queue(Queue *queue)
{
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;    
}

void enqueue(Queue *q, const char *name, const char *surname)
{
    if (q->size >= MAX_QUEUE_SIZE) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (q->front == MAX_QUEUE_SIZE - 1) {
        q->front = 0; // Wrap around if front reaches the end
    }

    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // Circular increment
    strncpy(q->people[q->rear].name, name, MAX_NAME_LENGTH - 1);
    q->people[q->rear].name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination

    strncpy(q->people[q->rear].surname, surname, MAX_NAME_LENGTH - 1);
    q->people[q->rear].surname[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination

    q->size++;
    printf("Enqueued: %s %s\n",name, surname);
}

void dequeue(Queue *queue)
{

}
