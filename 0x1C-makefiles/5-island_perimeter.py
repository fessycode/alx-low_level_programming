#!/usr/bin/python3
"""
TO defines Island  Perimeter function.
"""


def island_perimeter(grid):
    """
    returns the perimeter of the island
    decribed in grid:
    + grid is a list of list of integers:
      - 0 represents a water zone
      - 1 represents a land zone
      - One cell is a square with side length 1
      - Grid cells are connected horizontally/vertically (not diagonally).
      - Grid is rectangular, width and height don’t exceed 100

    Approach:
    Using this simple model that iterate over all items in the grid,
    e.g. grid = [
                  [0, 0, 0, 0],
                  [0, 1, 1, 0],
                  [0, 1, 0, 0],
                  [0, 1, 0, 0],
                  [0, 0, 0, 0]
                ]
    Given a return variable `perimeter` set to `0`:
    Logic: for each items in the grid,for top, bottom, right, or left
    sides that is not `1` increase the perimeter by `1` unit.

    Starting with the assumption that width is going to be equal
    accross all row in the grid
    """

    if not len(grid):  # if grid is empty
        return
    y = len(grid)  # height starting from `0`: y_axis
    x = len(grid[0])  # width starting from `0`: x_axis
    perimeter = 0
    for dy in range(y):
        for dx in range(x):
            if grid[dy][dx] == 1:  # land ooo!
                try:
                    if grid[dy][dx - 1] == 0 or dx - 1 < 0:  # check to left
                        perimeter = perimeter + 1
                except IndexError:
                    perimeter = perimeter + 1
                    # print("left edge case at [{}][{}]".format(dy, dx))

                try:
                    if grid[dy][dx + 1] == 0:  # check to right
                        perimeter = perimeter + 1
                except IndexError:
                    perimeter = perimeter + 1
                    # print("right edge case at [{}][{}]".format(dy, dx))

                try:
                    if grid[dy - 1][dx] == 0 or dy - 1 < 0:  # check up
                        perimeter = perimeter + 1
                except IndexError:
                    perimeter = perimeter + 1
                    # print("up edge case at [{}][{}]".format(dy, dx))

                try:
                    if grid[dy + 1][dx] == 0:  # check down
                        perimeter = perimeter + 1
                except IndexError:
                    perimeter = perimeter + 1
                    # print("down edge case at [{}][{}]".format(dy, dx))

    return perimeter
