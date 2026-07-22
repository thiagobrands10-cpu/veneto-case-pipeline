#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char data[11];      // Formato: AAAA-MM-DD
    char indicador[20]; // CDI, IPCA, DOLAR, IBOVESPA
    double valor;       // Valor numérico da cotação/taxa/índice
} RegistroMercado;

void limparEDatar(RegistroMercado *reg) {
    if (reg->valor < 0) {
        reg->valor = 0.0; // Tratamento básico de dados inconsistentes
    }
}

int main() {
    // Simulando dados extraídos das séries (últimos 5 anos)
    RegistroMercado dados[] = {
        {"2021-07-22", "CDI", 4.15},
        {"2021-07-22", "IPCA", 0.53},
        {"2021-07-22", "DOLAR", 5.12},
        {"2021-07-22", "IBOVESPA", 125000.00},
        {"2026-07-22", "CDI", 10.50},
        {"2026-07-22", "IPCA", 0.35},
        {"2026-07-22", "DOLAR", 5.50},
        {"2026-07-22", "IBOVESPA", 128000.00}
    };

    int total_registros = sizeof(dados) / sizeof(dados[0]);

    // Salvando o resultado tratado na pasta data/
    FILE *file = fopen("data/dados_tratados.csv", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para gravação na pasta data/.\n");
        return 1;
    }

    fprintf(file, "data,indicador,valor\n");

    for (int i = 0; i < total_registros; i++) {
        limparEDatar(&dados[i]);
        fprintf(file, "%s,%s,%.2f\n", dados[i].data, dados[i].indicador, dados[i].valor);
    }

    fclose(file);
    printf("Pipeline em C executado com sucesso! Arquivo 'data/dados_tratados.csv' gerado.\n");

    return 0;
}
