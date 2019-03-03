int row0= 0;
int row1= 1;
int col0= 2;
int col1= 3;
int col2= 4;
int col3= 5;
int wholeNotePin=6;
int halfNotePin=8;
int quarterNotePin=10;
int eigthNotePin=11;
int sixteenthNotePin=7;
int dotPin=9;
int restPin=12;
bool prototype=false;
void setup() {
  // put your setup code here, to run once:67543.37654.00000+
  if(prototype==false){
    pinMode(restPin,OUTPUT);
    pinMode(dotPin,OUTPUT);
    pinMode(sixteenthNotePin,OUTPUT);
    pinMode(eigthNotePin,OUTPUT);
    pinMode(quarterNotePin,OUTPUT);
    pinMode(halfNotePin,OUTPUT);
    pinMode(wholeNotePin,OUTPUT);
    digitalWrite(wholeNotePin,LOW);
    digitalWrite(halfNotePin,LOW);
    digitalWrite(quarterNotePin,LOW);
    digitalWrite(eigthNotePin,LOW);
    digitalWrite(sixteenthNotePin,LOW);
    digitalWrite(dotPin,LOW);
    digitalWrite(restPin,LOW);
  }
  pinMode(row0,OUTPUT);
  pinMode(row1,OUTPUT);
  pinMode(col0,INPUT_PULLUP);
  pinMode(col1,INPUT_PULLUP);
  pinMode(col2,INPUT_PULLUP);
  pinMode(col3,INPUT_PULLUP);
}
int wholeNote=0;
int halfNote=1;
int quarterNote=2;
int eighthNote=3;
int sixteenthNote=4;
int dot=5;
int tie=6;
int rest=7;
int nothingPressed=8;
int oldButton=8;
int lastPressed=0;
void loop() {
  int currentButton= checkButtons();
  if((currentButton !=oldButton)&&(currentButton!= 8)&&((lastPressed!=currentButton)||((lastPressed==6)||(lastPressed==7)))){
    if(currentButton==wholeNote){
      Keyboard.print("7");
      if(prototype==false){
        digitalWrite(wholeNotePin,HIGH);
        digitalWrite(halfNotePin,LOW);
        digitalWrite(quarterNotePin,LOW);
        digitalWrite(eigthNotePin,LOW);
        digitalWrite(sixteenthNotePin,LOW);
        digitalWrite(dotPin,LOW);
        digitalWrite(restPin,LOW);
      }
    }else if(currentButton==halfNote){
      Keyboard.print("6");
      if(prototype==false){
        digitalWrite(wholeNotePin,LOW);
        digitalWrite(halfNotePin,HIGH);
        digitalWrite(quarterNotePin,LOW);
        digitalWrite(eigthNotePin,LOW);
        digitalWrite(sixteenthNotePin,LOW);
        digitalWrite(dotPin,LOW);
        digitalWrite(restPin,LOW);
      }
    }else if(currentButton==quarterNote){
      Keyboard.print("5");
      if(prototype==false){
        digitalWrite(wholeNotePin,LOW);
        digitalWrite(halfNotePin,LOW);
        digitalWrite(quarterNotePin,HIGH);
        digitalWrite(eigthNotePin,LOW);
        digitalWrite(sixteenthNotePin,LOW);
        digitalWrite(dotPin,LOW);
        digitalWrite(restPin,LOW);
      }
    }else if(currentButton==eighthNote){
      Keyboard.print("4");
      if(prototype==false){
        digitalWrite(wholeNotePin,LOW);
        digitalWrite(halfNotePin,LOW);
        digitalWrite(quarterNotePin,LOW);
        digitalWrite(eigthNotePin,HIGH);
        digitalWrite(sixteenthNotePin,LOW);
        digitalWrite(dotPin,LOW);
        digitalWrite(restPin,LOW);
      }
    }else if(currentButton==sixteenthNote){
      Keyboard.print("3");
      if(prototype==false){
        digitalWrite(wholeNotePin,LOW);
        digitalWrite(halfNotePin,LOW);
        digitalWrite(quarterNotePin,LOW);
        digitalWrite(eigthNotePin,LOW);
        digitalWrite(sixteenthNotePin,HIGH);
        digitalWrite(dotPin,LOW);
        digitalWrite(restPin,LOW);
      }
    }else if(currentButton==dot){
      Keyboard.print(".");
      if(prototype==false){
        digitalWrite(dotPin,HIGH);
      }
    }else if(currentButton==tie){
      Keyboard.print("+");
      delay(300);
    }else if(currentButton==rest){
      Keyboard.print("0");
      if(prototype==false){
        digitalWrite(restPin,HIGH);
      }
      delay(300);
    }
    lastPressed=currentButton;
  }
  oldButton=currentButton;
}
int checkButtons(){
  int buttonPressed=8;
  digitalWrite(row0,LOW);
  digitalWrite(row1,HIGH);
  if(digitalRead(col0)==LOW){
    buttonPressed=0;
  }else if(digitalRead(col1)==LOW){
    buttonPressed=1;
  }else if(digitalRead(col2)==LOW){
    buttonPressed=2;
  }else if(digitalRead(col3)==LOW){
    buttonPressed=3;
  }else{
    digitalWrite(row0,HIGH);
    digitalWrite(row1,LOW);
    if(digitalRead(col0)==LOW){
      buttonPressed=4;
    }else if(digitalRead(col1)==LOW){
      buttonPressed=5;
    }else if(digitalRead(col2)==LOW){
      buttonPressed=6;
    }else if(digitalRead(col3)==LOW){
      buttonPressed=7;
    }else{
      buttonPressed=8;
    }
  }
  return buttonPressed;
}
