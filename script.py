#!/usr/bin/env python3
from decimal import Decimal
import os
import numpy as np
import subprocess

entrada3 = np.array([])
entrada4 = np.array([])
entrada5 = np.array([])
i = 0
while i < 10:
    aux = subprocess.run(['./trab1', './entradas/3.txt', '5', './saidas/3.txt'], stdout=subprocess.PIPE, universal_newlines=True)
    y = aux.stdout
    y = y.split('\n')
    y = [Decimal(j)*1000 for j in y]
    # print(y)
    if i == 0:
        entrada3 = np.array(y)
    else:
        entrada3 = np.vstack((entrada3, y))
    i += 1

i = 0
while i < 10:
    aux = subprocess.run(['./trab1', './entradas/4.txt', '5', './saidas/4.txt'], stdout=subprocess.PIPE, universal_newlines=True)
    y = aux.stdout
    y = y.split('\n')
    y = [Decimal(j)*1000 for j in y]
    # print(y)
    if i == 0:
        entrada4 = np.array(y)
    else:
        entrada4 = np.vstack((entrada4, y))
    i += 1

i = 0
while i < 10:
    aux = subprocess.run(['./trab1', './entradas/5.txt', '10', './saidas/5.txt'], stdout=subprocess.PIPE, universal_newlines=True)
    y = aux.stdout
    y = y.split('\n')
    y = [Decimal(j)*1000 for j in y]
    # print(y)
    if i == 0:
        entrada5 = np.array(y)
    else:
        entrada5 = np.vstack((entrada5, y))
    i += 1

print(f'Médias entrada 3: {entrada3.mean(axis=0)}\n')
print(f'Médias entrada 4: {entrada4.mean(axis=0)}\n')
print(f'Médias entrada 5: {entrada5.mean(axis=0)}\n')