# Controle de Motor de Passo com STM32F401

Este repositório contém um projeto que controla um motor de passo utilizando um microcontrolador STM32F401 Blackpill. O sistema utiliza um display LCD 16x2 para exibir o ângulo do motor, a direção de movimento e seu estado atual (parado ou girando). O controle do motor é realizado através de 4 botões físicos.

## Descrição do Projeto

O projeto consiste em:

- **Microcontrolador**: STM32F401 Blackpill
- **Display**: LCD 16x2
- **Motor**: Motor de passo NEMA controlado pelo driver A4988
- **Botões**:
  - Botão "Play": Inicia o movimento do motor.
  - Botão de Direção: Altera a direção de movimento (horário/anti-horário).
  - Botão Incrementar: Aumenta o ângulo a ser movido em passos de 1,8 graus.
  - Botão Decrementar: Diminui o ângulo a ser movido em passos de 1,8 graus.
  
- **Componentes Adicionais**:
  - Capacitor de 100uF entre os pinos de 12V e GND do driver do motor.
  - LED que pisca para indicar que o microcontrolador está executando o código.

## Estrutura do Repositório

A estrutura de pastas do repositório é a seguinte:

- **[HARDWARE/](HARDWARE/)**: Contém o desenho esquemático das ligações feitas em protoboard.
- **[FIRMWARE/](FIRMWARE/)**: Contém todo o código utilizado no microcontrolador.

## Como Usar

1. **Configuração do Hardware**: Monte o circuito conforme o esquema na pasta HARDWARE.
2. **Carregamento do Firmware**: Carregue o código presente na pasta FIRMWARE para o microcontrolador STM32F401 através de um J-LINK ou um ST/LINK.
3. **Operação**: Utilize os botões para controlar o motor. O ângulo atual, a direção e o estado do motor que serão exibidos no LCD.

![schematic](HARDWARE/schematic.png)

## Licença

Este projeto está licenciado sob a MIT License - veja o arquivo [LICENSE](LICENSE) para mais detalhes.



