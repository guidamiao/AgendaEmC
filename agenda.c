#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

struct Pessoa{
    char* nome;
    char telefone[17];

}pessoa[MAX];

void mostraMenu(){
    printf("\n\tSELECIONE UMA DAS OPCOES DA SUA AGENDA:\n");
    printf ("\n\t--------------------------------------\n");
    printf("\t1 - CADASTRAR CONTATO \n"
           "\t2 - LISTAR CONTATOS\n"
           "\t3 - PESQUISAR CONTATOS POR NOME\n"
           "\t9 - SAIR\n\n");
}

///aloca a memoria
char* alocarMemoria(int tamanho){
    char* info = NULL;
    info = (char*) malloc(sizeof(tamanho) * sizeof(char));

    if(info == NULL){
        printf("ERROR: NÃO É POSSÍVEL ALOCAR A QTD DE MEMÓRIA DA QUAL FOI REQUISITADA.");
        exit(1);
    }
    return info;
}

/// CADASTRA O NOME + TELEFONE DO QUAL DESEJA SALVAR NA AGENDA.
void cadastrarContato(int registro){
    char dados[MAX];
    printf("\n\t\tNome: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);

    //ALOCAÇAO E CÓPIA DE DADOS
    pessoa[registro].nome = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].nome, dados);

    printf("\t\tTelefone: ");
    scanf("%[^\n]s", pessoa[registro].telefone);
    setbuf(stdin, NULL);


}
/// LISTA TODOS OS CONTATOS DO QUAL CADASTROU NA OPÇÃO 1.
void listarContatos(int qtdeContatos){
    int i;
    int contagem = 1;
    for(i = 0; i < qtdeContatos; i++){
        printf("\n\tContato ID: %d\n", contagem++);
        printf("\tNome: %s\n", pessoa[i].nome);
        printf("\tTelefone: %s\n", pessoa[i].telefone);
    }
    printf("\n\n");
}

// EXIBE O CONTATO QUE FOI CADASTRADO
void exibirContato(int indice){
    printf("\n\tNome: %s\n", pessoa[indice].nome);
    printf("\tTelefone: %s\n", pessoa[indice].telefone);

}

//REALIZA A PESQUISA DOS CONTATOS
int pesquisarContato(int qtdeContatos, char* nomeBuscado){
    int i;

    for(i = 0; i < qtdeContatos; i++){
        if(strcmp(nomeBuscado, pessoa[i].nome) == 0)
            return i;
    }
    return -1;
}

int leitor(){
    int opcao;

    printf("\n\tOpcao escolhida: ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);

    return opcao;
}

int main(){
    char nome[MAX];
    int numeroRegistro = 0;
    int opcaoEscolhida;
    int indice;

    do{
        mostraMenu();
        opcaoEscolhida = leitor();

        //ESCOLHAS DO MENUS
        switch(opcaoEscolhida){
            case 1:
                cadastrarContato(numeroRegistro++);
                break;
            case 2:
                listarContatos(numeroRegistro);
                break;
            case 3:
                printf("\n\tNome: ");
                scanf("%[^\n]s", nome);
                indice = pesquisarContato(numeroRegistro, nome);

                if(indice >= 0 && indice <= 99)
                    exibirContato(indice);
                else
                    printf("\n\tCONTATO NAO CADASTRADO,SELECIONE OUTRA OPCAO OU APERTE 9 PARA SAIR.\n");
                break;
            case 9:
                printf("\n\tSaindo da agenda...");
                break;
            default:
                printf("Opcao invalida, escolha uma outra opcao!");
                mostraMenu();
                opcaoEscolhida = leitor();
        }

    }while(opcaoEscolhida != 9);
}
