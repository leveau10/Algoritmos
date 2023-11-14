#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
int main(int argc, char const *argv[])
{
    int n, k;
    std::vector<double> results;
    while(std::cin >> n >> k){
        int grades[n];
        for (int i = 0; i < n; i++)
        {
            std::cin >> grades[i];
        }
        for (int i = 1; i < n-1; i++)
        {   
            for (int j = i+1; j < n; j++)
            {
                for (int m = j+1; m < n+1; m++)
                {
                    double media = ((grades[n-i] + grades[n-j] + grades[n-m])/3.0);
                    results.push_back(media);
                }       
            }
        }
        sort(results.begin(), results.end()); 
        std::cout << std::setprecision(1) << std::fixed << results[results.size()-k] << std::endl;
    }
    return 0;
}
