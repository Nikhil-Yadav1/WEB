#include <iostream>
#include <vector>

const int N = 5; // Size of the maze (N x N)
std::vector<std::vector<int>> maze(N, std::vector<int>(N, 0)); // Initialize with all cells as open

bool isSafe(int x, int y) {
    // Check if the cell is within the maze boundaries and not a wall (1)
    return x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0;
}

bool solveMaze(int x, int y, int goalX, int goalY, std::vector<std::vector<int>>& solution) {
    if (x == goalX && y == goalY) {
        // Reached the goal
        solution[x][y] = 1;
        return true;
    }

    if (isSafe(x, y)) {
        // Mark the current cell as part of the solution path
        solution[x][y] = 1;

        // Try moving in different directions: up, down, left, right
        if (solveMaze(x + 1, y, goalX, goalY, solution) ||
            solveMaze(x - 1, y, goalX, goalY, solution) ||
            solveMaze(x, y + 1, goalX, goalY, solution) ||
            solveMaze(x, y - 1, goalX, goalY, solution)) {
            return true;
        }

        // If no path is found in this direction, backtrack
        solution[x][y] = 0;
    }

    return false;
}

int main() {
    // Initialize the maze with walls (1s)
    maze[1][1] = 1;
    maze[1][3] = 1;
    maze[3][1] = 1;
    maze[3][2] = 1;
    maze[3][3] = 1;

    int startX = 0;
    int startY = 0;
    int goalX = N - 1;
    int goalY = N - 1;

    std::vector<std::vector<int>> solution(N, std::vector<int>(N, 0));

    if (solveMaze(startX, startY, goalX, goalY, solution)) {
        std::cout << "Solution found:" << std::endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << solution[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}