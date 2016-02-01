# SonarBoard
Firmware for **STM32F401 Nucleo64** board and **STm32F303 Nucleo32** board to handle up to four **HC-SR04** sonar sensors

## Description
*HC-SR04* sonar is a 2-wires driven distance sensor. It is triggered by a TTL 10 microsec pulse on *"Trig"* pin and the measured distance is proportional to the duration of the echo pulse received on the *"Echo"* pin.

* The Trig pulse is generated using a PWM timers programmed in "One Pulse mode".
* The Echo duration is measured using a timer in "Input Capture" coupling two channels: channel 1 triggers on rising edge on echo reception, channel 2 triggers on falling edge when the echo stops.

## Sonar Configuration
The sonars are driven coupled two by two to avoid echo interferences, only two triggers are generated to enable two sonars, 4 timers are required to measure the 4 echos.

Typical configuration:

          --- Sonar #0 ----------- Sonar #1 ---
          |                                   |
          |                                   |
          |                                   |
          --- Sonar #3 ----------- Sonar #2 ---
          
  - The sonar **#0** and the sonar **#2** receive the same trigger
  - The sonar **#1** and the sonar **#3** receive the same trigger

## Pinout
### Nucleo64
* **PB8** - Trigger Sonar #0 #2 [*TMR11 CH1 PWM SINGLE SHOT*] 
* **PB9** - Trigger Sonar #1 #3 [*TMR10 CH1 PWM SINGLE SHOT*] 
* **PA8** - Echo Sonar #0 [*TMR1 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PA0** - Echo Sonar #1 [*TMR2 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PA6** - Echo Sonar #2 [*TMR3 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PB6** - Echo Sonar #3 [*TMR4 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PA9** - USART 1 TX
* **PA10** - USART 1 RX
* **PC1** - Board Blue PushButton
* **PA5** - Board Green Led

### Nucleo32
* **PA6** - Trigger Sonar #0 #2 [*TMR16 CH1 PWM SINGLE SHOT*] 
* **PA7** - Trigger Sonar #1 #3 [*TMR17 CH1 PWM SINGLE SHOT*] 
* **PA8** - Echo Sonar #0 [*TMR1 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PA0** - Echo Sonar #1 [*TMR2 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PB4** - Echo Sonar #2 [*TMR3 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PA2** - Echo Sonar #3 [*TMR15 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PA9** - USART 1 TX
* **PA10** - USART 1 RX
* **PB3** - Board Green Led
 
**NOTE:** To enable the input pin for *Sonar #3 echo* on **PA2** you need to open **SB3** and **SB2**, disabling USART2 for Virtual COM Port - [For further information see Table 6 on document **UM1956** "STM32 Nucleo-32 boards - User Manual" - http://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00231744.pdf] 

## Serial communication
Baudrate 115200 8N1
 
### Serial output

### Serial input
