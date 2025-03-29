# UniversalKeyboardController
This Arduino sketch converts serial commands into keyboard actions using the Keyboard library. It listens for commands starting with 'd' (key down) or 'u' (key up) followed by a key identifier (a single character or a special key name).

## Board Compatibility
Note: This sketch requires an Arduino board with native USB support (e.g., Leonardo, Micro, or Due). The Arduino Uno is not supported because it lacks native USB capabilities. Uno uses a separate chip for USB-to-serial conversion, which does not allow direct emulation of a USB keyboard.

## How to Flash the Sketch
1. Install the Arduino IDE

    Download and install the latest version of the Arduino IDE.

2. Connect Your Board

    Connect your compatible Arduino board (Leonardo, Micro, Due, etc.) to your computer via USB.

3. Select the Board and Port

    Open the Arduino IDE.

    Go to Tools > Board and select your board model.

    Go to Tools > Port and select the COM port corresponding to your board.

4. Open the Sketch

   Open the UniversalKeyboardController.ino file in the Arduino IDE.

5. Upload the Sketch

    Click the Upload button. The IDE will compile and flash the sketch to your board.

## Using the Sketch
### Serial Commands:

Press a Key: Send a command starting with `d` followed by the key identifier.

Release a Key: Send a command starting with `u` followed by the key identifier.

### Example Commands:

- `dA` – Press the 'A' key.

- `uA` – Release the 'A' key.

- `dup` – Press the Up Arrow key.

- `udown` – Release the Down Arrow key.

### Serial Monitor:

Open the Serial Monitor (set to 9600 baud) to send commands and view any error messages.

## Troubleshooting
- Board Not Supported:

  Make sure you're using a board with native USB support.

- Upload Issues:

  Check that the correct board and port are selected in the IDE.

- Command Errors:

  If you send an unrecognized key command, an error message will appear on the Serial Monitor.

