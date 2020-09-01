#include <stdio.h>
#include <stdlib.h>

typedef struct No *ArvBin;

struct No{
    int info;
    struct No *esq;
    struct No *dir;
};

ArvBin *cria_ArvBin();
int insere_Arv(ArvBin *raiz, int valor);
void sucessor(ArvBin *q, ArvBin *r);
int remove_Arv(ArvBin *raiz, int x);
int consulta_Arv(ArvBin *raiz, int valor);
int altura_Arv(ArvBin *raiz);

int main()
{
    ArvBin *raiz;
    raiz = cria_ArvBin();
    int numeros, key, verifica=0, quantidade=0, altura=0;
    scanf("%d ", &numeros);
    while(numeros >= 0)
    {
        insere_Arv(raiz,numeros);
        quantidade++;
        scanf("%d ", &numeros);
    }
    scanf("%d", &key);

    altura = altura_Arv(raiz);
    printf("%d %d\n", quantidade, altura);
    verifica = consulta_Arv(raiz,key);
    if(verifica == 0)
    {
        insere_Arv(raiz,key);
        quantidade++;
    }
    else if(verifica == 1)
    {
        remove_Arv(raiz,key);
        quantidade--;
    }
    altura = altura_Arv(raiz);
    printf("%d %d\n", quantidade, altura);
}

ArvBin *cria_ArvBin()
{
    ArvBin *raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz !=  NULL){
        *raiz = NULL;
    }
    return raiz;
}

int insere_Arv(ArvBin *raiz, int valor)
{
    if(raiz == NULL){
        return 0;
    }
    struct No *novo;
    novo = (struct No*)malloc(sizeof(struct No));
    if(novo == NULL){
        return 0;
    }
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    if(*raiz == NULL){
        *raiz = novo;
    }else{
        struct No *atual = *raiz;
        struct No *ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor >= atual->info){
                atual = atual->dir;
            }else{
                atual = atual->esq;
            }
        }
        if(valor >= ant->info){
            ant->dir = novo;
        }else{
            ant->esq = novo;
        }
    }
    return 1;
}

void sucessor(ArvBin *q, ArvBin *r)
{
    if ((*r)->esq != NULL)
        sucessor(q, &(*r)->esq);
    else {
        (*q)->info = (*r)->info;
        *q = *r;
        *r = (*r)->dir;
    }
}

int remove_Arv(ArvBin *raiz, int x)
{
    ArvBin *p, q;
    p = raiz;
    while ((*p != NULL) && (x != (*p)->info)) {
        if (x < (*p)->info)
            p = &(*p)->esq;
        else if (x > (*p)->info)
            p = &(*p)->dir;
    }
    if (*p != NULL) {
        q = *p;
        if (q->esq == NULL)
            *p = q->dir;
        else if (q->dir == NULL)
            *p = q->esq;
        else
            sucessor(&q, &q->dir);
        free(q);
        return 1;
    }
    return 0;
}

int consulta_Arv(ArvBin *raiz, int valor)
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

int altura_Arv(ArvBin *raiz)
{
    if((raiz == NULL) || (*raiz == NULL)){
        return 0;
    }
    int alt_esq = altura_Arv(&((*raiz)->esq));
    int alt_dir = altura_Arv(&((*raiz)->dir));
    if(alt_esq > alt_dir){
        return (alt_esq + 1);
    }else{
        return (alt_dir + 1);
    }
}

