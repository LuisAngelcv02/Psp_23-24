#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){

    pid_t pid;

    pid=fork();

    if (pid==0)
    {
        printf("Mi nombre es Angel Cordova Vasquez\n");
        printf("Soy el proceso hijo y mi pid es:%d\n",getpid());
    }
    
    else{
        pid=wait(NULL);

        printf("El Pid de mi hijo es:%d\n",pid);
        printf("Soy el proceso padre y mi pid es:%d\n",getpid());
    }

}