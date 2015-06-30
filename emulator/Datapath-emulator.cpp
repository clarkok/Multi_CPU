#include "Datapath.h"

int main (int argc, char* argv[]) {
  Datapath_t* module = new Datapath_t();
  module->init();
  Datapath_api_t* api = new Datapath_api_t();
  api->init(module);
  FILE *f = NULL;
  FILE *tee = NULL;  module->set_dumpfile(f);
  api->set_teefile(tee);
  api->read_eval_print_loop();
  if (f) fclose(f);
  if (tee) fclose(tee);
}
