#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100 //fiz com 100 só pra teste, mas podemos mudar pra menos
#define TAM_TITULO 50

//  MATRIZ 1 - TITULOS (sophia) 
char titulos[MAX_LIVROS][TAM_TITULO];
int totalLivros = 0;

// MATRIZ 2 - PAGINAS (leticia)
//funcoes e vetores que entram aqui (cadastrarPaginas, listarPaginas, etc)

// cadastro de titulo
void cadastrarTitulo() {
    if (totalLivros >= MAX_LIVROS) {
        printf("Limite de livros atingido! ;-;\n");
        return;
    }

    printf("Digite o titulo do livro: ");
    scanf(" %[^\n]", titulos[totalLivros]); //diferente do %s que para de ler no primeiro espaço,
    //o %[^\n] le a linha inteira, palavras com espaço e tudo, e so para de ler quando aperta enter

    totalLivros++;
    printf("Livro cadastrado com sucesso! :) \n");
}

// mostra os livros cadastrados
void listarTitulos() {
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    printf("\n Titulos de Livros \n");
    for (int i = 0; i < totalLivros; i++) {
        printf("%d - %s\n", i, titulos[i]);
    }
}

// ve se o titulo existe e retorna onde ele ta (-1 se nao existir)
// outras partes do trabalho (Matriz 3) podem usar essa funcao
int buscarTitulo(char titulo[]) {
    for (int i = 0; i < totalLivros; i++) {
        if (strcmp(titulos[i], titulo) == 0) {
            return i;
        }
    }
    return -1;
}

// FIM DA MATRIZ 1
// (a Matriz 3 - Emprestimos, que usa buscarTitulo(), tambem pode entrar como uma terceira secao aqui, se for o caso)

int main() {
    int opcao;

    do {
        printf("\n Menu Titulos\n");
        printf("1 - Cadastrar titulo\n");
        printf("2 - Listar titulos\n");
        printf("3 - Buscar titulo\n");
        // quando juntar com a matriz 2, adicionar aqui as opcoes dela
        // (ex: 4 - Cadastrar paginas, 5 - Listar paginas)
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            cadastrarTitulo();
        }
        else if (opcao == 2) {
            listarTitulos();
        }
        else if (opcao == 3) {
            char busca[TAM_TITULO];
            printf("Digite o titulo a buscar: ");
            scanf(" %[^\n]", busca);

            int indice = buscarTitulo(busca);
            if (indice == -1) {
                printf("Titulo nao encontrado :( \n");
            } else {
                printf("Titulo encontrado no indice %d :)\n", indice);
            }
        }
        else if (opcao == 0) {
            printf("Que pena, voce saiu :(\n");
        }
        else {
            printf("Opcao invalida \n");
        }

    } while (opcao != 0);
//ola
    return 0;
}