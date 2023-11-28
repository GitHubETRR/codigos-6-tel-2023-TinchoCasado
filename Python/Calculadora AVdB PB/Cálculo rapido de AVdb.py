import math

#Ingreso de datos
fc = float(input("Ingrese la frecuencia de corte: "))
f = float(input("Ingrese la frecuencia a analizar: "))

#Cálculo en veces
resultado = (1/(math.sqrt(1+(f/fc)**2)))
print("El resultado es: ", resultado, "veces | Para una fc:", fc, "y una f:", f)

#Cálculo en decibeles
resultado = 20*math.log10(1/(math.sqrt(1+(f/fc)**2)))
print("El resultado es: ", resultado, "dB | Para una fc:", fc, "y una f:", f)

#Cálculo angular
resultado = -1*math.degrees(math.atan(f/fc))
print("El resultado es: ", resultado, " | Para una fc:", fc, "y una f:", f)