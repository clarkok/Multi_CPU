#include "Mock_Top.h"

int main (int argc, char* argv[]) {
  Mock_Top_t* module = new Mock_Top_t();
  module->init();
  Mock_Top_api_t* api = new Mock_Top_api_t();
  api->init(module);
  FILE *f = NULL;
  FILE *tee = NULL;  module->set_dumpfile(f);
  api->set_teefile(tee);
  api->read_eval_print_loop();
  if (f) fclose(f);
  if (tee) fclose(tee);
}
