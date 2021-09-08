// WiFiNINA - Version: Latest 
#include <WiFiNINA.h>
#include <ArduinoHttpClient.h>
char ssid[] = "ATR_Telepresence";
char pass[] = "discovery";
char server_address [] = "redwanulhsourav.pythonanywhere.com";
int status = WL_IDLE_STATUS;
int ledState = LOW;

unsigned long previousMillisInfo = 0;
unsigned long previousMillisLed = 0;

const int intervalInfo = 5000;
WiFiClient wifi;
HttpClient client = HttpClient(wifi,server_address, 80);

void setup() {
  Serial.begin(9600);
  while(!Serial);
    
  pinMode(LED_BUILTIN, OUTPUT);
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to network: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.println("You're connected to the network");
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
  Serial.println("---------------------------------------");
  Serial.println("Making get request");
 client.get("/get_status");

  int status_code = client.responseStatusCode();
  String response = client.responseBody();

  Serial.print("Status code: ");
  Serial.println(status_code);
  Serial.print("Response: ");
  Serial.println(response);
  delay(5000);
  

  
  
}

void loop() {
  Serial.println("Making get request");
 client.get("/get_status");

  int status_code = client.responseStatusCode();
  String response = client.responseBody();

  Serial.print("Status code: ");
  Serial.println(status_code);
  Serial.print("Response: ");
  Serial.println(response);
  delay(5000);
    /*
    //Bridge.begin();
    HttpClient client;

    client.get("https://redwanulhsourav.pythonanywhere.com/get_status");
    
    if (client.available()) {

    char c = client.read();

    if(c == '1'){
      digitalWrite(RED, HIGH);
      digitalWrite(LED_PWR,HIGH);
    }
    Serial.print(c);

  }
  */


}
