#include "sig.h"

void childprocess()
{ 
    int pid; 
  
    // to get child process 
    
    if ((pid = fork()) < 0) { 
        perror("fork"); 
        exit(1); 
    } 
  
    if (pid == 0) {    // child process
        signal(SIGHUP, sighup); 
        signal(SIGINT, sigint); 
        signal(SIGQUIT, sigquit); 
        for (;;) 
            ; 
        // loop for ever
    } 
  
    else // for parent
    { // pid id of child
        printf("\nPARENT: sending SIGHUP\n\n"); 
        kill(pid, SIGHUP); 
  
        sleep(3); //pause for 3 secs 
        printf("\nPARENT: sending SIGINT\n\n"); 
        kill(pid, SIGINT); 
  
        sleep(3);                   //pause for 3 secs 
        printf("\nPARENT: sending SIGQUIT\n\n"); 
        kill(pid, SIGQUIT); 
        sleep(3); 
    } 
} 

void sighup()   
{ 
    signal(SIGHUP, sighup);      // to reset signal 
    printf("CHILD: I have received  a  SIGHUP\n"); 
} 

void sigint() 
  
{ 
    signal(SIGINT, sigint); // to reset signal 
    printf("CHILD: I have received  a SIGINT\n"); 
} 
  
void sigquit() 
{ 
    printf("My PARENNT has Killed me!!!!\n"); 
    exit(0); 
} 
