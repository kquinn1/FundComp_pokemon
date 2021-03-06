//Katie Quinn
//function.cpp
#include "function.h"
bool check_collision( SDL_Rect A, SDL_Rect B )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;

    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

SDL_Surface *load_image( std::string filename ) 
{
    //The image that's loaded
        SDL_Surface* loadedImage = NULL;
            
    //The optimized image that will be used
        SDL_Surface* optimizedImage = NULL;
                     
    //Load the image
        loadedImage = IMG_Load( filename.c_str() );
        
    //If the image loaded
        if( loadedImage != NULL )
        {
     //Create an optimized image
           optimizedImage = SDL_DisplayFormat( loadedImage );
    //Free the old image
         SDL_FreeSurface( loadedImage );
       }

	if( optimizedImage!=NULL){
	//Include a line that will color key the image
		Uint32 colorkey = SDL_MapRGB( optimizedImage->format,0,0,0);
		SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );

	}
    //Return the optimized image
         return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}
