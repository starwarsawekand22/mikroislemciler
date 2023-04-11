#include <16f877a.h>
#fuses xt, nowdt
#use delay(clock=4mhz)
unsigned int16 i;// zaman� bununla tan�ml�caz 16 bitlik tan�mlad�k saklay�c�y�.
//***************************************
void test();
{
   if(input(pin_a1)==0 || input(pin_a2)==0)
   {
      output_b(0b00001100);
      output_c(0b00001100);
      delay_ms(1000);
      output_b(0b10000011);
      output_c(0b10000011);
   }
}



void main()
{
   output_b(0); output_c(0);
   while(TRUE)
   {
      output_b(0b10000011);
      output_c(0b10000011); // binary formatta yazd�k bilerek 0 lar s�n�k 1 ler yan�k b part�na ba�l� olan ledler
      
      
      for(i=0; i<500; i++) //zaman� par�alad�k burda
      {
         test();
         delay_ms(10);
         if(i == 400)
         {
            output_b(0b10001111); //sar�lar� yakt�k 4. sn ye de
            output_c(0b10001111);
         }
      }
      // buraya kadar ilk 5 sn yi yazd�k yayalara ye�il arabalara k�rm�z� ile ba�lad�k 
      
      
      output_b(0b01110000); 
      output_c(0b01110000);
      for(i=0; i<500; i++) //zaman� par�alad�k burda
      {
         test();
         delay_ms(10);
         if(i == 400)
         {
            output_b(0b01111100); //sar�lar� yakt�k 4. sn ye de
            output_c(0b01111100);
         }
      }
      
      // burada da  bir periyot bitti.
      
      
      
      
      
   }

}
