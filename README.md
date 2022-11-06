# Attiny85-Wireless-Temperature-Transmitter
Simple project: Attiny85 measures temperature using an NTC thermistor and wirelessly transmits the temperature to a receiver. The thermistor is essentially a resistor but what makes it special is that its resistance value is really sensitive to temperature fluxuations and is able to operate precisely within the [range](https://en.wikipedia.org/wiki/Thermistor) -90C to 130C. NTC which stands for negative temperature coefficient and this just means that as the thermistor is heated, its resistance will decrease.


## Items needed:
1. [Attiny85](https://www.digikey.com/product-detail/en/microchip-technology/ATTINY85-20PU/ATTINY85-20PU-ND/735469)
2. [Wireless Transmitter](https://www.sparkfun.com/products/10534)
3. [Wireless Receiver](https://www.sparkfun.com/products/10532)
4. [Thermistor](https://www.amazon.com/dp/B0166I8IU8/ref=sxbs_sxwds-stppvp_1?pf_rd_m=ATVPDKIKX0DER&pf_rd_p=d45777d6-4c64-4117-8332-1659db52e64f&pd_rd_wg=ADRbg&pf_rd_r=A8ASCX6BYD7PA4J48Q08&pf_rd_s=desktop-sx-bottom-slot&pf_rd_t=301&pd_rd_i=B0166I8IU8&pd_rd_w=nMwGH&pf_rd_i=thermistor&pd_rd_r=f46062b6-13f6-497d-a697-d06e222f8b9a&ie=UTF8&qid=1534946766&sr=1)
5. [Attiny programmer](https://www.sparkfun.com/products/11801) (unless you are able to program with your arduino as ISP using this [tutorial](http://highlowtech.org/?p=1229))


## Schematic diagrams:
### TX and RX circuits -
![alt text](https://i.imgur.com/FVEJkpQ.png)

***Figure 1***: Receiver (left) and transmitter (right) circuits.

![alt text](https://i.imgur.com/Dk5PBPE.png)

***Figure 2***: Attiny85 pin layout.

![alt text](https://i.imgur.com/j8vSlox.png)

***Figure 3***: Sample data collected while exhaling on the thermistor. Y axis is temperature in celsius and x axis is # of data points.

## Things to keep in mind:
1. Make sure that the Attiny's bootloader is burned and the **internal** clock is set to 8Mhz. This is necessary in order to be able to    upload code to the attiny using either the attiny programmer or an arduino as ISP. More info [here](http://highlowtech.org/?p=1695).
2. Manufacturing variations exist from thermistor to thermistor so while the steinhart-hart equation coefficients generated for this project
   will most likely produce decent results for you, a more rigorous [approach](   https://www.thinksrs.com/downloads/pdfs/applicationnotes/LDC%20Note%204%20NTC%20Calculator.pdf) should be used to gain coefficients that
   are much more suited for your specific thermistor.
3. R2 used was ~1000Ω but you are allowed to use any value resistor as long as you adjust the R2 value in Attiny85_wireless_thermistor.ino
4. You'll need the  [VirtualWire](http://www.airspayce.com/mikem/arduino/VirtualWire/index.html) library in order to utilize this code. Source files are [here](https://github.com/sparkfun/RF_Links).
5. The wireless TX/RX modules used in this project are suceptible to noise and the transmitter can only work up to ~3m with a direct        line of sight. This code will work with other frequency transmitters/recivers/transceivers as long as they are compatible with the
   VirtualWire library.
6. The number of decimal places was set to 2 but the analog input pins are 10 bit so the accuracy of the temperature values can improved by adusting the number of decimal places set by the [dtostrf()](https://www.microchip.com/webdoc/AVRLibcReferenceManual/group__avr__stdlib_1ga060c998e77fb5fc0d3168b3ce8771d42.html) function in Attiny85_wireless_thermistor.ino
7. Attiny25/45/85 [datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-2586-AVR-8-bit-Microcontroller-ATtiny25-ATtiny45-ATtiny85_Datasheet-Summary.pdf)
