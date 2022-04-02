#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int main(){
	
	FILE *parq;//variavel para usar o arquivo
	Cadastro pessoa[2];//chamada da struct em vetor
  	Cadastro *ppessoa;//struct como ponteiro
  	int op;

  	ppessoa = pessoa;//apontando para o endereço de memoria da struct vetor principal

	//alocando a memoria 
	ppessoa = (Cadastro *) malloc(2*(sizeof(Cadastro)));
	
	//abrindo o arquivo
	parq = fopen("Arquivo_Escola.txt","w");
	
	if(parq==NULL){
		printf("Erro na abertura do arquivo!");
		exit(1);
	}
	
	if(ppessoa==NULL){
		printf("ERRO na memória!!\n");
		exit(1);
	}

  	//menu do programa
  	do{
    	printf("Digite uma opção:\n");
    	printf("\t[1]-Cadastrar\n");
		printf("\t[2]-Exibir:\n");
		printf("\t[3]-Alterar:\n");
		printf("\t[4]-Excluir:\n");
		printf("\t[5]-Sair:\n");
    	scanf("%d", &op);//lê a opcao desejada

		system("cls");
		
    	//chamada das funcoes
    	switch(op){
      		case 1:
        		cadastrar_aluno(pessoa, parq);
      		break;
      		case 2:
        		exibir_aluno(pessoa);
      		break;
      		case 3:
      			alterar_aluno(pessoa);
      		break;
      		case 4:
        		excluir_aluno(pessoa);
      		break;
      		case 5:
        		printf("Saindo\n...");
      		break;
    }
    
  	}while(op<=4);
	
	//liberando a memoria
	free(ppessoa);
	//fazendo o EOF
	while(1){
		fprintf(parq,"\n");
		if(feof(parq)){
			break;
		}
	}
	fclose(parq);//fechando o arquivo
	
	return 0;
}

//funcao para cadastrar
void cadastrar_aluno(Cadastro *ppessoa, FILE *parq){

	int i;
	
  	for(i=0; i<2; i++){
 		printf("Digite sua matricula:\n");
		scanf("%d", &ppessoa->mat);
	
		printf("Digite seu nome:\n");
		scanf(" %[^\n]", ppessoa->nome);
	
		printf("Digite a primeira nota:\n");
		scanf("%f", &ppessoa->notas.nota1);
	
		printf("Digite a segunda nota:\n");
		scanf("%f", &ppessoa->notas.nota2);
	
		printf("Digite a primeira nota:\n");
		scanf("%f", &ppessoa->notas.nota3);
		ppessoa++;
  	}
  	
  	fprintf(parq,"\t----Dados----\n");
  	for(i=0; i<2; i++){
  		fprintf(parq,"Matricula: %d\n", ppessoa->mat);
  		fprintf(parq,"Nome: %s\n", ppessoa->nome);
  		fprintf(parq,"Nota 1: %.1f\n", ppessoa->notas.nota1);
  		fprintf(parq,"Nota 2: %.1f\n", ppessoa->notas.nota2);
  		fprintf(parq,"Nota 3: %.1f\n", ppessoa->notas.nota3);
  		fprintf(parq,"\n");
  		ppessoa++;
	  }
  	
  	system("cls");
}

//funcao para exibir
void exibir_aluno(Cadastro *ppessoa){

	int i;
  	printf("----Dados dos alunos:----\n");
  	
  	for(i=0; i<2; i++){
   		printf("\n");
		printf("\tMatricula: %d\n", ppessoa->mat);
		printf("\tNome: %s\n", ppessoa->nome);
		printf("\tPrimeira nota: %.1f\n", ppessoa->notas.nota1);
  		printf("\tSegunda nota: %.1f\n", ppessoa->notas.nota2);
		printf("\tTerceira nota: %.1f\n", ppessoa->notas.nota3);
		ppessoa++;
  }
  
}

//funcao para alterar
void alterar_aluno(Cadastro *ppessoa){
	
	int i;
	char altera[20];
	
	printf("Digite o nome do aluno para editar:\n");
	scanf("%s", altera);
	
	for(i=0;i<2;i++){
		if(strcmp(ppessoa->nome,altera)==0){
			printf("Digite sua matricula:\n");
			scanf("%d", &ppessoa->mat);
	
			printf("Digite seu nome:\n");
			scanf(" %[^\n]", ppessoa->nome);
	
			printf("Digite a primeira nota:\n");
			scanf("%f", &ppessoa->notas.nota1);
	
			printf("Digite a segunda nota:\n");
			scanf("%f", &ppessoa->notas.nota2);
	
			printf("Digite a primeira nota:\n");
			scanf("%f", &ppessoa->notas.nota3);
		}
	}
	
}

//funcao para excluir
void excluir_aluno(Cadastro *ppessoa){
	
	int i;
  	char nome_aluno[20];//variavel para escolher o aluno a ser exclcuido

  	printf("Digite o nome do aluno para excluir:\n");
  	scanf(" %[^\n]", nome_aluno);//pegando o nome do aluno

  	for(i=0; i<=2; i++){
  		/*
    		se o strcmp retornar 0 é por que as strings são iguais,
    		assim se a condição for verdadeira 
			entra na estrutura if e faz a excluão
    	*/
    	if(strcmp(ppessoa[i].nome,nome_aluno)==0){//funcao para comparar as strings
    		ppessoa[i] = ppessoa[i-2];//exclusao
     	}
  	}
  
 }
