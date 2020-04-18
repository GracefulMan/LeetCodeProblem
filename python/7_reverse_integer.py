def reverse(x):
    pos = True if x > 0 else False
    x = -x if x < 0 else x
    res = 0
    while x > 0:
        res = res * 10 + x % 10
        x = x // 10
    res = res if res <= 2 << 31 -1 else 0
    return res if pos else -res



def reverse2(x):
    res = ''
    x = str(x)
    for i in range(len(x) - 1, 0, -1): res += x[i]
    res = int(res + x[0]) if x[0] != '-' else -int(res)
    return res if res >= -2 << 30 and res <= 2 << 31 - 1 else 0


def reverse3(x):
    pos = 1 if x > 0 else -1
    res = list(str(x)) if pos == 1 else list(str(-x))
    res.reverse()
    res = int(''.join((str(i) for i in res)))
    return pos * res if res <= 2 << 31 -1 else 0




