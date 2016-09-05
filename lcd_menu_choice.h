#ifndef _LCD_MENU_CHOICE_
#define _LCD_MENU_CHOICE_

#include "lcd_menu.h"

namespace lcdmenu
{
    struct choice : public screen
    {
    public:
        choice(int mitem, LCD* lcd, screen* par);
    
        void handle_input(char input);
        void draw();
    
        void add_item(screen *sc, String label);
        void rem_item(int pos);
        void goback();
    private:
        bool state;
        int inside;
        int select, vtop;
        int itemcnt, maxit;
        screen **screens;
        String *labels;
    };
}

#endif
