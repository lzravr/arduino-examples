char c;
int in1 = 5;

void setup() {
  pinMode(in1, OUTPUT);
  Serial.begin(9600);
  digitalWrite(in1, HIGH);
}

void loop() {
  if(Serial.available())
  {
    c = Serial.read();

    switch(c)
    {
      case 'h': {
        Serial.print("h ");
        digitalWrite(in1, LOW);
        break;
      }
      case 'l': {
        Serial.print("l ");
        digitalWrite(in1, HIGH);
        break;
      }
    }
    
  }

}
