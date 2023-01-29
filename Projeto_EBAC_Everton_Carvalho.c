#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocaçõeo de espaço em memmoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string
		
int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: \n");
	scanf("%s", cpf);
		
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado \n");
	scanf("%s",nome);
		
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"_");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado \n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado \n");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
    system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado! \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!. \n");
	}
	
	printf("\nEssas são as informações do usuario: \n\n");
	
	while(fgets( conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n");
	}
			
	system("pause");
	
}

int deletar() // função para deletar usuário do sistema
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if (file == NULL);
	{
		printf("O usuário não se encontra no sistema!. \n");
		system("pause");
	}
		
}

int main()
	{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuÃ¡rio
		
		system("cls");
	
		switch(opcao) //inicio da seleÃ§Ã£o
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
		
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		} //fim da seleção.
			
	}	
}
