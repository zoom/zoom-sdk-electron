#ifndef _ZOOM_NODE_MEETING_PARTICIPANTS_CTRL_H_
#define _ZOOM_NODE_MEETING_PARTICIPANTS_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingParticipantsCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingParticipantsCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingParticipantsCtrlWrap >;
private:
	ZoomNodeMeetingParticipantsCtrlWrap();
	~ZoomNodeMeetingParticipantsCtrlWrap();
public:
	/// \brief Get the list of all the panelists in the meeting.
	/// \return If the function succeeds, the return value is the list of the panelists in the meeting.
	///Otherwise failed, the return value is an empty array.
	static void GetParticipantsList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the information of specified user.
	/// \param 1. userid(number) Specify the user ID for which you want to get the information. 
	///Zero(0) indicates to get the information of the current user.
	/// \return If the function succeeds, the return value is an object which includes the user's infomation.
	///For more details, see \link ZNUserInfomation \endlink. Otherwise failed, the return value is an empty object.
	static void GetUserInfoByUserID(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set callback function of notification of users who are in the meeting.
	/// \param 1. callback(function) Callback function of notification of users who are in the meeting, onUserJoin
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetMeetingUserJoinCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set callback function of notification of users who leave the meeting.
	/// \param 1. callback(function) Callback function of notification of users who leave the meeting, onUserLeft
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetMeetingUserLeftCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set callback function of notification of the new host.
	/// \param 1. callback(function) Callback function of notification of the new host, onHostChangeNotification
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetMeetingHostChangeCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingParticipantsCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingParticipantsCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetParticipantsList", ZoomNodeMeetingParticipantsCtrlWrap::GetParticipantsList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetUserInfoByUserID", ZoomNodeMeetingParticipantsCtrlWrap::GetUserInfoByUserID);

	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingUserJoinCB", ZoomNodeMeetingParticipantsCtrlWrap::SetMeetingUserJoinCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingUserLeftCB", ZoomNodeMeetingParticipantsCtrlWrap::SetMeetingUserLeftCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingHostChangeCB", ZoomNodeMeetingParticipantsCtrlWrap::SetMeetingHostChangeCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingParticipantsCtrlWrap >() {
	return &ZoomNodeMeetingParticipantsCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
