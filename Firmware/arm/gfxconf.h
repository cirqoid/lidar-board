/**
 * This file has a different license to the rest of the uGFX system.
 * You can copy, modify and distribute this file as you see fit.
 * You do not need to publish your source modifications to this file.
 * The only thing you are not permitted to do is to relicense it
 * under a different license.
 */

/**
 * Copy this file into your project directory and rename it as gfxconf.h
 * Edit your copy to turn on the uGFX features you want to use.
 * The values below are the defaults. You should delete anything
 * you are leaving as default.
 *
 * Please use spaces instead of tabs in this file.
 */

#ifndef _GFXCONF_H
#define _GFXCONF_H

/* The operating system to use. One of these must be defined - preferably in your Makefile */
#define GFX_USE_OS_CHIBIOS                         TRUE
//#define GFX_USE_OS_WIN32                           TRUE
//#define GFX_USE_OS_LINUX                           TRUE
//#define GFX_USE_OS_OSX                             TRUE


///////////////////////////////////////////////////////////////////////////
// GDISP                                                                 //
///////////////////////////////////////////////////////////////////////////
#define GFX_USE_GDISP                                TRUE
#define GDISP_NEED_STARTUP_LOGO                      FALSE

#define GDISP_NEED_AUTOFLUSH                         FALSE
#define GDISP_NEED_TIMERFLUSH                        FALSE
#define GDISP_NEED_VALIDATION                        TRUE
#define GDISP_NEED_CLIP                              TRUE
#define GDISP_NEED_TEXT                              TRUE
    #define GDISP_INCLUDE_FONT_UI2                   FALSE
    #define GDISP_INCLUDE_FONT_DEJAVUSANS32 FALSE
    #define GDISP_INCLUDE_USER_FONTS	TRUE
#define GDISP_NEED_CIRCLE                            FALSE
#define GDISP_NEED_CONVEX_POLYGON                    FALSE
#define GDISP_NEED_MULTITHREAD                       TRUE

#define GDISP_NEED_CONTROL TRUE
#define GDISP_DEFAULT_ORIENTATION                    GDISP_ROTATE_PORTRAIT

///////////////////////////////////////////////////////////////////////////
// GWIN                                                                  //
///////////////////////////////////////////////////////////////////////////
#define GFX_USE_GWIN                                 FALSE

#define GWIN_NEED_WINDOWMANAGER                      FALSE

#define GWIN_NEED_CONSOLE                            FALSE
    #define GWIN_CONSOLE_USE_HISTORY                 FALSE
        #define GWIN_CONSOLE_HISTORY_AVERAGING       FALSE
        #define GWIN_CONSOLE_HISTORY_ATCREATE        FALSE
    #define GWIN_CONSOLE_ESCSEQ                      FALSE
	#define GWIN_CONSOLE_USE_BASESTREAM              FALSE
#define GWIN_NEED_GRAPH                              FALSE

#define GWIN_NEED_WIDGET                             FALSE
    #define GWIN_NEED_LABEL                          FALSE
        #define GWIN_LABEL_ATTRIBUTE                 FALSE
    #define GWIN_NEED_BUTTON                         FALSE
        #define GWIN_BUTTON_LAZY_RELEASE             FALSE
    #define GWIN_NEED_SLIDER                         FALSE
    #define GWIN_NEED_CHECKBOX                       FALSE
    #define GWIN_NEED_IMAGE                          FALSE
        #define GWIN_NEED_IMAGE_ANIMATION            FALSE
    #define GWIN_NEED_RADIO                          FALSE
    #define GWIN_NEED_LIST                           FALSE
        #define GWIN_NEED_LIST_IMAGES                FALSE
    #define GWIN_NEED_PROGRESSBAR                    FALSE
        #define GWIN_PROGRESSBAR_AUTO                FALSE
	#define GWIN_FLAT_STYLING                        FALSE
#define GWIN_NEED_CONTAINERS                         FALSE
    #define GWIN_NEED_CONTAINER                      FALSE
    #define GWIN_NEED_FRAME                          FALSE


///////////////////////////////////////////////////////////////////////////
// GEVENT                                                                //
///////////////////////////////////////////////////////////////////////////
#define GFX_USE_GEVENT                               FALSE

///////////////////////////////////////////////////////////////////////////
// GTIMER                                                                //
///////////////////////////////////////////////////////////////////////////
#define GFX_USE_GTIMER                               FALSE

///////////////////////////////////////////////////////////////////////////
// GQUEUE                                                                //
///////////////////////////////////////////////////////////////////////////
#define GFX_USE_GQUEUE                               FALSE

#define GQUEUE_NEED_ASYNC                            FALSE
#define GQUEUE_NEED_GSYNC                            FALSE
#define GQUEUE_NEED_FSYNC                            FALSE
#define GQUEUE_NEED_BUFFERS                          FALSE

///////////////////////////////////////////////////////////////////////////
// GINPUT                                                                //
///////////////////////////////////////////////////////////////////////////
#define GFX_USE_GINPUT                               FALSE

#define GINPUT_NEED_MOUSE                            FALSE

#endif /* _GFXCONF_H */
