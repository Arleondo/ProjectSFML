#include <SFML/Graphics.hpp>
#include "MainMenu.h"
using namespace sf;

int main() {
    RenderWindow MENU(VideoMode(960, 720), "Main Menu", Style::Default);
    MainMenu mainMenu(960,720);

    while (MENU.isOpen()) {
        Event event{};
        while (MENU.pollEvent(event)) {
            if (event.type == Event::Closed) {
                MENU.close();
            }

            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::Up) {
                    mainMenu.MoveUp();
                    break;
                }
                if (event.key.code == Keyboard::Down) {
                    mainMenu.MoveDown();
                    break;
                }
                if (event.key.code == Keyboard::Return) {
                    RenderWindow Play(VideoMode(960, 720), "Boxing");
                    RenderWindow Options(VideoMode(960, 720), "Options");
                    RenderWindow About(VideoMode(960, 720), "About");

                    int x = mainMenu.MainMenuPressed();
                    if (x == 0) {
                        while (Play.isOpen()) {
                            Event aevent{};
                            while (Play.pollEvent(aevent));
                            if (aevent.type == Event::Closed) {
                                Play.close();
                            }
                            if (aevent.type == Event::KeyPressed) {
                                if (aevent.key.code == Keyboard::Escape) {
                                    Play.close();
                                }
                            }
                        }
                        Options.close();
                        About.close();
                        Play.clear();
                        Play.display();
                    }
                    if (x == 1)
                    {
                        while (Options.isOpen())
                        {
                            Event aevent{};
                            while (Options.pollEvent(aevent));
                            if (aevent.type == Event::Closed)
                            {
                                Options.close();
                            }
                            if (aevent.type == Event::KeyPressed) {
                                if (aevent.key.code == Keyboard::Escape) {
                                    Options.close();
                                }
                            }
                        }
                        Play.close();
                        Options.clear();
                        About.close();
                        Options.display();
                    }
                    if (x == 2)
                    {
                        while (About.isOpen())
                        {
                            Event aevent{};
                            while (About.pollEvent(aevent));
                            if (aevent.type == Event::Closed)
                            {
                                About.close();
                            }
                            if (aevent.type == Event::KeyPressed) {
                                if (aevent.key.code == Keyboard::Escape) {
                                    About.close();
                                }
                            }
                        }
                        Play.close();
                        Options.clear();
                        About.clear();
                        About.display();
                    }
                    if (x == 3)
                    {
                        MENU.close();
                    }
                    break;
                }
            }
        }
        MENU.clear();
        mainMenu.draw(MENU);
        MENU.display();

    }
}