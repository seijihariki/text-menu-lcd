#ifndef _LCD_MENU_CONFIRM_
#define _LCD_MENU_CONFIRM_

#include "lcd_menu.h"
namespace lcdmenu
{
    struct confirm : public screen
    {
    public:
        confirm(String _label, screen* sc, LCD* lcd, screen* par);
    
        void handle_input(char input);
        void draw();
        void goback();
    private:
        bool inside, select;
        screen *onconf;
        String label;
    };
}
#endif
