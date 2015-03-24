set(GFXLIB "{HOME}/arm/ugfx-2.1")
set(MFDIR ${GFXLIB}/src/gdisp/mcufont)

set(GFXLIB_INCLUDE_DIRS ${GFXLIB} ${MFDIR} ${GFXLIB}/drivers/gdisp/ILI9341)

set(GFXLIB_SOURCE_FILES

${GFXLIB}/drivers/gdisp/ILI9341/gdisp_lld_ILI9341.c

# gfx.mk
${GFXLIB}/src/gfx.c

# src/gos/sys_make.mk
    ${GFXLIB}/src/gos/chibios.c
    ${GFXLIB}/src/gos/freertos.c
    ${GFXLIB}/src/gos/win32.c
    ${GFXLIB}/src/gos/linux.c
    ${GFXLIB}/src/gos/osx.c
    ${GFXLIB}/src/gos/raw32.c

# src/gqueue/sys_make.mk
     ${GFXLIB}/src/gqueue/gqueue.c

# src/gdisp/sys_make.mk
    ${GFXLIB}/src/gdisp/gdisp.c
    ${GFXLIB}/src/gdisp/fonts.c
    ${GFXLIB}/src/gdisp/image.c
    ${GFXLIB}/src/gdisp/image_native.c
    ${GFXLIB}/src/gdisp/image_gif.c
    ${GFXLIB}/src/gdisp/image_bmp.c
    ${GFXLIB}/src/gdisp/image_jpg.c
    ${GFXLIB}/src/gdisp/image_png.c

# src/gdisp/mcufont/mcufont.mk
    ${MFDIR}/mf_encoding.c
    ${MFDIR}/mf_font.c
    ${MFDIR}/mf_justify.c
    ${MFDIR}/mf_kerning.c
    ${MFDIR}/mf_rlefont.c
    ${MFDIR}/mf_bwfont.c
    ${MFDIR}/mf_scaledfont.c
    ${MFDIR}/mf_wordwrap.c

# src/gevent/sys_make.mk
    ${GFXLIB}/src/gevent/gevent.c

# src/gtimer/sys_make.mk
    ${GFXLIB}/src/gtimer/gtimer.c

# src/gwin/sys_make.mk
    ${GFXLIB}/src/gwin/gwin.c
    ${GFXLIB}/src/gwin/gwidget.c
    ${GFXLIB}/src/gwin/gwm.c
    ${GFXLIB}/src/gwin/console.c
    ${GFXLIB}/src/gwin/graph.c
    ${GFXLIB}/src/gwin/button.c
    ${GFXLIB}/src/gwin/slider.c
    ${GFXLIB}/src/gwin/checkbox.c
    ${GFXLIB}/src/gwin/gimage.c
    ${GFXLIB}/src/gwin/label.c
    ${GFXLIB}/src/gwin/radio.c
    ${GFXLIB}/src/gwin/list.c
    ${GFXLIB}/src/gwin/progressbar.c
    ${GFXLIB}/src/gwin/gcontainer.c
    ${GFXLIB}/src/gwin/frame.c

# src/ginput/sys_make.mk
    ${GFXLIB}/src/ginput/ginput.c
    ${GFXLIB}/src/ginput/mouse.c
    ${GFXLIB}/src/ginput/keyboard.c
    ${GFXLIB}/src/ginput/toggle.c
    ${GFXLIB}/src/ginput/dial.c

# src/gadc/sys_make.mk
    ${GFXLIB}/src/gadc/gadc.c

# src/gaudio/sys_make.mk
    ${GFXLIB}/src/gaudio/gaudio.c

# src/gmisc/sys_make.mk
    ${GFXLIB}/src/gmisc/gmisc.c
    ${GFXLIB}/src/gmisc/arrayops.c
    ${GFXLIB}/src/gmisc/trig.c

# src/gfile/sys_make.mk
    ${GFXLIB}/src/gfile/gfile.c
)
