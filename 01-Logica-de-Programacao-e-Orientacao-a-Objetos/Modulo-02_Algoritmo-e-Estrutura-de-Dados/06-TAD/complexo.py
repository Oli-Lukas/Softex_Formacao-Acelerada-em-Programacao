class complexo:
  def __init__(self, real, imaginario):
    self.real       = real
    self.imaginario = imaginario
  
  def calcular_tres(self, complexo1, complexo2, complexo3):
    pass

  def conjugado(self):
    return complexo(self.real, -self.imaginario)

  def __neg__(self):
    real_inverso       = -self.real
    imaginario_inverso = -self.imaginario

    resultado = complexo(real_inverso, imaginario_inverso)

    return resultado

  def __str__(self):
    operador = '-' if self.imaginario < 0 else '+'

    if (self.real == 0):
      return '{}i'.format(self.imaginario)
    else:
      return '{} {} {}i'.format(self.real, operador, abs(self.imaginario))
  
  def __add__(self, outro):
    soma_real       = self.real + outro.real
    soma_imaginario = self.imaginario + outro.imaginario
    
    resposta = complexo(soma_real, soma_imaginario)

    if soma_imaginario == 0:
      return soma_real
    else:
      return resposta
  
  def __sub__(self, outro):
    subtracao_real       = self.real - outro.real
    subtracao_imaginario = self.imaginario - outro.imaginario

    resultado = complexo(subtracao_real, subtracao_imaginario)

    if subtracao_imaginario == 0:
      return subtracao_real
    else:
      return resultado
  
  def __mul__(self, outro):
    a = self.real
    b = self.imaginario

    c = outro.real
    d = outro.imaginario

    parte_real       = ((a * c) - (b * d))
    parte_imaginaria = ((a * d) + (c * b))

    resultado = complexo(parte_real, parte_imaginaria)

    if (parte_imaginaria == 0):
      return parte_real
    else:
      return resultado

  def __truediv__(self, outro):
    numerador   = complexo(self.real, self.imaginario) * outro.conjugado()
    denominador = outro * outro.conjugado()

    return complexo((numerador.real / denominador), (numerador.imaginario / denominador))
