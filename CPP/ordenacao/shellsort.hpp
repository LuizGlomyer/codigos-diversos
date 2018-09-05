#ifndef SHELLSORT_HPP_INCLUDED
#define SHELLSORT_HPP_INCLUDED
/*
template <typename T>
void shellsort(T* v, int tam){
    int gap = 1;
    int i, j;

    while (gap < tam)
        gap = gap*3+1;

    while (gap > 1) {
        gap /= 3;
        for (i = gap; i < tam; i++) {
            T aux = v[i];
            j = i;

            while (j >= gap && aux < v[j-gap]) {
                v[j] = v[j-gap];
                j -= gap;
            }

            v[j] = aux;
        }
    }
}
*/















/*void shellsort(int* v, int tam){
    int h = 1;
    while(h < tam/3)
        h = 3 * h + 1;
    while(h >= 1){
        for(int i = h; i < tam - 1;)
    }
}

*/







#endif // SHELLSORT_HPP_INCLUDED
