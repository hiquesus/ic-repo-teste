import pandas as pd

# df = pd.read_csv('dados.csv', on_bad_lines='warn') #todas as 1350 linha foram skippadas
# df = pd.read_csv('cities.csv')
df = pd.read_csv('worldcities.csv')

print(df)

# df.plot(x = 'Sample ID', y = 'population', title = "População")