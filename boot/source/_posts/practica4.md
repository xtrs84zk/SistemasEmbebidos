---
title: Práctica 4
date: 2020-10-08 17:05:28
tags:



---

La cuarta práctica consiste en encender y apagar cuatro LEDs con un intervalo de un medio entre ellos en dirección a la derecha y luego a la izquierda para mantener la ilusión de movimiento. Se aprovecha además, para introducir el concepto de estructuras de control, tal como el ciclo for. <!-- more -->

## Materiales

- 4 LED.
- 1 Particle photon.
- 1 Resistencia 220 Ohms.
- 8 Cables dupont.

## Configuración física

![Cuatro LEDs, de D0 a D3](../assets/4led-en-d0-3.png)

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
  delay(tiempo);
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(i, HIGH);
    delay(tiempo);
    digitalWrite(i, LOW);
    delay(tiempo);
  }
  for (int i = 3; i > 0; i--)
  {
    digitalWrite(i, HIGH);
    delay(tiempo);
    digitalWrite(i, LOW);
    delay(tiempo);
  }
}
```



[Código de ejemplo aquí.](https://github.com/xtrs84zk/SistemasEmbebidos/blob/main/src/Practica4.ino)

