N = 10**5
sum_arr = [0]*(N+1)
val_arr = [-i for i in range(N+1)]

for i in range(1, N+1):
    for j in range(1, N//i + 1):
        val_arr[i*j] += i


def f(v):
    if v > N : return 0
    return val_arr[v]

for i in range(1, N+1):
    sum_arr[i] = sum_arr[i-1] + i*(f(f(i)) == i and f(i) != i)

#for i in range(1, N):
#    if i == f(f(i)):
#        print(i)

T = int(input())
for _ in range(T):
    n = int(input())
    print(sum_arr[n])