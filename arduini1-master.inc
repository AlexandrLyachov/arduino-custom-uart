void(* resetFunc) (void) = 0; // reset arduino func

void setup()
{
  pinMode(13, INPUT);
  pinMode(12, OUTPUT);
  Serial.begin(19200);
    cli(); // отключить глобальные прерывания
    TCCR1A = 0; // установить регистры в 0
    TCCR1B = 0; 

    OCR1A = 15624; // установка регистра совпадения
    TCCR1B |= (1 << WGM12); // включение в CTC режим

    // Установка битов CS10 и CS12 на коэффициент деления 1024
    TCCR1B |= (1 << CS10);
    TCCR1B |= (1 << CS12);

    TIMSK1 |= (1 << OCIE1A);  // включение прерываний по совпадению
    sei(); // включить глобальные прерывания
}
String label = " HELLOW"; // enter text only caps
int ors = 0;

void loop(){
textToChar();
}

int num = 1000000;
int iv;
int bukva;
void textToChar(){
  	char *to = (char *) label.c_str();
    while (*to++ != '\0') {
      iv = (int)* to;
      cz(iv);
    }
}
int bb[8];
int schet = 0;
int num1, num2;
int time;
uint32_t myTimer1;
void cz(int isd)
{
    if (millis() - myTimer1 >= 10000) {
    myTimer1 = millis();             
  }
  if (schet<= label.length()-1)
  {
    schet++;
    num1 = isd;
    num2 = isd;

  for(int i = 0; i<= 7; i++)
  {
    num1 = num1%2;
    num2 = num2/2;
    bb[i] = num1;
    num1 = num2;
  }
  for(int b = 0; b<=7; b++)
  {
  Serial.println(bb[b]);
   digitalWrite(12,bb[b]);
  delay(100);
  }
  Serial.println("-");
  }
}
ISR(TIMER1_COMPA_vect)
{
  schet = 0;
}
