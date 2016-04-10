T = int(input())

for i in range(T):
    n = int(input())
    a = 1
    for i in range(1, n+1, 1):
        a = a*i
    ans = 0
    while a:
        ans += a%10
        a = a//10
    print(ans)
