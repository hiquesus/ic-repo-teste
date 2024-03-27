def main():
    # gets height
    h = geth()
    # loops until you print everything
    for i in range(h):
        s = h - i - 1
        print(" " * s, end="")  # spaces for left stair
        print("#" * (i + 1), end="")  # left stair
        print("  ", end="")  # 2 spaces between blocks
        print("#" * (i + 1))  # right stair


# function to get the height
def geth():
    while True:
        try:
            # make sure it's a positive intiger (and smaller than 9)
            n = int(input("Height: "))
            if n > 0 and n <= 8:
                # return the intiger and break the loop (if it's a positive int)
                return n
            else:
                print("must be positive and less than 9")
        # if there's a value error, it's not an intiger, therefore prints that you should write an intiger
        except ValueError:
            print("must be an intiger")


main()