from cs50 import SQL

database = SQL("sqlite:///favourites.db")

favourite = input("Favourite Team: ")

rows = database.execute("SELECT COUNT(*) AS n FROM favourites WHERE team = ?", favourite)  # "?" is kinda like %s in C

print(rows[0]["n"])