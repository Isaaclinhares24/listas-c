////////////////////////////////////
//programa que implementa um deque//
////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
///////////////////////////
//declaracao estrutura no//
///////////////////////////

struct no
{
    int numero;
    struct no *proximo;
};

struct deque
{
    struct no *filaNormal;
    struct no *filaPreferencial;

};

////////////////////////////////
//funcao que insere no na fila//
////////////////////////////////

struct deque *entrar(struct deque *cabeca, int numero , bool tipo)
{
    //alocacao de memoria novo no
    struct no *novoNo = (struct no *) malloc (sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximo = NULL;

    if(tipo)
    {
        //verdadeiro para fila normal
        novoNo -> proximo = cabeca ->filaNormal;
        cabeca -> filaNormal = novoNo;

    }
    else
    {
        //falso fila preferencial
        novoNo -> proximo = cabeca ->filaPreferencial;
        cabeca -> filaPreferencial =novoNo;
    }

    return cabeca;
};

///////////////////////////////////
//funcao que remove um no da fila//
///////////////////////////////////

struct no *sair(struct no *fila)
{
    //Cenario muito facil(fila vazia)
    if (fila==NULL)
    {

         return NULL;
    }
    //cenarui medio facil(so tem 1 no)
    if (fila->proximo== NULL)
    {
        printf("%d\n",fila ->numero);
        free(fila);
        return NULL;
    }
    //Cenario dificil(fila tem mais de 1 no procurar ultimo)
    struct no *penultimo = fila;
    while (penultimo -> proximo ->proximo !=NULL)
    {
        penultimo = penultimo ->proximo;
    }
    struct no *excluir = penultimo -> proximo;
    printf("%d\n" , excluir -> numero);
    free(excluir);
    penultimo -> proximo =NULL;
    return fila;
}

/////////////////////////////////////
//funcao que realiza o atendimento //
/////////////////////////////////////

void atender(struct deque *cabeca ,int *contadorPreferencial)
{
    //cenario muito facil (ambas vazia)
    if((cabeca -> filaNormal ==NULL)&&
       (cabeca -> filaPreferencial == NULL))
    {
        printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠘⠹⣶⣿⠷⢃⡆⠻⢈⣿⣿\n");
        printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣀⣴⣿⠿⣫⣾⢈⣸⣷⠹⣿\n");
        printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⣀⣤⣶⣾⣿⣿⣿⣷⣶⣶⣬⡩⣵⣿⣿⣿⡘⢹⣿⢠⣄\n");
        printf("⠄⠄⠄⠄⠄⠄⠄⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⢻⣿⣿⣞⡄⢿⣜⣿\n");
        printf("⠄⠄⠄⠄⠄⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⣿⣿⣋⠄⠙⠉⠛\n");
        printf("⠄⠄⠄⠄⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣷⠇⠄⠄⠄⠄\n");
        printf("⠄⠄⠄⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠄⣿⡄⠄⠄⠄⠄\n");
        printf("⡀⠄⠄⢠⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠄⠄⠘⠇⠄⠄⠄⠄\n");
        printf("⣶⣾⣿⣷⡹⣿⣿⣿⣎⢿⣿⣿⣿⣿⣿⣿⣿⡿⠿⣛⣵⣿⣷⣶⣤⡀⠄⠄⠄⠄\n");
        printf("⣿⣿⣿⣿⣿⣮⣿⡿⠿⣛⣢⢩⣭⣭⣭⣭⣶⣿⣿⣿⣿⣿⣿⣿⣿⣷⠄⠄⠄⠄\n");
        printf("⣿⣿⣿⠿⣫⣾⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠄⠄⠄⠄\n");
        printf("⠿⢟⣭⣾⣿⣿⣿⣿⣿⣿⣿⣮⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠄⠄⠄⠄\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢛⣁⣀⣀⣀⣀⣀\n");

    }

    //cenario medio facil (so tem na fila normal)

    if (cabeca ->filaPreferencial == NULL)
    {
        cabeca -> filaNormal=sair(cabeca -> filaNormal);

    }
    //cenario dificil
    if(*contadorPreferencial >4)
    {
        cabeca -> filaNormal =sair (cabeca ->filaNormal);
        *contadorPreferencial =0;

    }
    else
    {
        cabeca ->filaPreferencial = sair (cabeca -> filaPreferencial);
        (*contadorPreferencial)++;
    }
}

////////////////////
//funcao principal//
////////////////////

int main()
{
    //declaracao de variavel
    int i = 0;
    int contadorPreferencial = 0;
    struct deque *cabeca = (struct deque *) malloc(sizeof(struct deque));
    cabeca ->filaNormal = NULL;
    cabeca -> filaPreferencial= NULL;

    //inicializar aleatorio
    time_t t;
    srand(time(&t));

    //precessar
    for (i=0;i<100;i++)
    {
        cabeca = entrar(cabeca,i,(rand() %2 ));

    }
     for (i=0;i<100;i++)
     {
         atender(cabeca, &contadorPreferencial);
     }
}
