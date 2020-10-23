---
title: Práctica 10
date: 2020-10-21 17:05:18
tags:
---

La décima consiste en medir el valor analógico desde GND y, posteriormente, desde 3.3v para ejemplificar el uso de las entradas analógicas a través de A0. El valor obtenido se imprime al puerto serial que será leído desde la computadora utilizando el comando **particle serial monitor**.

 <!-- more -->

## Materiales

- 1 Particle Photon.
- 1 Cable USB para datos.
- 1 Cable dupont.

## Configuración física

Previamente, se debe conectar el mismo cable usb tanto al dispositivo Particle Photon, como a la computadora que se esté utilizando. En caso de no contar con el particle-cli ya instalado, se puede obtener a través de node con la instrucción **npm i -g particle-cli** ; para Windows y demás, favor de revisar [la documentación](https://docs.particle.io/tutorials/developer-tools/cli/).

<table>
<tr>
<th><img src="../assets/cable-A0-a-GND.png" alt="Cable de A0 a GND"></th>
<th><img src="../assets/serial-monitor-A0-GND.png" alt="Monitor serial en GND"></th>
<th>Se conecta el cable desde la entrada analógica A0 al pin GND y se mide la respuesta en el puerto serial.</th>
</tr>
</table>

<table>
<tr>
<th><img src="../assets/cable-A0-a-3v.png" alt="Cable de A0 a 3.3v"></th>
<th><img src="../assets/serial-monitor-A0-3v.png" alt="Monitor serial en 3.3v"></th>
<th>Se conecta el cable desde la entrada analógica A0 al pin 3.3v y se mide la respuesta en el puerto serial.</th>
</tr>
</table>

## Código

### Declaración

```cpp
double lectura = 0; // se declara e inicializa la variable para almacenar la lectura
```

### Inicialización

```cpp
void setup()
{
    pinMode(A0, INPUT); // se declara la entrada analógica A0 como entrada
    Serial.begin(9600); // se inicializa el puerto serial para el monitoreo
}
```

### Ciclo

```cpp
void loop()
{
    lectura = analogRead(A0); // se lee la entrada analógica A0 que proporciona valores de 0-4095
    Serial.print("La lectura en A0 es: ");
    Serial.println(lectura); // se imprime el valor en lectura
    delay(1000);             // esperando 1 segundo entre cada instalación
}
```

[Código de ejemplo aquí.](https://github.com/xtrs84zk/SistemasEmbebidos/blob/main/src/Practica10.ino)
