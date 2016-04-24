# LcdScroller
A library to display scrolling text on LCD screen from Arduino

## How to use

### Arduino IDE setup
To make this library available in your Arduino IDE, follow [this tutorial](https://www.arduino.cc/en/hacking/libraries)

### Use library in your project
First, include the library in your main file
```c++
#include <LcdScroller.h>
```

Then, create an instance of the LcdScroller object
```c++
LcdScroller scrollLine(&lcd,0,0,15);
```
Here lcd is the handle to ```LiquidCrystal``` object representing the LCD screen on which you want to display the scrolling text
Second parameter is the line number starting at 0 for first line
Third and fourth parameters are the first and last character positions on the line between which the scrolling will take place

Then, use the ```setText``` command
```c++
scrollLine.setText("Text that needs to scroll", 25);
```
First parameter is the text itself
Second parameter is the length of this text

Finally, you need to call the ```update``` function in your ```loop``` and make sure that the loop is running faster than 250ms (value of ```DELAY_SCROLL_MID```)
