#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Menu do Time
 1- cadastrar time
 2- remover time
 3- listar todos os times
 4- pesquisar
      - pesquisar time pelo id
      - pesquisar time pelo tecnico
      - pesquisar conferencia pelo time
      - pesquisar time pelo ranking
      - pesquisar ranking pelo time
  5- sair
*/


typedef struct
{
    int id;
    char nome[50];
    char cidade[50];
    int ranking;
    char conferencia[10];
    char tecnico[50];

}Time;
//-----------------------------------------------------------------------------
void cabecalho (){
  printf("---------------------------\n" );
  printf("\t TIME \n" );
  printf("---------------------------\n" );
}
//-----------------------------------------------------------------------------
void cadastrar(){

  Time time;
  char opc;

  FILE* arquivo;
  arquivo = fopen("dadostime.txt", "ab");
      if ( arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo\n" );
         exit(1);// finaliza o programa
      }
        do {
//id do time
          setbuf(stdin, NULL);
          printf("Digite o ID do time:");
          scanf("%d", &time.id );
          setbuf(stdin, NULL);
//nome do time
          printf("Digite o nome do time: " );
          scanf("%49[^\n]", time.nome);
         fflush(stdin);
         __fpurge(stdin);
//cidade do time
          printf("Digite a cidade do time:" );
               scanf("%49[^\n]", time.nome);
        __fpurge(stdin);
          fflush(stdin);
//posição que o time esta no ranking
          printf("Digite a posicao que o time esta no ranking da temporada atual:" );
          scanf("%d", &time.ranking );
          setbuf(stdin, NULL);
// conferencia que o time joga ( leste ou oeste )
          printf("Digite a conferencia desse time:");
               scanf("%10[^\n]", time.conferencia);
        __fpurge(stdin);
          fflush(stdin);
// nome do tecnico atual
          printf("Digite o nome do tecnico atual:" );
              scanf("%49[^\n]", time.tecnico);
        __fpurge(stdin);
          fflush(stdin);
                  setbuf(stdin, NULL);

      fwrite(&time, sizeof(Time), 1, arquivo);
      //continuatr cadastro
            printf("Deseja continuar?\n s - sim \n n - nao\n" );
            printf("opcao:" );
                setbuf(stdin, NULL);
            scanf("%c", &opc );
            setbuf(stdin, NULL);

      }while(opc == 's');
      fclose (arquivo);
      printf("\n Agradecemos o cadastro\n" );

}// fim da função cadastar

//---------------------------------------------------------------------------
void listar(){
  Time time;
  FILE* arquivo;

  arquivo = fopen("dadostime.txt", "rb");
      if ( arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo\n" );
        exit(1);// finaliza o programa
      } else {

  while(fread(&time, sizeof(Time), 1, arquivo)==1){
           printf("\tID do time: %d\n ", time.id );
           printf("\tNome do time: %s\n ", time.nome );
           printf("\tCidade: %s \n", time.cidade);
           printf("\tConferencia: %s\n ", time.conferencia);
           printf("\tTecnico: %s\n ", time.tecnico );
           printf("\tPosicao no ranking atual: %d\n", time.ranking );
          printf("------------------------------------------------\n" );

        }// while
          fclose (arquivo);
      }// fim do else

}// fim da função listar
//----------------------------------------------------------------------------
void menu(){
  int opc;


  do {

    cabecalho();
    printf("1 - Cadastrar time\n" );
    printf("2 - Remover time\n" );
    printf("3 - Listar todos os times\n" );
    printf("4 - Pesquisar\n" );
    printf("5 - Sair\n" );

printf("\nEscolha uma opcao:" );
scanf("%i", &opc);

switch (opc) {
  case 1:
  system ("clear");
  printf("---------------------------\n" );
  printf("CADASTRAR TIME \n" );
  printf("---------------------------\n" );
  cadastrar();
  break;

  case 2:
  // remover time
  break;

  case 3:
  system ("clear");
    printf("------------------------------------------------\n" );
  printf("\tLISTAR TODOS OS TIME \n" );
    printf("------------------------------------------------\n" );
  listar();
  return 0;
  break;

  case 4:
  // pesquisar
  break;

  case 5:
  printf("\nObrigado por sua visita !!\n" );
  break;

  default:
  printf("\nOpcao invalida, tente novamente\n");
  break;
}


} while (opc != 5);

}// fim da função menu

int main() {
  menu();
  return 0;
}
