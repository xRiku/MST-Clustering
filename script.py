#!/usr/bin/env python3
from decimal import Decimal
import os
import numpy as np
import subprocess

x = np.array([])
i = 0
while i < 10:
    aux = subprocess.run(['./trab1', './entradas/5.txt', '10', './saidas/5.txt'], stdout=subprocess.PIPE, universal_newlines=True)
    y = aux.stdout
    y = y.split('\n')
    y = [Decimal(j)*1000 for j in y]
    # print(y)
    if i == 0:
        x = np.array(y)
    else:
        x = np.vstack((x, y))
    i += 1

print(f'Mean: {x.mean(axis=0)}')