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

/* --- Vial --- */
// Уникальный идентификатор именно ЭТОЙ прошивки/раскладки для Vial.
// Сгенерирован случайно, менять не нужно (если не хочешь получить
// в Vial-приложении "другую" клавиатуру с нуля).
#define VIAL_KEYBOARD_UID {0x64, 0x0A, 0x4C, 0xA6, 0x37, 0x33, 0xA3, 0x96}

// Комбинация для разблокировки настроек Vial (Security → Unlock):
// две верхние левые клавиши на ЛЕВОЙ половине, зажать при включении.
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}

#define DYNAMIC_KEYMAP_LAYER_COUNT 4
