# 🏠 Smart Home Automation System

## 📋 Project Overview
A comprehensive smart home automation system using ATmega32 microcontroller that automatically controls lighting and fan speed based on environmental conditions like temperature and light intensity, with fire detection safety features.

## 🎯 Features

### 🌡️ Temperature Control
- **Automatic Fan Speed Control** based on room temperature:
  - ≥ 40°C → Fan ON at 100% speed
  - ≥ 35°C → Fan ON at 75% speed  
  - ≥ 30°C → Fan ON at 50% speed
  - ≥ 25°C → Fan ON at 25% speed
  - < 25°C → Fan OFF

### 💡 Lighting Control
- **Automatic LED Control** based on ambient light intensity:
  - Intensity < 15% → All 3 LEDs ON (Red, Green, Blue)
  - Intensity 16-50% → Red + Green LEDs ON
  - Intensity 51-70% → Only Red LED ON
  - Intensity > 70% → All LEDs OFF

### 🔥 Fire Safety
- **Flame Detection** with immediate alert system
- **Buzzer Alarm** activation when fire detected
- **Critical Alert** display on LCD
- System remains in alert mode until flame is no longer detected

### 📊 Real-time Monitoring
- **LCD Display** shows:
  - First Row: "FAN is ON/OFF" status
  - Second Row: "Temp= xxC LDR= xx%" readings

## 🛠 Hardware Components

### Microcontroller & Peripherals
- **Microcontroller**: ATmega32
- **Display**: 16x2 LCD (8-bit mode)
- **Sensors**:
  - LM35 Temperature Sensor (ADC Channel 1)
  - LDR Light Sensor (ADC Channel 0) 
  - Flame Sensor (Digital Input)

### Actuators & Indicators
- **DC Motor**: Fan control via H-Bridge
- **LEDs**: Red, Green, Blue for light level indication
- **Buzzer**: Fire alarm system

### Pin Configuration
| Component | Port/Pin | Connection |
|-----------|----------|------------|
| LCD Data | PORTC | 8-bit mode |
| LCD RS | PD0 | Control |
| LCD E | PD1 | Control |
| Motor IN1 | PB0 | H-Bridge |
| Motor IN2 | PB1 | H-Bridge |
| Motor EN | PB3 | PWM (OC0) |
| Red LED | PB5 | Indicator |
| Green LED | PB6 | Indicator |
| Blue LED | PB7 | Indicator |
| Flame Sensor | PD2 | Digital Input |
| Buzzer | PD3 | Output |
| LDR | PA0 | ADC Channel 0 |
| LM35 | PA1 | ADC Channel 1 |

## 📁 Project Structure

```
Smart_Home_Automation/
│
├── Application/
│   └── Smart_Home_Automation.c
│
├── HAL/
│   ├── BUZZER/
│   │   ├── Buzzer.c
│   │   └── Buzzer.h
│   ├── DCMotor/
│   │   ├── DCMotor.c
│   │   └── DCMotor.h
│   ├── Flame_sensor/
│   │   ├── Flame.c
│   │   └── Flame.h
│   ├── LCD/
│   │   ├── LCD.c
│   │   └── LCD.h
│   ├── LDR/
│   │   ├── LDR.c
│   │   └── LDR.h
│   ├── LED/
│   │   ├── LED.c
│   │   └── LED.h
│   └── LM35/
│       ├── LM35.c
│       └── LM35.h
│
├── MCAL/
│   ├── ADC/
│   │   ├── ADC.c
│   │   └── ADC.h
│   ├── GPIO/
│   │   ├── GPIO.c
│   │   ├── GPIO.h
│   │   ├── std_type.h
│   │   └── common_macros.h
│   └── PWM/
│       ├── PWM.c
│       └── PWM.h
│
└── Documentation/
    └── Mini Project3.pdf
```

## 🔧 Drivers Implementation

### ADC Driver
- **Reference Voltage**: Configurable (AREF/AVCC/Internal 2.56V)
- **Prescaler**: F_CPU/128
- **Channels**: 8-channel 10-bit ADC
- **Features**: Polling mode with callback support

### PWM Driver  
- **Timer**: Timer0
- **Mode**: Fast PWM
- **Prescaler**: F_CPU/1024
- **Output**: Non-inverting mode on OC0 pin

### GPIO Driver
- Configurable pin/port directions
- Support for both input and output modes
- Read/Write operations for pins and ports

### Sensor Drivers
- **LM35**: Temperature measurement with linear 10mV/°C output
- **LDR**: Light intensity measurement with percentage calculation
- **Flame Sensor**: Digital fire detection

## 🚀 How to Build

### Prerequisites
- AVR GCC Compiler
- AVRDUDE for flashing
- Proteus for simulation (optional)

### Compilation
```bash
avr-gcc -mmcu=atmega32 -Os -o main.elf *.c
avr-objcopy -O ihex main.elf main.hex
```

### Flashing
```bash
avrdude -c usbasp -p m32 -U flash:w:main.hex
```

## 💡 System Operation

1. **Initialization**: All drivers and peripherals are initialized
2. **Sensor Reading**: Continuous monitoring of temperature and light
3. **Decision Making**: Automatic control decisions based on thresholds
4. **Actuation**: Motor speed and LED control based on decisions
5. **Safety Monitoring**: Continuous fire detection with highest priority
6. **Display Update**: Real-time status on LCD

## 🛡 Safety Features

- **Priority System**: Fire detection has highest priority
- **Fail-safe**: Default safe states for all actuators
- **Visual Feedback**: LCD provides system status
- **Audible Alerts**: Buzzer for emergency situations

## 📊 Performance Specifications

- **MCU Frequency**: 16 MHz
- **ADC Resolution**: 10-bit
- **PWM Resolution**: 8-bit (0-255)
- **Update Rate**: 2 Hz (500ms intervals)
- **Temperature Range**: 0°C to 150°C (LM35)
- **Light Intensity**: 0% to 100% scale

## 👨‍💻 Developed By
**Mahmoud Abouzeid**  
Embedded Systems Engineer

## 📄 License
This project is developed for educational purposes as part of the Edges Embedded Systems Diploma.

---
**Note**: This project demonstrates embedded systems concepts including peripheral drivers, sensor interfacing, PWM control, and real-time system design using layered architecture approach.
