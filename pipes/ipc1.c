#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

void main(){
    int fd[2];
    char buffer[30];
    pid_t pid;
    char hola[30];

    pipe (fd);

    pid=fork();

    if(pid==0){

        close(fd[1]);
        read(fd[0],hola,20);
        printf("%s",hola);

    }
    else{
        close(fd[0]);
        write(fd[1], "hola asd" ,9);
        wait(NULL);
    }
}
