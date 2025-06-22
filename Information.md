# 1)Arduino Board:  

Aurdino uno R3 

• Microcontroller: ATmega328P 
• Operating Voltage: 5V 
• Number of Digital I/O Pins: 14 
• Analog Input Pins: 6 
• USB Type B connector for programming 
• Power jack for external 9V supply 

 

# 2)Sensor 
a) Ultrasonic Sensor (HC-SR04) 
Purpose: To detect the presence of waste by measuring distance. 
Working Principle: Emits ultrasonic waves and measures the time they take to reflect  back. 

b) Soil Moisture Sensor (analog type) 
Purpose: To detect moisture content to differentiate between dry and wet waste. 
Working Principle: Higher moisture → lower resistance → higher analog value. 

c) Servo Motor (SG90) 
Purpose: To divert waste to Dry or Wet bins based on sensor reading. 



# 3)Connections: 

a)Ultrasonic Sensor (HC-SR04) 
VCC → 5V on Arduino(via Breadboard Positive Power Rail) 
GND → GND on Arduino(via Breadboard Negative Power Rail) 
Trig → Digital Pin 8 
Echo → Digital Pin 9 

b)Soil/Moisture Sensor (FC-28 via Module) 
Sensor VCC → 5V on Arduino (via Breadboard Positive Power Rail) 
Sensor GND → GND on Arduino (via Breadboard Negative Power Rail) 
Analog Output (AO) → Analog Pin A0 on Arduino  

c)Servo Motor 
Signal (Orange) → Digital Pin 7 
VCC (Red) → 5V (via breadboard) 
GND (Brown) → GND (via breadboard)  

d)Power & Breadboard Setup 
Arduino 5V → Breadboard Positive Power Rail (Red) 
Arduino GND → Breadboard Negative Power Rail (Blue) 


# 4)Output 

The system detects an object within 15 cm. 
It measures the humidity: 

    If >10%, it's classified as WET (servo turns left). 

    If ≤10%, it's classified as DRY (servo turns right). 

After a few seconds, the servo resets to the center (112°). 
The serial monitor displays distance, humidity and classification (WET/DRY). 
