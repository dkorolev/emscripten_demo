#include <string>
#include <emscripten.h>
#include <emscripten/bind.h>

using namespace emscripten;

std::string wasmVersion() {
  return "1.0";
}

int demoAdd(int a, int b) {
  return 100+a+b;
}

int demoMul(int a, int b) {
  return 100+a*b;
}

EMSCRIPTEN_BINDINGS(my_module) {
  function("wasmVersion", &wasmVersion);
  function("demoAdd", &demoAdd);
  function("demoMul", &demoMul);
}
