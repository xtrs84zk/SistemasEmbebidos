---
title: Práctica 9
date: 2020-10-14 17:45:18
tags:
---

La novena práctica es una práctica mixta que consiste en:

1. Secuencia de LEDs de izquierda a derecha y viceversa.

2. PWM a los 4 LEDs de 0 al 100% y del 100 al 0%.

3. Secuencia de encendido y apagado de izquierda a derecha y viceversa.

4. Se repite el ciclo.

 <!-- more -->

## Materiales

- 4 LED.
- 1 Particle Photon.
- 1 Resistencia 220 Ohms.
- 12 Cables dupont.

## Configuración física

// Simón

## Código

### Declaración

```cpp
int tiempo = 500; // tiempo entre LEDs
int tiempoPWM = 20; // tiempo entre actualizaciones PWM
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
    // Secuencia de LEDs de izquierda a derecha y viceversa
    for (int i = 0; i <= 2; i++) // encendiendo y apagando hacia la derecha
    {
        digitalWrite(i, HIGH);
        delay(tiempo);
        digitalWrite(i, LOW);
        delay(tiempo);
    }
    for (int i = 3; i >= 0; i--) // encendiendo y apagando de regreso
    {
        digitalWrite(i, HIGH);
        delay(tiempo);
        digitalWrite(i, LOW);
        delay(tiempo);
    }
    // PWM a los 4 LEDs de 0 a 100% y de 100 a 0%
    for (int i = 0; i <= 255; i++) // incrementando intensidad
    {
        analogWrite(0, i);
        analogWrite(1, i);
        analogWrite(2, i);
        analogWrite(3, i);
        delay(tiempoPWM);
    }
    for (int i = 255; i >= 0; i--) // decrementando intensidad
    {
        analogWrite(0, i);
        analogWrite(1, i);
        analogWrite(2, i);
        analogWrite(3, i);
        delay(tiempoPWM);
    }
    // Secuencia de encendido y apagado de izquierda a derecha y viceversa
    for (int i = 0; i <= 3; i++) // encendiendo leds
    {
        digitalWrite(i, HIGH);
        delay(tiempo);
    }
    for (int i = 3; i >= 0; i--) // apagando leds
    {
        digitalWrite(i, LOW);
        delay(tiempo);
    }
}
```



[Código de ejemplo aquí.](https://github.com/xtrs84zk/SistemasEmbebidos/blob/main/src/Practica9.ino)