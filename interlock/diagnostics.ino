/************************
 * 
 * This file contains diagnostic functions and statements that can be copied into the main
 *  file or called from here if you un-comment them.
 * 
*************************/

// Included for Testing
//#include <ArduinoTrace.h>
//#TRACE(); // output a stamp to serial everytime it's called
//#DUMP(variable); // dumps the value of the variable you pass in to the serial output


// Verify modules configured without error
/*
if (P1.rollCall(RollCall, 4) == 0) {
Serial.println("True");
}
*/

/********************
* Function to print the state and any tripped conditions as well as the analog values
*
********************/
void print_states(){

  Serial.print("\nCurrent State: ");

  switch (newState) {

    case normal:
      Serial.println("normal");
      break;

    case trouble1:
      Serial.println("trouble 1 - cage door trip");
      break;

    case trouble2:
      Serial.println("trouble 2 - vacuum trip");
      break;
        
    case trouble3:
      Serial.println("trouble 3 - source trip");
      break;
  }


  for(int n=0; n<16; n++) {

    if (input[n] != input_normal[n]){
        Serial.print("Input ");
        Serial.print(n+1);
        Serial.println(" is tripped");
    }  
  }

  Serial.print("\nTritium Sniffer Voltage: ");
  Serial.println(analog1,6);

  Serial.print("\nVaccuum Gauge Mid-Potential Voltage: ");
  Serial.println(analog2,6);

  Serial.print("\nTitanium Sublimation Pump 1 Mid-Potential Voltage: ");
  Serial.println(analog3,6);

}