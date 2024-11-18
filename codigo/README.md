# Código da Lixeira Inteligente

Este repositório contém o código fonte para o funcionamento da lixeira inteligente.

## Estrutura do Código

- `codigo_fonte.ino`: Código principal que controla a lixeira inteligente, mede o nível de resíduos e se comunica via MQTT.

## Dependências

- Biblioteca `PubSubClient` para comunicação MQTT.
- Biblioteca `WiFi` para conexão com a rede.

## Como Usar

1. **Configuração**: Edite as constantes `ssid`, `password` e `mqtt_server` no código fonte `codigo_fonte.ino`.
2. **Upload**: Carregue o código na sua placa Arduino Uno através da IDE Arduino.
3. **Monitoramento**: Utilize um cliente MQTT para monitorar as mensagens publicadas no tópico `lixeira/status`.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir uma issue ou enviar um pull request.
