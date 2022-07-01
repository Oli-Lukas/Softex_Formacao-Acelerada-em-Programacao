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

#define TAMANHO_TURMA 25
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
bool valida_nota(float nota);
bool eh_aluno_aprovado(Aluno aluno);
bool permite_aluno_turma(Turma t, Aluno aluno);
bool turma_cheia(Turma t);
bool turma_contem_nota(Turma t, float nota_alvo);
void adiciona_aluno_turma(Turma *t, Aluno aluno);
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
    printf("\t%d)\n", contador+1);
    ler_aluno(&alunos[contador]);

    if (eh_aluno_aprovado(alunos[contador]))
    {
      quantidade_aprovados++;

      /** Adiciona aluno em uma turma. **/
      if      (permite_aluno_turma(turma_a, alunos[contador]))     adiciona_aluno_turma(&turma_a, alunos[contador]);
      else if (permite_aluno_turma(turma_b, alunos[contador]))     adiciona_aluno_turma(&turma_b, alunos[contador]);
      else if (permite_aluno_turma(turma_c, alunos[contador]))     adiciona_aluno_turma(&turma_c, alunos[contador]);
      else if (!turma_cheia(turma_d))                              adiciona_aluno_turma(&turma_d, alunos[contador]);
    }
  }

  exibe_turma(turma_a, "Turma A");
  exibe_turma(turma_b, "Turma B");
  exibe_turma(turma_c, "Turma C");
  exibe_turma(turma_d, "Turma D");

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
  printf("\tDigite o nome do aluno: ");
  fgets(aluno->nome, sizeof(char) * TAMANHO_NOME, stdin);
  aluno->nome[strcspn(aluno->nome, "\n")] = '\0';

  do
  {
    printf("\tNota de %s: ", aluno->nome);
    scanf("%f", &aluno->nota);

    if (!valida_nota(aluno->nota))
    {
      printf("\tNota invalida!\n");
      printf("\tPor favor! Digite uma nota no intervalo [0.00-10.00].\n");
    }
  }
  while(!valida_nota(aluno->nota));

  clean_stdin();
}

bool valida_nota(float nota)
{
  return (nota >= 0 && nota <= 10);
}

bool eh_aluno_aprovado(Aluno aluno)
{
  return (aluno.nota >= 7) ? true : false;
}

bool permite_aluno_turma(Turma t, Aluno aluno)
{
  /** Se a turma estiver cheia retornar 'false'. **/
  if (turma_cheia(t)) return false;

  /** Se houver aluno com mesma nota retornar 'false'. **/
  if (turma_contem_nota(t, aluno.nota)) return false;

  return true;
}

bool turma_cheia(Turma t)
{
  return (t.quantidade >= TAMANHO_TURMA) ? true : false;
}

bool turma_contem_nota(Turma t, float nota_alvo)
{
  for (int contador = 0; contador < TAMANHO_TURMA; contador++)
    if (t.alunos[contador].nota == nota_alvo)
      return true;
  
  return false;
}

void adiciona_aluno_turma(Turma *t, Aluno aluno)
{
  t->alunos[t->quantidade++] = aluno;
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