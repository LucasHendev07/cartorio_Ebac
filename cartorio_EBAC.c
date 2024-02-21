
#include <stdio.h> //bibloteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o e acentua��o em mem�ria
#include <locale.h> //biblioteca para aloca��o de texto por regi�o
#include <string.h> //Biblioteca respons�vel por dar vida as springs.




int resgistrar()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];	
	
	printf("Digite o CPF a ser registrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf); //respons�vel por copiar os valores das strings.
	
	FILE *file; //para criar o arquivo.
	file = fopen(arquivo, "w"); //para abrir o arquivo e definir a cria��o de novos dados. 
	fprintf(file,cpf); //para salvar o valor do CPF no arquivo.
	fclose(file); //fechar o arquivo.
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser resgistrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser resgistrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser resgistrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}







int consultar()
{
	
	
	char cpf[40];
	char conteudo[200];
	

	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}	
	
	fclose(file);
	system("pause");
	
}







int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");	
	
	if (file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
	}
	
	fclose(file);
	system("pause");
	
	}
	






int main()//Fun��o principal
{
	
	int opcao=0;//Definindo vari�veis
	int laco=1; //Fun��o de la�o de repeti��o
	
	for(laco=1;laco=1;)
	{
	
	
		system("cls");//Comando para iniciar nova tela apartir da op��o escolhida
		
		setlocale(LC_ALL, "portuguese");//Definindo linguagem
	
		printf("\t*** Cart�rio da EBAC ***\n\n");//in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t01 - Registrar nomes\n");
		printf("\t02 - Consultar nomes\n");
		printf("\t03 - Deletar nomes\n\n");
		printf("op��o:");//Final do menu
	
		scanf("%d", &opcao);//armazenagem da escolha do usu�rio
	
		system("cls");//Comando para iniciar nova tela apartir da op��o escolhida 
	
		switch(opcao)
		{
			case 1:
			resgistrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n\n");
			system("pause");
			break;
				
		}//termino da sele��o
	
	}
}

