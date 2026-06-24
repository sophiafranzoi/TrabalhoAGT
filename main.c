#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100 //fiz com 100 só pra teste, mas podemos mudar pra menos
#define TAM_TITULO 30
#define DISTANCIA 5

//  MATRIZ 1 - TITULOS (sophia) 
char titulos[MAX_LIVROS][TAM_TITULO];
int totalLivros = 0;

// MATRIZ 2 - PAGINAS (leticia)
int paginas[MAX_LIVROS];

// cadastro de titulo
void cadastrarTitulo() {
    int valido = 1;
    if (totalLivros >= MAX_LIVROS) {
        printf("Limite de livros atingido! ;-;\n");
        return;
    }

    printf("\nDigite o titulo do livro: ");
    scanf(" %[^\n]", titulos[totalLivros]); //diferente do %s que para de ler no primeiro espaço,
    //o %[^\n] le a linha inteira, palavras com espaço e tudo, e so para de ler quando aperta enter
    
    for (int i = 0; i < totalLivros; i++) { 
        if (strcmp(titulos[totalLivros], titulos[i]) == 0) {  
            printf("Titulo ja cadastrado\n");
            valido = 0;
            break;  
            
        }
    }
    if (valido){
        printf("\nDigite o numero de paginas desse livro: ");
        scanf("%i", &paginas[totalLivros]);

        while (paginas[totalLivros] < 0){
            printf("\nNumero de paginas invalido. Tente novamente");
            printf("\nDigite o numero de paginas desse livro: ");
            scanf("%i", &paginas[totalLivros]);
        }

        totalLivros++;
        printf("\nLivro cadastrado com sucesso! :) \n");
    }
}

// mostra os livros cadastrados
void listarTitulos() {
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    printf("\n----Titulos de Livros-----Paginas--------- \n");
    for (int i = 0; i < totalLivros; i++) {
        int tamanho;
        //for (tamanho = 0; titulos[tamanho]; tamanho++);
            //tamanho = 
            int num_espacos = DISTANCIA + TAM_TITULO - tamanho;
        printf("%d - %s  %i\n", i, titulos[i], paginas[i]); //tentar deixar alinhado como no exemplo
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
int emprestimos[MAX_LIVROS][5];
int cadastros = 0, valido, dia_inicio, dias; 
char emprestimo[TAM_TITULO];


void cadastro_especifico(){
    printf("\nDigite o titúlo que deseja cadastrar: ");
    scanf(" %[^\n]", emprestimo);

   
    if (buscarTitulo(emprestimo) != -1) {
        emprestimos[cadastros][1] = buscarTitulo(emprestimo);
        emprestimos[cadastros][2] = buscarTitulo(emprestimo);
        valido = 1;
    }
    else {
        printf("Esse titulo nao esta cadastrado na biblioteca de livros\n");
        valido = 0;
    }
    
    if (valido == 1){

        do{
            printf("\nDigite o dia do início do emprestimo:\n2 - Segunda\n3 - Terca\n4 - Quarta\n5 - Quinta\n6 - Sexta\nOpcao: "); 
            scanf("%i", &dia_inicio);

            if (dia_inicio >= 2 && dia_inicio <= 6) emprestimos[cadastros][3] = dia_inicio;
            else printf("Opcao invalida!\n");
        } while (dia_inicio < 2 || dia_inicio > 6);

        do{
            printf("\nDigite o numero de dias para o emprestimo (até 7 dias): ");
            scanf("%i", &dias);

            if (dias >= 1 && dias <= 7) emprestimos[cadastros][4] = dias;
            else printf("Numero de dias invalido!\n");
        } while (dias < 1 || dias > 7);
    }

}

int main() {
    int opcao;

    do {
        printf("\n----Menu Titulos----\n");
        printf("1 - Cadastrar titulo\n");
        printf("3 - Listar titulos\n");
        printf("4 - Buscar titulo\n");
        printf("5 - Cadastrar emprestimo\n");
        // quando juntar com a matriz 2, adicionar aqui as opcoes dela
        // (ex: 4 - Cadastrar paginas, 5 - Listar paginas)
        printf("0 - Sair\n");
        printf("--------------------\n\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            cadastrarTitulo();
        }
        else if (opcao == 3) {
            listarTitulos();
        }
        else if (opcao == 4) {
            char busca[TAM_TITULO];
            printf("Digite o titulo a buscar: ");
            scanf(" %[^\n]", busca);

            int indice = buscarTitulo(busca);
            if (indice == -1) {
                printf("\nTitulo nao encontrado :( \n");
            } else {
                printf("\nTitulo encontrado no indice %d :)\nTitulo: %s  - Paginas: %i\n", indice, titulos[indice], paginas[indice]);
            }
        }
        else if (opcao == 5){
            cadastro_especifico();
        }
        else if (opcao == 0) {
            printf("Que pena, voce saiu :(\n");
        }
        else {
            printf("Opcao invalida \n");
        }

    } while (opcao != 0);

    return 0;
}