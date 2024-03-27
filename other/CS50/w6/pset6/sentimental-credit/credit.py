# AMEX -> 15 digits + starts w/ 34/37
# VISA -> 13 or 16 digits + starts w/ 4
# MASTERCARD -> 16 digits + starts w/ 51/52/53/54/55

card = 0
while card < 1:
    try:
        # make sure it's a positive number
        card = int(input("Number: "))
        if card < 0:
            print("must be positive")
    # if there's a value error, it's not an number, therefore prints that you should write a number
    except ValueError:
        print("must be an intiger")


def checkcard(card):
    def digitsof(n):
        return [int(d) for d in str(n)]
    digits = digitsof(card)
    odd = digits[-1::-2]
    even = digits[-2::-2]
    checksum = 0
    checksum += sum(odd)
    for d in even:
        checksum += sum(digitsof(d*2))
    return checksum % 10


# if it's valid, check card company
if checkcard(card) == 0:
    # AMEX CHECK
    if (card >= 34 * 10**13 and card < 35 * 10**13) or (card >= 37 * 10**13 and card < 38 * 10**13):
        print("AMEX")
    # VISA CHECK
    elif (card >= 4 * 10**12 and card < 5 * 10**12) or (card >= 4 * 10**15 and card < 5 * 10**15):
        print("VISA")
    # MASTERCARD CHECK
    elif card >= 51 * 10**14 and card < 56 * 10**14:
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")