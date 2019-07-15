#ifndef _ZOOM_NODE_ADDON_H_
#define _ZOOM_NODE_ADDON_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

class ZOOM_NODE_HIDE ZoomNodeAuthWrap : 
	public ZoomWrapObject<ZoomNodeAuthWrap >
{
	friend class ZoomWrapObject<ZoomNodeAuthWrap >;
private:
	ZoomNodeAuthWrap();
	~ZoomNodeAuthWrap();
public:
	//param:1.key(required) 2.secret(required) 3.callback(required)
	static void Auth(const v8::FunctionCallbackInfo<v8::Value>& args);
	//param:1.user_name(required) 2.psw(required) 3.callback(required) 4.rememberme(optional)
	static void Login(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void LoginWithSSOToken(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Logout(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetAuthResult(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetLoginStatus(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetLoginCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetLogoutCB(const v8::FunctionCallbackInfo<v8::Value>& args);


	static v8::Persistent<v8::Function> constructor;
};

template<>
static void InitClassAttribute<ZoomNodeAuthWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeAuthWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "Auth", ZoomNodeAuthWrap::Auth);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Login", ZoomNodeAuthWrap::Login);
	NODE_SET_PROTOTYPE_METHOD(tpl, "LoginWithSSOToken", ZoomNodeAuthWrap::LoginWithSSOToken);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Logout", ZoomNodeAuthWrap::Logout);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAuthResult", ZoomNodeAuthWrap::GetAuthResult);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetLoginStatus", ZoomNodeAuthWrap::GetLoginStatus);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetLoginCB", ZoomNodeAuthWrap::SetLoginCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetLogoutCB", ZoomNodeAuthWrap::SetLogoutCB);

}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeAuthWrap >() {
	return &ZoomNodeAuthWrap::constructor;
}

class ZOOM_NODE_HIDE ZoomNodeWrap : public ZoomWrapObject<ZoomNodeWrap >
{
	friend class ZoomWrapObject<ZoomNodeWrap >;
private:
	ZoomNodeWrap() {}
	~ZoomNodeWrap() {}

public:
	//param:1.path 2.domain 3.langid 4.enable_log
	static void InitSDK(const v8::FunctionCallbackInfo<v8::Value>& args);
	//param:none
	static void CleanUPSDK(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetAuthObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMeetingObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSetObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static void GetCustomizedResourceObj(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "InitSDK", ZoomNodeWrap::InitSDK);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CleanUPSDK", ZoomNodeWrap::CleanUPSDK);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAuthObj", ZoomNodeWrap::GetAuthObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingObj", ZoomNodeWrap::GetMeetingObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSetObj", ZoomNodeWrap::GetSetObj);
	
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCustomizedResourceObj", ZoomNodeWrap::GetCustomizedResourceObj);

}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeWrap >() {
	return &ZoomNodeWrap::constructor;
}

class ZOOM_NODE_HIDE ZoomNodeMeetingWrap :
	public ZoomWrapObject<ZoomNodeMeetingWrap > 
{
	friend class ZoomWrapObject<ZoomNodeMeetingWrap >;
private:
	ZoomNodeMeetingWrap();
	~ZoomNodeMeetingWrap();
public:
	//param:1.meetingnumber(required) 2.hDirectShareAppWnd(required) 3.participantId(required)
	//param:4.isVideoOff(required) 5. isAudioOff(required) 6. isDirectShareDesktop(required) 7.callback(required)
	static void Start(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Start_WithoutLogin(const v8::FunctionCallbackInfo<v8::Value>& args);
	//param:1.meetingnumber(required) 2.vanityID(required) 3.username(required) 4.psw(required) 5.hDirectShareAppWnd(required) 6.participantId(required)
	//param:7.webinartoken(required) 8.isVideoOff(required) 9. isAudioOff(required) 10. isDirectShareDesktop(required) 11.callback(required)
	static void Join(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Join_WithoutLogin(const v8::FunctionCallbackInfo<v8::Value>& args);
	//param:1. bEnd(required)
	static void Leave(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Lock(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Unlock(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetMeetingStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void GetMeetingInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMeetingUICtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMeetingAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMeetingAudioCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMeetingVideoCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMeetingParticipantsCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMeetingShareCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMeetingH323Ctrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMeetingConfigCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void GetSharingConnQuality(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetVideoConnQuality(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetAudioConnQuality(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "Start", ZoomNodeMeetingWrap::Start);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Join", ZoomNodeMeetingWrap::Join);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Leave", ZoomNodeMeetingWrap::Leave);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Lock", ZoomNodeMeetingWrap::Lock);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Unlock", ZoomNodeMeetingWrap::Unlock);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Start_WithoutLogin", ZoomNodeMeetingWrap::Start_WithoutLogin);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Join_WithoutLogin", ZoomNodeMeetingWrap::Join_WithoutLogin);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingStatusCB", ZoomNodeMeetingWrap::SetMeetingStatusCB);

	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingInfo", ZoomNodeMeetingWrap::GetMeetingInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingUICtrl", ZoomNodeMeetingWrap::GetMeetingUICtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingAnnotation", ZoomNodeMeetingWrap::GetMeetingAnnotation);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingAudioCtrl", ZoomNodeMeetingWrap::GetMeetingAudioCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingVideoCtrl", ZoomNodeMeetingWrap::GetMeetingVideoCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingParticipantsCtrl", ZoomNodeMeetingWrap::GetMeetingParticipantsCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingShareCtrl", ZoomNodeMeetingWrap::GetMeetingShareCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingH323Ctrl", ZoomNodeMeetingWrap::GetMeetingH323Ctrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingConfigCtrl", ZoomNodeMeetingWrap::GetMeetingConfigCtrl);

	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSharingConnQuality", ZoomNodeMeetingWrap::GetSharingConnQuality);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetVideoConnQuality", ZoomNodeMeetingWrap::GetVideoConnQuality);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAudioConnQuality", ZoomNodeMeetingWrap::GetAudioConnQuality);

}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingWrap >() {
	return &ZoomNodeMeetingWrap::constructor;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZOOM_NODE_HIDE ZoomNodeMeetingInfoWrap :
	public ZoomWrapObject<ZoomNodeMeetingInfoWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingInfoWrap >;
private:
	ZoomNodeMeetingInfoWrap(){}
	~ZoomNodeMeetingInfoWrap(){}
public:
	static void GetMeetingTopic(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMeetingType(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMeetingNumber(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMeetingID(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetInviteEmailTeamplate(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetInviteEmailTitle(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetJoinMeetingUrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMeetingHostTag(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void CheckingIsInternalMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingInfoWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingInfoWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingTopic", ZoomNodeMeetingInfoWrap::GetMeetingTopic);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingType", ZoomNodeMeetingInfoWrap::GetMeetingType);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingNumber", ZoomNodeMeetingInfoWrap::GetMeetingNumber);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingID", ZoomNodeMeetingInfoWrap::GetMeetingID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetInviteEmailTeamplate", ZoomNodeMeetingInfoWrap::GetInviteEmailTeamplate);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetInviteEmailTitle", ZoomNodeMeetingInfoWrap::GetInviteEmailTitle);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetJoinMeetingUrl", ZoomNodeMeetingInfoWrap::GetJoinMeetingUrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingHostTag", ZoomNodeMeetingInfoWrap::GetMeetingHostTag);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CheckingIsInternalMeeting", ZoomNodeMeetingInfoWrap::CheckingIsInternalMeeting);


}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingInfoWrap >() {
	return &ZoomNodeMeetingInfoWrap::constructor;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZOOM_NODE_HIDE ZoomNodeMeetingUICtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingUICtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingUICtrlWrap >;
private:
	ZoomNodeMeetingUICtrlWrap();
	~ZoomNodeMeetingUICtrlWrap();
public:
	static void ShowChatDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void HideChatDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnterFullScreen(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void ExitFullScreen(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SwitchToVideoWall(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SwtichToAcitveSpeaker(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void MoveFloatVideoWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void ShowSharingToolbar(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SwitchFloatVideoToActiveSpkMod(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void ChangeFloatoActiveSpkVideoSize(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SwitchFloatVideoToGalleryMod(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void ShowParticipantsListWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void ShowBottomFloatToolbarWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void ShowJoinAudioDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void HideJoinAudioDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetWallViewPageInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void ShowPreOrNextPageVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void ShowSharingFrameWindows(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetCurrentSplitScreenModeInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SwitchSplitScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetInviteButtonClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingUICtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingUICtrlWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowChatDlg", ZoomNodeMeetingUICtrlWrap::ShowChatDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideChatDlg", ZoomNodeMeetingUICtrlWrap::HideChatDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnterFullScreen", ZoomNodeMeetingUICtrlWrap::EnterFullScreen);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ExitFullScreen", ZoomNodeMeetingUICtrlWrap::ExitFullScreen);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SwitchToVideoWall", ZoomNodeMeetingUICtrlWrap::SwitchToVideoWall);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SwtichToAcitveSpeaker", ZoomNodeMeetingUICtrlWrap::SwtichToAcitveSpeaker);
	NODE_SET_PROTOTYPE_METHOD(tpl, "MoveFloatVideoWnd", ZoomNodeMeetingUICtrlWrap::MoveFloatVideoWnd);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowSharingToolbar", ZoomNodeMeetingUICtrlWrap::ShowSharingToolbar);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SwitchFloatVideoToActiveSpkMod", ZoomNodeMeetingUICtrlWrap::SwitchFloatVideoToActiveSpkMod);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ChangeFloatoActiveSpkVideoSize", ZoomNodeMeetingUICtrlWrap::ChangeFloatoActiveSpkVideoSize);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SwitchFloatVideoToGalleryMod", ZoomNodeMeetingUICtrlWrap::SwitchFloatVideoToGalleryMod);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowParticipantsListWnd", ZoomNodeMeetingUICtrlWrap::ShowParticipantsListWnd);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowBottomFloatToolbarWnd", ZoomNodeMeetingUICtrlWrap::ShowBottomFloatToolbarWnd);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowJoinAudioDlg", ZoomNodeMeetingUICtrlWrap::ShowJoinAudioDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideJoinAudioDlg", ZoomNodeMeetingUICtrlWrap::HideJoinAudioDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetWallViewPageInfo", ZoomNodeMeetingUICtrlWrap::GetWallViewPageInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowPreOrNextPageVideo", ZoomNodeMeetingUICtrlWrap::ShowPreOrNextPageVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowSharingFrameWindows", ZoomNodeMeetingUICtrlWrap::ShowSharingFrameWindows);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCurrentSplitScreenModeInfo", ZoomNodeMeetingUICtrlWrap::GetCurrentSplitScreenModeInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SwitchSplitScreenMode", ZoomNodeMeetingUICtrlWrap::SwitchSplitScreenMode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetInviteButtonClickedCB", ZoomNodeMeetingUICtrlWrap::SetInviteButtonClickedCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingUICtrlWrap >() {
	return &ZoomNodeMeetingUICtrlWrap::constructor;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
class ZOOM_NODE_HIDE ZoomNodeSettingWrap :
	public ZoomWrapObject<ZoomNodeSettingWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingWrap >;
private:
	ZoomNodeSettingWrap();
	~ZoomNodeSettingWrap();
public:
	static void ShowSettingDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void HideSettingDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSettingVideoCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSettingAudioCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSettingGeneralCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSettingRecordingCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);


	static v8::Persistent<v8::Function> constructor;
};

template<>
static void InitClassAttribute<ZoomNodeSettingWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowSettingDlg", ZoomNodeSettingWrap::ShowSettingDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideSettingDlg", ZoomNodeSettingWrap::HideSettingDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingVideoCtrl", ZoomNodeSettingWrap::GetSettingVideoCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingAudioCtrl", ZoomNodeSettingWrap::GetSettingAudioCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingGeneralCtrl", ZoomNodeSettingWrap::GetSettingGeneralCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingRecordingCtrl", ZoomNodeSettingWrap::GetSettingRecordingCtrl);

}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingWrap >() {
	return &ZoomNodeSettingWrap::constructor;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
