// Setting up pins
int laser1 = 2;
int laser2 = 3;
int laser3 = 4;
int laser4 = 5;
int laser5 = 6;
int laser6 = 7;
int scanner = 8;
int check = 12;

// Setting up epoch controllers
int c = 0;

// Setting up timers
unsigned long startTime;
unsigned long now;

// Executtion control
bool startSet = false; 
bool execute = false;
bool msgReceived = false;

// Scanner parameters
int TR = 1000;
int scannerDuration = 10;
int numberOfScans = 20;
int numberOfDummies = 10;
bool scanner_On = false;

// Laser 1 parameters
int duration1 = 20;
int interval1 = 100;
bool laser1_On = false;
bool time1Set = false;
unsigned long laser1Time;
int epoch1[99];

// Laser 2 parameters
int duration2 = 20;
int interval2 = 100;
bool laser2_On = false;
bool time2Set = false;
unsigned long laser2Time;
int epoch2[99];

// Laser 3 parameters
int duration3 = 20;
int interval3 = 100;
bool laser3_On = false;
bool time3Set = false;
unsigned long laser3Time;
int epoch3[99];

// Laser 4 parameters
int duration4 = 20;
int interval4 = 100;
bool laser4_On = false;
bool time4Set = false;
unsigned long laser4Time;
int epoch4[99];

// Laser 5 parameters
int duration5 = 20;
int interval5 = 100;
bool laser5_On = false;
bool time5Set = false;
unsigned long laser5Time;
int epoch5[99];

// Laser 6 parameters
int duration6 = 20;
int interval6 = 100;
bool laser6_On = false;
bool time6Set = false;
unsigned long laser6Time;
int epoch6[99];

// Setting up message holder
String message;

void setup() {
  Serial.begin(115200);
  pinMode(laser1, OUTPUT);
  pinMode(laser2, OUTPUT);
  pinMode(laser3, OUTPUT);
  pinMode(laser4, OUTPUT);
  pinMode(laser5, OUTPUT);
  pinMode(laser6, OUTPUT);
  pinMode(scanner, OUTPUT);
  pinMode(check, OUTPUT);
}

void testLaser(String msgIn){
   
  char str[8];
  int values[4];
  int ci = 2;
  int vi = 0;
  
  for (int i = 2; i < msgIn.length(); i++) {
    if (msgIn.substring(i, i+1) == ",") {
      String msg = msgIn.substring(ci,i);
      values[vi] = msg.toInt();
      //Serial.println(values[vi]);
      ci=i+1;
      vi++;
    }
  }

  if(vi>0){
    switch (values[0]) {
      case 1:
        if(values[1] == 1) {
          duration1 = values[2];
          interval1 = 1000/values[3];
          execute = true;
          laser1_On = true;
          epoch1[0] = 1;
          numberOfScans = 1;
          c = 0;
        } else {
          laser1_On = false;
          execute = false;
        }
        break;
      case 2:
        if(values[1] == 1) {
          duration2 = values[2];
          interval2 = 1000/values[3];
          execute = true;
          laser2_On = true;
          epoch2[0] = 1;
          numberOfScans = 1;
          c = 0;
        } else {
          laser2_On = false;
          execute = false;
        }
        break;
      case 3:
      if(values[1] == 1) {
          duration3 = values[2];
          interval3 = 1000/values[3];
          execute = true;
          laser3_On = true;
          epoch3[0] = 1;
          numberOfScans = 1;
          c = 0;
        } else {
          laser3_On = false;
          execute = false;
        }
        break;
      case 4:
      if(values[1] == 1) {
          duration4 = values[2];
          interval4 = 1000/values[3];
          execute = true;
          laser4_On = true;
          epoch4[0] = 1;
          numberOfScans = 1;
          c = 0;
        } else {
          laser4_On = false;
          execute = false;
        }
        break;
      case 5:
      if(values[1] == 1) {
          duration5 = values[2];
          interval5 = 1000/values[3];
          execute = true;
          laser5_On = true;
          epoch5[0] = 1;
          numberOfScans = 1;
          c = 0;
        } else {
          laser5_On = false;
          execute = false;
        }
        break;
      case 6:
      if(values[1] == 1) {
          duration6 = values[2];
          interval6 = 1000/values[3];
          execute = true;
          laser6_On = true;
          epoch6[0] = 1;
          numberOfScans = 1;
          c = 0;
        } else {
          laser6_On = false;
          execute = false;
        }
        break;
    }
    
  }
}

void calibrateLaser(String msgIn) {
  char str[8];
  int values[4];
  int ci = 2;
  int vi = 0;
  
  for (int i = 2; i < msgIn.length(); i++) {
    if (msgIn.substring(i, i+1) == ",") {
      String msg = msgIn.substring(ci,i);
      values[vi] = msg.toInt();
      //Serial.println(values[vi]);
      ci=i+1;
      vi++;
    }
  }

  if(vi>0){
    switch (values[0]) {
      case 1:
        if(values[1] == 1) {
          digitalWrite(laser1, HIGH);
        } else {
          digitalWrite(laser1, LOW);
        }
        break;
      case 2:
        if(values[1] == 1) {
          digitalWrite(laser2, HIGH);
        } else {
          digitalWrite(laser2, LOW);
        }
        break;
      case 3:
      if(values[1] == 1) {
          digitalWrite(laser3, HIGH);
        } else {
          digitalWrite(laser3, LOW);
        }
        break;
      case 4:
      if(values[1] == 1) {
          digitalWrite(laser4, HIGH);
        } else {
          digitalWrite(laser4, LOW);
        }
        break;
      case 5:
      if(values[1] == 1) {
          digitalWrite(laser5, HIGH);
        } else {
          digitalWrite(laser5, LOW);
        }
        break;
      case 6:
      if(values[1] == 1) {
          digitalWrite(laser6, HIGH);
        } else {
          digitalWrite(laser6, LOW);
        }
        break;
    }
  }  
}

void loop() {
  
  if(execute) {
    
    if(!startSet) {
      // Setting start time
      startTime = millis();
      // Enabling and switchin on scanner
      scanner_On = true;
      digitalWrite(scanner,HIGH);
      // Enabling lasers
      laser1_On = true;
      laser2_On = true;
      startSet = true;
    }
  
    // Controlling Scanner
    if(scanner_On) {
      now = millis();
      if((now - startTime) >= scannerDuration) {
        digitalWrite(scanner,LOW);
        scanner_On = false;
      }
    }
  
    // Controlling Laser 1
    if(epoch1[c] == 1) {
      if(laser1_On) {
        if(!time1Set) {
          digitalWrite(laser1, HIGH);
          laser1Time = millis();
          time1Set = true;
        }
        now = millis();
        if((now - laser1Time) >= duration1) {
          digitalWrite(laser1,LOW);
          laser1_On = false;
          time1Set = false;
        }
      }
      now = millis();
      if((now - laser1Time) >= interval1) {
        laser1_On = true;
      }
    }
  
    // Controlling Laser 2
    if(epoch2[c] == 1) {
      if(laser2_On) {
        if(!time2Set) {
          digitalWrite(laser2, HIGH);
          laser2Time = millis();
          time2Set = true;
        }
        now = millis();
        if((now - laser2Time) >= duration2) {
          digitalWrite(laser2,LOW);
          laser2_On = false;
          time2Set = false;
        }
      }
      now = millis();
      if((now - laser2Time) >= interval2) {
        laser2_On = true;
      }
    }

    // Controlling Laser 3
    if(epoch3[c] == 1) {
      if(laser3_On) {
        if(!time3Set) {
          digitalWrite(laser3, HIGH);
          laser3Time = millis();
          time3Set = true;
        }
        now = millis();
        if((now - laser3Time) >= duration3) {
          digitalWrite(laser3,LOW);
          laser3_On = false;
          time3Set = false;
        }
      }
      now = millis();
      if((now - laser3Time) >= interval3) {
        laser3_On = true;
      }
    }

    // Controlling Laser 4
    if(epoch4[c] == 1) {
      if(laser4_On) {
        if(!time4Set) {
          digitalWrite(laser4, HIGH);
          laser4Time = millis();
          time4Set = true;
        }
        now = millis();
        if((now - laser4Time) >= duration4) {
          digitalWrite(laser4,LOW);
          laser4_On = false;
          time4Set = false;
        }
      }
      now = millis();
      if((now - laser4Time) >= interval4) {
        laser4_On = true;
      }
    }

    // Controlling Laser 5
    if(epoch5[c] == 1) {
      if(laser5_On) {
        if(!time5Set) {
          digitalWrite(laser5, HIGH);
          laser5Time = millis();
          time5Set = true;
        }
        now = millis();
        if((now - laser5Time) >= duration5) {
          digitalWrite(laser5,LOW);
          laser5_On = false;
          time5Set = false;
        }
      }
      now = millis();
      if((now - laser5Time) >= interval5) {
        laser5_On = true;
      }
    }

    // Controlling Laser 6
    if(epoch6[c] == 1) {
      if(laser6_On) {
        if(!time6Set) {
          digitalWrite(laser6, HIGH);
          laser6Time = millis();
          time6Set = true;
        }
        now = millis();
        if((now - laser6Time) >= duration6) {
          digitalWrite(laser6,LOW);
          laser6_On = false;
          time6Set = false;
        }
      }
      now = millis();
      if((now - laser6Time) >= interval6) {
        laser6_On = true;
      }
    }
  
    // Checking for end of TR
    now = millis();
    if((now - startTime) >= TR){
      c++;
      if(c==numberOfScans){
        c = 0;
      }
      startSet = false;
    }
  } 

  while(Serial.available()){
    delay(10);
    if(Serial.available() > 0){
      char inData = Serial.read();
      message += inData;
    }
    if(!msgReceived) {
      msgReceived = true;
    }
  }      
  
  if(msgReceived) {
    //Serial.flush();
    digitalWrite(check,HIGH);
    delay(100);
    digitalWrite(check,LOW);
    
    switch(message.charAt(0)) {
      case'T':
        testLaser(message);
        message = "";
        msgReceived = false;
        break;
      case 'E':
        execute = true;
        message = "";
        msgReceived = false;
        break;
      case 'O':
        execute = false;
        message = "";
        msgReceived = false;
        break;
      case 'C':
        calibrateLaser(message);
        message = "";
        msgReceived = false;
        break;
      default:
        break;
    }
  }  
}

