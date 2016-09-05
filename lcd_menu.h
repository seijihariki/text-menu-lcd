#ifndef _LCD_MENU_
#define _LCD_MENU_

#include <Arduino.h>
namespace lcdmenu
{
    struct LCD
    {
    public:
        LCD(int sx, int sy);
        virtual void write(String str) = 0;
        virtual void write(String str, int row) = 0;
        virtual void write(String str, int column, int row) = 0;
        
        virtual void move(int x, int y) = 0;
        virtual void clear() = 0;
        
        int w, h;
    };
    
    struct screen
    {
    public:
        screen(screen* par, LCD* _lcd);
    
        virtual void handle_input(char input) = 0;
        virtual void draw() = 0;
        virtual void goback() = 0;
        
        void setParent(screen *par);
    
    protected:
        LCD* lcd;
        screen* parent;
};
}
#endif
