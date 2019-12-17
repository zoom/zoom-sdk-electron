#ifndef _ZOOM_NODE_VIDEO_RAW_DATA_H_
#define _ZOOM_NODE_VIDEO_RAW_DATA_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeVideoRawDataWrap :
	public ZoomWrapObject<ZoomNodeVideoRawDataWrap >
{
	friend class ZoomWrapObject<ZoomNodeVideoRawDataWrap >;
private:
	ZoomNodeVideoRawDataWrap();
	virtual ~ZoomNodeVideoRawDataWrap();
public:
	/// \brief Set callback functions of notification of video raw data passed from native_sdk layer.
	/// \param 1. callback(function) Callback function of notification of video raw data passed from native_sdk layer, onVideoRawDataReceived.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set callback functions of notification of subscribed user video on in rawdata module.
	/// \param 1. callback(function) Callback function of notification of video on in rawdata module, onSubscribedVideoUserDataOn.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetRawDataVideoUserDataOnCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set callback functions of notification of subscribed user video off in rawdata module.
	/// \param 1. callback(function) Callback function of notification of video off in rawdata module, onSubscribedVideoUserDataOff.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetRawDataVideoUserDataOffCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set callback functions of notification of the subscribed user's left whose video is on in rawdata module.
	/// \param 1. callback(function) Callback function of notification of the user's left  whose video is on in rawdata module, onSubscribedVideoUserLeft.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetRawDataVideoUserLeftCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Start video raw data channel.
	/// \param 1. rawDataMemoryMode(number) see \link RawDataMemoryMode \endlink enum.
	/// \return If the function succeeds, the return value is SDKRawDataError_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKRawDataError \endlink enum.
	static void Start(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Subscribe one user's video_raw_data.
	/// \param 1. userid(number) Specify the user ID for which you want to get the video_raw_data. 
	/// \param 2. size(number) Specify the video_raw_data resolution you want to get. To get extended resolution information, see \link RawDataResolution \endlink enum.
	/// \param 3. recver_handle(number) Specify the SubWindow in which you want to render the video_raw_data. 
	/// \return If the function succeeds, the return value is SDKRawDataError_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKRawDataError \endlink enum.
	static void Subscribe(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief UnSubscribe one user's video_raw_data.
	/// \param 1. userid(number) Specify the user ID for which you want to unsubscribe the video_raw_data. 
	/// \param 2. recver_handle(number) Specify the SubWindow in which you want to stop rendering the video_raw_data. 
	/// \return If the function succeeds, the return value is SDKRawDataError_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKRawDataError \endlink enum.
	static void UnSubscribe(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetLocalDeviceStatus(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RotateLocalDevice(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Stop video raw data channel.
	/// \return If the function succeeds, the return value is SDKRawDataError_SUCCESS.
	///Otherwise failed. To get extended error information, see \link SDKRawDataError \endlink enum.
	static void Stop(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void StartPipeServer(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopPipeServer(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeVideoRawDataWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeVideoRawDataWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRawDataCB", ZoomNodeVideoRawDataWrap::SetRawDataCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRawDataVideoUserDataOnCB", ZoomNodeVideoRawDataWrap::SetRawDataVideoUserDataOnCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRawDataVideoUserDataOffCB", ZoomNodeVideoRawDataWrap::SetRawDataVideoUserDataOffCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRawDataVideoUserLeftCB", ZoomNodeVideoRawDataWrap::SetRawDataVideoUserLeftCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Start", ZoomNodeVideoRawDataWrap::Start);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Subscribe", ZoomNodeVideoRawDataWrap::Subscribe);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnSubscribe", ZoomNodeVideoRawDataWrap::UnSubscribe);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetLocalDeviceStatus", ZoomNodeVideoRawDataWrap::GetLocalDeviceStatus);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RotateLocalDevice", ZoomNodeVideoRawDataWrap::RotateLocalDevice);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Stop", ZoomNodeVideoRawDataWrap::Stop);

	NODE_SET_PROTOTYPE_METHOD(tpl, "StartPipeServer", ZoomNodeVideoRawDataWrap::StartPipeServer);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopPipeServer", ZoomNodeVideoRawDataWrap::StopPipeServer);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeVideoRawDataWrap >() {
	return &ZoomNodeVideoRawDataWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#endif
