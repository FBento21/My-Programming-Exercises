def count_partitions(n, m):
    """
    Counts the number of ways to partition n objects using parts up to m >= 0
    """
    if m == 1:
        return n
    else:
        count_partitions(n - m, m)
