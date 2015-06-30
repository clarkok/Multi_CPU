#include "WB_Bus.h"

int main (int argc, char* argv[]) {
  WB_Bus_t* module = new WB_Bus_t();
  module->init();
  WB_Bus_api_t* api = new WB_Bus_api_t();
  api->init(module);
  FILE *f = NULL;
  FILE *tee = NULL;  module->set_dumpfile(f);
  api->set_teefile(tee);
  api->read_eval_print_loop();
  if (f) fclose(f);
  if (tee) fclose(tee);
}
