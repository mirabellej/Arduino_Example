/*
 * Multi-tasking with outputs 
 * 
 * How can we have more than one output working at the same time without using delay()? 
 * Let's set up timers and use millis() to blink our LED and play a sound on our piezo at different times. 
 */
int ledPin =  8; 
int piezo = 9; 

// Keep track of our LED
int ledState = LOW;             // ledState used to set the LED
unsigned long previousBlink = 0;        // will store last time LED was updated
long blinkInterval = 500;    // interval at which to blink (milliseconds)

// Keep track of our piezo 
int onDuration = 1000; // how long do we want our piezo to sound for?
int pauseDuration = 2000; // how long do we want our piezo to be silent for?
unsigned long lastMelodyStart; // keep track of the last time we played our melody or tone


void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  blinkLED();
  beepPiezo(); 
}


void blinkLED(){
    unsigned long currentBlink = millis();

  if (currentBlink - previousBlink >= blinkInterval) {
    // save the last time you blinked the LED
    previousBlink = currentBlink;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}

void beepPiezo(){
  // if the current time minus the last start time is greater than our pause duration
  if (millis() - lastMelodyStart >= pauseDuration) { 
    lastMelodyStart = lastMelodyStart + pauseDuration; // increase the start of our last melody by the pause duration
    tone(piezo, 550, onDuration); // sound our tone
  }
}
