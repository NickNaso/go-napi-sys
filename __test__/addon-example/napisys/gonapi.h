#ifndef GO_NAPI_H
#define GO_NAPI_H

#include <node_api.h>

#ifdef __cplusplus
extern "C" {
#endif

extern napi_callback Callback(void* caller);
extern napi_async_execute_callback AsyncExecuteCallback(void* caller);
extern napi_async_complete_callback AsyncCompleteCallback(void* caller);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // GO_NAPI_H