#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória e comandos de sistema
#include <locale.h> // Biblioteca de configurações de localização e idioma
#include <string.h> // Biblioteca responsável por manipulação de strings

// Função para registrar um novo usuário no sistema
int registro() 
{
	char arquivo[40]; // Variável para armazenar o nome do arquivo
	char cpf[40]; // Variável para armazenar o CPF
	char nome[40]; // Variável para armazenar o nome
	char sobrenome[40]; // Variável para armazenar o sobrenome
	char cargo[40]; // Variável para armazenar o cargo
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // Lê o CPF do usuário
	
	strcpy(arquivo, cpf); // Copia o CPF para a variável 'arquivo', que será usada como nome do arquivo
	
	FILE *file; // Declara o ponteiro para o arquivo
	file = fopen(arquivo, "w"); // Cria erquivo para escrita
	fprintf(file, "%s", cpf); // Salva o CPF no arqu abre o aivo
	fclose(file); // Fecha o arquivo após a escrita
	
	// Adiciona o campo "Nome" ao arquivo
	file = fopen(arquivo, "a"); // Abre o arquivo no modo append (acrescentar)
	fprintf(file, "\n Nome:"); // Escreve o rótulo "Nome:" no arquivo
	fclose(file); // Fecha o arquivo
	
	// Solicita o nome do usuário e o adiciona ao arquivo
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); // Salva o nome no arquivo
	fclose(file);
	
	// Adiciona o campo "Sobrenome" ao arquivo
	file = fopen(arquivo, "a");
	fprintf(file, "\n Sobrenome:");
	fclose(file);
	
	// Solicita o sobrenome do usuário e o adiciona ao arquivo
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome); // Salva o sobrenome no arquivo
	fclose(file);
	
	// Adiciona o campo "Cargo" ao arquivo
	file = fopen(arquivo, "a");
	fprintf(file, "\n Cargo:");
	fclose(file);
	
	// Solicita o cargo do usuário e o adiciona ao arquivo
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo); // Salva o cargo no arquivo
	fclose(file);
	
	system("pause"); // Pausa o programa para o usuário visualizar a mensagem
}

// Função para consultar as informações de um usuário registrado
int consulta()
{
	setlocale(LC_ALL,"Portuguese"); // Define o idioma como Português
	
	char cpf[40]; // Variável para armazenar o CPF a ser consultado
	char conteudo[200]; // Buffer para armazenar o conteúdo do arquivo
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); // Lê o CPF do usuário
	
	FILE *file;
	file = fopen(cpf, "r"); // Abre o arquivo para leitura com o nome do CPF
	
	if (file == NULL) // Verifica se o arquivo foi encontrado
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
		system("pause");
		return 0; // Retorna ao menu
	
	}
	
	printf("Essas são as informações do usuário: \n\n CPF:");
	
	while (fgets(conteudo, 200, file) != NULL) // Lê cada linha do arquivo até o final
	{
		printf("%s", conteudo); // Imprime o conteúdo lido na tela
		printf("\n\n"); // Quebra de linha para formatação
	}
	system("pause"); // Pausa para o usuário visualizar as informações
}	

// Função para deletar o registro de um usuário do sistema
int deletar()
{
	char cpf[40]; // Variável para armazenar o CPF a ser deletado
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s", cpf); // Lê o CPF do usuário
	
	if (remove(cpf) == 0) // Tenta deletar o arquivo com o nome do CPF
	{
		printf("O usuário foi deletado com sucesso!\n"); // Confirmação de exclusão bem-sucedida
	} 
	else 
	{
		printf("Erro ao deletar o usuário. Usuário não se encontra no sistema!\n"); // Mensagem de erro se o arquivo não for encontrado
	}

	system("pause"); // Pausa para o usuário visualizar a mensagem
}

// Função principal, responsável pelo menu e navegação entre as opções
int main()
{
	int opcao = 0; // Variável para armazenar a escolha do usuário no menu
	int x = 1; // Variável de controle do loop do menu
	
	for (x = 1; x = 1;) // Loop infinito para exibir o menu
	{
		system("cls"); // Limpa a tela
		
		setlocale(LC_ALL,"Portuguese"); // Define o idioma como Português
		
		printf("### Cartório da EBAC ###\n\n"); // Título do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n"); 
		printf("Opção: "); // Solicita uma opção do usuário
		
		scanf("%d", &opcao); // Lê a escolha do usuário
		
		system("cls"); // Limpa a tela
		
		switch(opcao) // Verifica qual opção foi escolhida
		{
			case 1:
				registro(); // Chama a função de registro
				break;
			
			case 2:
				consulta(); // Chama a função de consulta
				break;
			
			case 3:
				deletar(); // Chama a função de deletar
				break;
			
			default:
				printf("Essa opção não está disponível!\n"); // Mensagem de erro para opções inválidas
				system("pause");
				break;
		} // Fim do switch
	}
}

