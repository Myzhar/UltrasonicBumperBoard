# SonarBoard
Firmware for STM32F401 Nucleo board to handle up to four HC-SR04 Sonar Sensor

## Sonar Configuration
The sonars are driven coupled two by two to avoid echo interferences. 
Typical configuration:

          --- Sonar #0 ----------- Sonar #1 ---
          |                                   |
          |                                   |
          |                                   |
          --- Sonar #3 ----------- Sonar #2 ---
          
  - The sonar **#0** and the sonar **#2** receive the same trigger
  - The sonar **#1** and the sonar **#3** receive the same trigger

## Pinout
* **PB8** - Trigger Sonar #0 #2 [*TMR11 CH1 PWM SINGLE SHOT*] 
* **PB9** - Trigger Sonar #1 #3 [*TMR10 CH1 PWM SINGLE SHOT*] 
* **PA8** - Echo Sonar #0 [*TMR1 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PA0** - Echo Sonar #1 [*TMR2 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PA6** - Echo Sonar #2 [*TMR3 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PB6** - Echo Sonar #3 [*TMR4 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PA2** - USART 2 TX
* **PA3** - USART 2 RX
 
## Serial communication
Baudrate 115200 8N1
 
### Serial output

### Serial input
