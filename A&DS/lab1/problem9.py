def stock_up(s):
    s = bin(s)[2:]
    cnt = 0
    for i in range(len(s)-1):
        if s[i] != s[i+1]:
            cnt += 1
        elif cnt > 2:
            return False
    return cnt == 2

def cnt_1(strng):
    cnt_r = 0
    for i in range(len(strng)-1):
        if strng[i] != strng[i+1]:
            cnt_r += 1
        if cnt_r == 2:
            return len(strng) - i - 1
    return 1 if cnt_r == 1 else len(strng)


def cnt_1_start(strng):
    cnt_1 = 0
    for i in range(len(strng)):
        if strng[i] == '1':
            cnt_1 += 1
        else:
            return cnt_1
    return len(strng)


x, y = [int(s) for s in input().split()]





if x < 10 and y < 10:
    cnt = 0
    for i in range(x, y+1):
        if stock_up(i):
            cnt += 1
    print(cnt)
else:
    cnt = 1 if x < 5 else 1
    x = max(9, x)


    pow_two_after_x = 1
    pow_two_before_y = 1
    while 2**pow_two_after_x < x:
        pow_two_after_x += 1
    while 2**(pow_two_before_y) < y:
        pow_two_before_y += 1
    if y == 2**(pow_two_before_y):
        y -= 1
        pow_two_before_y -= 1
    cnt_1_x = cnt_1(bin(x)[2:])
    cnt_1_y = cnt_1(bin(y)[2:]) if stock_up(y) else cnt_1(bin(y)[2:]) - 1

    
    if pow_two_after_x > pow_two_before_y:
        print(cnt_1_y - cnt_1_x + 1)
    elif 2**pow_two_after_x == x and 2**pow_two_before_y == y:
        cnt_1 = 0
        for i in range(pow_two_after_x, pow_two_before_y):
            cnt_1 += (i*(i-1))//2
        print(cnt_1)
        
    else:
        x = bin(x)[2:]
        y = bin(y)[2:]
        for i in range(cnt_1_x, len(x) - cnt_1_start(x)):
            cnt += 1
        for i in range(len(x) - cnt_1_start(x) - 1):
            cnt += (i * (i+1))//2
        for i in range(cnt_1_y):
            cnt += 1
        for i in range(len(y) - cnt_1_start(y), len(y)-1):
            cnt += (i * (i+1))//2
        for i in range(pow_two_after_x, pow_two_before_y):
            cnt += (i*(i-1))//2
        print(cnt)
        
    
