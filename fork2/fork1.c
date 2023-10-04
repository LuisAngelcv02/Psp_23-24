#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
    pid_t pid1,pid2,pid3,pid4;
    int status;

    pid1=fork();

    if (pid1==0)
    {
        pid3=fork();

        if (pid3==0)
        {
            pid4=fork();

            if(pid4==0){
            printf("Proceso p4 %d\n",getpid());
                
            }
            
            else{
            waitpid(pid4,&status,0);
            printf("Proceso p3 %d\n",getpid());
            }
        }
        
    }

    else{
        //pid3=wait(NULL);
        //pid1=wait(NULL);
       
   //waitpid(pid1,&status,0);
   waitpid(pid3,&status,0);
   pid2=fork();
        if(pid2==0){
            printf("Proceso p2 %d\n",getpid());
        }
        else{
            waitpid(pid2,&status,0);
            
            printf("Proceso p1 %d\n",getpid());
        }
    
    }
    
}
