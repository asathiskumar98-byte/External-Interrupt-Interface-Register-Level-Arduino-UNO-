void setup() 
{
  // put your setup code here, to run once:
  DDRB |= (1<<DDB5);  // PB5 = O/P

  // Enable the GIE (Global Interrupt Enable Bit)
  SREG |= (1<<7);  
  //sei();

  //Enable the Required External Interrupts from the Corresponding Registers
  EIMSK |= (1<<INT0) | (1<<INT1);

  // Set the Edge select for External Interrupts
  EICRA |= (1<<ISC10) | (1<<ISC11) | (1<<ISC00) | (1<<ISC01);
}

void loop() 
{
  // put your main code here, to run repeatedly:

}

// Implement the Interrupt Handler
ISR(INT0_vect)
{
  PORTB |= (1<<PB5);
}  

ISR(INT1_vect)
{
  PORTB &= ~(1<<PB5);
}  