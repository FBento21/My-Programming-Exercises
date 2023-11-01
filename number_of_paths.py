def number_of_paths(n, m):
    """
    Computes the number of unique paths from the top left corner to bottom right
    corner of n x m grid, only moving down or right 1 unit at time
    """
    if n == 1 or m == 1:
        return n + m
    else:
        return number_of_paths(n - 1, m) + number_of_paths(n, m - 1)

print(number_of_paths(1, 3))

