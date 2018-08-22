/*
* Script: Attiny85_wireless_thermistor.ino
* Description: An attiny85 is connected with an NTC thermistor to
*              measure temperature and a 434MHz wireless transmitter
*              to send the data where it will be logged or displayed.
*
*
* Author: Kevin Rivera
* Creation date: 08/22/2018 v1.0
*/

// Circuit diagram:
// Thermistor = 
// 
//    5V-----thermistor-----R2-----Gnd
//                       ^              
//                       A1
// 
// 434MHz wireless transmitter = 
//     
//               [  ]
//               ||||
//    5V-----------^
//    Gnd--------^
//    pin12-------^
//    Optional antenna could be added to the last pin
//
//
//                     ATtiny85
//                      _____
//              RESET -|o    |- 5V
//                    -|     |- Transmitter pin
//                    -|     |- A1
//                GND -|_____|-



#include <Math.h>
#include <VirtualWire.h>

//////////////////////////////////////Variables//////////////////////////////////////////

const int aPin1 = 1;                          // Analog Pin 1 will read voltage data of the thermistor.
float thermRes;                            // Thermistor resistance.
int data1;                                 // Data relayed from ADC pin A0 will be mapped here.
const float R2 = 997;                      // R2 resistance.
float T;                                   // Temperature reported by the thermistor.
char TM[10];                               // Thermistor data will be stored here.

//////////////////////////////////////Functions//////////////////////////////////////////

void setup(){
  
  vw_set_tx_pin(1);                        // Transmit pin set to 1. Default is 12.
  vw_setup(2000);                          // Wireless communication bits per second.

} 

void loop(){

  data1 = analogRead(aPin1);                  // Analog data from A1 is read.
  thermRes=R2*((1023.0 / data1) - 1.0);    // Thermistor resistance measured.
  dtostrf(thermT(thermRes), 6, 2, TM);     // Conversion of the thermistor float data to a char string.
  
  send(TM);                                // Wireless transmission of the thermistor data array.
  
  memset(TM, 0, sizeof(TM));               // Clearing the contents of the thermistor data array.
  delay(1000);                             // A second is waited before the loop is executed again.
}

// Method which takes in a char * and transmits the contents it points to.
void send(char *Tdata){
  
  vw_send((uint8_t *)Tdata, strlen(Tdata));// Function from virtual wire library that transmits a message.
  vw_wait_tx();                            // Waits until the whole message is sent.

}

// Method that can convert the thermistor resistance to temperature directly.
float thermT(float a){
  T = 1.0 / (0.001129148 + (0.000234125 * log(a)) + (0.0000000876741 * log(a) * log(a) * log(a)));
  T = T - 273.15;                          // Conversion from Kelvin to Celsius.
  return T;
}
