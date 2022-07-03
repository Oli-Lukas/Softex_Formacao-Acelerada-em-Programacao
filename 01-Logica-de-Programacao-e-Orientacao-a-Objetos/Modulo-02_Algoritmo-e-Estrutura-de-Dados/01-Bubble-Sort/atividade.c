/**
 * Construa um algoritmo de ordenação, utilizando o método bubble sort estudado.
 * (Lembre-se que se trata de uma série de instruções que devem ser seguidas
 *  passo a passo).
 * 
 * Para isso, você deve criar um método em que o tamanho do vetor seja dez e
 * deve estar em ordem crescente.
 * 
 * O vetor deverá:
 *  -> comparar seus elementos dois a dois adjacentes;
 *  -> se os elementos não estiverem em ordem, então ordenar;
 *  -> senão, avançar para o próximo par;
 *  -> repetir a operação até que nenhuma troca possa ser feita no vetor inteiro.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define TAMANHO_VETOR 10
#define MENOR_NUMERO  0
#define MAIOR_NUMERO  1000

int  gera_numero();
void popula_vetor(int vetor[]);
void bubble_sort(int vetor[]);
void troca(int vetor[], int *numero1, int *numero2);
void exibe_array(int vetor[]);

int main()
{
  int vetor[TAMANHO_VETOR];

  srand((unsigned int)time(NULL));

  popula_vetor(vetor);
  printf("Vetor gerado  : ");
  exibe_array(vetor);

  bubble_sort(vetor);

  printf("Vetor ordenado: ");
  exibe_array(vetor);
  
  return EXIT_SUCCESS;
}

int gera_numero()
{
  return ((MENOR_NUMERO) + rand() % (MAIOR_NUMERO + 1));
}

void popula_vetor(int vetor[])
{
  for (int contador = 0; contador < TAMANHO_VETOR; contador++)
    vetor[contador] = gera_numero();
}

void bubble_sort(int vetor[])
{
  /** MÉTODO DE ORDENAÇÃO BOLHA **/
  int limite;
  bool trocou;

  limite = TAMANHO_VETOR - 1;
  trocou = false;

  for (int i = 0; i < (TAMANHO_VETOR - 1); i++)
  {
    for (int j = 0; j < limite; j++)
    {
      // -> comparar seus elementos dois a dois adjacentes.
      if (vetor[j] > vetor[j + 1])
      {
        // -> se os elementos não estiverem em ordem, então ordenar.
        troca(vetor, &vetor[j], &vetor[j + 1]);
        trocou = true;
      }
      // -> senão, avançar para o próximo par. 
    }
    
    limite--;
    // -> repetir a operação até que nenhuma troca possa ser feita no vetor inteiro.
    if (!trocou) break;
    else         trocou = false;
  }
}

void troca(int vetor[], int *numero1, int *numero2)
{
  int temporario;

  temporario = *numero1;
  *numero1 = *numero2;
  *numero2 = temporario;
}

void exibe_array(int vetor[])
{
  printf("[");
  for (int contador = 0; contador < TAMANHO_VETOR - 1; contador++)
    printf("%d - ", vetor[contador]);
  printf("%d]", vetor[TAMANHO_VETOR - 1]);

  putchar('\n');
}

#undef TAMANHO_ARRAY
#undef MENOR_NUMERO
#undef MAIOR_NUMERO