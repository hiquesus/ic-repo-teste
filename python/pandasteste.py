import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('worldcities.csv')

ax = df.plot.hist(column=["population"], bins=1000, figsize=(10, 8))
plt.show()
