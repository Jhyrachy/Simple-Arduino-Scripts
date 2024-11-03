# Personal Arduino Projects
A collection of small personal projects for Arduino using minimal hardware.

---

## RGB LED Controlled by Gyroscope
This project reads values from a gyroscope, converting them to a scale from 1 to 255 to adjust the colors of an RGB LED.

---

## Morse Code Machine
A program to create a small Morse code device using a buzzer and a switch. It simulates the sound and appearance of an old Morse code machine.

---

## Voltmeter
Simple code that turns an Arduino into a basic voltmeter.

---

## Music and Sound
This project enables the Arduino to play music on a buzzer. By manually transcribing sheet music, it automatically converts each note to its corresponding sound frequency and lights up the LED associated with that note.

### Notes and Pins

| Note | Pin |
|------|-----|
| Do   | 11  |
| Re   | 10  |
| Mi   | 9   |
| Fa   | 7   |
| Sol  | 6   |
| La   | 5   |
| Si   | 4   |

- **Buzzer:** Pin 8
- **Status LED:** Pin 13 (lights briefly each time a note is played)

The status LED provides visual feedback, especially helpful when a note repeats often or is played in different octaves. If the note is sharp or flat, the LED blinks so quickly it’s almost imperceptible.

As it stands, the code plays the "Imperial March" from *Star Wars*.
