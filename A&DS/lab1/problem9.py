def binn(lst):
    res = 0
    for i in range(len(lst)-1, -1, -1):
        res += lst[i] * 2**(len(lst)-i-1)
    return res


def f(x):
    cnt = 0
    for i in range(len(x)-1):
        if x[i] != x[i+1]:
            cnt += 1
    return cnt == 2



x, y = [int(g) for g in input().split()]
flag1 = False
flag2 = True
cnt = 0



for n in range(3, 61):
    for i in range(0, n-2):
        num = [0] * n
        for k in range(i+1):
            num[k] = 1
        for j in range(n-1, i+1, -1):
            num[j] = 1
            cnt += 1
            if cnt > 32187:
                print(binn(num))
            if flag2 and binn(num) >= x:
                cnt = 1
                flag2 = False
            if binn(num) > y:
                cnt -= 1
                flag1 = True
                break
        if flag1:
            break
    if flag1:
        break
print(cnt)



    
