#include <stdio.h>
#include <stdlib.h>

#define TAM_ROTOR 26
#define DESLOC1 22
#define DESLOC2 7
#define DESLOC3 18


    /*65 -> A,
     90 -> Z;
     97 -> a;
     122-> z;
    */

void exiveVet(char* aux)
{
    int i=0;
    printf("\n");
     for(i=0;i<TAM_ROTOR;i++)
        printf("%c",aux[i]);
    return;
}
char* criaRotor(char* vet,int desloc)
{
    int i,j=0;
    char* vetAux;
    vetAux =  (char*)malloc(sizeof(char)*TAM_ROTOR);
    for(i=desloc;j<25;i++) // deu ruim no mod, fiz com if mesmo
    {
        if (i == TAM_ROTOR) i =0;
        vetAux[j] = vet[i];
        j++;
    }
    return vetAux;
}
int main()
{
    char *vetA,*veta, *rot1,*rot2,*rot3;
    vetA =  (char*)malloc(sizeof(char)*TAM_ROTOR);
    veta =  (char*)malloc(sizeof(char)*TAM_ROTOR);
    int i = 0, tam=25, iniA=65, inia = 97;

    //cria ambiente do alfabeto

    for(i=0; i<TAM_ROTOR; i++)
        vetA[i] = iniA+i;
    for(i=0; i<TAM_ROTOR; i++)
        veta[i] = inia+i;
    //exibe
    printf("\nVetor letras maiusculas:");
    exiveVet(vetA);
    printf("\nVetor letras minusculas:");
    exiveVet(veta);

    rot1 = criaRotor(veta, DESLOC1);
    rot2 = criaRotor(veta, DESLOC2);
    rot3 = criaRotor(veta, DESLOC3);
    printf("\nRotor1:");
    exiveVet(rot1);
    printf("\nRotor2:");
    exiveVet(rot2);
    printf("\nRotor3:");
    exiveVet(rot3);

    getchar();
    return 0;
}
