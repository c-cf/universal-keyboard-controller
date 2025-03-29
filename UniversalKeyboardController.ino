#include <Keyboard.h>

// Define a structure for key mapping
struct KeyMapping {
  const char* name;
  uint8_t keycode;
};

// Key mapping table: supports many common keyboard functions
const KeyMapping keyMappings[] = {
  {"up",       KEY_UP_ARROW},
  {"down",     KEY_DOWN_ARROW},
  {"left",     KEY_LEFT_ARROW},
  {"right",    KEY_RIGHT_ARROW},
  {"f1",       KEY_F1},
  {"f2",       KEY_F2},
  {"f3",       KEY_F3},
  {"f4",       KEY_F4},
  {"f5",       KEY_F5},
  {"f6",       KEY_F6},
  {"f7",       KEY_F7},
  {"f8",       KEY_F8},
  {"f9",       KEY_F9},
  {"f10",      KEY_F10},
  {"f11",      KEY_F11},
  {"f12",      KEY_F12},
  {"alt",      KEY_LEFT_ALT},
  {"shift",    KEY_LEFT_SHIFT},
  {"ctrl",     KEY_LEFT_CTRL},
  {"control",  KEY_LEFT_CTRL},
  {"esc",      KEY_ESC},
  {"enter",    KEY_RETURN},
  {"insert",   KEY_INSERT},
  {"delete",   KEY_DELETE},
  {"home",     KEY_HOME},
  {"end",      KEY_END},
  {"pageup",   KEY_PAGE_UP},
  {"pagedown", KEY_PAGE_DOWN},
  {"tab",      KEY_TAB},
  {"backspace",KEY_BACKSPACE},
  {"space",    ' '},
  {"gui",      KEY_LEFT_GUI},
  {"win",      KEY_LEFT_GUI},
  {"menu",     KEY_MENU}
};

// Get the corresponding keycode for a given key string
uint8_t getKeyCode(const String &key) {
  for (uint8_t i = 0; i < sizeof(keyMappings) / sizeof(keyMappings[0]); i++) {
    if (key.equalsIgnoreCase(keyMappings[i].name)) {
      return keyMappings[i].keycode;
    }
  }
  return 0; // Return 0 if no corresponding special key is found
}

// Process the key action (press or release) based on the provided key string and action type
void processKey(const String &key, bool press) {
  // If the command is a single character, use that directly
  if (key.length() == 1) {
    char k = key.charAt(0);
    if (press)
      Keyboard.press(k);
    else
      Keyboard.release(k);
  } else {
    uint8_t keycode = getKeyCode(key);
    if (keycode != 0) {
      if (press)
        Keyboard.press(keycode);
      else
        Keyboard.release(keycode);
    } else {
      // Output an error message for debugging if the key is unknown
      Serial.print("Unknown key: ");
      Serial.println(key);
    }
  }
}

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  if (Serial.available() > 0) {
    // Read one line of command from Serial and trim whitespace
    String command = Serial.readStringUntil('\n');
    command.trim();
    if (command.length() == 0) return;  // Ignore empty commands

    // Determine the action based on the command prefix: 'd' for press, 'u' for release
    char action = command.charAt(0);
    String key = command.substring(1);
    key.trim();

    if (action == 'd') {        // Press key
      processKey(key, true);
    } else if (action == 'u') { // Release key
      processKey(key, false);
    } else {
      Serial.print("Invalid command: ");
      Serial.println(command);
    }
  }
}
