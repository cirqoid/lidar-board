INCLUDE(CMakeForceCompiler)

SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_VERSION 1)

SET(ARM_TOOLCHAIN "${HOME}/arm/gcc-arm-none-eabi-4_9-2014q4")

# specify the cross compiler
CMAKE_FORCE_C_COMPILER(${ARM_TOOLCHAIN}/bin/arm-none-eabi-gcc GNU)
CMAKE_FORCE_CXX_COMPILER(${ARM_TOOLCHAIN}/bin/arm-none-eabi-g++ GNU)
SET(CMAKE_OBJCOPY ${ARM_TOOLCHAIN}/bin/arm-none-eabi-objcopy)

SET(CMAKE_C_LINK_FLAGS "")
SET(CMAKE_CXX_LINK_FLAGS "")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Os -ggdb -fomit-frame-pointer -falign-functions=16 -ffunction-sections -fdata-sections -fno-common -DTHUMB_PRESENT -mno-thumb-interwork -DTHUMB_NO_INTERWORKING -mcpu=cortex-m0 -mthumb -DTHUMB")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os -ggdb -fomit-frame-pointer -falign-functions=16 -ffunction-sections -fdata-sections -fno-common -DTHUMB_PRESENT -mno-thumb-interwork -DTHUMB_NO_INTERWORKING -mcpu=cortex-m0 -mthumb -DTHUMB")
set(CMAKE_EXE_LINKER_FLAGS "-nostartfiles -T${PROJECT_SOURCE_DIR}/arm/STM32F051x8.ld -Wl,--gc-sections -mno-thumb-interwork -mthumb ")
set(CMAKE_EXECUTABLE_SUFFIX ".elf")

# where is the target environment
SET(CMAKE_FIND_ROOT_PATH  ${ARM_TOOLCHAIN})

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

FUNCTION(STM32_ADD_HEX_BIN_TARGETS TARGET)
    IF(EXECUTABLE_OUTPUT_PATH)
      SET(FILENAME "${EXECUTABLE_OUTPUT_PATH}/${TARGET}")
    ELSE()
      SET(FILENAME "${TARGET}")
    ENDIF()
    ADD_CUSTOM_TARGET(${TARGET}.hex DEPENDS ${TARGET} COMMAND ${CMAKE_OBJCOPY} -Oihex ${FILENAME}.elf ${FILENAME}.hex)
    ADD_CUSTOM_TARGET(${TARGET}.bin DEPENDS ${TARGET} COMMAND ${CMAKE_OBJCOPY} -O binary ${FILENAME}.elf ${FILENAME}.bin)
    ADD_CUSTOM_TARGET(flash-${TARGET} DEPENDS ${TARGET} COMMAND "/Applications/GNU ARM Eclipse/OpenOCD/bin/openocd" -f /opt/local/share/openocd/scripts/board/stm32f0discovery.cfg   -f ${PROJECT_SOURCE_DIR}/scripts/flash.cfg -c init -c targets -c "halt" -c "flash write_image erase ${FILENAME}.elf" -c "reset run" -c shutdown)
    ADD_CUSTOM_TARGET(debug-${TARGET} DEPENDS ${TARGET} COMMAND "/Applications/GNU ARM Eclipse/OpenOCD/bin/openocd" -f /opt/local/share/openocd/scripts/board/stm32f0discovery.cfg   -f ${PROJECT_SOURCE_DIR}/scripts/flash.cfg -c "stm32f0x.cpu configure -rtos auto;" -c init -c targets -c "halt")
    ADD_CUSTOM_TARGET(gdb-${TARGET} DEPENDS ${TARGET} COMMAND ${ARM_TOOLCHAIN}/bin/arm-none-eabi-gdb -ex "target remote localhost:3333" -ex "monitor reset halt"  ${FILENAME}.elf)
ENDFUNCTION()

