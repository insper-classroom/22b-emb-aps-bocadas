#include <asf.h>

#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"



//define notas
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

//definindo constantes e varivaveis globais
// change this to make the song slower or faster
volatile char start_flag = 0;
volatile char selecao_flag = 0;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!




// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!

int happy[] = {

	// Happy Birthday
	// Score available at https://musescore.com/user/8221/scores/26906

	NOTE_C4,4, NOTE_C4,8,
	NOTE_D4,-4, NOTE_C4,-4, NOTE_F4,-4,
	NOTE_E4,-2, NOTE_C4,4, NOTE_C4,8,
	NOTE_D4,-4, NOTE_C4,-4, NOTE_G4,-4,
	NOTE_F4,-2, NOTE_C4,4, NOTE_C4,8,

	NOTE_C5,-4, NOTE_A4,-4, NOTE_F4,-4,
	NOTE_E4,-4, NOTE_D4,-4, NOTE_AS4,4, NOTE_AS4,8,
	NOTE_A4,-4, NOTE_F4,-4, NOTE_G4,-4,
	NOTE_F4,-2,
	
};

int merry[] = {

	// We Wish You a Merry Christmas
	// Score available at https://musescore.com/user/6208766/scores/1497501
	
	NOTE_C5,4, //1
	NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
	NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
	NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
	NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
	NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
	NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
	NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,

	NOTE_F5,2, NOTE_C5,4, //8
	NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
	NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
	NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
	NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
	NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
	NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
	NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
	NOTE_F5,2, NOTE_C5,4,

	NOTE_F5,4, NOTE_F5,4, NOTE_F5,4,//17
	NOTE_E5,2, NOTE_E5,4,
	NOTE_F5,4, NOTE_E5,4, NOTE_D5,4,
	NOTE_C5,2, NOTE_A5,4,
	NOTE_AS5,4, NOTE_A5,4, NOTE_G5,4,
	NOTE_C6,4, NOTE_C5,4, NOTE_C5,8, NOTE_C5,8,
	NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
	NOTE_F5,2, NOTE_C5,4,
	NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
	NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
	
	NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, //27
	NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
	NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
	NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
	NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
	NOTE_F5,2, NOTE_C5,4,
	NOTE_F5,4, NOTE_F5,4, NOTE_F5,4,
	NOTE_E5,2, NOTE_E5,4,
	NOTE_F5,4, NOTE_E5,4, NOTE_D5,4,
	
	NOTE_C5,2, NOTE_A5,4,//36
	NOTE_AS5,4, NOTE_A5,4, NOTE_G5,4,
	NOTE_C6,4, NOTE_C5,4, NOTE_C5,8, NOTE_C5,8,
	NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
	NOTE_F5,2, NOTE_C5,4,
	NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
	NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
	NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
	NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
	
	NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,//45
	NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
	NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
	NOTE_F5,2, NOTE_C5,4,
	NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
	NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
	NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
	NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
	
	NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, //53
	NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
	NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
	NOTE_F5,2, REST,4
};
// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes


//buzzer
#define BUZZER_PIO			  PIOA
#define BUZZER_PIO_ID         ID_PIOA
#define BUZZER_PIO_IDX        24
#define BUZZER_PIO_IDX_MASK   (1<< BUZZER_PIO_IDX)

//botao start
#define START_PIO             PIOC
#define START_PIO_ID          ID_PIOC
#define START_PIO_IDX         31
#define START_PIO_IDX_MASK   (1u << START_PIO_IDX )

////botao selecao
#define SELECAO_PIO            PIOD
#define SELECAO_PIO_ID       ID_PIOD
#define SELECAO_PIO_IDX   			28
#define SELECAO_PIO_IDX_MASK (1u << SELECAO_PIO_IDX)

// LED
#define LED_PIO      PIOC
#define LED_PIO_ID   ID_PIOC
#define LED_IDX      8
#define LED_IDX_MASK (1 << LED_IDX)

int freq;
int t;
int thisNote = 0;

void set_buzzer(){
	pio_set(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
}
void clear_buzzer(){
	pio_clear(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
}

int get_startstop(){
	if(!pio_get(START_PIO,PIO_INPUT,START_PIO_IDX_MASK)){
		return 1;
	}
	return 0;
}

int get_selecao(){
	if(!pio_get(SELECAO_PIO,PIO_INPUT,SELECAO_PIO_IDX_MASK)){
		return 1;
	}
	return 0;
}

void buzzer_test(int freq){
	double t_ms=(1E6)/(double) freq;
	set_buzzer();
	delay_us(t_ms/2);
	clear_buzzer();
	delay_us(t_ms/2);
}

void tone(int freq, int t){
	double t_1=(double) t/(1E3);
	int pulse_number=t_1* ((double) freq);
	for(int i=0;i<pulse_number;i++){
		buzzer_test(freq);
	}
	
}


void start_callback(void);
void selecao_callback(void);

void start_callback(void)
{
	if (start_flag){
		start_flag = 0;
	}
	else{
		start_flag = 1;
	}
}

void selecao_callback(void){
	thisNote=0;
	if (selecao_flag){
		selecao_flag = 0;
	}
	else{
		selecao_flag = 1;
	}
}

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / 140;

int divider = 0, noteDuration = 0;


void init(void){

	// Inicializa clock
	sysclk_init();

	// Desativa watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	// Ativa PIOs
	pmc_enable_periph_clk(START_PIO_ID);
	pmc_enable_periph_clk(SELECAO_PIO_ID);
	
	// Configura led
	pmc_enable_periph_clk(LED_PIO_ID);
	pio_configure(LED_PIO, PIO_OUTPUT_0, LED_IDX_MASK, PIO_DEFAULT);
	
	// Configura o buzzer
	pmc_enable_periph_clk(BUZZER_PIO_ID);
	pio_configure(BUZZER_PIO, PIO_OUTPUT_0, BUZZER_PIO_IDX_MASK, PIO_DEFAULT);

	
	// PIO lida com pino do botão como entrada com pull-up e debounce
	pio_configure(START_PIO, PIO_INPUT, START_PIO_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	pio_configure(SELECAO_PIO, PIO_INPUT, SELECAO_PIO_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	pio_set_debounce_filter(SELECAO_PIO, SELECAO_PIO_IDX_MASK, 60);
	pio_set_debounce_filter(START_PIO, START_PIO_IDX_MASK, 60);
	
	
	pio_handler_set(
	START_PIO,
	START_PIO_ID,
	START_PIO_IDX_MASK,
	PIO_IT_FALL_EDGE,
	start_callback
	);
	
	pio_handler_set(
	SELECAO_PIO,
	SELECAO_PIO_ID,
	SELECAO_PIO_IDX_MASK,
	PIO_IT_FALL_EDGE,
	selecao_callback
	);
	
	// Ativa a interrupção e limpa a primeira IRQ gerada na ativação
	pio_enable_interrupt(START_PIO, START_PIO_IDX_MASK);
	pio_enable_interrupt(SELECAO_PIO, SELECAO_PIO_IDX_MASK);
	pio_get_interrupt_status(START_PIO);
	pio_get_interrupt_status(SELECAO_PIO);
	
	// Configura NVIC para receber interrupções do PIO do botão com prioridade 4
	NVIC_EnableIRQ(START_PIO_ID);
	NVIC_EnableIRQ(SELECAO_PIO_ID);
	NVIC_SetPriority(START_PIO_ID, 4);
	NVIC_SetPriority(SELECAO_PIO_ID, 4);

	
}

void run(int melody[], int notes){
	// there are two values per note (pitch and duration), so for each note there are four bytes
	// iterate over the notes of the melody.
	// Remember, the array is twice the number of notes (notes + durations)
	for (thisNote; thisNote < notes * 2; thisNote = thisNote + 2) {
		if (start_flag == 0){
			break;
		}
		// calculates the duration of each note
		divider = melody[thisNote + 1];
		if (divider > 0) {
			// regular note, just proceed
			noteDuration = (wholenote) / divider;
			} else if (divider < 0) {
			// dotted notes are represented with negative durations!!
			noteDuration = (wholenote) / abs(divider);
			noteDuration *= 1.5; // increases the duration in half for dotted notes
		}

		// we only play the note for 90% of the duration, leaving 10% as a pause
		tone(melody[thisNote], noteDuration * 0.9);

		// Wait for the specief duration before playing the next note.
		delay_ms(noteDuration);
	}
}


int main (void)
{
	board_init();
	sysclk_init();
	delay_init();
	init();
	
	// Init OLED
	gfx_mono_ssd1306_init();
	
	// Escreve na tela um circulo e um texto
	gfx_mono_draw_string("lister", 50,16, &sysfont);
	// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
	int notes_h = sizeof(happy) / sizeof(happy[0]) / 2;
	int notes_l = sizeof(merry) / sizeof(merry[0]) / 2;
	
	
	while(1) {
		if(!selecao_flag){
			gfx_mono_draw_string("     ", 50,16, &sysfont);
			gfx_mono_draw_string("Happy", 50,16, &sysfont);
			}
		 else{
			gfx_mono_draw_string("      ", 50,16, &sysfont);
			gfx_mono_draw_string("Merry", 50,16, &sysfont);
			}
		if (start_flag){
			if(!selecao_flag){
				run(happy, notes_h);
				start_flag = 0;
			}else{
				run(merry,notes_h);
				start_flag=0;
			}
			
			
		}
		
	}
}