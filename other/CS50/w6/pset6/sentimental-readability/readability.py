from cs50 import get_string

# get string

text = get_string("Text: ")
len = len(text)


def main():

    # get number of letters, words and sentences

    letters = countletters(text)
    words = countwords(text)
    sentences = countsentences(text)

    # index letters

    L = letters / words * 100
    S = sentences / words * 100

    # index calc and rounding

    calc = 0.0588 * L - 0.296 * S - 15.8
    index = round(calc)

    # print grade level
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print("Grade", index)


def countletters(text):  # count letters
    n = 0
    for i in range(len):
        if text[i].isalpha() == True:
            n += 1
        else:
            n += 0
    return n


def countwords(text):  # count words
    # if there's a paragraph space at the beginning, we don't count it as a word
    n = 1
    for i in range(len):
        if text[i].isspace() == True:
            n += 1
        else:
            n += 0
    return n


def countsentences(text):  # count letters
    n = 0
    for i in range(len):
        if text[i] == "." or text[i] == "!" or text[i] == "?":
            n += 1
        else:
            n += 0
    return n


main()