# Arduino Memory Game (Simon Says)

> **Note:** This is a beginner project I built when I was first starting out with Arduino! 

**[Click here to see and hear how the game works!](https://youtu.be/TMMk2V2ssN8?si=Wj2AJVkQ-SYWA-nD)**

This project is a classic "Simon Says" memory game. The objective is to remember and repeat an increasingly complex sequence of lights and sounds.

## Features
* **100 Levels:** Challenge yourself with up to 100 consecutive rounds.
* **Audio-Visual Feedback:** Every button has a paired LED and a unique musical tone.
* **Melodies & Monitoring:** Includes win/loss sound effects and tracks your game status via the Serial Monitor (9600 baud).

## Hardware Needed
* 1x Arduino Board (Uno, Nano, etc.)
* 4x Push Buttons & 4x LEDs (with 220Ω resistors)
* 1x Piezo Buzzer

## Pin Configuration

| Component | Pin | Notes |
| :--- | :--- | :--- |
| Buttons 1-4 | D8, D7, D4, D2 | Connect to GND (`INPUT_PULLUP`) |
| LEDs 1-4 | A0, A1, A2, A3 | Standard digital `OUTPUT` |
| Buzzer | D9 | Requires a PWM pin |
| Status LED | D11 | Optional; stays `HIGH` during active game |
| RNG Seed | A5 | Leave unconnected for random generation |

## How to Play
1. **Watch & Listen:** The Arduino plays a sequence of lights and tones.
2. **Repeat:** Press the buttons in the exact same order. 
3. **Advance:** Getting it right adds a new step to the sequence for the next round.
4. **Game Over:** Pressing the wrong button triggers flashing LEDs and a loss melody. Press the physical `RESET` button on your Arduino to play again!
