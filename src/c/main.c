#include <pebble.h>
#include "splash_window.h"
#include "main_window.h"
#include "error_window.h"

void launch_main_window(void *data) {
  window_stack_push(main_window_get_window(), true);
}

int main() {
  splash_window_create();
  window_stack_push(splash_window_get_window(), true);
  error_window_create();
  app_timer_register(2000, launch_main_window, NULL);
  
  main_window_create();
  window_stack_push(splash_window_get_window(), true);
  app_event_loop();
  splash_window_destroy();
  main_window_destroy();
  error_window_destroy();
}