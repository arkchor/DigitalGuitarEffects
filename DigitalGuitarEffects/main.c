#include "stdio.h"
#include "usbstk5515.h"
#include "usbstk5515_led.h"
#include "aic3204.h"
#include "PLL.h"
#include "bargraph.h"
#include "oled.h"
#include "pushbuttons.h"
#include "stereo.h"
#include "sinewaves.h"
#include "echo.h"
#include "reverberation.h"
#include "tremolo.h"
#include "delay.h"
#include "distortion.h"
//#include "stdlib.h"
//#include "string"

					//zmienne probkowe
Int16 left_input;
Int16 right_input;
Int16 left_output;
Int16 right_output;
Int16 mono_input;
Int16 dis_left_input;
Int16 dis_right_input;

Int16 sinewave;

#define skok 0.1
float czestotliwosc = 0;
float iterator = skok;
int down_freq = 500;
int up_freq = 3000;
int rate = 2000;
int dep = 20;
int rate2 = 1000;
int dep2 = 20;
int rate3 = 2000;
int dep3 = 50;

//char *str;
//int sygnal;
			//lekcja 8 - funkcja - opis ocb z rzutowaniem
static int ring_modulation(int input1, int input2)
{
	signed long result;
	result = (((long) input1 * input2) >> 15);
	return ((int) result);
}
static float freq_sweep()
{
	if (czestotliwosc > up_freq && iterator == skok) 
	{
    	iterator = -skok;
    } 
    else if(czestotliwosc < down_freq && iterator == -skok)
	{
    	iterator = skok;
    }
    czestotliwosc += iterator;
    
    return czestotliwosc;
}

					//probkowanie i gain
#define SAMPLES_PER_SECOND	48000L
#define GAIN_IN_dB 0

unsigned int Step = 0; 
unsigned int LastStep = 99;

unsigned int key = 0;

					//indeks petli
unsigned long int i = 0;



//################################################################################
//					main
//################################################################################
void main(void)
{
	printf("\n Program zaczyna dzialanie \n");
	
	USBSTK5515_init( );
	pll_frequency_setup(60);
	aic3204_hardware_init();
	aic3204_init();
				//gasi diode
	asm(" bclr XF");
				//wylacza kolorowe diody
	USBSTK5515_ULED_init();
				//dodaje ekranik lcd
	oled_init();
	SAR_init();
	//Delay_Init(85.6,1,10,10);
	
	
				//ilosc znakow na lcd 18
	//oled_display_message("123456789012345678", "123456789012345678");
	oled_display_message("KONIEC             ", "KONIEC             ");
				//start kodekow
	
	
				//glowna petla
	printf("\n zaczynam petle \n");
	set_sampling_frequency_and_gain(SAMPLES_PER_SECOND, GAIN_IN_dB);
										//dziala przez *X sekund
	for (i=0; i < SAMPLES_PER_SECOND * 600; i++)
	{
				//button - ilosc roznych opcji w nawias!
		Step = pushbuttons_read(14);
				//wziecie wejsc ze zrodla
		aic3204_codec_read(&left_input, &right_input);
		
				//stereo na mono
		mono_input = stereo_to_mono(left_input, right_input);
		
/*				//przypisanie wyjsc - tutaj dzialamy
		left_output =  left_input;
		right_output = right_input;
*/
		if(Step == 1)
		{
			if(Step != LastStep)
			{
				oled_display_message("1 ========== CLEAN", "------------------");
				LastStep = Step;
			}
			left_output = left_input;
			right_output = right_input;
			
		}
		if(Step == 2)
		{
			if(Step != LastStep)
			{
				oled_display_message("2 =========== ECHO", "------------------");
				echo_array_clear();
				LastStep = Step;
			}
			left_output = variable_echo(left_input, 64000, 32767);
			right_output = variable_echo(right_input, 64000, 32767);
			
		}
		if(Step == 3)
		{
			if(Step != LastStep)
			{
				oled_display_message("3 ===== MULTI ECHO", "------------------");
				echo_array_clear();
				LastStep = Step;
			}
			left_output = echo(echo(echo(echo(echo(echo(left_input))))));
			right_output = echo(echo(echo(echo(echo(echo(right_input))))));
			
		}
		if(Step == 4)
		{
			if(Step != LastStep)
			{
				oled_display_message("4 ========= REVERB", "------------------");
				reverberation_array_clear();
				LastStep = Step;
			}
			left_output = reverberation(left_input);
			right_output = reverberation(right_input);
			/*left_output = distortion(left_input,200,20);
            right_output = distortion(right_input,200,20);*/
			//left_output = reverberation(left_output) + left_input;
			//right_output = reverberation(right_output) + right_input;
			/*dis_left_input = distortion(left_input,200,12);
            dis_right_input = distortion(right_input,200,12);
			left_output = reverberation(left_output) + dis_left_input;
			right_output = reverberation(right_output) + dis_right_input;*/	
		}
		if(Step == 5)
		{
			if(Step != LastStep)
			{
				oled_display_message("5 ====== TREMOLO 1", "RATE=2000 DEPTH=20");
				LastStep = Step;
				Tremolo_init2();
			}
			
            left_output = Tremolo_process2(0.1*left_input,rate,dep);
            right_output = Tremolo_process2(0.1*right_input,rate,dep);
            Tremolo_sweep2(rate);
                         
			//left_output = echo(echo(echo(echo(echo(echo(left_input))))));
			//right_output = echo(echo(echo(echo(echo(echo(right_input))))));
		}
		if(Step == 6)
		{
			if(Step != LastStep)
			{
				oled_display_message("6 ====== TREMOLO 2", "RATE=1000 DEPTH=20");
				LastStep = Step;
				Tremolo_init2();
			}
			
            left_output = Tremolo_process2(0.1*left_input,rate2,dep2);
            right_output = Tremolo_process2(0.1*right_input,rate2,dep2);
            Tremolo_sweep2(rate2);
                         
			//left_output = echo(echo(echo(echo(echo(echo(left_input))))));
			//right_output = echo(echo(echo(echo(echo(echo(right_input))))));
		}
		if(Step == 7)
		{
			if(Step != LastStep)
			{
				oled_display_message("7 ====== TREMOLO 3", "RATE=2000 DEPTH=50");//echo_array_clear();
				LastStep = Step;
				Tremolo_init2();
			}
			
            left_output = Tremolo_process2(0.1*left_input,rate3,dep3);
            right_output = Tremolo_process2(0.1*right_input,rate3,dep3);
            Tremolo_sweep2(rate3);
                         
			//left_output = echo(echo(echo(echo(echo(echo(left_input))))));
			//right_output = echo(echo(echo(echo(echo(echo(right_input))))));
		}
		if(Step == 8)
		{
			if(Step != LastStep)
			{
				oled_display_message("8 === DISTORTION 1", "CUT=500   GAIN=8 ");
				LastStep = Step;
			}
			
            left_output = distortion(left_input,500,8);
            right_output = distortion(right_input,500,8);
			
		}
		if(Step == 9)
		{
			if(Step != LastStep)
			{
				oled_display_message("9 === DISTORTION 2", "CUT=200   GAIN=12 ");
				LastStep = Step;
			}
			
            left_output = distortion(left_input,200,12);
            right_output = distortion(right_input,200,12);
            
		}
		if(Step == 10)
		{
			if(Step != LastStep)
			{
				oled_display_message("10 === DISTORTION 3", "CUT=100    GAIN=20 ");
				LastStep = Step;
			}
			
            left_output = distortion(left_input,100,20);
            right_output = distortion(right_input,100,20);
			
		}
		if(Step == 11)
		{
			if(Step != LastStep)
			{
				oled_display_message("11 ======= RINGMOD", "------------------");
				LastStep = Step;
			}
			
						//alien voice
			sinewave = generate_sinewave_1 (freq_sweep(), 32767);
			left_output = ring_modulation (sinewave, left_input);
			right_output = ring_modulation (sinewave, right_input);
					
		}
		if(Step == 12)
		{
			if(Step != LastStep)
			{
				oled_display_message("12 == TREMOLO+ECHO", "------------------");
				echo_array_clear();
				LastStep = Step;
				Tremolo_init2();
			}
			//left_output = echo(echo(echo(echo(echo(echo(left_input))))));
			//right_output = echo(echo(echo(echo(echo(echo(right_input))))));
			//left_output = echo(echo(echo(echo(echo(echo(Tremolo_process2(0.1*left_input,rate,dep)))))));
			//right_output = echo(echo(echo(echo(echo(echo(Tremolo_process2(0.1*right_input,rate,dep)))))));
			//left_output = variable_echo(left_input, 64000, 32767);
			//right_output = variable_echo(right_input, 64000, 32767);
			//left_output = Tremolo_process2(0.1*left_input,rate,dep);
            //right_output = Tremolo_process2(0.1*right_input,rate,dep);
            //left_output = Tremolo_process2(0.1*variable_echo(left_input, 10000, 20000),rate,dep);
            //right_output = Tremolo_process2(0.1*variable_echo(right_input, 20000, 20000),rate,dep);
            //left_output = Tremolo_process2(0.1*echo(echo(echo(echo(echo(echo(left_input)))))),rate,dep);
            //right_output = Tremolo_process2(0.1*echo(echo(echo(echo(echo(echo(right_input)))))),rate,dep);
            left_output = Tremolo_process2(0.1*variable_echo(variable_echo(left_input, 20000, 20000), 20000, 20000),rate,dep);
            right_output = Tremolo_process2(0.1*variable_echo(variable_echo(right_input, 20000, 20000), 20000, 20000),rate,dep);
            Tremolo_sweep2(rate);
		}
		if(Step == 13)
		{
			if(Step != LastStep)
			{
				oled_display_message("13 === REVERB+DIST", "------------------");
				reverberation_array_clear();
				LastStep = Step;
			}
			//sygnal = left_input;
			//sprintf(str, "%d", sygnal);
			/*string tmp; // brzydkie rozwi¹zanie
			itoa(sygnal, (char*)tmp.c_str(), 18);
			string str = tmp.c_str();*/
			//oled_display_message("to jest step 7-cos", str);
			//printf("%d",sygnal);
            //left_output = left_input;
            //right_output = right_input;
            dis_left_input = distortion(left_input,500,8);
            dis_right_input = distortion(right_input,500,8);
			left_output = reverberation(dis_left_input);// + dis_left_input;
			right_output = reverberation(dis_right_input);// + dis_right_input;
		}
		if(Step == 14)
		{
			if(Step != LastStep)
			{
				oled_display_message("14 = TREM+REV+DIST", "------------------");
				reverberation_array_clear();
				LastStep = Step;
				Tremolo_init2();
			}
			//sygnal = left_input;
			//sprintf(str, "%d", sygnal);
			/*string tmp; // brzydkie rozwi¹zanie
			itoa(sygnal, (char*)tmp.c_str(), 18);
			string str = tmp.c_str();*/
			//oled_display_message("to jest step 7-cos", str);
			//printf("%d",sygnal);
            //left_output = left_input;
            //right_output = right_input;
            /*dis_left_input = distortion(left_input,500,8);
            dis_right_input = distortion(right_input,500,8);
			left_output = reverberation(left_output) + dis_left_input;
			right_output = reverberation(right_output) + dis_right_input;
			
            left_output = Tremolo_process2(0.1*left_output,rate,dep);
            right_output = Tremolo_process2(0.1*right_output,rate,dep);
            Tremolo_sweep2(rate);*/
            dis_left_input = Tremolo_process2(0.1*distortion(left_input,200,12),rate,dep);
            dis_right_input = Tremolo_process2(0.1*distortion(right_input,200,12),rate,dep);
			left_output = reverberation(dis_left_input);// + dis_left_input;
			right_output = reverberation(dis_right_input);// + dis_right_input;
            Tremolo_sweep2(rate);
		}

		
				//wyrzucenie wyjsc na glosnik
		aic3204_codec_write(left_output, right_output);
		
				//diody migajo? - jest ok, jak sie da glosniej. sa rozne progi - ogar i nie spal czegos!
		bargraph_12dB(left_output, right_output);
		
	}
	printf("zakonczylem petle \n");
	
				//koniec kodekow
	aic3204_disable();
	printf("Program zakonczyl dzialanie \n");
	oled_display_message("123456789012345678", "123456789012345678");
	SW_BREAKPOINT;
}
//################################################################################


