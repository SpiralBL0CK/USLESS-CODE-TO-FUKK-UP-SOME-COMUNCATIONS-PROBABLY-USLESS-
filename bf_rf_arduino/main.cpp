/* Side Notes

//https://forum.arduino.cc/index.php?topic=88422.0

The OCR1A variable is related to the frequency.
The OCR1A variable is one less than the actual divisor.
OCR1A - Frequency
15 - 500 khz
14 - ~530 khz
13 - ~570 khz
12 - ~610 khz
11 - ~670 khz
10 - ~730 khz
9 - 800 khz
8 - ~890 khz
7 - 1000 khz
6 - ~1140 khz
5 - ~1330 khz
4 - 1600 khz
3 - 2000 khz
2 - ~2670 khz
1 - 4000 khz
0 - 8000 khz *would not recommend this setting





*/
//formula to fuck up the tellecommunications  (16÷(OCR1A+1)÷2)×1000 = frequency in khz

const byte ANTENNA = 9;

unsigned long A = calcDelayTimeForFreq(440);
unsigned long B = calcDelayTimeForFreq(494);
unsigned long C = calcDelayTimeForFreq(523);
unsigned long D = calcDelayTimeForFreq(587);
unsigned long E = calcDelayTimeForFreq(659);
unsigned long F = calcDelayTimeForFreq(699);
unsigned long G = calcDelayTimeForFreq(784);
unsigned long _A2 = calcDelayTimeForFreq(880);
unsigned long rest = 1;

unsigned long q = 652;
unsigned long e = q/2;
unsigned long s = e/2;
unsigned long t = s/2;
unsigned long h = q*2;
unsigned long f = q*4;

void setup() {
  // set up Timer 1
  TCCR1A = _BV (COM1A0);  // toggle OC1A on Compare Match
  TCCR1B = _BV(WGM12) | _BV(CS10);   // CTC, no prescaler
  OCR1A =  9;       // compare A register value to 10 (zero relative)
}  // end of setup

void tone(unsigned long dTime, unsigned long playTime) {
  unsigned long end = millis() + playTime;
 
  while (end > millis()) {
    pinMode (ANTENNA, OUTPUT);
    delayMicroseconds(dTime);
    pinMode (ANTENNA, INPUT);
    delayMicroseconds(dTime);   
  }
}

void note(unsigned long dTime, unsigned long playTime) {
  tone(dTime,playTime-50);
  tone(rest,50);
}

unsigned long calcDelayTimeForFreq(unsigned long freq) {
  return 500000/freq;
}


void twinkleTwinkle() {
  note(C,q);
  note(C,q);
  note(G,q);
  note(G,q);
  note(_A2,q);
  note(_A2,q);
  note(G,h);
 
  note(F,q);
  note(F,q);
  note(E,q);
  note(E,q);
  note(D,q);
  note(D,q);
  note(C,h);
 
  note(G,q);
  note(G,q);
  note(F,q);
  note(F,q);
  note(E,q);
  note(E,q);
  note(D,h);
 
  note(G,q);
  note(G,q);
  note(F,q);
  note(F,q);
  note(E,q);
  note(E,q);
  note(D,h);
 
  note(C,q);
  note(C,q);
  note(G,q);
  note(G,q);
  note(_A2,q);
  note(_A2,q);
  note(G,h);

  note(F,q);
  note(F,q);
  note(E,q);
  note(E,q);
  note(D,q);
  note(D,q);
  note(C,h);
}

void locateTone() {
  note(A,t);
  note(B,t);
  note(C,t);
  note(D,t);
  note(E,f);
  note(D,t);
  note(C,t);
  note(B,t);
}

void loop() {
  twinkleTwinkle();
}
