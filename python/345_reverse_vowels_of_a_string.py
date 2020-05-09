def reverseVowels(s):
    s = [i for i in s]
    vowels = ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')
    head = 0
    tail = len(s) - 1
    while head < tail:
        while s[head] not in vowels and head < tail:
            head += 1
        while s[tail] not in vowels and head < tail:
            tail -= 1
        s[head], s[tail] = s[tail], s[head]
        head += 1
        tail -= 1
    return ''.join(s)

print(reverseVowels("hello"))