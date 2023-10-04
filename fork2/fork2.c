#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){

    pid_t pid1,pid2,pid3;

    pid1=fork();

    if (pid1==0)
    {
        pid2=fork();

        if(pid2==0){
            pid3=fork();

            if (pid3==0)
            {
                printf("pid4 %d\n",getpid());
                printf("soy pid4 mi padre es p3:%d\n",getppid());
                int suma=getpid()+getppid();

                printf("La suma del hijo y el padre es:%d\n",suma);
            }

            else{
                pid3=wait(NULL);
                int suma=getpid()+getppid();
                printf("pid3 %d\n",getpid());
                printf("soy pid3 mi padre es p2:%d\n",getppid());
                printf("La suma del hijo y el padre es:%d\n",suma);
            }
            
        }
        else{
            pid2=wait(NULL);
            int suma=getpid()+getppid();
            printf("pid2 %d\n",getpid());
            printf("soy pid2 mi padre es p1:%d\n",getppid());
            printf("La suma del hijo y el padre es:%d\n",suma);
        }
    }
    else{
        pid1=wait(NULL);
        printf("pid1 %d\n",getpid());
    }
    

}
