#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
    pid_t pid1,pid2,pid3;
    int status;
    pid4=getpid();
    pid1=fork();

    if (pid1==0)
    {
        if(getpid()%2==0){
        printf("p2 %d\n",getpid());
        printf("padre p2 es p1: %d\n",getppid());
        }
        else{
            printf("p2 %d\n",getpid());
        }
        
    }

    else{
        
       // printf("p1 %d\n",getpid());
        //printf("hijo de p1 es p2 %d\n",pid1)
        
        pid2=fork();
        if(pid2==0)
        {
            pid3=fork();
            if(pid3==0){
                if(getpid()%2==0){
                    printf("proceso p4 %d\n",getpid());
                    printf("padre p4 es p3 %d\n",getppid());
                }
                else{
                    printf("proceso p4 %d\n",getpid());
                }
                
            }
            else{
                //pid3=wait(NULL);
                waitpid(pid3,&status,0);
                if(pid3%2!=0){
                printf("proceso p3 %d\n",getpid());
                printf("proceso padre p3 es p2: %d\n",getppid());
                
                }
                else{
                    printf("proceso p3 %d\n",getpid());
            }
            
        }
        }
        else{
            pid1=wait(NULL);
            pid3=wait(NULL);
            //waitpid(pid1,&status,0);
            //waitpid(pid2,&status,0);
            
            if(getpid()%2==0){
                printf("p1%d\n",getpid());
                printf("p1 padre es %d\n",getppid());
            }
            else{
                printf("p1%d\n",getpid());
            }

        }
        
        
    }
    
}
