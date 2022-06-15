#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int id; // identificação
    char nome[50];
    char posicao[50];
    float altura;
    int idade;
    int numero_camisa;
    int idTIME; // identificação time
} Jogador;
void cabecalho()
{
    printf("---------------------------\n");
    printf("\t JOGADOR \n");
    printf("---------------------------\n");
}
void cadastro()
{
    char opcao;
    int contador = 0;
    
    Jogador jogador, *vet_jogadores;
    FILE *arq;
    arq = fopen("dados.txt", "ab");
    if (arq == NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n");
        exit(1); // finaliza o programa
    }
    cabecalho();
    
     vet_jogadores = (Jogador*) malloc(12 * sizeof(Jogador));
     if (vet_jogadores == NULL)//REALOCA O VET JOGADORES
        {
            vet_jogadores = realloc(vet_jogadores, 20 * sizeof(Jogador));
        }


    do
    {
        contador++;
        if (contador == 13)
        {
            printf("Limite de jogadores atingido\n\n");
        }
        jogador.id = contador++;
        printf("Digite o nome do jogador: ");
        fgets(jogador.nome, 50, stdin); // Recebe o nome do jogador
        jogador.nome[strcspn(jogador.nome, "\n")] = '\0';
        setbuf(stdin, NULL);
        printf("Digite a posição do jogador: ");
        fgets(jogador.posicao, 50, stdin); // Recebe a posicao do jogador
        jogador.posicao[strcspn(jogador.posicao, "\n")] = '\0';
        setbuf(stdin, NULL);
        printf("Digite o numero da camisa do jogador: ");
        scanf("%i", &jogador.numero_camisa);
        setbuf(stdin, NULL);
        printf("Digite a altura do jogador: ");
        scanf("%f", &jogador.altura); // recebe altura
        setbuf(stdin, NULL);
        printf("Digite a idade do jogador: ");
        scanf("%i", &jogador.idade); // recebe idade
        setbuf(stdin, NULL);
        printf("Digite o ID do time que ele joga: ");
        scanf("%i", &jogador.idTIME); // recebe ID do time
        setbuf(stdin, NULL);
        printf("Deseja fazer mais cadastros?\n s - sim\n n - não\n");
        printf("Opcão: ");
        scanf("%c", &opcao);
        setbuf(stdin, NULL);
        
        
        
        system("clear");
        fwrite(&jogador, sizeof(Jogador), 1, arq);


    } while (opcao == 's');
free(vet_jogadores);

 

    fclose(arq);
}
void Lista(){

    Jogador jogador;
    FILE *arquivo;
    arquivo = fopen("dados.txt", "rb" );
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1); // 1 significa erro
    }            // if

while (fread(&jogador, sizeof(Jogador), 1, arquivo) == 1)
{
    printf("Nome do jogador: %s\n", jogador.nome);
    printf("Numero da camisa: %i\n", jogador.numero_camisa);
    printf("Altura do jogador: %f\n", jogador.altura);
    printf("Idade do jogador: %i\n", jogador.idade);
    printf("ID do time do jogador: %i\n", jogador.idTIME);
    printf("------------------------------------------------\n");
}
fclose(arquivo);
}

void pesquisaID(){
    Jogador jogador;
    FILE *arquivo;
    int id;
    arquivo = fopen("dados.txt", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1); // 1 significa erro
    }            // if

    printf("Digite o ID do jogador para buscar as informações: ");
    scanf("%i", &id);

    


    while (fread(&jogador, sizeof(Jogador), 1, arquivo) == 1)
    {
        if (id == jogador.id)
        {
            printf("Nome do jogador: %s\n", jogador.nome);
            printf("Numero da camisa: %i\n", jogador.numero_camisa);
            printf("Altura do jogador: %f\n", jogador.altura);
            printf("Idade do jogador: %i\n", jogador.idade);
            printf("ID do time do jogador: %i\n", jogador.idTIME);
            printf("------------------------------------------------\n");
        }
        

     
    }



fclose(arquivo);


}









void pesquisar(){

    int opc;
    char opc2;
    do
    {
        system("cls");
        pesquisaID();
        printf("------------------------------------------------\n");
        printf("\tPESQUISAR\n");
        printf("------------------------------------------------\n");
        printf("1 - Pesquise o ID do jogador.\n");
        printf("2 - Sair.\n");

        printf("\nEscolha uma opcao:");
        scanf("%i", &opc);

        switch (opc)
        {
            // pesquisar time pelo id
        case 1:
            system("clear");
            printf("\nDeseja pesquisar mais ?\n s - sim \n n - nao\n");
            printf("opcao:");
            setbuf(stdin, NULL);
            scanf("%c", &opc2);
            setbuf(stdin, NULL);
            break;
            // pesquisar time pelo tecnico
        case 2:
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


void menu()
{
    int opc;

    do
    {

        cabecalho();
        printf("1 - Cadastrar jogador\n");
        printf("2 - Listar todos os jogadores\n");
        printf("3 - Pesquisar\n");
        printf("4 - Remover jogador\n");
        printf("5 - Sair\n");

        printf("\nEscolha uma opcao:");
        scanf("%i", &opc);

        switch (opc)
        {
        case 1:
            system("clear");
            printf("---------------------------\n");
            printf("CADASTRAR JOGADOR \n");
            printf("---------------------------\n");
            cadastro();
            break;

        case 2:
            system("clear");
            printf("------------------------------------------------\n");
            printf("\tLISTAR TODOS OS JOGADORES \n");
            printf("------------------------------------------------\n");
            Lista();
            //listar
            
            break;

        case 3:
      
            pesquisar();
            break;

        case 4:
        //remove
            break;

        case 5:
            printf("\nObrigado por sua visita !!\n");
            break;

        default:
            printf("\nOpcao invalida, tente novamente\n");
            break;
        }

    } while (opc != 5);

} // fim da função menu
int main(){
    menu();



    return 0;
}