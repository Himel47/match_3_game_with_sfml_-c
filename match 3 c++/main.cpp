#include<SFML/Graphics.hpp>

#include<SFML/Audio.hpp>

#include<SFML/System/Clock.hpp>

#include<bits/stdc++.h>

using namespace sf;

using namespace std;

string stringscore="", stringscore2="";
string stringmove="", stringmove2="";
string stringpoint="";

//time display
string stringminute1="";
string stringsecond1="";

int secondcounting=0, extra_timer=0;
int minutecounting=0;

int pointx=0, pointy=0, moves1=20, moves2=20, h_points, flag=0;
int tile=45; //tile size
Vector2i offset(36,18);


struct piece
{
    int x,y,col,row,kind,match,deleteanimationstyle;
    piece()
    {
        match=0;
        deleteanimationstyle=255;
    }
} grid[10][10];

void swap(piece p1, piece p2)
{
    std::swap(p1.col,p2.col);
    std::swap(p1.row,p2.row);

    grid[p1.row][p1.col]=p1;
    grid[p2.row][p2.col]=p2;
}


void move_ending_page()
{
    Font fonTf1, fonTf2, fonTf3;
    fonTf1.loadFromFile("fonts/COLONNA.ttf");
    fonTf2.loadFromFile("fonts/ITCKRIST.ttf");
    fonTf3.loadFromFile("fonts/OCRAEXT.ttf");

    RenderWindow Fail1(VideoMode(760,600), "Fail-1");

    Texture fail_bg, sad, exit;
    fail_bg.loadFromFile("image/bg_night.jpg");
    sad.loadFromFile("image/sad.png");
    exit.loadFromFile("image/exit1.jpg");

    Sprite bg_fail1(fail_bg), emoji(sad), exitf(exit);

    emoji.setPosition(316,50);
    exitf.setPosition(114,465);

    Text failT1("SORRY..!!", fonTf1, 65);
    Text failT2("You FAILED", fonTf2, 35);
    Text failT3("<Press ENTER for main page>", fonTf3, 28);

    failT1.setFillColor(sf::Color::Yellow);
    failT2.setFillColor(sf::Color::Red);
    failT3.setFillColor(sf::Color::Yellow);

    failT1.setPosition(260,200);
    failT2.setPosition(280,350);
    failT3.setPosition(190,500);

    while(Fail1.isOpen())
    {
        Event fail1_event;
        while(Fail1.pollEvent(fail1_event))
        {
            if(fail1_event.type== Event::KeyPressed)
            {

                if(Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    Fail1.close();
                }

            }
        }

        Fail1.clear();
        Fail1.draw(bg_fail1);
        Fail1.draw(emoji);
        Fail1.draw(exitf);

        Fail1.draw(failT1);
        Fail1.draw(failT2);
        Fail1.draw(failT3);

        Fail1.display();
    }
}


void Level4_page(int flag)
{
level_event1:
    Music music4;
    music4.openFromFile("music/candy crush.ogg");

    RenderWindow level_4(VideoMode(760,600), "Level_4 Starting");

    int posy;
    int clock4=0;

    Font best41, best42, best43, best44, best45;
    best41.loadFromFile("fonts/comic.ttf");
    best42.loadFromFile("fonts/VINERITC.ttf");
    best43.loadFromFile("fonts/OCRAEXT.ttf");
    best44.loadFromFile("fonts/COLONNA.ttf");
    best45.loadFromFile("fonts/ITCKRIST.ttf");

    Text t41("LEVEL -- 4", best41, 65);
    Text t42("<Press ENTER to Continue>", best42, 30);
    Text t43("Press ESC to exit", best43, 30);

    t41.setFillColor(sf::Color::Magenta);
    t42.setFillColor(sf::Color::Yellow);

    t41.setPosition(220,245);
    t42.setPosition(175,500);
    t43.setPosition(45,2);

    Texture bg4, arrow_exit;
    bg4.loadFromFile("image/bg_night.jpg");
    arrow_exit.loadFromFile("image/dynamic_blue_left.png");

    Sprite Back4(bg4), exitarrow(arrow_exit);
    exitarrow.setPosition(-3,0);

    if(flag==0)
    {
        music4.play();
    }
    else if(flag==1)
    {
        music4.stop();
    }

    while(level_4.isOpen())
    {
        Event starting4;
        while(level_4.pollEvent(starting4))
        {
            if(starting4.type== Event::KeyPressed)
            {

                if(Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    level_4.close();
                }

                if(Keyboard::isKeyPressed(Keyboard::Enter))
                {
game_event2:
                    sf::Clock clock_timer;

                    sf::Time time;

                    level_4.setFramerateLimit(65);

                    pointy=0;
                    minutecounting=0;
                    secondcounting=0;
                    extra_timer=0;
                    posy=150;

                    Texture t1,t2,t3,t4,t5,t6,t7;
                    t1.loadFromFile("image/bg_night.jpg");
                    t2.loadFromFile("image/gems.png");
                    t3.loadFromFile("image/button2.png");
                    t4.loadFromFile("image/button2.png");
                    t5.loadFromFile("image/button3.png");
                    t6.loadFromFile("image/Design-PNG-Photo.png");
                    t7.loadFromFile("image/png.png");

                    Sprite background(t1), gems(t2),point_bg(t3), point_bg2(t4), point_bg3(t5), point_bg4(t6), escape(t7);
                    point_bg.setPosition(420,70);
                    point_bg2.setPosition(420,190);
                    point_bg3.setPosition(420,310);
                    point_bg4.setPosition(590,420);
                    escape.setPosition(5,510);

                    //game page writings

                    Font fontg;
                    fontg.loadFromFile("fonts/ALGER.ttf");
                    Text game1("Score :", fontg, 35);
                    Text game2("Time :", fontg, 35);
                    Text game3("Target ::", fontg, 35);
                    Text game4("more than $ 6500 $", fontg, 15);
                    Text game5("Within 2 minutes...", fontg, 15);
                    Text game6("Press ESC to pause", best43, 25);
                    Text game7("# Level - 4", best41, 45);
                    game1.setPosition(420,20);
                    game2.setPosition(420,140);
                    game3.setPosition(420,260);
                    game4.setPosition(420,310);
                    game5.setPosition(420,330);
                    game6.setPosition(60,510);
                    game7.setPosition(5,440);
                    game1.setFillColor(sf::Color::Yellow);
                    game2.setFillColor(sf::Color::Yellow);
                    game3.setFillColor(sf::Color::Yellow);
                    game4.setFillColor(Color::Red);
                    game5.setFillColor(Color::Red);
                    game6.setFillColor(Color::Yellow);
                    game7.setFillColor(Color::Yellow);


                    //game code

                    for(int i=1; i<=8; i++)
                    {
                        for(int j=1; j<=8; j++)
                        {
                            grid[i][j].kind=rand()%6;
                            grid[i][j].col=j;
                            grid[i][j].row=i;
                            grid[i][j].x=j*tile;
                            grid[i][j].y=i*tile;
                        }
                    }

                    int x0,y0,x,y;
                    int click=0;
                    Vector2i position;

                    bool isSwap=false, isMoving=false;
game_event1:
                    while(level_4.isOpen())
                    {
                        Event event;
                        while(level_4.pollEvent(event))
                        {
                            if(event.type==Event::KeyPressed)
                            {
                                if(Keyboard::isKeyPressed(Keyboard::Escape))
                                {
                                    /* PAUSE MENU for LEVEL _ 4 */

                                    extra_timer=secondcounting;

                                    Texture a1, a2, a3, a4, a5, a6, a7;
                                    a1.loadFromFile("image/bg_night.jpg");
                                    a2.loadFromFile("image/play.jpg");
                                    a3.loadFromFile("image/sound.jpg");
                                    a4.loadFromFile("image/mute.jpg");
                                    a5.loadFromFile("image/restart.jpg");
                                    a6.loadFromFile("image/exit.jpg");
                                    a7.loadFromFile("image/galaxy.jpg");

                                    Text text1("Resume", best43, 20);
                                    Text text2("Restart", best43, 20);
                                    Text text3("Mute", best43, 20);
                                    Text text5("Sound", best43, 20);
                                    Text text4("Exit", best43, 20);
                                    Text text6("MATCH-3", best42, 45);
                                    Text text7("MANIA", best42, 28);

                                    text1.setPosition(160,152);
                                    text2.setPosition(160,262);
                                    text3.setPosition(160,372);
                                    text5.setPosition(160,372);
                                    text4.setPosition(160,482);
                                    text6.setPosition(340,250);
                                    text7.setPosition(560,260);

                                    text1.setFillColor(Color::Yellow);
                                    text2.setFillColor(Color::Yellow);
                                    text3.setFillColor(Color::Yellow);
                                    text4.setFillColor(Color::Yellow);
                                    text5.setFillColor(Color::Yellow);
                                    text6.setFillColor(Color::Yellow);
                                    text7.setFillColor(Color::Yellow);

                                    Sprite play(a2), sound(a3), mute(a4), restart(a5), exit(a6), bg(a1), arrow_bg(a7);

                                    play.setPosition(30,85);
                                    restart.setPosition(30,205);
                                    mute.setPosition(30,325);
                                    sound.setPosition(30,325);
                                    exit.setPosition(30,445);
                                    arrow_bg.setPosition(155,posy);

                                    while(level_4.isOpen())
                                    {
                                        Event pause_event;
                                        while(level_4.pollEvent(pause_event))
                                        {
                                            if(pause_event.type==Event::KeyPressed)
                                            {
                                                if(Keyboard::isKeyPressed(Keyboard::Up))
                                                {
                                                    posy=posy-110;
                                                    if(posy<150)
                                                    {
                                                        posy=480;
                                                    }
                                                    arrow_bg.setPosition(155, posy);
                                                }
                                                else if(Keyboard::isKeyPressed(Keyboard::Down))
                                                {
                                                    posy=posy+110;
                                                    if(posy>480)
                                                    {
                                                        posy=150;
                                                    }
                                                    arrow_bg.setPosition(155, posy);
                                                }
                                                if(Keyboard::isKeyPressed(Keyboard::Enter))
                                                {
                                                    if(posy==370 && flag==0)
                                                    {
                                                        music4.stop();
                                                        flag=1;
                                                    }
                                                    else if(posy==370 && flag==1)
                                                    {
                                                        music4.play();
                                                        flag=0;
                                                    }
                                                    else if(posy==150)
                                                    {
                                                        clock_timer.restart();
                                                        goto game_event1;
                                                    }
                                                    else if(posy==260)
                                                    {
                                                        goto game_event2;
                                                    }
                                                    else if(posy==480)
                                                    {
                                                        level_4.close();
                                                    }
                                                }
                                            }
                                        }
                                        level_4.draw(bg);
                                        level_4.draw(arrow_bg);
                                        level_4.draw(play);
                                        level_4.draw(restart);
                                        if(flag==0)
                                        {
                                            level_4.draw(sound);
                                            level_4.draw(text5);
                                        }
                                        else if(flag==1)
                                        {
                                            level_4.draw(mute);
                                            level_4.draw(text3);
                                        }
                                        level_4.draw(exit);
                                        level_4.draw(text1);
                                        level_4.draw(text2);
                                        level_4.draw(text4);
                                        level_4.draw(text6);
                                        level_4.draw(text7);

                                        level_4.display();
                                    }

                                }
                            }
                            if(event.type == Event::Closed)
                            {
                                level_4.close();
                            }

                            if(event.type == Event::MouseButtonPressed)
                            {
                                if(event.key.code == Mouse::Left)
                                {
                                    if(!isSwap && !isMoving)
                                    {
                                        click++;
                                        position = Mouse::getPosition(level_4)-offset;
                                    }
                                }
                            }
                        }

                        //Score part

                        stringscore=""+to_string(pointy);
                        Text ttt2(stringscore, fontg, 25);
                        ttt2.setFillColor(sf::Color::Red);
                        ttt2.setPosition(425,70);

                        /*Score part End*/

                        /*time display part*/

                        stringminute1=""+to_string(minutecounting);
                        Text tminute1(stringminute1, fontg, 25);
                        tminute1.setFillColor(sf::Color::Red);
                        tminute1.setPosition(435,190);

                        stringsecond1=" : "+to_string(secondcounting);
                        Text tsecond1(stringsecond1, fontg, 25);
                        tsecond1.setFillColor(sf::Color::Red);
                        tsecond1.setPosition(450,190);

                        time = clock_timer.getElapsedTime();
                        secondcounting= time.asSeconds()+extra_timer;

                        /*Time display part End*/



                        //mouse click
                        if(click==1)
                        {
                            x0=position.x/tile+1;
                            y0=position.y/tile+1;
                        }
                        if(click==2)
                        {
                            x=position.x/tile+1;
                            y=position.y/tile+1;
                            if(abs(x-x0)+abs(y-y0)==1)
                            {
                                swap(grid[y0][x0],grid[y][x]);
                                isSwap=true;
                                click=0;
                            }
                            else
                            {
                                click=1;
                            }
                        }

                        //Match finding
                        for(int i=1; i<=8; i++)
                        {
                            for(int j=0; j<=8; j++)
                            {
                                if(grid[i][j].kind==grid[i+1][j].kind)
                                {
                                    if(grid[i][j].kind==grid[i-1][j].kind)
                                    {
                                        for(int n=-1; n<=1; n++)
                                        {
                                            grid[i+n][j].match++;
                                        }
                                    }
                                }

                                if(grid[i][j].kind==grid[i][j+1].kind)
                                {
                                    if(grid[i][j].kind==grid[i][j-1].kind)
                                    {
                                        for(int n=-1; n<=1; n++)
                                        {
                                            grid[i][j+n].match++;
                                        }
                                    }
                                }
                            }
                        }

                        //moving animation
                        isMoving=false;
                        for(int i=1; i<=8; i++)
                        {
                            for(int j=1; j<=8; j++)
                            {
                                piece &p = grid[i][j];
                                int dx,dy;
                                for(int n=0; n<4; n++)        // 4 times speed
                                {
                                    dx= p.x-p.col*tile;
                                    dy= p.y-p.row*tile;
                                    if(dx)
                                    {
                                        p.x=p.x-dx/abs(dx);
                                    }
                                    if(dy)
                                    {
                                        p.y=p.y-dy/abs(dy);
                                    }
                                }
                                if(dx||dy)
                                {
                                    isMoving=true;
                                }
                            }
                        }

                        //deleting animation
                        if(!isMoving)
                        {
                            for(int i=1; i<=8; i++)
                            {
                                for(int j=1; j<=8; j++)
                                {
                                    if(grid[i][j].match)
                                    {
                                        if(grid[i][j].deleteanimationstyle>10)
                                        {
                                            grid[i][j].deleteanimationstyle=grid[i][j].deleteanimationstyle-10;
                                            isMoving=true;
                                        }
                                    }
                                }
                            }
                        }

                        //get Score
                        int score=0;
                        for(int i=1; i<=8; i++)
                        {
                            for(int j=1; j<=8; j++)
                            {
                                score+=grid[i][j].match;

                                if(grid[i][j].match)
                                {
                                    pointy+=1;
                                }
                            }
                        }

                        //swap back is no match
                        if(isSwap && !isMoving)
                        {
                            if(!score)
                            {
                                swap(grid[y0][x0],grid[y][x]);
                                isSwap=false;
                            }
                        }


                        if(secondcounting>59)
                        {
                            minutecounting++;
                            if(minutecounting==2)
                            {
                                if(pointy>6500)
                                {
                                    ofstream writescore("highscore.txt");
                                    if(writescore.is_open())
                                    {
                                        if(pointy>h_points)
                                        {
                                            h_points=pointy;
                                        }
                                        writescore<<h_points;
                                    }
                                    writescore.close();

                                    Texture pass_bg;
                                    pass_bg.loadFromFile("image/bg_night.jpg");

                                    Sprite bg41(pass_bg);

                                    Text passT41("CONGRATULATIONS", best44, 45);
                                    Text passT42("Thank you for Playing our Game. Hope you", best43, 25);
                                    Text passT43("enjoyed this. We will try to improve our", best43, 25);
                                    Text passT44("game according all your needs. Thank you", best43, 25);
                                    Text passT45("Again...", best43, 25);

                                    passT41.setFillColor(Color::White);
                                    passT42.setFillColor(Color::White);
                                    passT43.setFillColor(Color::White);
                                    passT44.setFillColor(Color::White);
                                    passT45.setFillColor(Color::White);

                                    passT41.setPosition(160,150);
                                    passT42.setPosition(85,240);
                                    passT43.setPosition(85,300);
                                    passT44.setPosition(85,360);
                                    passT45.setPosition(85,420);

                                    while(level_4.isOpen())
                                    {
                                        Event pass_event;
                                        while(level_4.pollEvent(pass_event))
                                        {
                                            if(pass_event.type==Event::KeyPressed)
                                            {

                                                if(Keyboard::isKeyPressed(Keyboard::Enter))
                                                {
                                                    music4.stop();
                                                    level_4.close();
                                                }

                                            }
                                        }
                                        level_4.clear();
                                        level_4.draw(bg41);

                                        level_4.draw(passT41);
                                        level_4.draw(passT42);
                                        level_4.draw(passT43);
                                        level_4.draw(passT44);
                                        level_4.draw(passT45);

                                        level_4.display();
                                    }
                                }
                                else
                                {
                                    ofstream writescore("highscore.txt");
                                    if(writescore.is_open())
                                    {
                                        if(pointy>h_points)
                                        {
                                            h_points=pointy;
                                        }
                                        writescore<<h_points;
                                    }
                                    writescore.close();

                                    level_4.close();
                                    move_ending_page();
                                }
                            }
                            extra_timer=0;
                            time = clock_timer.restart();
                        }


                        //grid updating after matching
                        if(!isMoving)
                        {
                            for(int i=8; i>=1; i--)
                            {
                                for(int j=1; j<=8; j++)
                                {
                                    if(grid[i][j].match)
                                    {
                                        for(int n=i; n>=1; n--)
                                        {
                                            if(!grid[n][j].match)
                                            {
                                                swap(grid[n][j],grid[i][j]);
                                                break;
                                            }
                                        }
                                    }
                                }
                            }

                            for(int j=1; j<=8; j++)
                            {
                                for(int i=8,n=0; i>=1; i--)
                                {
                                    if(grid[i][j].match)
                                    {
                                        grid[i][j].kind=rand()%6;
                                        grid[i][j].y= -tile*n++;
                                        grid[i][j].match=0;
                                        grid[i][j].deleteanimationstyle=255;
                                    }
                                }
                            }
                        }

                        //draw//
                        level_4.draw(background);

                        for(int i=1; i<=8; i++)
                        {
                            for(int j=1; j<=8; j++)
                            {
                                piece p = grid[i][j];
                                gems.setTextureRect(IntRect(p.kind*43,0,45,45));
                                gems.setColor(Color(255,255,255,p.deleteanimationstyle));
                                gems.setPosition(p.x,p.y);
                                gems.move(offset.x-tile,offset.y-tile);
                                level_4.draw(gems);
                            }
                        }

                        level_4.draw(game1);
                        level_4.draw(game2);
                        level_4.draw(game3);
                        level_4.draw(point_bg3);
                        level_4.draw(game4);
                        level_4.draw(game5);
                        level_4.draw(game6);
                        level_4.draw(game7);

                        level_4.draw(point_bg);
                        level_4.draw(point_bg2);
                        level_4.draw(point_bg4);
                        level_4.draw(ttt2);
                        level_4.draw(tminute1);
                        level_4.draw(tsecond1);
                        level_4.draw(escape);

                        level_4.display();

                    }
                }

            }
        }

        level_4.clear();
        level_4.draw(Back4);
        level_4.draw(t41);
        level_4.draw(exitarrow);
        clock4++;
        if(clock4%300<150)
        {
            level_4.draw(t42);
        }
        level_4.draw(t43);
        level_4.display();
    }
}


void Level3_page(int flag)
{
level_event1:
    Music music3;
    music3.openFromFile("music/candy crush.ogg");

    RenderWindow level_3(VideoMode(760,600), "Level - 3");

    int posy;

    Font best31, best32,best33,best34,best35;
    best31.loadFromFile("fonts/comic.ttf");
    best32.loadFromFile("fonts/VINERITC.ttf");
    best33.loadFromFile("fonts/OCRAEXT.ttf");
    best34.loadFromFile("fonts/COLONNA.ttf");
    best35.loadFromFile("fonts/ITCKRIST.ttf");

    int clock3=0;

    Text t31("LEVEL -- 3", best31, 65);
    Text t32("<Press ENTER to Continue>", best32, 30);
    Text t33("Press ESC to exit", best33, 30);

    t31.setFillColor(sf::Color::Magenta);
    t32.setFillColor(sf::Color::Yellow);

    t31.setPosition(220,245);
    t32.setPosition(175,500);
    t33.setPosition(45, 2);

    Texture bg3, arrow_exit;
    bg3.loadFromFile("image/bg_night.jpg");
    arrow_exit.loadFromFile("image/dynamic_blue_left.png");

    Sprite Back3(bg3), exitarrow(arrow_exit);
    exitarrow.setPosition(-3, 0);

    if(flag==0)
    {
        music3.play();
    }
    else if(flag==1)
    {
        music3.stop();
    }

    while(level_3.isOpen())
    {
        Event starting3;
        while(level_3.pollEvent(starting3))
        {
            if(starting3.type== Event::KeyPressed)
            {

                if(Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    level_3.close();
                }

                if(Keyboard::isKeyPressed(Keyboard::Enter))
                {
game_event2:
                    sf::Clock clock_timer;

                    sf::Time time;

                    level_3.setFramerateLimit(65);

                    pointx=0;
                    minutecounting=0;
                    secondcounting=0;
                    extra_timer=0;
                    posy=150;

                    Texture t1,t2,t3,t4,t5,t6,t7;
                    t1.loadFromFile("image/bg_night.jpg");
                    t2.loadFromFile("image/gems.png");
                    t3.loadFromFile("image/button2.png");
                    t4.loadFromFile("image/button2.png");
                    t5.loadFromFile("image/button3.png");
                    t6.loadFromFile("image/Design-PNG-Photo.png");
                    t7.loadFromFile("image/png.png");

                    Sprite background(t1), gems(t2),point_bg(t3), point_bg2(t4), point_bg3(t5), point_bg4(t6), escape(t7);
                    point_bg.setPosition(420,70);
                    point_bg2.setPosition(420,190);
                    point_bg3.setPosition(420,310);
                    point_bg4.setPosition(590,420);
                    escape.setPosition(5,510);

                    //game page writings

                    Font fontg;
                    fontg.loadFromFile("fonts/ALGER.ttf");
                    Text game1("Score :", fontg, 35);
                    Text game2("Time :", fontg, 35);
                    Text game3("Target ::", fontg, 35);
                    Text game4("more than $ 6000 $", fontg, 15);
                    Text game5("Within 2 minutes...", fontg, 15);
                    Text game6("Press ESC to pause", best33, 25);
                    Text game7("# Level - 3", best31, 45);
                    game1.setPosition(420,20);
                    game2.setPosition(420,140);
                    game3.setPosition(420,260);
                    game4.setPosition(420,310);
                    game5.setPosition(420,330);
                    game6.setPosition(60,510);
                    game7.setPosition(5,440);
                    game1.setFillColor(sf::Color::Yellow);
                    game2.setFillColor(sf::Color::Yellow);
                    game3.setFillColor(sf::Color::Yellow);
                    game4.setFillColor(Color::Red);
                    game5.setFillColor(Color::Red);
                    game6.setFillColor(Color::Yellow);
                    game7.setFillColor(Color::Yellow);


                    //game code

                    for(int i=1; i<=8; i++)
                    {
                        for(int j=1; j<=8; j++)
                        {
                            grid[i][j].kind=rand()%5;
                            grid[i][j].col=j;
                            grid[i][j].row=i;
                            grid[i][j].x=j*tile;
                            grid[i][j].y=i*tile;
                        }
                    }

                    int x0,y0,x,y;
                    int click=0;
                    Vector2i position;

                    bool isSwap=false, isMoving=false;
game_event1:
                    while(level_3.isOpen())
                    {
                        Event event;
                        while(level_3.pollEvent(event))
                        {
                            if(event.type==Event::KeyPressed)
                            {
                                if(Keyboard::isKeyPressed(Keyboard::Escape))
                                {
                                    /* PAUSE MENU for LEVEL _ 3 */

                                    extra_timer=secondcounting;

                                    Texture a1, a2, a3, a4, a5, a6, a7;
                                    a1.loadFromFile("image/bg_night.jpg");
                                    a2.loadFromFile("image/play.jpg");
                                    a3.loadFromFile("image/sound.jpg");
                                    a4.loadFromFile("image/mute.jpg");
                                    a5.loadFromFile("image/restart.jpg");
                                    a6.loadFromFile("image/exit.jpg");
                                    a7.loadFromFile("image/galaxy.jpg");

                                    Text text1("Resume", best33, 20);
                                    Text text2("Restart", best33, 20);
                                    Text text3("Mute", best33, 20);
                                    Text text5("Sound", best33, 20);
                                    Text text4("Exit", best33, 20);
                                    Text text6("MATCH-3", best32, 45);
                                    Text text7("MANIA", best32, 28);

                                    text1.setPosition(160,152);
                                    text2.setPosition(160,262);
                                    text3.setPosition(160,372);
                                    text5.setPosition(160,372);
                                    text4.setPosition(160,482);
                                    text6.setPosition(340,250);
                                    text7.setPosition(560,260);

                                    text1.setFillColor(Color::Yellow);
                                    text2.setFillColor(Color::Yellow);
                                    text3.setFillColor(Color::Yellow);
                                    text4.setFillColor(Color::Yellow);
                                    text5.setFillColor(Color::Yellow);
                                    text6.setFillColor(Color::Yellow);
                                    text7.setFillColor(Color::Yellow);

                                    Sprite play(a2), sound(a3), mute(a4), restart(a5), exit(a6), bg(a1), arrow_bg(a7);

                                    play.setPosition(30,85);
                                    restart.setPosition(30,205);
                                    mute.setPosition(30,325);
                                    sound.setPosition(30,325);
                                    exit.setPosition(30,445);
                                    arrow_bg.setPosition(155,posy);

                                    while(level_3.isOpen())
                                    {
                                        Event pause_event;
                                        while(level_3.pollEvent(pause_event))
                                        {
                                            if(pause_event.type==Event::KeyPressed)
                                            {
                                                if(Keyboard::isKeyPressed(Keyboard::Up))
                                                {
                                                    posy=posy-110;
                                                    if(posy<150)
                                                    {
                                                        posy=480;
                                                    }
                                                    arrow_bg.setPosition(155, posy);
                                                }
                                                else if(Keyboard::isKeyPressed(Keyboard::Down))
                                                {
                                                    posy=posy+110;
                                                    if(posy>480)
                                                    {
                                                        posy=150;
                                                    }
                                                    arrow_bg.setPosition(155, posy);
                                                }
                                                if(Keyboard::isKeyPressed(Keyboard::Enter))
                                                {
                                                    if(posy==370 && flag==0)
                                                    {
                                                        music3.stop();
                                                        flag=1;
                                                    }
                                                    else if(posy==370 && flag==1)
                                                    {
                                                        music3.play();
                                                        flag=0;
                                                    }
                                                    else if(posy==150)
                                                    {
                                                        clock_timer.restart();
                                                        goto game_event1;
                                                    }
                                                    else if(posy==260)
                                                    {
                                                        goto game_event2;
                                                    }
                                                    else if(posy==480)
                                                    {
                                                        level_3.close();
                                                    }
                                                }
                                            }
                                        }
                                        level_3.draw(bg);
                                        level_3.draw(arrow_bg);
                                        level_3.draw(play);
                                        level_3.draw(restart);
                                        if(flag==0)
                                        {
                                            level_3.draw(sound);
                                            level_3.draw(text5);
                                        }
                                        else if(flag==1)
                                        {
                                            level_3.draw(mute);
                                            level_3.draw(text3);
                                        }
                                        level_3.draw(exit);
                                        level_3.draw(text1);
                                        level_3.draw(text2);
                                        level_3.draw(text4);
                                        level_3.draw(text6);
                                        level_3.draw(text7);

                                        level_3.display();
                                    }

                                }
                            }
                            if(event.type == Event::Closed)
                            {
                                level_3.close();
                            }

                            if(event.type == Event::MouseButtonPressed)
                            {
                                if(event.key.code == Mouse::Left)
                                {
                                    if(!isSwap && !isMoving)
                                    {
                                        click++;
                                        position = Mouse::getPosition(level_3)-offset;
                                    }
                                }
                            }
                        }

                        //Score part

                        stringscore=""+to_string(pointx);
                        Text ttt2(stringscore, fontg, 25);
                        ttt2.setFillColor(sf::Color::Red);
                        ttt2.setPosition(425,70);

                        /*Score part End*/

                        /*time display part*/

                        stringminute1=""+to_string(minutecounting);
                        Text tminute1(stringminute1, fontg, 25);
                        tminute1.setFillColor(sf::Color::Red);
                        tminute1.setPosition(435,190);

                        stringsecond1=" : "+to_string(secondcounting);
                        Text tsecond1(stringsecond1, fontg, 25);
                        tsecond1.setFillColor(sf::Color::Red);
                        tsecond1.setPosition(450,190);

                        time = clock_timer.getElapsedTime();
                        secondcounting= time.asSeconds()+extra_timer;

                        /*Time display part End*/



                        //mouse click
                        if(click==1)
                        {
                            x0=position.x/tile+1;
                            y0=position.y/tile+1;
                        }
                        if(click==2)
                        {
                            x=position.x/tile+1;
                            y=position.y/tile+1;
                            if(abs(x-x0)+abs(y-y0)==1)
                            {
                                swap(grid[y0][x0],grid[y][x]);
                                isSwap=true;
                                click=0;
                            }
                            else
                            {
                                click=1;
                            }
                        }

                        //Match finding
                        for(int i=1; i<=8; i++)
                        {
                            for(int j=0; j<=8; j++)
                            {
                                if(grid[i][j].kind==grid[i+1][j].kind)
                                {
                                    if(grid[i][j].kind==grid[i-1][j].kind)
                                    {
                                        for(int n=-1; n<=1; n++)
                                        {
                                            grid[i+n][j].match++;
                                        }
                                    }
                                }

                                if(grid[i][j].kind==grid[i][j+1].kind)
                                {
                                    if(grid[i][j].kind==grid[i][j-1].kind)
                                    {
                                        for(int n=-1; n<=1; n++)
                                        {
                                            grid[i][j+n].match++;
                                        }
                                    }
                                }
                            }
                        }

                        //moving animation
                        isMoving=false;
                        for(int i=1; i<=8; i++)
                        {
                            for(int j=1; j<=8; j++)
                            {
                                piece &p = grid[i][j];
                                int dx,dy;
                                for(int n=0; n<4; n++)        // 4 times speed
                                {
                                    dx= p.x-p.col*tile;
                                    dy= p.y-p.row*tile;
                                    if(dx)
                                    {
                                        p.x=p.x-dx/abs(dx);
                                    }
                                    if(dy)
                                    {
                                        p.y=p.y-dy/abs(dy);
                                    }
                                }
                                if(dx||dy)
                                {
                                    isMoving=true;
                                }
                            }
                        }

                        //deleting animation
                        if(!isMoving)
                        {
                            for(int i=1; i<=8; i++)
                            {
                                for(int j=1; j<=8; j++)
                                {
                                    if(grid[i][j].match)
                                    {
                                        if(grid[i][j].deleteanimationstyle>10)
                                        {
                                            grid[i][j].deleteanimationstyle=grid[i][j].deleteanimationstyle-10;
                                            isMoving=true;
                                        }
                                    }
                                }
                            }
                        }

                        //get Score
                        int score=0;
                        for(int i=1; i<=8; i++)
                        {
                            for(int j=1; j<=8; j++)
                            {
                                score+=grid[i][j].match;

                                if(grid[i][j].match)
                                {
                                    pointx+=1;
                                }
                            }
                        }

                        //swap back is no match
                        if(isSwap && !isMoving)
                        {
                            if(!score)
                            {
                                swap(grid[y0][x0],grid[y][x]);
                                isSwap=false;
                            }
                        }


                        if(secondcounting>59)
                        {
                            minutecounting++;
                            if(minutecounting==2)
                            {
                                if(pointx>6000)
                                {
                                    ofstream writescore("highscore.txt");
                                    if(writescore.is_open())
                                    {
                                        if(pointy>h_points)
                                        {
                                            h_points=pointy;
                                        }
                                        writescore<<h_points;
                                    }
                                    writescore.close();

                                    Texture pass_bg, pass_bg2;
                                    pass_bg.loadFromFile("image/bg_night.jpg");

                                    Sprite bg31(pass_bg);

                                    Text passT31("CONGRATULATIONS", best34, 45);
                                    Text passT32("You PASSED this Level", best35, 35);
                                    Text passT33("Press ENTER for Next Level", best33, 30);

                                    passT31.setFillColor(Color::White);
                                    passT32.setFillColor(Color::White);
                                    passT33.setFillColor(Color::White);

                                    passT31.setPosition(160,150);
                                    passT32.setPosition(180,350);
                                    passT33.setPosition(175,500);

                                    while(level_3.isOpen())
                                    {
                                        Event pass_event;
                                        while(level_3.pollEvent(pass_event))
                                        {
                                            if(pass_event.type==Event::KeyPressed)
                                            {

                                                if(Keyboard::isKeyPressed(Keyboard::Enter))
                                                {
                                                    music3.stop();
                                                    level_3.close();
                                                    Level4_page(flag);
                                                }

                                            }
                                        }
                                        level_3.clear();
                                        level_3.draw(bg31);

                                        level_3.draw(passT31);
                                        level_3.draw(passT32);
                                        level_3.draw(passT33);

                                        level_3.display();
                                    }
                                }
                                else
                                {
                                    ofstream writescore("highscore.txt");
                                    if(writescore.is_open())
                                    {
                                        if(pointy>h_points)
                                        {
                                            h_points=pointy;
                                        }
                                        writescore<<h_points;
                                    }
                                    writescore.close();

                                    level_3.close();
                                    move_ending_page();
                                }
                            }
                            extra_timer=0;
                            time = clock_timer.restart();
                        }


                        //grid updating after matching
                        if(!isMoving)
                        {
                            for(int i=8; i>=1; i--)
                            {
                                for(int j=1; j<=8; j++)
                                {
                                    if(grid[i][j].match)
                                    {
                                        for(int n=i; n>=1; n--)
                                        {
                                            if(!grid[n][j].match)
                                            {
                                                swap(grid[n][j],grid[i][j]);
                                                break;
                                            }
                                        }
                                    }
                                }
                            }

                            for(int j=1; j<=8; j++)
                            {
                                for(int i=8,n=0; i>=1; i--)
                                {
                                    if(grid[i][j].match)
                                    {
                                        grid[i][j].kind=rand()%5;
                                        grid[i][j].y= -tile*n++;
                                        grid[i][j].match=0;
                                        grid[i][j].deleteanimationstyle=255;
                                    }
                                }
                            }
                        }

                        //draw//
                        level_3.draw(background);

                        for(int i=1; i<=8; i++)
                        {
                            for(int j=1; j<=8; j++)
                            {
                                piece p = grid[i][j];
                                gems.setTextureRect(IntRect(p.kind*43,0,45,45));
                                gems.setColor(Color(255,255,255,p.deleteanimationstyle));
                                gems.setPosition(p.x,p.y);
                                gems.move(offset.x-tile,offset.y-tile);
                                level_3.draw(gems);
                            }
                        }

                        level_3.draw(game1);
                        level_3.draw(game2);
                        level_3.draw(game3);
                        level_3.draw(point_bg3);
                        level_3.draw(game4);
                        level_3.draw(game5);
                        level_3.draw(game6);
                        level_3.draw(game7);

                        level_3.draw(point_bg);
                        level_3.draw(point_bg2);
                        level_3.draw(point_bg4);
                        level_3.draw(ttt2);
                        level_3.draw(tminute1);
                        level_3.draw(tsecond1);
                        level_3.draw(escape);

                        level_3.display();

                    }
                }

            }
        }

        level_3.clear();
        level_3.draw(Back3);
        level_3.draw(exitarrow);
        level_3.draw(t33);
        level_3.draw(t31);
        clock3++;
        if(clock3%300<150)
        {
            level_3.draw(t32);
        }

        level_3.display();
    }
}


void Level2_page(int flag)
{
level_event2:
    Music music2;
    music2.openFromFile("music/candy crush.ogg");

    int posy;
    int clock2=0;

    Font best21, best22, best23, best24, best25;
    best21.loadFromFile("fonts/comic.ttf");
    best22.loadFromFile("fonts/VINERITC.ttf");
    best23.loadFromFile("fonts/OCRAEXT.ttf");
    best24.loadFromFile("fonts/COLONNA.ttf");
    best25.loadFromFile("fonts/ITCKRIST.ttf");

    RenderWindow level_2(VideoMode(760,600), "Level_2 Starting");

    Text t21("LEVEL -- 2", best21, 65);
    Text t22("<Press ENTER to Continue>", best22, 30);
    Text t23("Press ESC for exit", best23, 30);

    t21.setFillColor(sf::Color::Magenta);
    t22.setFillColor(sf::Color::Yellow);

    t21.setPosition(220,245);
    t22.setPosition(175,500);
    t23.setPosition(45,2);

    Texture bg2, arrowexit;
    bg2.loadFromFile("image/bg_night.jpg");
    arrowexit.loadFromFile("image/dynamic_blue_left.png");

    Sprite Back2(bg2), arrow_2(arrowexit);
    arrow_2.setPosition(-3,0);

    if(flag==0)
    {
        music2.play();
    }
    else if(flag==1)
    {
        music2.stop();
    }

    while(level_2.isOpen())
    {
        Event starting2;
        while(level_2.pollEvent(starting2))
        {
            if(starting2.type== Event::KeyPressed)
            {

                if(Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    level_2.close();
                }

                if(Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    /* Game Code for LEVEL -2 */
game_event2:
                    level_2.setFramerateLimit(65);

                    pointy=0;
                    moves2=20;
                    posy=150;

                    Texture t1, t2, t3, t4, t5, t6, t7;
                    t1.loadFromFile("image/bg_night.jpg");
                    t2.loadFromFile("image/gems.png");
                    t3.loadFromFile("image/button2.png");
                    t4.loadFromFile("image/button2.png");
                    t5.loadFromFile("image/button2.png");
                    t6.loadFromFile("image/Design-PNG-Photo.png");
                    t7.loadFromFile("image/png.png");

                    Sprite background(t1), gems(t2),point_bg(t3), point_bg2(t4), point_bg3(t5), point_bg4(t6), escape(t7);
                    point_bg.setPosition(420,70);
                    point_bg2.setPosition(420,190);
                    point_bg3.setPosition(420,310);
                    point_bg4.setPosition(590,420);
                    escape.setPosition(5,510);

                    //game page writings

                    Font fontg;
                    fontg.loadFromFile("fonts/ALGER.ttf");
                    Text game1("Score :", fontg, 35);
                    Text game2("Moves :", fontg, 35);
                    Text game3("Target ::", fontg, 35);
                    Text game4("$ 5000 $", fontg, 25);
                    Text game5("Press ESC to Pause", best23, 25);
                    Text game6("# Level - 2", best21, 45);
                    game1.setPosition(420,20);
                    game2.setPosition(420,140);
                    game3.setPosition(420,260);
                    game4.setPosition(425,310);
                    game5.setPosition(60,510);
                    game6.setPosition(5,440);
                    game1.setFillColor(sf::Color::Yellow);
                    game2.setFillColor(sf::Color::Yellow);
                    game3.setFillColor(sf::Color::Yellow);
                    game4.setFillColor(sf::Color::Red);
                    game5.setFillColor(sf::Color::Yellow);
                    game6.setFillColor(sf::Color::Yellow);


                    /*GAME  CODE*/

                    for(int i=1; i<=8; i++)
                    {
                        for(int j=1; j<=8; j++)
                        {
                            grid[i][j].kind=rand()%6;
                            grid[i][j].col=j;
                            grid[i][j].row=i;
                            grid[i][j].x=j*tile;
                            grid[i][j].y=i*tile;
                        }
                    }

                    int x0,y0,x,y;
                    int click=0;
                    Vector2i position;

                    bool isSwap=false, isMoving=false;
game_event1:
                    while(level_2.isOpen())
                    {
                        Event event;
                        while(level_2.pollEvent(event))
                        {
                            if(event.type == Event::KeyPressed)
                            {
                                if(Keyboard::isKeyPressed(Keyboard::Escape))
                                {
                                    /* PAUSE MENU for LEVEL _ 2 */

                                    Texture a1,a2,a3,a4,a5,a6,a7;
                                    a1.loadFromFile("image/bg_night.jpg");
                                    a2.loadFromFile("image/play.jpg");
                                    a3.loadFromFile("image/sound.jpg");
                                    a4.loadFromFile("image/mute.jpg");
                                    a5.loadFromFile("image/restart.jpg");
                                    a6.loadFromFile("image/exit.jpg");
                                    a7.loadFromFile("image/galaxy.jpg");

                                    Text text1("Resume", best23, 20);
                                    Text text2("Restart", best23, 20);
                                    Text text3("Mute", best23, 20);
                                    Text text4("Sound", best23, 20);
                                    Text text5("Exit", best23, 20);
                                    Text text6("MATCH-3", best22, 45);
                                    Text text7("MANIA", best22, 28);

                                    text1.setPosition(160,152);
                                    text2.setPosition(160,262);
                                    text3.setPosition(160,372);
                                    text4.setPosition(160,372);
                                    text5.setPosition(160,482);
                                    text6.setPosition(340,250);
                                    text7.setPosition(560,260);

                                    text1.setFillColor(Color::Yellow);
                                    text2.setFillColor(Color::Yellow);
                                    text3.setFillColor(Color::Yellow);
                                    text4.setFillColor(Color::Yellow);
                                    text5.setFillColor(Color::Yellow);
                                    text6.setFillColor(Color::Yellow);
                                    text7.setFillColor(Color::Yellow);

                                    Sprite play(a2), sound(a3), mute(a4), restart(a5), bg(a1), exit(a6), arrow_bg(a7);

                                    play.setPosition(30,85);
                                    restart.setPosition(30,205);
                                    mute.setPosition(30,325);
                                    sound.setPosition(30,325);
                                    exit.setPosition(30,445);
                                    arrow_bg.setPosition(155,posy);

                                    while(level_2.isOpen())
                                    {
                                        Event pause_event;
                                        while(level_2.pollEvent(pause_event))
                                        {
                                            if(pause_event.type == Event::KeyPressed)
                                            {
                                                if(Keyboard::isKeyPressed(Keyboard::Up))
                                                {
                                                    posy=posy-110;
                                                    if(posy<150)
                                                    {
                                                        posy=480;
                                                    }

                                                    arrow_bg.setPosition(155,posy);
                                                }

                                                else if(Keyboard::isKeyPressed(Keyboard::Down))
                                                {
                                                    posy=posy+110;
                                                    if(posy>480)
                                                    {
                                                        posy=150;
                                                    }

                                                    arrow_bg.setPosition(155,posy);
                                                }

                                                else if(Keyboard::isKeyPressed(Keyboard::Enter))
                                                {
                                                    if(posy==370 && flag==0)
                                                    {
                                                        music2.stop();
                                                        flag=1;
                                                    }

                                                    else if(posy==370 && flag==1)
                                                    {
                                                        music2.play();
                                                        flag=0;
                                                    }

                                                    else if(posy==150)
                                                    {
                                                        goto game_event1;
                                                    }

                                                    else if(posy==260)
                                                    {
                                                        goto game_event2;
                                                    }

                                                    else if(posy==480)
                                                    {
                                                        level_2.close();
                                                    }
                                                }
                                            }
                                        }
                                        level_2.draw(bg);
                                        level_2.draw(arrow_bg);
                                        level_2.draw(play);
                                        level_2.draw(restart);
                                        if(flag==0)
                                        {
                                            level_2.draw(sound);
                                            level_2.draw(text4);
                                        }
                                        else if(flag==1)
                                        {
                                            level_2.draw(mute);
                                            level_2.draw(text3);
                                        }
                                        level_2.draw(exit);
                                        level_2.draw(text1);
                                        level_2.draw(text2);
                                        level_2.draw(text5);
                                        level_2.draw(text6);
                                        level_2.draw(text7);

                                        level_2.display();
                                    }
                                }
                            }
                            else if(event.type == Event::Closed)
                            {
                                level_2.close();
                            }

                            if(event.type == Event::MouseButtonPressed)
                            {
                                if(event.key.code == Mouse::Left)
                                {
                                    if(!isSwap && !isMoving)
                                    {
                                        click++;
                                        position = Mouse::getPosition(level_2)-offset;
                                    }
                                }
                            }
                        }

                        /*Score display part*/

                        stringscore=""+to_string(pointy);
                        Text tscore2(stringscore, fontg, 25);
                        tscore2.setFillColor(sf::Color::Red);
                        tscore2.setPosition(425,70);

                        /*Score display part End*/

                        /*Move display part*/

                        stringmove=""+to_string(moves2);
                        Text tmove2(stringmove, fontg, 25);
                        tmove2.setFillColor(sf::Color::Red);
                        tmove2.setPosition(425,190);

                        /*Move display part End*/




                        //mouse click
                        if(click==1)
                        {
                            x0=position.x/tile+1;
                            y0=position.y/tile+1;
                        }
                        if(click==2)
                        {
                            x=position.x/tile+1;
                            y=position.y/tile+1;
                            if(abs(x-x0)+abs(y-y0)==1)
                            {
                                swap(grid[y0][x0],grid[y][x]);
                                isSwap=true;
                                click=0;
                                moves2--;
                            }
                            else
                            {
                                click=1;
                            }
                        }

                        //Match finding
                        for(int i=1; i<=8; i++)
                        {
                            for(int j=0; j<=8; j++)
                            {
                                if(grid[i][j].kind==grid[i+1][j].kind)
                                {
                                    if(grid[i][j].kind==grid[i-1][j].kind)
                                    {
                                        for(int n=-1; n<=1; n++)
                                        {
                                            grid[i+n][j].match++;
                                        }
                                    }
                                }

                                if(grid[i][j].kind==grid[i][j+1].kind)
                                {
                                    if(grid[i][j].kind==grid[i][j-1].kind)
                                    {
                                        for(int n=-1; n<=1; n++)
                                        {
                                            grid[i][j+n].match++;
                                        }
                                    }
                                }
                            }
                        }

                        //moving animation
                        isMoving=false;
                        for(int i=1; i<=8; i++)
                        {
                            for(int j=1; j<=8; j++)
                            {
                                piece &p = grid[i][j];
                                int dx,dy;
                                for(int n=0; n<4; n++)        // 4 times speed
                                {
                                    dx= p.x-p.col*tile;
                                    dy= p.y-p.row*tile;
                                    if(dx)
                                    {
                                        p.x=p.x-dx/abs(dx);
                                    }
                                    if(dy)
                                    {
                                        p.y=p.y-dy/abs(dy);
                                    }
                                }
                                if(dx||dy)
                                {
                                    isMoving=true;
                                }
                            }
                        }

                        //deleting animation
                        if(!isMoving)
                        {
                            for(int i=1; i<=8; i++)
                            {
                                for(int j=1; j<=8; j++)
                                {
                                    if(grid[i][j].match)
                                    {
                                        if(grid[i][j].deleteanimationstyle>10)
                                        {
                                            grid[i][j].deleteanimationstyle=grid[i][j].deleteanimationstyle-10;
                                            isMoving=true;
                                        }
                                    }
                                }
                            }
                        }


                        //get Score
                        int score=0;
                        for(int i=1; i<=8; i++)
                        {
                            for(int j=1; j<=8; j++)
                            {
                                score+=grid[i][j].match;

                                if(grid[i][j].match)
                                {
                                    //point = ;
                                    pointy+=1;
                                    if(pointy>5000)
                                    {
                                        if(moves2>0)
                                        {
                                            ofstream writescore("highscore.txt");
                                            if(writescore.is_open())
                                            {
                                                if(pointy>h_points)
                                                {
                                                    h_points=pointy;
                                                }
                                                writescore<<h_points;
                                            }
                                            writescore.close();

                                            Texture pass_bg,pass_bg2;
                                            pass_bg.loadFromFile("image/bg_night.jpg");

                                            Sprite bg21_pass(pass_bg);

                                            Text passT21("CONGRATULATIONS..!!", best24, 45);
                                            Text passT22("You PASSED this Level", best25, 35);
                                            Text passT23("Press ENTER for Next Level", best23, 30);

                                            passT21.setFillColor(sf::Color::Yellow);
                                            passT22.setFillColor(sf::Color::Yellow);
                                            passT23.setFillColor(sf::Color::Yellow);

                                            passT21.setPosition(160,150);
                                            passT22.setPosition(180,350);
                                            passT23.setPosition(175,500);

                                            while(level_2.isOpen())
                                            {
                                                Event pass_event;
                                                while(level_2.pollEvent(pass_event))
                                                {
                                                    if(pass_event.type== Event::KeyPressed)
                                                    {

                                                        if(Keyboard::isKeyPressed(Keyboard::Enter))
                                                        {
                                                            music2.stop();
                                                            level_2.close();
                                                            Level3_page(flag);
                                                        }

                                                    }
                                                }

                                                level_2.clear();
                                                level_2.draw(bg21_pass);

                                                level_2.draw(passT21);
                                                level_2.draw(passT22);
                                                level_2.draw(passT23);

                                                level_2.display();
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        //swap back is no match
                        if(isSwap && !isMoving)
                        {
                            if(!score)
                            {
                                swap(grid[y0][x0],grid[y][x]);
                                isSwap=false;
                            }
                        }

                        //grid updating after matching
                        if(!isMoving)
                        {
                            for(int i=8; i>=1; i--)
                            {
                                for(int j=1; j<=8; j++)
                                {
                                    if(grid[i][j].match)
                                    {
                                        for(int n=i; n>=1; n--)
                                        {
                                            if(!grid[n][j].match)
                                            {
                                                swap(grid[n][j],grid[i][j]);
                                                break;
                                            }
                                        }
                                    }
                                }
                            }

                            for(int j=1; j<=8; j++)
                            {
                                for(int i=8,n=0; i>=1; i--)
                                {
                                    if(grid[i][j].match)
                                    {
                                        grid[i][j].kind=rand()%6;
                                        grid[i][j].y= -tile*n++;
                                        grid[i][j].match=0;
                                        grid[i][j].deleteanimationstyle=255;
                                    }
                                }
                            }
                        }

                        //draw//
                        level_2.draw(background);

                        for(int i=1; i<=8; i++)
                        {
                            for(int j=1; j<=8; j++)
                            {
                                piece p = grid[i][j];
                                gems.setTextureRect(IntRect(p.kind*43,0,45,45));
                                gems.setColor(Color(255,255,255,p.deleteanimationstyle));
                                gems.setPosition(p.x,p.y);
                                gems.move(offset.x-tile,offset.y-tile);
                                level_2.draw(gems);
                            }
                        }

                        level_2.draw(game1);
                        level_2.draw(game2);
                        level_2.draw(game3);
                        level_2.draw(escape);
                        level_2.draw(game5);
                        level_2.draw(game6);

                        level_2.draw(point_bg);
                        level_2.draw(point_bg2);
                        level_2.draw(point_bg3);
                        level_2.draw(point_bg4);
                        level_2.draw(game4);
                        level_2.draw(tscore2);
                        level_2.draw(tmove2);

                        level_2.display();

                        if(moves2==0)
                        {
                            if(pointy<5000)
                            {
                                ofstream writescore("highscore.txt");
                                if(writescore.is_open())
                                {
                                    if(pointy>h_points)
                                    {
                                        h_points=pointy;
                                    }
                                    writescore<<h_points;
                                }
                                writescore.close();

                                level_2.close();
                                move_ending_page();
                            }
                        }

                    }
                }

            }
        }

        level_2.clear();
        level_2.draw(Back2);
        level_2.draw(arrow_2);
        level_2.draw(t21);
        clock2++;
        if(clock2%300<150)
        {
            level_2.draw(t22);
        }
        level_2.draw(t23);

        level_2.display();
    }
}


void Level1_page(int flag)
{
level_event1:
    Music music1;
    music1.openFromFile("music/candy crush.ogg");

    int posy;
    int clock1=0;

    Font best11, best12,best13,best14,best15;
    best11.loadFromFile("fonts/comic.ttf");
    best12.loadFromFile("fonts/VINERITC.ttf");
    best13.loadFromFile("fonts/OCRAEXT.ttf");
    best14.loadFromFile("fonts/COLONNA.ttf");
    best15.loadFromFile("fonts/ITCKRIST.ttf");

    RenderWindow level_1(VideoMode(760,600), "Level_1 Starting");

    Text t11("LEVEL -- 1", best11, 65);
    Text t12("<Press ENTER to Continue>", best12, 30);
    Text t13("Press ESC to go back", best13, 30);

    t11.setFillColor(sf::Color::Red);
    t12.setFillColor(sf::Color::Yellow);

    t11.setPosition(220,245);
    t12.setPosition(175,500);
    t13.setPosition(45,2);

    Texture bg1,arrow1;
    bg1.loadFromFile("image/bg_night.jpg");
    arrow1.loadFromFile("image/dynamic_blue_left.png");

    Sprite Back1(bg1), arrow_1(arrow1);

    arrow_1.setPosition(-3,0);

    if(flag==0)
    {
        music1.play();
    }
    else if(flag==1)
    {
        music1.stop();
    }

    while(level_1.isOpen())
    {
        Event starting1;
        while(level_1.pollEvent(starting1))
        {
            if(starting1.type== Event::KeyPressed)
            {

                if(Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    level_1.close();
                }

                if(Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    /* Game Code for LEVEL - 1 */
game_event2:
                    level_1.setFramerateLimit(65);

                    pointx=0;
                    moves1=20;
                    posy=150;

                    Texture t1,t2,t3,t4,t5,t6,t7;
                    t1.loadFromFile("image/bg_night.jpg");
                    t2.loadFromFile("image/gems.png");
                    t3.loadFromFile("image/button2.png");
                    t4.loadFromFile("image/button2.png");
                    t5.loadFromFile("image/button2.png");
                    t6.loadFromFile("image/Design-PNG-Photo.png");
                    t7.loadFromFile("image/png.png");

                    Sprite background(t1), gems(t2),point_bg(t3), point_bg2(t4), point_bg3(t5), point_bg4(t6), escape(t7);
                    point_bg.setPosition(420,70);
                    point_bg2.setPosition(420,190);
                    point_bg3.setPosition(420,310);
                    point_bg4.setPosition(590,420);
                    escape.setPosition(5,510);

                    //game page writings

                    Font fontg;
                    fontg.loadFromFile("fonts/ALGER.ttf");
                    Text game1("Score :", fontg, 35);
                    Text game2("Moves :", fontg, 35);
                    Text game3("Target ::", fontg, 35);
                    Text game4("$ 5000 $", fontg, 25);
                    Text game5("Press ESC to Pause", best13, 25);
                    Text game6("# Level - 1", best11, 45);
                    game1.setPosition(420,20);
                    game2.setPosition(420,140);
                    game3.setPosition(420,260);
                    game4.setPosition(425,310);
                    game5.setPosition(60,510);
                    game6.setPosition(5,440);
                    game1.setFillColor(sf::Color::Yellow);
                    game2.setFillColor(sf::Color::Yellow);
                    game3.setFillColor(sf::Color::Yellow);
                    game4.setFillColor(sf::Color::Red);
                    game5.setFillColor(sf::Color::Yellow);
                    game6.setFillColor(sf::Color::Yellow);


                    //game code

                    for(int i=1; i<=8; i++)
                    {
                        for(int j=1; j<=8; j++)
                        {
                            grid[i][j].kind=rand()%5;         //randomly gems permutation
                            grid[i][j].col=j;
                            grid[i][j].row=i;
                            grid[i][j].x=j*tile;
                            grid[i][j].y=i*tile+40;
                        }
                    }

                    int x0,y0,x,y;
                    int click=0;
                    Vector2i position;

                    bool isSwap=false, isMoving=false;
game_event1:
                    while(level_1.isOpen())
                    {
                        Event event;
                        while(level_1.pollEvent(event))
                        {
                            if(event.type== Event::KeyPressed)
                            {
                                if(Keyboard::isKeyPressed(Keyboard::Escape))
                                {
                                    /* PAUSE MENU for LEVEL _ 1 */

                                    Texture a1, a2, a3, a4, a5, a6, a7;
                                    a1.loadFromFile("image/bg_night.jpg");
                                    a2.loadFromFile("image/play.jpg");
                                    a3.loadFromFile("image/sound.jpg");
                                    a4.loadFromFile("image/mute.jpg");
                                    a5.loadFromFile("image/restart.jpg");
                                    a6.loadFromFile("image/exit.jpg");
                                    a7.loadFromFile("image/galaxy.jpg");

                                    Text text1("Resume", best13, 20);
                                    Text text2("Restart", best13, 20);
                                    Text text3("Mute", best13, 20);
                                    Text text5("Sound", best13, 20);
                                    Text text4("Exit", best13, 20);
                                    Text text6("MATCH-3", best12, 45);
                                    Text text7("MANIA", best12, 28);

                                    text1.setPosition(160,152);
                                    text2.setPosition(160,262);
                                    text3.setPosition(160,372);
                                    text5.setPosition(160,372);
                                    text4.setPosition(160,482);
                                    text6.setPosition(340,250);
                                    text7.setPosition(560,260);

                                    text1.setFillColor(Color::Yellow);
                                    text2.setFillColor(Color::Yellow);
                                    text3.setFillColor(Color::Yellow);
                                    text4.setFillColor(Color::Yellow);
                                    text5.setFillColor(Color::Yellow);
                                    text6.setFillColor(Color::Yellow);
                                    text7.setFillColor(Color::Yellow);

                                    Sprite play(a2), sound(a3), mute(a4), restart(a5), exit(a6), bg(a1), arrow_bg(a7);

                                    play.setPosition(30,85);
                                    restart.setPosition(30,205);
                                    mute.setPosition(30,325);
                                    sound.setPosition(30,325);
                                    exit.setPosition(30,445);
                                    arrow_bg.setPosition(155,posy);

                                    while(level_1.isOpen())
                                    {
                                        Event pause_event;
                                        while(level_1.pollEvent(pause_event))
                                        {
                                            if(pause_event.type==Event::KeyPressed)
                                            {
                                                if(Keyboard::isKeyPressed(Keyboard::Up))
                                                {
                                                    posy=posy-110;
                                                    if(posy<150)
                                                    {
                                                        posy=480;
                                                    }
                                                    arrow_bg.setPosition(155, posy);
                                                }
                                                else if(Keyboard::isKeyPressed(Keyboard::Down))
                                                {
                                                    posy=posy+110;
                                                    if(posy>480)
                                                    {
                                                        posy=150;
                                                    }
                                                    arrow_bg.setPosition(155, posy);
                                                }
                                                if(Keyboard::isKeyPressed(Keyboard::Enter))
                                                {
                                                    if(posy==370 && flag==0)
                                                    {
                                                        music1.stop();
                                                        flag=1;
                                                    }
                                                    else if(posy==370 && flag==1)
                                                    {
                                                        music1.play();
                                                        flag=0;
                                                    }
                                                    else if(posy==150)
                                                    {
                                                        goto game_event1;
                                                    }
                                                    else if(posy==260)
                                                    {
                                                        goto game_event2;
                                                    }
                                                    else if(posy==480)
                                                    {
                                                        level_1.close();
                                                    }
                                                }
                                            }
                                        }
                                        level_1.draw(bg);
                                        level_1.draw(arrow_bg);
                                        level_1.draw(play);
                                        level_1.draw(restart);
                                        if(flag==0)
                                        {
                                            level_1.draw(sound);
                                            level_1.draw(text5);
                                        }
                                        else if(flag==1)
                                        {
                                            level_1.draw(mute);
                                            level_1.draw(text3);
                                        }
                                        level_1.draw(exit);
                                        level_1.draw(text1);
                                        level_1.draw(text2);
                                        level_1.draw(text4);
                                        level_1.draw(text6);
                                        level_1.draw(text7);

                                        level_1.display();
                                    }
                                }
                            }
                            else if(event.type == Event::Closed)
                            {
                                goto level_event1;
                            }

                            if(event.type == Event::MouseButtonPressed)
                            {
                                if(event.key.code == Mouse::Left)
                                {
                                    if(!isSwap && !isMoving)
                                    {
                                        click++;
                                        position = Mouse::getPosition(level_1)-offset;
                                    }
                                }
                            }
                        }

                        /*Score display part*/

                        stringscore=""+to_string(pointx);
                        Text ttt(stringscore, fontg, 25);
                        ttt.setFillColor(sf::Color::Red);
                        ttt.setPosition(425,70);

                        /*Score display part End*/

                        /*Move display part*/

                        stringmove=""+to_string(moves1);
                        Text ttmove(stringmove, fontg, 25);
                        ttmove.setFillColor(sf::Color::Red);
                        ttmove.setPosition(425,190);

                        /*Move display part End*/




                        //mouse click
                        if(click==1)
                        {
                            x0=position.x/tile+1;
                            y0=position.y/tile+1;
                        }
                        if(click==2)
                        {
                            x=position.x/tile+1;
                            y=position.y/tile+1;
                            if(abs(x-x0)+abs(y-y0)==1)
                            {
                                swap(grid[y0][x0],grid[y][x]);
                                isSwap=true;
                                click=0;
                                moves1--;
                            }
                            else
                            {
                                click=1;
                            }
                        }

                        //Match finding
                        for(int i=1; i<=8; i++)
                        {
                            for(int j=0; j<=8; j++)
                            {
                                if(grid[i][j].kind==grid[i+1][j].kind)
                                {
                                    if(grid[i][j].kind==grid[i-1][j].kind)
                                    {
                                        for(int n=-1; n<=1; n++)
                                        {
                                            grid[i+n][j].match++;
                                        }
                                    }
                                }

                                if(grid[i][j].kind==grid[i][j+1].kind)
                                {
                                    if(grid[i][j].kind==grid[i][j-1].kind)
                                    {
                                        for(int n=-1; n<=1; n++)
                                        {
                                            grid[i][j+n].match++;
                                        }
                                    }
                                }
                            }
                        }

                        //moving animation
                        isMoving=false;
                        for(int i=1; i<=8; i++)
                        {
                            for(int j=1; j<=8; j++)
                            {
                                piece &p = grid[i][j];
                                int dx,dy;
                                for(int n=0; n<4; n++)        // 4 times speed
                                {
                                    dx= p.x-p.col*tile;
                                    dy= p.y-p.row*tile;
                                    if(dx)
                                    {
                                        p.x=p.x-dx/abs(dx);
                                    }
                                    if(dy)
                                    {
                                        p.y=p.y-dy/abs(dy);
                                    }
                                }
                                if(dx||dy)
                                {
                                    isMoving=true;
                                }
                            }
                        }

                        //deleting animation
                        if(!isMoving)
                        {
                            for(int i=1; i<=8; i++)
                            {
                                for(int j=1; j<=8; j++)
                                {
                                    if(grid[i][j].match)
                                    {
                                        if(grid[i][j].deleteanimationstyle>10)
                                        {
                                            grid[i][j].deleteanimationstyle=grid[i][j].deleteanimationstyle-10;
                                            isMoving=true;
                                        }
                                    }
                                }
                            }
                        }


                        //get Score

                        int score=0;
                        for(int i=1; i<=8; i++)
                        {
                            for(int j=1; j<=8; j++)
                            {
                                score+=grid[i][j].match;

                                if(grid[i][j].match)
                                {
                                    pointx+=1;
                                    if(pointx>5000)
                                    {
                                        if(moves1>0)
                                        {
                                            /*  PASSING SHOW PART  */

                                            ofstream writescore("highscore.txt");
                                            if(writescore.is_open())
                                            {
                                                if(pointy>h_points)
                                                {
                                                    h_points=pointy;
                                                }
                                                writescore<<h_points;
                                            }
                                            writescore.close();

                                            Texture pass_bg;
                                            pass_bg.loadFromFile("image/bg_night.jpg");

                                            Sprite bg11_pass(pass_bg);

                                            Text passT1("CONGRATULATIONS..!!", best14, 45);
                                            Text passT2("You PASSED this Level", best15, 35);
                                            Text passT3("Press ENTER for Next Level", best13, 30);

                                            passT1.setFillColor(sf::Color::Yellow);
                                            passT2.setFillColor(sf::Color::Yellow);
                                            passT3.setFillColor(sf::Color::Yellow);

                                            passT1.setPosition(160,150);
                                            passT2.setPosition(180,350);
                                            passT3.setPosition(175,500);

                                            while(level_1.isOpen())
                                            {
                                                Event pass_event;
                                                while(level_1.pollEvent(pass_event))
                                                {
                                                    if(pass_event.type== Event::KeyPressed)
                                                    {

                                                        if(Keyboard::isKeyPressed(Keyboard::Enter))
                                                        {
                                                            music1.stop();
                                                            level_1.close();
                                                            Level2_page(flag);
                                                        }

                                                    }
                                                }

                                                level_1.clear();
                                                level_1.draw(bg11_pass);

                                                level_1.draw(passT1);
                                                level_1.draw(passT2);
                                                level_1.draw(passT3);

                                                level_1.display();
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        //swap back is no match
                        if(isSwap && !isMoving)
                        {
                            if(!score)
                            {
                                swap(grid[y0][x0],grid[y][x]);
                                isSwap=false;
                            }
                        }

                        //grid updating after matching
                        if(!isMoving)
                        {
                            for(int i=8; i>=1; i--)
                            {
                                for(int j=1; j<=8; j++)
                                {
                                    if(grid[i][j].match)
                                    {
                                        for(int n=i; n>=1; n--)
                                        {
                                            if(!grid[n][j].match)
                                            {
                                                swap(grid[n][j],grid[i][j]);
                                                break;
                                            }
                                        }
                                    }
                                }
                            }

                            for(int j=1; j<=8; j++)
                            {
                                for(int i=8,n=0; i>=1; i--)
                                {
                                    if(grid[i][j].match)
                                    {
                                        grid[i][j].kind=rand()%5;
                                        grid[i][j].y= -tile*n++;
                                        grid[i][j].match=0;
                                        grid[i][j].deleteanimationstyle=255;
                                    }
                                }
                            }
                        }

                        //draw//
                        level_1.draw(background);

                        for(int i=1; i<=8; i++)
                        {
                            for(int j=1; j<=8; j++)
                            {
                                piece p = grid[i][j];
                                gems.setTextureRect(IntRect(p.kind*43,0,45,45));
                                gems.setColor(Color(255,255,255,p.deleteanimationstyle));
                                gems.setPosition(p.x,p.y);
                                gems.move(offset.x-tile,offset.y-tile);
                                level_1.draw(gems);
                            }
                        }

//game_event:

                        level_1.draw(game1);
                        level_1.draw(game2);
                        level_1.draw(game3);
                        level_1.draw(point_bg3);
                        level_1.draw(game4);
                        level_1.draw(game5);
                        level_1.draw(game6);

                        level_1.draw(point_bg);
                        level_1.draw(point_bg2);
                        level_1.draw(point_bg4);
                        level_1.draw(ttt);
                        level_1.draw(ttmove);
                        level_1.draw(escape);

                        level_1.display();

                        if(moves1==0)
                        {
                            if(pointx<5000)
                            {
                                ofstream writescore("highscore.txt");
                                if(writescore.is_open())
                                {
                                    if(pointy>h_points)
                                    {
                                        h_points=pointy;
                                    }
                                    writescore<<h_points;
                                }
                                writescore.close();

                                level_1.close();
                                move_ending_page();
                            }
                        }

                    }

                    /* CODE of Level 1 ends here*/
                }

            }
        }

        level_1.clear();
        level_1.draw(Back1);
        level_1.draw(arrow_1);
        level_1.draw(t11);
        clock1++;
        if(clock1%300<150)
        {
            level_1.draw(t12);
        }
        level_1.draw(t13);

        level_1.display();
    }
}


int main()
{
    std::ifstream takeread;
    takeread.open("highscore.txt");
    if(takeread.is_open())
    {
        while(!takeread.eof())
        {
            takeread>>h_points;
        }
    }
    takeread.close();

event1:
    Music music;
    music.openFromFile("music/funky.ogg");
    music.setLoop(true);
    int xposition, yposition, poss;

    Font font1, font2, font3, font4, font5, font6;
    font1.loadFromFile("fonts/ITCKRIST.ttf");
    font2.loadFromFile("fonts/VINERITC.ttf");
    font3.loadFromFile("fonts/MAIAN.ttf");
    font4.loadFromFile("fonts/AGENCYR.ttf");
    font5.loadFromFile("fonts/OCRAEXT.ttf");
    font6.loadFromFile("fonts/COLONNA.ttf");

    RenderWindow MainPage(VideoMode(760, 600), "Main Page");

    Texture w_background, w_logo, w_style;

    //text fixing

    Text w_t("Welcome To", font1, 38);
    Text t1("MATCH-3", font2, 55);
    Text t2("MANIA", font2, 38);
    Text t3("Play Game", font3, 30);
    Text t4("High Score", font3, 30);
    Text t5("Instructions", font3, 30);
    Text t6("Music", font3, 30);
    Text t7("Exit", font3, 30);
    Text dv("Developed By ==> Raisul & Himel", font1, 20);

    //text coloring

    w_t.setFillColor(sf::Color::Yellow);
    t1.setFillColor(sf::Color::Yellow);
    t2.setFillColor(sf::Color::Yellow);
    t3.setFillColor(sf::Color::Red);
    t4.setFillColor(sf::Color::Red);
    t5.setFillColor(sf::Color::Red);
    t6.setFillColor(sf::Color::Red);
    t7.setFillColor(sf::Color::Red);
    dv.setFillColor(sf::Color::Green);

    //text position declaring

    w_t.setPosition(275, 50);
    t1.setPosition(180, 125);
    t2.setPosition(450, 135);
    t3.setPosition(305, 230);
    t4.setPosition(305, 270);
    t5.setPosition(305, 310);
    t6.setPosition(305, 350);
    t7.setPosition(305, 390);
    dv.setPosition(420,550);

    //image loading

    w_background.loadFromFile("image/neon_shape.jpg");
    w_logo.loadFromFile("image/galaxy-png.jpg");
    w_style.loadFromFile("image/DownArrow.png");


    Sprite logo_s(w_logo), b_s(w_background), a_s(w_style);
    xposition=300;
    yposition=232;
    logo_s.setPosition(xposition,yposition);

    music.play();

event2:
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
                    if(yposition==392)
                    {
                        MainPage.close();
                    }
                    else if(yposition==352)
                    {
                        /*Sound page part*/

                        poss=195;

                        Text a1("Sound ???", font1, 40);
                        Text a2("Yes", font3, 25);
                        Text a3("Yes", font3, 25);
                        Text a4("No", font3, 25);
                        Text a5("No", font3, 25);
                        Text a6("Press ESC to Mainpage", font5, 30);

                        a1.setFillColor(Color::White);
                        a2.setFillColor(Color::Yellow);
                        a3.setFillColor(Color::White);
                        a4.setFillColor(Color::Yellow);
                        a5.setFillColor(Color::White);
                        a6.setFillColor(Color::Yellow);

                        a1.setPosition(290,100);
                        a6.setPosition(45,2);

                        Texture m1,m2,m3,m4,m5;

                        m1.loadFromFile("image/neon_shape.jpg");
                        m2.loadFromFile("image/sound.jpg");
                        m3.loadFromFile("image/mute.jpg");
                        m4.loadFromFile("image/dynamic_blue_left.png");
                        m5.loadFromFile("image/button2.png");

                        Sprite s(m1), s1(m2), s2(m3), s3(m4), s4(m5);
                        s1.setPosition(420,200);
                        s2.setPosition(420,200);
                        s3.setPosition(-3,0);
                        s4.setPosition(270,poss);

                        while(MainPage.isOpen())
                        {
                            Event sound_page;
                            while(MainPage.pollEvent(sound_page))
                            {
                                if(sound_page.type==Event::KeyPressed)
                                {
                                    if(Keyboard::isKeyPressed(Keyboard::Escape))
                                    {
                                        goto event2;
                                    }
                                    else if(Keyboard::isKeyPressed(Keyboard::Down))
                                    {
                                        poss=poss+50;
                                        if(poss>245)
                                        {
                                            poss=195;
                                        }
                                        s4.setPosition(270,poss);
                                    }
                                    else if(Keyboard::isKeyPressed(Keyboard::Up))
                                    {
                                        poss=poss-50;
                                        if(poss<195)
                                        {
                                            poss=245;
                                        }
                                        s4.setPosition(270,poss);
                                    }
                                    else if(Keyboard::isKeyPressed(Keyboard::Enter))
                                    {
                                        if(poss==245 && flag==0)
                                        {
                                            music.stop();
                                            flag=1;
                                        }
                                        if(poss==195 && flag==1)
                                        {
                                            music.play();
                                            flag=0;
                                        }
                                    }
                                }
                            }
                            MainPage.clear();
                            MainPage.draw(s);
                            MainPage.draw(s3);
                            if(flag==0)
                            {
                                MainPage.draw(s1);
                                MainPage.draw(s4);
                            }
                            else if(flag==1)
                            {
                                MainPage.draw(s2);
                                MainPage.draw(s4);
                            }
                            if(poss==195)
                            {
                                a3.setPosition(280,200);
                                a4.setPosition(280,250);
                                MainPage.draw(a3);
                                MainPage.draw(a4);
                            }
                            else
                            {
                                a2.setPosition(280,200);
                                a5.setPosition(280,250);
                                MainPage.draw(a2);
                                MainPage.draw(a5);
                            }
                            MainPage.draw(a1);
                            MainPage.draw(a6);
                            MainPage.display();
                        }
                    }
                    else if(yposition==312)
                    {
                        /* Instruction Page Part */

                        Text t1("Welcome to our Match - 3 Mania . You  have  to", font5, 25);
                        Text t2("match  three  or  more gems  to  get  Points .", font5, 25);
                        Text t3("To match you have to use the mouse click , and", font5, 25);
                        Text t4("ESCAPE button to pause any of the game levels.", font5, 25);
                        Text t5("You are given some  game activity instructions", font5, 25);
                        Text t6("in game pages . Hope you will ENJOY the GAME .", font5, 25);
                        Text t7("Thank You...", font5, 25);
                        Text t8("Press ESC to Mainpage", font5, 30);

                        t8.setPosition(45,2);
                        t1.setPosition(45,120);
                        t2.setPosition(45,170);
                        t3.setPosition(45,220);
                        t4.setPosition(45,270);
                        t5.setPosition(45,320);
                        t6.setPosition(45,370);
                        t7.setPosition(45,420);

                        t1.setFillColor(Color::White);
                        t2.setFillColor(Color::White);
                        t3.setFillColor(Color::White);
                        t4.setFillColor(Color::White);
                        t5.setFillColor(Color::White);
                        t6.setFillColor(Color::White);
                        t7.setFillColor(Color::White);
                        t8.setFillColor(Color::White);

                        Texture a1,a2;

                        a1.loadFromFile("image/sbg_night.jpg");
                        a2.loadFromFile("image/dynamic_blue_left.png");

                        Sprite BackGround(a1), Exit_arrow(a2);
                        Exit_arrow.setPosition(-3,0);

                        while(MainPage.isOpen())
                        {
                            Event ins_event;
                            while(MainPage.pollEvent(ins_event))
                            {
                                if(ins_event.type== Event::KeyPressed)
                                {
                                    if(Keyboard::isKeyPressed(Keyboard::Escape))
                                    {
                                        goto event2;
                                    }
                                }
                            }

                            MainPage.clear();
                            MainPage.draw(BackGround);
                            MainPage.draw(Exit_arrow);
                            MainPage.draw(t1);
                            MainPage.draw(t2);
                            MainPage.draw(t3);
                            MainPage.draw(t4);
                            MainPage.draw(t5);
                            MainPage.draw(t6);
                            MainPage.draw(t7);
                            MainPage.draw(t8);

                            MainPage.display();
                        }
                    }
                    else if(yposition==272)
                    {
                        /*High score page part*/

                        stringpoint=""+to_string(h_points);
                        Text tpoint(stringpoint, font5, 45);
                        tpoint.setFillColor(sf::Color::White);
                        tpoint.setPosition(260,280);

                        Text T1("Your", font4, 45);
                        Text T2("HIGH SCORE :", font6, 65);
                        Text T3("Press ESC to go back", font5, 30);

                        T1.setFillColor(sf::Color::Red);
                        T2.setFillColor(sf::Color::Yellow);
                        T3.setFillColor(sf::Color::Yellow);

                        T1.setPosition(160,190);
                        T2.setPosition(235,170);
                        T3.setPosition(45,2);

                        Texture score_bg, board_bg, escape_arrow;
                        score_bg.loadFromFile("image/score_background_drops.jpg");
                        board_bg.loadFromFile("image/button.png");
                        escape_arrow.loadFromFile("image/dynamic_blue_left.png");

                        Sprite scoreback(score_bg), scoreboard(board_bg), back_arrow(escape_arrow);
                        scoreboard.setPosition(240,270);
                        back_arrow.setPosition(-3,0);

                        while(MainPage.isOpen())
                        {
                            Event score_event;
                            while(MainPage.pollEvent(score_event))
                            {
                                if(score_event.type== Event::Closed)
                                {
                                    goto event2;
                                }

                                if(score_event.type== Event::KeyPressed)
                                {

                                    if(Keyboard::isKeyPressed(Keyboard::Escape))
                                    {
                                        goto event2;
                                    }

                                }
                            }

                            MainPage.clear();

                            MainPage.draw(scoreback);
                            MainPage.draw(scoreboard);
                            MainPage.draw(tpoint);
                            MainPage.draw(back_arrow);
                            MainPage.draw(T3);
                            MainPage.draw(T1);
                            MainPage.draw(T2);
                            MainPage.display();

                        }
                    }
                    else if(yposition==232)
                    {
                        /*page that will display after main page*/

                        int page_clock=0;

                        Text Ta("Press ESC to go back", font5, 30);
                        Text Tb("<< Press Enter for Level 1 >>", font2, 30);

                        Ta.setFillColor(sf::Color::Green);
                        Tb.setFillColor(sf::Color::Yellow);

                        Ta.setPosition(45,2);
                        Tb.setPosition(175,500);

                        Texture page_bg, arrow;
                        page_bg.loadFromFile("image/score_background(level).jpg");
                        arrow.loadFromFile("image/dynamic_blue_left.png");

                        Sprite level_bg(page_bg), esc_arrow(arrow);

                        esc_arrow.setPosition(-3,0);

                        while(MainPage.isOpen())
                        {
                            Event level_event;
                            while(MainPage.pollEvent(level_event))
                            {
                                if(level_event.type==Event::Closed)
                                {
                                    goto event2;
                                }
                                if(level_event.type== Event::KeyPressed)
                                {

                                    if(Keyboard::isKeyPressed(Keyboard::Escape))
                                    {
                                        goto event2;
                                    }

                                    else if(Keyboard::isKeyPressed(Keyboard::Enter))
                                    {
                                        music.stop();
                                        Level1_page(flag);
                                        goto event1;
                                    }

                                }
                            }

                            MainPage.clear();
                            MainPage.draw(level_bg);
                            MainPage.draw(esc_arrow);
                            MainPage.draw(Ta);

                            page_clock++;
                            if(page_clock%300<150)
                            {
                                MainPage.draw(Tb);
                            }

                            MainPage.display();
                        }
                    }
                }

                //arrow moving

                else if(Keyboard::isKeyPressed(Keyboard::Up))
                {
                    yposition-=40;
                    if(yposition<232)
                    {
                        yposition+=(5*40);
                    }
                    logo_s.setPosition(xposition,yposition);
                }


                else if(Keyboard::isKeyPressed(Keyboard::Down))
                {
                    yposition+=40;
                    if(yposition>392)
                    {
                        yposition-=(5*40);
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
        MainPage.draw(t7);
        MainPage.draw(t6);
        MainPage.draw(t5);
        MainPage.draw(t4);
        MainPage.draw(t3);
        MainPage.draw(t2);
        MainPage.draw(t1);
        MainPage.draw(dv);
        MainPage.display();


    }
}
