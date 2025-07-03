# Arduino Morse Code Encoder/Decoder

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Arduino-blue.svg?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-success.svg?style=for-the-badge)

## 📋 Description

An intelligent Arduino-based Morse code decoder that can interpret Morse code signals from multiple input sources. The system features dual sensor support (LDR for light-based signals and piezo for sound/vibration), real-time decoding, and LCD display output. Perfect for educational purposes, amateur radio enthusiasts, or anyone interested in learning Morse code.

## ✨ Features

- **Dual Input Support**: Light Detection Resistor (LDR) and Piezo sensor
- **Real-time Decoding**: Instant Morse code to text conversion
- **LCD Display**: 16x2 I2C LCD for output visualization
- **Simulation Mode**: Built-in demonstration with "PES" example
- **Adjustable Sensitivity**: Potentiometer-controlled sensor selection
- **Serial Monitor Output**: Debug and monitoring capabilities
- **Complete Alphabet Support**: A-Z character recognition

## 🔧 Hardware Requirements

### Components
- Arduino Uno/Nano/Pro Mini
- 16x2 LCD with I2C backpack
- Light Dependent Resistor (LDR)
- Piezo sensor/buzzer
- 10kΩ Potentiometer
- Resistors (10kΩ for LDR pull-down)
- Jumper wires
- Breadboard

### Pin Configuration
| Component | Arduino Pin | Description |
|-----------|-------------|-------------|
| LDR | A0 | Light sensor input |
| Piezo | A1 | Sound/vibration sensor |
| Potentiometer | A2 | Mode selection |
| LCD SDA | A4 | I2C data line |
| LCD SCL | A5 | I2C clock line |

## 🔌 Circuit Diagram

![Screenshot 2025-07-03 173858](https://github.com/user-attachments/assets/a0e040a7-a9ef-4d21-9b23-af23b8d6466e)


## 📚 Libraries Required

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```

Install via Arduino Library Manager:
- **LiquidCrystal I2C** by Frank de Brabander

## 🚀 Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/Kathitjoshi/arduino-morse-encoder-decoder.git
   cd arduino-morse-encoder-decoder
   ```

2. **Install required libraries**
   - Open Arduino IDE
   - Go to Sketch → Include Library → Manage Libraries
   - Search for "LiquidCrystal I2C" and install

3. **Upload the code**
   - Connect your Arduino to your computer
   - Open the `.ino` file in Arduino IDE
   - Select your board and port
   - Click Upload

## 🎮 Usage

### Simulation Mode
The device starts in simulation mode and automatically decodes "PES" to demonstrate functionality.

### Sensor Mode
1. **LDR Mode**: Turn potentiometer fully left
   - Flash a light (flashlight, laser) in dot/dash patterns
   - Short flash = dot (·)
   - Long flash = dash (−)

2. **Piezo Mode**: Turn potentiometer fully right
   - Tap or create vibrations in dot/dash patterns
   - Short tap = dot (·)
   - Long tap = dash (−)

### Timing Guidelines
- **Dot Duration**: ~200ms
- **Dash Duration**: ~600ms
- **Character Pause**: ~800ms
- **Word Pause**: ~1400ms

## 📖 Morse Code Reference

| Letter | Code | Letter | Code | Letter | Code | Letter | Code |
|--------|------|--------|------|--------|------|--------|------|
| A | ·− | B | −··· | C | −·−· | D | −·· |
| E | · | F | ··−· | G | −−· | H | ···· |
| I | ·· | J | ·−−− | K | −·− | L | ·−·· |
| M | −− | N | −· | O | −−− | P | ·−−· |
| Q | −−·− | R | ·−· | S | ··· | T | − |
| U | ··− | V | ···− | W | ·−− | X | −··− |
| Y | −·−− | Z | −−·· | | | | |

## ⚙️ Configuration

### Adjustable Parameters
```cpp
const int threshold = 500;        // Sensor sensitivity
const int dotDuration = 200;      // Dot timing (ms)
const int dashDuration = 600;     // Dash timing (ms)
const int charPause = 800;        // Character separation (ms)
const int wordPause = 1400;       // Word separation (ms)
```

### LCD I2C Address
If your LCD doesn't work, try changing the I2C address:
```cpp
LiquidCrystal_I2C lcd(0x3F, 16, 2);  // Try 0x3F instead of 0x27
```

## 🔍 Troubleshooting

| Problem | Solution |
|---------|----------|
| LCD not displaying | Check I2C address (0x27 or 0x3F) |
| Sensor not responsive | Adjust threshold value |
| Incorrect decoding | Check timing parameters |
| No output | Verify wiring connections |

## 📈 Future Enhancements

- [ ] Support for numbers and punctuation
- [ ] Adjustable speed settings
- [ ] Audio feedback
- [ ] Memory storage for messages
- [ ] Wireless transmission capability
- [ ] Mobile app integration

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Author

 Made By Kathit Joshi, Kavyansh Jain, and Mahashwetha Panigrahi with 💗

## 🙏 Acknowledgments

- Arduino community for excellent documentation
- Morse code enthusiasts and amateur radio operators
- Open source contributors

## 📞 Support

If you encounter any issues or have questions:
- Open an issue on GitHub
- Check the troubleshooting section
- Contact via email: your.email@example.com

---

⭐ **Star this repo if you found it helpful!**
