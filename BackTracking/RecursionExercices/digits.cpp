#include <iostream>

int digits(int n){
    int qtd = 0;
    if (n < 10 && n > -1){
        return 1;
    }else{
        qtd++;
        return qtd + digits(n/10);
    }
}

int main(int argc, char const *argv[])
{
    std::cout << digits(2314);
    return 0;
}
