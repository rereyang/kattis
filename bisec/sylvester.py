import sys

def query(n, x, y): 
    neg = 0
    while n > 1:
        hn = n / 2
        if x >= hn and y >= hn: 
            neg = neg + 1
            x = x - hn
            y = y - hn
        elif x >= hn and y < hn:
            x = x - hn
        elif x < hn and y >= hn: 
            y = y - hn
        n = hn
    return (-1) ** neg 

_k = input()
for i in sys.stdin:
    line = i.split()
    n, x, y, w, h = tuple(map(int, line))
    for i in range(y, y + h):
        for j in range(x, x + w - 1):
            print(query(n, i, j), end=" ")
        print(query(n, i, x + w - 1))