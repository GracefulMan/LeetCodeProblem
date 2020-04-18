def isPalindrome2(x):
    return list(str(x))[::-1] == list(str(x))


def isPalindrome(x):
    if x < 0: return False
    res = 0
    org= x
    while x > 0:
        res = res * 10 + x % 10
        x = x // 10
    print(res)
    return res == org




def isPalindrome3(x):
    if x < 0:return False
    x =str(x)
    length = len(x)
    for i in range(length // 2):
        if x[i] != x[length - i -1]:
            return False
    return True
print(isPalindrome3(123))


