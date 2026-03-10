#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 100 // Definição para evitar erros (embora o pedido seja simples, ajuda na segurança)

// Estrutura solicitada no trabalho
typedef struct {
    int id;
    char nome[50];
} Produto;

void limparBuffer(); // Função auxiliar para limpar scanf de strings

int main() {
    Produto produtos[TAM_MAX];
    int qtd_produtos = 0; // Quantos produtos foram cadastrados atualmente
    int opcao;

    while(1) { // Laço principal do menu
        printf("\n========== MENU PRINCIPAL ========== \n");
        printf("1 - Incluir\n");
        printf("2 - Consultar\n");
        printf("3 - Alterar\n");
        printf("4 - Excluir\n");
        printf("5 - Listar todos\n");
        printf("0 - Sair\n");
        printf("Digite a opcao desejada: ");
        
        scanf("%d", &opcao);
        limparBuffer(); // Garante que o buffer fique limpo antes de ler strings

        switch(opcao) {
            
            // --- 1. INCLUSÃO ---
            case 1:
                if(qtd_produtos >= TAM_MAX) {
                    printf("\nErro: Capacidade máxima de produtos atingida!\n");
                    break;
                }

                printf("\n-- CADASTRAR PRODUTO --\n");
                printf("Digite o ID do produto (inteiro): ");
                scanf("%d", &produtos[qtd_produtos].id);
                
                printf("Digite o Nome do produto: ");
                fgets(produtos[qtd_produtos].nome, 50, stdin); 
                // Remove o '\n' que o fgets costuma adicionar
                produtos[qtd_produtos].nome[strcspn(produtos[qtd_produtos].nome, "\n")] = 0; 

                qtd_produtos++; // Aumenta o contador de itens válidos
                printf("\nProduto incluido com sucesso!\n");
                break;

            // --- 2. CONSULTA ---
            case 2:
                if(qtd_produtos == 0) {
                    printf("\nErro: Nao ha produtos cadastrados.\n");
                    break;
                }
                
                printf("\n-- CONSULTAR PRODUTO --\n");
                printf("Digite o ID a ser consultado: ");
                int id_busca;
                scanf("%d", &id_busca);
                limparBuffer();

                int achou = 0;
                for(int i=0; i<qtd_produtos; i++){
                    if(produtos[i].id == id_busca){
                        printf("\nPRODUTO ENCONTRADO:\n");
                        printf("ID: %d\nNome: %s\n", produtos[i].id, produtos[i].nome);
                        achou = 1;
                        break;
                    }
                }
                if(!achou) printf("\nNenhum produto encontrado com esse ID.\n");
                break;

            // --- 3. ALTERACAO ---
            case 3:
                if(qtd_produtos == 0) {
                    printf("\nErro: Nao ha produtos cadastrados.\n");
                    break;
                }

                printf("\n-- ALTERAR PRODUTO --\n");
                printf("Digite o ID do produto a ser alterado: ");
                int id_altera;
                scanf("%d", &id_altera);
                limparBuffer();

                achou = 0;
                for(int i=0; i<qtd_produtos; i++){
                    if(produtos[i].id == id_altera){
                        printf("Id antigo: %d\n", produtos[i].id);
                        
                        // Solicita novo ID e Nome
                        printf("Digite o NOVO ID para este produto: ");
                        scanf("%d", &produtos[i].id);
                        
                        printf("Digite o NOVO NOME: ");
                        fgets(produtos[i].nome, 50, stdin);
                        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = 0;

                        printf("\nProduto alterado com sucesso!\n");
                        achou = 1;
                        break;
                    }
                }
                if(!achou) printf("\nProduto nao encontrado para alteracao.\n");
                break;

            // --- 4. EXCLUSAO ---
            case 4:
                if(qtd_produtos == 0) {
                    printf("\nErro: Nao ha produtos cadastrados.\n");
                    break;
                }

                printf("\n-- EXCLUIR PRODUTO --\n");
                printf("Digite o ID do produto a ser excluido: ");
                int id_exclui;
                scanf("%d", &id_exclui);
                limparBuffer();

                achou = 0;
                for(int i=0; i<qtd_produtos; i++){
                    if(produtos[i].id == id_exclui){
                        // Lógica simples de exclusão: puxar tudo para cima (shift left)
                        // Para este nivel basico da Fatec geralmente basta zerar ou mover
                        // Vou usar a logica de "Zerar dados" mantendo o tamanho do array
                        
                        produtos[i].id = 0;
                        strcpy(produtos[i].nome, "");
                        
                        // Nota: Em sistemas mais avancados fazemos a reposicao de indices.
                        // Aqui vamos considerar o array estático conforme solicitado.
                        
                        printf("\nProduto ID %d marcado como excluido.\n", id_exclui);
                        achou = 1;
                        break; 
                    }
                }
                if(!achou) printf("\nProduto nao encontrado para exclusao.\n");
                break;

            // --- 5. LISTA TODOS ---
            case 5:
                if(qtd_produtos == 0) {
                    printf("\nLista de produtos vazia.\n");
                    break;
                }

                printf("\n-- RELATORIO DE PRODUTOS --\n");
                printf("%-10s | %-40s\n", "ID", "NOME");
                printf("------------------------------------------\n");
                
                for(int i=0; i<qtd_produtos; i++){
                    printf("%-10d | %-40s\n", produtos[i].id, produtos[i].nome);
                }
                break;

            // --- SAIR ---
            case 0:
                printf("\nPrograma encerrado.\n");
                return 0; // Sai do laço principal (fim do main)

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    }
    return 0;
}

// Funcao auxiliar para limpar o buffer de entrada após ler numeros
void limparBuffer(){
    int c = getchar(); 
    while(c != '\n' && c != EOF);
}