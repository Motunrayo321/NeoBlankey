# 🌍 NeoBlankey – AI-Enhanced Neonatal Care System

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![Status](https://img.shields.io/badge/status-prototype-green.svg)]()
[![Made with ❤️ in Africa](https://img.shields.io/badge/Made%20with%20❤️-Africa-red.svg)]()


## Overview

NeoBlankey is a smart, low-cost, portable neonatal care device designed to combat hypothermia in preterm and low-birth-weight infants, especially in underserved communities.
It combines thermal regulation, AI-powered health monitoring, and solar energy to provide hospital-grade neonatal care in environments where incubators and stable electricity are unavailable.

This repository contains:

* Source code for control systems, AI algorithms, and sensor integration
* Media files (designs, schematics, demos)
* Documentation & research reports
* Development updates and roadmap

---

## Key Features

* Thermal Regulation – Peltier-based heating with PID control (±0.2°C accuracy)
* Swaddle Design – Comfortable, insulated blanket with integrated heating
* Energy Autonomy – Rechargeable batteries + solar charging for off-grid use
* AI Health Monitoring – Body temperature, SpO₂, movement, and CO₂ tracking with predictive analytics
* Connectivity – Wi-Fi/Bluetooth support, EMR integration, mobile dashboard (planned)
* Safety – Overheating protection, buzzer alerts, auto shutoff

---

## Problem It Solves

* Neonatal hypothermia is a leading cause of infant mortality in Africa.
* Incubators are expensive, immobile, and electricity-dependent.
* Existing alternatives (cloth, hot water bottles, wax warmers) are unsafe or lack monitoring.

NeoBlankey fills this gap with an affordable, intelligent, and portable solution.

---

## Repository Structure

```
NeoBlankey/
│
├── code/                 # Firmware & AI models (Arduino, MicroPython, TensorFlow Lite)
├── docs/                 # Reports, technical docs, validation protocols
├── media/                # Images, demo videos, schematics
├── hardware/             # PCB design files, CAD models
├── presentations/        # Pitch decks, talks, workshop slides
├── tests/                # Sensor validation & clinical testing scripts
└── README.md             # Project overview (this file)
```

---

## Getting Started

### Requirements

* Arduino Nano / ESP32
* Peltier module + relay system
* DHT11/NTC thermistor
* Pulse oximeter sensor (reflectance type)
* CO₂ sensor (NDIR)
* Lithium-ion batteries + MPPT solar charger

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/NeoBlankey.git
   cd NeoBlankey/code
   ```
2. Install dependencies (Arduino libraries, TensorFlow Lite for microcontrollers).
3. Flash firmware to your microcontroller.
4. Connect sensors and power system.

---

## Current Development Phase

* Functional prototype (thermal regulation + safety features)
* Integration of AI health monitoring & sensor network
* Pilot testing with healthcare partners
* Roadmap: Clinical trials → Manufacturing partnerships → Global deployment

---

## Impact & Sustainability

* Maternal Health: Reduces anxiety and saves newborn lives
* Child Nutrition: Improves survival for breastfeeding initiation and growth
* Gender Inclusion: Empowers mothers, midwives, and female caregivers
* Sustainability: Solar-powered, designed for off-grid environments

---

## Contributing

We welcome contributions in:

* Firmware optimization
* AI model training
* Hardware design improvements
* Clinical validation support
* Documentation & translations

To contribute:

1. Fork the repo
2. Create a new branch (`feature/your-feature`)
3. Commit your changes
4. Open a Pull Request

---

## License

This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details.

---

## Contact

* Team Lead: Motunrayo Sanyaolu
* Email: motunrayosanya@gmail.com
* LinkedIn: https://www.linkedin.com/in/motunrayo321

---
