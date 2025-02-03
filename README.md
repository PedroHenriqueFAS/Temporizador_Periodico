# Projeto: Temporizador_Periodico

## 📝 Sobre o Projeto

Este projeto implementa um semáforo utilizando o Raspberry Pi Pico e LEDs. O programa controla o ciclo de cores (vermelho, amarelo e verde) em intervalos de 3 segundos.

## 🎯 Funcionalidades

O código utiliza um temporizador repetitivo para alternar os LEDs, representando o ciclo de um semáforo:

-Vermelho aceso por 3 segundos\
-Amarelo aceso por 3 segundos\
-Verde aceso por 3 segundos

Os LEDs são controlados pelos pinos GPIO do Raspberry Pi Pico:

-Pino 11: LED Vermelho\
-Pino 12: LED Amarelo\
-Pino 13: LED Verde

A cada ciclo, a função repeating_timer_callback é chamada para atualizar o estado dos LEDs.

## 📂 Estrutura do Projeto

O projeto é composto pelos seguintes arquivos principais:

- `Temporizador_Periodico.c`: Contém a lógica principal do sistema.
- `CMakeLists.txt`: Arquivo de configuração do CMake para compilação do projeto.
- `pio_matrix.pio.h`: Arquivo gerado a partir do código PIO utilizado para o controle dos LEDs.

## 🛠️ Requisitos

- Raspberry Pi Pico
- SDK do Pico instalado
- CMake
- Compilador compatível com C e C++

## ⚙️ Compilação e Execução

1. Clone o repositório do projeto:
   ```sh
   git clone https://github.com/PedroHenriqueFAS/Temporizador_Periodico
   cd Temporizador_Periodico
   ```
2. Crie um diretório de build e entre nele:
   ```sh
   mkdir build
   cd build
   ```
3. Execute o comando CMake para configurar a compilação:
   ```sh
   cmake ..
   ```
4. Compile o projeto:
   ```sh
   make
   ```
5. Faça o upload do binário gerado para a Raspberry Pi Pico.

## 👥 Colaboradores

1. **Pedro Henrique Ferreira Amorim da Silva** - [GitHub](https://github.com/PedroHenriqueFAS)

## 📜 Licença

Este projeto está licenciado sob a Licença MIT. Para mais detalhes, consulte o arquivo LICENSE.

