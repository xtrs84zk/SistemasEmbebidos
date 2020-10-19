---
title: Práctica 3
date: 2020-10-07 17:25:28
tags:


---

La tercer práctica consiste en encender y apagar cuatro LEDs con un intervalo de un segundo entre ellos. <!-- more -->

## Materiales

- 4 LED.
- 1 Particle photon.
- 1 Resistencia 220 Ohms.
- 12 Cables dupont.

## Configuración física

// aquí va la manera en que se conectan los pines

## Código

### Declaración

```cpp
int led1 = D0;
int led2 = D1;
int led3 = D2;
int led4 = D3;

int tiempoS = 1000; 
```

### Inicialización

```cpp
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}
```

### Ciclo

```cpp
void loop() {
  digitalWrite(led1, HIGH); // primer led
  delay(tiempoS);
  digitalWrite(led2, HIGH); // segundo led
  delay(tiempoS);
  digitalWrite(led3, HIGH); // tercer led
  delay(tiempoS);
  digitalWrite(led4, HIGH); // cuarto led
  delay(tiempoS);
}
```



[Código de ejemplo aquí.](https://github.com/xtrs84zk/SistemasEmbebidos/blob/main/src/Practica3.ino)

