# Portafolio de Microcontroladores con ESP32

**Autor:** Josué Eliseo Jiménez Herrera  
**Institución:** Universidad Agraria del Ecuador  
**Carrera:** Computación  
**Asignatura:** Programación y Manejo de Microcontroladores  
**Semestre y paralelo:** 10 SB  
**Docente:** Ing. Karina Real Avilés, MSc.

## Práctica 01 LED parpadeante

- Código físico: [src/main.cpp](Practica%2001-led/src/main.cpp).
- [Configuración PlatformIO](Practica%2001-led/platformio.ini).
- [Simulación funcional en Wokwi](https://wokwi.com/projects/478903973893281793).
- Archivos de simulación: `Wokwi/Practica01-led`.
- Montaje físico: GPIO4 → resistencia de 220 Ω → ánodo del LED; cátodo → GND.
- Simulación: GPIO2 → resistencia de 220 Ω → ánodo del LED; cátodo → GND.
- Temporización: encendido 500 ms y apagado 500 ms; período de 1 s y frecuencia de 1 Hz.

Se conserva el programa de la guía. En PlatformIO se incluye explícitamente `Arduino.h` y se utiliza GPIO4; en Wokwi se utiliza GPIO2.

## Entorno de desarrollo

VS Code con PlatformIO IDE. Abrir la carpeta `Practica 01-led`, que contiene `platformio.ini`:

```ini
[env:esp32dev]
platform = espressif32 @ 6.12.0
board = esp32dev
framework = arduino
monitor_speed = 115200
```

La versión se fija para reproducir el entorno con Arduino ESP32 2.0.17.

```sh
pio run
pio run --target upload
```

`monitor_speed` prepara el monitor para futuras prácticas; este programa no imprime por serial. `.pio/` se excluye mediante `.gitignore` porque contiene archivos generados.

## Características del chip ESP32

Según la introducción del [ESP32 Series Datasheet v5.3](https://documentation.espressif.com/esp32_datasheet_en.pdf):

1. CPU Xtensa LX6 de 32 bits, con uno o dos núcleos según la variante.
2. Frecuencia de hasta 240 MHz.
3. 520 KB de SRAM y 448 KB de ROM.
4. Wi-Fi 802.11 b/g/n de 2,4 GHz y Bluetooth 4.2 BR/EDR y Bluetooth LE.
5. 34 GPIO programables en el chip; seis son solo de entrada y algunos se reservan para memoria o arranque.

No todos los GPIO del chip están disponibles como salidas en la placa. En esta práctica se usa GPIO4.

**Chip:** circuito integrado ESP32 con CPU, memoria y periféricos. **Módulo:** chip, flash, cristal y antena en un conjunto. **Placa:** módulo más regulador, USB-UART, botones y conectores. El módulo físico fotografiado lleva la inscripción ESP-32; la variante comercial completa no se distingue con certeza.

## Resistencia del LED

Para el LED rojo simulado se adopta una caída de 2,0 V y una corriente de diseño de 6 mA:

`R = (3,3 V - 2,0 V) / 0,006 A = 216,7 Ω`.

Se usa el valor comercial 220 Ω, con corriente aproximada de 5,9 mA. El LED blanco físico tiene una caída directa diferente; esta cuenta no es una medición de ese LED.

## Referencias

- Espressif Systems. ESP32 Series Datasheet v5.3. https://documentation.espressif.com/esp32_datasheet_en.pdf
- PlatformIO. Espressif ESP32 Dev Module. https://docs.platformio.org/en/latest/boards/espressif32/esp32dev.html
- PlatformIO. Release 6.12.0. https://github.com/platformio/platform-espressif32/releases/tag/v6.12.0

## Lista de prácticas

1. Entorno de desarrollo, GitHub, LED con ESP32 y simulación en Wokwi.
