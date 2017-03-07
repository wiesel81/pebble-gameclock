#include <pebble.h>

#define COLOR_BGCOLOR_DEFAULT GColorBlack
#define COLOR_FORECOLOR_DEFAULT GColorWhite
#define STROKE_WIDTH 2
#define BUTTON_LONG_PRESSED_DURATION_DEFAULT 1000 // in milliseconds
#define STATE_MSG_VIBRATION_ON "VIBE ON"
#define STATE_MSG_VIBRATION_OFF "VIBE OFF"
#define STATE_MSG_VIBRATION_BUTTON_ON "VIBE ON BUTTON ON"
#define STATE_MSG_VIBRATION_BUTTON_OFF "VIBE ON BUTTON OFF"
#define STATE_MSG_START_ON_READY "START ON READY"
#define STATE_MSG_START_ON_SNAP "START ON SNAP"
#define STATE_MSG_TURBO_MODE "TURBO-MODE!!!"
#define VIBE_SHORT 150
#define VIBE_LONG 400
#define VIBE_LONGEST 800
#define VIBE_PAUSE 200
#define VIBE_ENABLED_DEFAULT true
#define VIBE_ON_NOTIFICATION_ENABLED_DEFAULT true
#define VIBE_ON_TAP_ENABLED_DEFAULT false
#define VIBE_DEFAULT_INDEX 1
#define VIBE_OFF_PATTERN_INDEX 0
#define VIBE_ON_TIMER_EXPIRED_PATTERN_INDEX_DEFAULT 14
#define VIBE_ON_BUTTON_PRESSED_PATTERN_INDEX_DEFAULT 0
#define VIBE_ON_BUTTON_STARTS_TIMER_PATTERN_INDEX_DEFAULT 3
#define VIBE_ON_BUTTON_STOPS_TIMER_PATTERN_INDEX_DEFAULT 1
#define TIMER_START_VALUE_DEFAULT (12*60)
#define TIMER_START_VALUE_MIN (5*60)
#define TIMER_START_VALUE_MAX (25*60)
#define TIMER_COUNTDOWN_STEP_DEFAULT 1
#define TIMER_COUNTDOWN_STEP_TURBO 5
#define TIMER_INCREASE_STEP_DEFAULT 3
#define TIMER_DECREASE_STEP_DEFAULT 10

#define FONT_DEFAULT FONT_KEY_GOTHIC_18
#define FONT_DEFAULT_SIZE 22 // additional space needed for letters like 'g'
#if defined(PBL_PLATFORM_CHALK) || defined(PBL_PLATFORM_EMERY)
#define FONT_TICKER RESOURCE_ID_ROBOTO_BOLD_SUBSET_49
#define FONT_TICKER_SIZE 64 // why not 49???
#else
#define FONT_TICKER RESOURCE_ID_ROBOTO_BOLD_SUBSET_42 // FONT_KEY_ROBOTO_BOLD_SUBSET_49
#define FONT_TICKER_SIZE 56 // why not 42???
#endif

#define NOTIFICATION_MAX 9
#define NOTIFICATION_MSG_MAX_LEN 40

#define SETTINGS_KEY_VERSION 1
#define SETTINGS_KEY 100
#define SETTINGS_KEY_NOTIFICATION_2MIN_WARNING 200
#define SETTINGS_KEY_NOTIFICATION_TIMER_EXPIRED 300
#define SETTINGS_KEY_NOTIFICATION_MSG_START 1001

typedef struct Notification {
	int second;
	bool onTimerEnabled;
	int vibePatternIndex;
	char *stateMessage;
} __attribute__((__packed__)) Notification;

// Structure containing our settings
typedef struct ClaySettings {
	bool vibesEnabled;
	bool vibesOnNotificationsEnabled;
	bool vibesOnTapEnabled;
	int vibesOnButtonPressedPatternIndex;
	int vibesOnButtonStartsTimerPatternIndex;
	int vibesOnButtonStopsTimerPatternIndex;
	int vibesOnButtonSetsStartOnReadyPatternIndex;
	int vibesOnButtonSetsStartOnSnapPatternIndex;
	int timerStartValue;
	int timerIncreaseStep;
	int timerDecreaseStep;
	Notification notification2MinWarning;
	Notification notificationTimerExpired;
	Notification notifications[NOTIFICATION_MAX];
} __attribute__((__packed__)) ClaySettings;

// The following function may be used from the project's .c-file
void initSettings(void);
bool isVibesEnabled(void);
bool invertVibesEnabled(void);
bool isVibesOnNotificationsEnabled(void);
bool isVibeOnTapEnabled(void);
const VibePattern *getVibesOnTimerExpiredPattern(void);
const VibePattern *getOnButtonPressedVibePattern(void);
bool invertVibesOnButtonPressedEnabled(void);
const VibePattern *getOnButtonStartsTimerVibePattern(void);
const VibePattern *getOnButtonStopsTimerVibePattern(void);
const VibePattern *getOnButtonSetsStartOnReadyVibePattern(void);
const VibePattern *getOnButtonSetsStartOnSnapVibePattern(void);
const Notification *getNotification(int);
const VibePattern *getVibesNotificationPattern(const Notification *);
char *getNotificationStateMessage(const Notification *);
int incrementTimerStartValue(void);
int decrementTimerStartValue(void);
int getTimerStartValue(void);
int getTimerIncreaseStep(void);
int getTimerDecreaseStep(void);
int getButtonPressedLongDuration(void);
GColor getBackgroundColor(void);
GColor getForegroundColor(void);
uint32_t getStartIconResourceID(void);
uint32_t getStopIconResourceID(void);
char *getStateMessageVibesOn(void);
char *getStateMessageVibesOff(void);
char *getStateMessageVibesOnButtonPressedOn(void);
char *getStateMessageVibesOnButtonPressedOff(void);
char *getStateMessageStartOnReady(void);
char *getStateMessageStartOnSnap(void);
char *getStateMessageTurboMode(void);
