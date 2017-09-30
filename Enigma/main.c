#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    for(i=desloc;j<TAM_ROTOR;i++) // deu ruim no mod, fiz com if mesmo
    {
        if (i == TAM_ROTOR-1) i =0;
        vetAux[j] = vet[i];
        j++;
    }
    return vetAux;
}


char* deslocaRotor(char* vet,int desloc)
{
    int i,j=0;
    char* vetAux;
    vetAux =  (char*)malloc(sizeof(char)*TAM_ROTOR);
    for(i=desloc;j<TAM_ROTOR;i++) // deu ruim no mod, fiz com if mesmo
    {
        if (i == TAM_ROTOR) i =0;
        vetAux[j] = vet[i];
        j++;
    }
    return vetAux;
}


 void exibeRotores(char* vet1,char* vet2,char* vet3)
 {

    printf("\nRotor 1:");
     exiveVet(vet1);

    printf("\nRotor 2:");
     exiveVet(vet2);

    printf("\n Rotor 3:");
     exiveVet(vet3);
     return;
 }



void* ordemRotor(char* vet1,char* vet2,char* vet3)
{
    int i=0,j=0,random1,random2,random3;
    char* vetAux1,* vetAux2,* vetAux3;
    char* vetsort[2]; // vetor para atribuir o rotor;

    vetsort[0]  =  (char*)malloc(sizeof(char)*TAM_ROTOR);
    vetsort[1]  =  (char*)malloc(sizeof(char)*TAM_ROTOR);
    vetsort[2]  =  (char*)malloc(sizeof(char)*TAM_ROTOR);

    vetsort[0]=vet1;
    vetsort[1]=vet2;
    vetsort[2]=vet3;

    do{
    random1 = rand()%3;
    random2 = rand()%3;
    random3 = rand()%3;
    }while( (random1 == random2 ) || (random1 == random3) || (random2 == random3) );

    printf("\n%d",random1);
    printf("\n%d",random2);
    printf("\n%d",random3);
    vet1 = vetsort[0];
    vet2 = vetsort[1];
    vet3 = vetsort[2]; // ERRO AQUI.

    exibeRotores(vet1,vet2,vet3);

    getchar();
    return;
}




int main()
{

    srand(time(NULL));
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

    rot1 = deslocaRotor(rot1, 1);
    printf("\nRotor1:");
    exiveVet(rot1);


    ordemRotor(rot1,rot2,rot3);


    getchar();
    return 0;
}
