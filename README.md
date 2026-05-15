# 🦾 Robot Arm Calculator

> A C++ command-line tool for structural analysis and motor-gearbox selection of a single-link robot arm — built for the Spring 2026 semester.

**Team 34 — All Mechanical**

| Name | ID |
|---|---|
| Basel Ibrahim Ahmed Ahmed | 2400338 |
| Ali Mohamed Ahmed Hassan | 2400469 |
| Mohamed Abdallah Abdelkader | 2400866 |
| Pierre Ossama Magdi Siha | 2400389 |
| Abdelmaqsoud Maher Abdelmaqsoud | 2400519 |

---

## 📌 Overview

This program assists in the **mechanical design and component selection** of a single-link robot arm. Given user-defined geometry, material, payload, and motion requirements, it:

1. Calculates bending stress on the arm link
2. Iteratively optimizes cross-section dimensions to reach the material's yield strength
3. Computes the required output torque
4. Selects the best motor + gearbox combination from a built-in database

---

## ✨ Features

- **9 built-in materials** (Cast Iron, Aluminum, Steel, Tungsten, and more) with the option to add a custom material at runtime
- **2 cross-section shapes** — rectangular and circular
- **30 real motors** from the Maxon EC-max / RE / IDX / ECX / EC-4pole families
- **34 real gearboxes** from the Maxon GPX / GP families
- **Structural optimization** — automatically scales cross-section until bending stress reaches 95–100% of yield strength
- **Two optimization priorities** for motor-gearbox selection:
  - Minimize total weight
  - Minimize a composite cost score (weight + size)
- **Input validation** throughout — rejects invalid types, negative values, and out-of-range choices
- **Restart loop** — run multiple cases without recompiling

---

## 🔧 How It Works

### Step 1 — Material Selection
Choose from the built-in list or enter a custom material with its density (g/cm³) and yield strength (MPa).

### Step 2 — Cross-Section & Geometry
Choose a **rectangular** (base × height × length) or **circular** (radius × length) cross-section. Mass and second moment of area are computed automatically.

### Step 3 — Loads & Motion
Enter:
- Payload mass (kg)
- Maximum angular acceleration (rad/s²)
- Required output speed (rad/s)

### Step 4 — Bending Stress & Optimization
The bending moment is computed as:

```
M = m_link · g · (L/2) + m_payload · g · L
  + m_link · (L/2)² · α + m_payload · L² · α
```

The cross-section is scaled up (×1.01/iteration) or down (×0.99/iteration) until:

```
0.95 · σ_yield ≤ σ_bending ≤ σ_yield
```

### Step 5 — Motor & Gearbox Selection
All motor-gearbox pairs are evaluated. A valid pair satisfies:

```
τ_out = τ_motor × gear_ratio × η  ≥  τ_required
ω_out = ω_motor / gear_ratio       ≥  ω_required
```

The pair with the lowest weight or cost score is selected and displayed.

---

## 🚀 Getting Started

### Prerequisites
- A C++ compiler supporting C++11 or later (GCC, Clang, MSVC)

### Compile

```bash
g++ -std=c++11 -o robot_arm main.cpp -lm
```

### Run

```bash
./robot_arm
```

On Windows:
```bash
robot_arm.exe
```

---

## 📋 Example Session

```
Select material:
1) Cast Iron
2) Copper nickel
...
> 4

Select cross section shape (1)rectangular or (2)circular:
> 2
radius= 15
length= 300

Enter payload mass in kg: 0.5
Enter maximum angular acceleration (rad/s^2): 5
Enter required speed (rad/s): 3

==================== optimizations ====================
stress before optimization= 183.4 MPa
stress after optimization= 240.6 MPa
mass of link after optimization: 0.312 Kg
optimized radius: 16.23 mm

Select optimization priority:
 1) Minimize Weight
 2) Minimize Cost
> 1

------- BEST COMBINATION -------
Motor:   EC-max 30 90W
Gearbox: GPX32 33:1
Minimum Weight: 0.430 kg
Output Torque:  2765.0 mNm
Output Speed:   3.14 rad/s
Required Torque: 2490.3 mNm
```

---

## 📐 Key Formulas

| Quantity | Formula |
|---|---|
| Rectangular area moment | `I = b·h³ / 12` |
| Circular area moment | `I = π·r⁴ / 4` |
| Bending stress (rect.) | `σ = M·(h/2) / I` |
| Bending stress (circ.) | `σ = M·r / I` |
| Gearbox output torque | `τ_out = τ_motor · i · η` |
| Gearbox output speed | `ω_out = ω_motor / i` |

> All internal calculations use **mm**, **tons**, and **MPa** for dimensional consistency (`g = 9810 mm/s²`).

---

## 🗂️ Project Structure

```
robot-arm-calculator-project_spring2026/
└── main.cpp        # Full source — classes, arrays, functions, and main loop
```

---

## 🔮 Possible Future Improvements

- [ ] Load motor/gearbox data from external CSV files
- [ ] Add a safety factor input for the yield stress constraint
- [ ] Support multi-link arm configurations
- [ ] Export results to a text or CSV report file
- [ ] Add a simple GUI

---

## 📄 License

This project was submitted as an academic assignment. All code was written by Team 34.
