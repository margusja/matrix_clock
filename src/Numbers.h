/*
 * n is unit index
 */
void make_one(int n) {
  lc.setRow(n,0,B00001000);
  lc.setRow(n,1,B00011000);
  lc.setRow(n,2,B00101000);
  lc.setRow(n,3,B00001000);
  lc.setRow(n,4,B00001000);
  lc.setRow(n,5,B00001000);
  lc.setRow(n,6,B00001000);
  lc.setRow(n,7,B00001000);
}

/*
 * n is unit index
 */
void make_two(int n) {
  lc.setRow(n,0,B00111110);
  lc.setRow(n,1,B00000010);
  lc.setRow(n,2,B00000010);
  lc.setRow(n,3,B00111110);
  lc.setRow(n,4,B00100000);
  lc.setRow(n,5,B00100000);
  lc.setRow(n,6,B00100000);
  lc.setRow(n,7,B00111110);
}

/*
 * n is unit index
 */
void make_three(int n) {
  lc.setRow(n,0,B00111110);
  lc.setRow(n,1,B00000010);
  lc.setRow(n,2,B00000010);
  lc.setRow(n,3,B00111110);
  lc.setRow(n,4,B00000010);
  lc.setRow(n,5,B00000010);
  lc.setRow(n,6,B00000010);
  lc.setRow(n,7,B00111110);
}

/*
 * n is unit index
 */
void make_four(int n) {
  lc.setRow(n,0,B00000100);
  lc.setRow(n,1,B00001100);
  lc.setRow(n,2,B00010100);
  lc.setRow(n,3,B00100100);
  lc.setRow(n,4,B01111110);
  lc.setRow(n,5,B00000100);
  lc.setRow(n,6,B00000100);
  lc.setRow(n,7,B00000100);
}

/*
 * n is unit index
 */
void make_five(int n) {
  lc.setRow(n,0,B00111110);
  lc.setRow(n,1,B00100000);
  lc.setRow(n,2,B00100000);
  lc.setRow(n,3,B00111110);
  lc.setRow(n,4,B00000010);
  lc.setRow(n,5,B00000010);
  lc.setRow(n,6,B00000010);
  lc.setRow(n,7,B00111110);
}

/*
 * n is unit index
 */
void make_six(int n) {
  lc.setRow(n,0,B00001000);
  lc.setRow(n,1,B00010000);
  lc.setRow(n,2,B00100000);
  lc.setRow(n,3,B00100000);
  lc.setRow(n,4,B00111110);
  lc.setRow(n,5,B00100010);
  lc.setRow(n,6,B00100010);
  lc.setRow(n,7,B00111110);
}

/*
 * n is unit index
 */
void make_seven(int n) {
  lc.setRow(n,0,B00111110);
  lc.setRow(n,1,B00100010);
  lc.setRow(n,2,B00000010);
  lc.setRow(n,3,B00000010);
  lc.setRow(n,4,B00000100);
  lc.setRow(n,5,B00001000);
  lc.setRow(n,6,B00001000);
  lc.setRow(n,7,B00001000);
}

/*
 * n is unit index
 */
void make_eight(int n) {
  lc.setRow(n,0,B00111110);
  lc.setRow(n,1,B00100010);
  lc.setRow(n,2,B00100010);
  lc.setRow(n,3,B00111110);
  lc.setRow(n,4,B00100010);
  lc.setRow(n,5,B00100010);
  lc.setRow(n,6,B00100010);
  lc.setRow(n,7,B00111110);
}

/*
 * n is unit index
 */
void make_nine(int n) {
  lc.setRow(n,0,B00111110);
  lc.setRow(n,1,B00100010);
  lc.setRow(n,2,B00100010);
  lc.setRow(n,3,B00111110);
  lc.setRow(n,4,B00000010);
  lc.setRow(n,5,B00000010);
  lc.setRow(n,6,B00000100);
  lc.setRow(n,7,B00001000);
}

/*
 * n is unit index
 */
void make_zero(int n) {
  lc.setRow(n,0,B00111110);
  lc.setRow(n,1,B00100010);
  lc.setRow(n,2,B00100010);
  lc.setRow(n,3,B00100010);
  lc.setRow(n,4,B00100010);
  lc.setRow(n,5,B00100010);
  lc.setRow(n,6,B00100010);
  lc.setRow(n,7,B00111110);
}

/*
 * n is unit index
 */
void make_template(int n) {
  lc.setRow(n,0,B00000000);
  lc.setRow(n,1,B00000000);
  lc.setRow(n,2,B00000000);
  lc.setRow(n,3,B00000000);
  lc.setRow(n,4,B00000000);
  lc.setRow(n,5,B00000000);
  lc.setRow(n,6,B00000000);
  lc.setRow(n,7,B00000000);
}

void toNumber(int i, int n) {
  if (n == 0) make_zero(i);
  if (n == 1) make_one(i);
  if (n == 2) make_two(i);
  if (n == 3) make_three(i);
  if (n == 4) make_four(i);
  if (n == 5) make_five(i);
  if (n == 6) make_six(i);
  if (n == 7) make_seven(i);
  if (n == 8) make_eight(i);
  if (n == 9) make_nine(i);
}