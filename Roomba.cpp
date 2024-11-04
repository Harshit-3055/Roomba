#include <Ultrasonic.h>
#include <SoftwareSerial.h>

#define MOTOR_LEFT_FORWARD 9
#define MOTOR_LEFT_BACKWARD 10
#define MOTOR_RIGHT_FORWARD 11
#define MOTOR_RIGHT_BACKWARD 12

// Ultrasonic sensor pins
#define TRIG_PIN_FRONT 2
#define ECHO_PIN_FRONT 3
#define TRIG_PIN_LEFT 4
#define ECHO_PIN_LEFT 5
#define TRIG_PIN_RIGHT 6
#define ECHO_PIN_RIGHT 7

// Bluetooth HC-05 pins
#define HC05_TX 8
#define HC05_RX 13

// Create ultrasonic sensor objects
Ultrasonic ultrasonicFront(TRIG_PIN_FRONT, ECHO_PIN_FRONT);
Ultrasonic ultrasonicLeft(TRIG_PIN_LEFT, ECHO_PIN_LEFT);
Ultrasonic ultrasonicRight(TRIG_PIN_RIGHT, ECHO_PIN_RIGHT);

// Initialize Bluetooth
SoftwareSerial bluetooth(HC05_TX, HC05_RX);

// Constants
const int OBSTACLE_THRESHOLD = 20; // in cm
const int MOVE_SPEED = 255;        // PWM value

// Simple map representation (could be expanded for more details)
int roomMap[10][10]; // Example for a 10x10 grid

void setup()
{
    Serial.begin(9600);
    bluetooth.begin(9600);

    // Motor pins
    pinMode(MOTOR_LEFT_FORWARD, OUTPUT);
    pinMode(MOTOR_LEFT_BACKWARD, OUTPUT);
    pinMode(MOTOR_RIGHT_FORWARD, OUTPUT);
    pinMode(MOTOR_RIGHT_BACKWARD, OUTPUT);

    // Initialize room map to 0 (no obstacles)
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            roomMap[i][j] = 0; // 0 indicates free space
        }
    }
}

void loop()
{
    // Mapping and avoiding obstacles
    mapRoom();
    avoidObstacles();
}

// Function to map the room and update the room map
void mapRoom()
{
    // Example of updating map with distance data
    long distanceFront = ultrasonicFront.read();
    long distanceLeft = ultrasonicLeft.read();
    long distanceRight = ultrasonicRight.read();

    // For simplicity, let's assume current position is (0,0) and facing forward
    if (distanceFront < OBSTACLE_THRESHOLD)
    {
        roomMap[0][1] = 1; // Mark obstacle in front
    }
    if (distanceLeft < OBSTACLE_THRESHOLD)
    {
        roomMap[1][0] = 1; // Mark obstacle on the left
    }
    if (distanceRight < OBSTACLE_THRESHOLD)
    {
        roomMap[1][2] = 1; // Mark obstacle on the right
    }
}

// Function for obstacle avoidance
void avoidObstacles()
{
    long distanceFront = ultrasonicFront.read();

    if (distanceFront < OBSTACLE_THRESHOLD)
    {
        Serial.println("Obstacle detected! Turning...");
        turnRight();
    }
    else
    {
        moveForward();
    }
}

// Motor control functions
void moveForward()
{
    analogWrite(MOTOR_LEFT_FORWARD, MOVE_SPEED);
    analogWrite(MOTOR_RIGHT_FORWARD, MOVE_SPEED);
    digitalWrite(MOTOR_LEFT_BACKWARD, LOW);
    digitalWrite(MOTOR_RIGHT_BACKWARD, LOW);
}

void turnRight()
{
    analogWrite(MOTOR_LEFT_FORWARD, MOVE_SPEED);
    analogWrite(MOTOR_RIGHT_BACKWARD, MOVE_SPEED);
    delay(500); // Adjust delay for turn duration
    stopMotors();
}

void stopMotors()
{
    digitalWrite(MOTOR_LEFT_FORWARD, LOW);
    digitalWrite(MOTOR_LEFT_BACKWARD, LOW);
    digitalWrite(MOTOR_RIGHT_FORWARD, LOW);
    digitalWrite(MOTOR_RIGHT_BACKWARD, LOW);
}
