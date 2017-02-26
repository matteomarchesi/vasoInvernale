/*
 * vasoInvernale
 * REQUIRES: FastLED 3.1.0
 * 
 * Copyright (c) 2017 Matteo Marchesi
 *
 */


#include "FastLED.h"

// definisce il numero di led da comnadare nella striscia
#define NUM_LEDS 20

#define DATA_PIN 3

CRGB leds[NUM_LEDS];


int giornonotte_ledGRP1[]= {7,0,1,2,3,4,5,6};
int giornonotte_contaGRP1 = 0;
int colorGRP1=128;

int giornonotte_ledGRP2[]= {7,7,8,9,10,11,12,13};
int giornonotte_contaGRP2 = 0;
int colorGRP2=150;

int giornonotte_ledGRP3[]= {6,14,15,16,17,18,19};
int giornonotte_contaGRP3 = 0;
int colorGRP3=180;


int giornonotte(int cycle, int ledarray[]);

int bright = 255;
int fade = 32;

unsigned long previousGRP1 = 0;
const long intervalGRP1 = 50;

unsigned long previousGRP2 = 0;
const long intervalGRP2 = 80;

unsigned long previousGRP3 = 0;
const long intervalGRP3 = 80;


void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

}

void loop() {
  unsigned long current = millis();

  if (current - previousGRP1 >= intervalGRP1) {
    previousGRP1 = current;
    giornonotte_contaGRP1 = giornonotte(giornonotte_contaGRP1, giornonotte_ledGRP1,colorGRP1);
  }

  if (current - previousGRP2 >= intervalGRP2) {
    previousGRP2 = current;
    giornonotte_contaGRP2 = giornonotte(giornonotte_contaGRP2, giornonotte_ledGRP2,colorGRP2);
  }

  if (current - previousGRP3 >= intervalGRP3) {
    previousGRP3 = current;
    giornonotte_contaGRP3 = giornonotte(giornonotte_contaGRP3, giornonotte_ledGRP3,colorGRP3);
  }


}

int giornonotte(int cycle, int ledarray[],int C){
//  int C = 16; //color
  int B = sin8(cycle);      // bright  
//  int S = sin8(cycle+128);  //saturation
  int S = 128;
  for (int i = 0; i < ledarray[0]; i++){
    leds[ledarray[i+1]] = CHSV(C,S,B);
  }
  FastLED.show();
  cycle ++;
  return cycle;
}
