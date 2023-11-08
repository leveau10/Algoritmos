#include <iostream>

int occurrences(int n, int vet[], int k){
    int qtd = 0;
    if(n == 0){
        return 0;
    }
    if(vet[n-1] == k){
        qtd++;
    }
    return qtd + occurrences(n-1, vet, k );

}


int main(int argc, char const *argv[])
{
    int n;
    int number = 4;
    std::cin >> n;
    int vet[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> vet[i];
    }
    std::cout << occurrences(n, vet, number);
    return 0;
}
