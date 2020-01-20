#include "LedControl.h"
#include "symbols.h"

/*
   +---------------------+
   |     PIN MAPPINGS    |
   +---------------------+
   | +5V -> VCC          |
   | GND -> Ground (GND) |
   | ~11 -> DataIn (DIN) |
   | ~10 -> Load   (CS)  |
   | ~ 9 -> Clock  (CLK) |
   +---------------------+
*/
const LedControl lc = LedControl(11, 9, 10, 1);
const String MSG_END_TOKEN = "@MESSAGE END@";

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  scrolling_display_msg("HI THERE FRIEND");
  static_display_msg("HI THERE FRIEND");
}

void scrolling_display_msg(String msg) {
  msg = msg + MSG_END_TOKEN;

  String symbol_ids[2] = {" ", " "};
  int i = 0;
  while (true) {
    symbol_ids[0] = symbol_ids[1];
    symbol_ids[1] = String(msg[i]);

    /* Handles parsing of multi-character tokens. */
    if (symbol_ids[1] == "@") {
      do {
        i++;
        symbol_ids[1] += String(msg[i]);
      } while (String(msg[i]) != "@");
    }

    /* Display the character or end the message.*/
    if (symbol_ids[1] == MSG_END_TOKEN) {
      symbol_ids[1] = " ";
      scrolling_display_symbols(symbol_ids);
      break;
    } else {
      scrolling_display_symbols(symbol_ids);
      i++;
    }
  }

}

void static_display_msg(String msg) {
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
      static_display_symbol(" ");
      delay(1000);
      break;
    } else {
      static_display_symbol(symbol_id);
      delay(1000);
      i++;
    }
  }
}

void scrolling_display_symbols(String tokens[2]) {
  byte binCodes[2][8];
  for (int i = 0; i < SYMBOL_COUNT; i++) {
    if (symbols[i].token == tokens[0]) {
      for (int x = 0; x < 8; x++) {
        binCodes[0][x] = symbols[i].binCode[x];
      }
    }
    if (symbols[i].token == tokens[1]) {
      for (int x = 0; x < 8; x++) {
        binCodes[1][x] = symbols[i].binCode[x];
      }
    }
  }

  byte compound_bincode[8];
  for (int shift = 0; shift < 8; shift++) {
    for (int i = 0; i < 8; i++) {
      compound_bincode[i] = binCodes[0][i] << shift | (binCodes[1][i] << shift) >> 8;
    }
    display_symbol(compound_bincode, 0);
    delay(200);
  }
}

void static_display_symbol(String token) {
  for (int i = 0; i < SYMBOL_COUNT; i++) {
    if (symbols[i].token == token) {
      display_symbol(symbols[i].binCode, 0);
    }
  }
}

void display_symbol(byte binCode[], int shift) {
  if (shift >= 0) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(0, row, binCode[row] >> shift);
    }
  } else if (shift < 0) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(0, row, binCode[row] << abs(shift));
    }
  }
}
