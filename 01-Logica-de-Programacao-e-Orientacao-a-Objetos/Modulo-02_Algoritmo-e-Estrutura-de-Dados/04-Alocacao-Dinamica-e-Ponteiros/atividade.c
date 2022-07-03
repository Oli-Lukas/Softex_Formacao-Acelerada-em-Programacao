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

void preenche_vetor(int *ptr_vetor);
void exibe_vetor(int *ptr_vetor);

int main()
{
  int *ponteiro;

  printf("Alocando um espaco para vetor de %ld bytes...\n", TAMANHO_VETOR * sizeof(int));
  ponteiro = (int *) realloc(NULL, TAMANHO_VETOR * sizeof(int));

  if (ponteiro == NULL) {
    printf("Memoria nao disponivel!\n");
    printf("Saindo...\n");

    return EXIT_FAILURE;
  }

  preenche_vetor(ponteiro);
  exibe_vetor(ponteiro);

  printf("Liberando espaco na memoria heap...\n");
  free(ponteiro);

  printf("finalizando...\n");
  
  return EXIT_SUCCESS;
}

void preenche_vetor(int *ptr_vetor)
{
  for (int contador = 0; contador < TAMANHO_VETOR; contador++)
  {
    printf("Digite um numero para a posicao %d do vetor: ", contador + 1);
    scanf("%d", &ptr_vetor[contador]);
  }
}

void exibe_vetor(int *ptr_vetor)
{
  for (int contador = 0; contador < TAMANHO_VETOR; contador++)
    printf("Elemento %d --> %d\n", contador + 1, ptr_vetor[contador]);
}

#undef TAMANHO_VETOR