/************************
 * 
 * This file contains the html code for the webpage served by the ethernet module.
 * The webpage shows the state and conditions of the inputs as well as the analog values.
 * 
*************************/


/********************
* Function to serve the webpage showing the interlock system status
* 
*********************/
void serve_webpage(void) {

  String condition_txt;

  switch (currentState) {
    case 0:
      condition_txt = "Rebooting...";
      break;
    case 1:
      condition_txt = "normal";
      break;
    case 2:
      condition_txt = "Cage Door Trip";
      break;
    case 3:
      condition_txt = "Vacuum Trip";
      break;
    case 4:
      condition_txt = "Source Trip";
      break;
  }


  EthernetClient client = server.available();

  if (client) {
  //Serial.println("new client");
  // an http request ends with a blank line
  boolean currentLineIsBlank = true;
  while (client.connected()) {
      if (client.available()) {
      char c = client.read();
      //Serial.write(c);
      // if you've gotten to the end of the line (received a newline
      // character) and the line is blank, the http request has ended,
      // so you can send a reply
      if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE html>");
          client.println("<html>");
          client.println("<head>");
          client.println("    <title>Multi-SNICS Interlock Status Display</title>");
          client.println("    <style>");
          client.println("        body {");
          client.println("            font-family: Arial, sans-serif;");
          client.println("            margin: 20px;");
          client.println("            background-image: url('https://public.magnet.fsu.edu/Logos/FSU_Seal_RGB.png');");
          client.println("            background-size: 450px;");
          client.println("            background-repeat: repeat-x;");
          client.println("            background-position: center center;");
          client.println("            text-align: center;");
          client.println("            font-weight: bold;");
          client.println("        }");
          client.println("        table {");
          client.println("            border-collapse: collapse;");
          client.println("            width: 100%;");
          if (currentState>1){
            client.println("            background-color: #ffdddd;");
          } else {
            client.println("            background-color: #ddffdd;");
          } 
          client.println("            opacity: 95%;");
          client.println("        }");
          client.println("        th, td {");
          client.println("            border: 1px solid #dddddd;");
          client.println("            padding: 8px;");
          client.println("        }");
          client.println("        th {");
          client.println("            background-color: #f2f2f2;");
          client.println("        }");
          client.println("    </style>");
          client.println("</head>");
          client.println("<body>");
          client.println("    <h1>Multi-SNICS Interlock Status Display</h1>");
          client.print("    <h2>Condition: ");
          client.print(condition_txt);
          client.println("</h2>");
          client.println("    <table>");
          client.println("        <tr>");
          client.println("            <th>Input Conditions</th>");
          client.println("            <th></th>");
          client.println("            <th>Output Relays</th>");
          client.println("            <th></th>");
          client.println("            <th>Measurements</th>");
          client.println("        </tr>");
          client.println("        <tr>");
          client.println("            <td class='input-condition'>Reset Switch: </td>");
          client.print("            <td class='input-condition'>");
          client.print((input[0]==input_normal[0]) ? "normal" : "TRIPPED");
          client.println("</td>");
          client.println("            <td class='output-relay'>Switch LED: </td>");
          client.print("            <td class='output-relay'>");
          client.print((output[0]==0) ? "Off" : "Flashing Red");
          client.println("</td>");
          client.print("            <td class='measurement-number'>Tritium Detector: ");
          client.print(tSniffer, 1);
          client.println(" uCi/m^3</td>");
          client.println("        </tr>");
          client.println("        <tr>");
          client.println("            <td class='input-condition'>Emergency Interlock Switch: </td>");
          client.print("            <td class='input-condition'>");
          client.print((input[1]==input_normal[1]) ? "normal" : "TRIPPED");
          client.println("</td>");
          client.println("            <td class='output-relay'>Buzzer: </td>");
          client.print("            <td class='output-relay'>");
          client.print((output[1]==1) ? "Buzzing" : "Off");
          client.println("</td>");
          client.print("            <td class='measurement-number'>Vacuum Gauge: ");
          client.print(vacuum);
          client.println("E-6 Torr</td>");
          client.println("        </tr>");
          client.println("        <tr>");
          client.println("            <td class='input-condition'>Cage Door Contact: </td>");
          client.print("            <td class='input-condition'>");
          client.print((input[2]==input_normal[2]) ? "normal" : "TRIPPED");
          client.println("</td>");
          client.println("            <td class='output-relay'>Cage Door Trip LED: </td>");
          client.print("            <td class='output-relay'>");
          client.print((output[2]==0) ? "Green/Off" : "Red");
          client.println("</td>");
          client.print("            <td class='measurement-number'>Titanium Sublimation Pump: ");
          client.print(subPump, 1);
          client.println(" Amps</td>");
          client.println("        </tr>");
          client.println("        <tr>");
          client.println("            <td class='input-condition'>Fume Hood Flow Switch: </td>");
          client.print("            <td class='input-condition'>");
          client.print((input[3]==input_normal[3]) ? "normal" : "TRIPPED");
          client.println("</td>");
          client.println("            <td class='output-relay'>Vacuum Trip LED: </td>");
          client.print("            <td class='output-relay'>");
          client.print((output[3]==0) ? "Green/Off" : "Red");
          client.println("</td>");
          client.println("            <td class='measurement-number'></td>");
          client.println("        </tr>");
          client.println("        <tr>");
          client.println("            <td class='input-condition'>Vacuum Condition - Ground: </td>");
          client.print("            <td class='input-condition'>");
          client.print((input[4]==input_normal[4]) ? "normal" : "TRIPPED");
          client.println("</td>");
          client.println("            <td class='output-relay'>Source Trip LED: </td>");
          client.print("            <td class='output-relay'>");
          client.print((output[4]==0) ? "Green/Off" : "Red");
          client.println("</td>");
          client.println("            <td class='measurement-number'></td>");
          client.println("        </tr>");
          client.println("        <tr>");
          client.println("            <td class='input-condition'>Tritium Detector: </td>");
          client.print("            <td class='input-condition'>");
          client.print((input[5]==input_normal[5]) ? "normal" : "TRIPPED");
          client.println("</td>");
          client.println("            <td class='output-relay'>Pre-accelerator Power Supply: </td>");
          client.print("            <td class='output-relay'>");
          client.print((output[5]==1) ? "Unlocked" : "Locked Out");
          client.println("</td>");
          client.println("            <td class='measurement-number'></td>");
          client.println("        </tr>");
          client.println("        <tr>");
          client.println("            <td class='input-condition'>UNUSED</td>");
          client.print("            <td class='input-condition'>");
          client.print((input[6]==input_normal[6]) ? "normal" : "TRIPPED");
          client.println("</td>");
          client.println("            <td class='output-relay'>Gate Valve - Ground: </td>");
          client.print("            <td class='output-relay'>");
          client.print((output[6]==1) ? "Open" : "Closed");
          client.println("</td>");
          client.println("            <td class='measurement-number'></td>");
          client.println("        </tr>");
          client.println("        <tr>");
          client.println("            <td class='input-condition'>Building Power Failure: </td>");
          client.print("            <td class='input-condition'>");
          client.print((input[7]==input_normal[7]) ? "normal" : "TRIPPED");
          client.println("</td>");
          client.println("            <td class='output-relay'>Gate Valve - Mid Potential: </td>");
          client.print("            <td class='output-relay'>");
          client.print((output[7]==1) ? "Open" : "Closed");
          client.println("</td>");
          client.println("            <td class='measurement-number'></td>");
          client.println("        </tr>");
          client.println("        <tr>");
          client.println("            <td class='input-condition'>Coolant Flow At Pump: </td>");
          client.print("            <td class='input-condition'>");
          client.print((input[8]==input_normal[8]) ? "normal" : "TRIPPED");
          client.println("</td>");
          client.println("            <td class='output-relay'>UNUSED</td>");
          client.print("            <td class='output-relay'>");
          client.print((output[8]==0) ? "Open" : "Closed");
          client.println("</td>");
          client.println("            <td class='measurement-number'></td>");
          client.println("        </tr>");
          client.println("        <tr>");
          client.println("            <td class='input-condition'>Vacuum Condition - Mid Potential: </td>");
          client.print("            <td class='input-condition'>");
          client.print((input[9]==input_normal[9]) ? "normal" : "TRIPPED");
          client.println("</td>");
          client.println("            <td class='output-relay'>UNUSED</td>");
          client.print("            <td class='output-relay'>");
          client.print((output[9]==0) ? "Open" : "Closed");
          client.println("</td>");
          client.println("            <td class='measurement-number'></td>");
          client.println("        </tr>");
          client.println("        <tr>");
          client.println("            <td class='input-condition'>UNUSED</td>");
          client.print("            <td class='input-condition'>");
          client.print((input[10]==input_normal[10]) ? "normal" : "TRIPPED");
          client.println("</td>");
          client.println("            <td class='output-relay'>UNUSED</td>");
          client.print("            <td class='output-relay'>");
          client.print((output[10]==0) ? "Open" : "Closed");
          client.println("</td>");
          client.println("            <td class='measurement-number'></td>");
          client.println("        </tr>");
          client.println("        <tr>");
          client.println("            <td class='input-condition'>Coolant Flow At Source: </td>");
          client.print("            <td class='input-condition'>");
          client.print((input[11]==input_normal[11]) ? "normal" : "TRIPPED");
          client.println("</td>");
          client.println("            <td class='output-relay'>UNUSED</td>");
          client.print("            <td class='output-relay'>");
          client.print((output[11]==0) ? "Open" : "Closed");
          client.println("</td>");
          client.println("            <td class='measurement-number'></td>");
          client.println("        </tr>");
          client.println("        <tr>");
          client.println("            <td class='input-condition'>Smoke Detector At Source: </td>");
          client.print("            <td class='input-condition'>");
          client.print((input[12]==input_normal[12]) ? "normal" : "TRIPPED");
          client.println("</td>");
          client.println("            <td class='output-relay'>UNUSED</td>");
          client.print("            <td class='output-relay'>");
          client.print((output[12]==0) ? "Open" : "Closed");
          client.println("</td>");
          client.println("            <td class='measurement-number'></td>");
          client.println("        </tr>");
          client.println("        <tr>");
          client.println("            <td class='input-condition'>UNUSED</td>");
          client.print("            <td class='input-condition'>");
          client.print((input[13]==input_normal[13]) ? "normal" : "TRIPPED");
          client.println("</td>");
          client.println("            <td class='output-relay'>High-voltage Power Supplies: </td>");
          client.print("            <td class='output-relay'>");
          client.print((output[13]==1) ? "Unlocked" : "Locked Out");
          client.println("</td>");
          client.println("            <td class='measurement-number'></td>");
          client.println("        </tr>");
          client.println("        <tr>");
          client.println("            <td class='input-condition'>UNUSED</td>");
          client.print("            <td class='input-condition'>");
          client.print((input[14]==input_normal[14]) ? "normal" : "TRIPPED");
          client.println("</td>");
          client.println("            <td class='output-relay'>Boiler: </td>");
          client.print("            <td class='output-relay'>");
          client.print((output[14]==1) ? "Unlocked" : "Locked Out");
          client.println("</td>");
          client.println("            <td class='measurement-number'></td>");
          client.println("        </tr>");
          client.println("        <tr>");
          client.println("            <td class='input-condition'>UNUSED</td>");
          client.print("            <td class='input-condition'>");
          client.print((input[15]==input_normal[15]) ? "normal" : "TRIPPED");
          client.println("</td>");
          client.println("            <td class='output-relay'>Ionizer: </td>");
          client.print("            <td class='output-relay'>");
          client.print((output[15]==1) ? "Unlocked" : "Locked Out");
          client.println("</td>");
          client.println("            <td class='measurement-number'></td>");
          client.println("        </tr>");
          client.println("    </table>");
          client.println("    <br><footer>Written by yours truly, <a href='http://www.rubberhelix.com/'>Jonah K Gibbons</a></footer>");
          client.println("</body>");
          client.println("</html>");
          break;
      }
      if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
      } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
      }
      }
  }
  // give the web browser time to receive the data
  delay(1);
  // close the connection:
  client.stop();
  //Serial.println("client disconnected");
  }

}
