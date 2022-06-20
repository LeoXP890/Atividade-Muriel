#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "times.h"
#include "jogador.h"
#include "partida.h"
#include "login.h"
typedef struct
{
    char nickname[50];
    char senha[50];
} Login;
//----------------------------------------------------------------------------
void criarConta()
{
    Login login;
    int rotacao = 9;
    char y;
    

    FILE *arquivo;
    printf("------------------------------------------------\n");
    printf("\t\t CRIAR CONTA \n");
    printf("------------------------------------------------\n");

    printf("\nE necessario que o seu nickname e sua senha nao ultrapassem 10 LETRAS !!\n");

    arquivo = fopen("login.dat", "ab+");
    if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n");
        exit(1); // finaliza o programa
    }            // if

    printf("\nCrie um nickname com ate 10 letras:");
    setbuf(stdin, NULL);
    fgets(login.nickname, 20, stdin);
    login.nickname[strcspn(login.nickname, "\n")] = '\0';

    if (strlen(login.nickname) > 10)
    {
        printf("\t\nVoce ultrapassou a quantidade de caracteres permitida.\n");
        printf("Tente novamente!\n");
    };
    // senha
    printf("\nCrie uma senha com ate 10 letras:");
    setbuf(stdin, NULL);
    fgets(login.senha, 50, stdin);
    login.senha[strcspn(login.senha, "\n")] = '\0';

    if (strlen(login.senha) > 10)
    {
        printf("\tSenha ultrapassou a quantidade permitida de caracteres\n");
        printf("\tTente novamente\n");
    }

    for (int j = 0; login.senha[j] != '\0'; j++)
    {
        y = login.senha[j];
        if (y >= 'a' && y <= 'z')
        {
            y = y + rotacao;
            if (y > 'z')
            {
                y = y - 'z' + 'a' - 1;
            }
            login.senha[j] = y;
        } // if
    }     // for

    fwrite(&login, sizeof(Login), 1, arquivo);

    fclose(arquivo);

} // fim da função cadastrar
//----------------------------------------------------------------------------
void entrarConta()
{
    Login login;
    FILE *arquivo;
    char nick[20];
    char senha[20];
    int rotacao = 9;

    char y;

    printf("------------------------------------------------\n");
    printf("\t\t ENTRAR \n");
    printf("------------------------------------------------\n");

    printf("Nickname:");
    setbuf(stdin, NULL);
    fgets(nick, 20, stdin);
    nick[strcspn(nick, ("\n"))] = '\0';

    printf("Senha:");
    setbuf(stdin, NULL);
    fgets(senha, 20, stdin);
    senha[strcspn(senha, "\n")] = '\0';

    arquivo = fopen("login.dat", "rb+");
    if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n");
        exit(1); // finaliza o programa
    }

    while (fread(&login, sizeof(Login), 1, arquivo) == 1)
    {
        for (int j = 0; login.senha[j] != '\0'; j++)
        {
            y = login.senha[j];
            if (y >= 'a' && y <= 'z')
            {
                y = y - rotacao;
                if (y < 'a')
                {
                    y = y + 'z' - 'a' + 1;
                }
                login.senha[j] = y;
            } // if
            login.senha[j] = y;
        } // for
    }

    if (strcmp(nick, login.nickname) == 0 && strcmp(senha, login.senha) == 0)
    {
        printf("SEJA BEM VINDO !\n");
        // chamar menu principal
    }
    else
    {
        printf("Nickname ou senha invalidos\nTente novamente\n");
    }

    fclose(arquivo);
}
//----------------------------------------------------------------------------

void aberturaLogin()
{
    int opc;
    printf("------------------------------------------------\n");
    printf("\t\t NBA \n");
    printf("------------------------------------------------\n");

    printf("\t1- Entrar\n");
    printf("\t2- Criar conta\n");
    printf("Opcao:");
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        system("clear");
        entrarConta();
        break;
    case 2:
        system("clear");
        criarConta();
        break;
    default:
        printf("Opcao invalida, tente novamente\n");
        aberturaLogin();
        break;

    } // switch

} // fim da função abertura
  //----------------------------------------------------------------------------








/*int main()
{
    aberturaLogin();
    return 0;
}*/