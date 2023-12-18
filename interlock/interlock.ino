/************************
 * 
 * This is the main file for the software. It contains boot up procedures, main routines and
 *  any diagnostic functions for development and testing.
 * 
*************************/

#include <P1AM.h>
#include "map.h"
#include "config.h"
#include <Ethernet.h>
#include <LiquidCrystal.h>


// Network configuration
IPAddress ip(128, 186, 111, 180);
EthernetServer server(80);

// LCD display configuration
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Timer variables
unsigned long printerPace = 0;
unsigned long heartBeat = 0;
unsigned long lcdTimer = 0;
unsigned long lcdReset = 0;

// LCD display variable
int lcdLooper = 0;
int lcdLine2 = 16;

/******* 
 *Setup function runs once on startup
 *******/
void setup() {

  // Start LCD display and initial message
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Rebooting...");

  // Flash LED during initialization of modules
  while (!P1.init()) {
    digitalWrite(heartbeat, !digitalRead(heartbeat));
    delay(250);
  }

  // Initialize analog module settings
  const char P1_04ADL_2_CONFIG[] = { 0x40, 0x02 };  //only 3 setup at the moment

  // Serial begin for any readouts
  Serial.begin(9600);

  // Prints the modules connected to the bus 
  Serial.println(P1.rollCall(RollCall, 4));

  // Watchdog timer resets the system if it stalls for 5 seconds without being pet
  P1.configWD(5000, TOGGLE);
  P1.startWD();

  // Configure pin modes
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(SWITCH_BUILTIN,INPUT);

  // Ethernet setup and print info to serial
  Ethernet.init(5);
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());

  // Interrupts for future use to streamline important input changes
  //attachInterrupt(digitalPinToInterrupt(pin),ISR,mode);
  //attachInterrupt(digitalPinToInterrupt(pin),ISR,mode);


  /*######
  * Send start-up notice to logging server
  ######*/

  // Startup input check
  app_Tasks();

}

void loop() {


  // Read button on front panel
  if (P1.readDiscrete(in1) == CLOSED) {
    acknowledge();                          //Acknowledge alarm and silence buzzer
    delay(2000);
    if (P1.readDiscrete(in1) == CLOSED){    //Reset to normal condition
      newState = normal;
    }
  } 

  // Check the inputs and update the state
  app_Tasks();

  // Update the interfaces
  app_Interfaces();


  // Reset the watchdog timer
  P1.petWD();
  
}
