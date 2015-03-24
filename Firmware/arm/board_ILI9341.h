/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.org/license.html
 */

/**
* @file    boards/addons/gdisp/board_ILI9341_spi.h
* @brief   GDISP Graphic Driver subsystem board interface for the ILI9341 display.
*
* @note        This file contains a mix of hardware specific and operating system specific
*                      code. You will need to change it for your CPU and/or operating system.
*/

#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H

#include "ch.h"
#include "hal.h"

#define LCD_PORT        GPIOA
#define LCD_MOSI        7
#define LCD_MISO        6
#define LCD_SCK         5
#define LCD_CS          8
#define LCD_DC          9
#define LCD_RES         10

/**
* SPI configuration structure.
* Speed 12 MHz, CPHA=0, CPOL=0, 8bits frames, MSb transmitted first.
* Soft slave select.
*/
static const SPIConfig spi1cfg = {
        NULL,
        LCD_PORT,
        LCD_CS,
        0,
        SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0
};

static void send_data(uint16_t data);

/**
* @brief   Initialise the board for the display.
*
* @param[in] g                 The GDisplay structure
*
* @note        Set the g->board member to whatever is appropriate. For multiple
*                      displays this might be a pointer to the appropriate register set.
*
* @notapi
*/
static inline void init_board(GDisplay *g) {

    // As we are not using multiple displays we set g->board to NULL as we don't use it.
    g->board = 0;

    palSetPadMode(LCD_PORT, LCD_MISO, PAL_MODE_ALTERNATE(0) | PAL_STM32_OSPEED_HIGHEST);
    palSetPadMode(LCD_PORT, LCD_MOSI, PAL_MODE_ALTERNATE(0) | PAL_STM32_OSPEED_HIGHEST);
    palSetPadMode(LCD_PORT, LCD_SCK, PAL_MODE_ALTERNATE(0) | PAL_STM32_OSPEED_HIGHEST);

    palSetPadMode(LCD_PORT, LCD_CS, PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST);
    palSetPadMode(LCD_PORT, LCD_DC, PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST);
    palSetPadMode(LCD_PORT, LCD_RES, PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST);

    spiStart(&SPID1, &spi1cfg);
    spiSelect(&SPID1);
}

/**
* @brief   After the initialisation.
*
* @param[in] g                 The GDisplay structure
*
* @notapi
*/
static inline void post_init_board(GDisplay *g) {
    (void) g;
}

/**
* @brief   Set or clear the lcd reset pin.
*
* @param[in] g                 The GDisplay structure
* @param[in] state             TRUE = lcd in reset, FALSE = normal operation
*
* @notapi
*/
static inline void setpin_reset(GDisplay *g, bool_t state) {
    (void) g;
    palWritePad(LCD_PORT, LCD_RES, !state);
}
/**
* @brief   Set the lcd back-light level.
*
* @param[in] g                         The GDisplay structure
* @param[in] percent           0 to 100%
*
* @notapi
*/
static inline void set_backlight(GDisplay *g, uint8_t percent) {
    (void) g;
    (void) percent;
}

/**
* @brief   Take exclusive control of the bus
*
* @param[in] g                         The GDisplay structure
*
* @notapi
*/
static inline void acquire_bus(GDisplay *g) {
    (void) g;
}

/**
* @brief   Release exclusive control of the bus
*
* @param[in] g                         The GDisplay structure
*
* @notapi
*/
static inline void release_bus(GDisplay *g) {
    (void) g;
}

/**
* @brief   Send data to the index register.
*
* @param[in] g                         The GDisplay structure
* @param[in] index                     The index register to set
*
* @notapi
*/
static inline void write_index(GDisplay *g, uint16_t index) {
    (void) g;

    palClearPad(LCD_PORT, LCD_DC);
    palClearPad(LCD_PORT, LCD_CS);
    spiSend(&SPID1, 1, &index);
    palSetPad(LCD_PORT, LCD_CS);
}

/**
* @brief   Send data to the lcd with DC control.
*
* @param[in] g                         The GDisplay structure
* @param[in] data                      The data to send
*
* @notapi
*/
static inline void write_data(GDisplay *g, uint16_t data) {
    (void) g;

    palSetPad(LCD_PORT, LCD_DC);
    palClearPad(LCD_PORT, LCD_CS);
    spiSend(&SPID1, 1, &data);
    palSetPad(LCD_PORT, LCD_CS);
}

/**
* @brief   Set the bus in read mode
*
* @param[in] g                         The GDisplay structure
*
* @notapi
*/
static inline void setreadmode(GDisplay *g) {
    (void) g;
}

/**
* @brief   Set the bus back into write mode
*
* @param[in] g                         The GDisplay structure
*
* @notapi
*/
static inline void setwritemode(GDisplay *g) {
    (void) g;
}

/**
* @brief   Read data from the lcd.
* @return      The data from the lcd
*
* @param[in] g                         The GDisplay structure
*
* @notapi
*/
static inline uint16_t read_data(GDisplay *g) {
    (void) g;
    return 0;
}

#endif /* _GDISP_LLD_BOARD_H */
