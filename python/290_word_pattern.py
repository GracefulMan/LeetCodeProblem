def wordPattern(pattern, str):
    str = str.split(' ')
    if len(str) != len(pattern): return False
    test_dict = {}
    for i in range(len(str)):
        if pattern[i] not in test_dict.keys():
            test_dict[pattern[i]] = str[i]
        else:
            if test_dict[pattern[i]] != str[i]:
                return False
    return True
