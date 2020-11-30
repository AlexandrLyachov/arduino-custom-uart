void(* resetFunc) (void) = 0; // reset arduino func

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
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
int label[8];
int allnum;
int num[9];
String symv;

void loop()
{
digitalWrite(13,0);
  for(int g = 0; g<=7;g++)
  {
   delay(100);
   int i = digitalRead(12);
   label[g] = i;
   //ok();
  // Serial.println(label[g]);
  }
  num[0] = label[7] * pow(2,7);
  num[1] = label[6] * pow(2,6);
  num[2] = label[5] * pow(2,5);
  num[3] = label[4] * pow(2,4);
  num[4] = label[3] * pow(2,3);
  num[5] = label[2] * pow(2,2);
  num[6] = label[1] * pow(2,1);
  num[7] = label[0] * pow(2,0);
  allnum = num[0] + num[1] +num[2] +num[3] +num[4] +num[5] +num[6] +num[7];
  //Serial.println(allnum);
  abc();
  Serial.println("-");
}

int A = 65, B = 66, C = 67, D = 68, E = 69, F = 70, G = 71, H = 72, I = 73, J = 74, K = 75, L = 76, M = 77, N = 78, O = 79, P = 80, Q = 81, R = 82, S = 83, T = 84, U = 85, V = 86, W = 87, X = 88, Y = 89, Z = 90;
int AllOK;
int nums;
void abc()
{
  nums = allnum;
  if (nums == A){symv += "A";}
  else if (nums == 0){symv = " ";}
  else if (nums == B){symv += "B";}
  else if (nums == C){symv += "C";}
  else if (nums == D){symv += "D";}
  else if (nums == E){symv += "E";}
  else if (nums == F){symv += "F";}
  else if (nums == G){symv += "G";}
  else if (nums == H){symv += "H";}
  else if (nums == I){symv += "I";}
  else if (nums == J){symv += "J";}
  else if (nums == K){symv += "K";}
  else if (nums == L){symv += "L";}
  else if (nums == M){symv += "M";}
  else if (nums == N){symv += "N";}
  else if (nums == O){symv += "O";}
  else if (nums == P){symv += "P";}
  else if (nums == Q){symv += "Q";}
  else if (nums == R){symv += "R";}
  else if (nums == S){symv += "S";}
  else if (nums == T){symv += "T";}
  else if (nums == U){symv += "U";}
  else if (nums == V){symv += "V";}
  else if (nums == W){symv += "W";}
  else if (nums == X){symv += "X";}
  else if (nums == Y){symv += "Y";}
  else if (nums == Z){symv += "Z";}
  nums = 0;
  Serial.println(symv);
}

ISR(TIMER1_COMPA_vect)
{
  Serial.println(allnum);
}