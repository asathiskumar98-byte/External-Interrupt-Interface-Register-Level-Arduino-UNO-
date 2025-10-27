# ⚙️ External Interrupt Interface — Register-Level (Arduino UNO)

This project demonstrates how to configure and handle **external interrupts (INT0 & INT1)** on the **ATmega328P** at the register level, without using Arduino functions.

---

## ⚙️ Hardware Used
- Arduino UNO (ATmega328P)
- 2 Push Buttons (for INT0 & INT1)
- LED (on pin 13, PB5)
- 10kΩ Pull-down or Pull-up Resistors (if needed)

---

## 🔌 Pin Configuration

| Component | Function | Arduino Pin | Port |
|------------|-----------|--------------|------|
| Push Button 1 | External Interrupt 0 | D2 | PD2 / INT0 |
| Push Button 2 | External Interrupt 1 | D3 | PD3 / INT1 |
| LED | Output | D13 | PB5 |
| VCC | Power | +5V | — |
| GND | Ground | GND | — |

---

## 🧩 Code Explanation

### Key Registers Used
| Register | Purpose |
|-----------|----------|
| **DDRB** | Configure PB5 as output |
| **SREG** | Global Interrupt Enable (bit 7) |
| **EIMSK** | Enable specific external interrupts (INT0, INT1) |
| **EICRA** | Set interrupt trigger edge (rising, falling, etc.) |

### Logic
- **INT0 (D2)** → When pressed, triggers ISR → LED **ON**  
- **INT1 (D3)** → When pressed, triggers ISR → LED **OFF**

---

## ⚙️ Working Principle
1. Button 1 (INT0) sends a **rising edge** → LED turns **ON**.  
2. Button 2 (INT1) sends a **rising edge** → LED turns **OFF**.  
3. The CPU sleeps in the main loop until an interrupt occurs.  

---

## 🧰 Build & Upload
1. Compile with **AVR-GCC / Atmel Studio / PlatformIO**.  
2. Upload the HEX to **Arduino UNO**.  
3. Observe LED toggling as external interrupts occur.
