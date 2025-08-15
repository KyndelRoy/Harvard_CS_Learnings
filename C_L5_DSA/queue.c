#include <stdio.h>
#include <string.h>

#define MAX 5               // Max number of people in queue
#define MAX_NAME_LENGTH 50  // Max length for names

// Structure to hold person's details
typedef struct
{
    char name[MAX_NAME_LENGTH];      // Person's first name
    char surname[MAX_NAME_LENGTH];   // Person's surname
} Person;

// Structure for the queue
typedef struct
{
    Person people[MAX];  // Array to store people in the queue
    int front;           // Index of first element in the queue
    int rear;            // Index of last element in the queue
    int size;            // Number of elements currently in queue
} Queue;

// Initialize queue to empty state
void initQueue(Queue *q)
{
    q->front = 0;    // Start front at 0
    q->rear = -1;    // Rear is -1 when queue is empty
    q->size = 0;     // No elements in queue
}

// Check if queue is full
int isFull(Queue *q)
{
    return q->size == MAX;  // Queue is full if size equals MAX
}

// Check if queue is empty
int isEmpty(Queue *q)
{
    return q->size == 0;    // Queue is empty if size is 0
}

// Add person to the queue
void enqueue(Queue *q, Person p)
{
    if (isFull(q))
    {
        printf("Queue is full!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX; // Circular increment for rear index
    q->people[q->rear] = p;        // Store person directly in array
    q->size++;                     // Increase queue size
}

// Remove person from the queue
Person dequeue(Queue *q)
{
    Person temp = { "", "" }; // Default empty person to return if queue is empty
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return temp;
    }
    temp = q->people[q->front];      // Get the first person in the queue
    q->front = (q->front + 1) % MAX; // Move front forward (circularly)
    q->size--;                       // Decrease queue size
    return temp;                     // Return removed person
}

// Display all people in the queue
void displayQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue contents:\n");
    // Loop through the queue elements in order
    for (int i = 0; i < q->size; i++)
    {
        int index = (q->front + i) % MAX; // Calculate actual index (circular)
        printf("%s %s\n", q->people[index].name, q->people[index].surname);
    }
}

int main()
{
    Queue q;
    initQueue(&q); // Initialize the queue

    // Create some people
    Person p1 = { "John", "Doe" };
    Person p2 = { "Jane", "Smith" };
    Person p3 = { "Mike", "Brown" };

    // Add people to the queue
    enqueue(&q, p1);
    enqueue(&q, p2);
    enqueue(&q, p3);

    // Display queue contents
    displayQueue(&q);

    // Remove one person from the queue
    Person removed = dequeue(&q);
    printf("Dequeued: %s %s\n", removed.name, removed.surname);

    // Display queue contents again
    displayQueue(&q);

    return 0;
}
