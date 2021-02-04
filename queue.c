//queues
#include <stdio.h>
#define SIZE 5
int items[SIZE];
int front = -1, rear = -1;
int isfull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}
int isempty() {
  if (front == -1) return 1;
  return 0;
}
void insert(int element) {
  if (isfull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}
int delete() {
  int element;
  if (isempty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}
void display() {
  int i;
  if (isempty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}
void peek()
{
    if (isempty())
      printf(" \n Empty Queue\n");
    else
      printf("%d ", items[front]);
    
}
void main()
       {
        int choice,ele,b;
        do
        {
         printf("\nEnter your choice\n");
         printf("\n1.insertQ\n2.deleteQ\n3.peek\n4.display\n5.exit\n");
         scanf("%d",&choice);
         switch(choice)
         {
          case 1:printf("Enter the element to be added\n");
                 scanf("%d",&ele);
                 insert(ele);
                 break;
          case 2:b=delete();
                 
                  break;
                 
          case 3:peek();
                 
                 break;
          case 4:display();
                 
                 break;
          case 5:break;
          default:printf("invalid choice");
          }
         }
          while(choice!=5);
        }