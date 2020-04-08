import sys
import math

line = input()
lwnr = line.split()
l, w, n, r = float(lwnr[0]), float(lwnr[1]), int(lwnr[2]), float(lwnr[3])
cranes = []
for line in range(n):
    crane = input().split()
    cranes.append((float(crane[0]), float(crane[1]), ))
dist = lambda p1, p2: math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)
centers = [(-l / 2, 0), (l/ 2, 0), (0, -w / 2), (0, w / 2)]
min_num = n + 1
def generate(crs, cns): 
    global min_num
    if len(cns) == 0:
        min_num = min(min_num, n - len(crs))
        return
    for cr in crs: 
        cnsn = set(cns)
        for cn in cns:
            if dist(cn, cr) <= r:
               cnsn = cnsn - set([cn])
        if len(cnsn) < len(cns): 
            generate(crs - set([cr]), cnsn)
generate(set(cranes), set(centers))
if min_num == n + 1: 
    print("Impossible")
else:
    print(min_num)