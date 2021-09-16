//Nome: Beatriz Rodrigues Monteiro
//Matr�cula: 20100019
//Curso: Ci�ncia da computa��o

//Objetivo: Criar um algoritmo para descobrir o perfil dos us�arios que frequentam o cinema de Bras�lia
//Entrada: N�mero de sess�es, nome do filme, quantidade de pessoas, g�nero e idade de cada pessoa.
//Sa�da: Nome do filme, a quantidade de pessoas do sexo feminino e a quantidade de pessoas do sexo masculino que assistiram ao filme. 
//A quantidade de pessoas, seguindo a classifica��o por idade
//A quantidade de pessoas maiores de idade do sexo masculino e a quantidade de pessoas maiores de idade do sexo feminino que estiveram presentes.

#include<stdio.h> //Inclus�o de biblioteca para entrada e sa�da de dados
#include<locale.h> //Inclus�o de biblioteca para incluir linguagem
#include<stdlib.h> //Inclus�o de biblioteca para limpar tela
#include<string.h> //Inclus�o de biblioteca para manipula��o de string
#include<ctype.h> //Inclus�o de biblioteca para manipula��o de caracteres

int main() { //In�cio do algoritmo: fun��o main
setlocale(LC_ALL, "Portuguese"); //Defini��o de portugu�s como linguagem 

    int idade, sessoes, total, i; //Declara��o de vari�veis e o tipo
    char filme[80]; //Declara��o de vari�veis e o tipo
    char genero; //Declara��o de vari�veis e o tipo
    int qthomem = 0, qtmulher = 0, mulheradulta = 0, homemadulto = 0, idosos = 0, adultos = 0, adolescentes = 0, criancas = 0; //Declara��o de vari�veis e o tipo 
    
	printf("Seja bem-vindo ao cinema de Bras�lia\n\nSolicitaremos alguns dados\n"); //Imprime mensagem inicial na tela
	
	do{
		printf("Informar o n�mero de sess�es: "); //Imprime mensagem na tela requerindo a vari�vel n�mero de sess�es
        scanf("%d", &sessoes); //Guarda na mem�ria o n�mero de sess�es
        fflush(stdin); //Limpar buffer
	        
		if (sessoes != 2) //Condi��o para evitar que o n�mero de sess�es seja diferente de 2
	    	printf("Valor excedido, por favor informar exatamente 2 sess�es.\n"); //Imprime mensagem na tela de erro
	}	while (sessoes != 2); //Condi��o de repeti��o
	
	
	do{
		printf("Informar o nome do filme: "); //Imprime na tela mensagem requerindo a vari�vel nome do filme
	    fgets(filme, 80, stdin); //Guarda na mem�ria o nome do filme
	    fflush(stdin); //Limpar buffer
	    filme[strlen(filme) - 1 ] = '\0'; //Evitar erro no momento que for imprimir o nome do filme
	        
		if (strlen(filme) < 2) //Condi��o para acertar filme como mais do que 1 caracter
	    	printf("Nome inv�lido por ser muito curto.\n"); //Imprime mensagem na tela de erro
	}	while (strlen(filme) < 2); //Condi��o de repeti��o
	
	
	do{
		printf("Informar o n�mero de pessoas que assistiram o filme: "); //Imprime mensagem na tela requerindo o total de pessoas que assistiram a um determinado filme
	    scanf("%d", &total); //Guarda na mem�ria o n�mero total de pessoas que assistiram a um determinado filme
    	fflush(stdin); //Limpar buffer
	        
		if (total < 10) //Condi��o para evitar n�mero menores do que 10
	    	printf("Valor menor do que o esperado, informar n�mero maior do que 9.\n"); //Imprime mensagem na tela de erro
	}	while (total < 10); //Condi��o de repeti��o
	
	
	
    for (i=0; i<total; i++){ //Condi��o para guardar idade de cada pessoa
        do{
		    printf("Para cada pessoa informada, indicar sua idade: "); //Imprime mensagem na tela requerindo vari�vel idade
	        scanf("%d", &idade); //Guarda na mem�ria a idade de cada pessoa
	        fflush(stdin); //Limpar buffer
	        
			if (idade < 3 || idade > 100) //Condi��o para acertar idade de 3 a 100
	        	printf("Informar idade de 3 a 100 anos.\n"); //Imprime mensagem na tela de erro
		}	while (idade < 3 || idade > 100); //Condi��o de repeti��o
		

	    do{
		    printf("Para cada pessoa informada, indicar seu g�nero: "); //Imprime mensagem na tela requerindo vari�vel g�nero
	        scanf("%c", &genero); //Guarda na mem�ria a idade de cada pessoa
	        fflush(stdin); //Limpar buffer
	        genero = toupper(genero); //Deixar g�nero em capslock para facilitar as condi��es
	        
			if (genero != 'M' && genero != 'F') //Condi��o para acertar g�nero como F ou M
	        	printf("Informar F para g�nero feminino e M para masculino.\n"); //Imprime mensagem na tela de erro
		}	while (genero != 'M' && genero != 'F'); //Condi��o de repeti��o
		
		if (genero == 'F'){ //Condi��o para contagem mulher
			if(idade > 17) //Condi��o de contagem para mulher adulta
			    mulheradulta++; //Contagem para mulher adulta
			qtmulher++; //Contagem de mulher
		}
		else{ //Condi��o para contagem homem
			if(idade > 17) //Condi��o de contagem para homem adulto
			    homemadulto++; //Contagem para homem adulto
			qthomem++; //Contagem para homem
		}
		
		if (idade >= 65) //Condi��o para contagem de idosos
		    idosos++; //Contagem de idosos
		    else if (idade >= 18) //Condi��o para contagem de adultos
		    adultos++; //Contagem de adultos
		    else if (idade >= 14) //Condi��o para contagem de adolescentes
		    adolescentes++; //Contagem de adolescentes
		    else { //Condi��o para contagem de crian�as
		    	criancas++;  //Contagem de crian�as
			}
		
	}	
	
    system("cls"); //Limpar conte�do da tela
	printf("O filme %s teve: \n", &filme); //Imprime mensagem na tela informando nome do filme
	printf("%d espectadores do g�nero feminino\n", qtmulher); //Imprime mensagem na tela informando o n�mero de pessoas do g�nero feminino
	printf("%d espectadores do g�nero masculino\n", qthomem); //Imprime mensagem na tela informando o n�mero de pessoas do g�nero masculino
	printf("%d espectadores idosos (65 a 100 anos)\n", idosos); //Imprime mensagem na tela informando o n�mero de pessoas idosas
	printf("%d espectadores adultos (18 a 64 anos)\n", adultos); //Imprime mensagem na tela informando o n�mero de pessoas adultas
	printf("%d espectadores adolescentes (14 a 17 anos)\n", adolescentes); //Imprime mensagem na tela informando o n�mero de pessoas adolescentes
	printf("%d espectadores crian�as (3 a 13 anos)\n\n", criancas); //Imprime mensagem na tela informando o n�mero de pessoas crian�as
	printf("Digite qualquer tecla para prosseguir: "); //Imprime mensagem na tela para eventualmente trocar conte�do
	getchar(); //Guarda na mem�ria qualquer caracter
	
	system("cls"); //Limpar conte�do da tela
	printf("O filme %s teve: \n", &filme); //Imprime mensagem na tela informando nome do filme
	printf("%d espectadores do g�nero feminino maiores de idade\n", mulheradulta); //Imprime mensagem na tela informando o n�mero de pessoas do g�nero feminino
	printf("%d espectadores do g�nero masculino maiores de idade\n", homemadulto); //Imprime mensagem na tela informando o n�mero de pessoas do g�nero masculino
	

  return 0; //retorno da fun��o
}//final da fun��o
