#ifndef CONSTANTS_H
#define CONSTANTS_H

constexpr int PUMP_RELAY{15};     // это реле, ведущее на насос
constexpr int PUMP_AMOUNT{31};    // количество зон
constexpr int SWITCH_LEVEL{0};    // реле: 1 - высокого уровня (или мосфет), 0 - низкого
constexpr int MINIMAL_CURRENT{2}; // минимальный ток

// Граница между блоками реле: зоны 0..RELAY_BLOCK_SPLIT-1 -> реле 1,
// зоны RELAY_BLOCK_SPLIT.. -> реле 2 (со смещением на RELAY_BLOCK_SPLIT).
constexpr int RELAY_BLOCK_SPLIT{15};
constexpr int RELAY2_OFFSET{15}; // значение, вычитаемое из номера зоны для блока реле 2

// Множитель времени: реальный режим (60) и отладочный режим (1).
constexpr int REAL_TIME_MINUTES{60};
constexpr int DEBUG_TIME_MINUTES{1};

constexpr int DEFAULT_GFX_BL_VALUE{80};
constexpr int DEFAULT_GFX_BL_TIME{30};
constexpr int DEFAULT_WATER_PAUSE{180};
constexpr int DEFAULT_K_DW_TIME{100};
constexpr int DEFAULT_MINUTES{60};
constexpr int DEFAULT_PUMP_ACTIVE_PCT{33}; // Процент времени работы насоса от общего времени зоны
constexpr int MIN_PUMP_ACTIVE_PCT{20};
constexpr int MAX_PUMP_ACTIVE_PCT{50};
constexpr int EXT_CLICK_AREA_SMALL{10};
constexpr int EXT_CLICK_AREA_LARGE{20};
constexpr int FULL_OPACITY{255};
constexpr int LOW_OPACITY{100};

static constexpr uint32_t MS_PER_SECOND = 1000;
static constexpr uint16_t MIN_K_DW_TIME = 50;
static constexpr uint16_t MAX_K_DW_TIME = 200;
static constexpr uint16_t K_DW_STEP = 10;
static constexpr uint16_t MIN_GFX_BL_TIME = 10;
static constexpr uint16_t SCREEN_ANIM_DURATION_MS = 1000;

constexpr uint32_t ZONE_BAR_COLOR_DW = 0x0000CB; // тёмно-синий (грязная вода)
constexpr const char *VERSION = "Текущая версия прошивки - 2.4";
#endif