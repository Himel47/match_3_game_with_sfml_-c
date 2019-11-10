#include <SFML/Graphics.hpp>

#include<SFML/Audio.hpp>

#include<SFML/System/Clock.hpp>

#include<bits/stdc++.h>

using namespace sf;

using namespace std;

string stringscore="", stringscore2="";
string stringmove="", stringmove2="";

//time display
string stringminute1="";
string stringsecond1="";

int secondcounting=0;
int minutecounting=0;

int pointx=0, pointy=0, moves1=20, moves2=20;
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
    Font fonTf1, fonTf2;
    fonTf1.loadFromFile("fonts/COLONNA.ttf");
    fonTf2.loadFromFile("fonts/ITCKRIST.ttf");

    RenderWindow Fail1(VideoMode(760,600), "Fail-1");

    Texture fail_bg;
    fail_bg.loadFromFile("image/bg_night.jpg");

    Sprite bg_fail1(fail_bg);

    Text failT1("SORRY..!!", fonTf1, 65);
    Text failT2("You FAILED", fonTf2, 35);

    failT1.setFillColor(sf::Color::Yellow);
    failT2.setFillColor(sf::Color::Red);

    failT1.setPosition(160,150);
    failT2.setPosition(180,300);

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

        Fail1.draw(failT1);
        Fail1.draw(failT2);

        Fail1.display();
    }
}


int Level4_page()
{
    int clock4=0;

    Font best41, best42;
    best41.loadFromFile("fonts/comic.ttf");
    best42.loadFromFile("fonts/VINERITC.ttf");

    RenderWindow page4(VideoMode(760,600), "Level_4 Starting");

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


void Game3()
{
    sf::Clock clock;

    sf::Time time;

    RenderWindow app3(VideoMode(760,600), "Match-3 Game!");
    app3.setFramerateLimit(60);

    pointx=0;

    Texture t1,t2,t3,t4,t5;
    t1.loadFromFile("image/bg_night.jpg");
    t2.loadFromFile("image/gems.png");
    t3.loadFromFile("image/button2.png");
    t4.loadFromFile("image/button2.png");
    t5.loadFromFile("image/Design-PNG-Photo.png");

    Sprite background(t1), gems(t2),point_bg(t3), point_bg2(t4), point_bg3(t5);
    point_bg.setPosition(420,70);
    point_bg2.setPosition(420,180);
    point_bg3.setPosition(390,220);

    //game page writings

    Font fontg;
    fontg.loadFromFile("fonts/ALGER.ttf");
    Text game1("Score :", fontg, 35);
    Text game2("Time :", fontg, 35);
    Text game3("# Target :: >=8000 #", fontg, 13);
    game1.setPosition(420,20);
    game2.setPosition(420,130);
    game3.setPosition(420,115);
    game1.setFillColor(sf::Color::Yellow);
    game2.setFillColor(sf::Color::Yellow);
    game3.setFillColor(sf::Color::Yellow);


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

    while(app3.isOpen())
    {
        Event event;
        while(app3.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                app3.close();
            }

            if(event.type == Event::MouseButtonPressed)
            {
                if(event.key.code == Mouse::Left)
                {
                    if(!isSwap && !isMoving)
                    {
                        click++;
                        position = Mouse::getPosition(app3)-offset;
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

        //stringsecond1=""+to_string(moves1);
        //Text ttmove(stringmove, fontg, 25);
        //ttmove.setFillColor(sf::Color::Red);
        //ttmove.setPosition(425,180);

        stringminute1=""+to_string(minutecounting);
        Text tminute1(stringminute1, fontg, 25);
        tminute1.setFillColor(sf::Color::Red);
        tminute1.setPosition(435,180);

        stringsecond1=" : "+to_string(secondcounting);
        Text tsecond1(stringsecond1, fontg, 25);
        tsecond1.setFillColor(sf::Color::Red);
        tsecond1.setPosition(450,180);

        time = clock.getElapsedTime();
        secondcounting= time.asSeconds();
        //std::cout<<std::fixed;
        //std::cout<< std::setprecision(0);
        //std::cout<< time.asSeconds()<< std::endl;

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
                for(int n=0; n<3; n++)        // 3 times speed
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


        if(time.asSeconds()>60)
        {
            minutecounting++;
            if(minutecounting==2)
            {
                if(pointx>8000)
                {
                    app3.close();
                    //level3_pass_page();
                }
                else
                {
                    app3.close();
                    move_ending_page();
                }
            }
            time = clock.restart();
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
        app3.draw(background);

        for(int i=1; i<=8; i++)
        {
            for(int j=1; j<=8; j++)
            {
                piece p = grid[i][j];
                gems.setTextureRect(IntRect(p.kind*43,0,45,45));
                gems.setColor(Color(255,255,255,p.deleteanimationstyle));
                gems.setPosition(p.x,p.y);
                gems.move(offset.x-tile,offset.y-tile);
                app3.draw(gems);
            }
        }

        app3.draw(game1);
        app3.draw(game2);
        app3.draw(game3);

        app3.draw(point_bg);
        app3.draw(point_bg2);
        app3.draw(point_bg3);
        app3.draw(ttt2);
        app3.draw(tminute1);
        app3.draw(tsecond1);

        app3.display();

    }

}


int Level3_page()
{
    int clock3=0;

    Font best31, best32;
    best31.loadFromFile("fonts/comic.ttf");
    best32.loadFromFile("fonts/VINERITC.ttf");

    RenderWindow page3(VideoMode(760,600), "Level_3 Starting");

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
                    Game3();
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


int level2_pass_page()
{
    Font fonT21, fonT22;
    fonT21.loadFromFile("fonts/COLONNA.ttf");
    fonT22.loadFromFile("fonts/ITCKRIST.ttf");

    RenderWindow pass2(VideoMode(760,600), "Pass-2");

    Texture pass_bg,pass_bg2;
    pass_bg.loadFromFile("image/bg_night.jpg");
    pass_bg2.loadFromFile("image/Watercolor.png");

    Sprite bg21_pass(pass_bg), bg22_pass(pass_bg2);

    Text passT21("CONGRATULATIONS..!!", fonT21, 45);
    Text passT22("You PASSED this Level", fonT22, 35);

    passT21.setFillColor(sf::Color::Red);
    passT22.setFillColor(sf::Color::Red);

    passT21.setPosition(60,100);
    passT22.setPosition(80,300);

    while(pass2.isOpen())
    {
        Event pass_event;
        while(pass2.pollEvent(pass_event))
        {
            if(pass_event.type== Event::KeyPressed)
            {

                if(Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    pass2.close();
                    Level3_page();
                }

            }
        }

        pass2.clear();
        pass2.draw(bg21_pass);
        pass2.draw(bg22_pass);

        pass2.draw(passT21);
        pass2.draw(passT22);

        pass2.display();
    }
}


void Game2()
{
    RenderWindow app2(VideoMode(760,600), "Match-3 Level-2...!");
    app2.setFramerateLimit(60);

    Texture t1,t2,t3,t4,t5;
    t1.loadFromFile("image/bg_night.jpg");
    t2.loadFromFile("image/gems.png");
    t3.loadFromFile("image/button2.png");
    t4.loadFromFile("image/button2.png");
    t5.loadFromFile("image/Design-PNG-Photo.png");

    Sprite background(t1), gems(t2),point_bg(t3), point_bg2(t4), point_bg3(t5);
    point_bg.setPosition(420,70);
    point_bg2.setPosition(420,190);
    point_bg3.setPosition(390,220);

    //game page writings

    Font fontg;
    fontg.loadFromFile("fonts/ALGER.ttf");
    Text game1("Score :", fontg, 35);
    Text game2("Moves :", fontg, 35);
    Text game3("# Target :: 8000 #", fontg, 16);
    game1.setPosition(420,20);
    game2.setPosition(420,140);
    game3.setPosition(405,115);
    game1.setFillColor(sf::Color::Yellow);
    game2.setFillColor(sf::Color::Yellow);
    game3.setFillColor(sf::Color::Yellow);


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

    while(app2.isOpen())
    {
        Event event;
        while(app2.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                app2.close();
            }

            if(event.type == Event::MouseButtonPressed)
            {
                if(event.key.code == Mouse::Left)
                {
                    if(!isSwap && !isMoving)
                    {
                        click++;
                        position = Mouse::getPosition(app2)-offset;
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
                    if(pointy>8000)
                    {
                        if(moves2>0)
                        {
                            app2.close();
                            level2_pass_page();
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
        app2.draw(background);

        for(int i=1; i<=8; i++)
        {
            for(int j=1; j<=8; j++)
            {
                piece p = grid[i][j];
                gems.setTextureRect(IntRect(p.kind*43,0,45,45));
                gems.setColor(Color(255,255,255,p.deleteanimationstyle));
                gems.setPosition(p.x,p.y);
                gems.move(offset.x-tile,offset.y-tile);
                app2.draw(gems);
            }
        }

        app2.draw(game1);
        app2.draw(game2);
        app2.draw(game3);

        app2.draw(point_bg);
        app2.draw(point_bg2);
        app2.draw(point_bg3);
        app2.draw(tscore2);
        app2.draw(tmove2);

        app2.display();

        if(moves2==0)
        {
            if(pointy<8000)
            {
                app2.close();
                move_ending_page();
            }
        }

    }

}


void Level2_page()
{
    int clock2=0;

    Font best21, best22;
    best21.loadFromFile("fonts/comic.ttf");
    best22.loadFromFile("fonts/VINERITC.ttf");

    RenderWindow page2(VideoMode(760,600), "Level_2 Starting");

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
                    Game2();
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


int level1_pass_page()
{
    Font fonT1, fonT2;
    fonT1.loadFromFile("fonts/COLONNA.ttf");
    fonT2.loadFromFile("fonts/ITCKRIST.ttf");

    RenderWindow pass1(VideoMode(760,600), "Pass-1");

    Texture pass_bg,pass_bg2;
    pass_bg.loadFromFile("image/bg_night.jpg");
    pass_bg2.loadFromFile("image/Watercolor.png");

    Sprite bg11_pass(pass_bg), bg12_pass(pass_bg2);

    Text passT1("CONGRATULATIONS..!!", fonT1, 45);
    Text passT2("You PASSED this Level", fonT2, 35);

    passT1.setFillColor(sf::Color::Red);
    passT2.setFillColor(sf::Color::Red);

    passT1.setPosition(60,100);
    passT2.setPosition(80,300);

    while(pass1.isOpen())
    {
        Event pass_event;
        while(pass1.pollEvent(pass_event))
        {
            if(pass_event.type== Event::KeyPressed)
            {

                if(Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    pass1.close();
                    Level2_page();
                }

            }
        }

        pass1.clear();
        pass1.draw(bg11_pass);
        pass1.draw(bg12_pass);

        pass1.draw(passT1);
        pass1.draw(passT2);

        pass1.display();
    }
}


int Level1_page()
{
level_event1:
    int clock1=0;

    Font best11, best12,best13;
    best11.loadFromFile("fonts/comic.ttf");
    best12.loadFromFile("fonts/VINERITC.ttf");
    best13.loadFromFile("fonts/OCRAEXT.ttf");

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
                    /* Game Code for LEVEL -1 */

                    level_1.setFramerateLimit(60);

                    Texture t1,t2,t3,t4,t5;
                    t1.loadFromFile("image/bg_night.jpg");
                    t2.loadFromFile("image/gems.png");
                    t3.loadFromFile("image/button2.png");
                    t4.loadFromFile("image/button2.png");
                    t5.loadFromFile("image/Design-PNG-Photo.png");

                    Sprite background(t1), gems(t2),point_bg(t3), point_bg2(t4), point_bg3(t5);
                    point_bg.setPosition(420,70);
                    point_bg2.setPosition(420,190);
                    point_bg3.setPosition(590,420);

                    //game page writings

                    Font fontg;
                    fontg.loadFromFile("fonts/ALGER.ttf");
                    Text game1("Score :", fontg, 35);
                    Text game2("Moves :", fontg, 35);
                    Text game3("# Target :: 6000 #", fontg, 16);
                    game1.setPosition(420,20);
                    game2.setPosition(420,140);
                    game3.setPosition(405,115);
                    game1.setFillColor(sf::Color::Yellow);
                    game2.setFillColor(sf::Color::Yellow);
                    game3.setFillColor(sf::Color::Yellow);


                    //game code

                    for(int i=1; i<=8; i++)
                    {
                        for(int j=1; j<=8; j++)
                        {
                            grid[i][j].kind=rand()%7;
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

                    while(level_1.isOpen())
                    {
                        Event event;
                        while(level_1.pollEvent(event))
                        {
                            if(event.type == Event::Closed)
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
                                    if(pointx>6000)
                                    {
                                        if(moves1>0)
                                        {
                                            level_1.close();
                                            level1_pass_page();
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

                        level_1.draw(game1);
                        level_1.draw(game2);
                        level_1.draw(game3);

                        level_1.draw(point_bg);
                        level_1.draw(point_bg2);
                        level_1.draw(point_bg3);
                        level_1.draw(ttt);
                        level_1.draw(ttmove);

                        level_1.display();

                        if(moves1==0)
                        {
                            if(pointx<6000)
                            {
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
event1:
    Music music;
    int xposition,yposition;

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
    Text t6("Exit", font3, 30);
    Text dv("Developed By ==> Raisul & Himel", font1, 20);

    //text coloring

    w_t.setFillColor(sf::Color::Yellow);
    t1.setFillColor(sf::Color::Yellow);
    t2.setFillColor(sf::Color::Yellow);
    t3.setFillColor(sf::Color::Red);
    t4.setFillColor(sf::Color::Red);
    t5.setFillColor(sf::Color::Red);
    t6.setFillColor(sf::Color::Red);
    dv.setFillColor(sf::Color::Green);

    //text position declaring

    w_t.setPosition(275, 50);
    t1.setPosition(180, 125);
    t2.setPosition(450, 135);
    t3.setPosition(305, 230);
    t4.setPosition(305, 270);
    t5.setPosition(305, 310);
    t6.setPosition(305, 350);
    dv.setPosition(420,550);

    //image loading

    w_background.loadFromFile("image/neon_shape.jpg");
    w_logo.loadFromFile("image/galaxy-png.jpg");
    w_style.loadFromFile("image/DownArrow.png");


    Sprite logo_s(w_logo), b_s(w_background), a_s(w_style);
    xposition=300;
    yposition=232;
    logo_s.setPosition(xposition,yposition);

    music.openFromFile("music/Fantasy Game Loop.wav");
    music.setVolume(50);
    music.play();


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
                    if(yposition==352)
                    {
                        MainPage.close();
                    }
                    else if(yposition==312)
                    {
                        MainPage.close();
                        // instruction_page;
                    }
                    else if(yposition==272)
                    {
                        /*High score page part*/

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
                                    goto event1;
                                }

                                if(score_event.type== Event::KeyPressed)
                                {

                                    if(Keyboard::isKeyPressed(Keyboard::Escape))
                                    {
                                        goto event1;
                                    }

                                }
                            }

                            MainPage.clear();

                            MainPage.draw(scoreback);
                            MainPage.draw(scoreboard);
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
                                    goto event1;
                                }
                                if(level_event.type== Event::KeyPressed)
                                {

                                    if(Keyboard::isKeyPressed(Keyboard::Escape))
                                    {
                                        goto event1;
                                    }

                                    else if(Keyboard::isKeyPressed(Keyboard::Enter))
                                    {
                                        Level1_page();
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
                        yposition+=(4*40);
                    }
                    logo_s.setPosition(xposition,yposition);
                }


                else if(Keyboard::isKeyPressed(Keyboard::Down))
                {
                    yposition+=40;
                    if(yposition>352)
                    {
                        yposition-=(4*40);
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
