#include <iostream>

int fatn(int num){
    if (num == 0 || num == 1)
    {
        return 1;
    }else {
        return num*fatn(num-1);
    }
}

int main(int argc, char const *argv[])
{
    std::cout << fatn(5);
    return 0;
}
