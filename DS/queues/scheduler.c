#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

#define max 5

struct Schedule
{
    int ID;
    char title[100];
    int duration;
    char status[100];
};

struct Schedule task[10] = {
    {0, "Running", 3, "Idle"},
    {1, "Walking", 3, "Idle"},
    {2, "Cycling", 3, "Idle"},
    {3, "Hiking", 3, "Idle"},
    {4, "Laps", 3, "Idle"},
    {5, "Swimming", 3, "Idle"},
    {6, "Football", 3, "Idle"},
    {7, "Cricket", 3, "Idle"},
    {8, "Tennis", 3, "Idle"},
    {9, "Badminton", 3, "Idle"}};

int taskcount = 10;

struct Schedule queue[max];
int front = -1, rear = -1;

void enqueue(struct Schedule task)
{
    if (rear == max - 1)
    {
        printf("\nQueue is full\n");
        // calculate wait time
        int mintime = queue[front].duration, maxtime = 0;
        for (int i = front; i <= rear; i++)
        {
            maxtime += queue[i].duration;
        }
        printf("Wait time is between %d and %d seconds\n", mintime, maxtime);
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear].duration = task.duration;
        queue[rear].ID = task.ID;
        strcpy(queue[rear].title, task.title);
        strcpy(queue[rear].status, "Queued");
    }
    else
    {
        rear++;
        queue[rear].duration = task.duration;
        queue[rear].ID = task.ID;
        strcpy(queue[rear].title, task.title);
        strcpy(queue[rear].status, "Queued");
    }
}

void dequeue()
{
    if (front == -1 && rear == -1 || front == rear + 1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("Task %d is running\n", queue[front].ID);
        sleep(queue[front].duration);
        printf("Task %d is completed\n", queue[front].ID);
        front++;
        // make status completed
        for (int i = 0; i < taskcount; i++)
        {
            if (task[i].ID == queue[front - 1].ID)
            {
                strcpy(task[i].status, "Completed");
            }
        }
    }
}

int main()
{
    int choice;
    while (1)
    {

        printf("\n1. Schedule task\n");
        printf("2. Run task\n");
        printf("3. Display scheduled Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the task id of the tasks to be scheduled\n");
            printf("0.Running\n1.Walking\n2.cycling\n3.hiking\n4.Laps\n5.Swimming\n6.Football\n7.Cricket\n8.Tennis\n9.Badminton\n");
            printf("\n");
            int id;
            scanf("%d", &id);
            for (int i = 0; i < taskcount; i++)
            {
                if (task[i].ID == id)
                {
                    if (strcmp(task[i].status, "Idle") == 0)
                    {
                        enqueue(task[i]);
                        strcpy(task[i].status, "Queued");
                    }
                    else
                    {
                        printf("Task is already queued or completed\n");
                    }
                }
            }
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("\nQueued tasks are:\n");
            for (int i = front; i <= rear; i++)
            {
                printf("\nID: %d", queue[i].ID);
                printf("\tTitle: %s", queue[i].title);
                printf("\nDuration: %d", queue[i].duration);
                printf("\tStatus: %s", queue[i].status);
                printf("\n\n");
            }
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Invalid Input\n");
        }
    }
    return 0;
}