# -*- coding: utf-8 -*-

'''
Iván Rodríguez - 2017
Código generado para el canal de YouTube Piensa 3D
'''

# Importamos los módulos necesarios
from math import pi
from math import log10
import numpy as np
from matplotlib import pyplot as plt


# Código de cálculos y entrada
print("Bienvenido a la graficadora de transferencias")
r = float(input("Ingrese el valor de resistencia (en ohms): "))
c = float(input("Ingrese el valor de capacitor (en microfaradios): "))
c = float(c*0.000001)
f_low = int(input("Ingrese el piso de frecuencia (en Hz): "))
f_high = int(input("Ingrese el techo de frecuencia (en Hz): "))
fc_x = 1/(2*pi*r*c)
fc_y = 10*log10(1/(2*pi*fc_x*r*c+1))

# Generamos los datos para el gráfico
x = np.array(range(f_low, f_high))
y = np.zeros(len(x))
for i in range(len(x)):
    y[i] = 10*log10(1/(2*pi*(x[i])*r*c+1))
print("La frecuencia de corte, representada con rojo en el gráfico, se encuentra en f = ", fc_x, "Hz")


# Creamos el gráfico
plt.grid(color='k', linestyle='--', linewidth=0.5)
plt.title("Transferencia en función de frecuencia", loc = 'left')
plt.xlabel("Frecuencia (Hz)")
plt.ylabel("Transferencia (dB)")
plt.xscale("log")
plt.plot(x,y)
plt.scatter(x=fc_x, y=fc_y, c = "red")
#plt.vlines(x=fc_x, ymin=y[f_high], ymax=fc_y, colors='k',linestyles='dashed')
#plt.hlines(y=fc_y, xmin=0, xmax=fc_x, colors='k',linestyles='dashed')
plt.show(block=1)