// Setting up pins
int laser1 = 3;
int laser2 = 5;
int scanner = 6;
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
int values1[5];
int power1 = 100;
int pwr1;
int epoch1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

// Laser 2 parameters
int duration2 = 20;
int interval2 = 100;
bool laser2_On = false;
bool time2Set = false;
unsigned long laser2Time;
int values2[5];
int power2 = 100;
int pwr2;
int epoch2[] = {1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1};

// Setting up message holder
String message;

void setup() {
  Serial.begin(115200);
  pinMode(laser1, OUTPUT);
  pinMode(laser2, OUTPUT);
  pinMode(scanner, OUTPUT);
  pinMode(check, OUTPUT);
}

void testLaser1(String message){

  digitalWrite(check,HIGH);
  delay(100);
  digitalWrite(check,LOW);
      
  char str[8];
  int ci = 2;
  int vi = 0;
  
  for (int i = 2; i < message.length(); i++) {
    if (message.substring(i, i+1) == ",") {
      String msg = message.substring(ci,i);
      values1[vi] = msg.toInt();
      //Serial.println(values[vi]);
      ci=i+1;
      vi++;
    }
  }

  if(vi>0){
    power1 = map(values1[2], 0, 100, 0, 255);
    duration1 = values1[3];
    interval1 = 1000/values1[4];
    execute = true;
  }
}

void loop() {
  
  if(execute) {
    // Mapping power output
    pwr2 = map(power2, 0, 100, 0, 255);
    
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
          analogWrite(laser1, power1);
          laser1Time = millis();
          time1Set = true;
        }
        now = millis();
        if((now - laser1Time) >= duration1) {
          analogWrite(laser1,LOW);
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
          analogWrite(laser2, pwr2);
          laser2Time = millis();
          time2Set = true;
        }
        now = millis();
        if((now - laser2Time) >= duration2) {
          analogWrite(laser2,LOW);
          laser2_On = false;
          time2Set = false;
        }
      }
      now = millis();
      if((now - laser2Time) >= interval2) {
        laser2_On = true;
      }
    }
  
    // Checking for end of TR
    now = millis();
    if((now - startTime) >= TR){
      c++;
      if(c==21){
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
    switch(message.charAt(0)) {
      case'T':
        testLaser1(message);
        message = "";
        break;
      case 'E':
        execute = true;
        message = "";
        break;
      case 'O':
        execute = false;
        message = "";
        break;
      default:
        break;
    }
  }  
}

