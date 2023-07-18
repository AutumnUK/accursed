#include <gb/gb.h>
#include "tiles.c"               
#include "map.c"

uint8_t timer,
        background_offset_1,
        background_offset_2,
        background_offset_3;

void interruptLCD() {
    switch (LYC_REG) {
		case 0x00: move_bkg(background_offset_1,0); LYC_REG = 0x70; break;
		case 0x70: move_bkg(background_offset_2,0); LYC_REG = 0x78; break;
		case 0x78: move_bkg(background_offset_3,0); LYC_REG = 0x00; break;
    }
}

void bkgInit() {
    timer = 0;
    set_bkg_tiles(0,0,80,18,map);       // Sets the map.
    set_bkg_data(0,13,tiles);            // Sets the tileset.
    STAT_REG = 0x45;
    LYC_REG  = 0x00; // First line. ( 00 / 78 / 80 )
    disable_interrupts();
    add_LCD(interruptLCD);
    enable_interrupts();
    set_interrupts(VBL_IFLAG | LCD_IFLAG);
    SHOW_BKG;
}

void bkgUpdate() {
    timer++;
        if (timer == 2) {
            background_offset_1 += 1;
            background_offset_2 += 2;
            background_offset_3 += 3;
            timer = 0;
        }
}