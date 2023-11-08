#include <iostream>
#include <vector>

std::vector<int> divsArray(int n, int div){
    std::vector<int> list;

    if(div == 0){
        return list;
    }

    if (n%div == 0)
    {
        list = divsArray(n, div-1 );
        list.push_back(div);
    }else{
        list = divsArray(n, div-1 );
    }

    return list;
    
}

std::vector<int> divs(int n){
    return divsArray(n, n);
}

int main(int argc, char const *argv[])
{
    int n = 20;
    std::vector<int> list = divs(n);

    for (int i : list)
    {
        std::cout << i << " ";
    }

    return 0;
}
