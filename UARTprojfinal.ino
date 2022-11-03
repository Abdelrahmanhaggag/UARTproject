#include <avr/io.h> // Importing libraries
#include <util/delay.h> 
#include "adc.h" 

void init(); 

int main(void){        
  init();     //  Calling void init function
  
  while (1)  //   loop
  {
      int pushb = PIND & (1 << 7) ;   // Initializing push button to assigned pin

     if(pushb)       // Push button if statement
     {
       PORTB = PORTB & ~(1 << 2);
     }
     else
     {
       PORTB = PORTB | (1 << 2);
     }


    unsigned short a = Adc_ReadChannel(1);   // Potentiometer values in a

    if( a == 0)     // Potentiometer if statement
    {
      
      PORTB = PORTB & ~(1 << 0);    // LED OFF
      PORTB = PORTB & ~(1 << 1);    //LED OFF
    }
    else if (a < 200)  //
    {
      PORTB = PORTB | (1 << 1);    // LED ON
      PORTB = PORTB & ~(1 << 0);  // LED OFF
    }
    
    else
    {
       PORTB = PORTB | (1 << 0);    // LED OFF
      PORTB = PORTB & ~(1 << 1);   // LED ON
    }

  }
return 0;
}

void init(){
  DDRC = 0x00; 
  DDRB = DDRB | (1 << 0); 
  DDRB = DDRB | (1 << 1); 
  DDRB = DDRB | (1 << 2);  
  DDRD = DDRD & !(1 << 7); 
  PORTD = PORTD |(1 << 7);
  
  adc_Init(); //initialize ADC module with default settings
}