#include<stdio.h>
#include<pthread.h>
void *thread1(void *p)
{
   printf("in thread1..\n");
   printf("str=%s\n",(char*)p);
//   while(1);
   printf("self-->%u\n",pthread_self());
   return NULL;
}
void *thread2(void *ptr)
{
   printf("in thread2..\n");
   printf("str1=%s\n",(char*)ptr);
//   while(1);
   return NULL;
}

int main()
{
  pthread_t t1,t2;
  pthread_create(&t1,0,thread1,"hello_world111");
  pthread_create(&t2,0,thread2,"hello_world222");
  printf("thread1 id=%u\n",(unsigned)&t1);
  printf("thread2 id=%u\n",(unsigned)&t2);
  //while(1);
// pthread_exit(NULL);
  pthread_join(t1,0);
  pthread_join(t2,0);
}
