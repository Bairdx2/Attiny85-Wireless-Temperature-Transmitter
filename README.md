# Attiny85-Wireless-Temperature-Transmitter
Simple project: Attiny85 measures temperature using a thermistor and transmits the temperature to a receiver using a relatively cheap wireless transmitter. The thermistor is essentially a resistor but what makes it special is that its resistance value is really sensitive to temperature fluxuations and is able to operate precisely within the [range](https://en.wikipedia.org/wiki/Thermistor) -90C to 130C. NTC which stands for negative temperature coefficient and this just means that as the thermistor is heated, its resistance will decrease.


## Items needed:
1. [Attiny85](https://www.digikey.com/product-detail/en/microchip-technology/ATTINY85-20PU/ATTINY85-20PU-ND/735469)
2. [Wireless Transmitter](https://www.sparkfun.com/products/10534)
3. [Wireless Receiver](https://www.sparkfun.com/products/10532)
4. [Thermistor](https://www.amazon.com/dp/B0166I8IU8/ref=sxbs_sxwds-stppvp_1?pf_rd_m=ATVPDKIKX0DER&pf_rd_p=d45777d6-4c64-4117-8332-1659db52e64f&pd_rd_wg=ADRbg&pf_rd_r=A8ASCX6BYD7PA4J48Q08&pf_rd_s=desktop-sx-bottom-slot&pf_rd_t=301&pd_rd_i=B0166I8IU8&pd_rd_w=nMwGH&pf_rd_i=thermistor&pd_rd_r=f46062b6-13f6-497d-a697-d06e222f8b9a&ie=UTF8&qid=1534946766&sr=1)
5. [Attiny programmer](https://www.sparkfun.com/products/11801) (unless you are able to program with your arduino using this [tutorial](http://highlowtech.org/?p=1229))


## Schematic diagrams:
### TX and RX circuits -
![alt text](https://i.imgur.com/E5YgfeX.png)
![alt text](https://cdn.sparkfun.com/assets/f/8/f/d/9/52713d5b757b7fc0658b4567.png)

## Things to keep in mind:
1. Make sure that the Attiny's bootloader is burned and the **internal** clock is set to 8Mhz. This is necessary in order to be able to upload code to the attiny using either the attiny programmer or an arduino as ISP. More info [here](http://highlowtech.org/?p=1695).
2. Manufacturing variations exist from thermistor to thermistor so while the steinhart-hart equation coefficients generated for this project
   will most likely produce decent results for you, a more rigorous [approach](   https://www.thinksrs.com/downloads/pdfs/applicationnotes/LDC%20Note%204%20NTC%20Calculator.pdf) should be used to gain coefficients that
   are much more suited for your specific thermistor.
3. The wireless TX/RX modules used in this project are suceptible to noise and the transmitter can only work up to ~3m with a direct line    of sight
4. R2 used was ~1000Ω but you are allowed to use any value resistor as long as you adjust the R2 value in Attiny85_wireless_thermistor.ino
