/************************
 * 
 * This file contains the names for the signals and maps the ports and pins
 * to convenient variable names (in# or out#). Only change the comments for the
 * signals to match what's connected to the interlock for reference.
 * 
*************************/

//Logic
#define OPEN 0
#define CLOSED 1

// P1-16ND3 - inputs signals
#define in1 1,1     // Reset switch
#define in2 1,2     // Gate valve close switch
#define in3 1,3     // Cage door contact
#define in4 1,4     // Fume hood flow switch
#define in5 1,5     // Vacuum condition - gnd
#define in6 1,6     // Tritium monitor
#define in7 1,7     // UNUSED
#define in8 1,8     // Power failure
#define in9 1,9     // Coolant flow - gnd
#define in10 1,10   // Vacuum condition - mid
#define in11 1,11   // UNUSED
#define in12 1,12   // Coolant flow - high
#define in13 1,13   // Smoke detector - high
#define in14 1,14   // UNUSED
#define in15 1,15   // UNUSED
#define in16 1,16   // UNUSED

// P1-08TRS #1 - output relays
#define out1 2,1    // Green or flashing red LED
#define out2 2,2    // Buzzer
#define out3 2,3    // Red LED trouble 1
#define out4 2,4    // Red LED trouble 2
#define out5 2,5    // Red LED trouble 3
#define out6 2,6    // Pre-accelerator power supply
#define out7 2,7    // Gate valve - gnd
#define out8 2,8    // Gate valve - mid

// P1-08TRS #2 - output relays
#define out9 3,1    // UNUSED
#define out10 3,2   // UNUSED
#define out11 3,3   // UNUSED
#define out12 3,4   // UNUSED
#define out13 3,5   // UNUSED
#define out14 3,6   // High-volt power supplies - high
#define out15 3,7   // Boiler - high
#define out16 3,8   // Ionizer - high

// P1-04ADL-2 - analog input voltages
#define anin1 4,1   //Tritium sniffer
#define anin2 4,2   //Vaccuum gauge - mid
#define anin3 4,3   //TSP1 - mid

//LED heartbeat on controller
#define heartbeat 32
