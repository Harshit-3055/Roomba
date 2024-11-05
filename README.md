# Project Title

Arduino-Based Automatic Vacuum Cleaner (ROOMBA)

## Introduction

This project involves designing and building an automatic vacuum cleaner, similar to a Roomba, using an Arduino microcontroller. The vacuum cleaner is designed to autonomously clean floors by detecting obstacles, navigating around them, and collecting dust and debris in a designated chamber. This document outlines the purpose of the project, the problem it aims to solve, and the components used in the construction.

## Objective

The main objective of this project is to create a cost-effective, efficient, and autonomous vacuum cleaner that can navigate a room, avoid obstacles, and clean the floor without human intervention.

## Problem Statement

Cleaning floors manually can be time-consuming and tedious. While commercial robotic vacuum cleaners are available, they can be expensive. This project aims to provide a low-cost alternative that leverages open-source technology and widely available components to create a functional automatic vacuum cleaner.

## Components and Their Uses

1. **ARDUINO UNO/NANO**:

   - **Purpose**: Acts as the brain of the vacuum cleaner, controlling all the sensors, motors, and other components based on the programmed logic.
   - **Use in Project**: It processes the input from sensors and sends appropriate signals to the motor driver to navigate the cleaner.

2. **L293D MOTOR DRIVER**:

   - **Purpose**: Controls the direction and speed of the DC motors.
   - **Use in Project**: Drives the gear DC motors that control the movement of the wheels.

3. **LITHIUM ION BATTERY**:

   - **Purpose**: Powers the entire system.
   - **Use in Project**: Provides the necessary power to the Arduino, motors, sensors, and other components.

4. **ULTRASONIC SENSOR**:

   - **Purpose**: Detects obstacles by measuring the distance to objects in front of the vacuum cleaner.
   - **Use in Project**: Helps the vacuum cleaner avoid collisions by changing direction when an obstacle is detected.

5. **INFRARED SENSOR**:

   - **Purpose**: Detects the edges or boundaries of the cleaning area.
   - **Use in Project**: Prevents the vacuum cleaner from falling off edges (e.g., stairs) by detecting changes in surface level.

6. **GEAR DC MOTOR**:

   - **Purpose**: Provides torque to drive the wheels of the vacuum cleaner.
   - **Use in Project**: Controls the movement of the vacuum cleaner, allowing it to navigate the cleaning area.

7. **BRUSHLESS DC MOTOR (90MM CPU Cooler Fan)**:

   - **Purpose**: Powers the vacuum fan, which creates suction to collect dust and debris.
   - **Use in Project**: Drives the fan blades to generate airflow through the vacuum chamber.

8. **CELL HOLDER**:

   - **Purpose**: Holds the lithium-ion batteries securely in place.
   - **Use in Project**: Ensures that the batteries are safely mounted and connected to the circuit.

9. **SWITCHES**:

   - **Purpose**: Allows the user to turn the vacuum cleaner on and off.
   - **Use in Project**: Provides a manual control for powering the device.

10. **TP4056 LITHIUM ION CHARGING MODULE**:

    - **Purpose**: Safely charges the lithium-ion batteries.
    - **Use in Project**: Ensures that the batteries are charged correctly without the risk of overcharging.

11. **RUBBER WHEELS**:

    - **Purpose**: Provides traction on various floor surfaces.
    - **Use in Project**: Enables the vacuum cleaner to move smoothly across the cleaning area.

12. **DUMMY FREE WHEEL**:

    - **Purpose**: Supports the vacuum cleaner's balance without being driven by a motor.
    - **Use in Project**: Acts as a stabilizer, allowing the cleaner to pivot and turn easily.

13. **CASING**:

    - **Purpose**: Protects the internal components and gives the vacuum cleaner a finished appearance.
    - **Use in Project**: Houses all the electronic and mechanical components securely.

14. **FAN BLADES**:

    - **Purpose**: Creates suction by moving air through the vacuum chamber.
    - **Use in Project**: Facilitates dust and debris collection by generating airflow into the dust collection bag.

15. **PLASTIC CONTAINER (VACUUM CHAMBER)**:

    - **Purpose**: Holds the collected dust and debris.
    - **Use in Project**: Acts as the main chamber where dirt and dust are collected during operation.

16. **SILK BAG FOR DUST COLLECTION**:
    - **Purpose**: Collects and stores dust and debris sucked up by the vacuum cleaner.
    - **Use in Project**: Serves as the filter and dust bag, trapping dirt inside the vacuum chamber.

## How It Works

1. **Mapping, Obstacle Detection and Navigation**: The ultrasonic sensor constantly checks for obstacles in the path of the vacuum cleaner. When an obstacle is detected, the Arduino processes this information and sends signals to the motor driver to change direction. It is able to map the room and find the most efficient path for it to navigate.

2. **Edge Detection**: Infrared sensors monitor the floor for any sudden drops (like stairs). If an edge is detected, the vacuum cleaner will stop or turn to avoid falling.

3. **Dust Collection**: The brushless DC motor drives the fan, creating suction to draw in dust and debris through the fan blades and into the plastic container. The silk bag filters and collects the dust, keeping the vacuum chamber clean.

4. **Power Management**: The lithium-ion battery provides power to the entire system, while the TP4056 module ensures the battery is charged safely.

## Conclusion

This Arduino-based automatic vacuum cleaner project provides an affordable and efficient solution to floor cleaning. By integrating sensors, motors, and a microcontroller, the vacuum cleaner can autonomously navigate and clean a designated area, reducing the need for manual cleaning and contributing to a more convenient and automated lifestyle.
