#include <gb/gb.h>
#include "tilesets/level1_tiles.c"               
#include "tilemaps/level1_map.c"

uint8_t timer,
        background_offset_1,
        background_offset_2,
        background_offset_3;

void interruptLCD(void) {
    switch (LYC_REG) {
		case 0x00: move_bkg(background_offset_1,0); LYC_REG = 0x68; break;
		case 0x68: move_bkg(background_offset_2,0); LYC_REG = 0x70; break;
		case 0x70: move_bkg(background_offset_3,0); LYC_REG = 0x00; break;
    }
}

void level1_bkg_init(void) {
    timer = 0;
    set_bkg_tiles(0,0,80,18,level1_map);       // Sets the map.
    set_bkg_data(0,13,level1_tiles);            // Sets the tileset.
    STAT_REG = 0x45;
    LYC_REG  = 0x00; // First line. ( 00 / 78 / 80 )
    disable_interrupts();
    add_LCD(interruptLCD);
    enable_interrupts();
    set_interrupts(VBL_IFLAG | LCD_IFLAG);
    SHOW_BKG;
}

void level1_bkg_update(void) {
    timer++;
        if (timer == 2) {
            background_offset_1 += 1;
            background_offset_2 += 3;
            background_offset_3 += 5;
            timer = 0;
        }
}