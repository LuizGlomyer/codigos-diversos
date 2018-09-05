#ifndef BOGOSORT_HPP_INCLUDED
#define BOGOSORT_HPP_INCLUDED

 #include <algorithm>
 #include <vector>

 template<class T>
 void bogosort(T* v, int tam)
 {
     std::vector<T> array;
     for(int i = 0; i < tam; i++)
        array.push_back(v[i]);
     while (! is_sorted(array.begin(), array.end()))
         std::random_shuffle(array.begin(), array.end());
     for(int i = 0; i < tam; i++)
     v[i] = array[i];
 }

 template<class T>
 bool is_sorted(const std::vector<T>& array)
 {
     for (typename std::vector<T>::size_type i = 1; i < array.size(); ++i)
         if (array[i] < array[i-1]) return false;
     return true;
 }


#endif // BOGOSORT_HPP_INCLUDED
