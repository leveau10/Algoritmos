#include <iostream>

int somatory(int n, int vet[]){
    int sum = 0;
    if(n == 0){
        return 0;
    }else{
        sum += vet[n-1];
        return sum + somatory(n-1, vet);
    }


}

int main(int argc, char const *argv[])
{
    int n, sum;
    std::cin >> n;
    int vet[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> vet[i];
    }
    sum = somatory(n, vet);
    std::cout << sum;
    return 0;
}
