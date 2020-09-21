#include <stdio.h>
#include <stdlib.h>

struct Arv_AVL{
    int info;
    int alt;
    struct Arv_AVL *esq;
    struct Arv_AVL *dir;
};

struct Arv_AVL *Arv_AVL_Aux(int info);
struct Arv_AVL *insere_Arv(struct Arv_AVL *raiz, int info);
struct Arv_AVL *remove_Arv(struct Arv_AVL *raiz, int info);
struct Arv_AVL *procuraMenor(struct Arv_AVL *atual);
struct Arv_AVL *RotacaoEsq(struct Arv_AVL *raiz);
struct Arv_AVL *RotacaoDir(struct Arv_AVL *raiz);
void preOrdem_Arv(struct Arv_AVL *raiz);
int consulta_Arv(struct Arv_AVL *raiz, int info);
int verifica_AVL(struct Arv_AVL *Arv_AVL);
int maior(int a, int b);
int altura(struct Arv_AVL *Arv_AVL);

int main()
{
    struct No *raiz = NULL;

    int quantidadeEntrada, i, valor, valorBuscado, encontrado;

    scanf("%d", &quantidadeEntrada);
    for(i = 0; i < quantidadeEntrada; i++)
    {
        scanf("%d", &valor);
        raiz = insere_Arv(raiz,valor);
    }

    scanf("%d", &valorBuscado);
    encontrado = consulta_Arv(raiz,valorBuscado);

    if(encontrado == 1)
    {
        raiz = remove_Arv(raiz,valorBuscado);
    }
    else if(encontrado == 0)
    {
        raiz = insere_Arv(raiz,valorBuscado);
    }

    preOrdem_Arv(raiz);
}

struct Arv_AVL *Arv_AVL_Aux(int info)
{
	struct Arv_AVL *temp = (struct Arv_AVL*)malloc(sizeof(struct Arv_AVL));
	temp->info = info;
	temp->esq = NULL;
	temp->dir = NULL;
	temp->alt = 1;
	return temp;
}

struct Arv_AVL *insere_Arv(struct Arv_AVL *raiz, int info)
{
	if(raiz == NULL)
    {
		return Arv_AVL_Aux(info);
    }

	if(info < raiz->info)
    {
		raiz->esq = insere_Arv(raiz->esq, info);
    }
	else if(info > raiz->info)
    {
		raiz->dir = insere_Arv(raiz->dir, info);
    }
	else
    {
		return raiz;
    }

	raiz->alt = maior(altura(raiz->esq), altura(raiz->dir)) + 1;

	int verifica = verifica_AVL(raiz);

	if(verifica > 1 && info < raiz->esq->info)
    {
		return RotacaoDir(raiz);
    }

	if(verifica < -1 && info > raiz->dir->info)
    {
		return RotacaoEsq(raiz);
    }

	if(verifica > 1 && info > raiz->esq->info)
	{
		raiz->esq = RotacaoEsq(raiz->esq);
		return RotacaoDir(raiz);
	}

	if(verifica < -1 && info < raiz->dir->info)
	{
		raiz->dir = RotacaoDir(raiz->dir);
		return RotacaoEsq(raiz);
	}

	return raiz;
}

struct Arv_AVL *remove_Arv(struct Arv_AVL *raiz, int info)
{
	if(raiz == NULL)
    {
		return raiz;
    }

	if(info < raiz->info)
    {
		raiz->esq = remove_Arv(raiz->esq, info);
    }
    else if(info > raiz->info)
    {
		raiz->dir = remove_Arv(raiz->dir, info);
    }
	else
	{
		if(raiz->dir == NULL && raiz->esq == NULL)
		{
			free(raiz);
			raiz = NULL;
		}
        else if(raiz->esq != NULL && raiz->dir == NULL)
		{
			struct Arv_AVL *temp = raiz->esq;
			raiz = raiz->esq;
			free(temp);
		}
		else if(raiz->dir != NULL && raiz->esq == NULL)
		{
			struct Arv_AVL *temp = raiz->dir;
			raiz = raiz->dir;
			free(temp);
		}
		else
		{
			struct Arv_AVL *temp = procuraMenor(raiz->dir);
			raiz->info = temp->info;
			raiz->dir = remove_Arv(raiz->dir, temp->info);
		}
	}
	if(raiz == NULL)
    {
    	return raiz;      
    }

	raiz->alt = 1 + maior(altura(raiz->esq),altura(raiz->dir));

	int verifica = verifica_AVL(raiz);

	if(verifica > 1 && verifica_AVL(raiz->esq) >= 0)
    {
		return RotacaoDir(raiz);
    }

	if(verifica < -1 && verifica_AVL(raiz->dir) <= 0)
    {
		return RotacaoEsq(raiz);
    }

	if(verifica > 1 && verifica_AVL(raiz->esq) < 0)
	{
		raiz->esq = RotacaoEsq(raiz->esq);
		return RotacaoDir(raiz);
	}
	
	if(verifica < -1 && verifica_AVL(raiz->dir) > 0)
	{
		raiz->dir = RotacaoDir(raiz->dir);
		return RotacaoEsq(raiz);
	}
	return raiz;
}

struct Arv_AVL *procuraMenor(struct Arv_AVL *Arv_AVL)
{
	while(Arv_AVL->esq != NULL)
    {
		Arv_AVL = Arv_AVL->esq;
    }

	return Arv_AVL;
}

struct Arv_AVL *RotacaoEsq(struct Arv_AVL *raiz)
{
	struct Arv_AVL *pB = raiz->dir;
	struct Arv_AVL *pC = pB->esq;

	pB->esq = raiz;
	raiz->dir = pC;

	raiz->alt = maior(altura(raiz->esq), altura(raiz->dir)) + 1;
	pB->alt = maior(altura(pB->esq), altura(pB->dir)) + 1;

	return pB;
}

struct Arv_AVL *RotacaoDir(struct Arv_AVL *raiz)
{
	struct Arv_AVL *pB = raiz->esq;
	struct Arv_AVL *pC = pB->dir;

	pB->dir = raiz;
	raiz->esq = pC;

	raiz->alt = maior(altura(raiz->esq), altura(raiz->dir)) + 1;
	pB->alt = maior(altura(pB->esq), altura(pB->dir)) + 1;

	return pB;
}

void preOrdem_Arv(struct Arv_AVL *raiz)
{
    if (raiz != NULL) 
    {
        printf("(C%d",raiz->info);
        preOrdem_Arv(raiz->esq);
        preOrdem_Arv(raiz->dir);
        printf(")");
    } 
    else 
    {
		printf("()");
    }
}

int consulta_Arv(struct Arv_AVL *raiz, int info)
{
    if(raiz == NULL){
        return 0;
    }
    struct Arv_AVL *atual = raiz;
    while(atual != NULL){
        if(info == atual->info){
            return 1;
        }
        if(info > atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    return 0;
}

int verifica_AVL(struct Arv_AVL *Arv_AVL)
{
	if(Arv_AVL == NULL)
    {
        return 0;
    }
	
 	return altura(Arv_AVL->esq) - altura(Arv_AVL->dir);
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

int altura(struct Arv_AVL *Arv_AVL)
{
	if(Arv_AVL == NULL)
    {
		return 0;
    }

 	return Arv_AVL->alt;
}