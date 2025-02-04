# Repositório de Projetos para Raspberry Pi Pico W (EmbarcaTech)

Este repositório contém dois projetos desenvolvidos para a placa **Raspberry Pi Pico W** utilizando **CMake** e o **Pico SDK**. Esses projetos são requisitos da atividade 2 da aula síncrona do dia 29/01/2024.

## Estrutura do Repositório

```
/
|-- atividade-1-semaforo/
|   |-- atividade-1-semaforo.c
|   |-- CMakeLists.txt
|   |-- diagram.json
|   |-- pico_sdk_import.cmake
|   |-- wokwi.toml
|
|-- atividade-2-temporizador/
|   |-- atividade-2-temporizador.c
|   |-- CMakeLists.txt
|   |-- diagram.json
|   |-- pico_sdk_import.cmake
|   |-- wokwi.toml
```

## Descrição dos Projetos

### 1. Atividade 1 - Semáforo

Este projeto simula um semáforo utilizando três LEDs conectados ao Raspberry Pi Pico W. O sistema alterna entre as cores **vermelho**, **amarelo** e **verde** a cada **3 segundos**, respeitando a lógica de funcionamento de um semáforo real.

#### Funcionamento:
- O LED **vermelho** acende primeiro.
- Após **3 segundos**, acende o LED **amarelo**.
- Após **3 segundos**, acende o LED **verde**.
- O ciclo se repete indefinidamente.

A cada segundo uma mensagem é exibida no monitor serial através da rotina padrão do programa.

### 2. Atividade 2 - Temporizador

Este projeto implementa um sistema de temporização controlado por um botão. Quando pressionado, acende três LEDs simultaneamente e os desliga em intervalos programados:

#### Funcionamento:
- Pressionar o botão faz com que todos os LEDs (azul, vermelho e verde) acendam ao mesmo tempo.
- O LED **azul** apaga após **3 segundos**.
- O LED **vermelho** apaga após **6 segundos**.
- O LED **verde** apaga após **9 segundos**, finalizando a execução.
- O sistema aguarda uma nova pressão do botão para reiniciar.

## Como Executar os Projetos

### 1. Requisitos
- Placa **Raspberry Pi Pico W**
- SDK do Raspberry Pi Pico configurado
- **Visual Studio Code** com a extensão do **Raspberry Pi Pico** instalada
- **Extensão Wokwi para VS Code**

### 2. Compilando e Carregando o Código
1. Clone este repositório:
2. Abra o **VS Code** e carregue a pasta do projeto.
3. Utilize a extensão do **Raspberry Pi Pico** para compilar o projeto e carregar o firmware na placa.

### 3. Executando a Simulação com Wokwi
- Para testar o projeto sem um Raspberry Pi Pico W físico, abra o arquivo `diagram.json` no **VS Code** e execute a simulação através da extensão do **Wokwi**.

## Vídeo de demonstração dos projetos
- Segue o link com o video demonstrando o funcionamento dos projetos: <https://youtu.be/U9xZD5YipLs>

---
Desenvolvido por **David Rios Santana**

