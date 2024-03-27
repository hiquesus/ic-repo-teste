import csv

with open("favourites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = {}  # or dict()
    for row in (reader):
        favourite = row["player"]  # just change "team" to change the thingy
        if favourite in counts:
            counts[favourite] += 1
        else:
            counts[favourite] = 1

# def get_value(favourite):
#     return counts[favourite]
# key=get_value

# for team in sorted(counts, reverse=True):  # reverse alphabetic sorting  # just get rid of ", reverse=True" to make it alphabetical
for favourite in sorted(counts, key=lambda team: counts[favourite], reverse=True):  # decreasing sorting  # just get rid of ", reverse=True" to make it crescent
    # lambda para substituir função get_value
    print(favourite,":", counts[favourite])

# see favourite

favourite = input("Favourite: ")
if favourite in counts:
    print(favourite, ":", counts[favourite])
else:
    print("favourite not in the list")