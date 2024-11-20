#include <iostream>
#include <unordered_map>
#include <vector>

long long fibMemo(int n, std::unordered_map<int, long long>& memo) {
    if (n == 0 || n == 1) 
        return n;
    
    if (memo.find(n) != memo.end()) 
        return memo[n];
    
    return memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);;
}

long long fibDP(int n) {
    std::vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

long long fibRecursive (int n) {
    if (n == 0 || n == 1) 
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

long long fibIterative (int n) {
    if (n == 0 || n == 1)   
        return n;

    int a = 0;
    int b = 1;
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

template <int N>
struct fibCompileTime {
    static const long long value = fibCompileTime<N - 1>::value + fibCompileTime<N - 2>::value;
};

template <>
struct fibCompileTime<0> {
    static const long long value = 0;
};

template <>
struct fibCompileTime<1> {
    static const long long value = 1;
};


int main () {
    std::unordered_map<int, long long> memo = std::unordered_map<int, long long>();
    std::cout << fibMemo(10, memo) << std::endl;
    std::cout << fibDP(10) << std::endl;
    std::cout << fibRecursive(10) << std::endl;
    std::cout << fibIterative(10) << std::endl; 
    std::cout << fibCompileTime<10>::value << std::endl;
}