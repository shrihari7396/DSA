#include <Servo.h>

Servo vertical;

int servoh = 30;  
int servoMax = 160;
int servoMin = 20;

int topConnection = A1;
int botConnection = A0;

void setup () {
    vertical.attach(3);
    vertical.write(servoh);
    delay(3000);
}

void loop() {
    
    int top = analogRead(topConnection);  
    int bot = analogRead(botConnection);  
    
    int delayTime = 500;  

    int diff = top - bot;

    if (top > bot) {
        servoh = --servoh;  
        if (servoh < servoMin) {
            servoh = servoMin;  
        }
    } else if (top < bot) {
            servoh = ++servoh;
        if (servoh > servoMax) {
            servoh = servoMax;
        }
    }

        vertical.write(servoh);

        delay(delayTime);
    }