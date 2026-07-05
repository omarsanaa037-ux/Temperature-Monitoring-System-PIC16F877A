# Temperature Monitoring System using PIC16F877A

This project is a Microcontroller assignment to design and simulate a Temperature Monitoring System. The system uses a PIC16F877A microcontroller to read analog temperature data from an LM35 sensor and display it on a 16x2 LCD screen.

## Project Requirements
1. Interface a 16x2 LCD display using 4-bit mode connection.
2. In the first part, the display was successfully tested on PORTB to show a welcome message and my student credentials.
3. In the second part, the connections were updated to PORTD, and the LM35 sensor was integrated into channel AN0 (PORTA) to update temperature readings dynamically.

## LCD Interfacing (4-Bit Mode)
Using 4-bit mode helps reduce the pins used on the microcontroller. Here is the connection mapping used in the simulation:

* VSS -> GND
* VCC -> +5V
* VEE -> Potentiometer (for contrast adjustment)
* RS -> RD4
* RW -> GND (Fixed to Write mode)
* EN -> RD5
* D4 to D7 -> RD0 to RD3

## How the Calculations Work
The LM35 sensor provides an analog output of 10mV for every 1 degree Celsius. The PIC microcontroller processes this through its internal 10-bit ADC. 

The formula used in the MikroC code to get the temperature in Celsius is:
`Temperature = (ADC_Reading * 1000) / 1024;`

The final integer is converted to text using the `IntToStr` function and displayed on the second line of the LCD screen every 500ms.

## Tools Used
* MikroC Pro for PIC (for writing and compiling the C code)
* PICSimLab (for hardware simulation and testing)

## Future Work / Improvements
* Adding a buzzer or LED indicator to trigger an alarm if the temperature goes over a specific limit.
* Saving the temperature logs inside an external EEPROM.
* Modifying the code to keep track of and display the Max/Min temperatures.
