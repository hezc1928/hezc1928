

# import sys
# sys.path.append('../')

import pandas as pd

df = pd.read_csv('E:\cpp_project\py\matplotlib\part_table.dat',
                 sep="\t", header=None)

a = df.values.tolist()
#   names=["one", "two", "three", "o1", "o2","o3","o4"]
# print(df)
# print(a)
# 这样a是一个二维list
for i in range(len(a)):
    print(a[i])
