#include "gonapi.h"

#include "_cgo_export.h"

struct CallbackWrap {
  CallbackWrap(void* data) : data{data} {}
  napi_callback operator()() {
    static auto dataCopy = data;
    return [](napi_env env, napi_callback_info info) -> napi_value {
        return CallCallback(dataCopy, env, info);
    };
  }
  void* data;
};

struct AsyncExecuteCallbackWrap {
  AsyncExecuteCallbackWrap(void* data) : data{data} {}
  napi_async_execute_callback operator()() {
    static auto dataCopy = data;
    return [](napi_env env, void* data) -> void {
        return CallAsyncExecuteCallback(dataCopy, env, data);
    };
  }
  void* data;
};

struct AsyncCompleteCallbackWrap {
  AsyncCompleteCallbackWrap(void* data) : data{data} {}
  napi_async_complete_callback operator()() {
    static auto dataCopy = data;
    return [](napi_env env, napi_status status, void* data) -> void {
        return CallAsyncCompleteCallback(dataCopy, env, status, data);
    };
  }
  void* data;
};

napi_callback Callback(void* caller) {
  CallbackWrap cb{caller};
  return cb();
}

napi_async_execute_callback AsyncExecuteCallback(void* caller) {
  AsyncExecuteCallbackWrap cb{caller};
  return cb();

}

napi_async_complete_callback AsyncCompleteCallback(void* caller) {
  AsyncCompleteCallbackWrap cb{caller};
  return cb();
}
