#include <stdlib.h>
#include "ch.h"
#include "hal.h"
#include "gfx.h"

#include "stdio.h"

#define MAX_DIGITS      4
#define DIGIT_WIDTH     320 / MAX_DIGITS

#define LCD_PORT        GPIOA
#define LCD_MOSI        7
#define LCD_MISO        6
#define LCD_SCK         5
#define LCD_CS          8
#define LCD_DC          9
#define LCD_RES         10

static const SPIConfig spicfg = {
        NULL,
        LCD_PORT,
        LCD_CS,
        0,
        SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0
};

/* I2C interface #2 */
static const I2CConfig i2cconfig = {
        STM32_TIMINGR_PRESC(1) |
                STM32_TIMINGR_SCLDEL(0x04) | STM32_TIMINGR_SDADEL(0x02) |
                STM32_TIMINGR_SCLH(0x0F)  | STM32_TIMINGR_SCLL(0x13),
        0,
        0
};
void init()
{
    halInit();
    chSysInit();

    palSetPadMode(GPIOA, 0, PAL_MODE_INPUT_PULLUP);
    palSetPadMode(GPIOB, 6, PAL_MODE_ALTERNATE(1) | PAL_STM32_OTYPE_OPENDRAIN);
    palSetPadMode(GPIOB, 7, PAL_MODE_ALTERNATE(1) | PAL_STM32_OTYPE_OPENDRAIN);

    gfxInit();
    gfxSleepMilliseconds(200);
    gdispSetOrientation(GDISP_ROTATE_90);
}

static uint8_t txBuf[10];
static uint8_t rxBuf[10];

int readDistance()
{
    spiStop(&SPID1);
    i2cStart(&I2CD1, &i2cconfig);
    i2cAcquireBus(&I2CD1);
    txBuf[0] = 0x00;
    txBuf[1] = 0x04;
    i2cMasterTransmitTimeout(&I2CD1, 0x62, txBuf, 2, rxBuf, 0, 100);
    chThdSleep(20);

    txBuf[0] = 0x8F;
    msg_t status = status = i2cMasterTransmitTimeout(&I2CD1, 0x62, txBuf, 1, rxBuf, 2, 100);
    i2cReleaseBus(&I2CD1);
    i2cStop(&I2CD1);
    spiStart(&SPID1, &spicfg);

    return status == RDY_OK ? (rxBuf[0] << 8) | rxBuf[1] : status;
}

static font_t font;
static uint8_t digits[MAX_DIGITS] = {0};
static color_t backgroundColor = White;

void updateScreen(int value, bool validationEnabled, bool validReading)
{
    int i;
    int digitsToRedraw = 0;
    uint8_t newDigits[MAX_DIGITS] = {0};
    for (i = 0; i < MAX_DIGITS; ++i)
    {
        int currentDigit = value % 10;
        value /= 10;
        if (digits[i] != currentDigit)
            digitsToRedraw = i + 1;
        newDigits[i] = currentDigit;
    }

    color_t newBackgroundColor = validationEnabled ? (validReading ? Green : Red) : White;
    if (backgroundColor != newBackgroundColor)
    {
        gdispClear(newBackgroundColor);
        backgroundColor = newBackgroundColor;
        digitsToRedraw = MAX_DIGITS;
    }
    bool pastLeadingZeros = false;
    for (i = digitsToRedraw - 1; i >= 0; --i)
    {
        gdispDrawChar(DIGIT_WIDTH * (MAX_DIGITS - i - 1), 60, 48 + digits[i], font, backgroundColor);
        if (!pastLeadingZeros && newDigits[i] > 0)
            pastLeadingZeros = true;
        if (pastLeadingZeros)
            gdispDrawChar(DIGIT_WIDTH * (MAX_DIGITS - i - 1), 60, 48 + newDigits[i], font, Black);
    }
    for (i = 0; i < MAX_DIGITS; i++)
        digits[i] = newDigits[i];

}

int main()
{
    init();

    gdispClear(White);
    font = gdispOpenFont("DejaVu Sans Book 128");

    int fixedDistance = -1;
    bool keyPressed = false;
    while(1)
    {
        int distance = readDistance();
        if (keyPressed && palReadPad(GPIOA, 0))
            fixedDistance = distance;
        keyPressed = !palReadPad(GPIOA, 0);
        updateScreen(distance >= 0 ? distance : 0, fixedDistance > 0, abs(distance - fixedDistance) < 5);
        gfxSleepMilliseconds(200);
    }

}
