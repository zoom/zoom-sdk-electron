#ifndef _ZOOM_NODE_MEETING_H323_CTRL_H_
#define _ZOOM_NODE_MEETING_H323_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeMeetingH323CtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingH323CtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingH323CtrlWrap >;
private:
	ZoomNodeMeetingH323CtrlWrap();
	~ZoomNodeMeetingH323CtrlWrap();
public:
	/// \brief Call out with the assigned H.323 device.
	/// \param 1. deviceName(string) Specifies the device name.
	/// \param 2. deviceIP(string) Specifies the device ip.  To get extended information,see \link ZNH323DeviceType \endlink enum.
	/// \param 3. deviceE164num(string) Specifies the device E164 number.
	/// \param 4. type(number) Specifies the H.323 device type.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS. 
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void CallOutH323(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Cancel current outgoing call.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void CancelCallOutH323(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the list of H.323 call-in number supported by the current meeting.
	/// \return If the function succeeds, the return value is the array of the call-in number. Otherwise failed, the return value is an empty array.
	static void GetH323Address(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the H.323 password for the current meeting.
	/// \return If the function succeeds, the return value is the H.323 meeting connect password. Otherwise failed, the return value is an empty string.
	static void GetH323Password(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the list of the call-out devices supported by the current meeting.
	/// \return If the function succeeds, the return value is the array of devices which includes deviceName, deviceIP, deviceE164num, deviceType. 
	///Otherwise failed, the return value is an empty array. 
	static void GetCalloutH323DviceList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the callback when the calling status of H.323 device changes.
	/// \param 1. callback(function)  The callback when the calling status of H.323 device changes, onCalloutStatusNotify. 
	///To get extended calling status information, see \link ZNH323CalloutStatus \endlink enum.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetH323CallOutStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);


	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingH323CtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingH323CtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "CallOutH323", ZoomNodeMeetingH323CtrlWrap::CallOutH323);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CancelCallOutH323", ZoomNodeMeetingH323CtrlWrap::CancelCallOutH323);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetH323Address", ZoomNodeMeetingH323CtrlWrap::GetH323Address);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetH323Password", ZoomNodeMeetingH323CtrlWrap::GetH323Password);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCalloutH323DviceList", ZoomNodeMeetingH323CtrlWrap::GetCalloutH323DviceList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetH323CallOutStatusCB", ZoomNodeMeetingH323CtrlWrap::SetH323CallOutStatusCB);

}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingH323CtrlWrap >() {
	return &ZoomNodeMeetingH323CtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
