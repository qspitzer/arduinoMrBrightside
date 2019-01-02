float pi = 3.14;


#define treble
//#define base

//one chunk = ~1.60 seconds
//each full note = ~ 0.4 seconds
//each break between notes is 0.05 seconds

//constants
//const int baseBuzz = 2;
const int trebleBuzz = 4;

const struct treble {
  float F = 349.228;
  float FSharp = 369.994;
  float C = 523.251;
  float CSharp = 554.365;
  float DSharp = 622.254;
  float rest = 0;
} TREBLE;

const struct base {
  //float lowFSharp = 
  float lowGSharp = 103.826;
  float lowASharp = 116.541;
  float C = 130.813;
  float CSharp = 138.591;
  float FSharp = 184.997;
  float GSharp = 195.998;
  float ASharp = 233.082;
  float midCSharp = 277.183;
  float DSharp = 311.127;
  float F = 349.228;
  float rest = 0;
} BASE;

//functions
void playNote(float note, int buzzer, float noteLength){
  float len = 1.6 / noteLength;
  tone(buzzer, note);
  delay((len-0.05)*1000);
  noTone(buzzer);
  delay(50);
}

void play2Notes(float n1, float n2, int buzzer, float noteLength){
  float len = 1.6 / noteLength;
  int maxPoint = 0;
  int otherMax = 0;
  float timePassed = 0;
  float points[450];
  for(int i = 0; i<450; i++){
    float playTone = sin(2*pi*n1*timePassed) + sin(2*pi*n2*timePassed);
    timePassed+=0.002222222;
    points[i] = playTone;
    if(playTone > points[maxPoint]) {
      maxPoint = i;
    }
  }
  timePassed = 0;
  for(int i = 0; i<450; i++){
    float playTone = sin(2*pi*n1*timePassed) + sin(2*pi*n2*timePassed);
    timePassed+=0.002222222;
    points[i] = playTone;
    if(playTone > points[otherMax] && i != maxPoint) {
      otherMax = i;
    }
  }
  Serial.println(points[otherMax]);
  Serial.println(points[maxPoint]);
  Serial.println(otherMax);
  Serial.println(maxPoint);
}

void play3Notes(float n1, float n2, float n3, int buzzer, float noteLength){
  int timePassed = 0;
  float len = 1.6 / noteLength;
  float playLen = len - 0.05;
  float oneLen = playLen / 50;
  for(int i = 0; i != 50; i++){
    float playTone = sin(2*pi*n1*timePassed) + sin(2*pi*n2*timePassed) + sin(2*pi*n3*timePassed);
    tone(buzzer, playTone);
    delay(oneLen * 1000);
    timePassed+=12;
  }
  noTone(buzzer);
  delay(50);
}*/

void base1() {
  //c1
  playNote(BASE.CSharp, baseBuzz, 8);
  playNote(BASE.GSharp, baseBuzz, 8);
  playNote(BASE.midCSharp, baseBuzz, 8);
  playNote(BASE.GSharp, baseBuzz, 8);

  playNote(BASE.DSharp, baseBuzz, 8);
  playNote(BASE.GSharp, baseBuzz, 8);
  playNote(BASE.midCSharp, baseBuzz, 8);
  playNote(BASE.GSharp, baseBuzz, 8);

  //c2
  playNote(BASE.C, baseBuzz, 8);
  playNote(BASE.GSharp, baseBuzz, 8);
  playNote(BASE.CSharp, baseBuzz, 8);
  playNote(BASE.GSharp, baseBuzz, 8);

  playNote(BASE.DSharp, baseBuzz, 8);
  playNote(BASE.GSharp, baseBuzz, 8);
  playNote(BASE.midCSharp, baseBuzz, 8);
  playNote(BASE.GSharp, baseBuzz, 8);
}

void base2() {
  //c1
  playNote(BASE.lowGSharp, baseBuzz, 8);
  playNote(BASE.CSharp, baseBuzz, 8);
  playNote(BASE.FSharp, baseBuzz, 8);
  playNote(BASE.CSharp, baseBuzz, 8);

  playNote(BASE.DSharp, baseBuzz, 8);
  playNote(BASE.FSharp, baseBuzz, 8);
  playNote(BASE.midCSharp, baseBuzz, 8);
  playNote(BASE.FSharp, baseBuzz, 8);

  //c2
  playNote(BASE.lowGSharp, baseBuzz, 8);
  playNote(BASE.CSharp, baseBuzz, 8);
  playNote(BASE.FSharp, baseBuzz, 8);
  playNote(BASE.CSharp, baseBuzz, 8);

  playNote(BASE.DSharp, baseBuzz, 8);
  playNote(BASE.FSharp, baseBuzz, 8);
  playNote(BASE.midCSharp, baseBuzz, 8);
  playNote(BASE.FSharp, baseBuzz, 8);
}

void playBase(){
  base1();
  base2();
  
  base1();
  base2();
  
  base1();
  base2();
  
  base1();
  base2();
  
  base1();
  base2();

  play2Notes(BASE.ASharp, BASE.lowASharp, baseBuzz, (5/4));

  //playNote(BASE.F
}
void playTreble(){
  //c1
  playNote(TREBLE.rest, trebleBuzz, 8);
  playNote(TREBLE.F, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.F, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.DSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.F, trebleBuzz, 8);

  //c2
  playNote(TREBLE.rest, trebleBuzz, 8);
  playNote(TREBLE.F, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.F, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.DSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.F, trebleBuzz, 8);

  //c3
  playNote(TREBLE.rest, trebleBuzz, 8);
  playNote(TREBLE.FSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.FSharp, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.DSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.FSharp, trebleBuzz, 8);

  //c4
  playNote(TREBLE.rest, trebleBuzz, 8);
  playNote(TREBLE.FSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.FSharp, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.DSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.FSharp, trebleBuzz, 8);

  //c5
  playNote(TREBLE.rest, trebleBuzz, 4);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  
  playNote(TREBLE.CSharp, trebleBuzz, 4);

  //c6
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.DSharp, trebleBuzz, 4);

  //c7
  playNote(TREBLE.CSharp, trebleBuzz, 4);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  
  playNote(TREBLE.CSharp, trebleBuzz, 4);

  //c8
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);

  playNote(TREBLE.C, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 4);

  //c9
  playNote(TREBLE.rest, trebleBuzz, 4);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  
  playNote(TREBLE.CSharp, trebleBuzz, 4);

  //c10
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.DSharp, trebleBuzz, 4);

  //c11
  playNote(TREBLE.CSharp, trebleBuzz, 4);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  
  playNote(TREBLE.CSharp, trebleBuzz, 4);

  //c12
  playNote(TREBLE.rest, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);

  playNote(TREBLE.DSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.C, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 4);

  //c13
  playNote(TREBLE.rest, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 4);

  //c14
  playNote(TREBLE.rest, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  
  playNote(TREBLE.CSharp, trebleBuzz, 4);

  //c15
  playNote(TREBLE.rest, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  
  playNote(TREBLE.CSharp, trebleBuzz, 4);

  //c16
  playNote(TREBLE.rest, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);

  playNote(TREBLE.DSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.C, trebleBuzz, 8);
  
  playNote(TREBLE.CSharp, trebleBuzz, 4);

  //c17
  playNote(TREBLE.rest, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  
  playNote(TREBLE.CSharp, trebleBuzz, 4);

  ///c18
  playNote(TREBLE.rest, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  
  playNote(TREBLE.CSharp, trebleBuzz, 4);

  //c19
  playNote(TREBLE.rest, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);

  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  
  playNote(TREBLE.CSharp, trebleBuzz, 4);

  //c20
  playNote(TREBLE.CSharp, trebleBuzz, 4);
  
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);
  playNote(TREBLE.CSharp, trebleBuzz, 8);

  playNote(TREBLE.C, trebleBuzz, 4);

  //c21
  //play2Notes(TREBLE.CSharp, TREBLE.FSharp, trebleBuzz, 2);
  play2Notes(TREBLE.CSharp, TREBLE.FSharp, trebleBuzz, 2);
  play2Notes(BASE.ASharp, BASE.lowASharp, trebleBuzz, 2);
}

void setup() {
  pinMode(baseBuzz, OUTPUT);
  pinMode(trebleBuzz, OUTPUT);
  
  Serial.begin(2000000);
  while(! Serial);

  #ifdef treble
  playTreble();
  #endif
  #ifdef base
  playBase();
  #endif
}

void loop() {
  // put your main code here, to run repeatedly:
}
