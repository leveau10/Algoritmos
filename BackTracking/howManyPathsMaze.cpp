#include <iostream>
int menorGeral = 1000000000;
int labirinto_bt(int labirinto[20][20], int linha, int coluna,int l, int c, int menor) {
    if (l == -1 || c == -1 || l == linha || c == coluna || labirinto[l][c] != 0)
        return 0;
 
    if (l == linha - 1 and c == coluna - 1){
        if (menor < menorGeral){
            menorGeral = menor+1;
        } 
        return 1;
    }
    labirinto[l][c] = 9;
    menor++;
    int ans =
        labirinto_bt(labirinto, linha, coluna, l + 1, c, menor) +
        labirinto_bt(labirinto, linha, coluna, l, c + 1, menor) +
        labirinto_bt(labirinto, linha, coluna, l, c - 1, menor) +
        labirinto_bt(labirinto, linha, coluna, l - 1, c, menor);
    labirinto[l][c] = 0;
    menor--;
    return ans;
}
 
int main(int argc, char const *argv[])
{
    int n, m;
    std::cin >> n >> m;
    int lab[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> lab[i][j];
        }
    }
 
    labirinto_bt(lab, n, m, 0, 0, 0);
    if(menorGeral == 1000000000){
        std::cout << -1;
    }else{
        std::cout << menorGeral;
    }
 
    return 0;
}
