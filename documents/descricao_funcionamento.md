# Descrição do Funcionamento

A lixeira inteligente é um sistema projetado para otimizar a gestão de resíduos, utilizando sensores de nível de resíduos e conectividade com a Internet das Coisas (IoT). O funcionamento do sistema é dividido nas seguintes etapas:

## Componentes Principais

- **Arduino Uno**: Plataforma de prototipagem eletrônica que controla a lógica do sistema.
- **ESP32**: Módulo Wi-Fi que permite a comunicação do sistema com a nuvem via protocolo MQTT.
- **Sensor Ultrassônico HC-SR04**: Mede a distância do nível de resíduos na lixeira.
- **Módulo Relé de 1 Canal**: Envia notificações quando a lixeira está cheia.
- **LCD 1602**: Exibe informações sobre o nível de resíduos e status da lixeira.
- **Bateria de Íon de Lítio (18650)**: Fonte de alimentação do sistema.

## Processo de Funcionamento

1. **Detecção do Nível de Resíduos**: O sensor ultrassônico mede continuamente a altura dos resíduos. Quando a altura ultrapassa um limite predefinido, um sinal é enviado ao Arduino.
2. **Notificação de Coleta**: O Arduino ativa o módulo relé, que aciona um LED de alerta e envia uma mensagem ao broker MQTT, informando que a lixeira precisa ser coletada.
3. **Monitoramento em Tempo Real**: Os dados são enviados à nuvem, permitindo que gestores acessem informações em tempo real através de um painel web ou aplicativo.
