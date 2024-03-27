import csv

with open("phonebook.csv", "a") as file:
    # that's for automatic closing (instead of file.open and file.close)

    name = input("Name: ")
    number = input("Number: ")

    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name": name, "number": number})