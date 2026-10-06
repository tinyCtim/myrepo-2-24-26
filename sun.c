
// game of life - from GitHub
// modified by lrb - user can input generations, speed and board dimensions
// displays population and generation

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ALIVE '#'
#define DEAD ' '

int grid[80][160];
int height,width;

/*
 * @brief Initializes the grid with random alive/dead values.
 *
 * This function populates the grid with random values, either 0 (dead)
 * or 1 (alive). This is used to initialize the grid at the start of
 * the Game of Life.
 */

void initGrid() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

/*
 * @brief Prints the current state of the grid to the console.
 *
 * This function clears the console and prints the current state
 * of the grid to the console. The grid is represented as a series
 * of '#' characters for alive cells and ' ' characters for dead
 * cells. The function is intended to be used in the main loop of
 * the program to print the state of the grid at each iteration.
 */

void printGrid() {
    system("clear");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", grid[i][j] ? ALIVE : DEAD);
        }
        printf("\n");
    }
}

/*
 * @brief Counts the number of alive neighbours for a given cell.
 *
 * This function takes two arguments, i and j, which represent the
 * coordinates of the cell in the grid. It then iterates over the
 * eight cells in the Moore neighbourhood of the cell, counting the
 * number of cells that are alive. Note that the cell itself is
 * excluded from the count.
 *
 * The function uses the modulo operator to wrap around the edges of
 * the grid, so the function works correctly even when the cell is
 * located at the edge of the grid.
 *
 * @param i The row of the cell in the grid.
 * @param j The column of the cell in the grid.
 * @return The number of alive neighbours of the cell.
 */

int countAliveNeighbours(int i, int j) {
    int count = 0;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            int x = (i + k + height) % height;
            int y = (j + l + width) % width;
            count += grid[x][y];
        }
    }
    count -= grid[i][j];
    return count;
}

/*
 * @brief Updates the grid according to the rules of the Game of Life.
 *
 * This function creates a new grid with the same dimensions as the
 * current grid, then iterates over each cell in the current grid.
 * For each cell, it counts the number of alive neighbours, and then
 * applies the rules of the Game of Life to determine whether the cell
 * should be alive or dead in the new grid. The new grid is then
 * copied back into the current grid.
 */

int updateGrid() {
    int population = 0;
    int newGrid[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int count = countAliveNeighbours(i, j);
            newGrid[i][j] = (grid[i][j] == 1) ? (count == 2 || count == 3) : (count == 3);
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = newGrid[i][j];
            population += grid[i][j];
        }
    }
    return population;
}

/*
 * @brief The main entry point for the Game of Life.
 *
 * This function initializes the grid with random values, then iterates
 * through the grid for a specified number of iterations, printing the
 * grid and updating it each time. The usleep() call is used to slow down
 * the iteration.
 */

int main() {
    srand(time(NULL));
    int iter,speed;
    printf("\nrun.c - 10/5/26");
    printf("\nEnter number of generations e.g. 813 ");
    scanf("%d",&iter);
    printf("Enter pause between generations e.g. 1000 for 1 second ");
    scanf("%d",&speed);
    printf("Enter width < 160 e.g. 100 ");
    scanf("%d",&width);
    printf("Enter height < 80 e.g. 60 ");
    scanf("%d",&height);
    initGrid();
    for (int i = 0; i < iter; i++) {
        printGrid();
        printf("\npopulation %d  generation %d\n",updateGrid(), i);
        usleep(speed * 1000);
    }
    return 0;
}
