*
  LcdScroller.cpp - Library to display scrolling text on LCD screen from Arduino
  Created by backslashn, April 24, 2016
  MIT Public License
*/

#include <Arduino.h>
#include "LcdScroller.h"

LcdScroller::LcdScroller(LiquidCrystal *lcd, byte lineNum, byte firstCharPos, byte lastCharPos) :
	_lcd(lcd), _lineNum(lineNum), _firstCharPos(firstCharPos),
	_text(NULL), _textLen(0), _firstCharIndex(0), _lastUpdateTime(0)
{
	_displayLen = lastCharPos - firstCharPos + 1;
}

void LcdScroller::setText(char *text, int textLen)
{
	_text = text;
	_textLen = textLen;
	
	if (_textLen <= _displayLen)
	{
		_lcd->setCursor(_firstCharPos,_lineNum);
		for (int i = 0; i < _textLen; i++)
		{
			_lcd->write(_text[i]);
		}
		for (int i = _textLen; i < _displayLen; i++)
		{
			_lcd->write(' ');
		}
	}
	else
	{
		_firstCharIndex = 0;
		_writeSubText();
	}
}

void LcdScroller::update()
{
	//Scroll only if text length superior to display length
	if (_textLen > _displayLen)
	{
		if (_firstCharIndex == 0)
		{
			//We use abs here to take into account the unsigned long limit
			if (abs(millis() - _lastUpdateTime) > DELAY_SCROLL_EXT)
			{
				_firstCharIndex++;
				_writeSubText();
			}
		}
		else if (_firstCharIndex == _textLen - _displayLen)
		{
			if (abs(millis() - _lastUpdateTime) > DELAY_SCROLL_EXT)
			{
				_firstCharIndex = 0;
				_writeSubText();
			}
		}
		else
		{
			if (abs(millis() - _lastUpdateTime) > DELAY_SCROLL_MID)
			{
				_firstCharIndex++;
				_writeSubText();
			}
		}
	}
}

void LcdScroller::_writeSubText()
{
	_lcd->setCursor(_firstCharPos,_lineNum);
	for (int i = 0; i < _displayLen; i++)
	{
		_lcd->write(_text[_firstCharIndex+i]);
	}
	_lastUpdateTime = millis();
}
