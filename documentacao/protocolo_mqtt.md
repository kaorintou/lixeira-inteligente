# Protocolo MQTT

O projeto da lixeira inteligente utiliza o protocolo MQTT para comunicação entre a lixeira e o sistema de monitoramento.

## Broker MQTT

- **Broker utilizado**: Um broker MQTT que pode ser configurado para receber mensagens da lixeira.
- **Tópicos**:
  - `lixeira/status`: Publica o status da lixeira, informando se está cheia ou não.

## Mensagens

As mensagens publicadas no tópico seguem o formato JSON. Por exemplo:

```json
{
  "status": "cheia"
}
```
