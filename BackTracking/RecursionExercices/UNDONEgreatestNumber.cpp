#include <iostream>

int greatest(int n, int vet[]){
    
}

int main(int argc, char const *argv[])
{
    int n, index;
    std::cin >> n;
    int vet[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> vet[i];
    }
    index = greatest(n, vet);
    std::cout << index;
    return 0;
}
