#include <iostream>

int bits( int n ){
    int qtd = 0;
    if( n <= 1){
        return 1;
    }else{
        qtd++;
        return qtd + bits(n/2);
    }


}

int main(int argc, char const *argv[])
{
    std::cout << bits(4213);
    return 0;
}
