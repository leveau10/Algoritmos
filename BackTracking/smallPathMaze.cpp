#include <iostream>
#include <climits>
bool maze(int vet[12][12], int n, int m, int line, int column){
    if(n < 0 || n > line-1 || m < 0 || m > column-1 || vet[n][m] != 0){
        return false;
    }
    if( n == line-1 && m == column-1){
        return true;
    }
    vet[n][m] = 9;
    if(maze(vet, n-1, m, line, column )){
        return true;
    }
    if(maze(vet, n, m-1, line, column )){
        return true;
    }
    if(maze(vet, n+1, m, line, column )){
        return true;
    }
    if(maze(vet, n, m+1, line, column )){
        return true;
    }
    vet[n][m] = 0;
    return false;
}
 
int main(int argc, char const *argv[])
{
    int n, m;
    std::cin >> n >> m;
    int lab[12][12];
    int menor = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> lab[i][j];
        }
 
        
    }
 
    std::cout << maze(lab, 0, 0, n, m);
    
    
    return 0;
}