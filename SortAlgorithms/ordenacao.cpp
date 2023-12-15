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
    
    for(int i = 0; i < t-1; i++){
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

    if (ordenado(a, t))
    {
        std::cout << "entrou" << std::endl;
        return void();
    }
    std::cout << "não ordenado" << std::endl;
    for (int i = 1; i < t; i++)
    {
        int ins = a[i];
        for (int j = 0; j < i+1; j++)
        {
            if (ins < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

/* TODO: Implementar função */
void merge_sort(int a[], unsigned int t);

int main(int argc, char const *argv[])
{
    int size = 5;
    int a[size] = {5,3,8,2,1};
    insercao(a, size);
    
    
    for (int i = 0; i < size; i++)
    {
        std::cout << a[i] << std::endl;
    }
    
    return 0;
}
