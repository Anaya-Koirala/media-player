#include "include/play_demo.h"
#include "include/play_video.h"
#include "include/gui.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc > 2) {
    play_video(argc, argv);
  } else if (argc == 2) {
    if (strcmp(argv[1], "-d") == 0) {
      play_demo(argc, argv);
    }else if (strcmp(argv[1], "-h") == 0) {
      printf("\t\tMEDIA PLAYER\nPlay Local Video File: player -v "
             "<filename>\nPlay Web Video File: player -u <url>\nPlay Demo Web "
             "Video: -d\nHelp: -h\nGUI Mode: -g (comming soon)\n");
    }else if (strcmp(argv[1], "-g") == 0) {
        open_file();
    }
  }else {
    printf("**FAILED PARSING VIDEO** \nHelp: Check if you entered the right "
           "video path or url\nHelp: Check your flags\nTip: Use *-h* for help screen");
  }
}
