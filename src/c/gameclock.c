#include <pebble.h>

#include "main.h"
#include "gameclock.h"
#include "settings.h"

static TextLayer *layerHeadline; // Layer for displaying headline
static TextLayer *layerCountdown; // Layer for displaying countdown
static TextLayer *layerState; // Layer for displaying state or messages
static BitmapLayer *layerButtonUp; // Layer for up-button description
static GBitmap *bitmapButtonUp = NULL;
// static TextLayer *layerButtonSelect; // Layer for select-button description
static BitmapLayer *layerButtonDown; // Layer for down-button description
static GBitmap *bitmapButtonDown = NULL;
static ActionBarLayer *layerActionBar;

static Timer timer;
static int timerCountdownStep = TIMER_COUNTDOWN_STEP_DEFAULT; // how many seconds are substracted by a single second tick (turbo-mode!)

static void handleSecondTick(struct tm *, TimeUnits);

static void vibrate(const VibePattern *pattern) {
	if(pattern != NULL) {
//APP_LOG(APP_LOG_LEVEL_DEBUG, "vibrate");
		vibes_enqueue_custom_pattern(*pattern);
	}
}

// TODO: implement motion sensor (accelerometer) with regard to settings
// https://developer.pebble.com/guides/events-and-services/accelerometer/

static void setTimer(const TimerInfo *newTimerInfo) {
	if(timer.info->state == STATE_RUNNING && newTimerInfo->state != STATE_RUNNING) {
		tick_timer_service_unsubscribe();
	} else if(timer.info->state != STATE_RUNNING && newTimerInfo->state == STATE_RUNNING) {
		tick_timer_service_subscribe(SECOND_UNIT, handleSecondTick);
	}
	timer.info = newTimerInfo;
	timer.stateMessage = timer.info->stateMessage;
	seconds2Time(timer.value, timer.valueDisplay);
	text_layer_set_text(layerCountdown, timer.valueDisplay);
	text_layer_set_text(layerState, timer.stateMessage);
}

static void decrementTimer(int step) {
	timer.value -= step;
	if(timer.value > 0) {
		seconds2Time(timer.value, timer.valueDisplay);
		text_layer_set_text(layerCountdown, timer.valueDisplay);
		const Notification *notification = getNotification(timer.value);
		if(notification != NULL) {
			vibrate(getVibesNotificationPattern(notification));
			char *stateMessage = getNotificationStateMessage(notification);
			if(stateMessage != NULL && stateMessage[0] != '\0') {
				timer.stateMessage = stateMessage;
				text_layer_set_text(layerState, timer.stateMessage);
			}
		}
	} else {
		vibrate(getVibesOnTimerExpiredPattern());
		timerCountdownStep = TIMER_COUNTDOWN_STEP_DEFAULT;
		timer.value = 0;
		setTimer(&TIMER_EXPIRED);
	}
}

static void incrementTimer(int step) {
	decrementTimer(step * -1);
}

// Event occurs on tap / shake
static void handleTap(AccelAxisType axis, int32_t direction) {
  if(timer.info->state == STATE_STOPPED) {
		vibrate(getOnButtonStopsTimerVibePattern());
	} else if(timer.info->state == STATE_RUNNING) {
		vibrate(getOnButtonStartsTimerVibePattern());
	}
}

// Event occurs every second
static void handleSecondTick(struct tm *t, TimeUnits unitsChanged) {
	decrementTimer(timerCountdownStep);
}

static void onUpClick(ClickRecognizerRef recognizer, void *context) {
	if(timer.info->state == STATE_STANDBY || timer.info->state == STATE_STOPPED) {
		vibrate(getOnButtonStartsTimerVibePattern());
		setTimer(&TIMER_RUNNING);
	} // else: button is disabled in all other states
}

static void onUpLongClick(ClickRecognizerRef recognizer, void *context) {
	if(timer.info->state == STATE_STOPPED) {
		vibrate(getOnButtonPressedVibePattern());
		incrementTimer(getTimerIncreaseStep());
	} else if(timer.info->state == STATE_STANDBY) {
		vibrate(getOnButtonPressedVibePattern());
		timerCountdownStep = TIMER_COUNTDOWN_STEP_DEFAULT;
		timer.value = incrementTimerStartValue();
		setTimer(&TIMER_STANDBY);
	} // else: button is disabled in all other states
}

static void onSelectClick(ClickRecognizerRef recognizer, void *context) {
	if(timer.info->state == STATE_STANDBY) {
		vibrate(getOnButtonPressedVibePattern());
		timerCountdownStep = TIMER_COUNTDOWN_STEP_DEFAULT;
		if(invertVibesEnabled()) {
			timer.stateMessage = getStateMessageVibesOn();
		} else {
			timer.stateMessage = getStateMessageVibesOff();
		}
		text_layer_set_text(layerState, timer.stateMessage);
	} else if(timer.info->state == STATE_STOPPED) {
		if(strcmp(timer.stateMessage, getStateMessageStartOnSnap()) == 0) {
			vibrate(getOnButtonSetsStartOnReadyVibePattern());
			timer.stateMessage = getStateMessageStartOnReady();
		} else {
			vibrate(getOnButtonSetsStartOnSnapVibePattern());
			timer.stateMessage = getStateMessageStartOnSnap();
		}
		text_layer_set_text(layerState, timer.stateMessage);
	} else if(timer.info->state == STATE_EXPIRED) {
		vibrate(getOnButtonPressedVibePattern());
		timerCountdownStep = TIMER_COUNTDOWN_STEP_DEFAULT;
		timer.value = getTimerStartValue();
		setTimer(&TIMER_STANDBY);
	} // else: button is disabled in all other states
}

static void onSelectLongClick(ClickRecognizerRef recognizer, void *context) {
	if(timer.info->state == STATE_STANDBY) {
		vibrate(getOnButtonPressedVibePattern());
		if(strcmp(timer.stateMessage, getStateMessageTurboMode()) != 0) {
			timer.stateMessage = getStateMessageTurboMode();
			timerCountdownStep = TIMER_COUNTDOWN_STEP_TURBO;
			text_layer_set_text(layerState, timer.stateMessage);
		} else {
			timerCountdownStep = TIMER_COUNTDOWN_STEP_DEFAULT;
			setTimer(&TIMER_STANDBY);
		}
	} else if(timer.info->state == STATE_STOPPED) {
		vibrate(getOnButtonPressedVibePattern());
		timer.value = getTimerStartValue();
		setTimer(&TIMER_STANDBY);
	} // else: button is disabled in all other states
}

static void onDownClick(ClickRecognizerRef recognizer, void *context) {
	if(timer.info->state == STATE_RUNNING) {
		vibrate(getOnButtonStopsTimerVibePattern());
		setTimer(&TIMER_STOPPED);
	} // else: button is disabled in all other states
}

static void onDownLongClick(ClickRecognizerRef recognizer, void *context) {
	if(timer.info->state == STATE_STOPPED) {
		vibrate(getOnButtonPressedVibePattern());
		decrementTimer(getTimerDecreaseStep());
	} else if(timer.info->state == STATE_STANDBY) {
		vibrate(getOnButtonPressedVibePattern());
		timerCountdownStep = TIMER_COUNTDOWN_STEP_DEFAULT;
		timer.value = decrementTimerStartValue();
		setTimer(&TIMER_STANDBY);
	} // else: button is disabled in all other states
}

void appClickConfigProvider(void *context) {
  window_single_click_subscribe(BUTTON_ID_UP, onUpClick);
	window_long_click_subscribe(BUTTON_ID_UP, getButtonPressedLongDuration(), onUpLongClick, NULL);
  window_single_click_subscribe(BUTTON_ID_SELECT, onSelectClick);
	window_long_click_subscribe(BUTTON_ID_SELECT, getButtonPressedLongDuration(), onSelectLongClick, NULL);
  window_single_click_subscribe(BUTTON_ID_DOWN, onDownClick);
	window_long_click_subscribe(BUTTON_ID_DOWN, getButtonPressedLongDuration(), onDownLongClick, NULL);
}

void appDrawCanvasGraphics(Layer *layer, GContext *ctx) {
  graphics_context_set_stroke_color(ctx, getForegroundColor());
  graphics_context_set_fill_color(ctx, getForegroundColor());
  graphics_context_set_stroke_width(ctx, 2);
	graphics_context_set_antialiased(ctx, false);

	graphics_draw_line(ctx, GPoint(0, MSG_BOX_HEIGHT(windowHeight)), GPoint(MSG_BOX_WIDTH(windowWidth), MSG_BOX_HEIGHT(windowHeight)));
	graphics_draw_line(ctx, GPoint(BTN_DESC_X_LEFT(windowWidth), 0), GPoint(BTN_DESC_X_LEFT(windowWidth), windowHeight));
	graphics_draw_line(ctx, GPoint(BTN_DESC_X_LEFT(windowWidth), BTN_DESC_HEIGHT(windowHeight)), GPoint(windowWidth, BTN_DESC_HEIGHT(windowHeight)));
	graphics_draw_line(ctx, GPoint(BTN_DESC_X_LEFT(windowWidth), windowHeight-(BTN_DESC_HEIGHT(windowHeight))), GPoint(windowWidth, windowHeight-(BTN_DESC_HEIGHT(windowHeight))));
	graphics_draw_line(ctx, GPoint(0, windowHeight-MSG_BOX_HEIGHT(windowHeight)), GPoint(MSG_BOX_WIDTH(windowWidth), windowHeight-MSG_BOX_HEIGHT(windowHeight)));
}

void updateGUI() {
	window_set_background_color(window, getBackgroundColor());

	// Update headline
	text_layer_set_text_color(layerHeadline, getForegroundColor());
	text_layer_set_text(layerHeadline, TEXT_HEADLINE);

	// Update description of buttons
	if(bitmapButtonUp != NULL) {
		gbitmap_destroy(bitmapButtonUp);
	}
	bitmapButtonUp = gbitmap_create_with_resource(getStartIconResourceID());
	bitmap_layer_set_bitmap(layerButtonUp, bitmapButtonUp);

	if(bitmapButtonDown != NULL) {
		gbitmap_destroy(bitmapButtonDown);
	}
	bitmapButtonDown = gbitmap_create_with_resource(getStopIconResourceID());
	bitmap_layer_set_bitmap(layerButtonDown, bitmapButtonDown);
	
	// Update countdown
	text_layer_set_text_color(layerCountdown, getForegroundColor());
	
	// Update state
	text_layer_set_text_color(layerState, getForegroundColor());
	
	// Update timer
	timer.value = getTimerStartValue();
	setTimer(&TIMER_STANDBY);
}

void appLoad(Window *window) {
	GFont basicFont = fonts_get_system_font(FONT_DEFAULT);
  //GFont timerFont = fonts_get_system_font(FONT_TICKER);
	GFont timerFont = fonts_load_custom_font(resource_get_handle(FONT_TICKER));

	// Initialize headline
	layerHeadline = text_layer_create(GRect(0, ((MSG_BOX_HEIGHT(windowHeight)-FONT_DEFAULT_SIZE)/2)+MSG_BOX_LAYER_Y_CORRECTION(windowHeight), MSG_BOX_WIDTH(windowWidth)-MSG_BOX_LAYER_X_CORRECTION(windowWidth), FONT_DEFAULT_SIZE)); 
	text_layer_set_background_color(layerHeadline, GColorClear);	
	text_layer_set_font(layerHeadline, basicFont);
	text_layer_set_text_alignment(layerHeadline, PBL_IF_RECT_ELSE(GTextAlignmentCenter, GTextAlignmentRight));	
	layer_add_child(layerWindow, text_layer_get_layer(layerHeadline));

	// Initialize description of buttons
	layerButtonUp = bitmap_layer_create(GRect(BTN_DESC_X_LEFT(windowWidth)+2, BTN_DESC_Y_TOP(windowHeight)+BTN_DESC_LAYER_Y_CORRECTION(windowHeight), BTN_DESC_WIDTH(windowWidth)-2, FONT_DEFAULT_SIZE));
	bitmap_layer_set_compositing_mode(layerButtonUp, GCompOpSet);
	layer_add_child(layerWindow, bitmap_layer_get_layer(layerButtonUp));

	layerButtonDown = bitmap_layer_create(GRect(BTN_DESC_X_LEFT(windowWidth)+2, windowHeight-BTN_DESC_Y_TOP(windowHeight)-BTN_DESC_LAYER_Y_CORRECTION(windowHeight), BTN_DESC_WIDTH(windowWidth)-2, FONT_DEFAULT_SIZE));
	bitmap_layer_set_compositing_mode(layerButtonDown, GCompOpSet);
	layer_add_child(layerWindow, bitmap_layer_get_layer(layerButtonDown));

	// Initialize countdown
  layerCountdown = text_layer_create(GRect(0, (windowHeight/2)-(FONT_TICKER_SIZE/2), windowWidth-BTN_DESC_WIDTH(windowWidth), FONT_TICKER_SIZE)); 
	text_layer_set_background_color(layerCountdown, GColorClear);
	text_layer_set_font(layerCountdown, timerFont);
	text_layer_set_text_alignment(layerCountdown, GTextAlignmentCenter);
  layer_add_child(layerWindow, text_layer_get_layer(layerCountdown));

	// Initialize state
	layerState = text_layer_create(GRect(0, windowHeight-((MSG_BOX_HEIGHT(windowHeight)+FONT_DEFAULT_SIZE)/2)-MSG_BOX_LAYER_Y_CORRECTION(windowHeight), MSG_BOX_WIDTH(windowWidth)-MSG_BOX_LAYER_X_CORRECTION(windowWidth), FONT_DEFAULT_SIZE)); 
	text_layer_set_background_color(layerState, GColorClear);
	text_layer_set_font(layerState, basicFont);
	text_layer_set_text_alignment(layerState, PBL_IF_RECT_ELSE(GTextAlignmentCenter, GTextAlignmentRight));	
	layer_add_child(layerWindow, text_layer_get_layer(layerState));

	// Initialize timer
	timer.info = &TIMER_STANDBY;
	if(timer.valueDisplay == NULL) {
		timer.valueDisplay = malloc(sizeof(char) * 6);
	}
	
	// Initialize settings
	initSettings();

	// Initialize GUI
	updateGUI();

	// Subscribe to tap events
	if(isVibeOnTapEnabled()) {
		accel_tap_service_subscribe(handleTap);
	}
}

void appUnload(Window *window) {
	text_layer_destroy(layerHeadline);
	text_layer_destroy(layerCountdown);
	text_layer_destroy(layerState);
	gbitmap_destroy(bitmapButtonUp);
	bitmap_layer_destroy(layerButtonUp);
	gbitmap_destroy(bitmapButtonDown);
	bitmap_layer_destroy(layerButtonDown);
	action_bar_layer_destroy(layerActionBar);

	// Unsubscribe from tap events
	if(isVibeOnTapEnabled()) {
		accel_tap_service_unsubscribe();
	}
}
