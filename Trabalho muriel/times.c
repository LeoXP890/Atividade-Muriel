#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "times.h"
#include "jogador.h"
#include "partida.h"
#include "login.h"
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
    int condicao; // 1 - inf ativas no programa ; 2 -  inf excluidas do programa
}Time;
//-----------------------------------------------------------------------------
void cabecalho_TIME(){
  printf("------------------------------------------------\n" );
  printf("\t MENU TIME \n" );
  printf("------------------------------------------------\n" );

}
//-----------------------------------------------------------------------------
void cadastrar_TIME(){

  Time time;
  FILE *arquivo;
  int id = 1;
  char opc;
  system ("clear");
  printf("------------------------------------------------\n" );
  printf("\tCADASTRAR TIME \n" );
  printf("------------------------------------------------\n" );

  arquivo = fopen("dadostime.dat", "ab+");
  if ( arquivo == NULL){
    printf("Nao foi possivel abrir o arquivo\n" );
     exit(1);// finaliza o programa
  }// if
  else{

    fread(&time,sizeof(Time),1,arquivo);
    while (!feof(arquivo)) {
      if (id == time.id){
        id = id + 1;
      }// if
  fread(&time,sizeof(Time),1,arquivo);
    }// while

time.condicao = 1;
printf("\t Cadastro ativo no programa \n" );
    time.id = id;
    printf("ID: %d\n", time.id );
      setbuf(stdin, NULL);
                printf("Digite o nome do time: " );
                scanf("%49[^\n]", time.nome);
            setbuf(stdin, NULL);
      //cidade do time
                printf("Digite a cidade do time:" );
                scanf("%49[^\n]", time.cidade);
            setbuf(stdin, NULL);
      //posição que o time esta no ranking
                printf("Digite a posicao que o time esta no ranking da temporada atual:" );
                scanf("%d", &time.ranking );
                setbuf(stdin, NULL);
      // conferencia que o time joga ( leste ou oeste )
                printf("Digite a conferencia desse time:");
                     scanf("%10[^\n]", time.conferencia);
                setbuf(stdin, NULL);
      // nome do tecnico atual
                printf("Digite o nome do tecnico atual:" );
                    scanf("%49[^\n]", time.tecnico);
                        setbuf(stdin, NULL);
      // informações ativas no arquivo



            fwrite(&time, sizeof(Time), 1, arquivo);
printf("\nTime cadastrado com sucesso !!\n" );
system("pause");
system("clear");
  }//else
fclose(arquivo);
}// fim da função cadastar
//---------------------------------------------------------------------------
void listar_TIME(){
  Time time;
  FILE* arquivo;

  arquivo = fopen("dadostime.dat", "rb+");
      if ( arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo\n" );
        exit(1);// finaliza o programa
      }
  while(fread(&time, sizeof(Time), 1, arquivo)==1){
    if (time.condicao == 1){
           printf("\tID do time: %d\n ", time.id );
           printf("\tNome do time: %s\n ", time.nome );
           printf("\tCidade: %s \n", time.cidade);
           printf("\tConferencia: %s\n ", time.conferencia);
           printf("\tTecnico: %s\n ", time.tecnico );
           printf("\tPosicao no ranking atual: %d\n", time.ranking );
          printf("------------------------------------------------\n" );
}// if
        }// while
fclose (arquivo);

}// fim da função listar
//----------------------------------------------------------------------------
void pesquisarTECNICO_TIME(){
  FILE* arquivo;
  Time time;
  char tecnico[50];

  arquivo = fopen("dadostime.dat", "rb+");
  if ( arquivo == NULL){
    printf("Nao foi possivel abrir o arquivo\n" );
    exit(1);// finaliza o programa
  }
  printf("------------------------------------------------\n" );
  printf("PESQUISAR DADOS DO TIME PELO NOME DO TECNICO \n" );
  printf("------------------------------------------------\n" );
  setbuf(stdin, NULL);
  printf("Digite o nome do tecnico:" );
  scanf("%49[^\n]", tecnico);
setbuf(stdin, NULL);
  system("clear");
  while( fread(&time,sizeof(Time), 1, arquivo)==1 ){
    if (strcmp(tecnico, time.tecnico)==0){
      printf("------------------------------------------------\n" );
      printf("\t RESULTADO do tecnico: %s\n", tecnico );
      printf("------------------------------------------------\n" );
      printf("\tID do time: %d\n ", time.id );
      printf("\tNome do time: %s\n ", time.nome );
      printf("\tCidade: %s \n", time.cidade);
      printf("\tPosicao no ranking atual: %d\n", time.ranking );
      printf("\tConferencia: %s\n ", time.conferencia);
      printf("------------------------------------------------\n" );
    }// if
  }// while
  fclose(arquivo);
}// fim da função que pesquisa o time pelo tecnico
//----------------------------------------------------------------------------
void pesquisarCONFERENCIA_TIME(){
  FILE* arquivo;
  Time time;
  char conferencia[10];

  arquivo = fopen("dadostime.dat", "rb+");
  if ( arquivo == NULL){
    printf("Nao foi possivel abrir o arquivo\n" );
    exit(1);// finaliza o programa
  }
  printf("------------------------------------------------\n" );
  printf("PESQUISAR DADOS DO TIME PELA CONFERENCIA \n" );
  printf("------------------------------------------------\n" );
  setbuf(stdin, NULL);
  printf("Digite a conferencia:" );
  scanf("%10[^\n]", conferencia);
setbuf(stdin, NULL);
  system("clear");

  while( fread(&time,sizeof(Time), 1, arquivo)==1 ){
    if (strcmp(conferencia, time.conferencia)==0){
      printf("------------------------------------------------\n" );
      printf("\t RESULTADO DA CONFERENCIA: %s\n", conferencia );
      printf("------------------------------------------------\n" );
      printf("\tID do time: %d\n ", time.id );
      printf("\tNome do time: %s\n ", time.nome );
      printf("\tCidade: %s \n", time.cidade);
      printf("\tPosicao no ranking atual: %d\n", time.ranking );
      printf("\tTecnico: %s\n ", time.tecnico );
     printf("------------------------------------------------\n" );

    }
  }
  fclose(arquivo);
} // fim da função que pesquisa o time pela conferencia
//----------------------------------------------------------------------------
void pesquisarID_TIME(){
  FILE* arquivo;
  Time time;
  int id;

  arquivo = fopen("dadostime.dat", "rb+");
  if ( arquivo == NULL){
    printf("Nao foi possivel abrir o arquivo\n" );
    exit(1);// finaliza o programa
  }
  printf("------------------------------------------------\n" );
  printf("\tPESQUISAR DADOS DO TIME PELO ID \n" );
  printf("------------------------------------------------\n" );
  printf("Digite o ID:" );
  scanf("%d", &id );
  system("clear");

  while( fread(&time,sizeof(Time), 1, arquivo)==1 ){
    if (id == time.id){
      printf("------------------------------------------------\n" );
      printf("\t RESULTADO DO ID: %d\n", id );
      printf("------------------------------------------------\n" );
      printf("\tNome do time: %s\n ", time.nome );
      printf("\tCidade: %s \n", time.cidade);
      printf("\tPosicao no ranking atual: %d\n", time.ranking );
      printf("\tConferencia: %s\n ", time.conferencia);
      printf("\tTecnico: %s\n ", time.tecnico );

    }
  }
  fclose(arquivo);
}// fim da função de pesquisar time plo ID
//----------------------------------------------------------------------------
void pesquisarRANKING_TIME(){
  FILE* arquivo;
  Time time;
  int ranking;

  arquivo = fopen("dadostime.dat", "rb+");
  if ( arquivo == NULL){
    printf("Nao foi possivel abrir o arquivo\n" );
    exit(1);// finaliza o programa
  }
  printf("------------------------------------------------\n" );
  printf("\tPESQUISAR DADOS DO TIME PELO RANKING \n" );
  printf("------------------------------------------------\n" );
  printf("Digite a posicao que o time esta no ranking:" );
  scanf("%d", &ranking );
  system ("clear");

  while( fread(&time,sizeof(Time), 1, arquivo)==1 ){
    if (ranking == time.ranking){
      printf("------------------------------------------------\n" );
      printf("\t RESULTADO DO RANKING: %d\n", ranking );
      printf("------------------------------------------------\n" );
      printf("\tID do time: %d\n ", time.id );
      printf("\tNome do time: %s\n ", time.nome );
      printf("\tCidade: %s \n", time.cidade);
      printf("\tConferencia: %s\n ", time.conferencia);
      printf("\tTecnico: %s\n ", time.tecnico );
     printf("------------------------------------------------\n" );
    }
  }
  fclose(arquivo);
}// fim da função de pesquisar time plo ID
//----------------------------------------------------------------------------
void pesquisarCIDADE_TIME(){
  FILE* arquivo;
  Time time;
  char cidade[50];

  arquivo = fopen("dadostime.dat", "rb+");
  if ( arquivo == NULL){
    printf("Nao foi possivel abrir o arquivo\n" );
    exit(1);// finaliza o programa
  }
  printf("------------------------------------------------\n" );
  printf("PESQUISAR DADOS DO TIME PELA CIDADE \n" );
  printf("------------------------------------------------\n" );
  setbuf(stdin, NULL);
  printf("Digite a cidade:" );
  scanf("%50[^\n]", cidade);
  setbuf(stdin, NULL);
  system("clear");

  while( fread(&time,sizeof(Time), 1, arquivo)==1 ){
    if (strcmp(cidade, time.cidade)==0){
      printf("------------------------------------------------\n" );
      printf("\t RESULTADO DA CIDADE: %s\n", cidade );
      printf("------------------------------------------------\n" );
      printf("\tID do time: %d\n ", time.id );
      printf("\tNome do time: %s\n ", time.nome );
      printf("\tPosicao no ranking atual: %d\n", time.ranking );
      printf("\tConferencia: %s\n ", time.conferencia);
      printf("\tTecnico: %s\n ", time.tecnico );
     printf("------------------------------------------------\n" );

    }
  }
  fclose(arquivo);
} // fim da função que pesquisa o time pela conferencia
//----------------------------------------------------------------------------
void pesquisar_TIME(){
  int opc;
  char opc2;

  do{
    system("clear");

    printf("------------------------------------------------\n" );
    printf("\tPESQUISAR\n" );
    printf("------------------------------------------------\n" );
  printf("1 - Pesquisar dados do time pelo ID.\n" );
  printf("2 - Pesquisar time pelo tecnico.\n" );
  printf("3 - Pesquisar time pela conferencia.\n" );
  printf("4 - Pesquisar time pelo ranking.\n" );
  printf("5 - Pesquisar time pela cidade.\n" );
  printf("6 - Sair.\n" );

  printf("\nEscolha uma opcao:" );
  scanf("%i", &opc);

  switch (opc) {
// pesquisar time pelo id
    case 1:
      system("clear");
      pesquisarID_TIME();
      printf("\nDeseja pesquisar mais ?\n s - sim \n n - nao\n");
      printf("opcao:");
      setbuf(stdin, NULL);
      scanf("%c", &opc2);
      setbuf(stdin, NULL);
      break;
      // pesquisar time pelo tecnico
    case 2:
    system ("clear");
  pesquisarTECNICO_TIME();
    printf("\nDeseja pesquisar mais ?\n s - sim \n n - nao\n" );
    printf("opcao:" );
        setbuf(stdin, NULL);
    scanf("%c", &opc2 );
    setbuf(stdin, NULL);
    break;
// pesquisar time pela conferencia
    case 3:
      system("clear");
      pesquisarCONFERENCIA_TIME();
      printf("\nDeseja pesquisar mais ?\n s - sim \n n - nao\n");
      printf("opcao:");
      setbuf(stdin, NULL);
      scanf("%c", &opc2);
      setbuf(stdin, NULL);
      break;
      //  pesquisar time pelo ranking
    case 4:
      system("clear");
      pesquisarRANKING_TIME();
      printf("\nDeseja pesquisar mais ?\n s - sim \n n - nao\n");
      printf("opcao:");
      setbuf(stdin, NULL);
      scanf("%c", &opc2);
      setbuf(stdin, NULL);
      break;
      //  Pesquisar time pela cidade
    case 5:
      system("clear");
      pesquisarCIDADE_TIME();
      printf("\nDeseja pesquisar mais ?\n s - sim \n n - nao\n");
      printf("opcao:");
      setbuf(stdin, NULL);
      scanf("%c", &opc2);
      setbuf(stdin, NULL);
      break;
      // sair
    case 6:
    printf("\nAgradecemos a sua visita !!\n" );
    exit(1);// finaliza o programa
    break;
// opção invalida
    default:
    printf("\nOpcao invalida, tente novamente\n");
    break;
  }
}while (opc2 == 's');
system("clear");
}// fim da função pesquisar
//----------------------------------------------------------------------------
void excluir_TIME(){
int id =0;
int igual = 0;
Time time;
FILE *arquivo;
char opc;
char confirmacao;

system("clear");
printf("------------------------------------------------\n" );
printf("\tEXCLUIR DADOS DE UM TIME \n" );
printf("------------------------------------------------\n" );

printf("Digite o ID do time que deseja excluir:" );
scanf("%d", &id );
setbuf(stdin, NULL);

arquivo = fopen("dadostime.dat", "rb+");

if ( arquivo == NULL){
  printf("Nao foi possivel abrir o arquivo\n" );
  exit(1);// finaliza o programa
}// if

  while (igual == 0 && !feof(arquivo)) {
    fread(&time,sizeof(Time),1,arquivo);
    if (!feof(arquivo) && id == time.id ){
      igual = 1;
      printf("\tNome do time: %s\n ", time.nome );
      printf("\tCidade: %s \n", time.cidade);
      printf("\tConferencia: %s\n ", time.conferencia);
      printf("\tTecnico: %s\n ", time.tecnico );
      printf("\tPosicao no ranking atual: %d\n", time.ranking );
     printf("------------------------------------------------\n" );
    }// if
  }// while
  if (igual == 1){
    printf("Deseja excluir esse time ?\n s-sim \n n-nao\n");
    printf("Opcao:" );
    scanf("%c", &opc );
    if (opc == 's'){
      fseek(arquivo,-sizeof(Time),SEEK_CUR);// posicionamento do ponteiro
      time.condicao = 2;
      fwrite(&time,sizeof(Time),1, arquivo);
      printf("Time excluido com sucesso !!\n" );
    }//if opc
  }// if
    fclose(arquivo);
    system("pause");
}
//----------------------------------------------------------------------------
void converte_csv_TIME(){
  Time time;
  FILE *arquivo;
  FILE *temporario;
  system("clear");
  printf("------------------------------------------------\n" );
  printf("\tCONVERTER DADOS PARA .CSV \n" );
  printf("------------------------------------------------\n" );

  temporario = fopen("dadosCSV.csv", "w+");
  arquivo = fopen("dadostime.dat", "rb+");

  fputs("ID; Nome; Cidade; Ranking;  Conferencia; Tecnico; Condição no programa (1 - ativo / 2 - excluido)\r",temporario );

  fread(&time, sizeof(Time),1, arquivo);
  while (!feof(arquivo)) {
     fprintf(temporario, "%d; %s; %s; %d; %s; %s; %d\r", time.id, time.nome, time.cidade, time.ranking, time.conferencia, time.tecnico, time.condicao );
     fread(&time, sizeof(Time),1, arquivo);
  }// while
  fclose(temporario);
  fclose(arquivo);
}
//----------------------------------------------------------------------------
void menu_TIME(){
  int opc;
  do {
    cabecalho_TIME();
    printf("1 - Cadastrar time\n" );
    printf("2 - Listar todos os times\n" );
    printf("3 - Pesquisar \n" );
    printf("4 - Excluir dados\n" );
    printf("5 - Converter dados para .csv\n" );
    printf("6 - Sair\n" );
printf("\nEscolha uma opcao:" );
scanf("%i", &opc);
switch (opc) {
// cadastar times
  case 1:
  cadastrar_TIME();
  break;
// listar times cadastrados
  case 2:
  system ("clear");
    printf("------------------------------------------------\n" );
  printf("\tLISTAR TODOS OS TIME \n" );
    printf("------------------------------------------------\n" );
  listar_TIME();
  break;
// pesquisar dados
  case 3:
    system("clear");
    pesquisar_TIME();
    system("pause");
    system("clear");
    menu_TIME();
    break;
    // remover dados
  case 4:
  excluir_TIME();
  break;
// converter dados para csv
  case 5:
  converte_csv_TIME();
  printf("\nConvercao bem sucedida\n\n" );
  system("pause");
  system("clear");
  menu_TIME();
  break;
// sair
  case 6:
  printf("\nObrigado por sua visita !!\n" );
  exit(1);// finaliza o programa
  break;
// opção invalida
  default:
  printf("\nOpcao invalida, tente novamente\n");
  break;
}// switch
    } while (opc != 5);
}// fim da função menu
//---------------------------------------------------------------------------
/*int main() {
  menu();
  return 0;
}*/
