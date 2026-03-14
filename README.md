# Arduino Memory Game (Simon Says)
Click here to see and hear how the game works!
https://youtu.be/TMMk2V2ssN8?si=Wj2AJVkQ-SYWA-nD


This project contains the Arduino code for a classic memory game, similar to "Simon Says." The game challenges the player to remember and repeat an increasingly complex sequence of lights and sounds.

## Features
* **100 Levels:** The game supports up to 100 consecutive rounds.
* **Audio-Visual Feedback:** Each button is paired with a specific LED and a unique musical tone.
* **Serial Monitoring:** Outputs the current round, player inputs, and game status to the Serial Monitor (9600 baud).
* **Game Over/Win Melodies:** Includes distinct audio sequences for making a mistake and for completing the game.

## Hardware Requirements
* 1x Arduino Board (Uno, Nano, etc.)
* 4x Push Buttons
* 4x LEDs 
* 4x Resistors for LEDs (e.g., 220Ω)
* 1x Piezo Buzzer

## Pin Configuration

| Component | Arduino Pin | Notes |
| :--- | :--- | :--- |
| Button 1 | D8 | Uses `INPUT_PULLUP` (connect to GND) |
| Button 2 | D7 | Uses `INPUT_PULLUP` (connect to GND) |
| Button 3 | D4 | Uses `INPUT_PULLUP` (connect to GND) |
| Button 4 | D2 | Uses `INPUT_PULLUP` (connect to GND) |
| LED 1 | A0 | Configured as digital `OUTPUT` |
| LED 2 | A1 | Configured as digital `OUTPUT` |
| LED 3 | A2 | Configured as digital `OUTPUT` |
| LED 4 | A3 | Configured as digital `OUTPUT` |
| Buzzer | D9 | Requires a PWM-capable pin |
| Status LED | D11 | Optional; stays `HIGH` during active game |
| RNG Seed | A5 | Leave unconnected for random seed generation |

## How to Play
1. **Start:** Power on or reset the Arduino. The Serial Monitor will display `--- NOWA GRA ---` (New Game).
2. **Watch and Listen:** The Arduino will play a sequence of lights and tones.
3. **Repeat:** Press the corresponding buttons in the exact same order.
4. **Advance:** If you are correct, the game will move to the next round and add one more step to the sequence.
5. **Game Over:** If you press the wrong button, the LEDs will flash, a "Game Over" melody will play, and the game will lock. Press the physical `RESET` button on the Arduino to play again.
