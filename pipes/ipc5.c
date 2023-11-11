#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 


int main(){

    int fd1[2];
    int fd2[2];
     int dni;
     char letraFinal;
    pid_t pid;

    pipe(fd1);
    pipe(fd2);

    pid=fork();

   if(pid==0){
        close(fd1[0]);
          printf("ingresa los numeros de tu dni:\n");
          scanf("%d",&dni);
          write(fd1[1],&dni,sizeof(dni));
          

          close(fd2[1]);
          read(fd2[0],&letraFinal,sizeof(char));
          printf("%c\n",letraFinal);

   }

   else{
     //me daba problemas al poner el wait ya que se queda esperando todo el rato
     
    //wait(NULL);
    close(fd1[1]);
    read(fd1[0],&dni,sizeof(dni));
    char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    int indice= dni % 23;
     
     char letraFinal=letra[indice];
    

     close(fd2[0]);
     write(fd2[1],&letraFinal,sizeof(char));
     
   }
