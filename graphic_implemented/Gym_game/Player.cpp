//Katie Quinn
// Player.cpp
#include "Player.h"
#include "globals.h"
#include "function.h"
#include <iostream>
using namespace std;

//sprite sheet 
SDL_Rect AclipsRight[3];
SDL_Rect AclipsLeft[3];
SDL_Rect AclipsUp[3];
SDL_Rect AclipsDown[3];
SDL_Rect PclipsRight[3];
SDL_Rect PclipsLeft[3];
SDL_Rect PclipsDown[2];
SDL_Rect PclipsUp[2];

//constructor
Player::Player(){
  xOffset = 200;
  yOffset = 550;
  xvel = 0;
  yvel = 0;
  Pframe = 0;
  Aframe = 0; 
  status = ASH_RIGHT;
  myBox.w = A_WIDTH;
  myBox.h = A_HEIGHT;
  updateBox();
  set_clips();

}

void Player::updateBox(){
  myBox.x = xOffset;
  myBox.y = yOffset;

}

void Player::movePlayer(int x, int y){
	xOffset = x;
	yOffset = y;
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
	    		case SDLK_UP: yvel += A_HEIGHT / 4; break;
        }
    }
}
int Player::move(){
//move
  if(status == ASH_LEFT || status == ASH_RIGHT){
    xOffset += xvel;
  } else  yOffset += yvel;
// keep in bounds
//for up
  if(status == ASH_UP){
		if(yOffset < 429 && (yOffset + A_HEIGHT > 429) && (xOffset + A_WIDTH > 257)){
			yOffset = 431;
      }
		if( yOffset < 342 && (yOffset + A_HEIGHT) > 342 && (xOffset + A_WIDTH) > 131 && xOffset < 215)
				yOffset = 344;
	   if( yOffset < 219 && (yOffset + A_HEIGHT) > 219 && xOffset > 83 && xOffset < 299)
				yOffset = 221;
		if( yOffset < 138 && (yOffset + A_HEIGHT) > 138 && xOffset > 260 && (xOffset + A_WIDTH) < 341)
				yOffset = 140;
		if(yOffset < 90 && (yOffset + A_HEIGHT) > 90 && xOffset > 176 && (xOffset + A_WIDTH) < 260)
				yOffset = 92;
		if( yOffset < 138 && (yOffset+ A_HEIGHT) > 138 && xOffset > 83 && xOffset < 176)
				yOffset = 140;
  }
//for down
  else if(status == ASH_DOWN){
			if( yOffset < SCREEN_HEIGHT - 2 && (yOffset + A_HEIGHT) > SCREEN_HEIGHT - 2 && (xOffset + A_WIDTH) > 257)
				yOffset = SCREEN_HEIGHT - 4 - A_HEIGHT;
			if( yOffset < 387 && (yOffset + A_HEIGHT) > 387 && xOffset > 83 && xOffset < 170)
				yOffset = 389 - A_HEIGHT;
			if( yOffset < 258 && (yOffset + A_HEIGHT) > 258 && xOffset > 128 && xOffset < 215)
				yOffset = 256 - A_HEIGHT;
			if( yOffset < 258 && (yOffset + A_HEIGHT) > 258 && xOffset > 257 && xOffset < 341)
				yOffset = 256 - A_HEIGHT;
			if( yOffset < 174 && (yOffset + A_HEIGHT) > 174 && xOffset > 83 && xOffset< 299)
				yOffset = 172 - A_HEIGHT;
  }
//for right
  else if(status == ASH_RIGHT){
			if( xOffset <  296 && (xOffset + A_WIDTH) > 296 && yOffset > 432)
				xOffset = 294 - A_WIDTH;
			if( xOffset < 257 && (xOffset + A_WIDTH) > 257 && (yOffset + A_HEIGHT) > 258 && yOffset < 432)
				xOffset = 255 - A_WIDTH;
			if( xOffset < 131 && (xOffset + A_WIDTH) > 131 && (yOffset + A_HEIGHT) > 258 && yOffset < 342)
				xOffset = 129 - A_WIDTH;
			if( xOffset < 341 && (xOffset + A_WIDTH) > 341 && yOffset > 138 && (yOffset + A_HEIGHT) < 258)
				xOffset = 339 - A_WIDTH;
			if( xOffset < 260 && (xOffset + A_WIDTH) > 260 && yOffset > 0 && yOffset < 138)
				xOffset = 258 - A_WIDTH;
	}		
//for left
	else if(status == ASH_LEFT){
			if( xOffset < 170 && (xOffset + A_WIDTH > 170) && (yOffset + A_HEIGHT) > 387)
				xOffset = 172;
			if( xOffset < 86 && (xOffset + A_WIDTH) > 86 && yOffset > 215 && yOffset < 388)
				xOffset = 88;
			if( xOffset < 215 && (xOffset + A_WIDTH) > 214 && (yOffset + A_HEIGHT) > 255 && yOffset < 343)
				xOffset = 217;
			if( xOffset < 301 && (xOffset + A_WIDTH) > 301 && yOffset < 219 && (yOffset + A_HEIGHT) > 174)
				xOffset = 140;
			if( xOffset < 176 && (xOffset + A_WIDTH) > 176 && yOffset > 90 && yOffset < 138)
				xOffset = 178;
			if( xOffset < 86 && (xOffset + A_WIDTH) > 86 && yOffset > 135 && yOffset < 174)
				xOffset = 88;	
	}
//keeps the trainer in bounds
  if(status == ASH_LEFT || status == ASH_RIGHT){
    if((xOffset<0) || (xOffset + A_WIDTH > SCREEN_WIDTH)){
			xOffset -= xvel;
  		}
  }
  else if((yOffset < 0) || (yOffset + A_HEIGHT > SCREEN_HEIGHT)){
	yOffset -= yvel;
   }

  updateBox(); //update the x and y coordinates of the box

if(check_collision(myBox, Swimmer)){
//	cout << "Shop!" << endl; //for testing
	return FIRST_FIGHT;
  }
  else if(check_collision(myBox, Trainer)) {
//	cout << "PC" << endl; //for testing
	return SECOND_FIGHT;
  }
  else if(check_collision(myBox, Misty)){
//	 cout << "HOME" << endl; //for testing
 	return THIRD_FIGHT;
   }
  else {
//	cout << "nothing" ; // for testing
	return IDLE;
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
  }  else if(status == ASH_DOWN){
	apply_surface(xOffset, yOffset, ash, screen, &AclipsDown[Aframe]);
	apply_surface(xOffset - IMG_OFFSET,  yOffset - A_HEIGHT, pika, screen, &PclipsDown[Pframe]);
  }

//  if(pika == NULL) cout << "pika is null" << endl;
//  if(ash == NULL) cout << "ash is null" << endl;
//  if(screen == NULL) cout << "screen is null " << endl;
}

void Player::set_clips(){ //set the sprite clips
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
