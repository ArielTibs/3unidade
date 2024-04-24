#ifndef ESTOQUE_H
#define ESTOQUE_H

typedef struct
{
    char nome[100];
    int quantidade;
    float valor_unitario;
} ItemEstoque;

void menuEstoque();
int compararItens(const void *a, const void *b);
float calcularValorTotalEstoque(ItemEstoque *estoque, int num_itens);
void gerarListaEstoque(ItemEstoque *estoque, int num_itens);

#endif /* ESTOQUE_H */
