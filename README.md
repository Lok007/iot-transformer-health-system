# IoT-Based Transformer Health Monitoring System

This repository presents a prototype embedded monitoring system
designed to observe the operating condition of electrical
distribution transformers using sensor-based measurements.

The project emphasizes embedded system design and protective
control logic for power infrastructure applications.

## Objective
The objective of this work is to study how real-time sensing
and threshold-based control can be used to enhance the
operational safety and reliability of distribution transformers.

## Functional Overview
The system performs the following functions:

- Continuous temperature monitoring of transformer components
- Measurement of load current under operating conditions
- Evaluation of sensor data against predefined safety limits
- Activation of protective isolation using relay control

The design is oriented toward smart grid and intelligent
power monitoring research.

## Embedded Platform
- ESP32 microcontroller for control and processing
- Temperature sensing using a digital temperature sensor
- Load current measurement using a Hall-effect sensor
- Relay-based actuation for protection logic

## Hardware Configuration
- ESP32 development board
- Temperature sensor module
- Current sensing module
- Relay module for load control
- Voltage sensing and display modules (planned extensions)

## Software Environment
- Embedded C/C++ firmware
- Arduino-based development workflow
- Sensor interface libraries
- Modular firmware structure for future expansion

## Repository Structure
iot-transformer-health-system/
├── docs/ # System diagrams and documentation
├── firmware/ # Embedded monitoring firmware
└── README.md

## Development Status
✔ Core sensing and protection logic implemented  
✔ Real-time monitoring validated  
🔄 Voltage measurement, visualization, and cloud integration planned

## Academic Context
This repository demonstrates concepts related to:
- Embedded monitoring systems
- Smart grid technologies
- Protective control in power electronics

