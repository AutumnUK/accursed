#include "../headers.h"
uint8_t background_offset_1;
uint8_t background_offset_2;
uint8_t background_offset_3;

uint8_t timer = 0;

// Does this set the heights?
void interruptLCD(void) {
    switch (LYC_REG) {
		case 0x00: move_bkg(background_offset_1,0); LYC_REG = 0x68; break;
		case 0x68: move_bkg(background_offset_2,0); LYC_REG = 0x70; break;
		case 0x70: move_bkg(background_offset_3,0); LYC_REG = 0x00; break;
    }
}

void stage_1_bkg_update(void) {
    vsync();
    timer++;
        if (timer == 2) {
            background_offset_1 += 1;
            background_offset_2 += 3;
            background_offset_3 += 5;
            timer = 0;
        }
}

void stage_1_bkg_init(void) {
    
    set_bkg_tiles(0,0,80,18,stage_1_map);      
    set_bkg_data(0,13,stage_1_tiles);            
    STAT_REG = 0x45;
    LYC_REG  = 0x00;
    disable_interrupts();
    add_LCD(interruptLCD);
    enable_interrupts();
    set_interrupts(VBL_IFLAG | LCD_IFLAG);
    SHOW_BKG;
}

void stage_1( void ) {
    stage_1_bkg_init();
    player_init();
    while (1) {
        stage_1_bkg_update();
        player_movement();
    }
}