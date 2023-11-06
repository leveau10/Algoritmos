#include <iostream>

int somatory(int n){
    if( n == 1){
        return 1;
    }else{
        return n + somatory(n-1);
    }
}

int main(int argc, char const *argv[])
{
    std::cout << somatory(6);
    return 0;
}
