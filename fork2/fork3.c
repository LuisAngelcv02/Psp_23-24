#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){

    pid_t pid1,pid2,pid3,pid4,pid5;
    int status;

    pid1=fork();

    if(pid1==0){
        //Aqui se divide y el es proceso hijo de p1 es decir p2
        pid2=fork();
        if(pid2==0){
            //Aqui entrariamos en el proceso p3 hijo de p2
            pid3=fork();
            if (pid3==0)
            {
                //Aqui estariamos en el proceso p5 es decir hijo de p3
                     printf("Soy p5 mi pid es:%d\n",getpid());
                     printf("Soy p5 mi proceso padre es:%d\n",getppid());
                     
            }
            else{
                //Aqui estamos en el proceso p3 que es hijo de p2
                pid3=wait(NULL);
                
                printf("Soy p3 mi pid es:%d\n",getpid());
                printf("Soy p3 mi padre es:%d\n",getppid());
            }
            
        }
        else{
            pid2=wait(NULL);
            //Aqui estariamos en el p2 que es padre de p3
            pid4=fork();
            if(pid4==0){
                //Aqui estamos en el proceso p4 hijo de p2
                pid5=fork();
                if(pid5==0){
                    //Aqui estamos en el proceso p6 hijo de p4
                    printf("Soy p6 mi pid es:%d\n",getpid());
                    printf("Soy p6 mi proceso padre es:%d\n",getppid());
                }
                else{
                    //Aqui estamos en el proceso p4 hijo de p2
                    pid5=wait(NULL);
                     printf("Soy p4 mi pid es:%d\n",getpid());
                     printf("Soy p4 mi proceso padre es:%d\n",getppid());
                }
            }
            else{
                //Aqui estamos en el proceso de p2 hijo de p1
                
                pid4=wait(NULL);
                printf("Soy p2 mi pid es:%d\n",getpid());
                printf("Soy p2 mi proceso padre es:%d\n",getppid());
            }

        }
    }
    else{
        pid1=wait(NULL);
        //Aqui esta el proceso padre es decir p1
        printf("Soy el proceso p1 mi pid %d\n",getpid());
    }
}
