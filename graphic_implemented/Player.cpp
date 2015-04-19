#include "Player.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "function.h"
#include "globals.h"
#include <iostream>
using namespace std;
SDL_Event  event;

//sprite sheet 
SDL_Rect AclipsRight[3];
SDL_Rect AclipsLeft[3];
SDL_Rect AclipsUp[3];
SDL_Rect AclipsDown[3];
SDL_Rect PclipsRight[3];
SDL_Rect PclipsLeft[3];
SDL_Rect PclipsDown[2];
SDL_Rect PclipsUp[2];

Player::Player(){
  xOffset = 200;
  yOffset = 200;
  xvel = 0;
  Pframe = 0;
  Aframe = 0;
  status = ASH_RIGHT;
  set_clips();
}

void Player::updateBox(){
  myBox.x = xOffset;
  myBox.y = yOffset;
}

void Player::set_clips(){
    int aWidth, aHeight;
    int pWidth, pHeight;
    aWidth = 31;
    aHeight = 32;
    pWidth = 50;
    pHeight = 35;

    AclipsDown[0].x = 0;
    AclipsDown[0].y = 0;
    AclipsDown[0].w = aWidth;
    AclipsDown[0].h = aHeight;

    //Clip range for the top middle
    AclipsDown[1].x = aWidth;
    AclipsDown[1].y = 0;
    AclipsDown[1].w = aWidth;
    AclipsDown[1].h = aHeight;

//Clip range for the top right
    AclipsDown[2].x = aWidth*2;
    AclipsDown[2].y = 0;
    AclipsDown[2].w = aWidth;
    AclipsDown[2].h = aHeight;

   //Clip range for the middle left
    AclipsLeft[0].x = 0;
    AclipsLeft[0].y = aHeight+2;
    AclipsLeft[0].w = aWidth;
    AclipsLeft[0].h = aHeight;
        //Clip range for the middle
    AclipsLeft[1].x = aWidth;
    AclipsLeft[1].y = aHeight+2;
    AclipsLeft[1].w = aWidth;
    AclipsLeft[1].h = aHeight;

    //Clip range for the middle right
    AclipsLeft[2].x = aWidth*2;
    AclipsLeft[2].y = aHeight+2;
    AclipsLeft[2].w = aWidth;
    AclipsLeft[2].h = aHeight;

    AclipsRight[0].x = 0;
    AclipsRight[0].y = aHeight*2+2;
    AclipsRight[0].w = aWidth;
    AclipsRight[0].h = aHeight;

    //Clip range for the bottom middle
    AclipsRight[1].x = aWidth;
    AclipsRight[1].y = aHeight*2+2;
    AclipsRight[1].w = aWidth;
    AclipsRight[1].h = aHeight;
    //Clip range for the bottom right
    AclipsRight[2].x = aWidth*2;
    AclipsRight[2].y = aHeight*2+2;
     AclipsRight[2].w = aWidth;
    AclipsRight[2].h = aHeight;

    AclipsUp[0].x = 0;
    AclipsUp[0].y = aHeight*3+2;
    AclipsUp[0].w = aWidth;
    AclipsUp[0].h = aHeight;

    //Clip range for the bottom middle
    AclipsUp[1].x = aWidth;
    AclipsUp[1].y = aHeight*3+2;
    AclipsUp[1].w = aWidth;
    AclipsUp[1].h = aHeight;
    //Clip range for the bottom right
    AclipsUp[2].x = aWidth*2;
    AclipsUp[2].y = aHeight*3+2;
    AclipsUp[2].w = aWidth;
    AclipsUp[2].h = aHeight;

    PclipsRight[0].x = pWidth;
    PclipsRight[0].y = 0;
    PclipsRight[0].w = pWidth;
    PclipsRight[0].h = pHeight;

    PclipsRight[1].x = pWidth*2;
    PclipsRight[1].y = 0;
    PclipsRight[1].w = pWidth;
    PclipsRight[1].h = pHeight;

    PclipsRight[2].x = pWidth*3;
    PclipsRight[2].y = 0;
    PclipsRight[2].w = pWidth;
    PclipsRight[2].h = pHeight;

    PclipsLeft[0].x = pWidth*7-5;
    PclipsLeft[0].y = 0;
    PclipsLeft[0].w = pWidth-10;
    PclipsLeft[0].h = pHeight;

    PclipsLeft[1].x = pWidth*8-5;
    PclipsLeft[1].y = 0;
    PclipsLeft[1].w = pWidth-10;
    PclipsLeft[1].h = pHeight;

    PclipsLeft[2].x = pWidth*9-5;
    PclipsLeft[2].y = 0;
    PclipsLeft[2].w = pWidth-10;
    PclipsLeft[2].h = pHeight;

    PclipsDown[0].x = 0;
    PclipsDown[0].y = 0;
    PclipsDown[0].w = pWidth;
    PclipsDown[0].h = pHeight;

    PclipsDown[1].x = pWidth*4;
    PclipsDown[1].y = 0;
    PclipsDown[1].w = pWidth;
    PclipsDown[1].h = pHeight;


    PclipsUp[0].x = pWidth*5;
    PclipsUp[0].y = 0;
    PclipsUp[0].w = pWidth;
    PclipsUp[0].h = pHeight;

    PclipsUp[1].x = pWidth*6;
    PclipsUp[1].y = 0;
    PclipsUp[1].w = pWidth-6;
    PclipsUp[1].h = pHeight;


}


void Player::handle_events(){
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Set the xvel
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: xvel += A_WIDTH / 4; break;
            case SDLK_LEFT: xvel -= A_WIDTH / 4; break;
            case SDLK_DOWN: yvel += A_HEIGHT / 4; break;
            case SDLK_UP: yvel -= A_HEIGHT / 4; break;
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Set the xvel
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: xvel -= A_WIDTH / 4; break;
            case SDLK_LEFT: xvel += A_WIDTH / 4; break;
            case SDLK_DOWN: yvel -= A_HEIGHT/4; break;
  }
    }
}
int Player::move(){
//move
  if(status == ASH_LEFT || status == ASH_RIGHT){
    xOffset += xvel;
  } else  yOffset += yvel;
// keep in bounds
  if((xOffset<0) || (xOffset + A_WIDTH > SCREEN_WIDTH)){
        xOffset -= xvel;
  }
  if((yOffset < 0) || (yOffset + A_HEIGHT > SCREEN_HEIGHT)){
        yOffset -= yvel;
   }

  updateBox();

 if(check_collision(myBox, Shop)){
      cout << "Shop!" << endl; //for testing
        return TO_SHOP;
  }
  else if(check_collision(myBox, PC)) {
     cout << "PC" << endl; //for testing
        return TO_PC;
  }
  else if(check_collision(myBox, Home)){
       cout << "HOME" << endl; //for testing
        return TO_HOME;
   }
  else if(check_collision(myBox, Gym)){
      cout << "Gym! " << endl; //for testing
         return TO_GYM;
  }
  else if(check_collision(myBox, Grass)){
      cout << "On grass! " ; // for testing
        return TO_GRASS;
  }
  else {
      cout << "nothing" ; // for testing
        return STAY;
  } 
}

void Player::show(){
   //if moving to left
   if(xvel < 0){
        status = ASH_LEFT; //set animation to left
        Pframe++; // next Pframe
        Aframe++;
    }
  //if moving to the right
  else if(xvel > 0){
        status = ASH_RIGHT;
        Pframe++;
        Aframe++;
  }
  else if(yvel < 0){
        status = ASH_UP;
        Pframe++;
        Aframe++;
  }
  else if(yvel > 0 ) {
        status = ASH_DOWN;
        Pframe++;
        Aframe++;

 }
  else{ //standing still
        Pframe = 0;
        Aframe = 0;
  }
// loop animation
  if((Pframe >= 4 && (status == ASH_LEFT || status == ASH_RIGHT)) || (Pframe>=2 && (status == ASH_UP || status == ASH_DOWN)) ){
        Pframe = 0;
  }
  if(Aframe >= 3) Aframe = 0;

  if(status == ASH_LEFT){
        apply_surface(xOffset,yOffset, ash, screen, &AclipsLeft[Aframe]);
        apply_surface(xOffset + A_WIDTH, yOffset, pika, screen, &PclipsLeft[Pframe]);
  } else if( status == ASH_RIGHT){
        apply_surface(xOffset,yOffset, ash, screen, &AclipsRight[Aframe]);
        apply_surface(xOffset - A_HEIGHT -2, yOffset, pika, screen, &PclipsRight[Pframe]);
  } else if(status == ASH_UP){
        apply_surface(xOffset,yOffset, ash, screen, &AclipsUp[Aframe]);
        apply_surface(xOffset - IMG_OFFSET, yOffset + A_HEIGHT, pika, screen, &PclipsUp[Pframe]);
  }
}
