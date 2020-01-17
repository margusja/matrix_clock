void display2led(int a, int b, int c, int d) {
    toNumber(3, a);
    toNumber(2, b);
    toNumber(1, c);
    toNumber(0, d);
}

void hourMinute2led(int hour, int minute) {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    if (hour < 10) {
      a = 0;
      b = hour;
    }
    else {
       a = (hour / 10) % 10;
       b = (hour) % 10;
    }

    if (minute < 10) {
      c = 0;
      d = minute;
    }
    else {
       c = (minute / 10) % 10;
       d = (minute) % 10;
    }

    toNumber(3, a);
    toNumber(2, b);
    toNumber(1, c);
    toNumber(0, d);
}

WiFiClient client = server.available();   // Listen for incoming clients

void webPage() {
    if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // turns the GPIOs on and off
            if (header.indexOf("GET /timezone/2") >= 0) {
              Serial.println("GPIO 5 on");
              data.val = 2;
              EEPROM.put(addr,data);
              EEPROM.commit();
              configTime(data.val * 3600, 0, "pool.ntp.org", "time.nist.gov");

            } else if (header.indexOf("GET /timezone/3") >= 0) {
              Serial.println("GPIO 5 off");
              data.val = 3;
              EEPROM.put(addr,data);
              EEPROM.commit();
              configTime(data.val * 3600, 0, "pool.ntp.org", "time.nist.gov");
            }

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");

            // Web Page Heading
            client.println("<body><h1>Led Clock Web Server</h1>");

            // Display current state, and ON/OFF buttons for GPIO 5
            client.println("<p>Timezone " + String(data.val) + "</p>");
            // If the output5State is off, it displays the ON button
            if (data.val==3) {
              client.println("<p><a href=\"/timezone/2\"><button class=\"button\">Suvi</button></a></p>");
            } else {
              client.println("<p><a href=\"/timezone/3\"><button class=\"button button2\">Talv</button></a></p>");
            }

            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");

    EEPROM.get(addr,data);
    Serial.println("New values are: "+String(data.val)+","+String(data.str));
  }
}