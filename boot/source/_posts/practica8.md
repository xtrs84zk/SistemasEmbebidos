---
title: Práctica 8
date: 2020-10-14 17:25:18
tags:
---

La séptima práctica consiste en incrementar lentamente la intensidad de un LED y luego decrementar al mismo ritmo. <!-- more -->

## Materiales

- 1 LED.
- 1 Particle Photon.
- 1 Resistencia 220 Ohms.
- 4 Cables dupont.

## Configuración física

// Simón

## Código

### Declaración

```cpp
int tiempo = 20;
```

### Inicialización

```cpp
void setup()
{
    pinMode(0, OUTPUT);
}
```

### Ciclo

```cpp
void loop()
{
    // Incrementando lentamente la intensidad del LED.
    for (int i = 0; i <= 255; i++)
    {
        analogWrite(0, i);
        delay(tiempo);
    }
    // Decrementando lentamente la intensidad del LED.
    for (int i = 255; i >= 0; i--)
    {
        analogWrite(0, i);
        delay(tiempo);
    }
}
```



[Código de ejemplo aquí.](https://github.com/xtrs84zk/SistemasEmbebidos/blob/main/src/Practica8.ino)