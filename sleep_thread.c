#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *thread1(void *p)
{
   printf("in thread1..\n");
   sleep(10);
   printf("thread exit1...\n");
   pthread_exit("thread 2 bye bye\n");
}

void *thread2(void *p)
{
   printf("in thread2..\n");
   sleep(5);
   printf("thread exit2...\n");
}

int main()
{ 
  char *p;
  pthread_t t1,t2;
  pthread_create(&t1,0,thread1,0);
  pthread_create(&t2,0,thread2,0);
  pthread_join(t1,&p);
  printf("str=%s\n",p);
}
