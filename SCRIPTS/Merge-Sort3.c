void merge(int vetor[], int inicio, int meioInicio, int meioFinal, int final, int vetor2[]);
void mergesort(int vetor2[], int inicio, int final, int vetor[]);
void merge3(int vetor[], int inicio, int final);

int main()
{
    int vetor[8] = {2, 5, 4, 7, 1, 2, 3, 6}, final, inicio;
    inicio = 0;
    final = 8;
    merge3(vetor, inicio, final);

    for(int i = 0; i < 8; i++)
    {
        printf("%d ", vetor[i]);
    }
}

void merge(int vetor[], int inicio, int meioInicio, int meioFinal, int final, int vetor2[])
{
    int i = inicio, j = meioInicio, k = meioFinal, l = inicio;  
   
    while ((i < meioInicio) && (j < meioFinal) && (k < final))  
    {  
        if(vetor[i] < vetor[j]) 
        { 
            if(vetor[i] < vetor[k]) 
            { 
                vetor2[l] = vetor[i];
                l++;
                i++; 
            } 
            else
            { 
                vetor2[l] = vetor[k]; 
                l++;
                k++; 
            } 
        } 
        else
        { 
            if(vetor[j] < vetor[k]) 
            { 
                vetor2[l] = vetor[j]; 
                l++;
                j++; 
            } 
            else
            { 
                vetor2[l] = vetor[k]; 
                l++;
                k++; 
            } 
        } 
    }  
  
    while ((i < meioInicio) && (j < meioFinal))  
    {  
        if(vetor[i] < vetor[j]) 
        { 
            vetor2[l] = vetor[i];
            l++;
            i++;  
        } 
        else
        { 
            vetor2[l] = vetor[j]; 
            l++;
            j++; 
        } 
    }  
  
    while ((j < meioFinal) && (k < final))  
    {  
        if(vetor[j] < vetor[k]) 
        { 
            vetor2[l] = vetor[j]; 
            l++;
            j++; 
        } 
        else
        { 
            vetor2[l] = vetor[k]; 
            l++;
            k++; 
        }  
    }  
  

    while ((i < meioInicio) && (k < final))  
    {  
        if(vetor[i] < vetor[k]) 
        { 
            vetor2[l] = vetor[i]; 
            l++;
            i++; 
        } 
        else
        { 
            vetor2[l] = vetor[k]; 
            l++;
            k++; 
        }  
    }  
   
    while (i < meioInicio)  
    {
        vetor2[l] = vetor[i];  
        l++;
        i++; 
    }
    while (j < meioFinal)
    {
        vetor2[l] = vetor[j];  
        l++;
        j++; 
    }   
 
    while (k < final)
    {
        vetor2[l] = vetor[k]; 
        l++;
        k++; 
    }
}

void mergesort(int vetor2[], int inicio, int final, int vetor[])
{
    if (final - inicio > 1)
    {
        int meioInicio = inicio + ((final - inicio) / 3);
        int meioFinal = inicio + 2 * ((final - inicio) / 3) + 1;
        mergesort(vetor, inicio, meioInicio, vetor2);
        mergesort(vetor, meioInicio, meioFinal, vetor2);
        mergesort(vetor, meioFinal, final, vetor2);
        merge(vetor, inicio, meioInicio, meioFinal, final, vetor2);
    }
}

void merge3(int vetor[], int inicio, int final)
{
    if (final != 0)
    {
        int tamanho = final - inicio;

        int *vetor2 = malloc(tamanho * sizeof(int));

        for(int i=0; i < final; i++)
        {
            vetor2[i] = vetor[i];
        }

        mergesort(vetor2,inicio,final,vetor);

        for(int i=0; i < final; i++)
        {
            vetor[i] = vetor2[i];
        }
    }
}