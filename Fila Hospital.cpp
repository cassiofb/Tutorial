#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 20

// Estrutura Heap

typedef struct Heap{
int id;
int prioridade[MAX+1];
int quant;
} Heap;

Heap * novoHeap(){
    Heap *novo = (Heap *)malloc(sizeof(Heap));
    novo->quant = 0;
    novo->id = 0;
    return novo;
}

// Funcoes Main

void msg(){
  printf("Bem vindo ao hospital /n/n");
  printf("Digite a opcao desejada de 1 a 3 ou 0 para sair: ");
}

void impressao(Heap *h){
	for(int i = 0; i <= h->quant; i++){
	  printf("%d", h->prioridade[i]);
	}
	printf("\n");
}

// Funcoes Heap

void troca(Heap *h, int pos1, int pos2){
    int aux = h->prioridade[pos1];
    h->prioridade[pos1] = h->prioridade[pos2];
    h->prioridade[pos2] = aux;
}

void subir(Heap *h, int pos){
    if (pos>1 && h->prioridade[pos] > h->prioridade[pos/2]){
        troca(h, pos, pos/2);
        pos = pos/2;
    }
}

void descer(Heap *h, int pos){
	int menor;



	if(h->quant >= (2*pos) && h->quant >= ((2*pos)+1));
}

void insercao(Heap *h, char p, int id){
  int aux = (p - 26);

 h->prioridade[++h->quant] = aux;
 h->id = id;

 subir(h, aux);
 impressao(h);
 system("pause");
}

void exclusao(Heap *h){
	if(h->quant > 0){
          if(h->quant > 1){
            h->prioridade[1]=h->prioridade[h->quant--];
            descer(h,1);
          }else
            h->quant--;
    }
 impressao(h);
 system("pause");
}

void atendimento(Heap *h){
	exclusao(h);
	impressao(h);
	system("pause");
}

void alteraPrio(Heap *h, int id, char p){
  int aux = (p - 26);
	if(h->id == id){
	  h->prioridade = aux;
	} else if(h->id != id){
		  subir(h, aux);
		}

 impressao(h);
 system("pause");
}

int Main(){

 Heap *h = novoHeap();
 int op = 4;
 char p;
 int v;

 while(op != 0){
 msg();
 scanf("%d", &op);
	if(op == 1){
   printf("Digite o a prioridade do paciente e se id(apenas numeros)\n eles podem se R, Y, G, B: ");
   scanf("%c %d", p, &v);
   insercao(h, p, v);
 	}else if(op == 2){
   atendimento(h);
 	}else if(op == 3){
   printf("Digite o id do paciente e sua no prioridade: ");
   scanf("%d %c", &v, p);
 	}
 system("cls");
}
 return 0;
}
