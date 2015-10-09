#include <Servo.h>
Servo myservo[6];
int i = 0;
int oldpos = 0;
int pos[6] = {1800,1800,1500,800,1200,1200};

void setup(){
    Serial.begin(9600);
    Serial.println("start");
    for(i=2;i<8;i++){
        myservo[i-2].attach(i);
    }
    for(i=2;i<8;i++){
        myservo[i-2].writeMicroseconds(pos[i-2]);
    }
}

void loop(){
    while (Serial.available() > 0) {
        i = 0;
        while(i<6){
            pos[i] = Serial.parseInt();
            i++;
        }
        if (Serial.read() == '\n') {
            for(i=2;i<8;i++){
                oldpos = myservo[i-2].readMicroseconds();
                if(oldpos > pos[i-2]){
                    while(oldpos > pos[i-2]){
                        oldpos -= 50;
                        myservo[i-2].writeMicroseconds(oldpos);
                        delay(50);
                    }
                }else{
                    if(oldpos == pos[i-2]){
                        myservo[i-2].writeMicroseconds(oldpos);
                    }
                    while(oldpos < pos[i-2]){
                        oldpos += 50;
                        myservo[i-2].writeMicroseconds(oldpos);
                        delay(50);
                    }
                }
            }
        }
    }
}
