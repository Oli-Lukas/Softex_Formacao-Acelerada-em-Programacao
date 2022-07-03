/**
 * Faça um algoritmo de ordenação utilizando o método insertion sort.
 * Crie um método que execute as seguintes operações:
 * 
 * -> Tamanho do vetor: 30;
 * -> Utilize números ímpares;
 * -> Opere em ordem crescente.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// -> Tamanho do vetor: 30.
#define TAMANHO_VETOR 30
#define MENOR_VALOR   0
#define MAIOR_VALOR   1000

int  gera_impar();
void popula_vetor(int vetor[]);
void exibe_vetor(int vetor[]);
void insertion_sort(int vetor[]);

int main()
{
  int vetor[TAMANHO_VETOR];

  srand((unsigned int)time(NULL));

  popula_vetor(vetor);
  printf("Vetor gerado  : ");
  exibe_vetor(vetor);

  insertion_sort(vetor);

  printf("Vetor ordenado: ");
  exibe_vetor(vetor);
  
  return EXIT_SUCCESS;
}

// -> Utilize números ímpares.
int gera_impar()
{
  int maior_limite = (MAIOR_VALOR % 2 == 0) ? MAIOR_VALOR - 1 : MAIOR_VALOR;
  int menor_limite = (MENOR_VALOR % 2 == 0) ? MENOR_VALOR + 1 : MENOR_VALOR;
  int numero_gerado;

  numero_gerado = (menor_limite) + rand() % (maior_limite + 1);

  return (numero_gerado % 2 == 0) ? numero_gerado + 1 : numero_gerado;
}

void popula_vetor(int vetor[])
{
  for (int contador = 0; contador < TAMANHO_VETOR; contador++)
    vetor[contador] = gera_impar();
}

void exibe_vetor(int vetor[])
{
  printf("[");
  for (int contador = 0; contador < TAMANHO_VETOR - 1; contador++)
    printf("%d - ", vetor[contador]);
  printf("%d]\n", vetor[TAMANHO_VETOR - 1]);
}

void insertion_sort(int vetor[])
{
  int chave, i, j;

  for (i = 1; i < TAMANHO_VETOR; i++)
  {
    chave = vetor[i];
    j = i - 1;

    // -> Opere em ordem crescente.
    while (j >= 0 && vetor[j] > chave)
    {
      vetor[j + 1] = vetor[j];
      j--;
    }

    vetor[j + 1] = chave;
  }
}

#undef TAMANHO_VETOR
#undef MENOR_VALOR
#undef MAIOR_VALOR