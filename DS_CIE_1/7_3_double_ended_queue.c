#include <stdio.h>
#define size 20

int rear = -1;
int front = -1;
int queue_array[size];

void insertFront(int value) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Queue Overflow!!!\n");
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front = front - 1;
        }
        queue_array[front] = value;
        printf("Value %d inserted at front!\n", value);
    }
}

void insertRear(int value) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Queue Overflow!!!\n");
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }
        queue_array[rear] = value;
        printf("Value %d inserted at rear!\n", value);
    }
}

void deleteFront() {
    if (front == -1) {
        printf("Queue Underflow!!!\n");
    } else {
        printf("The deleted element from front is %d\n", queue_array[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Queue Underflow!!!\n");
    } else {
        printf("The deleted element from rear is %d\n", queue_array[rear]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear = rear - 1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Empty Queue!!!\n");
    } else {
        printf("The elements in the queue are: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue_array[i]);
            i = (i + 1) % size;
        }
        printf("%d\n", queue_array[rear]);
    }
}

int main() {
    int run = 1, n, value;
    while (run) {
        printf("Enter the requirement:\n1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display\n6. Exit\n");
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("Enter the value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter the value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                run = 0;
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    }
    printf("Exited the program!\n");
    return 0;
}
