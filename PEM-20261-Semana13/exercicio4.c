struct Aluno {
    char nome[50];
    int matricula;
    float media;
};

void exercicio_04() {
    printf("--- Exercício 04: Mapa de Endereços de Struct ---\n");
    struct Aluno a1 = {"Joao", 12345, 9.5};

    printf("Endereco de nome:     %p\n", (void*)&a1.nome);
    printf("Endereco de matricula:%p\n", (void*)&a1.matricula);
    printf("Endereco de media:    %p\n", (void*)&a1.media);

    /* 
       COMENTÁRIO EXPLICATIVO:
       Os endereços geralmente NÃO são perfeitamente consecutivos byte a byte 
       devido ao "padding" (preenchimento). O compilador insere bytes vazios 
       entre as variáveis para alinhar a memória e melhorar a performance do processador.
       Por exemplo, após o array de chars (50 bytes), pode haver 2 bytes de lixo 
       para que o 'int' (que precisa de alinhamento de 4 bytes) comece no endereço certo.
    */
    printf("\n");
}