#!/usr/bin/env python3
# Código mescla entre script feito por Philipe deste grupo e Atílio Antônio Dadalto de outro grupo
import os
import re
import numpy as np
import pandas as pd
import subprocess
import seaborn as sns
import matplotlib as plt

# Remove a notação científica
np.set_printoptions(suppress=True)
sns.set_theme(style="darkgrid")


N_INPUT_FILES = 5
N_ITERATIONS = 20

entradas = []
entradasPercent = []
for inputFile in range(0, N_INPUT_FILES):
    entradas.append(np.array([]))
    entradasPercent.append(np.array([]))

k = {1: 2, 2: 4, 3: 5, 4: 5, 5: 10}

for i in range(N_ITERATIONS):
    for inputFile in range(1, N_INPUT_FILES + 1):
        # print(f"Testando {inputFile}.txt pela {i + 1} vez")

        aux = subprocess.run(
            [
                "./trab1",
                f"./entradas/{inputFile}.txt",
                f"{k[inputFile]}",
                f"./saidas/{inputFile}.txt",
            ],
            stdout=subprocess.PIPE,
            universal_newlines=True,
        )
        y = aux.stdout

        floats = re.findall("\d+\.\d+", y)
        floats = [float(string) for string in floats]
        floatsPercent = floats[:]
        floatsPercent[0:-1] = [100*n/floatsPercent[-1] for n in floatsPercent[0:-1]]

        if i == 0:
            entradas[inputFile - 1] = np.array(floats)
            entradasPercent[inputFile - 1] = np.array(floatsPercent)
        else:
            entradas[inputFile - 1] = np.vstack((entradas[inputFile - 1], floats))
            entradasPercent[inputFile - 1] = np.vstack((entradasPercent[inputFile - 1], floatsPercent))

medias = []
mediasPercent = []
for inputFile in range(0, N_INPUT_FILES):
    medias.append(entradas[inputFile].mean(axis=0)[0:-1])
    mediasPercent.append(entradasPercent[inputFile].mean(axis=0)[0:-1])

mediasNpArray = np.array(medias)
mediasNpArrayPercent = np.array(mediasPercent)
# print(medias)
df = pd.DataFrame(mediasNpArray)
dfPercent = pd.DataFrame(mediasNpArrayPercent)

stringsEntrada = []
for inputFile in range(1, N_INPUT_FILES + 1):
    stringsEntrada.append(f"Entrada {inputFile}")
df.index = stringsEntrada
dfPercent.index = stringsEntrada

df.columns = ["Leitura", "Distâncias", "Ordenação", "MST", "Agrupamento", "Escrita"]
dfPercent.columns = ["Leitura", "Distâncias", "Ordenação", "MST", "Agrupamento", "Escrita"]
# print(df)
# decimals = pd.Series([2, 2, 2, 2, 2, 2], index=["Leitura", "Distâncias", "Ordenação", "MST", "Agrupamento", "Escrita"])

dfPercent = dfPercent.round(2)
# print()

# print((dfPercent.T)[2])
# df_basic = df[['Ordenação']]
# df_basic["Distâncias"] = df["Distâncias"]
# df_basic["N"] = [50, 100, 1000, 2500, 5000]
# print(df_basic)
# g = sns.relplot(x="N", y="Ordenação", kind='line',data=df_basic)
# g1 = sns.relplot(x="N", y="Distâncias", kind='line',data=df_basic)
# g1 = g.twinx()
# g.fig.autofmt_xdate()
# g1.fig.autofmt_xdate()
# plt.pyplot.show()

print("\\begin{table}[h]", "\centering", sep=("\n"))
print(dfPercent.to_latex())
print("\end{table}")
