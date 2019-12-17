#ifndef _ZOOM_NODE_SHARE_RAW_DATA_H_
#define _ZOOM_NODE_SHARE_RAW_DATA_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeShareRawDataWrap :
	public ZoomWrapObject<ZoomNodeShareRawDataWrap >
{
	friend class ZoomWrapObject<ZoomNodeShareRawDataWrap >;
private:
	ZoomNodeShareRawDataWrap();
	virtual ~ZoomNodeShareRawDataWrap();
public:
	/// \brief Set callback functions of notification of share raw data passed from native_sdk layer.
	/// \param 1. callback(function) Callback function of notification of share raw data passed from native_sdk layer, onShareRawDataReceived.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set callback functions of notification of subscribed user starting sharing in rawdata module.
	/// \param 1. callback(function) Callback function of notification of starting sharing in rawdata module, onSubscribedShareUserDataOn.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetRawDataShareUserDataOnCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set callback functions of notification of subscribed user stopping sharing in rawdata module.
	/// \param 1. callback(function) Callback function of notification of stopping sharing in rawdata module, onSubscribedShareUserDataOff.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetRawDataShareUserDataOffCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set callback functions of notification of the subscribed user's left who is sharing in rawdata module.
	/// \param 1. callback(function) Callback function of notification of the user's left who is sharing in rawdata module, onSubscribedShareUserLeft.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetRawDataShareUserLeftCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Start share raw data channel.
	/// \param 1. rawDataMemoryMode(number) see \link RawDataMemoryMode \endlink enum.
	/// \return If the function succeeds, the return value is SDKRawDataError_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKRawDataError \endlink enum.
	static void Start(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Subscribe one user's share_raw_data.
	/// \param 1. userid(number) Specify the user ID for which you want to get the share_raw_data. 
	/// \param 2. size(number) Specify the share_raw_data resolution you want to get. To get extended resolution information, see \link RawDataResolution \endlink enum.
	/// \param 3. recver_handle(number) Specify the SubWindow in which you want to render the share_raw_data. 
	/// \return If the function succeeds, the return value is SDKRawDataError_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKRawDataError \endlink enum.
	static void Subscribe(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief UnSubscribe one user's share_raw_data.
	/// \param 1. userid(number) Specify the user ID for which you want to unsubscribe the share_raw_data. 
	/// \param 2. recver_handle(number) Specify the SubWindow in which you want to stop rendering the share_raw_data. 
	/// \return If the function succeeds, the return value is SDKRawDataError_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKRawDataError \endlink enum.
	static void UnSubscribe(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Stop share raw data channel.
	/// \return If the function succeeds, the return value is SDKRawDataError_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKRawDataError \endlink enum.
	static void Stop(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void StartPipeServer(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopPipeServer(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeShareRawDataWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeShareRawDataWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRawDataCB", ZoomNodeShareRawDataWrap::SetRawDataCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRawDataShareUserDataOnCB", ZoomNodeShareRawDataWrap::SetRawDataShareUserDataOnCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRawDataShareUserDataOffCB", ZoomNodeShareRawDataWrap::SetRawDataShareUserDataOffCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRawDataShareUserLeftCB", ZoomNodeShareRawDataWrap::SetRawDataShareUserLeftCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Start", ZoomNodeShareRawDataWrap::Start);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Subscribe", ZoomNodeShareRawDataWrap::Subscribe);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnSubscribe", ZoomNodeShareRawDataWrap::UnSubscribe);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Stop", ZoomNodeShareRawDataWrap::Stop);

	NODE_SET_PROTOTYPE_METHOD(tpl, "StartPipeServer", ZoomNodeShareRawDataWrap::StartPipeServer);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopPipeServer", ZoomNodeShareRawDataWrap::StopPipeServer);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeShareRawDataWrap >() {
	return &ZoomNodeShareRawDataWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#endif
