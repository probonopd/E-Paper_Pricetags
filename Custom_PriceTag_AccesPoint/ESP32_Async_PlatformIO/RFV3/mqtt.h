#pragma once
#include <PubSubClient.h>

const char* MQTT_BROKER = "192.168.0.10"; // TODO: Do not hardcode, use WiFiManager
WiFiClient espClient;
PubSubClient client(espClient);
long lastReconnectAttempt = 0;

boolean reconnect() {
  if (client.connect("arduinoClient")) {
    // Once connected, publish an announcement...
    client.publish("displays/receive","hello world");
    // ... and resubscribe
    client.subscribe("displays/send");
  }
  return client.connected();
}
