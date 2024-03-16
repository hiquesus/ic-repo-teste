import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('worldcities.csv')

# print(df.info()) // vendo infos do df

# plot do mundo onde cada ponto é uma cidade
df.plot(kind='scatter', x='lng', y='lat', title='Cidades')
plt.show()