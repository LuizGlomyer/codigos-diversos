#ifndef NO_HPP_INCLUDED
#define NO_HPP_INCLUDED


template<typename T>
class No{
public:
    No();
    ~No();
    T getDados() const;
    No* esq,* dir;
    T dados;
private:
};

template<typename T>
No<T>::No(){
    esq = dir = nullptr;
}

template<typename T>
No<T>::~No(){

}

template<typename T>
T No<T>::getDados() const{
    return dados;
}

#endif // NO_HPP_INCLUDED
