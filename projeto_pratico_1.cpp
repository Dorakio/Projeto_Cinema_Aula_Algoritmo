//Nome: Beatriz Rodrigues Monteiro
//Matrícula: 20100019
//Curso: Ciência da computação

//Objetivo: Criar um algoritmo para descobrir o perfil dos usúarios que frequentam o cinema de Brasília
//Entrada: Número de sessões, nome do filme, quantidade de pessoas, gênero e idade de cada pessoa.
//Saída: Nome do filme, a quantidade de pessoas do sexo feminino e a quantidade de pessoas do sexo masculino que assistiram ao filme. 
//A quantidade de pessoas, seguindo a classificação por idade
//A quantidade de pessoas maiores de idade do sexo masculino e a quantidade de pessoas maiores de idade do sexo feminino que estiveram presentes.

#include<stdio.h> //Inclusão de biblioteca para entrada e saída de dados
#include<locale.h> //Inclusão de biblioteca para incluir linguagem
#include<stdlib.h> //Inclusão de biblioteca para limpar tela
#include<string.h> //Inclusão de biblioteca para manipulação de string
#include<ctype.h> //Inclusão de biblioteca para manipulação de caracteres

int main() { //Início do algoritmo: função main
setlocale(LC_ALL, "Portuguese"); //Definição de português como linguagem 

    int idade, sessoes, total, i; //Declaração de variáveis e o tipo
    char filme[80]; //Declaração de variáveis e o tipo
    char genero; //Declaração de variáveis e o tipo
    int qthomem = 0, qtmulher = 0, mulheradulta = 0, homemadulto = 0, idosos = 0, adultos = 0, adolescentes = 0, criancas = 0; //Declaração de variáveis e o tipo 
    
	printf("Seja bem-vindo ao cinema de Brasília\n\nSolicitaremos alguns dados\n"); //Imprime mensagem inicial na tela
	
	do{
		printf("Informar o número de sessões: "); //Imprime mensagem na tela requerindo a variável número de sessões
        scanf("%d", &sessoes); //Guarda na memória o número de sessões
        fflush(stdin); //Limpar buffer
	        
		if (sessoes != 2) //Condição para evitar que o número de sessões seja diferente de 2
	    	printf("Valor excedido, por favor informar exatamente 2 sessões.\n"); //Imprime mensagem na tela de erro
	}	while (sessoes != 2); //Condição de repetição
	
	
	do{
		printf("Informar o nome do filme: "); //Imprime na tela mensagem requerindo a variável nome do filme
	    fgets(filme, 80, stdin); //Guarda na memória o nome do filme
	    fflush(stdin); //Limpar buffer
	    filme[strlen(filme) - 1 ] = '\0'; //Evitar erro no momento que for imprimir o nome do filme
	        
		if (strlen(filme) < 2) //Condição para acertar filme como mais do que 1 caracter
	    	printf("Nome inválido por ser muito curto.\n"); //Imprime mensagem na tela de erro
	}	while (strlen(filme) < 2); //Condição de repetição
	
	
	do{
		printf("Informar o número de pessoas que assistiram o filme: "); //Imprime mensagem na tela requerindo o total de pessoas que assistiram a um determinado filme
	    scanf("%d", &total); //Guarda na memória o número total de pessoas que assistiram a um determinado filme
    	fflush(stdin); //Limpar buffer
	        
		if (total < 10) //Condição para evitar número menores do que 10
	    	printf("Valor menor do que o esperado, informar número maior do que 9.\n"); //Imprime mensagem na tela de erro
	}	while (total < 10); //Condição de repetição
	
	
	
    for (i=0; i<total; i++){ //Condição para guardar idade de cada pessoa
        do{
		    printf("Para cada pessoa informada, indicar sua idade: "); //Imprime mensagem na tela requerindo variável idade
	        scanf("%d", &idade); //Guarda na memória a idade de cada pessoa
	        fflush(stdin); //Limpar buffer
	        
			if (idade < 3 || idade > 100) //Condição para acertar idade de 3 a 100
	        	printf("Informar idade de 3 a 100 anos.\n"); //Imprime mensagem na tela de erro
		}	while (idade < 3 || idade > 100); //Condição de repetição
		

	    do{
		    printf("Para cada pessoa informada, indicar seu gênero: "); //Imprime mensagem na tela requerindo variável gênero
	        scanf("%c", &genero); //Guarda na memória a idade de cada pessoa
	        fflush(stdin); //Limpar buffer
	        genero = toupper(genero); //Deixar gênero em capslock para facilitar as condições
	        
			if (genero != 'M' && genero != 'F') //Condição para acertar gênero como F ou M
	        	printf("Informar F para gênero feminino e M para masculino.\n"); //Imprime mensagem na tela de erro
		}	while (genero != 'M' && genero != 'F'); //Condição de repetição
		
		if (genero == 'F'){ //Condição para contagem mulher
			if(idade > 17) //Condição de contagem para mulher adulta
			    mulheradulta++; //Contagem para mulher adulta
			qtmulher++; //Contagem de mulher
		}
		else{ //Condição para contagem homem
			if(idade > 17) //Condição de contagem para homem adulto
			    homemadulto++; //Contagem para homem adulto
			qthomem++; //Contagem para homem
		}
		
		if (idade >= 65) //Condição para contagem de idosos
		    idosos++; //Contagem de idosos
		    else if (idade >= 18) //Condição para contagem de adultos
		    adultos++; //Contagem de adultos
		    else if (idade >= 14) //Condição para contagem de adolescentes
		    adolescentes++; //Contagem de adolescentes
		    else { //Condição para contagem de crianças
		    	criancas++;  //Contagem de crianças
			}
		
	}	
	
    system("cls"); //Limpar conteúdo da tela
	printf("O filme %s teve: \n", &filme); //Imprime mensagem na tela informando nome do filme
	printf("%d espectadores do gênero feminino\n", qtmulher); //Imprime mensagem na tela informando o número de pessoas do gênero feminino
	printf("%d espectadores do gênero masculino\n", qthomem); //Imprime mensagem na tela informando o número de pessoas do gênero masculino
	printf("%d espectadores idosos (65 a 100 anos)\n", idosos); //Imprime mensagem na tela informando o número de pessoas idosas
	printf("%d espectadores adultos (18 a 64 anos)\n", adultos); //Imprime mensagem na tela informando o número de pessoas adultas
	printf("%d espectadores adolescentes (14 a 17 anos)\n", adolescentes); //Imprime mensagem na tela informando o número de pessoas adolescentes
	printf("%d espectadores crianças (3 a 13 anos)\n\n", criancas); //Imprime mensagem na tela informando o número de pessoas crianças
	printf("Digite qualquer tecla para prosseguir: "); //Imprime mensagem na tela para eventualmente trocar conteúdo
	getchar(); //Guarda na memória qualquer caracter
	
	system("cls"); //Limpar conteúdo da tela
	printf("O filme %s teve: \n", &filme); //Imprime mensagem na tela informando nome do filme
	printf("%d espectadores do gênero feminino maiores de idade\n", mulheradulta); //Imprime mensagem na tela informando o número de pessoas do gênero feminino
	printf("%d espectadores do gênero masculino maiores de idade\n", homemadulto); //Imprime mensagem na tela informando o número de pessoas do gênero masculino
	

  return 0; //retorno da função
}//final da função
