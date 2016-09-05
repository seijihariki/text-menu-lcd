#ifndef _LCD_MENU_EXEC_FUNCTION_
#define _LCD_MENU_EXEC_FUNCTION_

#include "lcd_menu.h"
namespace lcdmenu
{
    struct exec_function : public screen
    {
    public:
        exec_function(void (* function)(), screen* sc, LCD* _lcd, screen* par);
    
        void handle_input(char input);
        void draw();
        void goback();
    private:
        bool inside;
        screen *onconf;
        void (* fn)();
    };
}

#endif
