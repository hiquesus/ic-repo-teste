def main():
    x = get()
    for i in range(x):
        print("?" * x, end="")
        print("")

def get():
    while True:
        try:
            n = int(input("x: "))
            if n > 0:
                return n
            else:
                print("must be positive")
        except ValueError:
            print("must be an intiger")

main()