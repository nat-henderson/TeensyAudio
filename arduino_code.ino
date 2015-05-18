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
  pinMode(2, OUTPUT);
  pinMode(2, OUTPUT);
  
}

void loop() {
  
}
