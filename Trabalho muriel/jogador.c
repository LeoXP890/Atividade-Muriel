#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "times.h"
#include "jogador.h"
#include "partida.h"
#include "login.h"

typedef struct
{
    int id; // identificação
    char nome[50];
    char posicao[50];
    float altura;// altura
    int idade;// idade
    int numero_camisa;// número da camisa
    int idTIME; // identificação time
} Jogador;
void cabecalho_JOGADOR()
{
    printf("---------------------------\n");
    printf("\t JOGADOR \n");
    printf("---------------------------\n");
}

void cadastro_JOGADOR()
{
    char opcao;
    int contaID = 1;
    int contador;

    Jogador jogador, *vet_jogadores;
    FILE *arq;
    arq = fopen("dados.dat", "ab+");// abre o arquivo para gravação
    if (arq == NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n");
        exit(1); // finaliza o programa
    }else
    {
        cabecalho_JOGADOR();

        vet_jogadores = (Jogador *)malloc(12 * sizeof(Jogador)); // alocação de memória para o vetor
        if (vet_jogadores == NULL)                               // REALOCA O VET JOGADORES
        {
            vet_jogadores = realloc(vet_jogadores, 20 * sizeof(Jogador)); // realoca o vetor
        }

        do
        {
            setbuf(stdin, NULL);

            fread(&jogador, sizeof(Jogador), 1, arq);
            while (!feof(arq))
            {
                if (contaID == jogador.id)
                {
                    contaID = contaID + 1;
                } // if
                fread(&jogador, sizeof(Jogador), 1, arq);
            } // while





            jogador.id = contaID;
            printf("Id do jogador: %i\n", jogador.id);
            printf("Digite o nome do jogador: ");
            setbuf(stdin, NULL);
            scanf("%49[^\n]", jogador.nome);
            fflush(stdin);
           
            printf("Digite a posição do jogador: ");
            setbuf(stdin, NULL);
            fgets(jogador.posicao, 50, stdin); // Recebe a posicao do jogador
            jogador.posicao[strcspn(jogador.posicao, "\n")] = '\0';
            fflush(stdin);

            printf("Digite o numero da camisa do jogador: ");
            setbuf(stdin, NULL);
            scanf("%i", &jogador.numero_camisa);
            fflush(stdin);

            printf("Digite a altura do jogador: ");
            setbuf(stdin, NULL);
            scanf("%f", &jogador.altura); // recebe altura
            fflush(stdin);

            printf("Digite a idade do jogador: ");
            setbuf(stdin, NULL);
            scanf("%i", &jogador.idade); // recebe idade
            fflush(stdin);

            printf("Deseja fazer mais cadastros?\n s - sim\n n - não\n");
            printf("Opcão: ");
            setbuf(stdin, NULL);
            scanf("%c", &opcao);
            fflush(stdin);

            system("clear");
            cabecalho_JOGADOR();
            fwrite(&jogador, sizeof(Jogador), 1, arq);

            jogador.id == contador++;

            setbuf(stdin, NULL);
            getchar();

        } while (opcao == 's');
        free(vet_jogadores);

        fclose(arq);
    }
    
}
void Lista_JOGADOR()
{

    Jogador jogador;
    FILE *arquivo;
    arquivo = fopen("dados.dat", "rb+");
    if (arquivo == NULL)
    {
        printf("Não existe nenhum jogador cadastrado, cadastre os jogadores para listalos\n");
        menu_JOGADOR(); 
    }            // if

    while (fread(&jogador, sizeof(Jogador), 1, arquivo) == 1)
    {
        printf("------------------------------------------------\n");
        printf("ID do jogador: %i\n", jogador.id);
        printf("Nome do jogador: %s\n", jogador.nome);
        printf("Posição do jogador: %s\n", jogador.posicao);
        printf("Numero da camisa: %i\n", jogador.numero_camisa);
        printf("Altura do jogador: %.2f\n", jogador.altura);
        printf("Idade do jogador: %i\n", jogador.idade);
        //printf("ID do time do jogador: %i\n", jogador.idTIME);
        printf("------------------------------------------------\n");
    }
    fclose(arquivo);
}

void pesquisaID_JOGADOR()
{
    Jogador jogador;
    FILE *arquivo;
    int id;
    arquivo = fopen("dados.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Não tem nenhum jogador cadastrado!\n Faça o cadastro para continuar\n");
        menu_JOGADOR(); // 1 significa erro
    }            // if

    printf("Digite o ID do jogador para buscar as informações: ");
    scanf("%i", &id);
 

    while (fread(&jogador, sizeof(Jogador), 1, arquivo) == 1)
    {
        if (id == jogador.id)
        {
            printf("------------------------------------------------\n");
            printf("ID do jogador: %i\n", jogador.id);
            printf("Nome do jogador: %s\n", jogador.nome);
            printf("Posição do jogador: %s\n", jogador.posicao);
            printf("Numero da camisa: %i\n", jogador.numero_camisa);
            printf("Altura do jogador: %.2f\n", jogador.altura);
            printf("Idade do jogador: %i\n", jogador.idade);
            //printf("ID do time do jogador: %i\n", jogador.idTIME);
            printf("------------------------------------------------\n");
        }
    }

    fclose(arquivo);
}
void pesquisaPosicoes_JOGADOR(){
    Jogador jogador;
    FILE *arquivo;
    char posicao[50];
    int contaID = 0;
    arquivo = fopen("dados.dat", "rb+");
    if (arquivo == NULL)
    {
        printf("Não tem nenhum jogador cadastrado!\n Faça o cadastro para continuar\n");
        menu_JOGADOR(); // 1 significa erro
    }           // if

    printf("Digite a posição do jogador para buscar por ele: ");
    setbuf(stdin, NULL);
    fgets(posicao, 50, stdin);
    posicao[strcspn(posicao, "\n")] = '\0';
    system("clear");
    while (fread(&jogador, sizeof(Jogador), 1, arquivo) == 1)
    {
           if (strcmp(posicao, jogador.posicao) == 0)
           {
               
               printf("------------------------------------------------\n");
               printf("\tPosição do Jogador: %s\n", jogador.posicao);
               printf("------------------------------------------------\n");
               printf("------------------------------------------------\n");
               printf("ID do jogador: %i\n", jogador.id);
               printf("Nome do jogador: %s\n", jogador.nome);
               printf("Numero da camisa: %i\n", jogador.numero_camisa);
               printf("Altura do jogador: %.2f\n", jogador.altura);
               printf("Idade do jogador: %i\n", jogador.idade);
               printf("ID do time do jogador: %i\n", jogador.idTIME);
               printf("------------------------------------------------\n");
           }
    }
    
    fclose(arquivo);
}

void pesquisaIDADE_JOGADOR(){
    Jogador jogador;
    FILE *arquivo;
    int idade;
    int nascimento;
    int somaidade = 2022;
    arquivo = fopen("dados.dat", "rb+");
    if (arquivo == NULL)
    {
        printf("Não tem nenhum jogador cadastrado!\n Faça o cadastro para continuar\n");
        menu_JOGADOR(); // 1 significa erro
    }           // if

    printf("Digite o ano de nacsimento do jogador para buscar por ele: ");
    setbuf(stdin, NULL);
    scanf("%i", &nascimento);
    system("clear");
    idade = somaidade - nascimento;//calcula a idade
    while (fread(&jogador, sizeof(Jogador), 1, arquivo) == 1)//enquanto ler do arquivo
    {
        if (idade == jogador.idade)
        {
           
            printf("------------------------------------------------\n");
            printf("\tIdade do Jogador: %i\n", jogador.idade);
            printf("------------------------------------------------\n");
            printf("------------------------------------------------\n");
            printf("ID do jogador: %i\n", jogador.id);
            printf("Nome do jogador: %s\n", jogador.nome);
            printf("Posição do jogador: %s\n", jogador.posicao);
            printf("Numero da camisa: %i\n", jogador.numero_camisa);
            printf("Altura do jogador: %.2f\n", jogador.altura);
            printf("Idade do jogador: %i\n", jogador.idade);
            printf("ID do time do jogador: %i\n", jogador.idTIME);
            printf("------------------------------------------------\n");
        }
    }

    getchar();
    fclose(arquivo);
}

void pesquisar_JOGADOR()//pesquisa
{

    int opc;
    char opc2;
    do
    {
        system("clear");

        printf("------------------------------------------------\n");
        printf("\tPESQUISAR\n");
        printf("------------------------------------------------\n");
        printf("1 - Pesquisar jogador pelo ID\n");
        printf("2 - Pesquisar jogador pela posicao\n");
        printf("3 - Pesquisar jogador pela idade\n");
        printf("4 - Sair.\n");

        printf("\nEscolha uma opcao:");
        scanf("%i", &opc);

        switch (opc)
        {
            // pesquisar time pelo id
        case 1:
            system("clear");
            pesquisaID_JOGADOR();
            printf("\nDeseja pesquisar mais ?\n s - sim \n n - nao\n");
            printf("opcao:");
            setbuf(stdin, NULL);
            scanf("%c", &opc2);
            setbuf(stdin, NULL);
            break;
            // pesquisar time pelo tecnico
        case 2:
            system("clear");
            pesquisaPosicoes_JOGADOR();
            printf("\nDeseja pesquisar mais ?\n s - sim \n n - nao\n");
            printf("opcao:");
            setbuf(stdin, NULL);
            scanf("%c", &opc2);
            setbuf(stdin, NULL);
            break;
        case 3:
            system("clear");
            pesquisaIDADE_JOGADOR();
            printf("\nDeseja pesquisar mais ?\n s - sim \n n - nao\n");
            printf("opcao:");
            setbuf(stdin, NULL);
            scanf("%c", &opc2);
            setbuf(stdin, NULL);
            break;

        case 4:

            printf("\nAgradecemos a sua visita !!\n");
            menu_JOGADOR(); // finaliza o programa
            break;
            // opção invalida
        default:
            printf("\nOpcao invalida, tente novamente\n");
            break;
        }
    } while (opc2 == 's');
    system("clear");
} // fim da função pesquisar

void removedoarquivo_JOGADOR(){// função para remover arquivo
    
    FILE *arquivo, *temporario;//

    arquivo = fopen("dados.dat", "rb+");
    temporario = fopen("temporario.dat", "wb+");
    if (arquivo == NULL)
    {
        printf("Não foi possivel abrir o arquivo\n");
        exit(1);
    }

    Jogador jogador;
    int id;
    printf("Digite o id do jogador para remover: ");
    scanf("%i", &id);
    while (fread(&jogador, sizeof(Jogador), 1, arquivo) == 1)
    {
        if (id !=jogador.id)
        {
            fwrite(&jogador, sizeof(jogador), 1, temporario);
            
        }
    }

    if (ferror(temporario))
    {
        printf("Erro ao excluir\n");
        
    }else
    {
        printf("Excluido com sucesso\n");
    }
    
    




    fclose(temporario);
    fclose(arquivo);

    remove("dados.dat");
    rename("temporario.dat", "dados.dat");

}


void menu_JOGADOR()// função para o menu
{
    int opc;
    char opc2;
    do
    {
        system("clear");

        printf("------------------------------------------------\n");
        printf("\tMENU\n");
        printf("------------------------------------------------\n");
        printf("1 - Cadastrar jogador\n");
        printf("2 - Listar jogadores\n");
        printf("3 - Pesquisar jogador\n");
        printf("4 - Remover jogador\n");
        printf("5 - Sair.\n");

        printf("\nEscolha uma opcao:");
        scanf("%i", &opc);

        switch (opc)
        {
            // cadastrar jogador
        case 1:
            system("clear");
            cadastro_JOGADOR();
            printf("\nDeseja cadastrar mais ?\n s - sim \n n - nao\n");
            printf("opcao:");
            setbuf(stdin, NULL);
            scanf("%c", &opc2);
            setbuf(stdin, NULL);
            break;
            // listar jogadores
        case 2:
            system("clear");
            Lista_JOGADOR();
            printf("\nDeseja listar mais ?\n s - sim \n n - nao\n");
            printf("opcao:");
            setbuf(stdin, NULL);
            scanf("%c", &opc2);
            setbuf(stdin, NULL);
            break;
            // pesquisar jogador
        case 3:
            system("clear");
            pesquisar_JOGADOR();
            printf("\nDeseja pesquisar mais ?\n s - sim \n n - nao\n");
            printf("opcao:");
            setbuf(stdin, NULL);
            scanf("%c", &opc2);
            setbuf(stdin, NULL);
            break;
            // remover jogador
        case 4:
            system("clear");
            removedoarquivo_JOGADOR();
            printf("\nDeseja remover mais ?\n s - sim \n n - nao\n");
            printf("opcao:");
            if (opc == 's')
            {
                removedoarquivo_JOGADOR();
            }
            
            setbuf(stdin, NULL);
            scanf("%c", &opc2);
            setbuf(stdin, NULL);
            break;
            // sair
        case 5:
            printf("\nAgradecemos a sua visita !!\n");
            exit(0);
            break;
            // opção invalida
        }
    }while (opc != 5);
    system("clear");
    
}
  
/*int main()
{
    menu_JOGADOR();

    return 0;
}*/