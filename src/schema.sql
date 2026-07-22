-- Criação da tabela de Indicadores de Mercado
CREATE TABLE IF NOT EXISTS fat_indicadores_mercado (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    data_referencia TEXT NOT NULL,
    nome_indicador TEXT NOT NULL,
    valor_numerico REAL NOT NULL
);

-- Inserção dos dados consolidados pelo pipeline
INSERT INTO fat_indicadores_mercado (data_referencia, nome_indicador, valor_numerico) VALUES
('2021-07-22', 'CDI', 4.15),
('2021-07-22', 'IPCA', 0.53),
('2021-07-22', 'DOLAR', 5.12),
('2021-07-22', 'IBOVESPA', 125000.00),
('2026-07-22', 'CDI', 10.50),
('2026-07-22', 'IPCA', 0.35),
('2026-07-22', 'DOLAR', 5.50),
('2026-07-22', 'IBOVESPA', 128000.00);
