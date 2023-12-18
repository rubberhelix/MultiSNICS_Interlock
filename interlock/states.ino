/************************
 * 
 * This file contains the settings for the output conditions for different states.
 * 
*************************/


/********************
* Function to reset to normal state
* 
*********************/
void normal_state(void) {

  P1.writeDiscrete(LOW,out1); //Main status LED green
  output[0] = 0;
  P1.writeDiscrete(LOW,out2); //Buzzer silent
  output[1] = 0;
  P1.writeDiscrete(LOW,out3); //Trouble 1 LED off
  output[2] = 0;
  P1.writeDiscrete(LOW,out4); //Trouble 2 LED off
  output[3] = 0;
  P1.writeDiscrete(LOW,out5); //Trouble 3 LED off
  output[4] = 0;

  P1.writeDiscrete(HIGH,out6); //Pre-accelerator supply on
  output[5] = 1;

  P1.writeDiscrete(HIGH,out7); //Gate Valve - Gnd Open
  output[6] = 1;
  P1.writeDiscrete(HIGH,out8); //Gate Valve - Mid Open
  output[7] = 1;

  P1.writeDiscrete(HIGH,out14); //High-volt supplies on
  output[13] = 1;
  P1.writeDiscrete(HIGH,out15); //Boiler supply on
  output[14] = 1;
  P1.writeDiscrete(HIGH,out16); //Ionizer supply on
  output[15] = 1;
  
}


/********************
* Function to initiate trouble 1 state
* 
*********************/
void trouble1_state(void) {

  P1.writeDiscrete(HIGH,out1); //Main Status LED flashing red
  output[0] = 0;
  P1.writeDiscrete(HIGH,out2); //Buzzer on
  output[1] = 1;
  P1.writeDiscrete(HIGH,out3); //Trouble 1 LED on
  output[2] = 1;
  P1.writeDiscrete(LOW,out4); //Trouble 2 LED off
  output[3] = 0;
  P1.writeDiscrete(LOW,out5); //Trouble 3 LED off
  output[4] = 0;

  P1.writeDiscrete(LOW,out6); //Pre-accelerator supply off
  output[5] = 0;

   P1.writeDiscrete(LOW,out14); //High-volt supplies off
  output[13] = 0;
  
}


/********************
* Function to initiate trouble 2 state
* 
*********************/
void trouble2_state(void) {

  P1.writeDiscrete(HIGH,out1); //Main Status LED flashing red
  output[0] = 1;
  P1.writeDiscrete(HIGH,out2); //Buzzer on
  output[1] = 1;
  P1.writeDiscrete(LOW,out3); //Trouble 1 LED off
  output[2] = 0;
  P1.writeDiscrete(HIGH,out4); //Trouble 2 LED on
  output[3] = 1;
  P1.writeDiscrete(LOW,out5); //Trouble 3 LED off
  output[4] = 0;

  P1.writeDiscrete(LOW,out6); //Pre-accelerator supply off
  output[5] = 0;

  P1.writeDiscrete(LOW,out7); //Gate Valve - Gnd Closed
  output[6] = 0;
  P1.writeDiscrete(LOW,out8); //Gate Valve - Mid Closed
  output[7] = 0;

  P1.writeDiscrete(LOW,out14); //High-volt supplies off
  output[13] = 0;
  P1.writeDiscrete(LOW,out16); //Ionizer supply off
  
  output[15] = 0;

}


/********************
* Function to initiate trouble 3 state
* 
*********************/
void trouble3_state(void) {
  
  P1.writeDiscrete(HIGH,out1); //Main Status LED flashing red
  output[0] = 1;
  P1.writeDiscrete(HIGH,out2); //Buzzer on
  output[1] = 1;
  P1.writeDiscrete(LOW,out3); //Trouble 1 LED off
  output[2] = 0;
  P1.writeDiscrete(LOW,out4); //Trouble 2 LED off
  output[3] = 0;
  P1.writeDiscrete(HIGH,out5); //Trouble 3 LED on
  output[4] = 1;

  P1.writeDiscrete(LOW,out6); //Pre-accelerator supply off
  output[5] = 0;
  
  P1.writeDiscrete(LOW,out7); //Gate Valve - Gnd Closed
  output[6] = 0;
  P1.writeDiscrete(LOW,out8); //Gate Valve - Mid Closed
  output[7] = 0;

  P1.writeDiscrete(LOW,out14); //High-volt supplies off
  output[13] = 0;
  P1.writeDiscrete(LOW,out15); //Boiler supply off
  output[14] = 0;
  P1.writeDiscrete(LOW,out16); //Ionizer supply off
  output[15] = 0;

}


/********************
* Function to silence the buzzer
* 
*********************/
void acknowledge(void) {

  P1.writeDiscrete(LOW,out2); //Buzzer silent
  output[1] = 0;
  
}
