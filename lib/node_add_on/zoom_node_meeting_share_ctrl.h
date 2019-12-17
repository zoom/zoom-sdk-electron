#ifndef _ZOOM_NODE_MEETING_SHARE_CTRL_H_
#define _ZOOM_NODE_MEETING_SHARE_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeMeetingShareCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingShareCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingShareCtrlWrap >;
private:
	ZoomNodeMeetingShareCtrlWrap();
	~ZoomNodeMeetingShareCtrlWrap();
public:
	/// \brief Share the specified application.
	/// \param 1. hShare_app(string) Specify the window handle of the application to be shared. If the hShare_app can't be shared, the return value is the ZNSDKERR_INVALID_PARAMETER error code. If the hShare_app is empty, the primary monitor will be shared. 
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void StartAppShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Share the specified monitor.
	/// \param 1. monitorID(string) Specify the monitor ID to be shared. If the monitorID is empty, the primary monitor will be shared.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void StartMonitorShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Stop the current sharing.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void StopShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set callback function of notification of the changed sharing status.
	/// \param 1. callback(function) Callback function of notification of the changed sharing status, onSharingStatus.
	///To get extended sharing status information, see \link ZNShareStatus \endlink enum.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetOnSharingStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingShareCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingShareCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartAppShare", ZoomNodeMeetingShareCtrlWrap::StartAppShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartMonitorShare", ZoomNodeMeetingShareCtrlWrap::StartMonitorShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopShare", ZoomNodeMeetingShareCtrlWrap::StopShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnSharingStatusCB", ZoomNodeMeetingShareCtrlWrap::SetOnSharingStatusCB);
	
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingShareCtrlWrap >() {
	return &ZoomNodeMeetingShareCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
