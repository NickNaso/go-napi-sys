#include <node_api.h>
//#include <assert.h>
#include "libgoaddon.h"

/*napi_value Method(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value world;
  status = napi_create_string_utf8(env, "world", 5, &world);
  assert(status == napi_ok);
  return world;
}*/

/*#define DECLARE_NAPI_METHOD(name, func)                          \
  { name, 0, func, 0, 0, 0, napi_default, 0 }*/

/*napi_value Init(napi_env env, napi_value exports) {
  Example();
  napi_status status;
  napi_property_descriptor desc = DECLARE_NAPI_METHOD("hello", Method);
  status = napi_define_properties(env, exports, 1, &desc);
  assert(status == napi_ok);
  return exports;
}*/

napi_value Init(napi_env env, napi_value  exports) {
  return (napi_value) Initialize((void*) env, (void*) exports);
  //return Initialize(env, exports);
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
