#include <stdio.h>
#include <stdlib.h>

typedef struct Noh
{
    int valor;
    struct Noh *esq, *dir;
};

typedef struct Noh Tree;

Tree * cria_elemento(int valor)
{
    Tree* noh = (Tree*)malloc(sizeof(Tree));
    noh->valor  = valor;
    noh->esq  =  noh->dir  = NULL;
    return(noh);
}

void arv_bin_check(Tree *a)
{
   if (!a)
        return;
    int aux = a->esq->valor;

    if(a->valor < aux){
        printf("\n nao eh uma arvore binaria de busca");
        a = NULL;
        return;
    }
    printf("\n eh uma arvore binaria de busca");
}

void imprime_arvore(Tree* a){
	if(a == NULL) {
		return;
	}
	imprime_arvore(a->esq);
	printf(" %d", a->valor);
	imprime_arvore(a->dir);
}

int main()
{
    int entrada = 0;

    printf("Digite os elementos da arvore:(Obs: 7 nohs, de cima pra baixo, da esquerda para direita.\n");
    scanf("%d", &entrada);
    Tree *arvore = cria_elemento(entrada);
    scanf("%d", &entrada);
    arvore->esq = cria_elemento(entrada);
    scanf("%d", &entrada);
    arvore->dir = cria_elemento(entrada);
    scanf("%d", &entrada);
    arvore->esq->esq = cria_elemento(entrada);
    scanf("%d", &entrada);
    arvore->esq->dir = cria_elemento(entrada);
    scanf("%d", &entrada);
    arvore->dir->esq  = cria_elemento(entrada);
    scanf("%d", &entrada);
    arvore->dir->dir = cria_elemento(entrada);

    printf("\n");
    imprime_arvore(arvore);
    arv_bin_check(arvore);

}
