# Counter-Strike 2 aimbot example

This project is a aimbot written in C/C++ for Counter-Strike 2. It utilizes memory reading and manipulation techniques to automatically aim at enemy players within a certain radius of the player's crosshair.

## preview
https://github.com/WzrterFX/cs2-aimbot/assets/122642787/d131d9a7-a08d-49ac-bfb4-d70f4c8d0ae5

## Features

- **Smooth Aim**: Smoothly adjusts the player's view angles to aim at enemy players.
- **Auto Targeting**: Automatically targets the nearest enemy player within a customizable radius.
- **Crosshair Distance**: Calculates the distance between the player's crosshair and enemy players to prioritize targets.

## Usage

To use this aimbot, follow these steps:

1. Compile the source code using a std 17 or more C++ compiler.
3. Update offsets if needed using cs2 dumper.
3. Compiled in x64 executable and run while Counter-Strike 2 is running.
4. Enjoy the automatic aiming assistance provided by the aimbot.

## Configuration

The aimbot can be configured by adjusting the following parameters in the source code:

- **Smoothness**: Adjusts the smoothness of the aimbot's aiming movement.
- **Radius**: Sets the maximum distance from which the aimbot will target enemy players.
- **Spotted**: Enables or disables targeting only spotted enemy players.
