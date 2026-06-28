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

    printf("\n----Titulos de Livros------------------Paginas--------- \n");
    for (int i = 0; i < totalLivros; i++) {
        int tamanho;
        for (tamanho = 0; titulos[i][tamanho] != '\0'; tamanho++);
        int num_espacos = DISTANCIA + TAM_TITULO - tamanho;
        printf("%d - %s", i, titulos[i]); //tentar deixar alinhado como no exemplo
        for (int j = 0; j < num_espacos; j++) {
            printf(" ");
        }
        printf("%i\n", paginas[i]);
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

// FIM DAS MATRIZES 1 E 2
// Matriz 3 
int emprestimos[MAX_LIVROS][5];
int cadastros = 0, valido, dia_inicio, dias, dia_fim; 
char emprestimo[TAM_TITULO];


   
void cadastro_especifico(){
    printf("\nDigite o titulo que deseja cadastrar: ");
    scanf(" %[^\n]", emprestimo);


    if (buscarTitulo(emprestimo) != -1) {
         int index = buscarTitulo(emprestimo); //antes salvava o indice repetido nas colunas [0] e [1] por engano
        // corrigido pra salvar o indice em [0] e o numero de paginas (paginas[indice]) em [1]
        emprestimos[cadastros][0] = index;
        emprestimos[cadastros][1] = paginas[index];
        valido = 1;
    }
    else {
        printf("Esse titulo nao esta cadastrado na biblioteca de livros\n");
        valido = 0;
    }
    
    if (valido == 1){

        do{
            printf("\nDigite o dia do inicio do emprestimo:\n2 - Segunda\n3 - Terca\n4 - Quarta\n5 - Quinta\n6 - Sexta\nOpcao: "); 
            scanf("%i", &dia_inicio);

            if (dia_inicio >= 2 && dia_inicio <= 6) emprestimos[cadastros][2] = dia_inicio;
            else printf("Opcao invalida!\n");
        } while (dia_inicio < 2 || dia_inicio > 6);

        do{
            printf("\nDigite o numero de dias para o emprestimo (ate 7 dias): ");
            scanf("%i", &dias);

            if (dias >= 1 && dias <= 7) emprestimos[cadastros][3] = dias;
            else printf("Numero de dias invalido!\n");
        } while (dias < 1 || dias > 7);

         dia_fim = dia_inicio + dias;
            while (dia_fim > 6) {
             dia_fim -= 5; // sabado e domingo nao contam, por isso pula o fim de semana
            }
        emprestimos[cadastros][4] = dia_fim;

    cadastros += 1;
    }

}
//lista os emprestimos cadastrados (Matriz 3)
    void listarEmprestimos() {
    if (cadastros == 0) {
        printf("\nNenhum emprestimo cadastrado.\n");
        return;
    }
    printf("\n%-20s%-20s%-20s%-22s%-15s\n",
           "Titulo", "Numero de Paginas", "Dia do Emprestimo", "Dias em Emprestimo", "Dia Devolucao");
    printf("---------------------------------------------------------------------------------------\n");
    for (int i = 0; i < cadastros; i++) {
        int idxLivro = emprestimos[i][0];
        int qtdPaginas = emprestimos[i][1];
        int diaInicio = emprestimos[i][2];
        int qtdDias = emprestimos[i][3];
        int diaFim = emprestimos[i][4];
        char nomeInicio[10];
        char nomeFim[10];

        // convertendo o dia de inicio pra nome
        if (diaInicio == 2) strcpy(nomeInicio, "Segunda");
        else if (diaInicio == 3) strcpy(nomeInicio, "Terca");
        else if (diaInicio == 4) strcpy(nomeInicio, "Quarta");
        else if (diaInicio == 5) strcpy(nomeInicio, "Quinta");
        else if (diaInicio == 6) strcpy(nomeInicio, "Sexta");
        else strcpy(nomeInicio, "Invalido");

        // convertendo o dia de devolucao pra nome
        if (diaFim == 2) strcpy(nomeFim, "Segunda");
        else if (diaFim == 3) strcpy(nomeFim, "Terca");
        else if (diaFim == 4) strcpy(nomeFim, "Quarta");
        else if (diaFim == 5) strcpy(nomeFim, "Quinta");
        else if (diaFim == 6) strcpy(nomeFim, "Sexta");
        else strcpy(nomeFim, "Invalido");
        printf("%-20s%-20d%-20s%-22d%-15s\n", titulos[idxLivro], qtdPaginas, nomeInicio, qtdDias, nomeFim);
    }
}

int main() {
    int opcao, certeza = 1;

    do {
        printf("\n----Menu Titulos----\n");
        printf("1 - Cadastrar titulo\n");
        printf("3 - Listar titulos\n");
        printf("4 - Buscar titulo\n");
        printf("5 - Cadastrar emprestimo\n");
        printf("6 - Listar emprestimo\n");
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
         else if (opcao == 6){
            listarEmprestimos();
        }
        else if (opcao == 0) {
            do{
                printf("Tem certeza de que deseja sair?\n1 - Nao\n2 - Sim\nOpcao: ");
                scanf("%i", &certeza);
                if (certeza == 2) printf("\nQue pena, voce saiu :(\n");
            } while (certeza != 1 && certeza != 2); 
            
        }
        else {
            printf("Opcao invalida \n");
        }

    } while (certeza == 1);

    return 0;
}