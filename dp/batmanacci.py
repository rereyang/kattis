import sys

for i in sys.stdin:
    ab = i.split()
    n = int(ab[0])
    k = int(ab[1])
    fib = [0, 1]
    for i in range(2, n + 1): 
        fib.append(fib[-1] + fib[-2])
    ni, ki = n, k
    sn = ["", "N", "A"]
    while ni > 2:
        if ki > fib[ni - 2]: 
            ni, ki = ni - 1, ki - fib[ni - 2]
        else: 
            ni = ni - 2
    print(sn[ni])