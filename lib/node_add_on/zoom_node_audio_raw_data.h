#ifndef _ZOOM_NODE_AUDIO_RAW_DATA_H_
#define _ZOOM_NODE_AUDIO_RAW_DATA_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeAudioRawDataWrap :
	public ZoomWrapObject<ZoomNodeAudioRawDataWrap >
{
	friend class ZoomWrapObject<ZoomNodeAudioRawDataWrap >;
private:
	ZoomNodeAudioRawDataWrap();
	virtual ~ZoomNodeAudioRawDataWrap();
public:
	/// \brief Set callback functions of notification of audio raw data passed from native_sdk layer.
	/// \param 1. callback(function) Callback function of notification of mixed audio raw data passed from native_sdk layer, onMixedAudioRawDataReceived.
	/// \param 2. callback(function) Callback function of notification of one way audio raw data passed from native_sdk layer, onOneWayAudioRawDataReceived.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Start audio raw data channel.
	/// \param 1. rawDataMemoryMode(number) see \link RawDataMemoryMode \endlink enum.
	/// \return If the function succeeds, the return value is SDKRawDataError_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKRawDataError \endlink enum.
	static void Start(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Stop audio raw data channel.
	/// \return If the function succeeds, the return value is SDKRawDataError_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKRawDataError \endlink enum.
	static void Stop(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void StartPipeServer(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopPipeServer(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeAudioRawDataWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeAudioRawDataWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRawDataCB", ZoomNodeAudioRawDataWrap::SetRawDataCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Start", ZoomNodeAudioRawDataWrap::Start);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Stop", ZoomNodeAudioRawDataWrap::Stop);

	NODE_SET_PROTOTYPE_METHOD(tpl, "StartPipeServer", ZoomNodeAudioRawDataWrap::StartPipeServer);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopPipeServer", ZoomNodeAudioRawDataWrap::StopPipeServer);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeAudioRawDataWrap >() {
	return &ZoomNodeAudioRawDataWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#endif
