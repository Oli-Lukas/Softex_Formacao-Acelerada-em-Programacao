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

#define TAMANHO_ARRAY 10
#define MENOR_NUMERO  0
#define MAIOR_NUMERO  1000

int  gera_numero();
void popula_array(int array[]);
void bubble_sort(int array[]);
void troca(int array[], int *numero1, int *numero2);
void exibe_array(int array[]);

int main()
{
  int array[TAMANHO_ARRAY];

  srand((unsigned int)time(NULL));

  popula_array(array);
  printf("Array gerado  : ");
  exibe_array(array);

  bubble_sort(array);

  printf("Array ordenado: ");
  exibe_array(array);
  
  return EXIT_SUCCESS;
}

int gera_numero()
{
  return ((MENOR_NUMERO) + rand() % (MAIOR_NUMERO + 1));
}

void popula_array(int array[])
{
  for (int contador = 0; contador < TAMANHO_ARRAY; contador++)
    array[contador] = gera_numero();
}

void bubble_sort(int array[])
{
  /** MÉTODO DE ORDENAÇÃO BOLHA **/
  int limite;
  bool trocou;

  limite = TAMANHO_ARRAY - 1;
  trocou = false;

  for (int i = 0; i < (TAMANHO_ARRAY - 1); i++)
  {
    for (int j = 0; j < limite; j++)
    {
      // -> comparar seus elementos dois a dois adjacentes.
      if (array[j] > array[j + 1])
      {
        // -> se os elementos não estiverem em ordem, então ordenar.
        troca(array, &array[j], &array[j + 1]);
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

void troca(int array[], int *numero1, int *numero2)
{
  int temporario;

  temporario = *numero1;
  *numero1 = *numero2;
  *numero2 = temporario;
}

void exibe_array(int array[])
{
  printf("[");
  for (int contador = 0; contador < TAMANHO_ARRAY - 1; contador++)
    printf("%d - ", array[contador]);
  printf("%d]", array[TAMANHO_ARRAY - 1]);

  putchar('\n');
}

#undef TAMANHO_ARRAY
#undef MENOR_NUMERO
#undef MAIOR_NUMERO