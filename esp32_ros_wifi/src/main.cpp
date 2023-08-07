/*
 *  Code initializes and connects to a WiFi network using given SSID and password, 
 *  then publishes a "Hello World!" message to a ROS topic "chatter" at regular intervals. 
 *  Make sure to update the SSID, password, IP and server details as per your network.
 * 
 *  Create by Stan Fu on 2023/08/07
 */
#include <arduino.h>
#include "WiFi.h"
#include <ros.h>
#include <std_msgs/String.h>

IPAddress ip(192, 168, 178, 47);
IPAddress server(192, 168, 178, 48);
uint16_t serverPort = 11411;
const char*  ssid = "FRITZ!Box 7530 JQ";
const char*  password = "27635171366830739521";

// Be polite and say hello
char hello[13] = "hello world!";
uint16_t period = 1000;
uint32_t last_time = 0;

ros::NodeHandle  nh;
// Make a chatter publisher
std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

void setupWiFi();

void setup(){
    Serial.begin(115200);
    setupWiFi();

    nh.getHardware()->setConnection(server, serverPort);
    nh.initNode();

    // Another way to get IP
    Serial.print("ROS IP = ");
    Serial.println(nh.getHardware()->getLocalIP());

    // Start to be polite
    nh.advertise(chatter);

}

void loop(){
  if(millis() - last_time >= period)
  {
    last_time = millis();
    if (nh.connected())
    {
      Serial.println("Connected");
      // Say hello
      str_msg.data = hello;
      chatter.publish( &str_msg );
    } else {
      Serial.println("Not Connected");
    }
  }
  nh.spinOnce();
  delay(1);
}


void setupWiFi()
{  
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) { delay(500);Serial.print("."); }
   Serial.print("SSID: ");
   Serial.println(WiFi.SSID());
   Serial.print("IP:   ");
   Serial.println(WiFi.localIP());
}
