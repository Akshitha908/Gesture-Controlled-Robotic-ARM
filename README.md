# Continuous Arm Gesture Controlled Robotic Arm using MEMS Sensor and Microcontroller

A gesture-controlled robotic arm that reads hand/arm movements with an **ADXL345 MEMS accelerometer** and drives the arm's DC motors through an **L298N motor driver**. Gestures are recognised with a simple threshold-based mapping, which keeps the system low-cost, fast and easy to build.

**B.Tech Major Project**, Electronics and Communication Engineering (2025-2026)
Sridevi Women's Engineering College, Hyderabad (JNTUH)

| Team member | Roll No. |
|---|---|
| Aluguvelli Akshitha | 22D21A0464 |
| Esogipeta Spoorthi | 22D21A0477 |
| Kodithala Vyshnavi | 22D21A0493 |

**Guide:** Dr. A. Narmada, Principal & Professor

## How it works

1. The ADXL345 measures acceleration on the X, Y and Z axes.
2. The microcontroller compares the readings with predefined thresholds.
3. The detected gesture is mapped to an arm action and sent to the L298N motor driver.

| Gesture (sensor reading) | Arm action |
|---|---|
| X below lower threshold | Move up |
| X above upper threshold | Move down |
| Y below lower threshold | Pick (gripper closes) |
| Y above upper threshold | Release (gripper opens) |
| Within thresholds | Stop / hold position |

## Hardware

- Microcontroller (Arduino-compatible; the report uses an ESP32)
- ADXL345 3-axis accelerometer (I2C)
- L298N motor driver
- DC motors for the arm and gripper
- Power supply and robotic arm chassis

### Motor driver pins used in the sketch

| Signal | Pin |
|---|---|
| Motor 1 IN1 (`m11`) | 7 |
| Motor 1 IN2 (`m12`) | 6 |
| Motor 2 IN1 (`m21`) | 5 |
| Motor 2 IN2 (`m22`) | 4 |

Motor logic: `00` = off, `01` = anti-clockwise, `10` = clockwise, `11` = off.

## Software setup

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. In **Library Manager**, install:
   - `Adafruit ADXL345`
   - `Adafruit Unified Sensor`
3. Open `src/project_b_1/project_b_1.ino`.
4. Select your board and port, then click **Upload**.

## Repository structure

```
.
├── README.md
├── .gitignore
├── src/
│   └── project_b_1/
│       └── project_b_1.ino    # Arduino sketch
└── docs/
    └── Project_Report.pdf     # Full project report
```

## Documentation

The full report (abstract, design, results and conclusion) is in [`docs/Project_Report.pdf`](docs/Project_Report.pdf).

## Applications

Industrial automation, assistive devices and remote control systems.
