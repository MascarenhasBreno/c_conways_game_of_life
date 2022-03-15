#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int height = 100;
int width = 100;

void grid_gen(char grid[height][width], int flag)
{
    int temp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (flag == 0)
            {
                temp = rand() % 2;
                if (temp == 1)
                {
                    grid[i][j] = 'x';
                    continue;
                }
            }
            grid[i][j] = '0';
        }
    }
}

void print_grid(char grid[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------------------------------------------------------------------------------\n");
}

int count_neighbors(char gridCount[height][width], int row, int col)
{
    int i, j, count = 0;
    for (i = row - 1; i <= row + 1; i++)
    {
        for (j = col - 1; j <= col + 1; j++)
        {
            if ((i == row && j == col) || (i < 0 || j < 0) || (i >= height || j >= width))
            {
                continue;
            }
            if (gridCount[i][j] == 'x')
            {
                count++;
            }
        }
    }

    return count;
}

void copy_grid(char first_array[height][width], char second_array[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            second_array[i][j] = first_array[i][j];
        }
    }
}

void game_iteration(char grid[height][width], char temp[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int neighbors = count_neighbors(grid, i, j);
            if (grid[i][j] == 'x' && (neighbors == 2 || neighbors == 3))
            {
                temp[i][j] = 'x';
                continue;
            }
            else if (grid[i][j] == '0' && neighbors == 3)
            {
                temp[i][j] = 'x';
                continue;
            }
            temp[i][j] = '0';
        }
    }
    copy_grid(temp, grid);
    print_grid(grid);
}

int main(int argc, char const *argv[])
{
    // array initialization
    char grid[height][width];
    char temp_grid[height][width];

    // grid creation
    srand(time(NULL));

    grid_gen(grid, 0);

    print_grid(grid);

    // game iterations
    int iterations = 10;
    for (int i = 0; i < iterations; i++)
    {
        copy_grid(grid, temp_grid);
        game_iteration(grid, temp_grid);
    }

    return 0;
}
