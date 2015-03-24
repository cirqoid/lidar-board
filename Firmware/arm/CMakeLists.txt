include (../cmake/Toolchain-stm32.cmake)

include_directories(${PROJECT_SOURCE_DIR}/arm ${PROJECT_SOURCE_DIR}/src)

add_executable(lidar-lite ${SOURCE_FILES} ${CHIBIOS_SOURCE_FILES} ${GFXLIB_SOURCE_FILES} )
stm32_add_hex_bin_targets(lidar-lite)

ADD_CUSTOM_TARGET(arm-reset COMMAND "/Applications/GNU ARM Eclipse/OpenOCD/bin/openocd" -f /opt/local/share/openocd/scripts/board/stm32f4discovery.cfg  -f ${PROJECT_SOURCE_DIR}/scripts/flash.cfg -c "reset run" -c "shutdown")
