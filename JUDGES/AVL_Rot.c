/*Funciona porém da Runtime Error com o Judge da UNIFESP*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No *ArvAVL;

struct No{
    int info;
    struct No *esq;
    struct No *dir;
};

ArvAVL *cria_ArvAVL();
void preOrdem_Arv(ArvAVL *raiz);
int insere_Arv(ArvAVL *raiz, int valor);
void carrega(ArvAVL *raiz);
void rotacaoLL(ArvAVL *raiz);
void rotacaoRR(ArvAVL *raiz);
void rotacaoLR(ArvAVL *raiz);
void rotacaoRL(ArvAVL *raiz);
int verifica_AVL(ArvAVL *raiz);
int maior(int a, int b);
int altura(ArvAVL *raiz);

int main()
{
    ArvAVL *raiz;
    int alt, verifica=0;

	raiz = cria_ArvAVL();
	carrega(raiz);
    
    alt = altura(raiz) - 1;
    printf("%d\n",alt);
    preOrdem_Arv(raiz);
    printf("\n");

    verifica = verifica_AVL(raiz);

    if(verifica <= -2) //rotacoes a direita
    {
        verifica = verifica_AVL(&((*raiz)->dir));
        if(verifica <= -1)
        {
            rotacaoRR(raiz);
            printf("RR\n");
        }
        else if(verifica >= 1)
        {
            rotacaoRL(raiz);
            printf("RL\n");
        }
    }
    else if(verifica >= 2) //rotacoes a esquerda
    {
        verifica = verifica_AVL(&((*raiz)->esq));
        if(verifica >= 1)
        {
            rotacaoLL(raiz);
            printf("LL\n");
        }
        else if(verifica <= -1)
        {
            rotacaoLR(raiz);
            printf("LR\n");
        }
    }

    alt = altura(raiz) - 1;
    printf("%d\n",alt);
    preOrdem_Arv(raiz);
}

ArvAVL *cria_ArvAVL()
{
    ArvAVL *raiz = (ArvAVL*)malloc(sizeof(ArvAVL));
    if(raiz !=  NULL)
    {
        *raiz = NULL;
    }
    return raiz;
}

void preOrdem_Arv(ArvAVL *raiz)
{
    if(*raiz != NULL)
    {
        printf("(C%d", (*raiz)->info);
        preOrdem_Arv(&((*raiz)->esq));
        preOrdem_Arv(&((*raiz)->dir));
		printf(")");
    }
	else
	{
		printf("()");
	}
}

int insere_Arv(ArvAVL *raiz, int valor)
{
    struct No *novo;
    novo = (struct No*)malloc(sizeof(struct No));
    if(novo == NULL)
    {
        return 0;
    }
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    if(*raiz == NULL)
    {
        *raiz = novo;
    }
    else
    {
        struct No *atual = *raiz;
        struct No *ant = NULL;
        while(atual != NULL)
        {
            ant = atual;
            if(valor >= atual->info)
            {
                atual = atual->dir;
            }
            else
            {
                atual = atual->esq;
            }
        }
        if(valor >= ant->info)
        {
            ant->dir = novo;
        }
        else
        {
            ant->esq = novo;
        }
    }
    return 1;
}


void carrega(ArvAVL *raiz)
{
    char c;
    int chave;
 
    scanf("%s", &c);
    if (c == '(') 
    {
        scanf("%s", &c);
        if (c == 'C') 
        {
            scanf("%d", &chave);
            insere_Arv(raiz,chave);
            carrega(&((*raiz)->esq));
            carrega(&((*raiz)->dir));
            scanf("%s", &c);
            return;
        }
    }
}

void rotacaoLL(ArvAVL *raiz)
{
	struct No *pB;
	pB = (*raiz)->esq;
	(*raiz)->esq = pB->dir;
	pB->dir = *raiz;
	*raiz = pB;
}	

void rotacaoRR(ArvAVL *raiz)
{
	struct No *pB;
	pB = (*raiz)->dir;
	(*raiz)->dir = pB->esq;
	pB->esq = *raiz;
	*raiz = pB;
}

void rotacaoLR(ArvAVL *raiz)
{
	rotacaoRR(&((*raiz)->esq));
    rotacaoLL(raiz);
}

void rotacaoRL(ArvAVL *raiz)
{
	rotacaoLL(&((*raiz)->dir));
    rotacaoRR(raiz);
}

int verifica_AVL(ArvAVL *raiz)
{
  return (altura(&((*raiz)->esq)) - altura(&((*raiz)->dir)));
}

int maior(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int altura(ArvAVL *raiz)
{
    if((raiz == NULL) || (*raiz == NULL))
    {
        return 0;
    }
    else
    {
        return 1 + maior(altura(&((*raiz)->esq)), altura(&((*raiz)->dir)));
    }   
}