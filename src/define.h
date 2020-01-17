#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 4
#define PAUSE_TIME 1000
#define SCROLL_SPEED 50
#define CLK_PIN 12
#define DATA_PIN 14
#define CS_PIN 13

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
LedControl lc=LedControl(DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

//MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);



/* we always wait a bit between updates of the display */
unsigned long delaytime=1000;