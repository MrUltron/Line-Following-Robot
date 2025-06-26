# 🤖 Line-Following Robot

A simple Arduino-based robot that autonomously follows a black line on a white surface using IR sensors and dual DC motors. Ideal for learning embedded control, sensor integration, and basic robotics.

---

## 🚀 Overview

The Line-Following Robot uses two infrared (IR) reflectance sensors to detect the contrast between a black line and a white background. Based on sensor readings, the Arduino adjusts the speed of two DC motors via an H-bridge driver, keeping the robot centered over the line.

---

## 🔧 Components Used

| Emoji | Component                        | Qty | Notes                                    |
|:-----:|----------------------------------|:---:|------------------------------------------|
| 🛠️    | Arduino Uno R3                   | 1   | ATmega328P, 5V                           |
| 👀    | IR Line Sensor Module (2-channel)| 1   | TCRT5000 or QRE1113                      |
| ⚙️    | L298N Motor Driver Module        | 1   | Dual H-bridge for DC motor control       |
| 🔌    | DC Geared Motors (3–6V)          | 2   | Mounted on chassis                       |
| 🏎️    | Robot Chassis & Wheels           | 1   | 2-wheel + caster                       |
| 🔋    | 6V – 9V Battery Pack              | 1   | Li-ion or NiMH                          |
| 🌉    | Jumper Wires & Breadboard        | Set | 22 AWG solid for chassis wiring         |

---

## 🔌 Wiring Diagram

 ┌────────────┐            ┌─────────────┐
 │  Arduino   │            │   L298N     │
 │  Uno R3    │            │  MotorDrv   │
 │            │            │             │
 │ 5V    ───▶ VCC           │
 │ GND   ───▶ GND           │
 │ D5    ───▶ IN1           │
 │ D6    ───▶ IN2           │
 │ D9    ───▶ IN3           │
 │ D10   ───▶ IN4           │
 │            │            │ ENA, ENB ⟵ PWM from D3, D11 │
 └────────────┘            └─────────────┘

 ┌────────────┐            ┌─────────────┐
 │  IR Sensor │            │   Motors    │
 │  Module    │            │             │
 │            │            │             │
 │ VCC  ───▶ 5V             │ M1+ / M1– from L298N ───▶ Left wheel
 │ GND  ───▶ GND            │ M2+ / M2– from L298N ───▶ Right wheel
 │ OUT1 ───▶ A0   (Left)    │
 │ OUT2 ───▶ A1   (Right)   │
 └────────────┘            └─────────────┘


> **Pin Summary**  
> • IR left → A0  
> • IR right → A1  
> • Motor driver IN1/IN2 → D5/D6  
> • Motor driver IN3/IN4 → D9/D10  
> • PWM enable pins → D3 (ENA), D11 (ENB)

---

## 💡 Working Principle

1. **Line Detection**  
   • IR sensors output HIGH on white (reflective) and LOW on black (absorbent).  
2. **Decision Logic**  
   • Both HIGH → move forward.  
   • Left LOW, Right HIGH → veer right.  
   • Left HIGH, Right LOW → veer left.  
   • Both LOW → stop or spin to find line.  
3. **Motor Control**  
   • Use `analogWrite()` on ENA/ENB to adjust speed.  
   • Set IN1/IN2 and IN3/IN4 HIGH/LOW to control direction.