module.exports = [
  {
    "type": "heading",
    "defaultValue": "GAMECLOCK Configuration",
  },
  {
    "type": "section",
    "items": [
      {
        "type": "heading",
        "defaultValue": "Global",
      },
			{
        "type": "toggle",
        "messageKey": "VibesEnabled",
        "label": "Enable vibration",
				"description": "If disabled, all other vibration settings are ignored.",
        "defaultValue": true,
      },
      {
        "type": "toggle",
        "messageKey": "VibesOnNotificationsEnabled",
        "label": "Enable vibration on notifications",
				"description": "If disabled, all custom vibration settings for notifications (except expired timer) are ignored.",
        "defaultValue": true,
      },
//			{
//				"type": "toggle",
//				"messageKey": "VibesOnTapEnabled",
//				"label": "Enable vibration for tapping or shaking the watch to get the current state (running / stopped)",
//				"description": "The vibration pattern for state 'running' / 'stopped'' is the same as for starting / stopping the timer.",
//				"defaultValue": true,
//      },
		],
	},
  {
    "type": "section",
    "items": [
      {
        "type": "heading",
        "defaultValue": "Buttons",
      },
			{
				"type": "select",
				"messageKey": "VibesOnButtonPressedPatternIndex",
				"label": "Vibration pattern on pressing a button",
				"description": "If set to 'Off', vibration settings for starting a timer are still active.",
				"defaultValue": "0",
				"options": [
					{ 
						"label": "Off", 
						"value": "0" 
					},
					{ 
						"label": "Short",
						"value": "1" 
					},
					{ 
						"label": "Long",
						"value": "2" 
					},
					{ 
						"label": "2x Short",
						"value": "3" 
					},
					{ 
						"label": "Short + Long",
						"value": "4" 
					},
					{ 
						"label": "Long + Short",
						"value": "5" 
					},
					{ 
						"label": "2x Long",
						"value": "6" 
					},
					{ 
						"label": "3x Short",
						"value": "7" 
					},
				],
			},
			{
				"type": "select",
				"messageKey": "VibesOnButtonStartsTimerPatternIndex",
				"label": 'Vibration pattern on pressing a button to start the timer',
				"description": "If set to 'Off', a vibration for pressing a button may occur.",
				"defaultValue": "3",
				"options": [
					{ 
						"label": "Off", 
						"value": "0" 
					},
					{ 
						"label": "Short",
						"value": "1" 
					},
					{ 
						"label": "Long",
						"value": "2" 
					},
					{ 
						"label": "2x Short",
						"value": "3" 
					},
					{ 
						"label": "Short + Long",
						"value": "4" 
					},
					{ 
						"label": "Long + Short",
						"value": "5" 
					},
					{ 
						"label": "2x Long",
						"value": "6" 
					},
					{ 
						"label": "3x Short",
						"value": "7" 
					},
				],
			},
			{
				"type": "select",
				"messageKey": "VibesOnButtonStopsTimerPatternIndex",
				"label": 'Vibration pattern on pressing a button to stop the timer',
				"description": "If set to 'Off', a vibration for pressing a button may occur.",
				"defaultValue": "1",
				"options": [
					{ 
						"label": "Off", 
						"value": "0" 
					},
					{ 
						"label": "Short",
						"value": "1" 
					},
					{ 
						"label": "Long",
						"value": "2" 
					},
					{ 
						"label": "2x Short",
						"value": "3" 
					},
					{ 
						"label": "Short - Long",
						"value": "4" 
					},
					{ 
						"label": "Long - Short",
						"value": "5" 
					},
					{ 
						"label": "2x Long",
						"value": "6" 
					},
					{ 
						"label": "3x Short",
						"value": "7" 
					},
				],
			},
			{
				"type": "select",
				"messageKey": "VibesOnButtonSetsStartOnReadyPatternIndex",
				"label": 'Vibration pattern on pressing a button to note that the stopped timer next has to be started "on ready"',
				"description": "If set to 'Off', a vibration for pressing a button may occur.",
				"defaultValue": "3",
				"options": [
					{ 
						"label": "Off", 
						"value": "0" 
					},
					{ 
						"label": "Short",
						"value": "1" 
					},
					{ 
						"label": "Long",
						"value": "2" 
					},
					{ 
						"label": "2x Short",
						"value": "3" 
					},
					{ 
						"label": "Short - Long",
						"value": "4" 
					},
					{ 
						"label": "Long - Short",
						"value": "5" 
					},
					{ 
						"label": "2x Long",
						"value": "6" 
					},
					{ 
						"label": "3x Short",
						"value": "7" 
					},
				],
			},
			{
				"type": "select",
				"messageKey": "VibesOnButtonSetsStartOnSnapPatternIndex",
				"label": 'Vibration pattern on pressing a button to note that the stopped timer next has to be started "on snap"',
				"description": "If set to 'Off', a vibration for pressing a button may occur.",
				"defaultValue": "1",
				"options": [
					{ 
						"label": "Off", 
						"value": "0" 
					},
					{ 
						"label": "Short",
						"value": "1" 
					},
					{ 
						"label": "Long",
						"value": "2" 
					},
					{ 
						"label": "2x Short",
						"value": "3" 
					},
					{ 
						"label": "Short - Long",
						"value": "4" 
					},
					{ 
						"label": "Long - Short",
						"value": "5" 
					},
					{ 
						"label": "2x Long",
						"value": "6" 
					},
					{ 
						"label": "3x Short",
						"value": "7" 
					},
				],
			},
    ]
  },
	{
    "type": "section",
    "items": [
      {
        "type": "heading",
        "defaultValue": "Timing",
      },
			{
				"type": "slider",
				"messageKey": "TimerStartValue",
				"label": "The minutes the timer should run (can be overwritten on the watch).",
				"min": 5,
				"max": 30,
				"step": 1,
				"defaultValue": 12,
			},
			{
				"type": "slider",
				"messageKey": "TimerIncreaseStep",
				"label": "The seconds the timer should be increased when the timer has to be adjusted.",
				"min": 1,
				"max": 20,
				"step": 1,
				"defaultValue": 3,
			},
			{
				"type": "slider",
				"messageKey": "TimerDecreaseStep",
				"label": "The seconds the timer should be decreased when the timer has to be adjusted (e.g. for 10 second run-off).",
				"min": 1,
				"max": 20,
				"step": 1,
				"defaultValue": 10,
			},
	  ]
  },
	{
    "type": "section",
    "items": [
      {
        "type": "heading",
        "defaultValue": "2' Warning",
      },
			{
				"type": "select",
				"messageKey": "VibesOn2MinWarningPatternIndex",
				"label": 'Vibration pattern when the timer reaching "02:00"',
				"description": "If set to 'Off', there is notification for the 2' warning.",
				"defaultValue": "6",
				"options": [
					{ 
						"label": "Off", 
						"value": "0" 
					},
					{ 
						"label": "Short",
						"value": "1" 
					},
					{ 
						"label": "Long",
						"value": "2" 
					},
					{ 
						"label": "2x Short",
						"value": "3" 
					},
					{ 
						"label": "Short - Long",
						"value": "4" 
					},
					{ 
						"label": "Long - Short",
						"value": "5" 
					},
					{ 
						"label": "2x Long",
						"value": "6" 
					},
					{ 
						"label": "3x Short",
						"value": "7" 
					},
					{ 
						"label": "2x Long + Short",
						"value": "8" 
					},
					{ 
						"label": "3x Long",
						"value": "9" 
					},
					{ 
						"label": "3x Long + Short",
						"value": "10" 
					},
					{ 
						"label": "4x Long",
						"value": "11" 
					},
					{ 
						"label": "4x Long + Short",
						"value": "12" 
					},
					{ 
						"label": "5x Long",
						"value": "13" 
					},
					{ 
						"label": "Very Long",
						"value": "14" 
					},
				],
			},
			{
				"type": "slider",
				"messageKey": "Notification2MinWarningCountdownValue",
				"label": "The seconds before the 2' warning a countdown should start and vibe every second.",
				"description": "If set to '0', there is no countdown.",
				"min": 0,
				"max": 10,
				"step": 1,
				"defaultValue": 5,
			},
			{
				"type": "input",
				"messageKey": "Notification2MinWarningStateMessage",
				"label": "State message for the 2' warning notification",
				"description": "If left empty, the state message is not changed when this notification occurs.",
				"defaultValue": "2:00 WARNING!",
				"attributes": {
					"placeholder": "eg: WARNING!",
					"limit": 20
				}
			},
	  ]
  },
	{
    "type": "section",
    "items": [
      {
        "type": "heading",
        "defaultValue": "Expired Timer",
      },
			{
				"type": "select",
				"messageKey": "VibesOnTimerExpiredPatternIndex",
				"label": 'Vibration pattern when timer expires, reaching "00:00"',
				"description": "Not affected by the 'Enable vibration on notifications' setting.",
				"defaultValue": "14",
				"options": [
					{ 
						"label": "Off", 
						"value": "0" 
					},
					{ 
						"label": "Short",
						"value": "1" 
					},
					{ 
						"label": "Long",
						"value": "2" 
					},
					{ 
						"label": "2x Short",
						"value": "3" 
					},
					{ 
						"label": "Short - Long",
						"value": "4" 
					},
					{ 
						"label": "Long - Short",
						"value": "5" 
					},
					{ 
						"label": "2x Long",
						"value": "6" 
					},
					{ 
						"label": "3x Short",
						"value": "7" 
					},
					{ 
						"label": "2x Long + Short",
						"value": "8" 
					},
					{ 
						"label": "3x Long",
						"value": "9" 
					},
					{ 
						"label": "3x Long + Short",
						"value": "10" 
					},
					{ 
						"label": "4x Long",
						"value": "11" 
					},
					{ 
						"label": "4x Long + Short",
						"value": "12" 
					},
					{ 
						"label": "5x Long",
						"value": "13" 
					},
					{ 
						"label": "Very Long",
						"value": "14" 
					},
				],
			},
			{
				"type": "slider",
				"messageKey": "NotificationTimerExpiredCountdownValue",
				"label": "The seconds before the timer expires a countdown should start and vibe every second.",
				"description": "If set to '0', there is no countdown.",
				"min": 0,
				"max": 10,
				"step": 1,
				"defaultValue": 5,
			},
	  ]
  },
  {
    "type": "section",
    "items": [
      {
        "type": "heading",
        "defaultValue": "Notification 1"
      },
			{
				"type": "slider",
				"messageKey": "Notification_1_Minute",
				"label": "The minute this notification should occur.",
				"min": 0,
				"max": 20,
				"step": 1,
				"defaultValue": 5,
			},
			{
				"type": "slider",
				"messageKey": "Notification_1_Second",
				"label": "The second this notification should occur.",
				"min": 0,
				"max": 59,
				"step": 1,
				"defaultValue": 0,
			},
      {
        "type": "toggle",
        "messageKey": "Notification_1_OnTimerEnabled",
        "label": 'Enable this notification.',
        "defaultValue": true,
      },
			{
				"type": "select",
				"messageKey": "Notification_1_VibePatternIndex",
				"label": "Vibration pattern for this notification",
				"defaultValue": "13",
				"options": [
					{ 
						"label": "Off", 
						"value": "0" 
					},
					{ 
						"label": "Short",
						"value": "1" 
					},
					{ 
						"label": "Long",
						"value": "2" 
					},
					{ 
						"label": "2x Short",
						"value": "3" 
					},
					{ 
						"label": "Short - Long",
						"value": "4" 
					},
					{ 
						"label": "Long - Short",
						"value": "5" 
					},
					{ 
						"label": "2x Long",
						"value": "6" 
					},
					{ 
						"label": "3x Short",
						"value": "7" 
					},
					{ 
						"label": "2x Long + Short",
						"value": "8" 
					},
					{ 
						"label": "3x Long",
						"value": "9" 
					},
					{ 
						"label": "3x Long + Short",
						"value": "10" 
					},
					{ 
						"label": "4x Long",
						"value": "11" 
					},
					{ 
						"label": "4x Long + Short",
						"value": "12" 
					},
					{ 
						"label": "5x Long",
						"value": "13" 
					},
					{ 
						"label": "Very Long",
						"value": "14" 
					},
				],
			},
			{
				"type": "input",
				"messageKey": "Notification_1_StateMessage",
				"label": "State message for this notification",
				"description": "If left empty, the state message is not changed when this notification occurs.",
        "defaultValue": "5:00 WARNING!",
				"attributes": {
					"placeholder": "eg: WARNING!",
					"limit": 20
				}
			},
		]
  },
  {
    "type": "section",
    "items": [
      {
        "type": "heading",
        "defaultValue": "Notification 2"
      },
			{
				"type": "slider",
				"messageKey": "Notification_2_Minute",
				"label": "The minute this notification should occur.",
				"min": 0,
				"max": 20,
				"step": 1,
				"defaultValue": 4,
			},
			{
				"type": "slider",
				"messageKey": "Notification_2_Second",
				"label": "The second this notification should occur.",
				"min": 0,
				"max": 59,
				"step": 1,
				"defaultValue": 30,
			},
      {
        "type": "toggle",
        "messageKey": "Notification_2_OnTimerEnabled",
        "label": 'Enable this notification.',
        "defaultValue": false,
      },
			{
				"type": "select",
				"messageKey": "Notification_2_VibePatternIndex",
				"label": "Vibration pattern for this notification",
				"defaultValue": "12",
				"options": [
					{ 
						"label": "Off", 
						"value": "0" 
					},
					{ 
						"label": "Short",
						"value": "1" 
					},
					{ 
						"label": "Long",
						"value": "2" 
					},
					{ 
						"label": "2x Short",
						"value": "3" 
					},
					{ 
						"label": "Short - Long",
						"value": "4" 
					},
					{ 
						"label": "Long - Short",
						"value": "5" 
					},
					{ 
						"label": "2x Long",
						"value": "6" 
					},
					{ 
						"label": "3x Short",
						"value": "7" 
					},
					{ 
						"label": "2x Long + Short",
						"value": "8" 
					},
					{ 
						"label": "3x Long",
						"value": "9" 
					},
					{ 
						"label": "3x Long + Short",
						"value": "10" 
					},
					{ 
						"label": "4x Long",
						"value": "11" 
					},
					{ 
						"label": "4x Long + Short",
						"value": "12" 
					},
					{ 
						"label": "5x Long",
						"value": "13" 
					},
					{ 
						"label": "Very Long",
						"value": "14" 
					},
				],
			},
			{
				"type": "input",
				"messageKey": "Notification_2_StateMessage",
				"label": "State message for this notification",
				"description": "If left empty, the state message is not changed when this notification occurs.",
        "defaultValue": "4:30 WARNING!",
				"attributes": {
					"placeholder": "eg: WARNING!",
					"limit": 20
				}
			},
		]
  },
  {
    "type": "section",
    "items": [
      {
        "type": "heading",
        "defaultValue": "Notification 3"
      },
			{
				"type": "slider",
				"messageKey": "Notification_3_Minute",
				"label": "The minute this notification should occur.",
				"min": 0,
				"max": 20,
				"step": 1,
				"defaultValue": 4,
			},
			{
				"type": "slider",
				"messageKey": "Notification_3_Second",
				"label": "The second this notification should occur.",
				"min": 0,
				"max": 59,
				"step": 1,
				"defaultValue": 0,
			},
      {
        "type": "toggle",
        "messageKey": "Notification_3_OnTimerEnabled",
        "label": 'Enable this notification.',
        "defaultValue": true,
      },
			{
				"type": "select",
				"messageKey": "Notification_3_VibePatternIndex",
				"label": "Vibration pattern for this notification",
				"defaultValue": "11",
				"options": [
					{ 
						"label": "Off", 
						"value": "0" 
					},
					{ 
						"label": "Short",
						"value": "1" 
					},
					{ 
						"label": "Long",
						"value": "2" 
					},
					{ 
						"label": "2x Short",
						"value": "3" 
					},
					{ 
						"label": "Short - Long",
						"value": "4" 
					},
					{ 
						"label": "Long - Short",
						"value": "5" 
					},
					{ 
						"label": "2x Long",
						"value": "6" 
					},
					{ 
						"label": "3x Short",
						"value": "7" 
					},
					{ 
						"label": "2x Long + Short",
						"value": "8" 
					},
					{ 
						"label": "3x Long",
						"value": "9" 
					},
					{ 
						"label": "3x Long + Short",
						"value": "10" 
					},
					{ 
						"label": "4x Long",
						"value": "11" 
					},
					{ 
						"label": "4x Long + Short",
						"value": "12" 
					},
					{ 
						"label": "5x Long",
						"value": "13" 
					},
					{ 
						"label": "Very Long",
						"value": "14" 
					},
				],
			},
			{
				"type": "input",
				"messageKey": "Notification_3_StateMessage",
				"label": "State message for this notification",
				"description": "If left empty, the state message is not changed when this notification occurs.",
        "defaultValue": "4:00 WARNING!",
				"attributes": {
					"placeholder": "eg: WARNING!",
					"limit": 20
				}
			},
		]
  },
  {
    "type": "section",
    "items": [
      {
        "type": "heading",
        "defaultValue": "Notification 4"
      },
			{
				"type": "slider",
				"messageKey": "Notification_4_Minute",
				"label": "The minute this notification should occur.",
				"min": 0,
				"max": 20,
				"step": 1,
				"defaultValue": 3,
			},
			{
				"type": "slider",
				"messageKey": "Notification_4_Second",
				"label": "The second this notification should occur.",
				"min": 0,
				"max": 59,
				"step": 1,
				"defaultValue": 30,
			},
      {
        "type": "toggle",
        "messageKey": "Notification_4_OnTimerEnabled",
        "label": 'Enable this notification.',
        "defaultValue": false,
      },
			{
				"type": "select",
				"messageKey": "Notification_4_VibePatternIndex",
				"label": "Vibration pattern for this notification",
				"defaultValue": "10",
				"options": [
					{ 
						"label": "Off", 
						"value": "0" 
					},
					{ 
						"label": "Short",
						"value": "1" 
					},
					{ 
						"label": "Long",
						"value": "2" 
					},
					{ 
						"label": "2x Short",
						"value": "3" 
					},
					{ 
						"label": "Short - Long",
						"value": "4" 
					},
					{ 
						"label": "Long - Short",
						"value": "5" 
					},
					{ 
						"label": "2x Long",
						"value": "6" 
					},
					{ 
						"label": "3x Short",
						"value": "7" 
					},
					{ 
						"label": "2x Long + Short",
						"value": "8" 
					},
					{ 
						"label": "3x Long",
						"value": "9" 
					},
					{ 
						"label": "3x Long + Short",
						"value": "10" 
					},
					{ 
						"label": "4x Long",
						"value": "11" 
					},
					{ 
						"label": "4x Long + Short",
						"value": "12" 
					},
					{ 
						"label": "5x Long",
						"value": "13" 
					},
					{ 
						"label": "Very Long",
						"value": "14" 
					},
				],
			},
			{
				"type": "input",
				"messageKey": "Notification_4_StateMessage",
				"label": "State message for this notification",
				"description": "If left empty, the state message is not changed when this notification occurs.",
        "defaultValue": "3:30 WARNING!",
				"attributes": {
					"placeholder": "eg: WARNING!",
					"limit": 20
				}
			},
		]
  },
  {
    "type": "section",
    "items": [
      {
        "type": "heading",
        "defaultValue": "Notification 5"
      },
			{
				"type": "slider",
				"messageKey": "Notification_5_Minute",
				"label": "The minute this notification should occur.",
				"min": 0,
				"max": 20,
				"step": 1,
				"defaultValue": 3,
			},
			{
				"type": "slider",
				"messageKey": "Notification_5_Second",
				"label": "The second this notification should occur.",
				"min": 0,
				"max": 59,
				"step": 1,
				"defaultValue": 0,
			},
      {
        "type": "toggle",
        "messageKey": "Notification_5_OnTimerEnabled",
        "label": 'Enable this notification.',
        "defaultValue": true,
      },
			{
				"type": "select",
				"messageKey": "Notification_5_VibePatternIndex",
				"label": "Vibration pattern for this notification",
				"defaultValue": "9",
				"options": [
					{ 
						"label": "Off", 
						"value": "0" 
					},
					{ 
						"label": "Short",
						"value": "1" 
					},
					{ 
						"label": "Long",
						"value": "2" 
					},
					{ 
						"label": "2x Short",
						"value": "3" 
					},
					{ 
						"label": "Short - Long",
						"value": "4" 
					},
					{ 
						"label": "Long - Short",
						"value": "5" 
					},
					{ 
						"label": "2x Long",
						"value": "6" 
					},
					{ 
						"label": "3x Short",
						"value": "7" 
					},
					{ 
						"label": "2x Long + Short",
						"value": "8" 
					},
					{ 
						"label": "3x Long",
						"value": "9" 
					},
					{ 
						"label": "3x Long + Short",
						"value": "10" 
					},
					{ 
						"label": "4x Long",
						"value": "11" 
					},
					{ 
						"label": "4x Long + Short",
						"value": "12" 
					},
					{ 
						"label": "5x Long",
						"value": "13" 
					},
					{ 
						"label": "Very Long",
						"value": "14" 
					},
				],
			},
			{
				"type": "input",
				"messageKey": "Notification_5_StateMessage",
				"label": "State message for this notification",
				"description": "If left empty, the state message is not changed when this notification occurs.",
        "defaultValue": "3:00 WARNING!",
				"attributes": {
					"placeholder": "eg: WARNING!",
					"limit": 20
				}
			},
		]
  },
  {
    "type": "section",
    "items": [
      {
        "type": "heading",
        "defaultValue": "Notification 6"
      },
			{
				"type": "slider",
				"messageKey": "Notification_6_Minute",
				"label": "The minute this notification should occur.",
				"min": 0,
				"max": 20,
				"step": 1,
				"defaultValue": 2,
			},
			{
				"type": "slider",
				"messageKey": "Notification_6_Second",
				"label": "The second this notification should occur.",
				"min": 0,
				"max": 59,
				"step": 1,
				"defaultValue":30,
			},
      {
        "type": "toggle",
        "messageKey": "Notification_6_OnTimerEnabled",
        "label": 'Enable this notification.',
        "defaultValue": true,
      },
			{
				"type": "select",
				"messageKey": "Notification_6_VibePatternIndex",
				"label": "Vibration pattern for this notification",
				"defaultValue": "8",
				"options": [
					{ 
						"label": "Off", 
						"value": "0" 
					},
					{ 
						"label": "Short",
						"value": "1" 
					},
					{ 
						"label": "Long",
						"value": "2" 
					},
					{ 
						"label": "2x Short",
						"value": "3" 
					},
					{ 
						"label": "Short - Long",
						"value": "4" 
					},
					{ 
						"label": "Long - Short",
						"value": "5" 
					},
					{ 
						"label": "2x Long",
						"value": "6" 
					},
					{ 
						"label": "3x Short",
						"value": "7" 
					},
					{ 
						"label": "2x Long + Short",
						"value": "8" 
					},
					{ 
						"label": "3x Long",
						"value": "9" 
					},
					{ 
						"label": "3x Long + Short",
						"value": "10" 
					},
					{ 
						"label": "4x Long",
						"value": "11" 
					},
					{ 
						"label": "4x Long + Short",
						"value": "12" 
					},
					{ 
						"label": "5x Long",
						"value": "13" 
					},
					{ 
						"label": "Very Long",
						"value": "14" 
					},
				],
			},
			{
				"type": "input",
				"messageKey": "Notification_6_StateMessage",
				"label": "State message for this notification",
				"description": "If left empty, the state message is not changed when this notification occurs.",
        "defaultValue": "2:30 WARNING!",
				"attributes": {
					"placeholder": "eg: WARNING!",
					"limit": 20
				}
			},
		]
  },
  {
    "type": "section",
    "items": [
      {
        "type": "heading",
        "defaultValue": "Notification 7"
      },
			{
				"type": "slider",
				"messageKey": "Notification_7_Minute",
				"label": "The minute this notification should occur.",
				"min": 0,
				"max": 20,
				"step": 1,
				"defaultValue": 1,
			},
			{
				"type": "slider",
				"messageKey": "Notification_7_Second",
				"label": "The second this notification should occur.",
				"min": 0,
				"max": 59,
				"step": 1,
				"defaultValue": 30,
			},
      {
        "type": "toggle",
        "messageKey": "Notification_7_OnTimerEnabled",
        "label": 'Enable this notification.',
        "defaultValue": false,
      },
			{
				"type": "select",
				"messageKey": "Notification_7_VibePatternIndex",
				"label": "Vibration pattern for this notification",
				"defaultValue": "5",
				"options": [
					{ 
						"label": "Off", 
						"value": "0" 
					},
					{ 
						"label": "Short",
						"value": "1" 
					},
					{ 
						"label": "Long",
						"value": "2" 
					},
					{ 
						"label": "2x Short",
						"value": "3" 
					},
					{ 
						"label": "Short - Long",
						"value": "4" 
					},
					{ 
						"label": "Long - Short",
						"value": "5" 
					},
					{ 
						"label": "2x Long",
						"value": "6" 
					},
					{ 
						"label": "3x Short",
						"value": "7" 
					},
					{ 
						"label": "2x Long + Short",
						"value": "8" 
					},
					{ 
						"label": "3x Long",
						"value": "9" 
					},
					{ 
						"label": "3x Long + Short",
						"value": "10" 
					},
					{ 
						"label": "4x Long",
						"value": "11" 
					},
					{ 
						"label": "4x Long + Short",
						"value": "12" 
					},
					{ 
						"label": "5x Long",
						"value": "13" 
					},
					{ 
						"label": "Very Long",
						"value": "14" 
					},
				],
			},
			{
				"type": "input",
				"messageKey": "Notification_7_StateMessage",
				"label": "State message for this notification",
				"description": "If left empty, the state message is not changed when this notification occurs.",
        "defaultValue": "1:30 WARNING!",
				"attributes": {
					"placeholder": "eg: WARNING!",
					"limit": 20
				}
			},
		]
  },
  {
    "type": "section",
    "items": [
      {
        "type": "heading",
        "defaultValue": "Notification 8"
      },
			{
				"type": "slider",
				"messageKey": "Notification_8_Minute",
				"label": "The minute this notification should occur.",
				"min": 0,
				"max": 20,
				"step": 1,
				"defaultValue": 1,
			},
			{
				"type": "slider",
				"messageKey": "Notification_8_Second",
				"label": "The second this notification should occur.",
				"min": 0,
				"max": 59,
				"step": 1,
				"defaultValue": 0,
			},
      {
        "type": "toggle",
        "messageKey": "Notification_8_OnTimerEnabled",
        "label": 'Enable this notification.',
        "defaultValue": true,
      },
			{
				"type": "select",
				"messageKey": "Notification_8_VibePatternIndex",
				"label": "Vibration pattern for this notification",
				"defaultValue": "2",
				"options": [
					{ 
						"label": "Off", 
						"value": "0" 
					},
					{ 
						"label": "Short",
						"value": "1" 
					},
					{ 
						"label": "Long",
						"value": "2" 
					},
					{ 
						"label": "2x Short",
						"value": "3" 
					},
					{ 
						"label": "Short - Long",
						"value": "4" 
					},
					{ 
						"label": "Long - Short",
						"value": "5" 
					},
					{ 
						"label": "2x Long",
						"value": "6" 
					},
					{ 
						"label": "3x Short",
						"value": "7" 
					},
					{ 
						"label": "2x Long + Short",
						"value": "8" 
					},
					{ 
						"label": "3x Long",
						"value": "9" 
					},
					{ 
						"label": "3x Long + Short",
						"value": "10" 
					},
					{ 
						"label": "4x Long",
						"value": "11" 
					},
					{ 
						"label": "4x Long + Short",
						"value": "12" 
					},
					{ 
						"label": "5x Long",
						"value": "13" 
					},
					{ 
						"label": "Very Long",
						"value": "14" 
					},
				],
			},
			{
				"type": "input",
				"messageKey": "Notification_8_StateMessage",
				"label": "State message for this notification",
				"description": "If left empty, the state message is not changed when this notification occurs.",
        "defaultValue": "1:00 WARNING!",
				"attributes": {
					"placeholder": "eg: WARNING!",
					"limit": 20
				}
			},
		]
  },
  {
    "type": "section",
    "items": [
      {
        "type": "heading",
        "defaultValue": "Notification 9"
      },
			{
				"type": "slider",
				"messageKey": "Notification_9_Minute",
				"label": "The minute this notification should occur.",
				"min": 0,
				"max": 20,
				"step": 1,
				"defaultValue": 0,
			},
			{
				"type": "slider",
				"messageKey": "Notification_9_Second",
				"label": "The second this notification should occur.",
				"min": 0,
				"max": 59,
				"step": 1,
				"defaultValue": 0,
			},
      {
        "type": "toggle",
        "messageKey": "Notification_9_OnTimerEnabled",
        "label": 'Enable this notification.',
        "defaultValue": false,
      },
			{
				"type": "select",
				"messageKey": "Notification_9_VibePatternIndex",
				"label": "Vibration pattern for this notification",
				"defaultValue": "0",
				"options": [
					{ 
						"label": "Off", 
						"value": "0" 
					},
					{ 
						"label": "Short",
						"value": "1" 
					},
					{ 
						"label": "Long",
						"value": "2" 
					},
					{ 
						"label": "2x Short",
						"value": "3" 
					},
					{ 
						"label": "Short - Long",
						"value": "4" 
					},
					{ 
						"label": "Long - Short",
						"value": "5" 
					},
					{ 
						"label": "2x Long",
						"value": "6" 
					},
					{ 
						"label": "3x Short",
						"value": "7" 
					},
					{ 
						"label": "2x Long + Short",
						"value": "8" 
					},
					{ 
						"label": "3x Long",
						"value": "9" 
					},
					{ 
						"label": "3x Long + Short",
						"value": "10" 
					},
					{ 
						"label": "4x Long",
						"value": "11" 
					},
					{ 
						"label": "4x Long + Short",
						"value": "12" 
					},
					{ 
						"label": "5x Long",
						"value": "13" 
					},
					{ 
						"label": "Very Long",
						"value": "14" 
					},
				],
			},
			{
				"type": "input",
				"messageKey": "Notification_9_StateMessage",
				"label": "State message for this notification",
				"description": "If left empty, the state message is not changed when this notification occurs.",
        "defaultValue": "",
				"attributes": {
					"placeholder": "eg: WARNING!",
					"limit": 20
				}
			},
		]
  },
  {
    "type": "submit",
    "defaultValue": "Save Settings"
  },
];
