/**
 * Após uma prova de vestibular, uma escola quer identificar quantos dos seus
 * alunos foram aprovados em cada turma de formandos. Ela quer saber qual aluno
 * teve a maior nota e de qual turma ele é. Nessa escola, há quatro turmas
 * (A, B, C e D) com vinte e cinco alunos cada.
 * 
 * Elabore um algoritmo que solicite o nome e a nota do vestibular aos alunos.
 * Depois, informe quantos deles foram aprovados, de que turma são, qual a maior
 * nota de todas.
 * 
 * Para que o aluno seja aprovado no vestibular, ele deverá obter nota maior ou
 * igual a 7.
 * 
 * ATENÇÃO: As notas por turma não podem se repetir.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAMANHO_TURMA 1
#define TAMANHO_NOME  50
#define TOTAL_ALUNOS  (TAMANHO_TURMA * 4)

typedef struct
{
  char  nome[TAMANHO_NOME];
  float nota;
}Aluno;

typedef struct
{
  Aluno alunos[TAMANHO_TURMA];
  int   quantidade;
}Turma;

void clean_stdin();
void ler_aluno(Aluno *aluno);
bool eh_aluno_aprovado(Aluno aluno);
bool permite_aluno(Turma t, Aluno aluno);
void exibe_turma(Turma t, const char *turma_titulo);

int main()
{
  Aluno alunos[TOTAL_ALUNOS];
  Turma turma_a, turma_b, turma_c, turma_d;
  int   quantidade_aprovados;

  turma_a = (Turma) {.quantidade = 0};
  turma_b = (Turma) {.quantidade = 0};
  turma_c = (Turma) {.quantidade = 0};
  turma_d = (Turma) {.quantidade = 0};

  quantidade_aprovados = 0;

  printf("\t\tAtividade 09\n");
  printf("\t\t######### ##\n\n");

  for (int contador = 0; contador < TOTAL_ALUNOS; contador++)
  {
    printf("%d)\n", contador+1);
    ler_aluno(&alunos[contador]);

    if (eh_aluno_aprovado(alunos[contador]))
    {
      quantidade_aprovados++;

      /** Aloca aluno em uma turma. **/
      if (permite_aluno(turma_a, alunos[contador]))
        turma_a.alunos[turma_a.quantidade++] = alunos[contador];
      else if (permite_aluno(turma_b, alunos[contador]))
        turma_b.alunos[turma_b.quantidade++] = alunos[contador];
      else if (permite_aluno(turma_c, alunos[contador]))
        turma_c.alunos[turma_c.quantidade++] = alunos[contador];
      else
        turma_d.alunos[turma_d.quantidade++] = alunos[contador];
    }
  }

  exibe_turma(turma_a, "Turma A");

  return EXIT_SUCCESS;
}

void clean_stdin()
{
  char c;

  do
  {
    c = getchar();
  }
  while (c != '\n' && c != EOF);
}
    
void ler_aluno(Aluno *aluno)
{
  printf("Digite o nome do aluno: ");
  fgets(aluno->nome, sizeof(char) * TAMANHO_NOME, stdin);
  aluno->nome[strcspn(aluno->nome, "\n")] = '\0';

  printf("Nota de %s: ", aluno->nome);
  scanf("%f", &aluno->nota);

  clean_stdin();
}

bool eh_aluno_aprovado(Aluno aluno)
{
  return (aluno.nota >= 7) ? true : false;
}

bool permite_aluno(Turma t, Aluno aluno)
{
  for (int contador = 0; contador < t.quantidade; contador++)
    if (t.alunos[contador].nota == aluno.nota)
      return false;

  return true;
}

void exibe_turma(Turma t, const char *turma_titulo)
{
  printf("\t\t%s\n\n", turma_titulo);

  for (int contador = 0; contador < t.quantidade; contador++)
  {
    printf("\tAluno: %s\n", t.alunos[contador].nome);
    printf("\tNota : %.2f\n\n", t.alunos[contador].nota);
  }

  printf("\t##########\n\n");
}

#undef TAMANHO_TURMA
#undef TAMANHO_NOME
#undef TOTAL_ALUNOS