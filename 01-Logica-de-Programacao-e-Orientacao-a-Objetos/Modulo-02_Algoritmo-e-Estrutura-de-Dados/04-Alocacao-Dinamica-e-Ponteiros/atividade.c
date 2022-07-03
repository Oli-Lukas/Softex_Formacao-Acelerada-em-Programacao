/**
 * Crie um vetor com ponteiros utilizando alocação dinâmica na linguagem C, que:
 * 
 * -> use a função realloc;
 * -> use a função sizeof;
 * -> que tenha tamanho 22 de vetor;
 * -> depois libere o bloco utilizando a função free.
 **/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_VETOR 22

int main()
{
  int *ponteiro;

  printf("Alocando um espaco para vetor de %ld bytes...\n", TAMANHO_VETOR * sizeof(int));
  ponteiro = (int *) calloc(TAMANHO_VETOR, sizeof(int));

  printf("Realocando um espaco para vetor de %ld bytes...\n", (TAMANHO_VETOR * 2) * sizeof(int));
  ponteiro = (int *) realloc(ponteiro, (TAMANHO_VETOR * 2) * sizeof(int));

  printf("Liberando espaco na memoria heap...\n");
  free(ponteiro);

  printf("finalizando...\n");
  
  return EXIT_SUCCESS;
}

#undef TAMANHO_VETOR