<p align="center"><img width=50% src="media/chrono_logo.png"></p>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
![Version](https://img.shields.io/badge/Version-v1.1+-blue.svg)
[![Dependencies](https://img.shields.io/badge/dependencies-up%20to%20date-brightgreen.svg)
![GitHub Issues](https://img.shields.io/github/issues/UnaiFernandez/Chrono.svg)](https://github.com/UnaiFernandez/Chrono/issues)
[![Contributions welcome](https://img.shields.io/badge/contributions-welcome-orange.svg)
![License](https://img.shields.io/badge/license-GPL-blue.svg)](https://opensource.org/licenses/gpl-license)

## Basic Overview

The idea of this project is to create a wrist watch with an arduino board. At the begining the project will be done with the board and other modules. But the idea for a final result is to develop a personalized PCB with all the needed components.

<p align="center"><img width=0% src="media/chrono_one.jpeg"></p>

## Chrono 1.1

<p align="center"><img width=50% src="media/chrono_one.jpeg"></p>

### functionalities
This first version fo chrono shows the time, the date and the day of the week printed on an LCD screen.
### materials
The following list contains the materials to build the 'Chrono1.1'.

- Arduino UNO
- LCD + I2C module
- DS1302 RTC module

The two modules can be bought mounted. However the modules can be mounted by hand having all the needed materials. In that case the materials required will be the following.

- Arduino UNO
- HD4478D (LCD)
- PCF8574 (I2C)
- DS1302 (RTC)
- 10kΩ resistor (x6)
- 330Ω resistor
- 32.768kHz oscillator
- CR2032-BS-2-1 battery holder
- 3V coin cell
### schema
<p align="center"><img width=80% src="media/chrono1_1_design.png"></p>


## Chrono 1.2

### functionalities
The functionalities of this second version of Chrono 1 does not change. The only variation on the project is that the ATMEGA328P-PU is used separated instead of using the whole arduino board. This change will let us making a more personalized project.
### materials
The following list contains the materials to build the 'Chrono1.2'.

- Arduino UNO
- LCD + I2C module
- DS1302 RTC module

The two modules can be bought mounted. However the modules can be mounted by hand having all the needed materials. In that case the materials required will be the following.

- Arduino UNO
- HD4478D (LCD)
- PCF8574 (I2C)
- DS1302 (RTC)
- 10kΩ resistor (x6)
- 330Ω resistor
- 32.768kHz oscillator
- CR2032-BS-2-1 battery holder
- 3V coin cell

