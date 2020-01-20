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

/* Consts */
const int SCROLL_DELAY = 100;
const int FLASH_DELAY = 500;
const LedControl lc = LedControl(11, 9, 10, 1);
const String MSG_END_TOKEN = "@MESSAGE END@";

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 0);
  lc.clearDisplay(0);
}

void loop() {
  scrolling_display_msg("@happy@ @sad@");
  /*static_display_msg("HI THERE FRIEND");*/
}

/* Displays message scrolling across the matrix. */
void scrolling_display_msg(String msg) {
  msg = msg + MSG_END_TOKEN;

  /* Read in and display the tokens. */
  String symbol_ids[2] = {" ", " "};
  int i = 0;
  while (true) {
    symbol_ids[0] = symbol_ids[1];
    symbol_ids[1] = String(msg[i]);

    /* Handles multi-character tokens. */
    if (symbol_ids[1] == "@") {
      do {
        i++;
        symbol_ids[1] += String(msg[i]);
      } while (String(msg[i]) != "@");
    }

    /* Display the characters or end the message.*/
    if (symbol_ids[1] == MSG_END_TOKEN) {
      symbol_ids[1] = " ";
      scrolling_display_bincodes(symbol_ids);
      break;
    } else {
      scrolling_display_bincodes(symbol_ids);
      i++;
    }
  }
}

/* Displays message by flashing one char at a time on the matrix. */
void static_display_msg(String msg) {
  const String MSG_END_TOKEN = "@MESSAGE END@";
  msg += MSG_END_TOKEN;

  /* Read in and display the tokens. */
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
      static_display_bincode(" ");
      delay(FLASH_DELAY);
      break;
    } else {
      static_display_bincode(symbol_id);
      delay(FLASH_DELAY);
      i++;
    }
  }
}

/* Displays two symbols scrolling across the matrix. */
void scrolling_display_bincodes(String tokens[2]) {
  /* Get the bincodes for each individual char. */
  byte bincodes[2][8];
  for (int i = 0; i < SYMBOL_COUNT; i++) {
    if (symbols[i].token == tokens[0]) {
      for (int x = 0; x < 8; x++) {
        bincodes[0][x] = symbols[i].bincode[x];
      }
    }
    if (symbols[i].token == tokens[1]) {
      for (int x = 0; x < 8; x++) {
        bincodes[1][x] = symbols[i].bincode[x];
      }
    }
  }

  /* Compute the bincodes for every phase between the characters and display them. */
  byte compound_bincode[8];
  for (int shift = 0; shift < 8; shift++) {
    for (int i = 0; i < 8; i++) {
      compound_bincode[i] = bincodes[0][i] << shift | (bincodes[1][i] << shift) >> 8;
    }
    display_bincode(compound_bincode);
    delay(SCROLL_DELAY);
  }
}

/* Displays one symbol statically on the matrix. */
void static_display_bincode(String token) {
  for (int i = 0; i < SYMBOL_COUNT; i++) {
    if (symbols[i].token == token) {
      display_bincode(symbols[i].bincode);
    }
  }
}

/* Displays an array of bytes on the matrix as rows. */
void display_bincode(byte bincode[]) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, bincode[row]);
  }
}
