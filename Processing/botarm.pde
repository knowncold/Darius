int baseColor;
int snum = 2;   //舵机和引脚编号
int i,j,servonum;
int snumX,keycount,servoall;
int snumY = 60;
String num,nstr;
PFont font;
int txtbutwidth = 45;
int txtbutheight = 20;
int[] servo = {1800,1800,1500,800,1200,1200};
boolean[] servover = {false,false,false,false,false,false};
boolean swth = false;
int[] keypart = {0,0,0,0};
boolean subuton = false;
import processing.serial.*;
Serial myPort;


void setup(){
    size(640, 360);
    baseColor = color(102);
    background(baseColor);
    font = createFont("Arial", 16, true);
    textFont(font,16);
    fill(0);
    text ( "Servo Test" ,282,25);
    for(i=0;i<2;i++){
        snumX = 100;
        for(j=0;j<3;j++){
            num = str(snum);
            text(num,snumX,snumY);
            fill(255);
            rect(snumX-18,snumY+10,txtbutwidth,txtbutheight);
            fill(0);
            num = str(servo[snum-2]);
            text(num,snumX-16,snumY+25);
            snumX += 220;
            snum++;
        }
        snumY += 140;
    }
    fill(255);
    rect(560,300,45,20);
    String portName = Serial.list()[1];
    myPort = new Serial(this, portName, 9600);
}

void draw(){
    update();
}

void update(){
    snumY = 60;
    snum = 2;
    for(i=0;i<2;i++){
        snumX = 100;
        for(j=0;j<3;j++){
            if(ifover(snumX-18,snumY+10,txtbutwidth,txtbutheight)){
                servover[snum-2] = true;
            }else{
                servover[snum-2] = false;
            }
            snumX += 220;
            snum++;
        }
        snumY += 140;
    }
    if(ifover(560,300,45,20)){
        subuton = true;
    }else{
        subuton = false;
    }
}

void mousePressed(){
    fill(255);
    for(i=0;i<6;i++){
        if(servover[i]){
            if(i<3){
                rect((82+220*(i-0)),70,txtbutwidth,txtbutheight);
                servonum = i + 2;
                swth = true;
            }else{
                rect((82+220*(i-3)),210,txtbutwidth,txtbutheight);
                servonum = i + 2;
                swth = true;
            }
        }
    }
    if(subuton){
        println("serial submit");
        for(i=0;i<6;i++){
            print(servo[i]);
            print(" ");
        }
        println(" ");
        nstr = str(servo[0])+" "+str(servo[1])+" "+str(servo[2])+" "+str(servo[3])+" "+str(servo[4])+" "+str(servo[5])+"\n";
        myPort.write(nstr);
        println(nstr);
    }
}

void keyPressed(){
    println(key);
    if(key == ENTER){
        swth = false;
        keycount = 0;
        servoall = (keypart[0]*1000+keypart[1]*100+keypart[2]*10+keypart[3]);
        servo[servonum-2] = servoall;
        num = str(servo[servonum-2]);
        fill(0);
        if(servonum<5){
            text(num,(84+220*(servonum-2)),85);

            println(servo[servonum-2]);
        }else{
            text(num,(84+220*(servonum-5)),225);

            println(servo[servonum-2]);
        }
    }
    if(swth){
        if(key != CODED){
            keypart[keycount] = int(key) - 48;
            keycount++;
            if(keycount>3){
                keycount = 0;
            }
        }
    }
}

boolean ifover(int x,int y,int twidth,int theight){
    if(mouseX >= x && mouseX <= (x + twidth) && mouseY >= y && mouseY <= (y + theight)){
        return true;
    }else{
        return false;
    }
}