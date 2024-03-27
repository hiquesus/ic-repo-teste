def main():
    height = get_height()
    for i in range(height):
         print("#")

def get_height():
    while True:
        try:
            n = int(input("height: "))
            if n > 0:
                return n
            else:
                print("must be positive")
        except ValueError:
            print("must be an intiger")

main()