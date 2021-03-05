#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Defining  message queue strucT
struct message_buffer 
{
   long message_types;
   char msgggg[100];
} message;

int mains() 
{
   key_t my_key;
   int msg_id;
   my_key = ftok("progfile", 65);  // to create unique key
   msg_id = msgget(my_key, 0666 | IPC_CREAT);  //  creating message queue and return id
   msgrcv(msg_id, &message, sizeof(message), 1, 0);  // used to receive message
   printf("Received Message is : %s \n", message.msgggg); // display the message
    printf("Write Message : ");
   fgets(message.msgggg, 100, stdin);
   
   msgsnd(msg_id, &message, sizeof(message), 0); 
   printf("Sent message is : %s \n", message.msgggg);
   return 0;
}