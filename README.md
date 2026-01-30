# Bit-Vector Integer Sorter (Memory-Constrained)

Implementação de alta performance em linguagem C para ordenação e filtragem de duplicatas de inteiros no intervalo [0, 5000]. O sistema utiliza um **Bitmap** para otimização extrema de memória e processamento linear.

## 🧠 Arquitetura Técnica
Diferente de implementações convencionais que utilizam vetores de inteiros (4 bytes por elemento), este sistema opera diretamente em nível de bit:
* **Eficiência de Memória**: Redução da pegada de memória em 32x ao mapear cada inteiro para um bit individual dentro de um bloco de 32 bits.
* **Complexidade Algorítmica**: Ordenação alcançada em tempo linear $O(n)$ através de uma única passagem pelo bitmap, eliminando a necessidade de algoritmos baseados em comparação (O(n log(n))$).
* **Restrições de Baixo Nível**: Desenvolvimento executado sob proibição estrita de declaração de variáveis locais, focando exclusivamente em aritmética de ponteiros e lógica bitwise pura.

## 🛠 Especificações de Implementação
A lógica baseia-se em operações bitwise fundamentais para manipulação de endereçamento:
* **Cálculo de Endereço**: `i >> 5` (equivalente a `i / 32`) para localização do bloco de memória.
* **Mapeamento de Bit**: `1 << (i & 31)` (equivalente a `i % 32`) para isolar o bit correspondente ao valor.
* **Operadores**: Utilização de `OR` inclusivo para persistência de dados e `AND` para verificação de estado.

## 🚀 Toolchain (Build e Execução)

O processo de compilação utiliza o GCC e foca na biblioteca padrão do C, garantindo portabilidade em ambientes POSIX.

### Compilação
```bash
gcc TR3_536281.c -o bit_sorter
```

### Execução (Linux/macOS)
```bash
./bit_sorter
```

### Execução (Windows)
```bash
.\bit_sorter.exe
```

## 📊 Análise de Recursos

| Atributo | Implementação Convencional | Bit-Vector Core |
| :--- | :--- | :--- |
| **Pegada de Memória** | ~20,000 Bytes (Int Array) | ~625 Bytes (Bitset) |
| **Complexidade de Tempo** | $O(n \log n)$ (Comparativo) | $O(n)$ (Acesso Direto) |
| **Eficiência de Cache** | Baixa (Espalhamento de Dados) | Altamente Otimizada (Localidade) |
| **Paradigma** | Abstração de Alto Nível | Engenharia de Sistemas (Low-Level) |
