#ifndef _ZOOM_NODE_ADDON_H_
#define _ZOOM_NODE_ADDON_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

class ZOOM_NODE_HIDE ZoomNodeAuthWrap :
	public ZoomWrapObject<ZoomNodeAuthWrap >
{
	//
	friend class ZoomWrapObject<ZoomNodeAuthWrap >;
private:
	ZoomNodeAuthWrap();
	~ZoomNodeAuthWrap();
public:
	/// \brief SDK Authentication.
	/// \param 1. sdk_key(string)  APP Key string.
	/// \param 2. sdk_secret(string)  APP Secret string.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void Auth(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void AuthWithJwtToken(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Account login with email.
	/// \param 1. user_name(string)  Username. It is usually working mailbox or other mailbox.
	/// \param 2. psw(string)  Account password.
	/// \param 3. remember_me(boolean) Optional. True indicates to save the information for next login.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void Login(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Account login with sso token.
	/// \param 1. ssotoken(string)  Account SSO token when logging.
	/// \param 2. remember_me(boolean) Optional. True indicates to save the information for next login.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void LoginWithSSOToken(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Account logout.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void Logout(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get authentication status.
	/// \return The return value is authentication status. To get extended error information, see \link ZNAuthResult \endlink enum.
	static void GetAuthResult(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get login status.
	/// \return The return value is login status. To get extended error information, see \link ZNLOGINSTATUS \endlink enum.
	static void GetLoginStatus(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set login callback function.
	/// \param 1. onLoginRet(function)  Callback of login result.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum. 
	static void SetLoginCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set logout callback function.
	/// \param 1. callback(function)  Callback of logout.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetLogoutCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set auth callback function.
	/// \param 1. callback(function)  Callback of auth.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetOnAuthReturnCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set zoom identity expired callback function.
	/// \param 1. callback(function)  Callback of zoom identity expired.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetOnZoomIdentityExpiredCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Direct Share Service Module.
	static void GetDirectShareHelperObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetOnZoomAuthIdentityExpiredCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};

template<>
static void InitClassAttribute<ZoomNodeAuthWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeAuthWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "Auth", ZoomNodeAuthWrap::Auth);
	NODE_SET_PROTOTYPE_METHOD(tpl, "AuthWithJwtToken", ZoomNodeAuthWrap::AuthWithJwtToken);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Login", ZoomNodeAuthWrap::Login);
	NODE_SET_PROTOTYPE_METHOD(tpl, "LoginWithSSOToken", ZoomNodeAuthWrap::LoginWithSSOToken);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Logout", ZoomNodeAuthWrap::Logout);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAuthResult", ZoomNodeAuthWrap::GetAuthResult);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetLoginStatus", ZoomNodeAuthWrap::GetLoginStatus);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetLoginCB", ZoomNodeAuthWrap::SetLoginCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetLogoutCB", ZoomNodeAuthWrap::SetLogoutCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetDirectShareHelperObj", ZoomNodeAuthWrap::GetDirectShareHelperObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnAuthReturnCB", ZoomNodeAuthWrap::SetOnAuthReturnCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnZoomIdentityExpiredCB", ZoomNodeAuthWrap::SetOnZoomIdentityExpiredCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnZoomAuthIdentityExpiredCB", ZoomNodeAuthWrap::SetOnZoomAuthIdentityExpiredCB);
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
	/// \brief Initialize ZOOM SDK.
	/// \param 1. path(string)  On win os is the sdk.dll path. On mac os is empty.
	/// \param 2. domain(string)  Web domain.
	/// \param 3. langid(number)  The ID of the SDK language. see \link ZNSDK_LANGUAGE_ID \endlink enum.
	/// \param 4. langName(string)  Resource name.
	/// \param 5. langInfo(string)  The value should be the full path of the resource file when the langType value is CustomizedLanguage_FilePath, including the file name. When the langType value is CustomizedLanguage_Content, the value saves the content of the resource.
	/// \param 6. strSupportUrl(string)  Support URL.
	/// \param 7. enable_log(boolean)  Enable log feature.
	/// \param 8. locale(number) Locale
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void InitSDK(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Clean up ZOOM SDK.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void CleanUPSDK(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Auth Service Module.
	static void GetAuthObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Meeting Service Module.
	static void GetMeetingObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Setting Service Module.
	static void GetSetObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Premeeting Service Module.
	static void GetPremeetingObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Customized Resource Service Module.
	static void GetCustomizedResourceObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Video RawData Service Module.
	static void GetVideoRawDataObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Audio RawData Service Module.
	static void GetAudioRawDataObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Share RawData Service Module.
	static void GetShareRawDataObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK RawData License Service Module.
	static void GetRawDataLicenseObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK SMS Helper Service Module.
	static void GetSDKSMSHelperObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the version of ZOOM SDK.
	/// \return The version of ZOOM SDK.
	static void GetZoomSDKVersion(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "InitSDK", ZoomNodeWrap::InitSDK);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CleanUPSDK", ZoomNodeWrap::CleanUPSDK);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAuthObj", ZoomNodeWrap::GetAuthObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingObj", ZoomNodeWrap::GetMeetingObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSetObj", ZoomNodeWrap::GetSetObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetPremeetingObj", ZoomNodeWrap::GetPremeetingObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCustomizedResourceObj", ZoomNodeWrap::GetCustomizedResourceObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetVideoRawDataObj", ZoomNodeWrap::GetVideoRawDataObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAudioRawDataObj", ZoomNodeWrap::GetAudioRawDataObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetShareRawDataObj", ZoomNodeWrap::GetShareRawDataObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRawDataLicenseObj", ZoomNodeWrap::GetRawDataLicenseObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetZoomSDKVersion", ZoomNodeWrap::GetZoomSDKVersion);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSDKSMSHelperObj", ZoomNodeWrap::GetSDKSMSHelperObj);
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
	/// \brief Start meeting.
	/// \param 1. meetingNumber(number)  Meeting number.
	/// \param 2. hDirectShareAppWnd(string)  The window handle of the direct sharing application.
	/// \param 3. participantId(number)  The ID of attendees. The SDK will set this value when the associated settings are turned on.
	/// \param 4. isVideoOff(boolean)  Turn off video or not. True indicates to turn off. In addition, this flag is affected by meeting attributes.
	/// \param 5. isAudioOff(boolean)  Turn off audio or not. True indicates to turn off. In addition, this flag is affected by meeting attributes.
	/// \param 6. isDirectShareDesktop(boolean)  Share the desktop directly or not. True indicates to Share.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void Start(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Start meeting without login.
	/// \param 1. userId(string)  [Required] User ID.  
	/// \param 2. userToken(string) [Required]  User token. 
	/// \param 3. userZAK(string)  [Required] ZOOM access token. 
	/// \param 4. username(string) [Required] Username. 
	/// \param 5. zoomuserType(number) [Required] Zoom user type. See \link ZNZoomUserType \endlink enum.
	/// \param 6. meetingNumber(number) [Optinal] Meeting number.
	/// \param 7. sdkVanityID(string) [Optinal] Meeting vanity ID
	/// \param 8. hDirectShareAppWnd(string) [Optinal] The window handle of the direct sharing application.
	/// \param 9. participantId(string) [Optinal] The ID of attendees. The SDK will set this value when the associated settings are turned on.
	/// \param 10. isDirectShareDesktop(boolean) [Optinal] Share the desktop directly or not. True indicates to share.
	/// \param 11. isVideoOff(boolean) [Optinal] Turn off the video or not. True indicates to turn off. In addition, this flag is affected by meeting attributes.
	/// \param 12. isAudioOff(boolean) [Optinal] Turn off the audio or not. True indicates to turn off. In addition, this flag is affected by meeting attributes.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void Start_WithoutLogin(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Join meeting.
	/// \param 1. meetingNumber(number)  Meeting number.
	/// \param 2. sdkVanityID(string)  Meeting vanity ID.
	/// \param 3. username(string)  Username when logged in the meeting.
	/// \param 4. psw(string) Meeting password.
	/// \param 5. hDirectShareAppWnd(string) The window handle of the direct sharing application.
	/// \param 6. participantId(string) The ID of attendees. The SDK will set this value when the associated settings are turned on.
	/// \param 7. webinarToken(string) Webinar token.
	/// \param 8. isVideoOff(boolean) Turn off the video or not. True indicates to turn off. In addition, this flag is affected by meeting attributes.
	/// \param 9. isAudioOff(boolean) Turn off the audio or not. True indicates to turn off. In addition, this flag is affected by meeting attributes.
	/// \param 10. isDirectShareDesktop(boolean) Share the desktop directly or not. True indicates to share.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void Join(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Join meeting without login.
	/// \param 1. meetingNumber(number)  [Required] Meeting number. Meeting number or VanityID is required.
	/// \param 2. sdkVanityID(string)  [Optinal] Meeting vanity ID. Meeting number or VanityID is required.
	/// \param 3. username(string) [Optinal] Username 
	/// \param 4. psw(string) [Optinal] Meeting password.
	/// \param 5. hDirectShareAppWnd(string) [Optinal] The window handle of the direct sharing application.
	/// \param 6. token4EnforceLogin(string) [Optinal] Use the token if the meeting requests to login.
	/// \param 7. participantId(string) [Optinal] The ID of attendees. The SDK will set this value when the associated settings are turned on.
	/// \param 8. webinarToken(string) [Optinal] Webinar token.
	/// \param 9. isDirectShareDesktop(boolean) [Optinal] Share the desktop directly or not. True indicates to share.
	/// \param 10. isVideoOff(boolean) [Optinal] Turn off the video or not. True indicates to turn off. In addition, this flag is affected by meeting attributes.
	/// \param 11. isAudioOff(boolean) [Optinal] Turn off the audio or not. True indicates to turn off. In addition, this flag is affected by meeting attributes.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void Join_WithoutLogin(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Leave/End Meeting 
	/// \param:1. bEnd(bool) If bEnd is true, end meeting; otherwise, leave meeting.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void Leave(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Lock the current meeting
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void Lock(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Unlock the current meeting.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void Unlock(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set meeting status changed callback function.
	/// \param 1. callback(function)  Callback of meeting status changed.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetMeetingStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Meeting Infomation Module.
	static void GetMeetingInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Meeting UI Controller Module.
	static void GetMeetingUICtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Meeting Annotation Controller Module.
	static void GetMeetingAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Meeting Audio Controller Module.
	static void GetMeetingAudioCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Meeting Video Controller Module.
	static void GetMeetingVideoCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Meeting Participants Controller Module.
	static void GetMeetingParticipantsCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Meeting Share Controller Module.
	static void GetMeetingShareCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Meeting H323 Controller Module.
	static void GetMeetingH323Ctrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Meeting Configuration Controller Module.
	static void GetMeetingConfigCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the quality of Internet connection when sharing.
	/// \return If the function succeeds, the return is one of those enumerated in \link ZNConnectionQuality \endlink enum.
	/// \remarks If you are not in the meeting, the ZNConn_Quality_Unknow will be returned.
	static void GetSharingConnQuality(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the Internet connection quality of video.
	/// \return If the function succeeds, the return is one of those enumerated in \link ZNConnectionQuality \endlink enum.
	/// \remarks If you are not in the meeting, the ZNConn_Quality_Unknow will be returned.
	static void GetVideoConnQuality(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the Internet connection quality of audio.
	/// \return If the function succeeds, the return is one of those enumerated in \link ZNConnectionQuality \endlink enum.
	/// \remarks If you are not in the meeting, the ZNConn_Quality_Unknow will be returned.
	static void GetAudioConnQuality(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void HandleZoomWebUriProtocolAction(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingWrap", v8::NewStringType::kInternalized).ToLocalChecked());
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

	NODE_SET_PROTOTYPE_METHOD(tpl, "HandleZoomWebUriProtocolAction", ZoomNodeMeetingWrap::HandleZoomWebUriProtocolAction);

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
	ZoomNodeMeetingInfoWrap() {}
	~ZoomNodeMeetingInfoWrap() {}
public:
	/// \brief Get the meeting topic.
	/// \return If the function succeeds, the return value is the current meeting topic. Otherwise returns an empty string of length ZERO(0)
	static void GetMeetingTopic(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the meeting type.
	/// \return If the function succeeds, the return value is the current meeting type. To get extended information, see \link ZNMeetingType \endlink enum.
	static void GetMeetingType(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the current meeting number.
	/// \return If the function succeeds, the return value is the current meeting number. Otherwise returns ZERO(0).
	static void GetMeetingNumber(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the current meeting ID.
	/// \return If the function succeeds, the return value is the current meeting ID. Otherwise returns an empty string of length ZERO(0).
	static void GetMeetingID(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the email invitation template for the current meeting.
	/// \return If the function succeeds, the return value is the email invitation template. Otherwise returns an empty string of length ZERO(0)
	static void GetInviteEmailTeamplate(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the meeting title in the email invitation template.
	/// \return If the function succeeds, the return value is the meeting title. Otherwise returns an empty string of length ZERO(0)
	static void GetInviteEmailTitle(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the URL of invitation to join the meeting.
	/// \return If the function succeeds, the return value is the URL of invitation. Otherwise returns an empty string of length ZERO(0)
	static void GetJoinMeetingUrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the host tag of the current meeting.
	/// \return If the function succeeds, the return value is the host tag. Otherwise returns an empty string of length ZERO(0)
	static void GetMeetingHostTag(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Determine whether the current meeting is internal or not.
	/// \return TRUE indicates that the current meeting is internal.
	static void CheckingIsInternalMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingInfoWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingInfoWrap", v8::NewStringType::kInternalized).ToLocalChecked());
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
	/// \brief Show the chat dialog during the meeting.
	/// \param 1. hParent(string) Parent window handle.
	/// \param 2. left(string) Left position of chat dialog.
	/// \param 3. top(string) Top position of chat dialog.
	/// \param 4. right(string) Right position of chat dialog.
	/// \param 5. bottom(string) Bottom position of chat dialog.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void ShowChatDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Hide the chat dialog during the meeting.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void HideChatDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Enter full screen display mode.
	/// \param 1. firstView(bool) True indicates to enable the full screen mode for the first view.
	/// \param 2. secondView(bool) True indicates to enable the full screen mode for the second view if it is in the dual view mode.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void EnterFullScreen(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Exit the full screen display mode.
	/// \param 1. firstView(bool) True indicates to exit the full screen mode for the first view.
	/// \param 2. secondView(bool) True indicates to exit the full screen mode for the second view if it is in the dual view mode.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void ExitFullScreen(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Switch to video wall mode. 
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SwitchToVideoWall(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Switch to the mode of showing the current speaker.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SwtichToAcitveSpeaker(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Move the floating video window.
	/// \param 1. left(string) Sets the left margin edge for the floating video window. Please use the coordinate of the screen.
	/// \param 2. top(string) Sets the top margin edge for the floating video window. Please use the coordinate of the screen.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void MoveFloatVideoWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Enable or disable to display the floating sharing toolbar.
	/// \param 1. bShow(bool) TRUE indicates to display the floating toolbar.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	/// \remarks This function works only in the share mode. 
	static void ShowSharingToolbar(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Switch to current speaker mode on the floating window. 
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SwitchFloatVideoToActiveSpkMod(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Adjust the display mode of floating window. 
	/// \param 1. type(number) Specify the type of the floating video. For more details, see \link ZNSDKFloatVideoType \endlink enum.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void ChangeFloatoActiveSpkVideoSize(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Switch to gallery view mode on the floating window. 
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SwitchFloatVideoToGalleryMod(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Display/hide the window which is used to display the list of the participants. 
	/// \param 1. bShow(bool) TRUE indicates to display the list of the participants. 
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void ShowParticipantsListWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Display/hide the toolbar at the bottom of the meeting window. 
	/// \param 1. bShow(bool) TRUE indicates to display the toolbar.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void ShowBottomFloatToolbarWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Display the dialog to choose the audio to join the meeting.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void ShowJoinAudioDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Hide the dialog to choose the audio to join the meeting.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void HideJoinAudioDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the information in video wall mode.
	/// \param 1. currentPage(string) 0 can be used to initialize.
	/// \param 2. totalPages(string) 0 can be used to initialize.
	/// \return If the function succeeds, the return value is a object which includes "err",
	///"currentPage" and "totalPages". To get extended error information, see \link ZNSDKError \endlink enum.
	static void GetWallViewPageInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Show the video users on previous page or next page in video wall mode.
	/// \param 1. bPageUp(bool) TRUE indicates to show the video users on previous page, FALSE next page.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	/// \remarks The function does not work if the window shows the first or last page. The return value is ZNSDKERR_SUCCESS in this case.
	static void ShowPreOrNextPageVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the visibility of the green frame when sharing the application.	/// \param 1. bShow(bool) TRUE indicates to display the frame. FALSE hide.	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void ShowSharingFrameWindows(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the information whether the current view supports split screen mode or not. If supports, check it if it is already in the split screen mode.
	/// \param 1. bZNSupportSplitScreen(bool) False can be used to initialize.
	/// \param 2. bZNInSplitScreenMode(bool) False can be used to initialize.
	/// \return If the function succeeds, the return value is a object which includes "err",
	///"bZNSupportSplitScreen" and "bZNInSplitScreenMode". To get extended error information, see \link ZNSDKError \endlink enum.
	static void GetCurrentSplitScreenModeInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Switch to the split screen mode or cancel.
	/// \param 1. bSplit TRUE indicates to switch to the split screen mode. FALSE cancel.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	///\remarks TRUE does not work if it is in the split screen mode. FALSE does not work if it is not the split screen mode.
	static void SwitchSplitScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set on invite button clicked callback function.
	/// \param 1. callback(function)  Callback event to click the INVITE button.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetInviteButtonClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/// \brief Active the principal window of meeting and place it on top.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///If the function fails, the return value is not ZNSDKERR_SUCCESS. To get extended error information, refer to ZNSDKError enum.
	static void BackToMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the window handle of the meeting user interface. This interface is only valid on Windows. 
	/// \return If the function succeeds, the return value is a object which includes "err" ZNSDKError, "hFirstView" the window handle(hex) of the meeting user interface displayed by the first view,
	///and "hSecondView" the window handle(hex) of the meeting user interface displayed by the second view. To get extended error information, see \link ZNSDKError \endlink enum.
	static void GetMeetingUIWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Change the display mode of the minimized meeting window for the first view.
	/// \param 1.mode(number) Specifies the minimized mode. For more details, see \link ZNSDKMinimizeUIMode \endlink enum.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SwitchMinimizeUIMode4FristScreenMeetingUIWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Determines the minimize state of the first view.
	/// \return For Windows: If the function succeeds, the return value is a object which includes "bIsMinimizMode"  TRUE indicates the minimize state, FALSE not;
	///"mode" the display mode. For more details, see \link ZNSDKMinimizeUIMode \endlink enum. 
	/// For Mac: If the function succeeds, the return value is a object which includes "bIsMinimizMode"  TRUE indicates the minimize state, FALSE not.
	static void IsMinimizeModeOfFristScreenMeetingUIWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief when someone else shares, and meeting window is not full screen. you can call the api to switch video & share display postion. 
	/// \param 1.bToDisplayShare(bool) TRUE means to display share, otherwise video.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SwapToShowShareViewOrVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Determine if the meeting is displaying the sharing screen now.
	/// \return If the function succeeds, the return value is a object which includes "err" ZNSDKError,
	///"bIsShare" TRUE means is showing sharing screen, FALSE means is showing video. To get extended error information, see \link ZNSDKError \endlink enum.
	static void IsDisplayingShareViewOrVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Determine if the user can swap to show sharing screen or video now.
	/// \return If the function succeeds, the return value is a object which includes "err" ZNSDKError,
	///"bCan" TRUE means Can, otherwise not. To get extended error information, see \link ZNSDKError \endlink enum.
	static void CanSwapToShowShareViewOrVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	static void SetonStartShareBtnClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetonEndMeetingBtnClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetonParticipantListBtnClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetonCustomLiveStreamMenuClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetonZoomInviteDialogFailedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetonCCBTNClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetonAudioBTNClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetonAudioMenuBTNClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingUICtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingUICtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
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

	NODE_SET_PROTOTYPE_METHOD(tpl, "BackToMeeting", ZoomNodeMeetingUICtrlWrap::BackToMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingUIWnd", ZoomNodeMeetingUICtrlWrap::GetMeetingUIWnd);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SwitchMinimizeUIMode4FristScreenMeetingUIWnd", ZoomNodeMeetingUICtrlWrap::SwitchMinimizeUIMode4FristScreenMeetingUIWnd);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsMinimizeModeOfFristScreenMeetingUIWnd", ZoomNodeMeetingUICtrlWrap::IsMinimizeModeOfFristScreenMeetingUIWnd);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SwapToShowShareViewOrVideo", ZoomNodeMeetingUICtrlWrap::SwapToShowShareViewOrVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsDisplayingShareViewOrVideo", ZoomNodeMeetingUICtrlWrap::IsDisplayingShareViewOrVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanSwapToShowShareViewOrVideo", ZoomNodeMeetingUICtrlWrap::CanSwapToShowShareViewOrVideo);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonStartShareBtnClickedCB", ZoomNodeMeetingUICtrlWrap::SetonStartShareBtnClickedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonEndMeetingBtnClickedCB", ZoomNodeMeetingUICtrlWrap::SetonEndMeetingBtnClickedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonParticipantListBtnClickedCB", ZoomNodeMeetingUICtrlWrap::SetonParticipantListBtnClickedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonCustomLiveStreamMenuClickedCB", ZoomNodeMeetingUICtrlWrap::SetonCustomLiveStreamMenuClickedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonZoomInviteDialogFailedCB", ZoomNodeMeetingUICtrlWrap::SetonZoomInviteDialogFailedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonCCBTNClickedCB", ZoomNodeMeetingUICtrlWrap::SetonCCBTNClickedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonAudioBTNClickedCB", ZoomNodeMeetingUICtrlWrap::SetonAudioBTNClickedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonAudioMenuBTNClickedCB", ZoomNodeMeetingUICtrlWrap::SetonAudioMenuBTNClickedCB);
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
	/// \brief Display Meeting Setting dialog.
	/// \param 1. hParent(string) Parent window handle.
	/// \param 2. left(string) The X-axis value of the top-left corner of the dialog uses the coordinate system of the monitor.
	/// \param 3. top(string) The Y-axis value of the top-left corner of the dialog uses the coordinate system of the monitor.
	/// \param 4. hSettingWnd(string) Window handle of the dialog setting.
	/// \param 5. bShow(bool) Enable to display or nor.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void ShowSettingDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Hide meeting setting dialog.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void HideSettingDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Video Setting Controller Module.
	static void GetSettingVideoCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Audio Setting Controller Module.
	static void GetSettingAudioCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK General Setting Controller Module.
	static void GetSettingGeneralCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Recording Setting Controller Module.
	static void GetSettingRecordingCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get Zoom SDK Setting UI Strategy Controller Module.
	static void GetSettingUIStrategyCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void GetSettingStatisticCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSettingAccessibilityCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};

template<>
static void InitClassAttribute<ZoomNodeSettingWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowSettingDlg", ZoomNodeSettingWrap::ShowSettingDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideSettingDlg", ZoomNodeSettingWrap::HideSettingDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingVideoCtrl", ZoomNodeSettingWrap::GetSettingVideoCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingAudioCtrl", ZoomNodeSettingWrap::GetSettingAudioCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingGeneralCtrl", ZoomNodeSettingWrap::GetSettingGeneralCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingRecordingCtrl", ZoomNodeSettingWrap::GetSettingRecordingCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingUIStrategyCtrl", ZoomNodeSettingWrap::GetSettingUIStrategyCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingStatisticCtrl", ZoomNodeSettingWrap::GetSettingStatisticCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingAccessibilityCtrl", ZoomNodeSettingWrap::GetSettingAccessibilityCtrl);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingWrap >() {
	return &ZoomNodeSettingWrap::constructor;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZOOM_NODE_HIDE ZoomNodePremeetingWrap :
	public ZoomWrapObject<ZoomNodePremeetingWrap >
{
	friend class ZoomWrapObject<ZoomNodePremeetingWrap >;
private:
	ZoomNodePremeetingWrap();
	~ZoomNodePremeetingWrap();
public:
	/// \brief Schedule Meeting with window params.
	/// \param 1. For Windows: hSelfWnd(string) Specifies the window handle of the window itself.
	///For Mac: height(string) Specifies the height of the window.
	/// \param 2. hParent(string) Specifies the window handle of the parent window. If the string is empty, the position coordinate is the monitor coordinate.
	///For Mac: width(string) Specifies the width of the window.
	/// \param 3. left(string) Specifies the X-axis coordinate of the top-left corner of the window
	/// \param 4. top(string) Specifies the Y-axis coordinate of the top-left of the window.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS. 
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void ScheduleMeetingWithWndParams(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Schedule Meeting.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void ScheduleMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Edit Meeting.
	/// \param 1. meetingUniqueID(number) Assign a meeting ID to schedule or edit related meeting.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void EditMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Edit Meeting with window params.
	/// \param 1. For Windows: hSelfWnd(string) Specifies the window handle of the window itself.
	///For Mac: height(string) Specifies the height of the window.
	/// \param 2. hParent(string) Specifies the window handle of the parent window. If the string is empty, the position coordinate is the monitor coordinate.
	///For Mac: width(string) Specifies the width of the window.
	/// \param 3. left(string) Specifies the X-axis coordinate of the top-left corner of the window
	/// \param 4. top(string) Specifies the Y-axis coordinate of the top-left of the window.
	/// \param 5.meetingUniqueID(number) Assign a meeting ID to schedule or edit related meeting.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void EditMeetingWithWndParams(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the list of current meetings.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void ListMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Delete the specified scheduled meeting.
	/// \param 1. meetingUniqueID(number) Assign a meeting ID to delete meeting.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	///It is forbidden to delete personal meeting or webinar or a recurring one.
	static void DeleteMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set on schedule or edit meeting callback function.
	/// \param 1. callback(function)  Schedule or edit meeting callback event.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetOnScheduleOrEditMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set on list meeting callback function.
	/// \param 1. callback(function) List meeting callback event.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetOnListMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set on delete meeting callback function.
	/// \param 1. callback(function) Delete meeting callback event.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetOnDeleteMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};

template<>
static void InitClassAttribute<ZoomNodePremeetingWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodePremeetingWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype

	NODE_SET_PROTOTYPE_METHOD(tpl, "ScheduleMeetingWithWndParams", ZoomNodePremeetingWrap::ScheduleMeetingWithWndParams);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ScheduleMeeting", ZoomNodePremeetingWrap::ScheduleMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EditMeeting", ZoomNodePremeetingWrap::EditMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EditMeetingWithWndParams", ZoomNodePremeetingWrap::EditMeetingWithWndParams);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ListMeeting", ZoomNodePremeetingWrap::ListMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DeleteMeeting", ZoomNodePremeetingWrap::DeleteMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnScheduleOrEditMeetingCB", ZoomNodePremeetingWrap::SetOnScheduleOrEditMeetingCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnListMeetingCB", ZoomNodePremeetingWrap::SetOnListMeetingCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnDeleteMeetingCB", ZoomNodePremeetingWrap::SetOnDeleteMeetingCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodePremeetingWrap >() {
	return &ZoomNodePremeetingWrap::constructor;
}



#endif
