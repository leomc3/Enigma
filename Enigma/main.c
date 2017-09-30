#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM_ROTOR 26
#define DESLOC1 2
#define DESLOC2 5
#define DESLOC3 7


    /*65 -> A,
     90 -> Z;
     97 -> a;
     122-> z;
    */

void exibeVet(char* aux)
{
    int i=0;
    //printf("\n");
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
        //if (i == TAM_ROTOR-1) i =0;
        vetAux[j] = vet[i%TAM_ROTOR];
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
     exibeVet(vet1);

    printf("\nRotor 2:");
     exibeVet(vet2);

    printf("\nRotor 3:");
     exibeVet(vet3);
     return;
 }



void ordemRotor(char* vet1,char* vet2,char* vet3)
{
    int i=0,j=0,random1,random2,random3;
    char* vetAux1,* vetAux2,* vetAux3;
    char* vetsort[3]; // vetor para atribuir o rotor;


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

    vet1 = vetsort[random1];
    vet2 = vetsort[random2];
    vet3 = vetsort[random3]; // ERRO AQUI.

    exibeRotores(vet1,vet2,vet3);

    return;
}

int tamMsg(char *msg)
{
   int i;
   for (i = 0; msg[i] != '\0'; ++i) ;
   return i;
}

int posVet(char* vet, char letra)
{
    int i = 0;
    while (vet[i] != letra)
        i++;
    printf("%d",i);
    return i;
}

char* geraCifraRotor()
{
	char letraAux;
	int i;
	int troca;

	char* vetCifra =  (char*)malloc(sizeof(char)*TAM_ROTOR);
	for(i=0; i< 26; i++)      // cria sequencia de a - z
	{
		vetCifra[i] = 97+i;   //97 o decimal ASCII de "a", indo até 97+25
	}



    printf("\n\n");
	for(i=0; i< 26; i++)      //embaralha a sequencia anterior
	{
		troca = rand()%26;
		letraAux = vetCifra[i];
		vetCifra[i] = vetCifra[troca];
		vetCifra[troca] = letraAux;
	}

	return vetCifra;
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
    printf("\nVetora:");
    exibeVet(vetA);
    printf("\nVetorA:");
    exibeVet(veta);

    rot1 = criaRotor(veta, DESLOC1);
    rot2 = criaRotor(veta, DESLOC2);
    rot3 = criaRotor(veta, DESLOC3);
    printf("\nRotor1:");
    exibeVet(rot1);
    printf("\nRotor2:");
    exibeVet(rot2);
    printf("\nRotor3:");
    exibeVet(rot3);

    rot1 = deslocaRotor(rot1, 1);
    printf("\nRotor1:");
    exibeVet(rot1);
    printf("\ -> Deslocado 1 posicao.(ok)");



    ordemRotor(rot1,rot2,rot3);



    char letra = 'd';
    int posicao = posVet(veta,letra);
    printf("\npos = %d\n",posicao);


    //teste
    char* msg = (char*)malloc(sizeof(char)*10);
    msg = 'Oi';
    int tama;
    tama = tamMsg(&msg);
    printf("\ntamanho msg = %d\n",tama);

    char* SubstituicaoRotor1 =  (char)malloc(sizeof(char)*TAM_ROTOR);
    char* SubstituicaoRotor2 =  (char)malloc(sizeof(char)*TAM_ROTOR);
    char* SubstituicaoRotor3 =  (char)malloc(sizeof(char)*TAM_ROTOR);

    SubstituicaoRotor1 = geraCifraRotor();
    SubstituicaoRotor2 = geraCifraRotor();
    SubstituicaoRotor3 = geraCifraRotor();


    exibeRotores(SubstituicaoRotor1,SubstituicaoRotor2,SubstituicaoRotor3);
    getchar();
    char msg_teste = 'n';

    char* msg_cifrada = cifradorEnigma(msg_teste, rot1,rot2,rot3);
    exibeVet(msg_cifrada);
    getchar();
    return 0;
}

char* cifradorEnigma(char* msg_clara, char* rot1,char* rot2,char* rot3)
{
    int i =0,j=0,k=0;
    char* msg_cifrada;
    msg_cifrada = (char)malloc(sizeof(char)*tamMsg(msg_clara))
    while(msg_teste[i] != '\0')
    {
        i = (i%TAM_ROTOR)
            deslocaRotor(rot1,1);
        if (i == 25)
        {
            deslocaRotor(rot2,1);
            j = (j%26);
        }
        if(j == 25)
            deslocaRotor(rot3,1);

    msg_cifrada[k] = encontraCrifra(msg_cifrada[k])

    }

    return msg_cifrada;


}


int encontraCrifra(char* rot1,char* rot2,char* rot3,char* SubstituicaoRotor1,char* SubstituicaoRotor2,char* SubstituicaoRotor3, int vezes)
{

}
