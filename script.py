#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd
import subprocess


# Remove a notação científica
np.set_printoptions(suppress=True)

entrada3 = np.array([])
entrada4 = np.array([])
entrada5 = np.array([])
i = 0
while i < 10:
    aux = subprocess.run(["./trab1", "./entradas/3.txt", "5", "./saidas/3.txt"], stdout=subprocess.PIPE, universal_newlines=True)
    y = aux.stdout
    y = y.split("\n")
    y = [float(j) for j in y]
    if i == 0:
        entrada3 = np.array(y)
    else:
        entrada3 = np.vstack((entrada3, y))
    i += 1

i = 0
while i < 10:
    aux = subprocess.run(["./trab1", "./entradas/4.txt", "5", "./saidas/4.txt"], stdout=subprocess.PIPE, universal_newlines=True)
    y = aux.stdout
    y = y.split("\n")
    y = [float(j) for j in y]
    if i == 0:
        entrada4 = np.array(y)
    else:
        entrada4 = np.vstack((entrada4, y))
    i += 1

i = 0
while i < 10:
    aux = subprocess.run(["./trab1", "./entradas/5.txt", "10", "./saidas/5.txt"], stdout=subprocess.PIPE, universal_newlines=True)
    y = aux.stdout
    y = y.split("\n")
    y = [float(j) for j in y]
    if i == 0:
        entrada5 = np.array(y)
    else:
        entrada5 = np.vstack((entrada5, y))
    i += 1

media3 = entrada3.mean(axis=0)
media4 = entrada4.mean(axis=0)
media5 = entrada5.mean(axis=0)

# print(f"Médias entrada 3: {media3}")
# print(f"Médias entrada 4: {media4}")
# print(f"Médias entrada 5: {media5}")

medias = np.array([media3,media4,media5])
# print(medias)
df = pd.DataFrame(medias)
df.index = ["Entrada 3", "Entrada 4", "Entrada 5"]
df.columns = ["Leitura", "Distâncias", "Ordenação", "MST", "Agrupamento", "Escrita"]
print("\\begin{table}[h]", "\centering", sep=("\n"))
print(df.to_latex())
print("\end{table}")