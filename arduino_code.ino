#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=347,402
AudioMixer4              mixer1;         //xy=546,409
AudioAnalyzePeak         peak1;          //xy=764,410
AudioAnalyzeFFT1024      fft1024_1;      //xy=772,460
AudioConnection          patchCord1(i2s1, 0, mixer1, 0);
AudioConnection          patchCord2(i2s1, 1, mixer1, 1);
AudioConnection          patchCord3(mixer1, fft1024_1);
AudioConnection          patchCord4(mixer1, peak1);
AudioControlSGTL5000     sgtl5000_1;     //xy=551,507
// GUItool: end automatically generated code


boolean low = false;
boolean mid_low = false;
boolean mid_high = false;
boolean high = false;
float peak = 0.0;

void setup() {
  mixer1.gain(0, 0.5);
  mixer1.gain(1, 0.5);
  sgt15000_1.enable();
  sgt15000_1.inputSelect(AUDIO_INPUT_LINEIN);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  if (fft1024_1.available()) {
    for (int bucketID = 0; buckedID < 2; buckedID++) {
      low = low | (fft1024_1.read(bucketID) > 0.5);
    }
    for (int bucketID = 2; buckedID <= 10; buckedID++) {
      mid_low = mid_low | (fft1024_1.read(bucketID) > 0.5);
    }
    for (int bucketID = 10; buckedID < 25; buckedID++) {
      mid_high = mid_high | (fft1024_1.read(bucketID) > 0.5);
    }
    for (int bucketID = 25; buckedID <= 511; buckedID++) {
      high = high | (fft1024_1.read(bucketID) > 0.5);
    }
  }
  if (peak1.available()) {
    peak = peak1.read();
  }
  if (low) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
  if (mid_low) {
    digitalWrite(3, HIGH);    
  } else {
    digitalWrite(3, LOW);
  }
  if (mid_high) {
    digitalWrite(4, HIGH);    
  } else {
    digitalWrite(4, LOW);
  }
  if (high) {
    digitalWrite(5, HIGH);    
  } else {
    digitalWrite(5, LOW);
  }
  if (peak > 0.1) {
    digitalWrite(6, HIGH);    
  } else {
    digitalWrite(6, LOW);
  }
  if (peak > 0.25) {
    digitalWrite(7, HIGH);    
  } else {
    digitalWrite(7, LOW);
  }
  if (peak > 0.5) {
    digitalWrite(8, HIGH);    
  } else {
    digitalWrite(8, LOW);
  }
  if (peak > 0.75) {
    digitalWrite(9, HIGH);    
  } else {
    digitalWrite(9, LOW);
  }
}
