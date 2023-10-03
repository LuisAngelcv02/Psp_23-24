#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
    pid_t p2,p3;

    //¿Funciona igual sin el p1?
    //pid_t p1;
   // p1=getpid();

    p2=fork();

    if(p2==0){
        printf("proceso p2 pid es:%d\n",getpid());
        printf("proceso padre p2 es:%d\n",getppid());
        sleep(2);
        printf("Despierto\n");

    }
    else{
        p2=wait(NULL);
        p3=fork();
        if (p3==0)
        {
            printf("p3 pid %d\n",getpid());
            printf("proceso padre p3 es:%d\n",getppid());
        }
        else{
           
            p3=wait(NULL);
            printf("p1 %d\n",getpid());
            printf("padre p1 %d",getppid());
        }
        

    }
}