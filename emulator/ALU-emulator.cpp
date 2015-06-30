#include "ALU.h"

int main (int argc, char* argv[]) {
  ALU_t* module = new ALU_t();
  module->init();
  ALU_api_t* api = new ALU_api_t();
  api->init(module);
  FILE *f = NULL;
  FILE *tee = NULL;  module->set_dumpfile(f);
  api->set_teefile(tee);
  api->read_eval_print_loop();
  if (f) fclose(f);
  if (tee) fclose(tee);
}
