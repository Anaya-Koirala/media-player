#include "include/play_demo.h"
#include <stdio.h>

void play_demo(int argc, char *argv[]) {
  system("./player -u "
         "https://ia801602.us.archive.org/11/items/"
         "Rick_Astley_Never_Gonna_Give_You_Up/"
         "Rick_Astley_Never_Gonna_Give_You_Up.ogv");
}
