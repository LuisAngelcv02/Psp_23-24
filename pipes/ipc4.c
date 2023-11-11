#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>

int main(){
    int fd1[2];
    int fd2[2];
    int numero;
    int resultado=1;
    pid_t pid;

    pipe(fd1);
    pipe(fd2);

    pid=fork();

    if(pid==0){
        close(fd1[1]);
        read(fd1[0],&numero,sizeof(numero));
        printf("numero aleatorio recibido de padres es :%d\n",numero);
        
        for (int i = 1; i <=numero; i++)
        {
            resultado *=i;
        }
        close(fd2[0]);
        write(fd2[1],&resultado,sizeof(resultado));

    }
    else{

        close(fd1[0]);
        srand(time(NULL));
         numero = rand()%11;
         write(fd1[1],&numero,sizeof(numero));

         close(fd2[1]);
         read(fd2[0],&resultado,sizeof(resultado));
         printf("el factorial de %d es: %d\n",numero,resultado);
    }
}
