/************************
 * 
 * This file contains the settings for the ethernet module, GPIO pins for the LCD screen,
 * the states, the data structure, the normal conditions for the inputs, the alarm priority
 * they are associated with, the MODBUS modules, and the text strings used for the LCD display.
 * 
*************************/


/******
* MAC address for the ethernet module
* 
******/
byte mac[] = {0x60, 0x52, 0xD0, 0x07, 0x17, 0x14};


/******
* GPIO pins for the LCD screen
* 
******/
const int rs = 0, en = 1, d4 = 11, d5 = 12, d6 = 13, d7 = 14;


/******
 * 
 * Number of states
 * (CAUTION CHANGING THIS!!!)
 * 
 ******/
enum STATES{
  startup,
  normal,
  trouble1,
  trouble2,
  trouble3
};


/******
 * 
 * Input buffer and values
 * 
 ******/
char buf[2];
uint16_t read;
int input[16];
float analog1;
float analog2;
float analog3;
float tSniffer;
float vacuum;
float subPump;


/******
 * Initial state of the interlock
 * 
 ******/
STATES newState = normal;
STATES currentState = startup;


/******
* Specify the trouble condition each input would trigger
* 
******/
STATES alarm[16] = {
    normal,     // Reset switch
    trouble3,     // Emergency source trip switch
    trouble1,   // Cage door contact
    trouble3,   // Fume hood flow switch
    trouble2,   // Vacuum condition - gnd
    trouble3,   // Tritium monitor
    normal,   // UNUSED
    trouble3,   // Power failure
    trouble3,   // Coolant flow - gnd
    trouble2,   // Vacuum condition - mid
    normal,   // UNUSED
    trouble3,   // Coolant flow - high
    trouble3,   // Smoke detector - high
    normal,     // UNUSED
    normal,     // UNUSED
    normal      // UNUSED

};


/******
* Specify the normal condition for each input
* 
*****/
bool input_normal[16] = {

    OPEN, 	// Reset switch
    CLOSED,	  // Emergency source trip switch
    CLOSED,	// Cage door contact
    CLOSED, // Fume hood flow switch
    OPEN,	  // Vacuum condition - gnd
    CLOSED,	// Tritium monitor
    OPEN,	  // UNUSED
    CLOSED,	// Power failure
    CLOSED,	// Coolant flow - gnd
    OPEN,	  // Vacuum condition - mid
    OPEN,	  // UNUSED
    CLOSED,	// Coolant flow - high
    OPEN, 	// Smoke detector - high
    OPEN,	  // UNUSED
    OPEN,	  // UNUSED
    OPEN	  // UNUSED
    
};

/******
* Array to track the output status for updating interfaces
* 
******/
bool output[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


/******
* Specify which modules are on the MODBUS
* 
******/
const char* RollCall[] = {
  "P1-16ND3", "P1-08TRS", "P1-08TRS", "P1-04ADL-2"
};


/******
* Text strings for the LCD Display
* 
******/
String state_txt[] = {"Rebooting...",
                      "Source Normal",
                      "Cage Door Trip!",
                      "Vacuum Trip!",
                      "Source Trip!"};

String in_txt[] = { "Reset Button",
                    "Emergency Switch",
                    "Cage Door Open",
                    "Fume Hood Flow",
                    "Vacuum Gauge 2",
                    "Tritium Monitor",
                    "error: port map",
                    "Bldg Power Fail",
                    "Coolant Flow 2",
                    "Vacuum Gauge 1",
                    "error: port map",
                    "Coolant Flow 1",
                    "Smoke at Source",
                    "error: port map",
                    "error: port map",
                    "error: port map",
                    ""};
