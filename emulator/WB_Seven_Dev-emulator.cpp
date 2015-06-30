#include "WB_Seven_Dev.h"

int main (int argc, char* argv[]) {
  WB_Seven_Dev_t* module = new WB_Seven_Dev_t();
  module->init();
  WB_Seven_Dev_api_t* api = new WB_Seven_Dev_api_t();
  api->init(module);
  FILE *f = NULL;
  FILE *tee = NULL;  module->set_dumpfile(f);
  api->set_teefile(tee);
  api->read_eval_print_loop();
  if (f) fclose(f);
  if (tee) fclose(tee);
}
