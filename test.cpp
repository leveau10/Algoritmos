#include "linkedList/linkedList.hpp"
#include <iostream>

int main()
{
    ll_int lista1;
    for (int i = 1; i < 30; i+=3){
        lista1.push_back(i);
    }

    lista1.push_front(5);
    int size = lista1.size();
    std::cout << "Size: " << size << std::endl;
    std::cout << "Soma: " << lista1.sum() << std::endl;
    std::cout << "Count: " << lista1.count(22) << std::endl;
    std::cout << "Repeated: " << lista1.repeated() << std::endl;
    lista1.bigDifference();
    std::cout << "lista1 = { ";
    for (int i=0 ; i< size; i++){
        std::cout << lista1.front() << " ";
        lista1.pop_front();
    }
    std::cout << "}" << std::endl;
    return 0;
}