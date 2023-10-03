#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main()
{
    __pid_t p1;
 printf("CCC \n");
 if (fork()==0)
 {
 printf("AAA \n");
 } else 
 printf("BBB \n");
 exit(0);
}
