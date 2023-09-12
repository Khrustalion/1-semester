def f(x):
    x = bin(x)[2:]
    cnt = 0
    for i in range(len(x) - 1):
        if x[i] != x[i+1]:
            cnt += 1
    return cnt == 2
lst = [1, 1, 2, 12, 8, 6, 16]
for i in range(len(lst)-1):
    for j in range(i+1, len(lst)):
        if lst[i] & lst[j] == 0:

            print(lst[i], lst[j])
