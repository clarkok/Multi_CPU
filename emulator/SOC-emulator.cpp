#include "SOC.h"

int main (int argc, char* argv[]) {
  SOC_t* module = new SOC_t();
  module->init();
  SOC_api_t* api = new SOC_api_t();
  api->init(module);
  FILE *f = NULL;
  FILE *tee = NULL;  module->set_dumpfile(f);
  api->set_teefile(tee);
  api->read_eval_print_loop();
  if (f) fclose(f);
  if (tee) fclose(tee);
}
