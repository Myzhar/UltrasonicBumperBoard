# SonarBoard
Firmware for **STm32F303 Nucleo32** board to handle up to four **HC-SR04** ultrasonic range sensors

## Description
*HC-SR04* module is a 2-wires driven distance sensor. It is triggered by a TTL 10 microsec pulse on *"Trig"* pin and the measured distance is proportional to the duration of the echo pulse received on the *"Echo"* pin.

* The Trig pulse is generated using a PWM timers programmed in "One Pulse mode".
* The Echo duration is measured using a timer in "Input Capture" coupling two channels: channel 1 triggers on rising edge on echo reception, channel 2 triggers on falling edge when the echo stops.

## Sensor Configuration
The sensors are triggered coupled two by two to avoid echo interferences, only two triggers are generated to enable two sonars, 4 timers are required to measure the 4 echos.

Typical configuration:

          --- Sonar #0 ----------- Sonar #1 ---
          |                                   |
          |                                   |
          |                                   |
          --- Sonar #3 ----------- Sonar #2 ---
          
  - The sensor **#0** and the sensor **#2** receive the same trigger
  - The sensor **#1** and the sensor **#3** receive the same trigger

## Pinout

### Nucleo32
* **PA6** - Trigger sensor #0 #2 [*TMR16 CH1 PWM SINGLE SHOT*] 
* **PA7** - Trigger sensor #1 #3 [*TMR17 CH1 PWM SINGLE SHOT*] 
* **PA8** - Echo sensor #0 [*TMR1 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PA0** - Echo sensor #1 [*TMR2 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PB4** - Echo sensor #2 [*TMR3 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PA2** - Echo sensor #3 [*TMR15 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PA9** - USART 1 TX
* **PA10** - USART 1 RX
* **PB3** - Board Green Led
 
**NOTE #1:** The Nucleo32 board is powered by an external 5V power supply, so **SB1** must be opened.

**NOTE #2:** To enable the input pin for *Sensor #3 echo* on **PA2** you need to open **SB3** and **SB2**, disabling USART2 for Virtual COM Port - [For further information see Table 6 on document **UM1956** "STM32 Nucleo-32 boards - User Manual" - http://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/DM00231744.pdf] 

![alt tag](https://github.com/Myzhar/SonarBoard/blob/develop/Images/STm32F303.PNG)

## Serial communication
Baudrate 115200 8N1
 
### Serial output

### Serial input
