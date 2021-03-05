#include<stdio.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>
# define max 8
sem_t empty;
sem_t full;
int circ_queue[max];
int front = -1;
int rear = -1;
void insertion(int item);
void deletion();
void* pd(void* pp)
{ 
   int item;
   sem_wait(&empty);
   scanf("%d",&item); //user input
   insertion(item);
   printf("\n");
   sem_post(&full);
}
void* cd(void* pp)
{
 sem_wait(&full);
  deletion();
   sem_post(&empty);
}

void insertion(int item)
{
if((front == 0 && rear == max-1) || (front == rear+1))
{
printf("Queuee  Overflow n");
return;
}
if(front == -1)
{
front = 0;
rear = 0;
}
else
{
if(rear == max-1)
rear = 0;
else
rear = rear+1;
}
circ_queue[rear] = item ;
printf("Element Produced : %d\n",item);
}

void deletion()
{
if(front == -1)
{
printf("Queue  Underflown");
return ;
}
printf("Element  Consumed : %d\n",circ_queue[front]);
if(front == rear)
{
front = -1;
rear=-1;
}
else
{
if(front == max-1)
front = 0;
else
front = front+1;
}
}


int main()
{
  int item;
   sem_init(&empty,0,max);
    sem_init(&full,0,0);
    pthread_t pro[8],con[8];
   printf("Enter  the  items  to  be  produced and consumed of buffer 8\n ");
   for(int i = 0; i < 8; i++) {
    pthread_create(&pro[i], NULL, (void *)pd, NULL);
    }
     for(int i = 0; i < 8; i++) {
        pthread_create(&con[i], NULL, (void *)cd,NULL);
    }
     for(int i = 0; i < 8; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 8; i++) {
        pthread_join(con[i], NULL);
    }
       sem_destroy(&empty);
    sem_destroy(&full);
return 0;
}
