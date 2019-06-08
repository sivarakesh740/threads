#include<stdio.h>
#include<pthread.h>

void *thread1(void *ptr)
{
  printf("hello..\n");
  printf("val=%d\n",(int*)ptr);
  printf("add=%u\n",(unsigned)ptr);
  return NULL;
}

int main()
{
  pthread_t t1;
  pthread_create(&t1,0,thread1,(void*)&t1);
  printf("thread id=%d\n",t1);
  pthread_exit(NULL); 
 //pthread_join(t1,NULL);
}
