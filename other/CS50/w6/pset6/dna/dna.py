import csv
import sys

# notes:
#


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    database = []
    argv1 = sys.argv[1]
    with open(argv1, "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)

    # TODO: Read DNA sequence file into a variable
    argv2 = sys.argv[2]
    with open(argv2, "r") as file:
        dnaseq = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    subseqs = list(database[0].keys())[1:]
    # print (subseq) - just to check
    results = {}
    for subseq in subseqs:
        results[subseq] = longest_match(dnaseq, subseq)

    # TODO: Check database for matching profiles
    for person in database:
        count = 0
        for subseq in subseqs:
            if int(person[subseq]) == results[subseq]:
                count += 1

        if count == len(subseqs):
            print(person["name"])
            return

    print("No Match.")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
