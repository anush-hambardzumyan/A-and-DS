#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

bool isValid(const std::vector<std::vector<std::string>>& board, int row, int col) {
    // Check column
    for (int r = 0; r < row; ++r) {
        if (board[r][col] == "Q")
            return false;
    }

    // Check upper left diagonal
    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0) {
        if (board[i--][j--] == "Q")
            return false;
    }

    // Check upper right diagonal
    i = row - 1, j = col + 1;
    while (i >= 0 && j < board.size()) {
        if (board[i--][j++] == "Q")
            return false;
    }

    return true;
}

// Backtrack function to get all solutions
void placeQueens(std::vector<std::vector<std::string>>& board, int row, int n, std::vector<std::vector<std::string>>& res) { 
    if (row == n) {
        std::vector<std::string> currSol;
        for (const auto& row : board) {
            std::string str = "";
            for (const auto& elem : row) {
                str += elem;
            }
            currSol.push_back(str);
        }
        res.push_back(currSol);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isValid(board, row, col)) {
            board[row][col] = "Q"; // Place queen
            placeQueens(board, row + 1, n, res);
            board[row][col] = "."; // Backtrack
        }
    }
}

// Backtrack function to count valid solutions
void countValidVersions(std::vector<std::vector<std::string>>& board, int row, int n, int& count) {
    if (row == n) {
        ++count;
        return;
    }

    for (int col{}; col < n; ++col) {
        if (isValid(board, row, col)) {
            board[row][col] = "Q";
            countValidVersions(board, row + 1, n, count);
            board[row][col] = ".";
        }
    }
}

int main() {
    int n = 0;

    std::cout << "Enter grid size (in [1-19] range): ";
    do {
        std::cin >> n;
    } while (n > 19 || n < 1);
    std::cout << std::endl;

    std::cout << "Enter 1 for getting count of all possible versions of arrangements of queens on grid: " << std::endl;
    std::cout << "Enter 2 for seeing all possible arrangements of queens on grid: " << std::endl;
    std::cout << "Enter option: "<< std::endl;

    int option = 0;
    do {
        std::cin >> option;
        std::cout << "You entered option: " << option << std::endl;  // Added diagnostic output
    } while (option != 1 && option != 2);  // Fix condition to prevent infinite loop

    std::vector<std::vector<std::string>> board(n, std::vector<std::string>(n, "."));

    if (option == 1) {
        int count = 0;
        countValidVersions(board, 0, n, count); 
        std::cout << "Number of possible solutions: " << count << std::endl;
    } else if (option == 2) {
        std::vector<std::vector<std::string>> res;
        std::cout << "Attempting to solve N-Queens for grid size " << n << std::endl; // Diagnostic
        placeQueens(board, 0, n, res);
        std::cout << "Solutions found: " << res.size() << std::endl;  // Diagnostic

        if (res.empty()) {
            std::cout << "No solutions exist for the given board size." << std::endl;
        } else {
            for (const auto& solution : res) {
                for (const auto& row : solution) {
                    std::cout << row << std::endl;
                }
                std::cout << std::endl;
            }
        }
    }

    return 0;
}
