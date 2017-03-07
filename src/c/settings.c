#include <pebble.h>
#include "settings.h"

uint32_t vibeSegementsShort[] = { VIBE_SHORT };
static const VibePattern VIBE_PATTERN_SHORT = { .durations = vibeSegementsShort, .num_segments = ARRAY_LENGTH(vibeSegementsShort) };
uint32_t vibeSegementsLong[] = { VIBE_LONG };
static const VibePattern VIBE_PATTERN_LONG = { .durations = vibeSegementsLong, .num_segments = ARRAY_LENGTH(vibeSegementsLong) };
uint32_t vibeSegementsShortShort[] = { VIBE_SHORT, VIBE_PAUSE, VIBE_SHORT };
static const VibePattern VIBE_PATTERN_SHORT_SHORT = { .durations = vibeSegementsShortShort, .num_segments = ARRAY_LENGTH(vibeSegementsShortShort) };
uint32_t vibeSegementsShortLong[] = { VIBE_SHORT, VIBE_PAUSE, VIBE_LONG };
static const VibePattern VIBE_PATTERN_SHORT_LONG = { .durations = vibeSegementsShortLong, .num_segments = ARRAY_LENGTH(vibeSegementsShortLong) };
uint32_t vibeSegementsLongShort[] = { VIBE_LONG, VIBE_PAUSE, VIBE_SHORT };
static const VibePattern VIBE_PATTERN_LONG_SHORT = { .durations = vibeSegementsLongShort, .num_segments = ARRAY_LENGTH(vibeSegementsLongShort) };
uint32_t vibeSegementsLongLong[] = { VIBE_LONG, VIBE_PAUSE, VIBE_LONG };
static const VibePattern VIBE_PATTERN_LONG_LONG = { .durations = vibeSegementsLongLong, .num_segments = ARRAY_LENGTH(vibeSegementsLongLong) };
uint32_t vibeSegementsShortShortShort[] = { VIBE_SHORT, VIBE_PAUSE, VIBE_SHORT, VIBE_PAUSE, VIBE_SHORT };
static const VibePattern VIBE_PATTERN_SHORT_SHORT_SHORT = { .durations = vibeSegementsShortShortShort, .num_segments = ARRAY_LENGTH(vibeSegementsShortShortShort) };
uint32_t vibeSegements2LongShort[] = { VIBE_LONG, VIBE_PAUSE, VIBE_LONG, VIBE_PAUSE, VIBE_SHORT };
static const VibePattern VIBE_PATTERN_2LONG_SHORT = { .durations = vibeSegements2LongShort, .num_segments = ARRAY_LENGTH(vibeSegements2LongShort) };
uint32_t vibeSegements3Long[] = { VIBE_LONG, VIBE_PAUSE, VIBE_LONG, VIBE_PAUSE, VIBE_LONG };
static const VibePattern VIBE_PATTERN_3LONG = { .durations = vibeSegements3Long, .num_segments = ARRAY_LENGTH(vibeSegements3Long) };
uint32_t vibeSegements3LongShort[] = { VIBE_LONG, VIBE_PAUSE, VIBE_LONG, VIBE_PAUSE, VIBE_LONG, VIBE_PAUSE, VIBE_SHORT };
static const VibePattern VIBE_PATTERN_3LONG_SHORT = { .durations = vibeSegements3LongShort, .num_segments = ARRAY_LENGTH(vibeSegements3LongShort) };
uint32_t vibeSegements4Long[] = { VIBE_LONG, VIBE_PAUSE, VIBE_LONG, VIBE_PAUSE, VIBE_LONG, VIBE_PAUSE, VIBE_LONG };
static const VibePattern VIBE_PATTERN_4LONG = { .durations = vibeSegements4Long, .num_segments = ARRAY_LENGTH(vibeSegements4Long) };
uint32_t vibeSegements4LongShort[] = { VIBE_LONG, VIBE_PAUSE, VIBE_LONG, VIBE_PAUSE, VIBE_LONG, VIBE_PAUSE, VIBE_LONG, VIBE_PAUSE, VIBE_SHORT };
static const VibePattern VIBE_PATTERN_4LONG_SHORT = { .durations = vibeSegements4LongShort, .num_segments = ARRAY_LENGTH(vibeSegements4LongShort) };
uint32_t vibeSegements5Long[] = { VIBE_LONG, VIBE_PAUSE, VIBE_LONG, VIBE_PAUSE, VIBE_LONG, VIBE_PAUSE, VIBE_LONG, VIBE_PAUSE, VIBE_LONG };
static const VibePattern VIBE_PATTERN_5LONG = { .durations = vibeSegements5Long, .num_segments = ARRAY_LENGTH(vibeSegements5Long) };
uint32_t vibeSegementsLongest[] = { VIBE_LONGEST };
static const VibePattern VIBE_PATTERN_LONGEST = { .durations = vibeSegementsLongest, .num_segments = ARRAY_LENGTH(vibeSegementsLongest) };

																							// 0	// 1									// 2								// 3											// 4											// 5											// 6											// 7														// 8												// 9								// 10												// 11								// 12												// 13								// 14
static const VibePattern *VIBE_PATTERNS[] = { NULL, &VIBE_PATTERN_SHORT, &VIBE_PATTERN_LONG, &VIBE_PATTERN_SHORT_SHORT, &VIBE_PATTERN_SHORT_LONG, &VIBE_PATTERN_LONG_SHORT, &VIBE_PATTERN_LONG_LONG, &VIBE_PATTERN_SHORT_SHORT_SHORT, &VIBE_PATTERN_2LONG_SHORT, &VIBE_PATTERN_3LONG, &VIBE_PATTERN_3LONG_SHORT, &VIBE_PATTERN_4LONG, &VIBE_PATTERN_4LONG_SHORT, &VIBE_PATTERN_5LONG, &VIBE_PATTERN_LONGEST };
static const Notification NOTIFICATION_COUNTDOWN = { 0, true, VIBE_DEFAULT_INDEX, NULL };

static ClaySettings settings = { VIBE_ENABLED_DEFAULT,
																VIBE_ON_NOTIFICATION_ENABLED_DEFAULT,
																VIBE_ON_TAP_ENABLED_DEFAULT,
																VIBE_OFF_PATTERN_INDEX,
																VIBE_ON_BUTTON_STARTS_TIMER_PATTERN_INDEX_DEFAULT,
																VIBE_ON_BUTTON_STOPS_TIMER_PATTERN_INDEX_DEFAULT,
																VIBE_ON_BUTTON_STARTS_TIMER_PATTERN_INDEX_DEFAULT,
																VIBE_ON_BUTTON_STOPS_TIMER_PATTERN_INDEX_DEFAULT,
																TIMER_START_VALUE_DEFAULT,
																TIMER_INCREASE_STEP_DEFAULT,
																TIMER_DECREASE_STEP_DEFAULT,
																// Notifications [second, onTimerEnabled, vibePatternIndex, stateMessage]
																{ 125, true, 6, "2:00 WARNING!" },
																{ 5, true, VIBE_ON_TIMER_EXPIRED_PATTERN_INDEX_DEFAULT, "EXPIRED" },
																{ { 300, true, 13, "5:00 WARNING!" },
																	{ 270, false, 12, "4:30 WARNING!" },
																	{ 240, true, 11, "4:00 WARNING!" },
																	{ 210, false, 10, "3:30 WARNING!" },
																	{ 180, true, 9, "3:00 WARNING!" },
																	{ 150, true, 8, "2:30 WARNING!" },
																	{ 90, false, 5, "1:30 WARNING!" },
																	{ 60, true, 2, "1:00 WARNING!" },
																	{ 0, false, 0, "" }
																}
															 };
const int settingsVersionCurrent = 1;

// TODO: add version to storage and migrate storage data if necessary
// https://developer.pebble.com/guides/events-and-services/persistent-storage/

// TODO: add settings for motion sensor (enable / disable, vibration pattern on starting / stopping timer)

// Read settings from persistent storage
static void loadSettings(void) {
	if(persist_exists(SETTINGS_KEY)) {
		persist_read_data(SETTINGS_KEY, &settings, sizeof(settings));
		settings.notification2MinWarning.stateMessage = malloc(NOTIFICATION_MSG_MAX_LEN + 1);
		persist_read_string(SETTINGS_KEY_NOTIFICATION_2MIN_WARNING, settings.notification2MinWarning.stateMessage, NOTIFICATION_MSG_MAX_LEN);
		settings.notificationTimerExpired.stateMessage = malloc(NOTIFICATION_MSG_MAX_LEN + 1);
		persist_read_string(SETTINGS_KEY_NOTIFICATION_TIMER_EXPIRED, settings.notificationTimerExpired.stateMessage, NOTIFICATION_MSG_MAX_LEN);
		for(int i = 0; i < NOTIFICATION_MAX; i++) {
			settings.notifications[i].stateMessage = malloc(NOTIFICATION_MSG_MAX_LEN + 1);
			persist_read_string(SETTINGS_KEY_NOTIFICATION_MSG_START + i, settings.notifications[i].stateMessage, NOTIFICATION_MSG_MAX_LEN);
		}
	}
}

// Delete the settings from persistent storage
static void deleteSettings(void) {
	if(persist_exists(SETTINGS_KEY)) {
		persist_delete(SETTINGS_KEY);
		persist_delete(SETTINGS_KEY_NOTIFICATION_2MIN_WARNING);
		persist_delete(SETTINGS_KEY_NOTIFICATION_TIMER_EXPIRED);
		for(int i = 0; i < NOTIFICATION_MAX; i++) {
			persist_delete(SETTINGS_KEY_NOTIFICATION_MSG_START + i);
		}
	}
}

// Save the settings to persistent storage
static void saveSettings(void) {
  persist_write_data(SETTINGS_KEY, &settings, sizeof(settings));
	persist_write_string(SETTINGS_KEY_NOTIFICATION_2MIN_WARNING, settings.notification2MinWarning.stateMessage);
	persist_write_string(SETTINGS_KEY_NOTIFICATION_TIMER_EXPIRED, settings.notificationTimerExpired.stateMessage);
	for(int i = 0; i < NOTIFICATION_MAX; i++) {
		persist_write_string(SETTINGS_KEY_NOTIFICATION_MSG_START + i, settings.notifications[i].stateMessage);
	}
	persist_write_int(SETTINGS_KEY_VERSION, settingsVersionCurrent);
}

static void inboxReceivedHandler(DictionaryIterator *iter, void *context) {
	// Handle global section
	Tuple *vibesEnabled = dict_find(iter, MESSAGE_KEY_VibesEnabled);
	if(vibesEnabled) {
		settings.vibesEnabled = vibesEnabled->value->int32 == 1;
	}
	Tuple *vibesOnNotificationsEnabled = dict_find(iter, MESSAGE_KEY_VibesOnNotificationsEnabled);
	if(vibesOnNotificationsEnabled) {
		settings.vibesOnNotificationsEnabled = vibesOnNotificationsEnabled->value->int32 == 1;
	}
	Tuple *vibesOnTapEnabled = dict_find(iter, MESSAGE_KEY_VibesOnTapEnabled);
	if(vibesOnTapEnabled) {
		settings.vibesOnTapEnabled = vibesOnTapEnabled->value->int32 == 1;
	}
	
	// Handle button section
	Tuple *vibesOnButtonPressedPatternIndex = dict_find(iter, MESSAGE_KEY_VibesOnButtonPressedPatternIndex);
	if(vibesOnButtonPressedPatternIndex) {
		settings.vibesOnButtonPressedPatternIndex = atoi(vibesOnButtonPressedPatternIndex->value->cstring);
	}
	Tuple *vibesOnButtonStartsTimerPatternIndex = dict_find(iter, MESSAGE_KEY_VibesOnButtonStartsTimerPatternIndex);
	if(vibesOnButtonStartsTimerPatternIndex) {
		settings.vibesOnButtonStartsTimerPatternIndex = atoi(vibesOnButtonStartsTimerPatternIndex->value->cstring);
	}
	Tuple *vibesOnButtonStopsTimerPatternIndex = dict_find(iter, MESSAGE_KEY_VibesOnButtonStopsTimerPatternIndex);
	if(vibesOnButtonStopsTimerPatternIndex) {
		settings.vibesOnButtonStopsTimerPatternIndex = atoi(vibesOnButtonStopsTimerPatternIndex->value->cstring);
	}
	Tuple *vibesOnButtonSetsStartOnReadyPatternIndex = dict_find(iter, MESSAGE_KEY_VibesOnButtonSetsStartOnReadyPatternIndex);
	if(vibesOnButtonSetsStartOnReadyPatternIndex) {
		settings.vibesOnButtonSetsStartOnReadyPatternIndex = atoi(vibesOnButtonSetsStartOnReadyPatternIndex->value->cstring);
	}
	Tuple *vibesOnButtonSetsStartOnSnapPatternIndex = dict_find(iter, MESSAGE_KEY_VibesOnButtonSetsStartOnSnapPatternIndex);
	if(vibesOnButtonSetsStartOnSnapPatternIndex) {
		settings.vibesOnButtonSetsStartOnSnapPatternIndex = atoi(vibesOnButtonSetsStartOnSnapPatternIndex->value->cstring);
	}

	// Handle timing section
	Tuple *timerStartValue = dict_find(iter, MESSAGE_KEY_TimerStartValue);
	if(timerStartValue) {
		settings.timerStartValue = timerStartValue->value->int32 * 60;
	}
	Tuple *timerIncreaseStep = dict_find(iter, MESSAGE_KEY_TimerIncreaseStep);
	if(timerIncreaseStep) {
		settings.timerIncreaseStep = timerIncreaseStep->value->int32;
	}
	Tuple *timerDecreaseStep = dict_find(iter, MESSAGE_KEY_TimerDecreaseStep);
	if(timerDecreaseStep) {
		settings.timerDecreaseStep = timerDecreaseStep->value->int32;
	}

	// Handle 2' warning section
	Tuple *vibesOn2MinWarningPatternIndex = dict_find(iter, MESSAGE_KEY_VibesOn2MinWarningPatternIndex);
	if(vibesOn2MinWarningPatternIndex) {
		settings.notification2MinWarning.vibePatternIndex = atoi(vibesOn2MinWarningPatternIndex->value->cstring);
	}
	Tuple *notification2MinWarningCountdownValue = dict_find(iter, MESSAGE_KEY_Notification2MinWarningCountdownValue);
	if(notification2MinWarningCountdownValue) {
		settings.notification2MinWarning.second = notification2MinWarningCountdownValue->value->int32 + 120;
	}
	Tuple *notification2MinWarningStateMessage = dict_find(iter, MESSAGE_KEY_Notification2MinWarningStateMessage);
	if(notification2MinWarningStateMessage) {
		settings.notification2MinWarning.stateMessage = notification2MinWarningStateMessage->value->cstring;
	}

	// Handle timer expired section
	Tuple *vibesOnTimerExpiredPatternIndex = dict_find(iter, MESSAGE_KEY_VibesOnTimerExpiredPatternIndex);
	if(vibesOnTimerExpiredPatternIndex) {
		settings.notificationTimerExpired.vibePatternIndex = atoi(vibesOnTimerExpiredPatternIndex->value->cstring);
	}
	Tuple *notificationTimerExpiredCountdownValue = dict_find(iter, MESSAGE_KEY_NotificationTimerExpiredCountdownValue);
	if(notificationTimerExpiredCountdownValue) {
		settings.notificationTimerExpired.second = notificationTimerExpiredCountdownValue->value->int32;
	}

	// Handle notification sections
	Tuple *notification_1_Minute = dict_find(iter, MESSAGE_KEY_Notification_1_Minute);
	if(notification_1_Minute) {
		settings.notifications[0].second = notification_1_Minute->value->int32 * 60;
	}
	Tuple *notification_1_Second = dict_find(iter, MESSAGE_KEY_Notification_1_Second);
	if(notification_1_Second) {
		settings.notifications[0].second += notification_1_Second->value->int32;
	}
	Tuple *notification_1_OnTimerEnabled = dict_find(iter, MESSAGE_KEY_Notification_1_OnTimerEnabled);
	if(notification_1_OnTimerEnabled) {
		settings.notifications[0].onTimerEnabled = notification_1_OnTimerEnabled->value->int32 == 1;
	}
	Tuple *notification_1_VibePatternIndex = dict_find(iter, MESSAGE_KEY_Notification_1_VibePatternIndex);
	if(notification_1_VibePatternIndex) {
		settings.notifications[0].vibePatternIndex = atoi(notification_1_VibePatternIndex->value->cstring);
	}
	Tuple *notification_1_StateMessage = dict_find(iter, MESSAGE_KEY_Notification_1_StateMessage);
	if(notification_1_StateMessage) {
		settings.notifications[0].stateMessage = notification_1_StateMessage->value->cstring;
	}

	Tuple *notification_2_Minute = dict_find(iter, MESSAGE_KEY_Notification_2_Minute);
	if(notification_2_Minute) {
		settings.notifications[1].second = notification_2_Minute->value->int32 * 60;
	}
	Tuple *notification_2_Second = dict_find(iter, MESSAGE_KEY_Notification_2_Second);
	if(notification_2_Second) {
		settings.notifications[1].second += notification_2_Second->value->int32;
	}
	Tuple *notification_2_OnTimerEnabled = dict_find(iter, MESSAGE_KEY_Notification_2_OnTimerEnabled);
	if(notification_2_OnTimerEnabled) {
		settings.notifications[1].onTimerEnabled = notification_2_OnTimerEnabled->value->int32 == 1;
	}
	Tuple *notification_2_VibePatternIndex = dict_find(iter, MESSAGE_KEY_Notification_2_VibePatternIndex);
	if(notification_2_VibePatternIndex) {
		settings.notifications[1].vibePatternIndex = atoi(notification_2_VibePatternIndex->value->cstring);
	}
	Tuple *notification_2_StateMessage = dict_find(iter, MESSAGE_KEY_Notification_2_StateMessage);
	if(notification_2_StateMessage) {
		settings.notifications[1].stateMessage = notification_2_StateMessage->value->cstring;
	}

	Tuple *notification_3_Minute = dict_find(iter, MESSAGE_KEY_Notification_3_Minute);
	if(notification_3_Minute) {
		settings.notifications[2].second = notification_3_Minute->value->int32 * 60;
	}
	Tuple *notification_3_Second = dict_find(iter, MESSAGE_KEY_Notification_3_Second);
	if(notification_3_Second) {
		settings.notifications[2].second += notification_3_Second->value->int32;
	}
	Tuple *notification_3_OnTimerEnabled = dict_find(iter, MESSAGE_KEY_Notification_3_OnTimerEnabled);
	if(notification_3_OnTimerEnabled) {
		settings.notifications[2].onTimerEnabled = notification_3_OnTimerEnabled->value->int32 == 1;
	}
	Tuple *notification_3_VibePatternIndex = dict_find(iter, MESSAGE_KEY_Notification_3_VibePatternIndex);
	if(notification_3_VibePatternIndex) {
		settings.notifications[2].vibePatternIndex = atoi(notification_3_VibePatternIndex->value->cstring);
	}
	Tuple *notification_3_StateMessage = dict_find(iter, MESSAGE_KEY_Notification_3_StateMessage);
	if(notification_3_StateMessage) {
		settings.notifications[2].stateMessage = notification_3_StateMessage->value->cstring;
	}

	Tuple *notification_4_Minute = dict_find(iter, MESSAGE_KEY_Notification_4_Minute);
	if(notification_4_Minute) {
		settings.notifications[3].second = notification_4_Minute->value->int32 * 60;
	}
	Tuple *notification_4_Second = dict_find(iter, MESSAGE_KEY_Notification_4_Second);
	if(notification_4_Second) {
		settings.notifications[3].second += notification_4_Second->value->int32;
	}
	Tuple *notification_4_OnTimerEnabled = dict_find(iter, MESSAGE_KEY_Notification_4_OnTimerEnabled);
	if(notification_4_OnTimerEnabled) {
		settings.notifications[3].onTimerEnabled = notification_4_OnTimerEnabled->value->int32 == 1;
	}
	Tuple *notification_4_VibePatternIndex = dict_find(iter, MESSAGE_KEY_Notification_4_VibePatternIndex);
	if(notification_4_VibePatternIndex) {
		settings.notifications[3].vibePatternIndex = atoi(notification_4_VibePatternIndex->value->cstring);
	}
	Tuple *notification_4_StateMessage = dict_find(iter, MESSAGE_KEY_Notification_4_StateMessage);
	if(notification_4_StateMessage) {
		settings.notifications[3].stateMessage = notification_4_StateMessage->value->cstring;
	}

	Tuple *notification_5_Minute = dict_find(iter, MESSAGE_KEY_Notification_5_Minute);
	if(notification_5_Minute) {
		settings.notifications[4].second = notification_5_Minute->value->int32 * 60;
	}
	Tuple *notification_5_Second = dict_find(iter, MESSAGE_KEY_Notification_5_Second);
	if(notification_5_Second) {
		settings.notifications[4].second += notification_5_Second->value->int32;
	}
	Tuple *notification_5_OnTimerEnabled = dict_find(iter, MESSAGE_KEY_Notification_5_OnTimerEnabled);
	if(notification_5_OnTimerEnabled) {
		settings.notifications[4].onTimerEnabled = notification_5_OnTimerEnabled->value->int32 == 1;
	}
	Tuple *notification_5_VibePatternIndex = dict_find(iter, MESSAGE_KEY_Notification_5_VibePatternIndex);
	if(notification_5_VibePatternIndex) {
		settings.notifications[4].vibePatternIndex = atoi(notification_5_VibePatternIndex->value->cstring);
	}
	Tuple *notification_5_StateMessage = dict_find(iter, MESSAGE_KEY_Notification_5_StateMessage);
	if(notification_5_StateMessage) {
		settings.notifications[4].stateMessage = notification_5_StateMessage->value->cstring;
	}

	Tuple *notification_6_Minute = dict_find(iter, MESSAGE_KEY_Notification_6_Minute);
	if(notification_6_Minute) {
		settings.notifications[5].second = notification_6_Minute->value->int32 * 60;
	}
	Tuple *notification_6_Second = dict_find(iter, MESSAGE_KEY_Notification_6_Second);
	if(notification_6_Second) {
		settings.notifications[5].second += notification_6_Second->value->int32;
	}
	Tuple *notification_6_OnTimerEnabled = dict_find(iter, MESSAGE_KEY_Notification_6_OnTimerEnabled);
	if(notification_6_OnTimerEnabled) {
		settings.notifications[5].onTimerEnabled = notification_6_OnTimerEnabled->value->int32 == 1;
	}
	Tuple *notification_6_VibePatternIndex = dict_find(iter, MESSAGE_KEY_Notification_6_VibePatternIndex);
	if(notification_6_VibePatternIndex) {
		settings.notifications[5].vibePatternIndex = atoi(notification_6_VibePatternIndex->value->cstring);
	}
	Tuple *notification_6_StateMessage = dict_find(iter, MESSAGE_KEY_Notification_6_StateMessage);
	if(notification_6_StateMessage) {
		settings.notifications[5].stateMessage = notification_6_StateMessage->value->cstring;
	}

	Tuple *notification_7_Minute = dict_find(iter, MESSAGE_KEY_Notification_7_Minute);
	if(notification_7_Minute) {
		settings.notifications[6].second = notification_7_Minute->value->int32 * 60;
	}
	Tuple *notification_7_Second = dict_find(iter, MESSAGE_KEY_Notification_7_Second);
	if(notification_7_Second) {
		settings.notifications[6].second += notification_7_Second->value->int32;
	}
	Tuple *notification_7_OnTimerEnabled = dict_find(iter, MESSAGE_KEY_Notification_7_OnTimerEnabled);
	if(notification_7_OnTimerEnabled) {
		settings.notifications[6].onTimerEnabled = notification_7_OnTimerEnabled->value->int32 == 1;
	}
	Tuple *notification_7_VibePatternIndex = dict_find(iter, MESSAGE_KEY_Notification_7_VibePatternIndex);
	if(notification_7_VibePatternIndex) {
		settings.notifications[6].vibePatternIndex = atoi(notification_7_VibePatternIndex->value->cstring);
	}
	Tuple *notification_7_StateMessage = dict_find(iter, MESSAGE_KEY_Notification_7_StateMessage);
	if(notification_7_StateMessage) {
		settings.notifications[6].stateMessage = notification_7_StateMessage->value->cstring;
	}

	Tuple *notification_8_Minute = dict_find(iter, MESSAGE_KEY_Notification_8_Minute);
	if(notification_8_Minute) {
		settings.notifications[7].second = notification_8_Minute->value->int32 * 60;
	}
	Tuple *notification_8_Second = dict_find(iter, MESSAGE_KEY_Notification_8_Second);
	if(notification_8_Second) {
		settings.notifications[7].second += notification_8_Second->value->int32;
	}
	Tuple *notification_8_OnTimerEnabled = dict_find(iter, MESSAGE_KEY_Notification_8_OnTimerEnabled);
	if(notification_8_OnTimerEnabled) {
		settings.notifications[7].onTimerEnabled = notification_8_OnTimerEnabled->value->int32 == 1;
	}
	Tuple *notification_8_VibePatternIndex = dict_find(iter, MESSAGE_KEY_Notification_8_VibePatternIndex);
	if(notification_8_VibePatternIndex) {
		settings.notifications[7].vibePatternIndex = atoi(notification_8_VibePatternIndex->value->cstring);
	}
	Tuple *notification_8_StateMessage = dict_find(iter, MESSAGE_KEY_Notification_8_StateMessage);
	if(notification_8_StateMessage) {
		settings.notifications[7].stateMessage = notification_8_StateMessage->value->cstring;
	}

	Tuple *notification_9_Minute = dict_find(iter, MESSAGE_KEY_Notification_9_Minute);
	if(notification_9_Minute) {
		settings.notifications[8].second = notification_9_Minute->value->int32 * 60;
	}
	Tuple *notification_9_Second = dict_find(iter, MESSAGE_KEY_Notification_9_Second);
	if(notification_9_Second) {
		settings.notifications[8].second += notification_9_Second->value->int32;
	}
	Tuple *notification_9_OnTimerEnabled = dict_find(iter, MESSAGE_KEY_Notification_9_OnTimerEnabled);
	if(notification_9_OnTimerEnabled) {
		settings.notifications[8].onTimerEnabled = notification_9_OnTimerEnabled->value->int32 == 1;
	}
	Tuple *notification_9_VibePatternIndex = dict_find(iter, MESSAGE_KEY_Notification_9_VibePatternIndex);
	if(notification_9_VibePatternIndex) {
		settings.notifications[8].vibePatternIndex = atoi(notification_9_VibePatternIndex->value->cstring);
	}
	Tuple *notification_9_StateMessage = dict_find(iter, MESSAGE_KEY_Notification_9_StateMessage);
	if(notification_9_StateMessage) {
		settings.notifications[8].stateMessage = notification_9_StateMessage->value->cstring;
	}

  // Save the new settings to persistent storage
  saveSettings();
}


void initSettings(void) {
	//APP_LOG(APP_LOG_LEVEL_DEBUG, "init settings");
	loadSettings();
	//deleteSettings();

	// Listen for AppMessages
	app_message_register_inbox_received(inboxReceivedHandler);
	app_message_open(1024, 1024);
}

bool isVibesEnabled(void) {
	return settings.vibesEnabled;
}

bool invertVibesEnabled(void) {
	settings.vibesEnabled = !settings.vibesEnabled;
	saveSettings();
	return settings.vibesEnabled;
}

bool isVibesOnNotificationsEnabled(void) {
	return (settings.vibesEnabled && settings.vibesOnNotificationsEnabled);
}

bool isVibeOnTapEnabled(void) {
	return settings.vibesOnTapEnabled;
}

const VibePattern *getVibesOnTimerExpiredPattern(void) {
	if(settings.vibesEnabled) {
		return VIBE_PATTERNS[settings.notificationTimerExpired.vibePatternIndex];
	}
	return NULL;
}

const VibePattern *getOnButtonPressedVibePattern(void) {
	if(settings.vibesEnabled) {
		return VIBE_PATTERNS[settings.vibesOnButtonPressedPatternIndex];
	}
	return NULL;
}

bool invertVibesOnButtonPressedEnabled(void) {
	if(settings.vibesOnButtonPressedPatternIndex > VIBE_OFF_PATTERN_INDEX) {
		settings.vibesOnButtonPressedPatternIndex = VIBE_OFF_PATTERN_INDEX;
	} else {
		settings.vibesOnButtonPressedPatternIndex = VIBE_DEFAULT_INDEX;
	}
	saveSettings();
	return (settings.vibesOnButtonPressedPatternIndex > VIBE_OFF_PATTERN_INDEX);
}

const VibePattern *getOnButtonStartsTimerVibePattern(void) {
	if(settings.vibesEnabled) {
		if(settings.vibesOnButtonStartsTimerPatternIndex > VIBE_OFF_PATTERN_INDEX) {
			return VIBE_PATTERNS[settings.vibesOnButtonStartsTimerPatternIndex];
		}
	}
	return NULL;
}

const VibePattern *getOnButtonStopsTimerVibePattern(void) {
	if(settings.vibesEnabled) {
		if(settings.vibesOnButtonStopsTimerPatternIndex > VIBE_OFF_PATTERN_INDEX) {
			return VIBE_PATTERNS[settings.vibesOnButtonStopsTimerPatternIndex];
		}
	}
	return NULL;
}

const VibePattern *getOnButtonSetsStartOnReadyVibePattern(void) {
	if(settings.vibesEnabled) {
		if(settings.vibesOnButtonSetsStartOnReadyPatternIndex > VIBE_OFF_PATTERN_INDEX) {
			return VIBE_PATTERNS[settings.vibesOnButtonSetsStartOnReadyPatternIndex];
		}
	}
	return NULL;	
}

const VibePattern *getOnButtonSetsStartOnSnapVibePattern(void) {
	if(settings.vibesEnabled) {
		if(settings.vibesOnButtonSetsStartOnSnapPatternIndex > VIBE_OFF_PATTERN_INDEX) {
			return VIBE_PATTERNS[settings.vibesOnButtonSetsStartOnSnapPatternIndex];
		}
	}
	return NULL;	
}

const Notification *getNotification(int second) {
	if(second >= 120 && second <= settings.notification2MinWarning.second && settings.notification2MinWarning.onTimerEnabled) {
		if(second > 120) {
			return &NOTIFICATION_COUNTDOWN;
		}
		return &settings.notification2MinWarning;
	}
	if(second <= settings.notificationTimerExpired.second && settings.notificationTimerExpired.onTimerEnabled) {
		if(second > 0) {
			return &NOTIFICATION_COUNTDOWN;
		}
		return &settings.notificationTimerExpired;
	}
	for(int i = 0; i < NOTIFICATION_MAX; i++) {
		if(settings.notifications[i].second == second && settings.notifications[i].onTimerEnabled) {
			return &settings.notifications[i];
		}
	}
	return NULL;
}

const VibePattern *getVibesNotificationPattern(const Notification *notification) {
	if(notification != NULL && settings.vibesEnabled && settings.vibesOnNotificationsEnabled) {
		return VIBE_PATTERNS[notification->vibePatternIndex];
	}
	return NULL;
}

char *getNotificationStateMessage(const Notification *notification) {
	if(notification != NULL) {
		return notification->stateMessage;
	}
	return NULL;
}

int incrementTimerStartValue(void) {
	if(settings.timerStartValue < TIMER_START_VALUE_MAX) {
		settings.timerStartValue += 60;
		saveSettings();
	}
	return settings.timerStartValue;	
}

int decrementTimerStartValue(void) {
	if(settings.timerStartValue > TIMER_START_VALUE_MIN) {
		settings.timerStartValue -= 60;
		saveSettings();
	}
	return settings.timerStartValue;
}

int getTimerStartValue(void) {
	return settings.timerStartValue;
}

int getTimerIncreaseStep(void) {
	return settings.timerIncreaseStep;
}

int getTimerDecreaseStep(void) {
	return settings.timerDecreaseStep;
}

int getButtonPressedLongDuration(void) {
	return BUTTON_LONG_PRESSED_DURATION_DEFAULT;
}

GColor getBackgroundColor(void) {
	return COLOR_BGCOLOR_DEFAULT;
}

GColor getForegroundColor(void) {
	return COLOR_FORECOLOR_DEFAULT;
}

uint32_t getStartIconResourceID(void) {
	return (gcolor_equal(getBackgroundColor(), GColorBlack) ? RESOURCE_ID_IMAGE_START_WHITE : RESOURCE_ID_IMAGE_START_BLACK);
}

uint32_t getStopIconResourceID(void) {
	return (gcolor_equal(getBackgroundColor(), GColorBlack) ? RESOURCE_ID_IMAGE_STOP_WHITE : RESOURCE_ID_IMAGE_STOP_BLACK);
}

char *getStateMessageVibesOn(void) {
	return STATE_MSG_VIBRATION_ON;
}

char *getStateMessageVibesOff(void) {
	return STATE_MSG_VIBRATION_OFF;
}

char *getStateMessageVibesOnButtonPressedOn(void) {
	return STATE_MSG_VIBRATION_BUTTON_ON;
}

char *getStateMessageVibesOnButtonPressedOff(void) {
	return STATE_MSG_VIBRATION_BUTTON_OFF;
}

char *getStateMessageStartOnReady(void) {
	return STATE_MSG_START_ON_READY;
}

char *getStateMessageStartOnSnap(void) {
	return STATE_MSG_START_ON_SNAP;
}

char *getStateMessageTurboMode(void) {
	return STATE_MSG_TURBO_MODE;
}
