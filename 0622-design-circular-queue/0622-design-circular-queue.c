typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* q = malloc(sizeof(MyCircularQueue));
    q->arr = malloc(k * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = k;
    return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* q, int value) {
    if (q->size == q->capacity)
        return false;

    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = value;
    q->size++;

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* q) {
    if (q->size == 0)
        return false;

    q->front = (q->front + 1) % q->capacity;
    q->size--;

    return true;
}

int myCircularQueueFront(MyCircularQueue* q) {
    if (q->size == 0)
        return -1;

    return q->arr[q->front];
}

int myCircularQueueRear(MyCircularQueue* q) {
    if (q->size == 0)
        return -1;

    return q->arr[q->rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* q) {
    return q->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* q) {
    return q->size == q->capacity;
}

void myCircularQueueFree(MyCircularQueue* q) {
    free(q->arr);
    free(q);
}