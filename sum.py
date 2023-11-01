def sum(n):
    """
    Recursive funcion which sums all integers up to n.
    """
    if n == 0:
        return 0
    else:
        return n + sum(n-1)

print(sum(10))
