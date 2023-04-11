#include <10F220.h>
#fuses NOMCLR, IOSC8
#use delay(clock = 8 Mhz)

int i =0;
void main()
{
   SETUP_TIMER_0(0); // timer 0 � �al��t�rmayaca��z.
   output_high(pin_b0); // k�rm�z� ledi yakt�k. header dosyas�ndan b0 � bulduk.
   output_low(pin_b1); // ye�il ledi s�nd�r
   output_low(pin_b2); // motoru durdur.
   while(TRUE)
   {
      if(input(pin_b3) == 0) // butona bas�ld� m�?
      {
         delay_ms(50); // buton ark�n�n s�nd�r�lmesi i�in kullan�l�r.
         while(input(pin_b3) == 0) // buton b�rak�lana kadar bekle 
         i++;
         if(i == 1)
            {
            output_high(pin_b2); // motoru �al��t�r.
            output_low(pin_b0); // k�rm�z� ledi s�nd�r
            output_high(pin_b1); // ye�il ledi yak
            i =255; //motoru bir sonraki d�ng�de durdurmak i�in yazd�k.
            }
         else 
            {
            output_low(pin_b2); // motoru durdur.         
            output_high(pin_b0); // k�rm�z� ledi yakt�k. header dosyas�ndan b0 � bulduk.
            output_low(pin_b1); // ye�il ledi s�nd�r
            }
         
         
      }
   }

}
