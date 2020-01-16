// Load Wi-Fi library
#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include "LedControl.h" 
#include <time.h>

#include <Foo.h> // My Wifi credentials

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

uint addr = 0;

// fake data
struct {
  uint val = 0;
  char str[20] = "";
} data;

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn
 pin 11 is connected to the CLK
 pin 10 is connected to LOAD / SC
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(14,12,13,4);

/* we always wait a bit between updates of the display */
unsigned long delaytime=1000;

void setup() {
  Serial.begin(115200);

  // commit 512 bytes of ESP8266 flash (for "EEPROM" emulation)
  // this step actually loads the content (512 bytes) of flash into
  // a 512-byte-array cache in RAM
  EEPROM.begin(512);

  // read bytes (i.e. sizeof(data) from "EEPROM"),
  // in reality, reads from byte-array cache
  // cast bytes into structure called data
  EEPROM.get(addr,data);
  Serial.println("Old values are: "+String(data.val)+","+String(data.str));

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();

  Serial.print("Timezone is: ");
  Serial.print(data.val);
  configTime(data.val * 3600, 0, "pool.ntp.org", "time.nist.gov");
  Serial.println("\nWaiting for time");
  while (!time(nullptr)) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("");

  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  Serial.print("Devices: ");
  Serial.println(lc.getDeviceCount());

  lc.shutdown(0,false);
  lc.shutdown(1,false);
  lc.shutdown(2,false);
  lc.shutdown(3,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,1);
  lc.setIntensity(1,1);
  lc.setIntensity(2,1);
  lc.setIntensity(3,1);
  /* and clear the display */
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  lc.clearDisplay(2);
  lc.clearDisplay(3);
}

/*
 * n is unit index
 */
void make_one(int n) {
  lc.setRow(n,0,B00001000);
  lc.setRow(n,1,B00011000);
  lc.setRow(n,2,B00101000);
  lc.setRow(n,3,B00001000);
  lc.setRow(n,4,B00001000);
  lc.setRow(n,5,B00001000);
  lc.setRow(n,6,B00001000);
  lc.setRow(n,7,B00001000);
}

/*
 * n is unit index
 */
void make_two(int n) {
  lc.setRow(n,0,B00111110);
  lc.setRow(n,1,B00000010);
  lc.setRow(n,2,B00000010);
  lc.setRow(n,3,B00111110);
  lc.setRow(n,4,B00100000);
  lc.setRow(n,5,B00100000);
  lc.setRow(n,6,B00100000);
  lc.setRow(n,7,B00111110);
}

/*
 * n is unit index
 */
void make_three(int n) {
  lc.setRow(n,0,B00111110);
  lc.setRow(n,1,B00000010);
  lc.setRow(n,2,B00000010);
  lc.setRow(n,3,B00111110);
  lc.setRow(n,4,B00000010);
  lc.setRow(n,5,B00000010);
  lc.setRow(n,6,B00000010);
  lc.setRow(n,7,B00111110);
}

/*
 * n is unit index
 */
void make_four(int n) {
  lc.setRow(n,0,B00000100);
  lc.setRow(n,1,B00001100);
  lc.setRow(n,2,B00010100);
  lc.setRow(n,3,B00100100);
  lc.setRow(n,4,B01111110);
  lc.setRow(n,5,B00000100);
  lc.setRow(n,6,B00000100);
  lc.setRow(n,7,B00000100);
}

/*
 * n is unit index
 */
void make_five(int n) {
  lc.setRow(n,0,B00111110);
  lc.setRow(n,1,B00100000);
  lc.setRow(n,2,B00100000);
  lc.setRow(n,3,B00111110);
  lc.setRow(n,4,B00000010);
  lc.setRow(n,5,B00000010);
  lc.setRow(n,6,B00000010);
  lc.setRow(n,7,B00111110);
}

/*
 * n is unit index
 */
void make_six(int n) {
  lc.setRow(n,0,B00001000);
  lc.setRow(n,1,B00010000);
  lc.setRow(n,2,B00100000);
  lc.setRow(n,3,B00100000);
  lc.setRow(n,4,B00111110);
  lc.setRow(n,5,B00100010);
  lc.setRow(n,6,B00100010);
  lc.setRow(n,7,B00111110);
}

/*
 * n is unit index
 */
void make_seven(int n) {
  lc.setRow(n,0,B00111110);
  lc.setRow(n,1,B00100010);
  lc.setRow(n,2,B00000010);
  lc.setRow(n,3,B00000010);
  lc.setRow(n,4,B00000100);
  lc.setRow(n,5,B00001000);
  lc.setRow(n,6,B00001000);
  lc.setRow(n,7,B00001000);
}

/*
 * n is unit index
 */
void make_eight(int n) {
  lc.setRow(n,0,B00111110);
  lc.setRow(n,1,B00100010);
  lc.setRow(n,2,B00100010);
  lc.setRow(n,3,B00111110);
  lc.setRow(n,4,B00100010);
  lc.setRow(n,5,B00100010);
  lc.setRow(n,6,B00100010);
  lc.setRow(n,7,B00111110);
}

/*
 * n is unit index
 */
void make_nine(int n) {
  lc.setRow(n,0,B00111110);
  lc.setRow(n,1,B00100010);
  lc.setRow(n,2,B00100010);
  lc.setRow(n,3,B00111110);
  lc.setRow(n,4,B00000010);
  lc.setRow(n,5,B00000010);
  lc.setRow(n,6,B00000100);
  lc.setRow(n,7,B00001000);
}

/*
 * n is unit index
 */
void make_zero(int n) {
  lc.setRow(n,0,B00111110);
  lc.setRow(n,1,B00100010);
  lc.setRow(n,2,B00100010);
  lc.setRow(n,3,B00100010);
  lc.setRow(n,4,B00100010);
  lc.setRow(n,5,B00100010);
  lc.setRow(n,6,B00100010);
  lc.setRow(n,7,B00111110);
}

/*
 * n is unit index
 */
void make_template(int n) {
  lc.setRow(n,0,B00000000);
  lc.setRow(n,1,B00000000);
  lc.setRow(n,2,B00000000);
  lc.setRow(n,3,B00000000);
  lc.setRow(n,4,B00000000);
  lc.setRow(n,5,B00000000);
  lc.setRow(n,6,B00000000);
  lc.setRow(n,7,B00000000);
}

void toNumber(int i, int n) {
  if (n == 0) make_zero(i);
  if (n == 1) make_one(i);
  if (n == 2) make_two(i);
  if (n == 3) make_three(i);
  if (n == 4) make_four(i);
  if (n == 5) make_five(i);
  if (n == 6) make_six(i);
  if (n == 7) make_seven(i);
  if (n == 8) make_eight(i);
  if (n == 9) make_nine(i);
}

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

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

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

  time_t now;
  struct tm * timeinfo;
  time(&now);
  timeinfo = localtime(&now);
  Serial.println(timeinfo->tm_hour);
  Serial.println(timeinfo->tm_min);
  hourMinute2led(timeinfo->tm_hour,timeinfo->tm_min);
  delay(delaytime);
}
