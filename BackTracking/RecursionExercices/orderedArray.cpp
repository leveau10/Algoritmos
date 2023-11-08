#include <iostream>

int ordered(int n, int vet[]){
    if (n == 1)
    {
        return true;
    }
    if(vet[n-1] >= vet[n-2]){
        return ordered(n-1, vet);
    }else{
        return false;
    }
    

}

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    int vet[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> vet[i];
    }
    std::cout << ordered(n, vet);
    return 0;
}
