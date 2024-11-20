# Lixeira Inteligente

## Descrição

Este projeto é uma **lixeira inteligente** que utiliza sensores para monitorar o nível de resíduos e se comunica via MQTT. O objetivo é otimizar a gestão de resíduos em áreas urbanas e industriais, permitindo que os serviços de coleta sejam acionados apenas quando necessário.

## Funcionamento

A lixeira é equipada com um sensor ultrassônico que mede a altura dos resíduos na lixeira. Quando o nível de resíduos atinge um limite predefinido, uma notificação é enviada para um broker MQTT, que pode ser monitorado por um aplicativo ou sistema de gerenciamento.

## Componentes Necessários

### Hardware:

- **Placas de Desenvolvimento**:
  - Arduino Uno
  - ESP32
- **Sensores**:
  - Sensor Ultrassônico HC-SR04
- **Atuadores**:
  - Módulo Relé
- **Outros**:
  - Fios de conexão e protoboard
  - Acesso à internet (para o módulo ESP32)

### Software:

- IDE Arduino
- Bibliotecas necessárias: `PubSubClient`

## Como Reproduzir

1. **Montagem**:

   - Siga as instruções na pasta `/documents/hardware_utilizado.md` para montar os componentes.

2. **Configuração**:

   - Edite o código fonte `src/main.ino` para inserir suas credenciais de Wi-Fi e informações do broker MQTT.

3. **Upload**:

   - Carregue o código na placa de desenvolvimento usando a IDE Arduino.

4. **Operação**:

   - Monitore o nível de resíduos através do aplicativo que se conecta ao broker MQTT.

## Documentação

- Para mais informações sobre cada parte do projeto, consulte a documentação nas pastas respectivas.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir uma issue ou enviar um pull request.
