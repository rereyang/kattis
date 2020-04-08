import sys

bindd = dict()
varr = dict()

def bind(var, val):
    if var in bindd:
        del varr[bindd[var]]
    bindd[var] = int(val) 
    varr[int(val)] = (var)

def retvar(var):
    if var in bindd:
        return bindd[var]
    else:
        return 3000

def retval(val):
    if val in varr:
        return varr[val]
    else:
        return ""

def evalr(xs):
    if len(xs) == 1:
        return retvar(xs[0])
    acc = retvar(xs[0])
    if acc >= 3000:
        return 3000
    for i in range(1, len(xs), 2):
        x = retvar(xs[i + 1])
        if x >= 3000:
            return 3000
        if xs[i] == '+':
            acc = acc + x
        else:
            acc = acc - x
    return acc

for i in sys.stdin:
    line = i.rstrip().split(" ")
    if line[0] == 'def':
        bind(line[1], line[2])
    elif line[0] == 'clear':
        bindd = {}
        varr = {}
    else:
        cres = evalr(line[1:-1])
        prfx = " ".join(line[1:])
        if cres >= 3000:
            print(prfx + " unknown")
        else:
            pvar = retval(cres)
            if len(pvar) > 0:
                print(prfx + " " + pvar)
            else:
                print(prfx + " unknown")
    # print("bindings")
    # print(bindd)
    # print("revers")
    # print(varr)
