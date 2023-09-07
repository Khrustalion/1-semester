n, k = [int(x) for x in input().split()]
nums = [int(x) for x in input().split()]

k = k % n if k > 0 else (n - (k%n)) % n + 1
print(*(nums[k-1:] + nums[:k-1]))
