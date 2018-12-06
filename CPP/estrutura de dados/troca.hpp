#ifndef TROCA_H
#define TROCA_H

template<typename T>
void troca(T& a, T& b){
    T c = a;
    a = b;
    b = c;
}


#endif // TROCA_H
