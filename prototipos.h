#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	float nota1, nota2, nota3;
}Notas;

typedef struct{
	int mat;
	char nome[20];
	Notas notas;
}Cadastro;

//funcoes do programa
void cadastrar_aluno(Cadastro *ppessoa, FILE *parq);
void exibir_aluno(Cadastro *ppessoa);
void alterar_aluno(Cadastro *ppessoa);
void excluir_aluno(Cadastro *ppessoa);
