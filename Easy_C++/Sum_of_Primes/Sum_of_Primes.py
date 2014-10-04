import sys
def isprime(n):
    # make sure it is a positive integer
    n = abs(int(n))
    if n < 2:
        return False
    if n == 2:
        return True
    if not n & 1:
        return False
    for x in range(3, int(n**0.5) + 1, 2):
        if n % x == 0:
            return False
    return True
    
count = 0
sum = 0
n = 0
while count < 1000:
    if isprime(n):
        count = count + 1
        sum = sum + n
    n = n + 1
print(sum)
    