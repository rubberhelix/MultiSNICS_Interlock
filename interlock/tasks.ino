/************************
 * 
 * This file contains the main functions for checking the inputs, changing states,
 *  and updating interfaces.
 * 
*************************/


/********************
* Function to check the condition of the inputs and update the state.
* 
*********************/
void app_Tasks(void){

  // Read discrete input values from the buffer and shift into an array
  P1.readBlockData(buf,2,0,DISCRETE_IN_BLOCK);

  read = (buf[1] << 8);
  read += (buf[0] << 0);

  // If the input is in alarm, escalate the new state
  for(int n=0; n<16; n++) {
    input[n] = ((read >> n) & 0b1) ? 1 : 0;
    if (input[n] != input_normal[n]){
      if (alarm[n] > newState) {
          newState = alarm[n];
      }
    }  
  }


  // Read analog values and scale to the unit ranges
  analog1 = P1.readAnalog(anin1)*10.0/8191.0; //  voltage
  analog2 = P1.readAnalog(anin2)*10.0/8191.0; //  voltage
  analog3 = P1.readAnalog(anin3)*10.0/8191.0; //  voltage
  tSniffer = analog1*2000.0-5.0;    //  volts to micro curies per meter^3
  vacuum = pow(10,(analog2-5.5)/0.5)*1000000;  //  volts to Torr - log scale
  subPump = analog3*5;  //  volts to amps


  // If the state didn't change, exit the function
  if (newState == currentState) { return;}


  // If there's a new alarm or a higher priority alarm, execute the new functions
  if (newState > currentState) {

    if (currentState == startup) {
      normal_state();
    }

    switch (newState) {

      case trouble1:
        trouble1_state();
        break;

      case trouble2:
        trouble2_state();
        break;
          
      case trouble3:
        trouble3_state();
        break;
    }
      
  } else if (newState == normal) {
      normal_state();
  }

  // Set the current state to the new state
  currentState = newState;

}


/********************
* Function to update interfaces- LEDs, LCD, log server, email notifications
*
********************/


void app_Interfaces(void) {


  //if state == not-normal, check last update time, if >5min, send update

  //send buffer to logs

  //notifications (email?)

  // LCD update, print, clear, etc
  if (lcdLooper > 15 || lcdLooper < 0){
    lcdLooper = 0;
  } else if (input[lcdLooper] == input_normal[lcdLooper]){
    lcdLooper++;
  } else if (input[lcdLooper] != input_normal[lcdLooper]) {
    lcdLine2 = lcdLooper;
  }

  if (currentState == normal) {
    lcdLine2 = 16;
  }

  if (millis()-lcdTimer >= 2000) {

    lcdLooper++;
    
    lcdTimer = millis();
    
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print(state_txt[currentState]);
    lcd.setCursor(0, 1);
    lcd.print(in_txt[lcdLine2]);
   
  } else if (lcdTimer < 0) {
    lcdTimer = millis();
  }

  if (millis()-lcdReset >= 20000) {
    lcdReset = millis();
    lcd.begin(16, 2);
    lcd.clear();
  }
  
  
  // Webpage function
  serve_webpage();

  // Diagnostics -> Serial Output
  if (digitalRead(SWITCH_BUILTIN) == 0){
    if ((millis()-printerPace)>3000) {
      print_states();
      printerPace = millis();    
    }
  }
  
  // Heartbeat
  if ((millis()-heartBeat)>1200) {
    for (int i=0; i<4; i++){
      digitalWrite(heartbeat, !digitalRead(heartbeat));
      delay(100);
    }
    heartBeat = millis();    
  }

}
