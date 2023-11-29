#include <iostream>
#include <vector>
/* TODO: Implementar função */
bool ordenado(int a[], unsigned int t){
  for (unsigned int i = 0; i < t-1; i++){
    if (a[i] > a[i+1]) return false;
  }
  return true;
};

/* TODO: Implementar função */
void selecao(int a[], unsigned int t){
    
    for (int i = 0; i < t-1; i++){
        int menor = a[i];
        int index = i;
        for (int j = i; j < t; j++)
        {
            if (a[j] < menor){         
                menor = a[j];
                index = j;
            }
        }
        int temp = a[index];
        a[index] = a[i];
        a[i]=temp;                    
    }    
}

/* TODO: Implementar função */
void insercao(int a[], unsigned int t){
    
}

/* TODO: Implementar função */
void merge_sort(int a[], unsigned int t);

int main(int argc, char const *argv[])
{
    int size = 10;
    int a[size] = {5,4,3,2,1,4,5,4,2,3};
    selecao(a, size);
    
    
    for (int i = 0; i < size; i++)
    {
        std::cout << a[i] << std::endl;
    }
    
    return 0;
}
