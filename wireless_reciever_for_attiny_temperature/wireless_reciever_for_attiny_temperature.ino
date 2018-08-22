/*
* Script: wireless_reciever_for_attiny_temperature.ino
* Description: An arduino uno is connected with a 434MHz wireless 
* receiver to collect data being sent from a 434MHz transmitter.
*              
*
*
* Author: Kevin Rivera
* Creation date: 08/22/2018 v1.0
*/

// Circuit diagram:
//  Receiver = 
//  
//              ____________
//             [   _____    ]
//              ||||    ||||
// Gnd----------^
// pin11---------^
// 5V--------------^
// 5V-------------------^
// Gnd-------------------^
// Gnd--------------------^
#include <VirtualWire.h>

//////////////////////////////////////Variables//////////////////////////////////////////

byte message[VW_MAX_MESSAGE_LEN];          // a buffer to hold the incoming messages.
byte msgLength = VW_MAX_MESSAGE_LEN;       // the size of the message.

//////////////////////////////////////Functions//////////////////////////////////////////

void setup()
{
  Serial.begin(9600);
  vw_setup(2000);                          // Wireless communication bits per second.
  vw_rx_start();                           // Starts the receiver.
}
void loop()
{
  if (vw_get_message(message, &msgLength))
  {
    Serial.print("Temperature is: ");
    for (int i = 0; i < msgLength; i++)
    {
      Serial.write(message[i]);
    }
    Serial.print(" degC");
    Serial.println();
  }
}
