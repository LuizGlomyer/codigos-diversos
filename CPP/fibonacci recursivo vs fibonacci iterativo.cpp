#include <iostream>
using namespace std;
int fib(int n){
    int x, y;
    if(n <= 1)
        return n;
    x = fib(n-1);
    y = fib(n-2);
    return x+y;

}

int main(){

    cout << fib(45);
    /*double x = 0, y = 1, fib = 0;
    for(int i = 0; i< 50; i++){
        fib = x + y;
        y = x;
        x = fib;
    }
    cout << fib;
*/
    return 0;
}
