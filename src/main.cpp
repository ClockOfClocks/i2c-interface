#include <Arduino.h>
#include <Wire.h>

// https://oscarliang.com/raspberry-pi-arduino-connected-i2c/

#define SLAVE_ADDRESS 0x04
int number = 0;
int state = 0;

// callback for sending data
void sendData(){
        Wire.write(number);
}

// callback for received data
void receiveData(int byteCount){

        Serial.print("byteCount: ");
        Serial.println(byteCount);

        int i=0;
        unsigned int fi=0;
        while(Wire.available()) {
                i++;
                number = Wire.read();
                Serial.print("data received: ");
                if(i<=2) {
                        Serial.print("ski: ");
                }
                Serial.println(number);
                if(i==3) {
                        fi = number;
                }else if(i>3) {
                        fi <<= 8;
                        fi+=number;
                }

                if (number == 1) {

                        if (state == 0) {
                                digitalWrite(LED_BUILTIN, HIGH); // set the LED on
                                state = 1;
                        }
                        else{
                                digitalWrite(LED_BUILTIN, LOW); // set the LED off
                                state = 0;
                        }
                }
        }

        Serial.print("fi number: ");
        Serial.println(fi);
}


void setup() {
        pinMode(LED_BUILTIN, OUTPUT);

        Serial.begin(9600); // start serial for output
        // initialize i2c as slave
        Wire.begin(SLAVE_ADDRESS);

        // define callbacks for i2c communication
        Wire.onReceive(receiveData);
        Wire.onRequest(sendData);

        Serial.println("Ready!");
}

void loop() {
        delay(100);
}
