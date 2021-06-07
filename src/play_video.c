#include "gst/gst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int play_video(int argc, char *argv[]) {
  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;

  gst_init(&argc, &argv);
  char buffer[150];
  if (strcmp(argv[1], "-v") == 0 & argv[2] != 0) {
    char *filename =
        sprintf(buffer, "playbin uri=file:///home/%s/%s", getlogin(), argv[2]);
  } else if ((strcmp(argv[1], "-u") == 0 & argv[2] != 0)) {
    char *filename = sprintf(buffer, "playbin uri=%s", argv[2]);
  }
  pipeline = gst_parse_launch(buffer, NULL);
  gst_element_set_state(pipeline, GST_STATE_PLAYING);

  bus = gst_element_get_bus(pipeline);
  msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,
                                   GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

  if (msg != NULL) {
    gst_message_unref(msg);
  }
  gst_object_unref(bus);
  gst_element_set_state(pipeline, GST_STATE_NULL);
  gst_object_unref(pipeline);
  return 0;
}
