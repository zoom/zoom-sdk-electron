#ifndef _ZOOM_NODE_MEETING_VIDEO_CTRL_H_
#define _ZOOM_NODE_MEETING_VIDEO_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingVideoCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingVideoCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingVideoCtrlWrap >;
private:
	ZoomNodeMeetingVideoCtrlWrap();
	~ZoomNodeMeetingVideoCtrlWrap();
public:
	/// \brief Turn off the specified user's video.
	/// \param 1. userid(number) Specifies the user ID. If userid is Zero(0), user's own video will be turned off.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void MuteVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Turn on the specified user's video.
	/// \param 1. userid(number) Specifies the user ID. If userid is Zero(0), user's own video will be turned on.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void UnMuteVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Pin the video of the assigned user.
	/// \param 1. bPin(bool) TRUE indicates to pin.
	/// \param 2. bFirstView(bool) TRUE indicates to pin the video on the primary view. FALSE indicates to pin the video on the secondary view. The function does not work when the user chooses FALSE without dual view.
	/// \param 3. userid(number) Specifies the user ID to be pinned. 
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void PinVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Spotlight the video of the assigned user.
	/// \param 1. bSpotlight(bool) TRUE indicates to spotlight.
	/// \param 2. userid(number) Specifies the user ID to be spotlighted.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SpotlightVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Display or not the user who does not turn on the video in the video all mode.
	/// \param 1. bHide(bool) TRUE indicates to hide, FALSE show.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void HideOrShowNoVideoUserOnVideoWall(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set callback function of notification of the user video status changes.
	/// \param 1. callback(function) Callback function of notification of the user video status changes, onUserVideoStatusChange.
	///To get extended video status information, see \link ZNVideoStatus \endlink enum.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetMeetingVideoStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set callback function of notification of the active speaker video user changes.
	/// \param 1. callback(function) Callback function of notification of the active speaker video user changes, onActiveSpeakerVideoUserChanged.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetActiveSpeakerVideoUserChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set callback function of notification of the active video user changes.
	/// \param 1. callback(function) Callback function of notification of the active video user changes, onActiveVideoUserChanged.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetActiveVideoUserChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingVideoCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingVideoCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "MuteVideo", ZoomNodeMeetingVideoCtrlWrap::MuteVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnMuteVideo", ZoomNodeMeetingVideoCtrlWrap::UnMuteVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "PinVideo", ZoomNodeMeetingVideoCtrlWrap::PinVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SpotlightVideo", ZoomNodeMeetingVideoCtrlWrap::SpotlightVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideOrShowNoVideoUserOnVideoWall", ZoomNodeMeetingVideoCtrlWrap::HideOrShowNoVideoUserOnVideoWall);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingVideoStatusCB", ZoomNodeMeetingVideoCtrlWrap::SetMeetingVideoStatusCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetActiveSpeakerVideoUserChangedCB", ZoomNodeMeetingVideoCtrlWrap::SetActiveSpeakerVideoUserChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetActiveVideoUserChangedCB", ZoomNodeMeetingVideoCtrlWrap::SetActiveVideoUserChangedCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingVideoCtrlWrap >() {
	return &ZoomNodeMeetingVideoCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
