#include <stdio.h>
#include <stdlib.h>

int main(){
    int a=0, b=0, c=0, d=0;
    int *pa = &a, *pb = &b, *pc = &c, *pd = &d;

    printf("Digite quatro valores (separados por espaco): ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    printf("Os valores foram armazenados. Valor atual dos ponteiros: ");
    printf("%d %d %d %d\n", (*pa), (*pb), (*pc), (*pd));
    
    printf("Digite quatro novos valores (separados por espaco): ");
    //registrando novos valores na memoria
    scanf("%d %d %d %d", pa, pb, pc, pd);

    printf("Os valores dos ponteiros foram modificados. Valor atual das variaveis inteiras: ");
    printf("%d %d %d %d\n", a, b, c, d);

    return 0;
}