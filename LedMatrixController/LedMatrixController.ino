#include "LedControl.h"
#include "symbols.h"

/*
 * +---------------------+
 * |     PIN MAPPINGS    |
 * +---------------------+
 * | +5V -> VCC          |
 * | GND -> Ground (GND) |
 * | ~11 -> DataIn (DIN) |
 * | ~10 -> Load   (CS)  |
 * | ~ 9 -> Clock  (CLK) |
 * +---------------------+
*/
const LedControl lc = LedControl(11, 9, 10, 1);

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  display_msg("HELLO WORLD!");
}

/* Displays a message.
 * 
 * msg: The message to be displayed as a string of valid tokens.
 */
void display_msg(String msg) {
  /* Add token to the end of the message so you know where to break while loop. */
  const String MSG_END_TOKEN = "@MESSAGE END@";
  msg += MSG_END_TOKEN;

  String symbol_id;
  int i = 0;
  while (true) {
    symbol_id = String(msg[i]);

    /* Handles parsing of multi-character tokens. */
    if (symbol_id == "@") {
      do {
        i++;
        symbol_id += String(msg[i]);
      } while (String(msg[i]) != "@");
    }

    /* Display the character or end the message.*/
    if (symbol_id == MSG_END_TOKEN) {
      display_symbol(" ");
      delay(1000);
      break;
    } else {
      display_symbol(symbol_id);
      delay(1000);
      i++;
    }
  }
}

/* Updates the display to show a given symbol.
 *  
 *  token: The token of the symbol to display.
 */
void display_symbol(String token) {
  /* For each symbol in "symbols.h". */
  for (int i = 0; i < SYMBOL_COUNT; i++) {
    /* If it's the one you're looking for: */
    if (symbols[i].strId == token) {
      /* Write it's contents to the LED matrix. */
      for (int row = 0; row < 8; row++) {
        lc.setRow(0, row, symbols[i].binCode[row]);
      }
    }
  }


  /* Print to LED Matrix */

}
