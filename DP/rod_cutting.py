import sys
def max(a, b):
    return a if (a > b) else b

def cutRod(price, n):
    if(n <= 0):
        return 0
    max_val = -sys.maxsize-1
    for i in range(0, n):
        max_val = max(max_val, price[i] +
                      cutRod(price, n - i - 1))
    return max_val

# Driver code
arr = [1, 12, 6, 2, 8, 5, 17, 20]
size = len(arr)
print("Maximum Obtainable Value is", cutRod(arr, size))
