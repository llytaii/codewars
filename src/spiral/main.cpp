// Challenge:
// https://www.codewars.com/kata/536a155256eb459b8700077e

#include <vector>
#include <iostream>

using Grid = std::vector<std::vector<int>>;

std::vector<std::vector<int>> create_spiral(int n)
{
    // initialization
    int run_length = n;
    int count = 1;
    int y = 0;
    int x = 0;

    Grid grid(n);

    std::cout << grid.max_size() << std::endl;

    for (auto &v : grid)
        v.resize(n);

    for (; x < run_length; ++x) // draw right (increment x 3 times only)
        grid[y][x] = count++;
    --x; ++y;
    --run_length;

    while (count < n * n)
    {
        for (int i = y + run_length; y < i; ++y) // draw down
            grid[y][x] = count++;
        --y; --x;

        for (int i = x - run_length; x > i; --x) // draw left
            grid[y][x] = count++;
        ++x; --y;

        --run_length;
        for (int i = y - run_length; y > i; --y) // draw up
            grid[y][x] = count++;
        ++y; ++x;

        for (int i = x + run_length; x < i; ++x) // draw right
            grid[y][x] = count++;
        --x; ++y;
        --run_length;
    }

    return grid;
}

int main()
{
    create_spiral(4);
}