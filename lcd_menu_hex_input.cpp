#include "lcd_menu_hex_input.h"

lcdmenu::hex_input::hex_input (String _label, int maxdigit, screen* sc, LCD* _lcd, screen* par) : after(sc), label(_label), 
    select(0), number("0"), md(maxdigit), draw_under(false), inside(false), screen(par, _lcd)
{
    if(md != 1) number += " "; 
}

void lcdmenu::hex_input::handle_input (char input)
{
    if(inside) {after->handle_input(input); return;}
    switch (input)
    {
    case 0:
        switch(number[select])
        {
        case ' ':
            number[select] = '0';
            if(number.length() < md) number += " ";
            break;
        case '9':
            number[select] = 'A';
            break;
        case 'F':
            if(select == number.length() - 2)
            {
                number.trim();
                number[select] = ' ';
            } else number[select] = '0';
            break;
        default:
            number[select]++;
            break;
        }
        break;
    case 2:
        switch(number[select])
        {
        case ' ':
            number[select] = 'F';
            if(number.length() < md) number += " ";
            break;
        case 'A':
            number[select] = '9';
            break;
        case '0':
            if(select == number.length() - 2)
            {
                number.trim();
                number[select] = ' ';
            } else number[select] = 'F';
            break;
        default:
            number[select]--;
            break;
        }
        break;
    case 1:
        {
            if(select == number.length() - 1) inside = true;
            else select++;
        }
        break;
    case 3:
        {
            if(select) select--; 
            else parent->goback();
        }
        break;
    }
}

void lcdmenu::hex_input::draw ()
{
    if(inside) {after->draw(); return;}
    
    lcd->write(label, 0, 0);
    
    for(int k = label.length(); k < lcd->w; k++) lcd->write(" ");
    lcd->move(number.length() + 2,1);
    
    for(int k = number.length() + 2; k < lcd->w; k++) 
        lcd->write((k >= 2 + md)?"-":" ");
    
    lcd->write("0x", 0, 1);
    String ntop = number;
    
    if(draw_under = !draw_under) ntop[select] = '_';
    lcd->write(ntop, 2, 1);
}

void lcdmenu::hex_input::goback ()
{
    inside = false;
}

