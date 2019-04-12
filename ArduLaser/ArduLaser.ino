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
int d = 0;

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
bool laser1Enabled = false;
bool time1Set = false;
unsigned long laser1Time;
int epoch1[1000];

// Laser 2 parameters
int duration2 = 20;
int interval2 = 100;
bool laser2_On = false;
bool laser2Enabled = false;
bool time2Set = false;
unsigned long laser2Time;
int epoch2[1000];

// Laser 3 parameters
int duration3 = 20;
int interval3 = 100;
bool laser3_On = false;
bool laser3Enabled = false;
bool time3Set = false;
unsigned long laser3Time;
int epoch3[1000];

// Laser 4 parameters
int duration4 = 20;
int interval4 = 100;
bool laser4_On = false;
bool laser4Enabled = false;
bool time4Set = false;
unsigned long laser4Time;
int epoch4[1000];

// Laser 5 parameters
int duration5 = 20;
int interval5 = 100;
bool laser5_On = false;
bool laser5Enabled = false;
bool time5Set = false;
unsigned long laser5Time;
int epoch5[1000];

// Laser 6 parameters
int duration6 = 20;
int interval6 = 100;
bool laser6_On = false;
bool laser6Enabled = false;
bool time6Set = false;
unsigned long laser6Time;
int epoch6[1000];

// Setting up message holder
String message;

void setup() {
  Serial.begin(115200);
  SerialUSB.begin(921600);
  while(!SerialUSB);
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

  int values[4];
  int ci = 2;
  int vi = 0;
  
  for (int i = 2; i < msgIn.length()-1; i++) {
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
          laser1Enabled = true;
          for(int i=0; i<=60; i++) {
            epoch1[i] = 1;
          }
          numberOfScans = 60;
          c = 0;
        } else {
          digitalWrite(laser1, LOW);
          laser1_On = false;
          laser1Enabled = false;
          memset(epoch1, 0, sizeof(epoch1));
          execute = false;
        }
        break;
      case 2:
        if(values[1] == 1) {
          duration2 = values[2];
          interval2 = 1000/values[3];
          execute = true;
          laser2_On = true;
          laser2Enabled = true;
          for(int i=0; i<=60; i++) {
            epoch2[i] = 1;
          }
          numberOfScans = 60;
          c = 0;
        } else {
          digitalWrite(laser2, LOW);
          laser2_On = false;
          laser2Enabled = false;
          memset(epoch2, 0, sizeof(epoch2));
          execute = false;
        }
        break;
      case 3:
        if(values[1] == 1) {
          duration3 = values[2];
          interval3 = 1000/values[3];
          execute = true;
          laser3_On = true;
          laser3Enabled = true;
          for(int i=0; i<=60; i++) {
            epoch3[i] = 1;
          }
          numberOfScans = 60;
          c = 0;
        } else {
          digitalWrite(laser3, LOW);
          laser3_On = false;
          laser3Enabled = false;
          memset(epoch3, 0, sizeof(epoch3));
          execute = false;
        }
        break;
      case 4:
        if(values[1] == 1) {
          duration4 = values[2];
          interval4 = 1000/values[3];
          execute = true;
          laser4_On = true;
          laser4Enabled = true;
          for(int i=0; i<=60; i++) {
            epoch4[i] = 1;
          }
          numberOfScans = 60;
          c = 0;
        } else {
          digitalWrite(laser4, LOW);
          laser4_On = false;
          laser4Enabled = false;
          memset(epoch4, 0, sizeof(epoch4));
          execute = false;
        }
        break;
      case 5:
        if(values[1] == 1) {
          duration5 = values[2];
          interval5 = 1000/values[3];
          execute = true;
          laser5_On = true;
          laser5Enabled = true;
          for(int i=0; i<=60; i++) {
            epoch5[i] = 1;
          }
          numberOfScans = 60;
          c = 0;
        } else {
          digitalWrite(laser5, LOW);
          laser5_On = false;
          laser5Enabled = false;
          memset(epoch5, 0, sizeof(epoch5));
          execute = false;
        }
        break;
      case 6:
        if(values[1] == 1) {
          duration6 = values[2];
          interval6 = 1000/values[3];
          execute = true;
          laser6_On = true;
          laser6Enabled = true;
          for(int i=0; i<=60; i++) {
            epoch6[i] = 1;
          }
          numberOfScans = 60;
          c = 0;
        } else {
          digitalWrite(laser6, LOW);
          laser6_On = false;
          laser6Enabled = false;
          memset(epoch6, 0, sizeof(epoch6));
          execute = false;
        }
        break;
    }
    
  }
}

void calibrateLaser(String msgIn) {

  int values[4];
  int ci = 2;
  int vi = 0;
  
  for (int i = 2; i < msgIn.length()-1; i++) {
    if (msgIn.substring(i, i+1) == ",") {
      String msg = msgIn.substring(ci,i);
      values[vi] = msg.toInt();
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

void setupParadigm(String msgIn) {

  int values[1000];
  int ci = 2;
  int vi = 0;
  
  for (int i = 2; i < msgIn.length()-1; i++) {
    if (msgIn.substring(i, i+1) == ",") {
      String msg = msgIn.substring(ci,i);
      values[vi] = msg.toInt();
      ci=i+1;
      vi++;
    }
  }

  if(vi>0){
    switch (values[0]) {
      case 1:
        Serial.print("Paradigm1 = ");
        if(values[1] == 1) {
          laser1_On = true;
          laser1Enabled = true;
        } else {
          laser1_On = false;
          laser1Enabled = false;
        }
        duration1 = values[2];
        interval1 = 1000/values[3];
        for(int i = 0; i < (vi-4); i++) {
          epoch1[i] = values[i+4];
          Serial.print(epoch1[i]);
        }
        Serial.println("//end");
        Serial.print("Number of scans = ");
        Serial.println(numberOfScans);
        Serial.print("Enable = ");
        Serial.print(laser1Enabled);
        Serial.print(", Duration = ");
        Serial.print(duration1);
        Serial.print(", Interval = ");
        Serial.println(interval1);
        break;
      case 2:
        Serial.print("Paradigm2 = ");
        if(values[1] == 1) {
          laser2_On = true;
          laser2Enabled = true;
        } else {
          laser2_On = false;
          laser2Enabled = false;
        }
        duration2 = values[2];
        interval2 = 1000/values[3];
        for(int i = 0; i < (vi-4); i++) {
          epoch2[i] = values[i+4];
          Serial.print(epoch2[i]);
        }
        Serial.println("//end");
        Serial.print("Number of scans = ");
        Serial.println(numberOfScans);
        Serial.print("Enable = ");
        Serial.print(laser2Enabled);
        Serial.print(", Duration = ");
        Serial.print(duration2);
        Serial.print(", Interval = ");
        Serial.println(interval2);
        break;
      case 3:
        Serial.print("Paradigm3 = ");
        if(values[1] == 1) {
          laser3_On = true;
          laser3Enabled = true;
        } else {
          laser3_On = false;
          laser3Enabled = false;
        }
        duration3 = values[2];
        interval3 = 1000/values[3];
        for(int i = 0; i < (vi-4); i++) {
          epoch3[i] = values[i+4];
          Serial.print(epoch3[i]);
        }
        Serial.println("//end");
        Serial.print("Number of scans = ");
        Serial.println(numberOfScans);
        Serial.print("Enable = ");
        Serial.print(laser3Enabled);
        Serial.print(", Duration = ");
        Serial.print(duration3);
        Serial.print(", Interval = ");
        Serial.println(interval3);
        break;
      case 4:
        Serial.print("Paradigm4 = ");
        if(values[1] == 1) {
          laser4_On = true;
          laser4Enabled = true;
        } else {
          laser4_On = false;
          laser4Enabled = false;
        }
        duration4 = values[2];
        interval4 = 1000/values[3];
        for(int i = 0; i < (vi-4); i++) {
          epoch4[i] = values[i+4];
          Serial.print(epoch4[i]);
        }
        Serial.println("//end");
        Serial.print("Number of scans = ");
        Serial.println(numberOfScans);
        Serial.print("Enable = ");
        Serial.print(laser4Enabled);
        Serial.print(", Duration = ");
        Serial.print(duration4);
        Serial.print(", Interval = ");
        Serial.println(interval4);
        break;
      case 5:
        Serial.print("Paradigm5 = ");
        if(values[1] == 1) {
          laser5_On = true;
          laser5Enabled = true;
        } else {
          laser5_On = false;
          laser5Enabled = false;
        }
        duration5 = values[2];
        interval5 = 1000/values[3];
        for(int i = 0; i < (vi-4); i++) {
          epoch5[i] = values[i+4];
          Serial.print(epoch5[i]);
        }
        Serial.println("//end");
        Serial.print("Number of scans = ");
        Serial.println(numberOfScans);
        Serial.print("Enable = ");
        Serial.print(laser5Enabled);
        Serial.print(", Duration = ");
        Serial.print(duration5);
        Serial.print(", Interval = ");
        Serial.println(interval5);
        break;
      case 6:
        Serial.print("Paradigm6 = ");
        if(values[1] == 1) {
          laser6_On = true;
          laser6Enabled = true;
        } else {
          laser6_On = false;
          laser6Enabled = false;
        }
        duration6 = values[2];
        interval6 = 1000/values[3];
        for(int i = 0; i < (vi-4); i++) {
          epoch6[i] = values[i+4];
          Serial.print(epoch6[i]);
        }
        Serial.println("//end");
        Serial.print("Number of scans = ");
        Serial.println(numberOfScans);
        Serial.print("Enable = ");
        Serial.print(laser6Enabled);
        Serial.print(", Duration = ");
        Serial.print(duration6);
        Serial.print(", Interval = ");
        Serial.println(interval6);
        break;
    }
  }
}

void setupScanner(String msgIn) {

  int values[3];
  int ci = 2;
  int vi = 0;
  
  for (int i = 2; i < msgIn.length()-1; i++) {
    if (msgIn.substring(i, i+1) == ",") {
      String msg = msgIn.substring(ci,i);
      values[vi] = msg.toInt();
      ci=i+1;
      vi++;
    }
  }

  if(vi>0){
    numberOfScans = values[0];
    numberOfDummies = values[1];
    TR = values[2];
    c = 0;
    d = numberOfDummies;
    Serial.print("Number of scans = ");
    Serial.print(numberOfScans);
    Serial.print(", Number of Dummies = ");
    Serial.print(numberOfDummies);
    Serial.print(", TR(ms) = ");
    Serial.println(TR);
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

    if(d < 1) {
      // Controlling Laser 1
      if(epoch1[c] == 1 && laser1Enabled) {
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
      if(epoch2[c] == 1 && laser2Enabled) {
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
      if(epoch3[c] == 1 && laser3Enabled) {
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
      if(epoch4[c] == 1 && laser4Enabled) {
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
      if(epoch5[c] == 1 && laser5Enabled) {
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
      if(epoch6[c] == 1 && laser6Enabled) {
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
    }
    
    // Checking for end of TR
    now = millis();
    if((now - startTime) >= TR){
      d--;
      if(d < 0) {
        c++;
      }
      if(c==numberOfScans){
        c = 0;
        d = numberOfDummies;
        execute = false;
      }
      startSet = false;
    }
      
  } 

  while(SerialUSB.available()){
    if(SerialUSB.available() > 0){
      char inData = SerialUSB.read();
      message += inData;
      if(inData == '&') {
        msgReceived = true;
        break;
      }
    }
  }      
  
  if(msgReceived) {
    
    Serial.flush();
    digitalWrite(check,HIGH);
    delay(10);
    digitalWrite(check,LOW);
    Serial.println(message);

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
        digitalWrite(laser1, LOW);
        digitalWrite(laser2, LOW);
        digitalWrite(laser3, LOW);
        digitalWrite(laser4, LOW);
        digitalWrite(laser5, LOW);
        digitalWrite(laser6, LOW);
        break;
      case 'C':
        calibrateLaser(message);
        message = "";
        msgReceived = false;
        break;
      case 'U':
        setupParadigm(message);
        message = "";
        msgReceived = false;
        break;
      case 'S':
        setupScanner(message);
        message = "";
        msgReceived = false;
        break;
      default:
        break;
    }
  }  
}
