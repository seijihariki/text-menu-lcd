#include "lcd_menu_exec_function.h"

lcdmenu::exec_function::exec_function ((void (* function)(), LCD* _lcd, screen* par) : fn(function), inside(false), onconf(sc), screen(par, _lcd)
{
}

void lcdmenu::exec_function::handle_input (char input)
{
    if (inside) onconf->handle_input(input);
}

void lcdmenu::exec_function::draw ()
{
    if(!ran) 
    {
        lcd->clear();
        fn();
        inside = ran = true;
    }
    if (inside) onconf->draw();
}

void lcdmenu::exec_function::goback ()
{
    inside = false;
    par->goback();
    ran = false;
}

