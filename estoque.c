#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

void menuEstoque()
{
    printf("\n-- Menu Estoque --\n");
    printf("1. Listar estoque\n");
    printf("2. Adicionar item\n");
    printf("3. Remover item\n");
    printf("4. Valor do estoque\n");
    printf("5. Voltar\n");
}

int compararItens(const void *a, const void *b)
{
    ItemEstoque *item1 = (ItemEstoque *)a;
    ItemEstoque *item2 = (ItemEstoque *)b;
    return strcmp(item1->nome, item2->nome);
}

float calcularValorTotalEstoque(ItemEstoque *estoque, int num_itens)
{
    float valor_total = 0.0;
    for (int i = 0; i < num_itens; i++)
    {
        valor_total += estoque[i].quantidade * estoque[i].valor_unitario;
    }
    return valor_total;
}

void gerarListaEstoque(ItemEstoque *estoque, int num_itens) {
    FILE *arquivo;
    arquivo = fopen("lista_estoque.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir.\n");
        return;
    }
    fprintf(arquivo, "-- Estoque em Ordem Alfabética --\n");
    for (int i = 0; i < num_itens; i++) {
        fprintf(arquivo, "%s - Quantidade: %d - Valor Unitário: R$ %.2f\n", estoque[i].nome, estoque[i].quantidade, estoque[i].valor_unitario);
    }
    fclose(arquivo);
    printf("Lista de estoque salva com sucesso no arquivo 'lista_estoque.txt'.\n");
}
