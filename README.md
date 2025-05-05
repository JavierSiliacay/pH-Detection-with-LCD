# pH Detection Sensor with RGB LED

This project demonstrates a pH detection system using an Arduino, where the pH level of a solution is measured and displayed on an LCD. The system uses an RGB LED to indicate the pH level:
- **Red**: Acidic (pH < 6.8)
- **Green**: Neutral (pH 6.8 - 7.9)
- **Blue**: Basic (pH > 7.9)

## 🔧 Hardware Components
- Arduino (Uno, Nano, etc.)
- pH Sensor
- RGB LED (Red, Green, Blue)
- 16x2 LCD with I2C interface
- Jumper wires and breadboard

## 📋 Pin Configuration
| Component    | Arduino Pin |
|--------------|-------------|
| pH Sensor    | A0          |
| Red LED      | D2          |
| Green LED    | D3          |
| Blue LED     | D4          |
| LCD (I2C)    | SDA, SCL    |

## 🧠 How It Works
- The analog pH sensor reads the pH of the solution.
- The value is converted into a pH level and displayed on the LCD screen.
- The RGB LED indicates the pH range:
  - **Red**: pH < 6.8 (Acidic)
  - **Green**: 6.8 <= pH <= 7.9 (Neutral)
  - **Blue**: pH > 7.9 (Basic)
  
## 🛠️ Setup
1. Connect the pH sensor to analog pin `A0`.
2. Wire the RGB LED to pins `D2`, `D3`, and `D4`.
3. Connect the 16x2 LCD with I2C to the `SDA` and `SCL` pins.
4. Upload the Arduino sketch.
5. The system will continuously display the pH value and indicate the pH level with the RGB LED.

## 📝 License
This project is open-source and free to use under the MIT License.

---

Made with ❤️ by Javier Siliacay | USTP 🇵🇭
