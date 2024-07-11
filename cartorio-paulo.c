#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço e memoria
#include <locale.h>  //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cudar das string

int registro() //função responsavel por cadastrar os usuarios no sistema
{
	//inicio  da criação de variaveis/string
	char arquivo[40];// declara uma string com espaço de [40] caracteristicas .
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variaveis ( strings sao fundamentais para a manupilação de texto de qualquer linguagem de programação.)
	printf("Digite seu CPF: "); //coletando informação do usuario
	scanf("%s", cpf); //%s refere-se a string cpf
	
    strcpy(arquivo,cpf); //responsavel por copiar os valores das strings
	
	FILE *file;  //cria o arquivo
	file = fopen(arquivo,"w"); //cria arquivo e o "w" significa escrever. caso conteudo ja existir o anterior sera subsrtituido.
	fprintf(file,cpf); //salva o valor da varial (do que tiver escrito)
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");  //mantem o conteudo  anterior e adiciona novas linhas no final do aquivo.
	fprintf(file,","); // salva o valor da varial
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta a informação e armazena, vai ser lida e armazenada na varialvel fornecida no caso (nome)
	scanf("%s", nome); //refere-se a string (nome)
	
	file = fopen(arquivo, "a");//mantem o conteudo  anterior e adiciona novas linhas no final do aquivo.
	fprintf(file,nome); //salva o valor da variavel (oq tiver escrito)
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");//mantem o conteudo  anterior e adiciona novas linhas no final do aquivo.
	fprintf(file,","); // salvar o valor da variavel ( oq foi escrito)
	fclose(file); // fecha o arquivo 
	
	printf("digite o sobrenome  a ser cadastrado: "); //vai ser lida e armazenada na varialvel fornecida no caso (sobrenome)
	scanf("%s", sobrenome); //refere-se a estring (sobrenome)
	
	file = fopen(arquivo, "a"); //mantem o conteudo  anterior e adiciona novas linhas no final do aquivo.
	fprintf(file,sobrenome); //salva o que foi digitado
	fclose(file); //fecha o arquivo 
	
    file = fopen(arquivo, "a"); // vai abrir o arquivo vai ler e manter o conteudo  anterior e adiciona novas linhas no final do aquivo.
	fprintf(file,","); // salva o valor da variavel (oq foi ecrito)
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coleta a informação e armazena, vai ser lida e armazenada na varialvel fornecida no caso (cargo)
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");//mantem o conteudo  anterior e adiciona novas linhas no final do aquivo.
	fprintf(file,cargo);
	fclose(file);// fecha o arquivo
	
    system("pause"); //fecha a função.( aguarda o usuario dar enter para continuar a execução do programa. obs: Não é portavel para outras plataformas e tbm nao muito seguro, ideal usar o "getchar()"
    
}

 int consultar() //função responsavel por fazer a consulta no sistema.
{
   	setlocale(LC_ALL, "portuguese");//Definindo a linguagem
   	
    char cpf[40]; //declara uma string com [40] caracteres
    char conteudo[200]; //declara uma string com [200] caracteres
 
    printf("digite o cpf a ser consultado: ");//coleta a informação e armazena, vai ser lida e armazenada na varialvel ou string, fornecida no caso (cpf)
    scanf("%s",cpf);//%s refere-se a string cpf
 
    FILE *file; //abre o arquivo file
    file = fopen(cpf,"r"); //vai abrir o arquivo para leitura
    
 if(file==NULL) //quanndo o arquivo nao existir
   {
 	printf("Não foi possivel abrir o arquivo, nao localizado!.\n");   
   }
   
    while(fgets(conteudo, 200, file) !=NULL) //while ver ler até o final do aquivo, fgets le as linhas armazenadas, !=NULL verifica se deu certo, caso nao encontre nada ou ele chegou no final no arquivo ou erro na leitura.
    {
    printf("\nEssas são as informações do usuario: ");
    printf("%s", conteudo); 
    printf("\n\n\n");// representa uma nova linha cada (\n)
	}
	
	system("pause");
	fclose(file);// fecha o arquivo
}

int deletar() //funçao responsavel por deletar o usuario do sistema.
{
  char cpf[40];
  
   printf("Digite o cpf a ser deletado: ");
   scanf("%s", cpf);
  
  remove(cpf); // remove a variavel do sistema no caso (cpf)
  
  FILE *file;
  file = fopen(cpf,"r");
  
  if(file == NULL)//quanndo o arquivo nao existir
  {
  	printf(" O usuario não se encontra no sistema!.\n");
  	system("pause");
  }
	fclose(file);// fecha o arquivo
}

int main() //função  responsavel por cordenar todas as operações que o programa realiza.
    {
	int opcao=0; //Definindo variaveis
	int laco=1; 
	
		for(laco=1;laco=1;) //o programa sempre volta para o inicio. obs: nao tem fim.
    {
	   
	   system("cls");//responsavel por limpar a tela
	
    	setlocale(LC_ALL, "portuguese");//Definindo a linguagem
	
    	printf("### cartório da EBAC ###\n\n"); //Inicio do menu
    	printf("escolha a opção desejada de menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - consultar nomes\n");
    	printf("\t3 - deletar nomes\n\n");
    	printf("\t4 - sair do sistema\n\n");
        printf("Opção:"); //Fim do menu
 
       scanf("%d", &opcao); //Armazenando a escolha do Usuario

       system("cls"); //responsavel por limpar a tela 
       
       switch(opcao) //inicio da seleção de menu
      {
      	   case 1:
	      registro(); //chamada de função
	      break; //sai do loop apos executar esse bloco.
	      
	      case 2:
	      consultar(); //chamada de função
    	  break;//sai do loop apos executar esse bloco.
    	  
    	  case 3:
       	  deletar(); //chamada de função
       	  break;//sai do loop apos executar esse bloco.
          
          case 4:
          printf("obrigado por utilizar o nosso sistema!\n");
		  return 0;
		  break;	
          
       	  default: // codigo executado se nao corresponder a nenhuma das funções ou opções existentes.
          printf(" essa opção nao está disponivel!\n");
          system("pause");
          break;  //sai do loop apos executar esse bloco.
	    }
   }
}












