#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct 
{
    int id; //identificação
    char nome[50];
    char posicao[50];
    float altura;
    int idade;
    int idTIME; //identificação time
}Jogador;


char cadastro(){
    Jogador jogador;

    jogador.id = (int*) calloc(50, sizeof(int));
    if (jogador.id == NULL)
    {
      jogador.id = (int*) realloc(jogador.id, 80 * sizeof(int));
    } // if
for (int i = 0; i < 12; i++)
{
    printf("Forneça o ID do jogador: ");
    scanf("%i", jogador.id); // recebe o ID do jogador
    printf("\nForneça o Nome do Jogador: ");
    fgets(jogador.nome, 50, stdin); // Recebe o nome do jogador
    jogador.nome[strcspn(jogador.nome, "\n")] = '\0';
    setbuf(stdin, NULL);
    printf("\nForneça a posição do jogaodor: ");
    fgets(jogador.posicao, 50, stdin); // Recebe a posicao do jogador
    jogador.posicao[strcspn(jogador.posicao, "\n")] = '\0';
    setbuf(stdin, NULL);
    printf("\nForneça a altura do jogador: ");
    scanf("%f", jogador.altura); // recebe altura
    printf("\nForneça a idade do jogador: ");
    scanf("%i", jogador.idade); // recebe idade
    printf("\nForneça o ID do time que ele joga: ");
    scanf("%i", jogador.idTIME); // recebe ID do time
}

}