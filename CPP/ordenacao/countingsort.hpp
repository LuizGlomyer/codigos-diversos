#ifndef COUNTINGSORT_HPP_INCLUDED
#define COUNTINGSORT_HPP_INCLUDED



void countingsort(int* A, int* B, int tam, int k){
    int* C = new int[k+1];
    for(int i = 0; i <= k; i++)
        C[i] = 0;
    for(int j = 0; j < tam; j++)
        C[A[j]] = C[A[j]] + 1;
    for(int i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1];
    for(int j = tam-1; j >= 0; j--){
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
}

#endif // COUNTINGSORT_HPP_INCLUDED
