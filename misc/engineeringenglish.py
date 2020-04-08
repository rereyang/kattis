import sys

dupl = set()
for i in sys.stdin:
    line = i.rstrip().lstrip().split(" ")
    ans = ""
    for word in line:
        if word.lower() in dupl:
            ans = ans + ". "
        else:
            ans = ans + word + " "
            dupl.add(word.lower())
    # print(dupl)
    print(ans[:-1])