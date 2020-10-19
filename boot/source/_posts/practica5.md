---
title: Práctica 5
date: 2020-10-08 17:35:28
tags:




---

La tercer práctica consiste en encender y apagar cuatro LEDs con un intervalo de un medio segundo entre ellos en dirección a la derecha, y luego a la izquierda para mantener la ilusión de movimiento. Se aprovecha además, para introducir el concepto de estructuras de control, tal como el ciclo for. <!-- more -->

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
int tiempo = 500; // medio segundo
```

### Inicialización

```cpp
void setup()
{
  for (int i = 0; i <= 3; i++)
  {
    pinMode(i, OUTPUT);
  }
}
```

### Ciclo

```cpp
void loop()
{
  //encendiendo leds
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(i, HIGH);
    delay(tiempo);
  }
  //apagando leds
  for (int i = 3; i >= 0; i--)
  {
    digitalWrite(i, LOW);
    delay(tiempo);
  }
}
```



[Código de ejemplo aquí.](https://github.com/xtrs84zk/SistemasEmbebidos/blob/main/src/Practica5.ino)