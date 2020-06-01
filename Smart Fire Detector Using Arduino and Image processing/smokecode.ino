const int buzzerPin = 12;
const int flamePin = 11;
const int smokeA0 = 10;
int Flame = HIGH;
int SmokeA0 = HIGH;
int redled = 5;
int greenled = 6;
int sensorThres = 400;
void setup()   {
  pinMode(buzzerPin, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(flamePin, INPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600); }
void loop()   {
  Flame = digitalRead(flamePin);
  if (Flame== LOW)
 SmokeA0 = digitalRead(smokeA0);
if (SmokeA0== LOW)
{
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(redled, HIGH);
  digitalWrite(greenled, LOW);
Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode  delay(1000);  //   Delay of 1 second
Serial.println("AT+CMGS=\"+917399938999\"\r"); // Replace x with mobile number
Serial.println("FIRE IN THE HOUSE");// The SMS text you want to send
Serial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
  //delay(100); 
  }
  else  
  {
 digitalWrite(buzzerPin, LOW);
  digitalWrite(greenled, HIGH);
  digitalWrite(redled, LOW);
}   }
