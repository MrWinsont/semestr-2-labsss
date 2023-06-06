#include "Game.hpp"



int main()
{
    vg::Log::SetPath("log.txt");
    vg::Log::SetLevel(vg::LogLevel::RELEASE);
    
    vg::Menu menu;
    menu.setResolution(600, 800);
    menu.setCaption("Game Menu");
    menu.setup();
    menu.runMenu();
 
    return 0;
}