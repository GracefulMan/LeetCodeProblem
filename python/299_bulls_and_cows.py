
def Counter(string):
    res = {}
    for i in range(len(string)):
        if string[i] in res.keys():
            res[string[i]]+=1
        else:
            res[string[i]] = 1
    return res

def getHint(secret, guess) :
    bulls = cows = 0
    for i in range(len(secret)):
        if secret[i] == guess[i]:
            bulls += 1
    sec = Counter(secret)
    gue = Counter(guess)
    for key, value in gue.items():
        if key in sec.keys():
            cows += min(value, sec[key])
    return "{}A{}B".format(bulls, cows - bulls)


secret = "1123"
guess = "0111"
print(getHint(secret,guess))