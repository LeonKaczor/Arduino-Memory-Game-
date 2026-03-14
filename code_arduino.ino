const int guzik1 = 8;
const int guzik2 = 7;
const int guzik3 = 4;
const int guzik4 = 2;

const int buzzer = 9;

const int ilosc_rund = 100;
int rundy[ilosc_rund];
int wybory[ilosc_rund];

int aktualna_runda = 0;

void setup() {
  pinMode(guzik1, INPUT_PULLUP);
  pinMode(guzik2, INPUT_PULLUP);
  pinMode(guzik3, INPUT_PULLUP);
  pinMode(guzik4, INPUT_PULLUP);

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  digitalWrite(11, HIGH); 
  Serial.begin(9600);
  randomSeed(analogRead(A5)); 

  Serial.println("--- NOWA GRA ---");

  tone(buzzer, 523);
  delay(150);
  noTone(buzzer);

  for (int i = 0; i < ilosc_rund; i++) {
    rundy[i] = random(1, 5);
  }
  delay(1000);
}

void loop() {
  if (aktualna_runda >= ilosc_rund) {
    Serial.println("WYGRALES CALA GRE!");
    tone(buzzer, 523); delay(150);
    tone(buzzer, 659); delay(150);
    tone(buzzer, 784); delay(300);
    noTone(buzzer);
    while (1);
  }

  Serial.print("Runda: ");
  Serial.println(aktualna_runda + 1);
  Serial.println("Patrz na diody...");
  delay(1000);

  // ODTWARZANIE SEKWENCJI
  for (int i = 0; i <= aktualna_runda; i++) {
    int czestotliwosc = 0;

    if (rundy[i] == 1) { 
      digitalWrite(A0, HIGH); 
      czestotliwosc = 262; 
    }
    else if (rundy[i] == 2) { 
      digitalWrite(A1, HIGH); 
      czestotliwosc = 330; 
    }
    else if (rundy[i] == 3) { 
      digitalWrite(A2, HIGH); 
      czestotliwosc = 392; 
    }
    else if (rundy[i] == 4) { 
      digitalWrite(A3, HIGH); 
      czestotliwosc = 494; 
    }
    
    tone(buzzer, czestotliwosc);
    delay(150); // Czas trwania dźwięku
    noTone(buzzer);
    delay(350); // Czas świecenia bez dźwięku (łącznie 500ms)

    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);

    delay(100); // Krótsza przerwa między mrugnięciami
  }

  Serial.println("Twoja kolej!");

  for (int i = 0; i <= aktualna_runda; i++) {

    int wcisniety = 0;

    while (wcisniety == 0) {
      if (digitalRead(guzik1) == LOW) { 
        wcisniety = 1; 
        digitalWrite(A0, HIGH); 
        tone(buzzer, 262);
      }
      else if (digitalRead(guzik2) == LOW) { 
        wcisniety = 2; 
        digitalWrite(A1, HIGH); 
        tone(buzzer, 330);
      }
      else if (digitalRead(guzik3) == LOW) { 
        wcisniety = 3; 
        digitalWrite(A2, HIGH); 
        tone(buzzer, 392);
      }
      else if (digitalRead(guzik4) == LOW) { 
        wcisniety = 4; 
        digitalWrite(A3, HIGH); 
        tone(buzzer, 494);
      }
    }

    wybory[i] = wcisniety;
    Serial.print("Wybrano: ");
    Serial.println(wcisniety);

    delay(50); 

    if (wcisniety == 1) while (digitalRead(guzik1) == LOW);
    if (wcisniety == 2) while (digitalRead(guzik2) == LOW);
    if (wcisniety == 3) while (digitalRead(guzik3) == LOW);
    if (wcisniety == 4) while (digitalRead(guzik4) == LOW);

    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    noTone(buzzer);

    delay(50); 

    if (wybory[i] != rundy[i]) {
      Serial.println("BLAD! Koniec gry.");
      Serial.print("Mialo byc: ");
      Serial.println(rundy[i]);

      digitalWrite(11, LOW);
      

      digitalWrite(A0, HIGH);
      digitalWrite(A1, HIGH);
      digitalWrite(A2, HIGH);
      digitalWrite(A3, HIGH);
      delay(1000);
  

      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      delay(200);

      digitalWrite(A0, HIGH);
      digitalWrite(A1, HIGH);
      digitalWrite(A2, HIGH);
      digitalWrite(A3, HIGH);
      delay(200);
      noTone(buzzer);

      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      delay(200);
      
      digitalWrite(A0, HIGH); delay(200);
      digitalWrite(A1, HIGH); delay(200);
      digitalWrite(A2, HIGH); delay(200);
      digitalWrite(A3, HIGH);

  tone(buzzer, 392);
  delay(350);
  noTone(buzzer);
  delay(20);

  tone(buzzer, 523);
  delay(900);
  noTone(buzzer);
  delay(20);

  tone(buzzer, 784);
  delay(900);
  noTone(buzzer);
  delay(20);
  tone(buzzer, 698);
  delay(250);
  tone(buzzer, 659); 
  delay(250);
  tone(buzzer, 587);
  delay(250);
  tone(buzzer, 1047);
  delay(900);
  noTone(buzzer);
  delay(20);
  tone(buzzer, 784);
  delay(900);
  noTone(buzzer);
  delay(20); 
  tone(buzzer, 698); 
  delay(250);
  tone(buzzer, 659); 
  delay(250);
  tone(buzzer, 587); 
  delay(250);
  tone(buzzer, 1047); 
  delay(900);
  noTone(buzzer);
  delay(20);
  tone(buzzer, 784); 
  delay(900);
  noTone(buzzer);
  delay(20);
  tone(buzzer, 698); 
  delay(250);
  tone(buzzer, 659); 
  delay(250);
  tone(buzzer, 698); 
  delay(250);
  tone(buzzer, 587); 
  delay(1500); 
  
  noTone(buzzer);
      while (1); 
    }
  }

  Serial.println("OK! Nastepny poziom.");
  delay(500);
  aktualna_runda++;
  delay(1000);
}