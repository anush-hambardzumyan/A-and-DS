#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int LongestCommonSubstring(std::string s1, std::string s2) {

    std::vector<std::vector<int>> dp(s1.size() + 1, std::vector<int>(s2.size() + 1, 0));
    int max = 0;
    for (int i = 1; i < s1.size() + 1; ++i) {
        for (int j = 1; j < s2.size() + 1; ++j) {
            if (s1[i - 1] == s2 [j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max = std::max(max, dp[i][j]);
            }
        }
    }
    return max;
}

int main() {
    std::string s1, s2;

    // Input two strings
    std::cout << "Enter the first string: ";
    std::getline(std::cin, s1);

    std::cout << "Enter the second string: ";
    std::getline(std::cin, s2);

    // Find the length of the longest common substring
    int result = LongestCommonSubstring(s1, s2);

    // Output the result
    std::cout << "Length of the Longest Common Substring: " << result << std::endl;

    return 0;
}
