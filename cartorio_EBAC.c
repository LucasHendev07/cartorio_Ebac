
#include <stdio.h> //bibloteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço e acentuação em memória
#include <locale.h> //biblioteca para alocação de texto por região
#include <string.h> //Biblioteca responsável por dar vida as springs.




int resgistrar()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];	
	
	printf("Digite o CPF a ser registrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf); //responsável por copiar os valores das strings.
	
	FILE *file; //para criar o arquivo.
	file = fopen(arquivo, "w"); //para abrir o arquivo e definir a criação de novos dados. 
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
		printf("Não foi possível abrir o arquivo, não localizado!! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}	
	
	fclose(file);
	system("pause");
	
}







int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");	
	
	if (file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
	}
	
	fclose(file);
	system("pause");
	
	}
	






int main()//Função principal
{
	
	int opcao=0;//Definindo variáveis
	int laco=1; //Função de laço de repetição
	
	for(laco=1;laco=1;)
	{
	
	
		system("cls");//Comando para iniciar nova tela apartir da opção escolhida
		
		setlocale(LC_ALL, "portuguese");//Definindo linguagem
	
		printf("\t*** Cartório da EBAC ***\n\n");//início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t01 - Registrar nomes\n");
		printf("\t02 - Consultar nomes\n");
		printf("\t03 - Deletar nomes\n\n");
		printf("opção:");//Final do menu
	
		scanf("%d", &opcao);//armazenagem da escolha do usuário
	
		system("cls");//Comando para iniciar nova tela apartir da opção escolhida 
	
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
			printf("Essa opção não está disponivel!\n\n");
			system("pause");
			break;
				
		}//termino da seleção
	
	}
}

