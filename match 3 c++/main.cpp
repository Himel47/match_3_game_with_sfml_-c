#include <SFML/Graphics.hpp>

#include<SFML/System/Clock.hpp>

#include<bits/stdc++.h>

using namespace sf;

using namespace std;

string stringscore="", stringscore2="";
string stringmove="", stringmove2="";
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

    RenderWindow Fail1(VideoMode(560,401), "Fail-1");

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


int level2_pass_page()
{
    Font fonT21, fonT22;
    fonT21.loadFromFile("fonts/COLONNA.ttf");
    fonT22.loadFromFile("fonts/ITCKRIST.ttf");

    RenderWindow pass2(VideoMode(560,401), "Pass-2");

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
    RenderWindow app2(VideoMode(560,401), "Match-3 Level-2...!");
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

    RenderWindow pass1(VideoMode(560,401), "Pass-1");

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


void Game1()
{
    RenderWindow app1(VideoMode(560,401), "Match-3 Level-1...!");
    app1.setFramerateLimit(60);

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

    while(app1.isOpen())
    {
        Event event;
        while(app1.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                app1.close();
            }

            if(event.type == Event::MouseButtonPressed)
            {
                if(event.key.code == Mouse::Left)
                {
                    if(!isSwap && !isMoving)
                    {
                        click++;
                        position = Mouse::getPosition(app1)-offset;
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
                    //point = ;
                    pointx+=1;
                    if(pointx>6000)
                    {
                        if(moves1>0)
                        {
                            app1.close();
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
        app1.draw(background);

        for(int i=1; i<=8; i++)
        {
            for(int j=1; j<=8; j++)
            {
                piece p = grid[i][j];
                gems.setTextureRect(IntRect(p.kind*43,0,45,45));
                gems.setColor(Color(255,255,255,p.deleteanimationstyle));
                gems.setPosition(p.x,p.y);
                gems.move(offset.x-tile,offset.y-tile);
                app1.draw(gems);
            }
        }

        app1.draw(game1);
        app1.draw(game2);
        app1.draw(game3);

        app1.draw(point_bg);
        app1.draw(point_bg2);
        app1.draw(point_bg3);
        app1.draw(ttt);
        app1.draw(ttmove);

        app1.display();

        if(moves1==0)
        {
            if(pointx<6000)
            {
                app1.close();
                move_ending_page();
            }
        }

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
                    Game1();
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
event1:
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
    w_logo.loadFromFile("image/galaxy-png.png");
    w_style.loadFromFile("image/DownArrow.png");


    Sprite logo_s(w_logo), b_s(w_background), a_s(w_style);
    xposition=195;
    yposition=187;
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
                    if(yposition==267)
                    {
                        MainPage.close();
                    }
                    else if(yposition==227)
                    {
                        High_score();
                    }
                    else if(yposition==187)
                    {
                        Font fontx,fonty;
                        fontx.loadFromFile("fonts/AGENCYB.ttf");
                        fonty.loadFromFile("fonts/COLONNA.ttf");

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
                        page_arrow.loadFromFile("image/night2.png");
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

                        int arrowposition=111;
                        level_arrow.setPosition(340,arrowposition);

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


                                    else if(Keyboard::isKeyPressed(Keyboard::Up))
                                    {
                                        arrowposition-=70;
                                        if(arrowposition<111)
                                        {
                                            arrowposition=321;
                                        }
                                        level_arrow.setPosition(340,arrowposition);
                                    }


                                    else if(Keyboard::isKeyPressed(Keyboard::Down))
                                    {
                                        arrowposition+=70;
                                        if(arrowposition>321)
                                        {
                                            arrowposition=111;
                                        }
                                        level_arrow.setPosition(340,arrowposition);
                                    }


                                    else if(Keyboard::isKeyPressed(Keyboard::Enter))
                                    {
                                        if(arrowposition==111)
                                        {
                                            Level1_page();
                                        }
                                        else if(arrowposition==181)
                                        {
                                            Level2_page();
                                        }
                                        else if(arrowposition==251)
                                        {
                                            Level3_page();
                                        }
                                        else if(arrowposition==321)
                                        {
                                            Level4_page();
                                        }
                                    }

                                }
                            }

                            MainPage.clear();
                            MainPage.draw(level_bg);
                            MainPage.draw(level_style1);
                            MainPage.draw(level1);
                            MainPage.draw(level2);
                            MainPage.draw(level3);
                            MainPage.draw(level4);
                            MainPage.draw(level_arrow);
                            MainPage.draw(Ta);
                            MainPage.draw(Tb);
                            MainPage.draw(Tc);
                            MainPage.draw(Td);
                            MainPage.draw(Te);
                            MainPage.display();
                        }
                    }
                }

                //arrow moving

                else if(Keyboard::isKeyPressed(Keyboard::Up))
                {
                    yposition-=40;
                    if(yposition<187)
                    {
                        yposition+=(3*40);
                    }
                    logo_s.setPosition(xposition,yposition);
                }


                else if(Keyboard::isKeyPressed(Keyboard::Down))
                {
                    yposition+=40;
                    if(yposition>267)
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
