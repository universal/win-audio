#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <node_api.h>

napi_value toValue(napi_env env, int value){
  napi_value nvalue = 0;
  napi_create_int32(env, value, &nvalue);
  return nvalue;
}

napi_value get(napi_env env, napi_callback_info info) {

  return toValue(env, -1);

}

napi_value isMuted(napi_env env, napi_callback_info info) {

  return toValue(env, -999);

}

napi_value mute(napi_env env, napi_callback_info info) {

  return toValue(env, -1);

}

napi_value set(napi_env env, napi_callback_info info) {

  return toValue(env, -1);

}

napi_value Init(napi_env env, napi_value exports) {

  napi_status status;
  napi_value get_fn, set_fn, mute_fn, is_mute_fn;

  status = napi_create_function(env, NULL, 0, get, NULL, &get_fn);
  status = napi_create_function(env, NULL, 0, set, NULL, &set_fn);
  status = napi_create_function(env, NULL, 0, mute, NULL, &mute_fn);
  status = napi_create_function(env, NULL, 0, isMuted, NULL, &is_mute_fn);

  status = napi_set_named_property(env, exports, "get", get_fn);
  status = napi_set_named_property(env, exports, "set", set_fn);
  status = napi_set_named_property(env, exports, "mute", mute_fn);
  status = napi_set_named_property(env, exports, "isMuted", is_mute_fn);

  return exports;
}

NAPI_MODULE(addon, Init)