df = {'a' : [1, 1], 'b' : 2}

df['c'] = [3 if x == 1 else 4 for x in df['a'] ]

print(df)