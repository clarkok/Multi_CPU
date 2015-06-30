#include "Regsiter_File.h"

int main (int argc, char* argv[]) {
  Regsiter_File_t* module = new Regsiter_File_t();
  module->init();
  Regsiter_File_api_t* api = new Regsiter_File_api_t();
  api->init(module);
  FILE *f = NULL;
  FILE *tee = NULL;  module->set_dumpfile(f);
  api->set_teefile(tee);
  api->read_eval_print_loop();
  if (f) fclose(f);
  if (tee) fclose(tee);
}
