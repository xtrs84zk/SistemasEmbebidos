---
title: Práctica 1
date: 2020-10-06 17:05:28
tags:
---

La primer práctica consiste en hacer parpadear un LED en el pin D0. <!-- more -->

## Materiales
- 1 LED.
- 1 Particle photon.
- 1 Resistencia 220 Ohms.
- 4 Cables dupont.

## Configuración física
// aquí va la manera en que se conectan los pines

## Código

### Declaración

```cpp
int led = D0;
int tiempoS = 1000;
```

### Inicialización

```cpp
void setup() {
  pinMode(led, OUTPUT);
}
```

### Ciclo

```cpp
void loop() {
  digitalWrite(led, HIGH);
  delay(tiempoS);
  digitalWrite(led, LOW);
  delay(tiempoS);
}
```



[Código de ejemplo aquí.](https://github.com/xtrs84zk/SistemasEmbebidos/blob/main/src/Practica1.ino)