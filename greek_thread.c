#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
void *myThreadFun(void *vargp)
{ 
    printf("add=%u\n",(unsigned)vargp);
    printf("value=%d\n",(int*)vargp);
    printf("Printing GeeksQuiz from Thread \n"); 
    exit(0);
    return NULL; 
} 
   
int main() 
{ 
    pthread_t thread_id; 
    printf("Before Thread\n"); 
    pthread_create(&thread_id, NULL, myThreadFun, &thread_id); 
    printf("hell0...\n");
    printf("fun_function...\n");
    //pthread_join(thread_id,NULL);
    wait(0);
  //  exit(0);
}
