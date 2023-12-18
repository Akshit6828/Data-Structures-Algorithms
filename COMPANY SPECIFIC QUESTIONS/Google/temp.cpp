#include <iostream>
#include <vector>
#include <unordered_map>

char find_winner(const std::vector<std::vector<char>>& matrix) {
    std::unordered_map<char, int> players {{'A', 0}, {'B', 0}, {'C', 0}};

    // Iterate through the matrix
    for (const auto& row : matrix) {
        for (char cell : row) {
            // Update player areas
            players[cell]++;
        }
    }

    // Find the player with the maximum area
    char winner = ' ';
    int maxArea = 0;
    for (const auto& player : players) {
        if (player.second > maxArea) {
            maxArea = player.second;
            winner = player.first;
        }
    }

    return winner;
}

int main() {
    // Example usage:
    std::vector<std::vector<char>> matrix = {
        {'A','B','A'},
        {'C','B','C'},
        {'A','B','A'},
    };

    char winner = find_winner(matrix);
    std::cout << "The winner is player: " << winner << std::endl;

    return 0;
}
