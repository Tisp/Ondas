# Ondas

Vamos simular uma chuva fantasiosa em um planeta imagináio, gerando ondas irreais. Para compor um cenário um pouco mais surrealista, um material especial cobre toda a borda do lago retangular, absorvendo completamente as ondas que nela tocam

## 1) O programa

O programa deve simular uma chuva neste lago. Cada gota produz uma onda irreal que se propaga de acordo com a função:

    h(ρ, t) = (ρ − v · t) · e(−(ρ−v·t)2) · e−t/10

onde h  é a altura da água com relação á superfície do lago em repouso. Os parâmetros são ρ, em coordenadas polares (ρ, θ), a partir do ponto de queda da onda e t, o tempo desde a queda da gota. Note que h não depende de θ. A velocidade de propagação da onda é v. Valores da altura (ou profundidade) menor do que ε podem ser desprezados.Os parâmetros de simulação são fornecidos em um arquivo texto, passado como primeiro argumento. Os outros argumento é o número de processadores utilizado.

## 2) Arquivo de entrada
O arquivo de entrada possui os seguintes parâmetros, um por linha:
* Tamanho do lago, um par de valores entre parênteses: (larg, alt)
*  Tamanho da matriz, outro par de valores entre parˆenteses: (L,H) • Tempo (virtual) de simulação: T
*  Velocidade de propagação da onda: v
* Limiar de altura ε
* Número de iterações: Niter
* Probabilidade de surgimento de uma gota, por iteração: P
* Semente para o gerador aleatórios: s

Este  é um exemplo de entrada:
```
(1000,2000)
(500,100)
120
10
0.001
1000
12.4
7623891
```
## 3) Simulação

A simulação é feita por uma sequência de Niter passos, chamados timesteps. Cada timestep equivale, portanto, a T segundos.
 Niter
Em cada passo estas operações devem ser efetuadas, nesta ordem:
1. Calcular o nível do lago em cada ponto (propagação das ondas).
2. Verificar, por sorteio, se uma nova gota deve aparecer e sortear sua posição.

## 4) Saída

A saída será um arquivo *PPM*, tipo P3(colorido ASCII), contendo a imagem final do lago.
Considere a superfície do lado em repouso como altura 0 e representados em preto. Valores postivos devem ser representados em azul e negativos em vermelho.
