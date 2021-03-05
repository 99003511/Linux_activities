/* 4.  To implement a simple client-server scenario using message queues
   * Client process send a string over message queue
   * Server process toggles the string and send back to client.*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// struct for message queue

struct msg_buffer 
{
   long message_types;
   char msgggg[100];
} message;

int main() 
{
   key_t my_key;
   int msg_id;
   my_key = ftok("progfile", 65);  // to create unique key
   msg_id = msgget(my_key, 0666 | IPC_CREAT);  // creating message queue and return id
   message.message_types = 1;
   printf("Write Message  :  ");
   fgets(message.msgggg, 100, stdin);
   printf("Sent message is : %s \n", message.msgggg);
   msgsnd(msg_id, &message, sizeof(message), 0);  // sending  message
   msgrcv(msg_id, &message, sizeof(message), 1, 0);  // used to receive message
   printf("Received Message is : %s \n", message.msgggg); // to display the messag
   return 0;
}