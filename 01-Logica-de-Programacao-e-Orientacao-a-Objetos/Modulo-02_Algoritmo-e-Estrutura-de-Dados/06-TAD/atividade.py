#!/bin/python3

# Crie um tipo abstrato de dado (TAD) para manipular números complexos na
# linguagem Python.
# O método deve:
#
# -> calcular três números complexos;
# -> realizar todas as operações básicas;
# -> e imprimir as propriedades real e img do números.

from complexo import *

def main():
  numero_complexo = complexo(10, 5)
  print('Exemplo de número complexo: {}'.format(numero_complexo))

  numero1 = complexo(2, 3)
  numero2 = complexo(1, 2)
  print('Soma de números complexos: {}'.format(numero1 + numero2))

  numero1 = complexo(2, 3)
  numero2 = complexo(1, 2)
  print('Subtração de números complexo: {}'.format(numero1 - numero2))

  numero1 = complexo(2, 3)
  numero2 = complexo(1, -4)
  print('Multiplicação de números complexos: {}'.format(numero1 * numero2))

  numero1 = complexo(6, -4)
  numero2 = complexo(4, 2)
  print('Divisão de números complexos: {}'.format(numero1 / numero2))


if __name__ == '__main__':
  main()
