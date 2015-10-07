#include <Servo.h>

Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
Servo myservo7;

int i = 0;
int oldpos = 0;
int pos[6] = {1800,1800,800,800,1200,1200};

void setup(){
    Serial.begin(9600);
    Serial.println("start");
    myservo2.attach(2);
    myservo3.attach(3);
    myservo4.attach(4);
    myservo5.attach(5);
    myservo6.attach(6);
    myservo7.attach(7);
    myservo2.writeMicroseconds(1800);
    myservo3.writeMicroseconds(1800);
    myservo4.writeMicroseconds(1500);
    myservo5.writeMicroseconds(800);
    myservo6.writeMicroseconds(1200);
    myservo7.writeMicroseconds(1200);
}

void loop(){
    while (Serial.available() > 0) {
        i = 0;
        while(i<6){
            pos[i] = Serial.parseInt();
            i++;
        }
        if (Serial.read() == '\n') {
            oldpos = myservo2.readMicroseconds();
            if(oldpos > pos[0]){
                while(oldpos > pos[0]){
                    oldpos -= 50;
                    myservo2.writeMicroseconds(oldpos);
                    delay(50);
                }
            }else{
                while(oldpos < pos[0]){
                    oldpos += 50;
                    myservo2.writeMicroseconds(oldpos);
                    delay(50);
                }
            }
            oldpos = myservo3.readMicroseconds();
            if(oldpos > pos[1]){
                while(oldpos > pos[1]){
                    oldpos -= 50;
                    myservo3.writeMicroseconds(oldpos);
                    delay(50);
                }
            }else{
                while(oldpos < pos[1]){
                    oldpos += 50;
                    myservo3.writeMicroseconds(oldpos);
                    delay(50);
                }
            }
            oldpos = myservo4.readMicroseconds();
            if(oldpos > pos[2]){
                while(oldpos > pos[2]){
                    oldpos -= 50;
                    myservo4.writeMicroseconds(oldpos);
                    delay(50);
                }
            }else{
                while(oldpos < pos[2]){
                    oldpos += 50;
                    myservo4.writeMicroseconds(oldpos);
                    delay(50);
                }
            }
            oldpos = myservo5.readMicroseconds();
            if(oldpos > pos[3]){
                while(oldpos > pos[3]){
                    oldpos -= 50;
                    myservo5.writeMicroseconds(oldpos);
                    delay(50);
                }
            }else{
                while(oldpos < pos[3]){
                    oldpos += 50;
                    myservo5.writeMicroseconds(oldpos);
                    delay(50);
                }
            }
            oldpos = myservo6.readMicroseconds();
            if(oldpos > pos[4]){
                while(oldpos > pos[4]){
                    oldpos -= 50;
                    myservo6.writeMicroseconds(oldpos);
                    delay(50);
                }
            }else{
                while(oldpos < pos[4]){
                    oldpos += 50;
                    myservo6.writeMicroseconds(oldpos);
                    delay(50);
                }
            }
            oldpos = myservo7.readMicroseconds();
            if(oldpos > pos[5]){
                while(oldpos > pos[5]){
                    oldpos -= 50;
                    myservo7.writeMicroseconds(oldpos);
                    delay(50);
                }
            }else{
                while(oldpos < pos[5]){
                    oldpos += 50;
                    myservo7.writeMicroseconds(oldpos);
                    delay(50);
                }
            }
        }
    }
}
