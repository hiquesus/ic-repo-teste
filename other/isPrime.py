def isPrime(n):
    if n == 1 or n == 0:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

def returnPrimes(n):
    A = list(range(n))
    primeNums = []

    for i in range(n):
        if isPrime(i):
            primeNums.append(A[i])
    return primeNums

def main():
    while True:
        try:
            numero = int(input("Todos os primos até: "))
            break
        except ValueError:
            print("Escreva um número inteiro")
    print(returnPrimes(numero))

main()