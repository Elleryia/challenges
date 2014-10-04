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
    
for x in range(1000, 1, -1):
    #check if x is a palindrome
    if (str(x) == str(x)[::-1]):
        #check if it is prime
        if isprime(x):
            print(x)
            break