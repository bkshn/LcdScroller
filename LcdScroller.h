/*
  LcdScroller.h - Library to display scrolling text on LCD screen from Arduino
  Created by backslashn, April 24, 2016
  MIT Public License
*/

#ifndef LcdScroller_h
#define LcdScroller_h

#include <Arduino.h>
#include <LiquidCrystal.h>

#define DELAY_SCROLL_EXT 750
#define DELAY_SCROLL_MID 250

class LcdScroller {
	public:
		LcdScroller(LiquidCrystal *lcd, byte lineNum, byte firstCharPos, byte lastCharPos);
		void setText(char *text, int textLen);
		void update();

	private:
		LiquidCrystal *_lcd;
		byte _lineNum;
		byte _firstCharPos;
		byte _displayLen;
		char *_text;
		byte _textLen;
		byte _firstCharIndex;
		unsigned long _lastUpdateTime;
		
		void _writeSubText();
};

#endif
