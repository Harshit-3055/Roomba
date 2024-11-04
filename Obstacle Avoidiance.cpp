#include <NewPing.h>

#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define MAX_DISTANCE 200 // Maximum distance for ultrasonic sensor (in cm)

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

#define motor1Pin1 4 // Motor 1 direction pin 1
#define motor1Pin2 5 // Motor 1 direction pin 2
#define motor2Pin1 6 // Motor 2 direction pin 1
#define motor2Pin2 7 // Motor 2 direction pin 2

#define MOVE_DURATION 500    // Duration to move forward (adjust for your speed)
#define TURN_DURATION 700    // Duration to turn (adjust for your robot)
#define OBSTACLE_DISTANCE 20 // Distance threshold for obstacle detection (cm)

enum Direction
{
    FORWARD,
    TURN_LEFT,
    TURN_RIGHT
};
Direction currentDirection = FORWARD;

void setup()
{
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
}

void loop()
{
    unsigned int distance = sonar.ping_cm();

    if (currentDirection == FORWARD)
    {
        if (distance < OBSTACLE_DISTANCE)
        { // Obstacle detected
            stopMotors();
            delay(200); // Pause briefly
            turn();     // Turn to avoid obstacle
        }
        else
        {
            moveForward();
            delay(MOVE_DURATION); // Move for a specified duration
        }
    }
    else if (currentDirection == TURN_LEFT || currentDirection == TURN_RIGHT)
    {
        turn();
        currentDirection = FORWARD; // Switch back to moving forward
    }
}

void moveForward()
{
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
}

void stopMotors()
{
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
}

void turn()
{
    // Turn in the current direction
    if (currentDirection == FORWARD)
    {
        // Randomly choose to turn left or right
        currentDirection = (random(0, 2) == 0) ? TURN_LEFT : TURN_RIGHT;
    }

    if (currentDirection == TURN_LEFT)
    {
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH); // Turn left
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        delay(TURN_DURATION);
    }
    else if (currentDirection == TURN_RIGHT)
    {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); // Turn right
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        delay(TURN_DURATION);
    }

    stopMotors();
    delay(200); // Pause before moving forward
}
