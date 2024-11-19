# Firmware do Controle de Motor de Passo

Este diretório contém o firmware utilizado para controlar o motor de passo com o microcontrolador STM32F401. O firmware foi organizado em três pastas principais, cada uma contendo diferentes componentes do sistema.

## Estrutura do Firmware

A estrutura da pasta do firmware é a seguinte:

### 1. [app](app/)

A pasta `app/` contém a aplicação principal do firmware. Aqui estão localizados os arquivos responsáveis pela lógica de controle do motor, interação com os botões e a interface com o display LCD 16x2. Esta pasta inclui:

- Código da aplicação de controle do motor.
- Inicialização e configuração do sistema.
- Implementação de funções de atualização do display e manipulação de entradas.

### 2. `drivers/`

Na pasta `drivers/`, encontra-se os drivers bare metal necessários para interagir diretamente com os periféricos do microcontrolador STM32F401. Esses drivers são implementações de baixo nível e incluem:

- Drivers para configurar os pinos (GPIO).
- Driver systick para temporização do sistema.

### 3. `shared/`

A pasta `shared/` contém códigos com um nível de abstração mais alto que os drivers. Esses arquivos são destinados a fornecer utilitários e funções reutilizáveis que podem ser utilizadas tanto pela aplicação principal quanto entre os arquivos shared, incluindo:

- Funções gerais reutilizáveis.
- Estruturas de dados comuns.

## Arquivos de Build

Dentro da pasta `app/`, terá outros arquivos importantes:

- **Makefile**: é utilizado para compilar o firmware. Ele define as regras de compilação e as dependências entre os arquivos, facilitando o processo de build do projeto.

- **linker_script.ld**: O script de link é responsável por definir a disposição da memória do microcontrolador e a alocação de seções durante a geração do arquivo binário final. É essencial para garantir que o firmware utilize adequadamente a memória disponível no STM32F401.

## Compilação

Para compilar o firmware, dentro da pasta `app/` você pode utilizar o comando:

```bash
make all
```

Já para limpar os arquivos desnecessários após compilação, utilize:

```bash
make clean
```

Certifique-se de que todas as ferramentas necessárias estejam instaladas e configuradas corretamente no seu ambiente de desenvolvimento.
