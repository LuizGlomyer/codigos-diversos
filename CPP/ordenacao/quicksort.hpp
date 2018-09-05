#ifndef QUICKSORT_HPP_INCLUDED
#define QUICKSORT_HPP_INCLUDED

#include <iostream>
#include <algorithm>
using namespace std;
#include "troca.hpp"

template<class T>
	int partition( T a[],int low,int high )
	{
		T num=a[low];
		int i=low+1;
		int j=high;
		T temp;

		while( 1 )
		{

		       while( i<high && num>a[i] )
		              i++;

		       while( num<a[j] )
		              j--;

		       if( i<j )
		       {
		          temp=a[i];
		          a[i]=a[j];
		          a[j]=temp;
		       }
		       else
		       {
		          temp=a[low];
		          a[low]=a[j];
		          a[j]=temp;
		       return(j);
		       }
		}
	}

	template<class T>
	void quicksort(T a[],int low,int high )
	{
		int j;

		if( low<high )
		{
		    j=partition(a,low,high);
		    quicksort(a,low,j-1);
		    quicksort(a,j+1,high );
		}
	}

#endif // QUICKSORT_HPP_INCLUDED
