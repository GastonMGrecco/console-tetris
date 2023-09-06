#ifndef RESIZE_H
#define RESIZE_H
#include "../variables/var.h"
void resize(){
     if (
            initial_width != windowWidth ||
            initial_height != windowHeight

        )
        {
            clear();
            initial_width = windowWidth;
            initial_height = windowHeight;
        }
}
#endif