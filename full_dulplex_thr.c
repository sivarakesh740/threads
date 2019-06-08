#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<string.h>

void *thread1(void *p)
{
  int fd;
  char a[20];
  printf("thread1=%u\n",(unsigned)p);
  fd=open("f1",O_RDWR);
  while(1)
  {  
   scanf("%s",a);
   write(fd,a,strlen(a)+1);
  // pthread_exit("write_the_data_from_file"); 
  }
}
void *thread2(void *p)
{
  int fd;
  char a[20];
  printf("thread2=%u\n",(unsigned)p);
  fd=open("f1",O_RDWR);
  while(1)
  {  
   read(fd,a,sizeof(a));
   printf("%s\n",a);
   pthread_exit("read_the_data_from_file"); 
  }
}
int main()
{
  char *p1,*p2;
  pthread_t t1,t2;
  
  mkfifo("f1",0664);
  mkfifo("f1",0664);
  
  pthread_create(&t1,0,thread1,0);
  pthread_create(&t2,0,thread2,0);
  
//  pthread_join(t1,&p1);
  pthread_join(t2,&p2);
  
 // printf("write_str=%s\n",p1);
  printf("read_str=%s\n",p2);
}

