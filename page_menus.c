#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "utilities.h"
#include "menu_utils.h"




void landingPage(){
    clearScreen();

    int width = 30;

    char *buttons[] = {"Log In", "Sign Up"};
    int selection = inlineOneButtonSelect(width, buttons, 2, (windowWidth()-2*width)/2, 3, 1, (windowHeight()-3)/2);

    switch (selection)
    {
    case 0:
        // TODO
        printf("LogIn Screen");
        break;
    
    case 1:
        // TODO
        printf("SignIn Screen");
        break;
    
    default:
        break;
    }
    
}