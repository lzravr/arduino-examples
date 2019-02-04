const int leftForward = 2;
const int leftBackward = 3;
const int rightForward = 4;
const int rightBackward = 5;

void setup() 
{
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);

}

void loop()
{
  //digitalWrite(leftForward , 255);
  digitalWrite(leftBackward , 255);
  digitalWrite(rightForward , HIGH);
  digitalWrite(rightBackward , LOW);
 
}
