N = 100000
prime = {}
seive = {}
for i in range(2, N):
    if i not in seive:
        prime[i] = 1
        for j in range(2, N//i + 1):
            seive[i*j] = 1
     
def gcd(a, b):
    if a == 0 or b == 0 : return a^b
    return gcd(b, a%b)

def isprime(n):
    return abs(n) in prime
            
n = int(input())
arr = [i for i in range(-n, n+1)]

ans_len = 0
ans_tup = (0, 0)

for a in arr:
    for b in arr:
        if not isprime(b): continue
        g = gcd(abs(a), abs(b))
        if g > 1 and g <= ans_len:
            continue
        f = lambda x : x*x + a*x + b
        glen = 0
        for n in range(1, b):
            if not isprime(f(n)):
                break
            glen += 1
        
        if glen > ans_len:
            ans_len = glen
            ans_tup = (a, b)

print(ans_tup[0], ans_tup[1])