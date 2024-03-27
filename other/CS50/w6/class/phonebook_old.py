import sys

# or people = dict()
people = {
    "Pedro": "+55 (82) 99159-5212",
    "Rique": "+55 (82) 99414-3848",
    "Banana": "+55 (82) 99123-4567"
}

name = input("Name: ")
if name in people:
    number = people[name]
    print("Number: ", number)