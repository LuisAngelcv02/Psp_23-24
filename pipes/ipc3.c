#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>

int main(){
    int fd[2];
    pid_t pid;
    int numero;
    int numero2;

    pipe(fd);
    pid=fork();

    if(pid==0){
        close(fd[0]);
        srand(time(NULL));
        //Esto deberia de inicializar la "semilla" para generar el num aleatorio
        
            
            numero= rand()%50 +1;
            numero2= rand()%50 +1;
            write(fd[1],&numero,sizeof(numero));
            write(fd[1],&numero2,sizeof(numero2));
        


    }
    else{
        close(fd[1]);
        
        read(fd[0],&numero,sizeof(numero2));
        read(fd[0],&numero2,sizeof(numero2));
        printf("numero aleatorio %d\n",numero);
        printf("numero aleatorio %d\n",numero2);

        int suma= numero+numero2;
        int resta = numero-numero2;
        int multi= numero*numero2;
        int division= numero/numero2;

        printf("%d + %d = %d \n",numero,numero2,suma);
        printf("%d - %d = %d \n",numero,numero2,resta);
        printf("%d * %d = %d \n",numero,numero2,multi);
        printf("%d / %d = %d \n",numero,numero2,division);
    }
}