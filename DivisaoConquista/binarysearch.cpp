#include <iostream>

int busca(int a[], int inicio, int fim, int e){
    int i = (inicio+fim)/2;
    if (a[i] == e) {
        return i;
    }
    if (inicio >= fim)
    {
        return -1;
    }else{
        if(a[i] < e){
            return busca(a, i+1, fim, e);
        }else{
            return busca(a, inicio, i-1, e);
        }
    }
    
}

int main(int argc, char const *argv[])
{

    int a[11] = {10,20,30,56,78,99,105,678,1098,1100,12000};
    int result = busca(a, 0, 10, 678);
    std::cout <<  result << std::endl;
    return 0;
}
