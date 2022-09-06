#pragma once

/* COPIED FROM GLFW/glfw3.h FILE */
/* We're doing this so that we don't have to include all of GLFW/glfw3.h
   into our KeyEvent.h and MouseEvent.h files. */

/* The unknown key */
#define FC_KEY_UNKNOWN            -1

/* Printable keys */
#define FC_KEY_SPACE              32
#define FC_KEY_APOSTROPHE         39  /* ' */
#define FC_KEY_COMMA              44  /* , */
#define FC_KEY_MINUS              45  /* - */
#define FC_KEY_PERIOD             46  /* . */
#define FC_KEY_SLASH              47  /* / */
#define FC_KEY_0                  48
#define FC_KEY_1                  49
#define FC_KEY_2                  50
#define FC_KEY_3                  51
#define FC_KEY_4                  52
#define FC_KEY_5                  53
#define FC_KEY_6                  54
#define FC_KEY_7                  55
#define FC_KEY_8                  56
#define FC_KEY_9                  57
#define FC_KEY_SEMICOLON          59  /* ; */
#define FC_KEY_EQUAL              61  /* = */
#define FC_KEY_A                  65
#define FC_KEY_B                  66
#define FC_KEY_C                  67
#define FC_KEY_D                  68
#define FC_KEY_E                  69
#define FC_KEY_F                  70
#define FC_KEY_G                  71
#define FC_KEY_H                  72
#define FC_KEY_I                  73
#define FC_KEY_J                  74
#define FC_KEY_K                  75
#define FC_KEY_L                  76
#define FC_KEY_M                  77
#define FC_KEY_N                  78
#define FC_KEY_O                  79
#define FC_KEY_P                  80
#define FC_KEY_Q                  81
#define FC_KEY_R                  82
#define FC_KEY_S                  83
#define FC_KEY_T                  84
#define FC_KEY_U                  85
#define FC_KEY_V                  86
#define FC_KEY_W                  87
#define FC_KEY_X                  88
#define FC_KEY_Y                  89
#define FC_KEY_Z                  90
#define FC_KEY_LEFT_BRACKET       91  /* [ */
#define FC_KEY_BACKSLASH          92  /* \ */
#define FC_KEY_RIGHT_BRACKET      93  /* ] */
#define FC_KEY_GRAVE_ACCENT       96  /* ` */
#define FC_KEY_WORLD_1            161 /* non-US #1 */
#define FC_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define FC_KEY_ESCAPE             256
#define FC_KEY_ENTER              257
#define FC_KEY_TAB                258
#define FC_KEY_BACKSPACE          259
#define FC_KEY_INSERT             260
#define FC_KEY_DELETE             261
#define FC_KEY_RIGHT              262
#define FC_KEY_LEFT               263
#define FC_KEY_DOWN               264
#define FC_KEY_UP                 265
#define FC_KEY_PAGE_UP            266
#define FC_KEY_PAGE_DOWN          267
#define FC_KEY_HOME               268
#define FC_KEY_END                269
#define FC_KEY_CAPS_LOCK          280
#define FC_KEY_SCROLL_LOCK        281
#define FC_KEY_NUM_LOCK           282
#define FC_KEY_PRINT_SCREEN       283
#define FC_KEY_PAUSE              284
#define FC_KEY_F1                 290
#define FC_KEY_F2                 291
#define FC_KEY_F3                 292
#define FC_KEY_F4                 293
#define FC_KEY_F5                 294
#define FC_KEY_F6                 295
#define FC_KEY_F7                 296
#define FC_KEY_F8                 297
#define FC_KEY_F9                 298
#define FC_KEY_F10                299
#define FC_KEY_F11                300
#define FC_KEY_F12                301
#define FC_KEY_F13                302
#define FC_KEY_F14                303
#define FC_KEY_F15                304
#define FC_KEY_F16                305
#define FC_KEY_F17                306
#define FC_KEY_F18                307
#define FC_KEY_F19                308
#define FC_KEY_F20                309
#define FC_KEY_F21                310
#define FC_KEY_F22                311
#define FC_KEY_F23                312
#define FC_KEY_F24                313
#define FC_KEY_F25                314
#define FC_KEY_KP_0               320
#define FC_KEY_KP_1               321
#define FC_KEY_KP_2               322
#define FC_KEY_KP_3               323
#define FC_KEY_KP_4               324
#define FC_KEY_KP_5               325
#define FC_KEY_KP_6               326
#define FC_KEY_KP_7               327
#define FC_KEY_KP_8               328
#define FC_KEY_KP_9               329
#define FC_KEY_KP_DECIMAL         330
#define FC_KEY_KP_DIVIDE          331
#define FC_KEY_KP_MULTIPLY        332
#define FC_KEY_KP_SUBTRACT        333
#define FC_KEY_KP_ADD             334
#define FC_KEY_KP_ENTER           335
#define FC_KEY_KP_EQUAL           336
#define FC_KEY_LEFT_SHIFT         340
#define FC_KEY_LEFT_CONTROL       341
#define FC_KEY_LEFT_ALT           342
#define FC_KEY_LEFT_SUPER         343
#define FC_KEY_RIGHT_SHIFT        344
#define FC_KEY_RIGHT_CONTROL      345
#define FC_KEY_RIGHT_ALT          346
#define FC_KEY_RIGHT_SUPER        347
#define FC_KEY_MENU               348

#define FC_KEY_LAST               FC_KEY_MENU

/*! @} */

/*! @defgroup mods Modifier key flags
 *  @brief Modifier key flags.
 *
 *  See [key input](@ref input_key) for how these are used.
 *
 *  @ingroup input
 *  @{ */

 /*! @brief If this bit is set one or more Shift keys were held down.
  *
  *  If this bit is set one or more Shift keys were held down.
  */
#define FC_MOD_SHIFT           0x0001
  /*! @brief If this bit is set one or more Control keys were held down.
   *
   *  If this bit is set one or more Control keys were held down.
   */
#define FC_MOD_CONTROL         0x0002
   /*! @brief If this bit is set one or more Alt keys were held down.
	*
	*  If this bit is set one or more Alt keys were held down.
	*/
#define FC_MOD_ALT             0x0004
	/*! @brief If this bit is set one or more Super keys were held down.
	 *
	 *  If this bit is set one or more Super keys were held down.
	 */
#define FC_MOD_SUPER           0x0008
	 /*! @brief If this bit is set the Caps Lock key is enabled.
	  *
	  *  If this bit is set the Caps Lock key is enabled and the @ref
	  *  FC_LOCK_KEY_MODS input mode is set.
	  */
#define FC_MOD_CAPS_LOCK       0x0010
	  /*! @brief If this bit is set the Num Lock key is enabled.
	   *
	   *  If this bit is set the Num Lock key is enabled and the @ref
	   *  FC_LOCK_KEY_MODS input mode is set.
	   */
#define FC_MOD_NUM_LOCK        0x0020