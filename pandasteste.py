import pandas as pd

df = pd.read_csv('dados.csv', on_bad_lines='warn') #todas as 1350 linha foram skippadas

print(df.to_string())