// LCD module connections
sbit LCD_RS at RD4_bit;
sbit LCD_EN at RD5_bit;
sbit LCD_D4 at RD0_bit;
sbit LCD_D5 at RD1_bit;
sbit LCD_D6 at RD2_bit;
sbit LCD_D7 at RD3_bit;

sbit LCD_RS_Direction at TRISD4_bit;
sbit LCD_EN_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD0_bit;
sbit LCD_D5_Direction at TRISD1_bit;
sbit LCD_D6_Direction at TRISD2_bit;
sbit LCD_D7_Direction at TRISD3_bit;
// End LCD module connections

// Global Variables
int ADC_Reading, Temperature;
char Temp_text[16]; // Buffer to store string conversion

void main() {
    TRISD = 0x00;   // Configure PORTD as Output for LCD
    TRISA = 0x01;   // Configure RA0/AN0 as Input for the sensor
    ADCON1 = 0x80;  // Configure Analog pins and Right justified ADC result

    Lcd_Init();                  // Initialize LCD module
    ADC_Init();                  // Initialize internal ADC module
    Lcd_Cmd(_LCD_CLEAR);         // Clear any residual display data
    Lcd_Cmd(_LCD_CURSOR_OFF);    // Disable the cursor blinking

    // Display Welcome Message
    Lcd_Out(1, 1, "Welcome to Project");
    Delay_ms(2000);              // Wait for 2 seconds
    Lcd_Cmd(_LCD_CLEAR);

    // Display Student Credentials
    Lcd_Out(1, 1, "Sanaa Omar");
    Lcd_Out(2, 1, "30602062702189");
    Delay_ms(3000);              // Display credentials for 3 seconds
    Lcd_Cmd(_LCD_CLEAR);

    // Fixed Text Header
    Lcd_Out(1, 1, "Temperature =");

    // Main Infinite Loop
    while (1) {
        ADC_Reading = ADC_Read(0);        // Read analog voltage from Channel 0 (AN0)
        Delay_ms(20);                     // Short stability delay

        // Mathematical conversion to Celsius
        // (ADC_Reading * 5000mV) / 1024 / 10mV
        Temperature = (ADC_Reading * 1000) / 1024; 

        IntToStr(Temperature, Temp_text); // Convert integer value to string array
        
        // Print the cleaned string output on Row 2, Column 1
        Lcd_Out(2, 1, Ltrim(Temp_text));
        Lcd_Out_CP(" C");                 // Append Celsius symbol unit

        Delay_ms(500);                    // Refresh display every 500ms
    }
}
