#include <iostream>

int evenSumArray(int n, int vet[]){
    int sum = 0;
    if(n == 0){
        return 0;
    }
    if (vet[n-1]%2 == 0)
    {
        sum+= vet[n-1];
    }
    return sum + evenSumArray(n-1, vet);
    
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
    index = evenSumArray(n, vet);
    std::cout << index;

    return 0;
}
