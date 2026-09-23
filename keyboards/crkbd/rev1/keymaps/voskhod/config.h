#pragma once

/* Главная половина — левая. USB всегда втыкается в неё.
   Так обе половины шьются одной и той же прошивкой. */
#define MASTER_LEFT
#define SPLIT_USB_DETECT
/* Mod-tap: Esc/Gui и '/Alt.
   Если Esc и кавычка иногда срабатывают как модификатор — увеличь TAPPING_TERM.
   Если наоборот, модификатор не успевает — уменьши. */
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

/* Передавать состояние слоёв и индикаторов на вторую половину —
   нужно для OLED и для подсветки, зависящей от слоя. */
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_SLEEP
#    define RGB_MATRIX_KEYPRESSES
#endif

#ifdef OLED_ENABLE
#    define OLED_TIMEOUT 60000
#endif
