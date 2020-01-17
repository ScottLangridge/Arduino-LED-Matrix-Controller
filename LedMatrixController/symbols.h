typedef struct {
  String strId;
  byte binCode[8];
} symbol;

/* Set this to the number of symbols in the array below. (Hint: Subtract ten from the line number of the last element)! */
const int SYMBOL_COUNT = 39;

/* All of the symbols that the matrix can display. */
symbol symbols[] = {
  {"A", {B00000000, B00111000, B01000100, B01000100, B01111100, B01000100, B01000100, B01000100}},
  {"B", {B00000000, B01111000, B01000100, B01000100, B01111000, B01000100, B01000100, B01111000}},
  {"C", {B00000000, B00111000, B01000100, B01000000, B01000000, B01000000, B01000100, B00111000}},
  {"D", {B00000000, B01111000, B01000100, B01000100, B01000100, B01000100, B01000100, B01111000}},
  {"E", {B00000000, B01111100, B01000000, B01000000, B01111000, B01000000, B01000000, B01111100}},
  {"F", {B00000000, B01111100, B01000000, B01000000, B01111000, B01000000, B01000000, B01000000}},
  {"G", {B00000000, B00111000, B01000100, B01000000, B01000000, B01001100, B01000100, B00111000}},
  {"H", {B00000000, B01000100, B01000100, B01000100, B01111100, B01000100, B01000100, B01000100}},
  {"I", {B00000000, B00111000, B00010000, B00010000, B00010000, B00010000, B00010000, B00111000}},
  {"J", {B00000000, B00011100, B00001000, B00001000, B00001000, B00001000, B01001000, B00110000}},
  {"K", {B00000000, B01000100, B01001000, B01010000, B01100000, B01010000, B01001000, B01000100}},
  {"L", {B00000000, B01000000, B01000000, B01000000, B01000000, B01000000, B01000000, B01111100}},
  {"M", {B00000000, B01000100, B01101100, B01010100, B01010100, B01000100, B01000100, B01000100}},
  {"N", {B00000000, B01000100, B01000100, B01100100, B01010100, B01001100, B01000100, B01000100}},
  {"O", {B00000000, B00111000, B01000100, B01000100, B01000100, B01000100, B01000100, B00111000}},
  {"P", {B00000000, B01111000, B01000100, B01000100, B01111000, B01000000, B01000000, B01000000}},
  {"Q", {B00000000, B00111000, B01000100, B01000100, B01000100, B01010100, B01001000, B00110100}},
  {"R", {B00000000, B01111000, B01000100, B01000100, B01111000, B01010000, B01001000, B01000100}},
  {"S", {B00000000, B00111100, B01000000, B01000000, B00111000, B00000100, B00000100, B01111000}},
  {"T", {B00000000, B01111100, B00010000, B00010000, B00010000, B00010000, B00010000, B00010000}},
  {"U", {B00000000, B01000100, B01000100, B01000100, B01000100, B01000100, B01000100, B00111000}},
  {"V", {B00000000, B01000100, B01000100, B01000100, B01000100, B00101000, B00101000, B00010000}},
  {"W", {B00000000, B01000100, B01000100, B01000100, B01010100, B01010100, B01010100, B00101000}},
  {"X", {B00000000, B01000100, B01000100, B00101000, B00010000, B00101000, B01000100, B01000100}},
  {"Y", {B00000000, B01000100, B01000100, B00101000, B00010000, B00010000, B00010000, B00010000}},
  {"Z", {B00000000, B01111100, B00000100, B00001000, B00010000, B00100000, B01000000, B01111100}},
  {"1", {B00000000, B00010000, B00110000, B00010000, B00010000, B00010000, B00010000, B00111000}},
  {"2", {B00000000, B00111000, B01000100, B00000100, B00001000, B00010000, B00100000, B01111100}},
  {"3", {B00000000, B01111100, B00001000, B00010000, B00001000, B00000100, B01000100, B00111000}},
  {"4", {B00000000, B00001000, B00011000, B00101000, B01001000, B01111100, B00001000, B00001000}},
  {"5", {B00000000, B01111100, B01000000, B01111000, B00000100, B00000100, B01000100, B00111000}},
  {"6", {B00000000, B00011000, B00100000, B01000000, B01111000, B01000100, B01000100, B00111000}},
  {"7", {B00000000, B01111100, B00000100, B00001000, B00010000, B00100000, B00100000, B00100000}},
  {"8", {B00000000, B00111000, B01000100, B01000100, B00111000, B01000100, B01000100, B00111000}},
  {"9", {B00000000, B00111000, B01000100, B01000100, B00111100, B00000100, B00001000, B00110000}},
  {"0", {B00000000, B00111000, B01000100, B01001100, B01010100, B01100100, B01000100, B00111000}},
  {" ", {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000}},
  {"-", {B00000000, B00000000, B00000000, B00000000, B00111100, B00000000, B00000000, B00000000}},
  {"!", {B01000000, B00010000, B00010000, B00010000, B00010000, B00010000, B00000000, B00010000}}
};
