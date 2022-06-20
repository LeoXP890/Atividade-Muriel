#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "times.h"
#include "jogador.h"
#include "partida.h"
#include "login.h"

typedef struct 
{
    int IDdaCASAleste;
    int IDdaCASAoeste;
    int IDdoVISITANTEleste;
    int IDdoVISITANTEoeste;
    int placardaCASAleste;
    int placardaCASAoeste;
    int placardoVISITANTEleste;
    int placardoVISITANTEoeste;
}Partidas;

void cadastroLeste_PARTIDAS(){
    FILE *arq;
    Partidas partida;
    arq = fopen("partidasLESTE.dat", "ab");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    printf("Digite o ID do time da casa: ");
    scanf("%d", &partida.IDdaCASAleste);
    printf("Digite o ID do time visitante: ");
    scanf("%d", &partida.IDdoVISITANTEleste);
    printf("Digite o placar do time da casa: ");
    scanf("%d", &partida.placardaCASAleste);
    printf("Digite o placar do time visitante: ");
    scanf("%d", &partida.placardoVISITANTEleste);
    fwrite(&partida, sizeof(Partidas), 1, arq);
    fclose(arq);

}
void cadastroOeste_PARTIDAS(){
    FILE *arq;
    Partidas partida;
    arq = fopen("partidasOESTE.dat", "ab");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    printf("Digite o ID do time da casa: ");
    scanf("%d", &partida.IDdaCASAoeste);
    printf("Digite o ID do time visitante: ");
    scanf("%d", &partida.IDdoVISITANTEoeste);
    printf("Digite o placar do time da casa: ");
    scanf("%d", &partida.placardaCASAoeste);
    printf("Digite o placar do time visitante: ");
    scanf("%d", &partida.placardoVISITANTEoeste);
    fwrite(&partida, sizeof(Partidas), 1, arq);
    fclose(arq);



}




void cadastrar_PARTIDAS(){
    int conferencia;
    int leste;
    int oeste;
    int contadorLeste = 0;
    int contadorOeste = 0;
    FILE *arquivo;
    arquivo = fopen("partidas.dat", "ab");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    Partidas partida;
    do
    {
        printf("Cadastro de partidas\n");
        printf("1 - Leste\n");
        printf("2 - Oeste\n");
        printf("3 - Sair\n");
        printf("Selecione a conferencia:\n");
        scanf("%d", &conferencia);
        system("clear");

        switch(conferencia){
            case 1:
            cadastroLeste_PARTIDAS();
                break;
            case 2:
            cadastroOeste_PARTIDAS();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida\n");
                break;
        }


    } while (conferencia != 3);
    
}

void lista_PARTIDAS(){
    
    FILE *arquivo;
    arquivo = fopen("partidas.dat", "rb");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    Partidas partida;
    int conferencia;
    do
    {
        printf("--------------------------------------\n");
        printf("Listar partidas\n");
        printf("1 - Leste\n");
        printf("2 - Oeste\n");
        printf("3 - Sair\n");
        printf("--------------------------------------\n");
        system("clear");
        printf("Selecione a conferencia:\n");
        scanf("%d", &conferencia);
        if (conferencia == 1)
        {
            system("clear");
            printf("--------------------------------------\n");
            printf("CONFERENCIA LESTE\n");
            printf("--------------------------------------\n");
            while(fread(&partida, sizeof(partida), 1, arquivo) == 1){
                printf("ID do time casa: %d\n", partida.IDdaCASAleste);
                printf("Placard da casa: %d\n", partida.placardaCASAleste);
                printf("ID do visitante: %d\n", partida.IDdoVISITANTEleste);
                printf("Placar do visitante: %d\n", partida.placardoVISITANTEleste);
                printf("--------------------------------------\n");
            }
        }
        else if (conferencia == 2)
        {
            system("clear");
            printf("--------------------------------------\n");
            printf("CONFERENCIA OESTE\n");
            printf("--------------------------------------\n");
            while(fread(&partida, sizeof(partida), 1, arquivo) == 1){
                printf("ID da casa: %d\n", partida.IDdaCASAoeste);
                printf("Placard da casa: %d\n", partida.placardaCASAoeste);
                printf("ID do visitante: %d\n", partida.IDdoVISITANTEoeste);
                printf("Placar do visitante: %d\n", partida.placardoVISITANTEoeste);
            }
        }
    } while (conferencia != 3);
}

void listarTIMES_PARTIDAS(){
  
  listar_TIME();
    
}



void menu_partidas(){
    int opcao;
do
{   
    printf("--------------------------------------\n");
    printf("PARTIDAS\n");
    printf("--------------------------------------\n");
    printf("1- Listar times\n");
    printf("2- Cadastrar partidas\n");
    printf("3- Listar partidas\n");
    printf("4- Sair\n");
    printf("--------------------------------------\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);
    switch(opcao)
    {
        case 1:
            listarTIMES_PARTIDAS();
            break;
        case 2:
            cadastrar_PARTIDAS();
            break;
        case 3:
            lista_PARTIDAS();
            break;
        case 4:
            exit(1);
        default:
            printf("Opcao invalida\n");


    }


} while (opcao != 3);
}
   



/*int main(){
    menu();
    
    return 0;
}*/
