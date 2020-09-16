/* Tudo indica estar funcionando */

#include <stdio.h>
#include <stdlib.h>

typedef struct No *ArvAVL;

struct No{
    int info;
    int alt;
    struct No *esq;
    struct No *dir;
};

ArvAVL *cria_ArvAVL();
void preOrdem_Arv(ArvAVL *raiz);
int insere_Arv(ArvAVL *raiz, int valor);
int remove_Arv(ArvAVL *raiz, int x);
struct No *procuraMenor(struct No *atual);
int consulta_Arv(ArvAVL *raiz, int valor);
void rotacaoLL(ArvAVL *raiz);
void rotacaoRR(ArvAVL *raiz);
void rotacaoLR(ArvAVL *raiz);
void rotacaoRL(ArvAVL *raiz);
int verifica_AVL(struct No *no);
int maior(int a, int b);
int altura(struct No *no);

int main()
{
    ArvAVL *raiz;
    raiz = cria_ArvAVL();
    insere_Arv(raiz,3);
    insere_Arv(raiz,4);
    insere_Arv(raiz,9);
    insere_Arv(raiz,2);
    insere_Arv(raiz,5);
    insere_Arv(raiz,1);
    insere_Arv(raiz,8);
    remove_Arv(raiz,5);
    preOrdem_Arv(raiz);
}


ArvAVL *cria_ArvAVL()
{
    ArvAVL *raiz = (ArvAVL*)malloc(sizeof(ArvAVL));
    if(raiz !=  NULL){
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
    int res;
    if(*raiz == NULL)
    {
        struct No *novo;
        novo = (struct No*)malloc(sizeof(struct No));
        if(novo == NULL){
            return 0;
        }
        novo->info = valor;
        novo->alt = 0;
        novo->dir = NULL;
        novo->esq = NULL;
        *raiz = novo;
        return 1;
    }
    struct No *atual = *raiz;
    if(valor < atual->info)
    {
        if((res=insere_Arv(&(atual->esq),valor))==1)
        {
            if(verifica_AVL(atual) >= 2)
            {
                if(valor < (*raiz)->esq->info)
                {
                    rotacaoLL(raiz);
                }
                else
                {
                    rotacaoLR(raiz);
                }
            }
        }
    }
    else
    {
        if((res=insere_Arv(&(atual->dir),valor))==1)
        {
            if(verifica_AVL(atual) >= 2)
            {
                if(valor > (*raiz)->dir->info)
                {
                    rotacaoRR(raiz);
                }
                else
                {
                    rotacaoRL(raiz);
                }
            }
        }
    }

    atual->alt = maior(altura(atual->esq),altura(atual->dir)) + 1;

    return res;
}

int remove_Arv(ArvAVL *raiz, int x)
{
    if(*raiz == NULL)
    {
        return 0;
    }

    int res;
    
    if(x < (*raiz)->info)
    {
        if((res=remove_Arv(&(*raiz)->esq,x))==1)
        {
            if(verifica_AVL(*raiz) >= 2)
            {
                if(altura((*raiz)->dir->esq) <= altura((*raiz)->dir->dir))
                {
                    rotacaoRR(raiz);
                }
                else
                {
                    rotacaoRL(raiz);
                }
            }
        }
    }

    if(x > (*raiz)->info)
    {
        if ((res=remove_Arv(&(*raiz)->dir,x))==1)
        {
            if(verifica_AVL(*raiz) >= 2)
            {
                if(altura((*raiz)->esq->dir) <= altura((*raiz)->esq->esq))
                {
                    rotacaoLL(raiz);
                }
                else
                {
                    rotacaoLR(raiz);
                }
            }
        }
        
    }

    if((*raiz)->info == x)
    {
        if(((*raiz)->esq == NULL || (*raiz)->dir == NULL))
        {
            struct No *noAntigo = (*raiz);
            if((*raiz)->esq != NULL)
            {
                *raiz = (*raiz)->esq;
            }
            else
            {
                *raiz = (*raiz)->dir;
            }
            free(noAntigo);
        }
        else
        {
            struct No *temp = procuraMenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_Arv(&(*raiz)->dir, (*raiz)->info);
            if(verifica_AVL(*raiz) >= 2)
            {
                if(altura((*raiz)->esq->dir) <= altura((*raiz)->esq->esq))
                {
                    rotacaoLL(raiz);
                }
                else
                {
                    rotacaoLR(raiz);
                }
            }
            (*raiz)->alt = maior(altura((*raiz)->esq),altura((*raiz)->dir)) + 1;
            return 1;
        }
        return res;
    }
}

struct No *procuraMenor(struct No *atual)
{
    struct No *no1 = atual;
    struct No *no2 = atual->esq;
    while(no2 != NULL)
    {
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int consulta_Arv(ArvAVL *raiz, int valor)
{
    if(raiz == NULL){
        return 0;
    }
    struct No *atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    return 0;
}

void rotacaoLL(ArvAVL *raiz)
{
	struct No *pB;
	pB = (*raiz)->esq;
	(*raiz)->esq = pB->dir;
	pB->dir = *raiz;
    (*raiz)->alt = maior(altura((*raiz)->esq),altura((*raiz)->dir)) + 1;
    pB->alt = maior(altura(pB->esq),(*raiz)->alt) + 1;
	*raiz = pB;
}	

void rotacaoRR(ArvAVL *raiz)
{
	struct No *pB;
	pB = (*raiz)->dir;
	(*raiz)->dir = pB->esq;
	pB->esq = *raiz;
    (*raiz)->alt = maior(altura((*raiz)->esq),altura((*raiz)->dir)) + 1;
    pB->alt = maior(altura(pB->dir),(*raiz)->alt) + 1;
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

int verifica_AVL(struct No *no)
{
    return labs(altura(no->esq) - altura(no->dir));
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

int altura(struct No *no)
{
    if(no == NULL)
    {
        return -1;
    }
    else
    {
        return no->alt;
    }   
}
