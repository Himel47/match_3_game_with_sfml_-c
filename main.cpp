#include <SFML/Graphics.hpp>

#include<SFML/System/Clock.hpp>

#include<bits/stdc++.h>

using namespace sf;

using namespace std;


int Level4_page()
{
    int clock4=0;

    Font best41, best42;
    best41.loadFromFile("fonts/comic.ttf");
    best42.loadFromFile("fonts/VINERITC.ttf");

    RenderWindow page4(VideoMode(560,401), "Level_4 Starting");

    Text t41("LEVEL -- 4", best41, 50);
    Text t42("<Press ENTER to Continue>", best42, 25);

    t41.setFillColor(sf::Color::Magenta);
    t42.setFillColor(sf::Color::Yellow);

    t41.setPosition(160,150);
    t42.setPosition(120,350);

    Texture bg4;
    bg4.loadFromFile("image/bg_night.jpg");

    Sprite Back4(bg4);

    while(page4.isOpen())
    {
        Event starting4;
        while(page4.pollEvent(starting4))
        {
            if(starting4.type== Event::KeyPressed)
            {

                if(Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    page4.close();
                }

                if(Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    page4.close();
                    //Game4();
                }

            }
        }

        page4.clear();
        page4.draw(Back4);
        page4.draw(t41);
        clock4++;
        if(clock4%300<150)
        {
            page4.draw(t42);
        }

        page4.display();
    }
}


int Level3_page()
{
    int clock3=0;

    Font best31, best32;
    best31.loadFromFile("fonts/comic.ttf");
    best32.loadFromFile("fonts/VINERITC.ttf");

    RenderWindow page3(VideoMode(560,401), "Level_3 Starting");

    Text t31("LEVEL -- 3", best31, 50);
    Text t32("<Press ENTER to Continue>", best32, 25);

    t31.setFillColor(sf::Color::Magenta);
    t32.setFillColor(sf::Color::Yellow);

    t31.setPosition(160,150);
    t32.setPosition(120,350);

    Texture bg3;
    bg3.loadFromFile("image/bg_night.jpg");

    Sprite Back3(bg3);

    while(page3.isOpen())
    {
        Event starting3;
        while(page3.pollEvent(starting3))
        {
            if(starting3.type== Event::KeyPressed)
            {

                if(Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    page3.close();
                }

                if(Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    page3.close();
                    //Game3();
                }

            }
        }

        page3.clear();
        page3.draw(Back3);
        page3.draw(t31);
        clock3++;
        if(clock3%300<150)
        {
            page3.draw(t32);
        }

        page3.display();
    }
}


void Level2_page()
{
    int clock2=0;

    Font best21, best22;
    best21.loadFromFile("fonts/comic.ttf");
    best22.loadFromFile("fonts/VINERITC.ttf");

    RenderWindow page2(VideoMode(560,401), "Level_2 Starting");

    Text t21("LEVEL -- 2", best21, 50);
    Text t22("<Press ENTER to Continue>", best22, 25);

    t21.setFillColor(sf::Color::Magenta);
    t22.setFillColor(sf::Color::Yellow);

    t21.setPosition(160,150);
    t22.setPosition(120,350);

    Texture bg2;
    bg2.loadFromFile("image/bg_night.jpg");

    Sprite Back2(bg2);

    while(page2.isOpen())
    {
        Event starting2;
        while(page2.pollEvent(starting2))
        {
            if(starting2.type== Event::KeyPressed)
            {

                if(Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    page2.close();
                }

                if(Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    page2.close();
                    //Game2();
                }

            }
        }

        page2.clear();
        page2.draw(Back2);
        page2.draw(t21);
        clock2++;
        if(clock2%300<150)
        {
            page2.draw(t22);
        }

        page2.display();
    }
}


int Level1_page()
{
    int clock1=0;

    Font best11, best12;
    best11.loadFromFile("fonts/comic.ttf");
    best12.loadFromFile("fonts/VINERITC.ttf");

    RenderWindow page1(VideoMode(560,401), "Level_1 Starting");

    Text t11("LEVEL -- 1", best11, 50);
    Text t12("<Press ENTER to Continue>", best12, 25);

    t11.setFillColor(sf::Color::Magenta);
    t12.setFillColor(sf::Color::Yellow);

    t11.setPosition(160,150);
    t12.setPosition(120,350);

    Texture bg1;
    bg1.loadFromFile("image/bg_night.jpg");

    Sprite Back1(bg1);

    while(page1.isOpen())
    {
        Event starting1;
        while(page1.pollEvent(starting1))
        {
            if(starting1.type== Event::KeyPressed)
            {

                if(Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    page1.close();
                }

                if(Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    page1.close();
                    //Game1();
                }

            }
        }

        page1.clear();
        page1.draw(Back1);
        page1.draw(t11);
        clock1++;
        if(clock1%300<150)
        {
            page1.draw(t12);
        }

        page1.display();
    }
}


void level_page()
{
    Font fontx,fonty;
    fontx.loadFromFile("fonts/AGENCYB.ttf");
    fonty.loadFromFile("fonts/COLONNA.ttf");

    RenderWindow Levels(VideoMode(560, 401), "Levels ::");

    Text Ta("Level 1", fontx, 40);
    Text Tb("Level 2", fontx, 40);
    Text Tc("Level 3", fontx, 40);
    Text Td("Level 4", fontx, 40);
    Text Te("SELECT LEVEL :", fonty, 50);

    Ta.setFillColor(sf::Color::Green);
    Tb.setFillColor(sf::Color::Green);
    Tc.setFillColor(sf::Color::Green);
    Td.setFillColor(sf::Color::Green);
    Te.setFillColor(sf::Color::Magenta);

    Ta.setPosition(362, 111);
    Tb.setPosition(362, 181);
    Tc.setPosition(362, 251);
    Td.setPosition(362, 321);
    Te.setPosition(160,10);

    Texture page_bg, page_level1, page_level2, page_level3, page_level4, page_arrow, page_style;
    page_arrow.loadFromFile("image/RightArrow.png");
    page_bg.loadFromFile("image/score_background.jpg");
    page_level1.loadFromFile("image/button1.png");
    page_level2.loadFromFile("image/button1.png");
    page_level3.loadFromFile("image/button1.png");
    page_level4.loadFromFile("image/button1.png");
    page_style.loadFromFile("image/Design.png");

    Sprite level_bg(page_bg), level1(page_level1), level2(page_level2), level3(page_level3), level4(page_level4), level_arrow(page_arrow), level_style1(page_style);

    level1.setPosition(340,111);
    level2.setPosition(340,181);
    level3.setPosition(340,251);
    level4.setPosition(340,321);
    level_style1.setPosition(0,0);

    int arrowposition=126;
    level_arrow.setPosition(280,arrowposition);

    while(Levels.isOpen())
    {
        Event level_event;
        while(Levels.pollEvent(level_event))
        {
            if(level_event.type== Event::KeyPressed)
            {

                if(Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    Levels.close();
                }


                else if(Keyboard::isKeyPressed(Keyboard::Up))
                {
                    arrowposition-=70;
                    if(arrowposition<126)
                    {
                        arrowposition=336;
                    }
                    level_arrow.setPosition(280,arrowposition);
                }


                else if(Keyboard::isKeyPressed(Keyboard::Down))
                {
                    arrowposition+=70;
                    if(arrowposition>336)
                    {
                        arrowposition=126;
                    }
                    level_arrow.setPosition(280,arrowposition);
                }


                else if(Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    if(arrowposition==126)
                    {
                        Level1_page();
                    }
                    else if(arrowposition==196)
                    {
                        Level2_page();
                    }
                    else if(arrowposition==266)
                    {
                        Level3_page();
                    }
                    else if(arrowposition==336)
                    {
                        Level4_page();
                    }
                }

            }
        }

        Levels.clear();
        Levels.draw(level_bg);
        Levels.draw(level_style1);
        Levels.draw(level1);
        Levels.draw(level2);
        Levels.draw(level3);
        Levels.draw(level4);
        Levels.draw(Ta);
        Levels.draw(Tb);
        Levels.draw(Tc);
        Levels.draw(Td);
        Levels.draw(Te);
        Levels.draw(level_arrow);
        Levels.display();
    }
}


void  High_score()
{

    Font fontA, fontB;
    fontA.loadFromFile("fonts/AGENCYR.ttf");
    fontB.loadFromFile("fonts/COLONNA.ttf");

    RenderWindow Hscore(VideoMode(560,401), "**High Score**");

    Text T1("Your", fontA, 35);
    Text T2("HIGH SCORE :", fontB, 50);

    T1.setFillColor(sf::Color::Red);
    T2.setFillColor(sf::Color::Yellow);

    T1.setPosition(110, 150);
    T2.setPosition(170,135);

    Texture score_bg, board_bg;
    score_bg.loadFromFile("image/score_background_drops.jpg");
    board_bg.loadFromFile("image/button.png");

    Sprite scoreback(score_bg), scoreboard(board_bg);
    scoreboard.setPosition(135,200);

    while(Hscore.isOpen())
    {
        Event score_event;
        while(Hscore.pollEvent(score_event))
        {
            if(score_event.type== Event::KeyPressed)
            {

                if(Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    Hscore.close();
                }

            }
        }

        Hscore.clear();

        Hscore.draw(scoreback);
        Hscore.draw(scoreboard);
        Hscore.draw(T1);
        Hscore.draw(T2);
        Hscore.display();

    }

}


int main()
{
    int xposition,yposition;

    Font font1, font2, font3;
    font1.loadFromFile("fonts/ITCKRIST.ttf");
    font2.loadFromFile("fonts/VINERITC.ttf");
    font3.loadFromFile("fonts/MAIAN.ttf");
    RenderWindow MainPage(VideoMode(560, 401), "Main Page");

    Texture w_background, w_logo, w_style;

    //text fixing

    Text w_t("Welcome To", font1, 35);
    Text t1("MATCH-3", font2, 50);
    Text t2("MANIA", font2, 35);
    Text t3("Play Game", font3, 25);
    Text t4("High Score", font3, 25);
    Text t5("Exit", font3, 25);
    Text dv("Developed By ==> Raisul & Himel", font1, 20);

    //text coloring

    w_t.setFillColor(sf::Color::Yellow);
    t1.setFillColor(sf::Color::Yellow);
    t2.setFillColor(sf::Color::Yellow);
    t3.setFillColor(sf::Color::Red);
    t4.setFillColor(sf::Color::Red);
    t5.setFillColor(sf::Color::Red);
    dv.setFillColor(sf::Color::Green);

    //text position declaring

    w_t.setPosition(175, 50);
    t1.setPosition(100, 115);
    t2.setPosition(350, 125);
    t3.setPosition(205, 185);
    t4.setPosition(205, 225);
    t5.setPosition(205, 265);
    dv.setPosition(220,350);

    //image loading

    w_background.loadFromFile("image/neon_shape.jpg");
    w_logo.loadFromFile("image/RightArrow.png");
    w_style.loadFromFile("image/DownArrow.png");


    Sprite logo_s(w_logo), b_s(w_background), a_s(w_style);
    xposition=130;
    yposition=190;
    logo_s.setPosition(xposition,yposition);


    while(MainPage.isOpen())
    {
        Event menu_event;
        while(MainPage.pollEvent(menu_event))
        {
            if(menu_event.type==Event::Closed)
                MainPage.close();
            else if(menu_event.type== Event::KeyPressed)
            {
                if(Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    if(yposition==270)
                    {
                        MainPage.close();
                    }
                    else if(yposition==230)
                    {
                        High_score();
                    }
                    else if(yposition==190)
                    {
                        level_page();
                    }
                }

                //arrow moving

                else if(Keyboard::isKeyPressed(Keyboard::Up))
                {
                    yposition-=40;
                    if(yposition<190)
                    {
                        yposition+=(3*40);
                    }
                    logo_s.setPosition(xposition,yposition);
                }


                else if(Keyboard::isKeyPressed(Keyboard::Down))
                {
                    yposition+=40;
                    if(yposition>270)
                    {
                        yposition-=(3*40);
                    }
                    logo_s.setPosition(xposition,yposition);
                }

                //arrow moving ending//
            }
        }


        MainPage.clear();
        MainPage.draw(b_s);
        MainPage.draw(a_s);
        MainPage.draw(logo_s);
        MainPage.draw(w_t);
        MainPage.draw(t5);
        MainPage.draw(t4);
        MainPage.draw(t3);
        MainPage.draw(t2);
        MainPage.draw(t1);
        MainPage.draw(dv);
        MainPage.display();


    }
}
