#include <iostream>
#include <random>
#include <chrono>

int maze(int l, int c){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(1, 100);
    std::cout << l << " " << c;
    std::cout << std::endl;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int rand_val = dis(gen);
            int result = rand_val <= 65 ? 0 : 1;
            std::cout << result << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    
    maze(4, 4);
    return 0;
}


