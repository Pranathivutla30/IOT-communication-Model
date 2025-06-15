#  IoT Communication Model – Device Connectivity Project

This project demonstrates the implementation of an IoT communication model for connecting physical devices and enabling remote monitoring and control. It was developed as part of a CPS Lab experiment at Visvodaya Engineering College.

---

##  Project Overview

The Internet of Things (IoT) enables seamless communication between devices, services, and people across any network, at any time, and from any place. This model focuses on **bi-directional communication** between IoT devices and remote user interfaces. The system supports real-time sensor monitoring (temperature and humidity) and actuator control (bulb on/off).

---

##  Objective

**To build a working IoT communication model for connecting and controlling hardware devices remotely.**

---

##  Hardware Components

- Raspberry Pi (with SD card)
- DHT11 Sensor (Temperature & Humidity)
- Relay Module
- Bulb
- Jumper Wires
- Power Adapter

---

##  Software & Tools Used

- Raspberry Pi Imager
- PuTTY (SSH access)
- VNC Viewer (remote desktop)
- RaspController (Android mobile app)
- Custom C program for UART communication (`sp.c`)
- Raspberry Pi OS (32-bit)

---

## Communication Technologies Involved

- Wi-Fi (primary connectivity)
- VNC over TCP/IP
- UART (serial communication on embedded devices)
- SSH (remote terminal access)

---

##  Description

This IoT setup uses a Raspberry Pi configured with:
- Remote access via SSH and VNC
- Integration with a DHT11 sensor to read temperature and humidity values
- Relay control to switch a bulb ON/OFF remotely
- Mobile access via RaspController

The communication model maintains a persistent bi-directional connection between the client (user or device) and the Raspberry Pi server. The server remains active, logging all open sessions and responding to user commands.

---

##  Setup Procedure (Step-by-Step)

1. **SD Card Preparation**
   - Use Raspberry Pi Imager to install Raspberry Pi OS on a 16GB SD card.
   - Set hostname, enable SSH, configure Wi-Fi (SSID: `IOTLAB`, password: `IOTLAB@123`), and create user credentials.

2. **Boot & Access**
   - Insert SD card into Raspberry Pi.
   - Access via PuTTY using the IP address (e.g., `192.168.243.6`).
   - Run `sudo raspi-config` to enable VNC.

3. **Desktop Access**
   - Open VNC Viewer on your desktop.
   - Connect using the IP address and login credentials.

4. **Mobile Access**
   - Install RaspController on your smartphone.
   - Add the Raspberry Pi device and login.
   - Use the app to read DHT11 sensor data and control the bulb.

5. **Circuit Connection**
   - Connect DHT11 sensor to GPIO pins.
   - Connect relay module to control a bulb.
   - Use RaspController or the desktop dashboard to test functionality.

---

## ⚙ UART Communication (`sp.c`)

This embedded C program configures UART0 for serial communication between microcontroller modules.

### Functions Included:

- `initClocks()` – Configures system clocks and PLL
- `initUART0()` – Initializes UART0 at 9600 baud
- `U0Write()` – Sends a byte over UART
- `Send_String()` – Sends a complete string over UART

This is designed for microcontroller-to-microcontroller or sensor module communication.

---

##  Output

- Temperature and humidity readings shown in mobile/desktop dashboard.
- Bulb toggles on/off based on user input.
- Full control and monitoring using either a desktop or mobile interface.

---

##  Conclusion

This project successfully demonstrates an **IoT communication system** that allows remote bi-directional interaction with connected devices using real-time sensor feedback and actuator control.

---

##  Author

**Lakshmi Pranathi Vutla**  
Visvodaya Engineering College – Department of CSE  
🔗 [GitHub: Pranathivutla30](https://github.com/Pranathivutla30)

---

##  Repository Links

- [Project Report (`IOT COMMUNICATION.docx`)](https://github.com/Pranathivutla30/your-repo-name/blob/main/IOT%20COMMUNICATION.docx)
- [UART Code (`sp.c`)](https://github.com/Pranathivutla30/your-repo-name/blob/main/sp.c)


---

## ⭐ Support

If you find this project helpful, feel free to star ⭐ the repository and share your feedback!
