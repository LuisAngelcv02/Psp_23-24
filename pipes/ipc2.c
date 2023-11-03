#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

int main() {
    int pipe_fd[2];
    pid_t pid;
    char numeros[4];
    
    pipe(pipe_fd);
    pid = fork();

    if (pid == 0) {
        // Proceso hijo
        
        close(pipe_fd[1]); // Cerramos el extremo de escritura del pipe en el proceso hijo

        char num[4];
        char signo[2];
        int sum = 0;
        int count = 0;

        while (signo[0]!= '+') {//Con esta linea me resulta mas facil comprender

            
            //con estas lineas tambien funciona pero no llego a entender como funciona
            /*if (read(pipe_fd[0], &num, sizeof(int)) != sizeof(int)) {
                break; // Salir del bucle cuando no se puede leer un número completo
            }*/
            read(pipe_fd[0],num,sizeof(char));
            read(pipe_fd[0],signo,sizeof(char));
           
            //printf("%s",num);
            sum+=atoi(num);
                 
                 //sum += num;
   
            
        }
        printf("suma %d",sum);
        close(pipe_fd[0]); // Cerramos el extremo de lectura del pipe en el proceso hijo
    } 
    
    else {
        // Proceso padre
        close(pipe_fd[0]); // Cerramos el extremo de lectura del pipe en el proceso padre
        
       char sign[2];
        for (int i = 0; i < 4; i++)
        {
        printf("ingresa el numero:\n");
        scanf("%s",&numeros[i]);
        write(pipe_fd[1],&numeros[i], sizeof(int));
        }

        printf("ingresa el numero:\n");
        scanf("%s",sign);
        write(pipe_fd[1],sign, sizeof(char));

        close(pipe_fd[1]); // Cerramos el extremo de escritura del pipe en el proceso padre
        wait(NULL);
    }
    
}