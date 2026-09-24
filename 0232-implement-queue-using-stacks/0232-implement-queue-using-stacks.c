typedef struct {
    int in[100];
    int out[100];
    int inTop;
    int outTop;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* q = malloc(sizeof(MyQueue));
    q->inTop = -1;
    q->outTop = -1;
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->in[++obj->inTop] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->outTop == -1) {
        while (obj->inTop >= 0)
            obj->out[++obj->outTop] = obj->in[obj->inTop--];
    }

    return obj->out[obj->outTop--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->outTop == -1) {
        while (obj->inTop >= 0)
            obj->out[++obj->outTop] = obj->in[obj->inTop--];
    }

    return obj->out[obj->outTop];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->inTop == -1 && obj->outTop == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}