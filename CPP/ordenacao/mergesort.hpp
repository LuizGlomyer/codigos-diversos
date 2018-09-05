#ifndef MERGESORT_HPP_INCLUDED
#define MERGESORT_HPP_INCLUDED

template<typename T>
void MergeS(T* v, int inicio, int meio, int fim){
    int p1,p2,tam, fim1 = 0, fim2 = 0;
    T* temp;
    tam = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    //temp = (int *) malloc(tam * sizeof(int));
    temp = new T[tam];
    if(temp != NULL){
        for(int i = 0; i < tam; i++)
            if(!fim1 && !fim2){

                if(v[p1] < v[p2])
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];

                if(p1 > meio)
                    fim1 = 1;
                if(p2 > fim)
                    fim2 = 1;
            }
            else{
                if(!fim1) temp[i] = v[p1++];
                else temp[i] = v[p2++];
            }
        for(int j = 0, k = inicio; j < tam; j++, k++)
            v[k] = temp[j];
    }
    //delete temp;
}

template<typename T>
void mergesort(T* v, int inicio, int fim){ //O(n log n) // inicio posicao 0, fim posicao tam-1
    int meio;
    if(inicio < fim){
        meio = (inicio+fim)/2;
        mergesort(v, inicio, meio);
        mergesort(v, meio+1, fim);
        MergeS(v, inicio, meio, fim);
    }
}


#endif // MERGESORT_HPP_INCLUDED
