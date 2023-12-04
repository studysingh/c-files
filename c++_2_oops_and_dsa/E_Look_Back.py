import math

def solve():
    n = int(input())
    arr = list(map(int, input().split()))
    ans = 0
    p = arr[0]
    for i in range(1, n):
        c = arr[i]
        if c >= p:
            p = c
            continue
        p_c = p / c
        nval = math.log2(p_c)
        x = int(nval)
        z = 0
        if x == nval:
            z = x
        else:
            z = x + 1
        p = c * (2 ** z)
        ans += z
    print(ans)

t = int(input())
while t > 0:
    solve()
    t -= 1
