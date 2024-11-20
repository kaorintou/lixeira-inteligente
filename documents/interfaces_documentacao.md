# Documentação das Interfaces

## Interfaces do Sistema da Lixeira Inteligente

### 1. Interface de Comunicação

A lixeira inteligente utiliza o protocolo MQTT para a comunicação entre a lixeira e o sistema de monitoramento. Esta interface permite que os dados sobre o nível de resíduos sejam transmitidos em tempo real.

#### Detalhes da Comunicação

- **Broker MQTT**: O sistema se conecta a um broker MQTT onde publica e assina tópicos.
- **Tópicos Utilizados**:
  - `lixeira/status`: Publica o status da lixeira (cheia ou não).

### 2. Interface do Usuário

A interface do usuário é acessada via um aplicativo web ou aplicativo móvel, permitindo que os gestores visualizem informações em tempo real sobre o status das lixeiras.

#### Funcionalidades da Interface do Usuário

- **Visualização em Tempo Real**: Os gestores podem monitorar o nível de resíduos das lixeiras.
- **Notificações**: Receber notificações quando a lixeira está cheia.
- **Relatórios**: Geração de relatórios sobre a eficiência da coleta de resíduos.

### 3. Integração com Sensores e Atuadores

A lixeira inteligente integra diversos componentes para garantir um funcionamento eficiente:

- **Sensor Ultrassônico HC-SR04**: Mede continuamente a distância até o nível de resíduos. Quando a lixeira está cheia, envia um sinal ao Arduino.
- **Módulo Relé de 1 Canal**: Recebe o sinal do Arduino para ativar um LED de alerta e notificar a necessidade de coleta.
