int buttons[] = {A0, A1, A2, A3,};
int rButton = A5;
int rLED = 3;
int gLED = 2;
int x1 = 0;
int x2 = 0;
int x3 = 0;
int x4 = 0;
int y1, y2, y3, y4;
int code[] = {x1, x2, x3, x4};
int input[] = {y1, y2, y3, y4};
int count =0;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }

  pinMode(rButton, INPUT_PULLUP);
  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
}

void loop() {
  
  if (checkCode(code) == true) {
    for(int i = 0; i < 10; i++) {
      digitalWrite(gLED, HIGH);
      delay(50);
      digitalWrite(gLED, LOW);
      delay(50);
    }
    count = 0;
    if (digitalRead(rButton) == LOW) {
      while(count < 4) {
        digitalWrite(rLED, LOW);
        if (digitalRead(buttons[0]) == LOW) {
          digitalWrite(rLED, HIGH);
          if (count == 0) {
            x1 = 0;
          }
          else if (count == 1) {
            x2 = 0;
          }
          else if (count == 2) {
            x3 = 0;
          }
          else if (count == 3) {
            x4 = 0;
          }
          count++;
          while (digitalRead(buttons[0]) == LOW) {
            delay(1);
          }
        }
        else if (digitalRead(buttons[1]) == LOW) {
          digitalWrite(rLED, HIGH);
          if (count == 0) {
            x1 = 1;
          }
          else if (count == 1) {
            x2 = 1;
          }
          else if (count == 2) {
            x3 = 1;
          }
          else if (count == 3) {
            x4 = 1;
          }
          count++;
          while (digitalRead(buttons[1]) == LOW) {
            delay(1);
          }
        }
        else if (digitalRead(buttons[2]) == LOW) {
          digitalWrite(rLED, HIGH);
          if (count == 0) {
            x1 = 2;
          }
          else if (count == 1) {
            x2 = 2;
          }
          else if (count == 2) {
            x3 = 2;
          }
          else if (count == 3) {
            x4 = 2;
          }
          count++;
          while (digitalRead(buttons[2]) == LOW) {
            delay(1);
          }
        }
        else if (digitalRead(buttons[3]) == LOW) {
          digitalWrite(rLED, HIGH);
          if (count == 0) {
            x1 = 3;
          }
          else if (count == 1) {
            x2 = 3;
          }
          else if (count == 2) {
            x3 = 3;
          }
          else if (count == 3) {
            x4 = 3;
          }
          count++;
          while (digitalRead(buttons[3]) == LOW) {
            delay(1);
          }
        }
      }
      digitalWrite(rLED, LOW);
      delay(100);
      digitalWrite(gLED, HIGH);
      delay(100);
      digitalWrite(gLED, LOW);
      delay(100);
      digitalWrite(rLED, HIGH);
      delay(100);
      digitalWrite(rLED, LOW);
  
      while (digitalRead(rButton) == LOW) {
         delay(1);
      }
    }
    code[0] = x1;
    code[1] = x2;
    code[2] = x3;
    code[3] = x4;
  }
  else if (checkCode(code) == false) {
    for(int i = 0; i < 10; i++) {
      digitalWrite(rLED, HIGH);
      delay(50);
      digitalWrite(rLED, LOW);
      delay(50);
    }
  }
}

boolean checkCode(int code[]) {
  int count = 0;
  
  while (count != 4) {
    digitalWrite(gLED, LOW);
    if (digitalRead(buttons[0]) == LOW) {
      digitalWrite(gLED, HIGH);
      if (count == 0) {
          y1 = 0;
        }
        else if (count == 1) {
          y2 = 0;
        }
        else if (count == 2) {
          y3 = 0;
        }
        else if (count == 3) {
          y4 = 0;
        }
        count++;
        while (digitalRead(buttons[0]) == LOW) {
          delay(1);
        }   
    }
    else if (digitalRead(buttons[1]) == LOW) {
      digitalWrite(gLED, HIGH);
      if (count == 0) {
          y1 = 1;
        }
        else if (count == 1) {
          y2 = 1;
        }
        else if (count == 2) {
          y3 = 1;
        }
        else if (count == 3) {
          y4 = 1;
        }
        count++;
        while (digitalRead(buttons[1]) == LOW) {
          delay(1);
        }   
    }
    else if (digitalRead(buttons[2]) == LOW) {
      digitalWrite(gLED, HIGH);
      if (count == 0) {
          y1 = 2;
        }
        else if (count == 1) {
          y2 = 2;
        }
        else if (count == 2) {
          y3 = 2;
        }
        else if (count == 3) {
          y4 = 2;
        }
        count++;
        while (digitalRead(buttons[2]) == LOW) {
          delay(1);
        }   
    }
    else if (digitalRead(buttons[3]) == LOW) {
      digitalWrite(gLED, HIGH);
      if (count == 0) {
          y1 = 3;
        }
        else if (count == 1) {
          y2 = 3;
        }
        else if (count == 2) {
          y3 = 3;
        }
        else if (count == 3) {
          y4 = 3;
        }
        count++;
        while (digitalRead(buttons[3]) == LOW) {
          delay(1);
        }   
    }
  }
  digitalWrite(gLED, LOW);

  input[0] = y1;
  input[1] = y2;
  input[2] = y3;
  input[3] = y4;
  
  int cnt2 = 0;
  for (int i = 0; i < 4; i++) {
    if (input[i] == code[i]) {
      cnt2 = cnt2;
    }
    else {
      cnt2++;
    }
  }
  if (cnt2 == 0) {
    return true;
  }
  else {
    return false;
  }
}

