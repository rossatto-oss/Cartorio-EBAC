#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o e memoria
#include <locale.h>  //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cudar das string

int registro() //fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio  da cria��o de variaveis/string
	char arquivo[40];// declara uma string com espa�o de [40] caracteristicas .
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de variaveis ( strings sao fundamentais para a manupila��o de texto de qualquer linguagem de programa��o.)
	printf("Digite seu CPF: "); //coletando informa��o do usuario
	scanf("%s", cpf); //%s refere-se a string cpf
	
    strcpy(arquivo,cpf); //responsavel por copiar os valores das strings
	
	FILE *file;  //cria o arquivo
	file = fopen(arquivo,"w"); //cria arquivo e o "w" significa escrever. caso conteudo ja existir o anterior sera subsrtituido.
	fprintf(file,cpf); //salva o valor da varial (do que tiver escrito)
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");  //mantem o conteudo  anterior e adiciona novas linhas no final do aquivo.
	fprintf(file,","); // salva o valor da varial
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta a informa��o e armazena, vai ser lida e armazenada na varialvel fornecida no caso (nome)
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
	
	printf("Digite o cargo a ser cadastrado: ");//coleta a informa��o e armazena, vai ser lida e armazenada na varialvel fornecida no caso (cargo)
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");//mantem o conteudo  anterior e adiciona novas linhas no final do aquivo.
	fprintf(file,cargo);
	fclose(file);// fecha o arquivo
	
    system("pause"); //fecha a fun��o.( aguarda o usuario dar enter para continuar a execu��o do programa. obs: N�o � portavel para outras plataformas e tbm nao muito seguro, ideal usar o "getchar()"
    
}

 int consultar() //fun��o responsavel por fazer a consulta no sistema.
{
   	setlocale(LC_ALL, "portuguese");//Definindo a linguagem
   	
    char cpf[40]; //declara uma string com [40] caracteres
    char conteudo[200]; //declara uma string com [200] caracteres
 
    printf("digite o cpf a ser consultado: ");//coleta a informa��o e armazena, vai ser lida e armazenada na varialvel ou string, fornecida no caso (cpf)
    scanf("%s",cpf);//%s refere-se a string cpf
 
    FILE *file; //abre o arquivo file
    file = fopen(cpf,"r"); //vai abrir o arquivo para leitura
    
 if(file==NULL) //quanndo o arquivo nao existir
   {
 	printf("N�o foi possivel abrir o arquivo, nao localizado!.\n");   
   }
   
    while(fgets(conteudo, 200, file) !=NULL) //while ver ler at� o final do aquivo, fgets le as linhas armazenadas, !=NULL verifica se deu certo, caso nao encontre nada ou ele chegou no final no arquivo ou erro na leitura.
    {
    printf("\nEssas s�o as informa��es do usuario: ");
    printf("%s", conteudo); 
    printf("\n\n\n");// representa uma nova linha cada (\n)
	}
	
	system("pause");
	fclose(file);// fecha o arquivo
}

int deletar() //fun�ao responsavel por deletar o usuario do sistema.
{
  char cpf[40];
  
   printf("Digite o cpf a ser deletado: ");
   scanf("%s", cpf);
  
  remove(cpf); // remove a variavel do sistema no caso (cpf)
  
  FILE *file;
  file = fopen(cpf,"r");
  
  if(file == NULL)//quanndo o arquivo nao existir
  {
  	printf(" O usuario n�o se encontra no sistema!.\n");
  	system("pause");
  }
	fclose(file);// fecha o arquivo
}

int main() //fun��o  responsavel por cordenar todas as opera��es que o programa realiza.
    {
	int opcao=0; //Definindo variaveis
	int laco=1; 
	
		for(laco=1;laco=1;) //o programa sempre volta para o inicio. obs: nao tem fim.
    {
	   
	   system("cls");//responsavel por limpar a tela
	
    	setlocale(LC_ALL, "portuguese");//Definindo a linguagem
	
    	printf("### cart�rio da EBAC ###\n\n"); //Inicio do menu
    	printf("escolha a op��o desejada de menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - consultar nomes\n");
    	printf("\t3 - deletar nomes\n\n");
    	printf("\t4 - sair do sistema\n\n");
        printf("Op��o:"); //Fim do menu
 
       scanf("%d", &opcao); //Armazenando a escolha do Usuario

       system("cls"); //responsavel por limpar a tela 
       
       switch(opcao) //inicio da sele��o de menu
      {
      	   case 1:
	      registro(); //chamada de fun��o
	      break; //sai do loop apos executar esse bloco.
	      
	      case 2:
	      consultar(); //chamada de fun��o
    	  break;//sai do loop apos executar esse bloco.
    	  
    	  case 3:
       	  deletar(); //chamada de fun��o
       	  break;//sai do loop apos executar esse bloco.
          
          case 4:
          printf("obrigado por utilizar o nosso sistema!\n");
		  return 0;
		  break;	
          
       	  default: // codigo executado se nao corresponder a nenhuma das fun��es ou op��es existentes.
          printf(" essa op��o nao est� disponivel!\n");
          system("pause");
          break;  //sai do loop apos executar esse bloco.
	    }
   }
}












