#include <iostream>

int divs(int n, int div ){
    int qtd = 0;
    if(div == 1){
        return 1;
    }else{
        if(n%div == 0){
            qtd++;
        }
        return qtd + divs(n, div-1);
    }
    
}


int div(int n ){
    return divs(n, n);
}


int main(int argc, char const *argv[])
{
    std:: cout << div(16);
    return 0;
}
