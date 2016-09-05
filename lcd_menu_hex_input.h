#ifndef _LCD_MENU_HEX_INPUT_
#define _LCD_MENU_HEX_INPUT_

#include "lcd_menu.h"
namespace lcdmenu
{
    struct hex_input : public screen
    {
    public:
        hex_input(String _label, int maxdigit, screen* sc, LCD* _lcd, screen* par);
        ~hex_input();
    
        void handle_input(char input);
        void draw();
        void goback();
    private:
        bool inside, draw_under;
        int select, md;
        screen *after;
        String label;
        String number;
    };
}

#endif
