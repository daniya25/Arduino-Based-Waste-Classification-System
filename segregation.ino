#include <Servo.h>  // Include Servo motor library 

  

Servo servo1;  // Create servo object to control the motor 

  

const int trigPin = 8;   // Ultrasonic sensor trigger pin 

const int echoPin = 9;   // Ultrasonic sensor echo pin 

  

long duration;           // To store duration of pulse from ultrasonic sensor 

int distance = 0;        // To store calculated distance 

int potPin = A0;         // Soil moisture sensor connected to analog pin A0 

int soil = 0;            // Raw soil sensor value 

int fsoil;               // Averaged and mapped soil moisture 

  

int maxDryValue = 10;    // Threshold to decide if waste is wet or dry 

int Ultra_Distance = 15; // Maximum detection distance (in cm) to consider waste 

  

void setup() { 

  Serial.begin(9600);          // Begin serial communication 

  pinMode(trigPin, OUTPUT);    // Set trigPin as output 

  pinMode(echoPin, INPUT);     // Set echoPin as input 

  servo1.attach(7);            // Attach the servo motor to pin 7 

  

  servo1.write(112);           // Move servo to neutral position on startup 

  Serial.println("Soil Sensor Ultrasonic Servo"); 

} 

  

void loop() { 

  int soil = 0;  // Reset soil reading 

  

  // Measure distance using ultrasonic sensor 

  for (int i = 0; i < 2; i++) { 

    digitalWrite(trigPin, LOW); 

    delayMicroseconds(7); 

    digitalWrite(trigPin, HIGH); 

    delayMicroseconds(10); 

    digitalWrite(trigPin, LOW); 

    delayMicroseconds(10); 

  

    duration = pulseIn(echoPin, HIGH);                    // Time taken for echo 

    distance = duration * 0.034 / 2 + distance;           // Convert to cm 

    delay(10); 

  } 

  

  distance = distance / 2;  // Average the 2 readings 

  

  // If object detected within required range 

  if (distance < Ultra_Distance && distance > 1) { 

    delay(1000);  // Short delay before reading soil moisture 

  

    // Take 3 soil moisture readings and average them 

    for (int i = 0; i < 3; i++) { 

      soil = analogRead(potPin);                          // Read analog value 

      soil = constrain(soil, 485, 1023);                  // Limit extreme values 

      fsoil = (map(soil, 485, 1023, 100, 0)) + fsoil;     // Map to percentage 

      delay(75); 

    } 

  

    fsoil = fsoil / 3;  // Final average moisture 

  

    // Print moisture and distance info 

    Serial.print("Humidity: "); 

    Serial.print(fsoil); 

    Serial.print("%"); 

    Serial.print(" Distance: "); 

    Serial.print(distance); 

    Serial.print(" cm"); 

  

    // Decision based on moisture value 

    if (fsoil > maxDryValue) { 

      delay(1000); 

      Serial.println(" ==>WET Waste "); 

      servo1.write(62);     // Move servo left of neutral for wet waste 

      delay(3000); 

    } else { 

      delay(1000); 

      Serial.println(" ==>Dry Waste "); 

      servo1.write(162);    // Move servo right of neutral for dry waste 

      delay(3000); 

    } 

  

    servo1.write(112);      // Return to neutral position 

  } 

  

  // Reset values for next cycle 

  distance = 0; 

  fsoil = 0; 

  delay(1000);              // Delay before next detection 

} 
