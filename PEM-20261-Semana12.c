Versão final com cabeçalho ajustado e código sem comentários:

/*------------------------------------------------------------*
 *                  FATEC Ipiranga                            *
 * Disciplina: Programação Estruturada e Modular              *
 * Professor:                                                 *
 *------------------------------------------------------------*
 * Nome:                                                      *
 * RA:                                                        *
 *------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define MAX_PASTAS      50
#define LIMITE_ALERTA   300.0

typedef struct {
    char  nome[50];
    float tamanho_proprio;
    float tamanho_total;
    int   subpastas_indices[10];
    int   qtd_sub;
} Pasta;

Pasta drive[MAX_PASTAS];

float processarHierarquia(Pasta *pasta_ptr,
                          Pasta *drive_ptr,
                          int    nivel_atual,
                          int    limite_prof)
{
    if (pasta_ptr == NULL || nivel_atual > limite_prof)
        return 0.0f;

    pasta_ptr->tamanho_total = pasta_ptr->tamanho_proprio;

    for (int i = 0; i < pasta_ptr->qtd_sub; i++) {
        int    filho_idx = pasta_ptr->subpastas_indices[i];
        Pasta *filho_ptr = drive_ptr + filho_idx;

        pasta_ptr->tamanho_total +=
            processarHierarquia(filho_ptr,
                                drive_ptr,
                                nivel_atual + 1,
                                limite_prof);
    }

    for (int i = 0; i < nivel_atual; i++)
        printf("  ");

    printf("|-- %s [%.2f GB]", pasta_ptr->nome, pasta_ptr->tamanho_total);

    if (pasta_ptr->tamanho_total > LIMITE_ALERTA)
        printf(" [!] ALERTA: GARGALO DETECTADO");

    printf("\n");

    return pasta_ptr->tamanho_total;
}

int main(void)
{
    strcpy(drive[0].nome, "RAIZ");
    drive[0].tamanho_proprio      = 10.0f;
    drive[0].qtd_sub              = 2;
    drive[0].subpastas_indices[0] = 1;
    drive[0].subpastas_indices[1] = 2;

    strcpy(drive[1].nome, "Projetos_TI");
    drive[1].tamanho_proprio      = 50.0f;
    drive[1].qtd_sub              = 1;
    drive[1].subpastas_indices[0] = 3;

    strcpy(drive[2].nome, "Backups_Antigos");
    drive[2].tamanho_proprio = 350.0f;
    drive[2].qtd_sub         = 0;

    strcpy(drive[3].nome, "Videos_Aulas");
    drive[3].tamanho_proprio = 280.0f;
    drive[3].qtd_sub         = 0;

    int    limite;
    Pasta *raiz_ptr = drive;

    printf("Defina o limite de profundidade do mergulho: ");
    scanf("%d", &limite);

    printf("\n--- RELATORIO DE HIERARQUIA INTELIGENTE ---\n");
    processarHierarquia(raiz_ptr, drive, 0, limite);
    printf("-------------------------------------------\n");

    return 0;
}