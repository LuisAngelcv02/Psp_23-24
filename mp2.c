#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){

    pid_t pid_abuelo,pid_padre,pid_hijo;

    pid_abuelo=fork();

    if (pid_abuelo==0)
    {
        pid_padre=fork();

        if(pid_padre==0){
            printf("proceso p3 y mi pid es:%d\n",getpid());
            printf("Proceso p3 y mi padre es:%d\n",getppid());
        }
        else{
            pid_hijo=wait(NULL);
            printf("proceso p2 y mi pid es:%d\n",getpid());
            printf("Soy el proceso p2 y mi padres es:%d\n",getppid());
        }
        
    }
    else{
        pid_padre=wait(NULL);
        printf("proceso p1 y mi pid es:%d\n",getpid());
        printf("Soy el proceso p1 y mi hijo es:%d\n",pid_padre);
    }
}
