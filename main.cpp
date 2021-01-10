#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

using namespace std;
using namespace sf;





char mapa[20][20]{

                {'#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , },
                {'#' , '#' , ' ' , ' ' , ' ' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '#' , },
                {'#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , ' ' , '#' , ' ' , '#' , },
                {'#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , ' ' , '#' , ' ' , '#' , },
                {'#' , '#' , ' ' , ' ' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '#' , ' ' , '#' , ' ' , '#' , },
                {'#' , '#' , ' ' , '#' , '#' , ' ' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , ' ' , '#' , ' ' , '#' , ' ' , '#' , },
                {'#' , '#' , ' ' , '#' , '#' , ' ' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , ' ' , '#' , ' ' , '#' , ' ' , '#' , },
                {'#' , '#' , ' ' , ' ' , ' ' , ' ' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , ' ' , ' ' , ' ' , ' ' , ' ' , '#' , },
                {'#' , '#' , ' ' , '#' , '#' , '#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , ' ' , '#' , ' ' , '#' , ' ' , '#' , },
                {'#' , '#' , ' ' , ' ' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , ' ' , '#' , },
                {'#' , '#' , ' ' , '#' , ' ' , '#' , '#' , ' ' , '#' , 'o' , '#' , '#' , 'o' , '#' , 'o' , '#' , ' ' , '#' , ' ' , '#' , },
                {'#' , '#' , ' ' , '#' , ' ' , '#' , '#' , ' ' , '#' , 'o' , '#' , '#' , 'o' , '#' , 'o' , '#' , ' ' , '#' , ' ' , '#' , },
                {'#' , '#' , ' ' , '#' , ' ' , '#' , '#' , ' ' , '#' , 'o' , '#' , '#' , 'o' , '#' , 'o' , '#' , ' ' , '#' , ' ' , '#' , },
                {'#' , '#' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , '#' , 'o' , '#' , '#' , 'o' , '#' , 'o' , ' ' , ' ' , '#' , ' ' , '#' , },
                {'#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , 'o' , '#' , '#' , 'o' , '#' , '#' , '#' , '#' , '#' , ' ' , '#' , },
                {'#' , '#' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '#' , },
                {'#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , ' ' , '#' , },
                {'#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , ' ' , '#' , },
                {'#' , '#' , ' ' , ' ' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , 'o' , ' ' , ' ' , '#' , },
                {'#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , }

};




class packman{



    public:
        int x;
        int y;
        int ww=0;

        char lastMove;
        int eaten=0;
        //char a;
        int won (){

            if (ww==1){
                return 1;

            }
            else {


            return 0;
            }

        }

        void moveP(char a){
            int qq=0;
            mapa[y][x]=' ';




             if (a=='w'){
            if (mapa[y-1][x]=='o')
            {
                eaten=eaten+1;
            }
            y=y-1;


            if (mapa[y][x]=='#' || mapa[y][x]=='$'){
                y=y+1;
                a=lastMove;
                qq=qq+1;




            }

            }
            else if (a=='s'){
            if (mapa[y][x+1]=='o')
            {
                eaten=eaten+1;
            }

            y=y+1;

            if (mapa[y][x]=='#' || mapa[y][x]=='$'){
                y=y-1;
                a=lastMove;
                qq=qq+1;



            }

            }
            else if (a=='d'){
            if (mapa[y][x+1]=='o')
            {
                eaten=eaten+1;
            }
            x=x+1;
            if (mapa[y][x]=='#' || mapa[y][x]=='$'){
                x=x-1;
                a=lastMove;
                qq=qq+1;



            }

            }
            else if (a=='a'){
            if (mapa[y][x-1]=='o')
            {
                eaten=eaten+1;
            }
            x=x-1;
            if (mapa[y][x]=='#' || mapa[y][x]=='$'){
                x=x+1;
                a=lastMove;
                qq=qq+1;



            }


             }




                if(qq%2==1){

                if (a=='w'){
                    if(mapa[y-1][x]=='o'){

                    eaten=eaten+1;
                    }


                    y=y-1;
                if (mapa[y][x]=='#' || mapa[y][x]=='$'){
                        y=y+1;



                    }


                }
                else if (a=='s'){
                    if(mapa[y+1][x]=='o'){

                    eaten=eaten+1;
                    }

                    y=y+1;

                    if (mapa[y][x]=='#' || mapa[y][x]=='$'){
                        y=y-1;



                    }

                }
                else if (a=='d'){
                    if(mapa[y][x+1]=='o'){

                    eaten=eaten+1;
                    }
                    x=x+1;
                    if (mapa[y][x]=='#' || mapa[y][x]=='$'){
                        x=x-1;



                    }


                }
                else if (a=='a'){
                    if(mapa[y][x-1]=='o'){

                    eaten=eaten+1;
                    }
                    x=x-1;

                    if (mapa[y][x]=='#' || mapa[y][x]=='$'){
                        x=x+1;


                    }



                }
                }

           mapa[y][x]='@';

            if (eaten==42){
                cout<<"pac-man won!!!";
                ww=1;

            }
            else {
            cout<<"your point is :"<<eaten<<endl;
            ww=0;


            }

            lastMove = a;


        }


};



class ghost{

    public:
        int x;
        int y;
        int openways[4];


        int i;
        int f;
        int lastmove=0;
        int r;
        int w=0;








        void checkways(){
            for (int q=0;q<4;q++){
                openways[q]=4;

            }
            i=0;

            if(mapa[y-1][x]!='#' and mapa[y-1][x]!='$')//Up
            {
                openways[i]=0;

                i=i+1;


            }
             if(mapa[y+1][x]!='#' and mapa[y+1][x]!='$' )//Down
            {
                openways[i]=1;

                i=i+1;


            }
             if(mapa[y][x-1]!='#' and mapa[y][x-1]!='$' )//left
            {
                openways[i]=2;
                i=i+1;


            }
             if(mapa[y][x+1]!='#' and mapa[y][x+1]!='$' )//right
            {
                openways[i]=3;
                i=i+1;


            }

        }



            //----------------------------------------------------------

            bool isrand(){

                if (i>2){
                    return true;

                }

                else if (lastmove==0 and mapa[y-1][x]=='#'  or lastmove==0 and mapa[y-1][x]=='$'){
                    return true;


                }
                else if(lastmove==1 and mapa[y+1][x]=='#'  or lastmove==1 and mapa[y+1][x]=='$' ){

                    return true;
                }
                else if(lastmove==2 and mapa[y][x-1]=='#'  or lastmove==2 and mapa[y][x-1]=='$'){

                    return true;
                }
                else if(lastmove==3 and mapa[y][x+1]=='#'  or lastmove==3 and mapa[y][x+1]=='$'){

                    return true;
                }
                else {
                    return false;
                }


            }

            //----------------------------------------------------------

        int lost(){
            if (w==1){
                return 1;

            }


        }


        void moveG(){

                checkways();

                if (i==0){

                    x=x;
                    y=y;
                    mapa[y][x]='$';

                }
                else {

                if (r==1){
                    mapa[y][x]='o';

                }
                else{

                    mapa[y][x]=' ';

                }


                srand(time(0));
                if (isrand()==true){

                    f=rand()%i;



                    if ( openways[f]==0 and mapa[y-1][x]!='#'  ){
                        if(mapa[y-1][x]=='@'){

                            cout<<"you lost!!!";
                            w=1;


                        }
                        if (mapa[y-1][x]=='o'){

                            r=1;

                        }
                        else{

                            r=0;
                        }
                        y=y-1;


                    }
                    else if ( openways[f]==1 and mapa[y+1][x]!='#'){
                        if(mapa[y+1][x]=='@'){
                            cout<<"you lost!!!";
                            w=1;


                        }

                        if (mapa[y+1][x]=='o'){

                            r=1;

                        }
                        else{

                            r=0;
                        }
                        y=y+1;


                    }
                   else  if ( openways[f]==2 and mapa[y][x-1]!='#'){
                        if(mapa[y][x-1]=='@'){
                            cout<<"you lost!!!";
                            w=1;


                        }
                        if (mapa[y][x-1]=='o'){

                            r=1;

                        }
                        else{

                            r=0;
                        }
                        x=x-1;


                    }
                    else if ( openways[f]==3 and mapa[y][x+1]!='#'){
                        if(mapa[y][x+1]=='@'){
                            cout<<"you lost!!!";
                            w=1;


                        }
                         if (mapa[y][x+1]=='o'){

                            r=1;

                        }
                        else{

                            r=0;
                        }
                        x=x+1;


                    }




                    lastmove=openways[f];



                }







                else{
                    r=0;



                    if ( lastmove==0 and mapa[y-1][x]!='#' ){

                       if(mapa[y+1][x]=='@'){
                            cout<<"you lost!!!";
                            w=1;


                        }

                        if (mapa[y-1][x]=='o'){

                            r=1;

                        }
                        else{

                            r=0;
                        }
                        y=y-1;


                    }
                    else if ( lastmove==1 and mapa[y+1][x]!='#' ){
                        if(mapa[y+1][x]=='@'){
                            cout<<"you lost!!!";
                            w=1;


                        }
                        if (mapa[y+1][x]=='o'){

                            r=1;

                        }
                        else{

                            r=0;
                        }

                        y=y+1;


                    }
                   else  if ( lastmove==2 and mapa[y][x-1]!='#' ){


                        if(mapa[y][x-1]=='@'){
                            cout<<"you lost!!!";
                            w=1;


                        }



                        if (mapa[y][x-1]=='o'){

                            r=1;

                        }
                        else{

                            r=0;
                        }


                        x=x-1;


                    }
                    else if ( lastmove==3 and mapa[y][x+1]!='#'){

                        if(mapa[y][x+1]=='@'){
                            cout<<"you lost!!!";
                            w=1;


                        }
                        if (mapa[y][x+1]=='o'){

                            r=1;

                        }
                        else{

                            r=0;
                        }

                        x=x+1;


                    }





                }















                    mapa[y][x]='$';



                    }







        }




};


int main()

{
    int fx;
    int fy;

    packman a;
    ghost b1;
    ghost b2;
    ghost b3;



    b1.x=3;
    b1.y=1;
    b2.x=18;
    b2.y=11;
    b3.x=2;
    b3.y=6;


    a.x = 18;
    a.y = 18;
    mapa[a.x][a.y] = '@';

    mapa[b1.y][b1.x] = '$';
    mapa[b2.y][b2.x] = '$';
    mapa[b3.y][b3.x] = '$';

    RenderWindow window(VideoMode(500, 500), "PackMan");
    char m;
    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type==Event::KeyPressed){

                if (event.key.code==Keyboard::Up){

                    m='w';


                }
                else if (event.key.code==Keyboard::Right){

                    m='d';


                }
                else if (event.key.code==Keyboard::Down){

                    m='s';


                }
                else if (event.key.code==Keyboard::Left){

                    m='a';


                }

            }




            }












        for (int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if (mapa[i][j]=='#'){

                    RectangleShape divar(Vector2f(20,20));

                    divar.setPosition(j*20,i*20);

                    divar.setFillColor(Color(0,0,200));

                    window.draw(divar);

                }
                if (mapa[i][j]=='@'){

                    CircleShape PKman(9);

                    PKman.setPosition(j*20,i*20);

                    PKman.setFillColor(Color(200,200,0));

                    window.draw(PKman);
                    }

                if (mapa[i][j]=='o'){

                    CircleShape food(3);

                    food.setPosition(j*20,i*20);

                    food.setFillColor(Color(20,200,100));

                    window.draw(food);

                }

                 if (b1.x == j && b1.y == i){

                    CircleShape Ghost(9);

                    Ghost.setPosition(j*20,i*20);

                    Ghost.setFillColor(Color(0,200,0));

                    window.draw(Ghost);

                }
               if ( b2.x == j && b2.y == i){

                    CircleShape Ghost(9);

                    Ghost.setPosition(j*20,i*20);

                    Ghost.setFillColor(Color(0,200,200));

                    window.draw(Ghost);

                }
                 if ( b3.x == j && b3.y == i){

                    CircleShape Ghost(9);

                    Ghost.setPosition(j*20,i*20);

                    Ghost.setFillColor(Color(200,0,20));

                    window.draw(Ghost);

                }


        }







    }







    window.display();
    window.clear();

    a.moveP(m);

    b1.moveG();


    b2.moveG();
    b3.moveG();
    if ( b1.lost()==1 || b2.lost()==1 || b3.lost()==1){

        break;

    }
    else if(a.won()==1){
        break;

    }



    usleep(250000);

 //   delay(5000);
    }

    return 0;
}
