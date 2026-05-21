struct Produto {
    char nome[40];
    float preco;
    int estoque;
};

void exercicio_06() {
    printf("--- Exercício 06: Struct via Ponteiro ---\n");
    struct Produto p1;
    struct Produto *ptr = &p1;

    // 1. Usando (*ptr).campo (Desreferenciação explícita)
    // Precisamos dos parênteses porque . tem prioridade maior que *
    (*ptr).preco = 10.50;
    (*ptr).estoque = 100;
    // strcpy((*ptr).nome, "Caneta"); // Simplificando para não incluir string.h aqui, vamos assumir preenchimento manual ou ignorar nome para focar na sintaxe
    
    printf("Usando (*ptr).campo -> Preco: %.2f, Estoque: %d\n", (*ptr).preco, (*ptr).estoque);

    // 2. Usando ptr->campo (Operador seta - sintaxe açúcar)
    ptr->preco = 20.00;
    ptr->estoque = 50;
    
    printf("Usando ptr->campo   -> Preco: %.2f, Estoque: %d\n", ptr->preco, ptr->estoque);
    
    /* 
       COMENTÁRIO: 
       ptr->campo é exatamente equivalente a (*ptr).campo. 
       É apenas uma forma mais limpa e legível de escrever.
    */
    printf("\n");
}