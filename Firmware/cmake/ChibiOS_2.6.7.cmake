set(CHIBIOS "${HOME}/arm/ChibiOS_2.6.7")

set(CHIBIOS_INCLUDE_DIRS

# os/hal/platforms/STM32F4xx/platform.mk
    ${CHIBIOS}/os/hal/platforms/STM32F0xx
    ${CHIBIOS}/os/hal/platforms/STM32
    ${CHIBIOS}/os/hal/platforms/STM32/GPIOv2
    ${CHIBIOS}/os/hal/platforms/STM32/RTCv2
    ${CHIBIOS}/os/hal/platforms/STM32/I2Cv2
    ${CHIBIOS}/os/hal/platforms/STM32/SPIv2
    ${CHIBIOS}/os/hal/platforms/STM32/TIMv1
    ${CHIBIOS}/os/hal/platforms/STM32/USARTv2

# os/hal/hal.mk
    HALINC = ${CHIBIOS}/os/hal/include

# os/ports/GCC/ARMCMx/STM32F4xx/port.mk
    ${CHIBIOS}/os/ports/common/ARMCMx/CMSIS/include
    ${CHIBIOS}/os/ports/common/ARMCMx
    ${CHIBIOS}/os/ports/GCC/ARMCMx
    ${CHIBIOS}/os/ports/GCC/ARMCMx/STM32F0xx

# os/kernel/kernel.mk
    ${CHIBIOS}/os/kernel/include

# os/various/fatfs_bindings/fatfs.mk
    ${CHIBIOS}/ext/fatfs/src
)

set (CHIBIOS_SOURCE_FILES

# os/hal/platforms/STM32F4xx/platform.mk
    ${CHIBIOS}/os/hal/platforms/STM32F0xx/stm32_dma.c
    ${CHIBIOS}/os/hal/platforms/STM32F0xx/hal_lld.c
    ${CHIBIOS}/os/hal/platforms/STM32F0xx/adc_lld.c
    ${CHIBIOS}/os/hal/platforms/STM32F0xx/ext_lld_isr.c
    ${CHIBIOS}/os/hal/platforms/STM32/ext_lld.c
    ${CHIBIOS}/os/hal/platforms/STM32/GPIOv2/pal_lld.c
    ${CHIBIOS}/os/hal/platforms/STM32/I2Cv2/i2c_lld.c
    ${CHIBIOS}/os/hal/platforms/STM32/RTCv2/rtc_lld.c
    ${CHIBIOS}/os/hal/platforms/STM32/SPIv2/spi_lld.c
    ${CHIBIOS}/os/hal/platforms/STM32/TIMv1/gpt_lld.c
    ${CHIBIOS}/os/hal/platforms/STM32/TIMv1/icu_lld.c
    ${CHIBIOS}/os/hal/platforms/STM32/TIMv1/pwm_lld.c
    ${CHIBIOS}/os/hal/platforms/STM32/USARTv2/serial_lld.c
    ${CHIBIOS}/os/hal/platforms/STM32/USARTv2/uart_lld.c

# os/hal/hal.mk
    ${CHIBIOS}/os/hal/src/hal.c
    ${CHIBIOS}/os/hal/src/adc.c
    ${CHIBIOS}/os/hal/src/can.c
    ${CHIBIOS}/os/hal/src/ext.c
    ${CHIBIOS}/os/hal/src/gpt.c
    ${CHIBIOS}/os/hal/src/i2c.c
    ${CHIBIOS}/os/hal/src/icu.c
    ${CHIBIOS}/os/hal/src/mac.c
    ${CHIBIOS}/os/hal/src/mmc_spi.c
    ${CHIBIOS}/os/hal/src/mmcsd.c
    ${CHIBIOS}/os/hal/src/pal.c
    ${CHIBIOS}/os/hal/src/pwm.c
    ${CHIBIOS}/os/hal/src/rtc.c
    ${CHIBIOS}/os/hal/src/sdc.c
    ${CHIBIOS}/os/hal/src/serial.c
    ${CHIBIOS}/os/hal/src/serial_usb.c
    ${CHIBIOS}/os/hal/src/spi.c
    ${CHIBIOS}/os/hal/src/tm.c
    ${CHIBIOS}/os/hal/src/uart.c
    ${CHIBIOS}/os/hal/src/usb.c

# os/ports/GCC/ARMCMx/STM32F4xx/port.mk
    ${CHIBIOS}/os/ports/GCC/ARMCMx/crt0.c
    ${CHIBIOS}/os/ports/GCC/ARMCMx/STM32F0xx/vectors.c
    ${CHIBIOS}/os/ports/GCC/ARMCMx/chcore.c
    ${CHIBIOS}/os/ports/GCC/ARMCMx/chcore_v6m.c
    ${CHIBIOS}/os/ports/common/ARMCMx/nvic.c

# os/kernel/kernel.mk
    ${CHIBIOS}/os/kernel/src/chsys.c
    ${CHIBIOS}/os/kernel/src/chdebug.c
    ${CHIBIOS}/os/kernel/src/chlists.c
    ${CHIBIOS}/os/kernel/src/chvt.c
    ${CHIBIOS}/os/kernel/src/chschd.c
    ${CHIBIOS}/os/kernel/src/chthreads.c
    ${CHIBIOS}/os/kernel/src/chdynamic.c
    ${CHIBIOS}/os/kernel/src/chregistry.c
    ${CHIBIOS}/os/kernel/src/chsem.c
    ${CHIBIOS}/os/kernel/src/chmtx.c
    ${CHIBIOS}/os/kernel/src/chcond.c
    ${CHIBIOS}/os/kernel/src/chevents.c
    ${CHIBIOS}/os/kernel/src/chmsg.c
    ${CHIBIOS}/os/kernel/src/chmboxes.c
    ${CHIBIOS}/os/kernel/src/chqueues.c
    ${CHIBIOS}/os/kernel/src/chmemcore.c
    ${CHIBIOS}/os/kernel/src/chheap.c
    ${CHIBIOS}/os/kernel/src/chmempools.c

)
