// l298n 1 (back); has words on my car

// high for forward
const int inB1 = 2;
const int inB4 = 5;

// high for backward
const int inB2 = 3;
const int inB3 = 4;

// l298n 2 (front)

// high for forward
const int inF2 = 8;
const int inF3 = 10;

// high for backward
const int inF1 = 7;
const int inF4 = 11;

// pwms
const int enA1 = 6;
const int enB1 = 9;
const int enA2 = 10;
const int enB2 = 11;


void setup() {
  pinMode(inB1, OUTPUT);
  pinMode(inB2, OUTPUT);
  pinMode(inB3, OUTPUT);
  pinMode(inB4, OUTPUT);

  pinMode(inF1, OUTPUT);
  pinMode(inF2, OUTPUT);
  pinMode(inF3, OUTPUT);
  pinMode(inF4, OUTPUT);

  stop_motors();
  
  Serial.begin(9600);
  
  delay(50);
}

void loop() {
  if (Serial.available() > 0) {
    String str = Serial.readStringUntil('\n');
    str.trim();

    if (str == "f") {
      forward();
    } else if (str == "b") {
       backward();
    } else if (str == "s") {
      stop_motors();
    }
  }
  delay(20);
}

void stop_motors() {
    digitalWrite(inB1, LOW);
    digitalWrite(inB2, LOW);
    digitalWrite(inB3, LOW);
    digitalWrite(inB4, LOW);

    digitalWrite(inF1, LOW);
    digitalWrite(inF2, LOW);
    digitalWrite(inF3, LOW);
    digitalWrite(inF4, LOW);
}

void forward() {
  digitalWrite(inB2, LOW);
  digitalWrite(inB3, LOW);
  digitalWrite(inF3, LOW);
  digitalWrite(inF1, LOW);

  digitalWrite(inB4, HIGH);
  digitalWrite(inB1, HIGH);
  digitalWrite(inF2, HIGH);
  digitalWrite(inF4, HIGH);

}

void backward() {
  digitalWrite(inB4, LOW);
  digitalWrite(inB1, LOW);
  digitalWrite(inF2, LOW);
  digitalWrite(inF4, LOW);

  digitalWrite(inB2, HIGH);
  digitalWrite(inB3, HIGH);
  digitalWrite(inF3, HIGH);
  digitalWrite(inF1, HIGH);

}
