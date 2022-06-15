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

} Time;
//-----------------------------------------------------------------------------
void cabecalho()
{
  printf("------------------------------------------------\n");
  printf("\t MENU TIME \n");
  printf("------------------------------------------------\n");
}
//-----------------------------------------------------------------------------
void cadastrar()
{

  Time time;
  char opc;

  FILE *arquivo;
  arquivo = fopen("dadostime.txt", "ab");
  if (arquivo == NULL)
  {
    printf("Nao foi possivel abrir o arquivo\n");
    exit(1); // finaliza o programa
  }
  do
  {
    // id do time
    setbuf(stdin, NULL);
    printf("Digite o ID do time:");
    scanf("%d", &time.id);
    setbuf(stdin, NULL);
    // nome do time
    printf("Digite o nome do time: ");
    scanf("%49[^\n]", time.nome);
    fflush(stdin);
    // cidade do time
    printf("Digite a cidade do time:");
    scanf("%49[^\n]", time.cidade);
    fflush(stdin);
    // posição que o time esta no ranking
    printf("Digite a posicao que o time esta no ranking da temporada atual:");
    scanf("%d", &time.ranking);
    setbuf(stdin, NULL);
    // conferencia que o time joga ( leste ou oeste )
    printf("Digite a conferencia desse time:");
    scanf("%10[^\n]", time.conferencia);
    fflush(stdin);
    // nome do tecnico atual
    printf("Digite o nome do tecnico atual:");
    scanf("%49[^\n]", time.tecnico);
    fflush(stdin);
    setbuf(stdin, NULL);

    fwrite(&time, sizeof(Time), 1, arquivo);
    // continuatr cadastro
    printf("Deseja continuar?\n s - sim \n n - nao\n");
    printf("opcao:");
    setbuf(stdin, NULL);
    scanf("%c", &opc);
    setbuf(stdin, NULL);

  } while (opc == 's');
  fclose(arquivo);
  printf("\n Agradecemos o cadastro\n");

} // fim da função cadastar
//---------------------------------------------------------------------------
void listar()
{
  Time time;
  FILE *arquivo;

  arquivo = fopen("dadostime.txt", "rb");
  if (arquivo == NULL)
  {
    printf("Nao foi possivel abrir o arquivo\n");
    exit(1); // finaliza o programa
  }
  else
  {

    while (fread(&time, sizeof(Time), 1, arquivo) == 1)
    {
      printf("\tID do time: %d\n ", time.id);
      printf("\tNome do time: %s\n ", time.nome);
      printf("\tCidade: %s \n", time.cidade);
      printf("\tConferencia: %s\n ", time.conferencia);
      printf("\tTecnico: %s\n ", time.tecnico);
      printf("\tPosicao no ranking atual: %d\n", time.ranking);
      printf("------------------------------------------------\n");

    } // while
    fclose(arquivo);
  } // fim do else

} // fim da função listar
//----------------------------------------------------------------------------
void pesquisarTECNICO()
{
  FILE *arquivo;
  Time time;
  char tecnico[50];

  arquivo = fopen("dadostime.txt", "rb");
  if (arquivo == NULL)
  {
    printf("Nao foi possivel abrir o arquivo\n");
    exit(1); // finaliza o programa
  }
  printf("------------------------------------------------\n");
  printf("PESQUISAR DADOS DO TIME PELO NOME DO TECNICO \n");
  printf("------------------------------------------------\n");
  fflush(stdin);
  printf("Digite o nome do tecnico:");
  gets(tecnico);
  system("cls");
  while (fread(&time, sizeof(Time), 1, arquivo) == 1)
  {
    if (strcmp(tecnico, time.tecnico) == 0)
    {
      printf("------------------------------------------------\n");
      printf("\t RESULTADO do tecnico: %s\n", tecnico);
      printf("------------------------------------------------\n");
      printf("\tID do time: %d\n ", time.id);
      printf("\tNome do time: %s\n ", time.nome);
      printf("\tCidade: %s \n", time.cidade);
      printf("\tConferencia: %s\n ", time.conferencia);
      printf("\tPosicao no ranking atual: %d\n", time.ranking);
      printf("------------------------------------------------\n");
    } // if
  }   // while
  fclose(arquivo);
}
//----------------------------------------------------------------------------
void pesquisarCONFERENCIA()
{
  FILE *arquivo;
  Time time;
  char conferencia[10];

  arquivo = fopen("dadostime.txt", "rb");
  if (arquivo == NULL)
  {
    printf("Nao foi possivel abrir o arquivo\n");
    exit(1); // finaliza o programa
  }
  printf("------------------------------------------------\n");
  printf("PESQUISAR DADOS DO TIME PELA CONFERENCIA \n");
  printf("------------------------------------------------\n");
  fflush(stdin);
  printf("Digite a conferencia:");
  gets(conferencia);

  system("cls");

  while (fread(&time, sizeof(Time), 1, arquivo) == 1)
  {
    if (strcmp(conferencia, time.conferencia) == 0)
    {
      printf("------------------------------------------------\n");
      printf("\t RESULTADO DA CONFERENCIA: %s\n", conferencia);
      printf("------------------------------------------------\n");
      printf("\tID do time: %d\n ", time.id);
      printf("\tNome do time: %s\n ", time.nome);
      printf("\tCidade: %s \n", time.cidade);
      printf("\tTecnico: %s\n ", time.tecnico);
      printf("\tPosicao no ranking atual: %d\n", time.ranking);
      printf("------------------------------------------------\n");
    }
  }
  fclose(arquivo);
} // fim da função que pesquisa o time pela conferencia
//----------------------------------------------------------------------------
void pesquisarID()
{
  FILE *arquivo;
  Time time;
  int id;

  arquivo = fopen("dadostime.txt", "rb");
  if (arquivo == NULL)
  {
    printf("Nao foi possivel abrir o arquivo\n");
    exit(1); // finaliza o programa
  }
  printf("------------------------------------------------\n");
  printf("\tPESQUISAR DADOS DO TIME PELO ID \n");
  printf("------------------------------------------------\n");
  printf("Digite o ID:");
  scanf("%d", &id);
  system("cls");

  while (fread(&time, sizeof(Time), 1, arquivo) == 1)
  {
    if (id == time.id)
    {
      printf("------------------------------------------------\n");
      printf("\t RESULTADO DO ID: %d\n", id);
      printf("------------------------------------------------\n");
      printf("\tNome do time: %s\n ", time.nome);
      printf("\tCidade: %s \n", time.cidade);
      printf("\tConferencia: %s\n ", time.conferencia);
      printf("\tTecnico: %s\n ", time.tecnico);
      printf("\tPosicao no ranking atual: %d\n", time.ranking);
    }
  }
  fclose(arquivo);
} // fim da função de pesquisar time plo ID
//----------------------------------------------------------------------------
void pesquisarRANKING()
{
  FILE *arquivo;
  Time time;
  int ranking;

  arquivo = fopen("dadostime.txt", "rb");
  if (arquivo == NULL)
  {
    printf("Nao foi possivel abrir o arquivo\n");
    exit(1); // finaliza o programa
  }
  printf("------------------------------------------------\n");
  printf("\tPESQUISAR DADOS DO TIME PELO RANKING \n");
  printf("------------------------------------------------\n");
  printf("Digite a posicao que o time esta no ranking:");
  scanf("%d", &ranking);
  system("cls");

  while (fread(&time, sizeof(Time), 1, arquivo) == 1)
  {
    if (ranking == time.ranking)
    {
      printf("------------------------------------------------\n");
      printf("\t RESULTADO DO RANKING: %d\n", ranking);
      printf("------------------------------------------------\n");
      printf("\tID do time: %d\n ", time.id);
      printf("\tNome do time: %s\n ", time.nome);
      printf("\tCidade: %s \n", time.cidade);
      printf("\tConferencia: %s\n ", time.conferencia);
      printf("\tTecnico: %s\n ", time.tecnico);
      printf("------------------------------------------------\n");
    }
  }
  fclose(arquivo);
} // fim da função de pesquisar time plo ID

//----------------------------------------------------------------------------
void pesquisarCIDADE()
{
  FILE *arquivo;
  Time time;
  char cidade[50];

  arquivo = fopen("dadostime.txt", "rb");
  if (arquivo == NULL)
  {
    printf("Nao foi possivel abrir o arquivo\n");
    exit(1); // finaliza o programa
  }
  printf("------------------------------------------------\n");
  printf("PESQUISAR DADOS DO TIME PELA CIDADE \n");
  printf("------------------------------------------------\n");
  fflush(stdin);
  printf("Digite a cidade:");
  gets(cidade);

  system("cls");

  while (fread(&time, sizeof(Time), 1, arquivo) == 1)
  {
    if (strcmp(cidade, time.cidade) == 0)
    {
      printf("------------------------------------------------\n");
      printf("\t RESULTADO DA CIDADE: %s\n", cidade);
      printf("------------------------------------------------\n");
      printf("\tID do time: %d\n ", time.id);
      printf("\tNome do time: %s\n ", time.nome);
      printf("\tConferencia: %s\n ", time.conferencia);
      printf("\tTecnico: %s\n ", time.tecnico);
      printf("\tPosicao no ranking atual: %d\n", time.ranking);
      printf("------------------------------------------------\n");
    }
  }
  fclose(arquivo);
} // fim da função que pesquisa o time pela conferencia

//----------------------------------------------------------------------------
void pesquisar()
{
  int opc;
  char opc2;

  do
  {
    system("cls");

    printf("------------------------------------------------\n");
    printf("\tPESQUISAR\n");
    printf("------------------------------------------------\n");
    printf("1 - Pesquisar dados do time pelo ID.\n");
    printf("2 - Pesquisar time pelo tecnico.\n");
    printf("3 - Pesquisar time pela conferencia.\n");
    printf("4 - Pesquisar time pelo ranking.\n");
    printf("5 - Pesquisar time pela cidade.\n");
    printf("6 - Sair.\n");

    printf("\nEscolha uma opcao:");
    scanf("%i", &opc);

    switch (opc)
    {
      // pesquisar time pelo id
    case 1:
      system("cls");
      pesquisarID();
      printf("\nDeseja pesquisar mais ?\n s - sim \n n - nao\n");
      printf("opcao:");
      setbuf(stdin, NULL);
      scanf("%c", &opc2);
      setbuf(stdin, NULL);
      break;
      // pesquisar time pelo tecnico
    case 2:
      system("cls");
      pesquisarTECNICO();
      printf("\nDeseja pesquisar mais ?\n s - sim \n n - nao\n");
      printf("opcao:");
      setbuf(stdin, NULL);
      scanf("%c", &opc2);
      setbuf(stdin, NULL);
      break;
      // pesquisar time pela conferencia
    case 3:
      system("cls");
      pesquisarCONFERENCIA();
      printf("\nDeseja pesquisar mais ?\n s - sim \n n - nao\n");
      printf("opcao:");
      setbuf(stdin, NULL);
      scanf("%c", &opc2);
      setbuf(stdin, NULL);
      break;
      //  pesquisar time pelo ranking
    case 4:
      system("cls");
      pesquisarRANKING();
      printf("\nDeseja pesquisar mais ?\n s - sim \n n - nao\n");
      printf("opcao:");
      setbuf(stdin, NULL);
      scanf("%c", &opc2);
      setbuf(stdin, NULL);
      break;
      //  Pesquisar time pela cidade
    case 5:
      system("cls");
      pesquisarCIDADE();
      printf("\nDeseja pesquisar mais ?\n s - sim \n n - nao\n");
      printf("opcao:");
      setbuf(stdin, NULL);
      scanf("%c", &opc2);
      setbuf(stdin, NULL);
      break;
      // sair
    case 6:
      printf("\nAgradecemos a sua visita !!\n");
      exit(1); // finaliza o programa
      break;
      // opção invalida
    default:
      printf("\nOpcao invalida, tente novamente\n");
      break;
    }
  } while (opc2 == 's');
  system("cls");
} // fim da função pesquisar
//----------------------------------------------------------------------------
void menu()
{
  int opc;
  do
  {
    cabecalho();
    printf("1 - Cadastrar time\n");
    printf("2 - Remover time\n");
    printf("3 - Listar todos os times\n");
    printf("4 - Pesquisar\n");
    printf("5 - Sair\n");

    printf("\nEscolha uma opcao:");
    scanf("%i", &opc);

    switch (opc)
    {
    case 1:
      system("cls");
      printf("------------------------------------------------\n");
      printf("\tCADASTRAR TIME \n");
      printf("------------------------------------------------\n");
      cadastrar();
      break;
    // remover time
    case 2:

      break;
      // listar times cadastrados
    case 3:
      system("cls");
      printf("------------------------------------------------\n");
      printf("\tLISTAR TODOS OS TIME \n");
      printf("------------------------------------------------\n");
      listar();
      break;
      // pesquisar times
    case 4:
      system("cls");
      pesquisar();
      break;
      // sair
    case 5:
      printf("\nObrigado por sua visita !!\n");
      exit(1); // finaliza o programa
      break;
      // opção invalida
    default:
      printf("\nOpcao invalida, tente novamente\n");
      break;
    } // switch
  } while (opc != 5);
} // fim da função menu
//---------------------------------------------------------------------------
int main()
{
  menu();
  return 0;
}