#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria e comandos de sistema
#include <locale.h> // Biblioteca de configura��es de localiza��o e idioma
#include <string.h> // Biblioteca respons�vel por manipula��o de strings

// Fun��o para registrar um novo usu�rio no sistema
int registro() 
{
	char arquivo[40]; // Vari�vel para armazenar o nome do arquivo
	char cpf[40]; // Vari�vel para armazenar o CPF
	char nome[40]; // Vari�vel para armazenar o nome
	char sobrenome[40]; // Vari�vel para armazenar o sobrenome
	char cargo[40]; // Vari�vel para armazenar o cargo
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // L� o CPF do usu�rio
	
	strcpy(arquivo, cpf); // Copia o CPF para a vari�vel 'arquivo', que ser� usada como nome do arquivo
	
	FILE *file; // Declara o ponteiro para o arquivo
	file = fopen(arquivo, "w"); // Cria erquivo para escrita
	fprintf(file, "%s", cpf); // Salva o CPF no arqu abre o aivo
	fclose(file); // Fecha o arquivo ap�s a escrita
	
	// Adiciona o campo "Nome" ao arquivo
	file = fopen(arquivo, "a"); // Abre o arquivo no modo append (acrescentar)
	fprintf(file, "\n Nome:"); // Escreve o r�tulo "Nome:" no arquivo
	fclose(file); // Fecha o arquivo
	
	// Solicita o nome do usu�rio e o adiciona ao arquivo
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); // Salva o nome no arquivo
	fclose(file);
	
	// Adiciona o campo "Sobrenome" ao arquivo
	file = fopen(arquivo, "a");
	fprintf(file, "\n Sobrenome:");
	fclose(file);
	
	// Solicita o sobrenome do usu�rio e o adiciona ao arquivo
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome); // Salva o sobrenome no arquivo
	fclose(file);
	
	// Adiciona o campo "Cargo" ao arquivo
	file = fopen(arquivo, "a");
	fprintf(file, "\n Cargo:");
	fclose(file);
	
	// Solicita o cargo do usu�rio e o adiciona ao arquivo
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo); // Salva o cargo no arquivo
	fclose(file);
	
	system("pause"); // Pausa o programa para o usu�rio visualizar a mensagem
}

// Fun��o para consultar as informa��es de um usu�rio registrado
int consulta()
{
	setlocale(LC_ALL,"Portuguese"); // Define o idioma como Portugu�s
	
	char cpf[40]; // Vari�vel para armazenar o CPF a ser consultado
	char conteudo[200]; // Buffer para armazenar o conte�do do arquivo
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); // L� o CPF do usu�rio
	
	FILE *file;
	file = fopen(cpf, "r"); // Abre o arquivo para leitura com o nome do CPF
	
	if (file == NULL) // Verifica se o arquivo foi encontrado
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
		system("pause");
		return 0; // Retorna ao menu
	
	}
	
	printf("Essas s�o as informa��es do usu�rio: \n\n CPF:");
	
	while (fgets(conteudo, 200, file) != NULL) // L� cada linha do arquivo at� o final
	{
		printf("%s", conteudo); // Imprime o conte�do lido na tela
		printf("\n\n"); // Quebra de linha para formata��o
	}
	system("pause"); // Pausa para o usu�rio visualizar as informa��es
}	

// Fun��o para deletar o registro de um usu�rio do sistema
int deletar()
{
	char cpf[40]; // Vari�vel para armazenar o CPF a ser deletado
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s", cpf); // L� o CPF do usu�rio
	
	if (remove(cpf) == 0) // Tenta deletar o arquivo com o nome do CPF
	{
		printf("O usu�rio foi deletado com sucesso!\n"); // Confirma��o de exclus�o bem-sucedida
	} 
	else 
	{
		printf("Erro ao deletar o usu�rio. Usu�rio n�o se encontra no sistema!\n"); // Mensagem de erro se o arquivo n�o for encontrado
	}

	system("pause"); // Pausa para o usu�rio visualizar a mensagem
}

// Fun��o principal, respons�vel pelo menu e navega��o entre as op��es
int main()
{
	int opcao = 0; // Vari�vel para armazenar a escolha do usu�rio no menu
	int x = 1; // Vari�vel de controle do loop do menu
	
	for (x = 1; x = 1;) // Loop infinito para exibir o menu
	{
		system("cls"); // Limpa a tela
		
		setlocale(LC_ALL,"Portuguese"); // Define o idioma como Portugu�s
		
		printf("### Cart�rio da EBAC ###\n\n"); // T�tulo do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n"); 
		printf("Op��o: "); // Solicita uma op��o do usu�rio
		
		scanf("%d", &opcao); // L� a escolha do usu�rio
		
		system("cls"); // Limpa a tela
		
		switch(opcao) // Verifica qual op��o foi escolhida
		{
			case 1:
				registro(); // Chama a fun��o de registro
				break;
			
			case 2:
				consulta(); // Chama a fun��o de consulta
				break;
			
			case 3:
				deletar(); // Chama a fun��o de deletar
				break;
			
			default:
				printf("Essa op��o n�o est� dispon�vel!\n"); // Mensagem de erro para op��es inv�lidas
				system("pause");
				break;
		} // Fim do switch
	}
}

