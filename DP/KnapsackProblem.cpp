#include <iostream>
#include <vector>
#include <algorithm>

int KnapsackProblem(int bagCapacity, std::vector<int> weights, std::vector<int> prices) {
    std::vector<std::vector<int>> dp(weights.size() + 1, std::vector<int>(bagCapacity + 1, 0));
    
    for (int i = 1; i <= weights.size(); i++) {
        for (int j = 1; j <= bagCapacity; j++) {
            if (weights[i - 1] <= j) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + prices[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[weights.size()][bagCapacity];
} 
 
int main () {
    std::vector<int> prices = {3000, 2000, 1500};   //Stereo, Laptop, Guitar
    std::vector<int> weights = {4, 3, 1};           //weight in lbs
    int bagCapacity = 4;                            //capacity of robbing ban  
    std::cout << KnapsackProblem(bagCapacity, weights, prices) << std::endl; //Laptop and Guitar will be chosen
}