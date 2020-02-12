
#include "zoom_node_addon.h"
#include "zoom_v8_to_c.h"
#include "zoom_node_meeting_annotation.h"
#include "zoom_node_meeting_audio_ctrl.h"
#include "zoom_node_meeting_video_ctrl.h"
#include "zoom_node_meeting_participants_ctrl.h"
#include "zoom_node_meeting_share_ctrl.h"
#include "zoom_node_meeting_h323_ctrl.h"
#include "zoom_node_meeting_config_ctrl.h"
#include "zoom_node_setting_video_ctrl.h"
#include "zoom_node_setting_audio_ctrl.h"
#include "zoom_node_setting_general_ctrl.h"
#include "zoom_node_setting_ui_strategy_ctrl.h"
#include "zoom_node_setting_recording_ctrl.h"
#include "zoom_node_customized_resource.h"
#include "zoom_node_direct_share_helper.h"
#include "zoom_node_video_raw_data.h"
#include "zoom_node_audio_raw_data.h"
#include "zoom_node_share_raw_data.h"
#include "zoom_raw_data_wrap.h"
#include "run_task_to_main_thread.h"
#include "zoom_node_raw_data_license.h"
#include "zoom_node_sdk_sms_helper.h"
#include "zoom_node_setting_statistic_ctrl.h"
#include "zoom_node_setting_accessibility_ctrl.h"

ZNativeSDKWrap _g_native_wrap;
void CreateObject(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeWrap::NewInstance(args);
}

void InitAll(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
	ZoomNodeWrap::Init(exports->GetIsolate());
	ZoomNodeAuthWrap::Init(exports->GetIsolate());
	ZoomNodeMeetingWrap::Init(exports->GetIsolate());
	ZoomNodeSettingWrap::Init(exports->GetIsolate());
	ZoomNodePremeetingWrap::Init(exports->GetIsolate());
	ZoomNodeCustomizedResourceWrap::Init(exports->GetIsolate());
	ZoomNodeMeetingInfoWrap::Init(exports->GetIsolate());
	ZoomNodeMeetingUICtrlWrap::Init(exports->GetIsolate());
	ZoomNodeMeetingAnnotationWrap::Init(exports->GetIsolate());
	ZoomNodeMeetingAudioCtrlWrap::Init(exports->GetIsolate());
	ZoomNodeMeetingVideoCtrlWrap::Init(exports->GetIsolate());
	ZoomNodeMeetingParticipantsCtrlWrap::Init(exports->GetIsolate());
	ZoomNodeMeetingShareCtrlWrap::Init(exports->GetIsolate());
	ZoomNodeMeetingH323CtrlWrap::Init(exports->GetIsolate());
	ZoomNodeMeetingConfigCtrlWrap::Init(exports->GetIsolate());
	ZoomNodeSettingVideoCtrlWrap::Init(exports->GetIsolate());
	ZoomNodeSettingAudioCtrlWrap::Init(exports->GetIsolate());
	ZoomNodeSettingGeneralCtrlWrap::Init(exports->GetIsolate());
	ZoomNodeSettingUIStrategyCtrlWrap::Init(exports->GetIsolate());
	ZoomNodeSettingRecordingCtrlWrap::Init(exports->GetIsolate());
	ZoomNodeDirectShareHelperWrap::Init(exports->GetIsolate());
	ZoomNodeVideoRawDataWrap::Init(exports->GetIsolate());
	ZoomNodeAudioRawDataWrap::Init(exports->GetIsolate());
	ZoomNodeShareRawDataWrap::Init(exports->GetIsolate());
	ZoomNodeRawDataLicenseWrap::Init(exports->GetIsolate());
	ZoomNodeSDKSMSHelperWrap::Init(exports->GetIsolate());
	ZoomNodeSettingStatisticCtrlWrap::Init(exports->GetIsolate());
	ZoomNodeSettingAccessibilityCtrlWrap::Init(exports->GetIsolate());
	NODE_SET_METHOD(module, "exports", CreateObject);
}

NODE_MODULE(zoomsdk, InitAll)

v8::Persistent<v8::Function> ZoomNodeWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeAuthWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeMeetingWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeSettingWrap::constructor;
v8::Persistent<v8::Function> ZoomNodePremeetingWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeCustomizedResourceWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeMeetingInfoWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeMeetingUICtrlWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeMeetingAnnotationWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeMeetingAudioCtrlWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeMeetingVideoCtrlWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeMeetingParticipantsCtrlWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeMeetingShareCtrlWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeMeetingH323CtrlWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeMeetingConfigCtrlWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeSettingVideoCtrlWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeSettingAudioCtrlWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeSettingGeneralCtrlWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeSettingUIStrategyCtrlWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeSettingRecordingCtrlWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeDirectShareHelperWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeVideoRawDataWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeAudioRawDataWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeShareRawDataWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeRawDataLicenseWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeSDKSMSHelperWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeSettingStatisticCtrlWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeSettingAccessibilityCtrlWrap::constructor;
///////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void ZoomNodeWrap::InitSDK(const v8::FunctionCallbackInfo<v8::Value>& args){
	
#if (defined _WIN32)
	Init_MainThread_RunLoop(GetCurrentThreadId());
#else
	Init_MainThread_RunLoop(0);
#endif
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 6) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "ZoomNodeWrap::InitSDK-Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsNumber() || 
		!args[3]->IsString() ||
		!args[4]->IsString() ||
		!args[5]->IsString() 
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	ZNInitParam param;
	zoom_v8toc(args[0].As<v8::String>(), param.path);
	zoom_v8toc(args[1].As<v8::String>(), param.domain);
	int langid = (int)args[2].As<v8::Integer >()->Value();
	param.langid = (ZNSDK_LANGUAGE_ID)langid;
	zoom_v8toc(args[3].As<v8::String>(), param.obConfigOpts.customizedLang.langName);
	zoom_v8toc(args[4].As<v8::String>(), param.obConfigOpts.customizedLang.langInfo);
	zoom_v8toc(args[5].As<v8::String>(), param.strSupportUrl);
	
	if (args.Length() > 6)
	{
		zoom_v8toc(args[6].As<v8::Boolean>(), param.enable_log);
		if (args.Length() > 7)
		{
			int zn_locale = (int)args[7].As<v8::Integer >()->Value();
			param.locale = (ZNSDK_APP_Locale)zn_locale;
		}
	}
	ZNSDKError err = _g_native_wrap.InitSDK(param);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeWrap::CleanUPSDK(const v8::FunctionCallbackInfo<v8::Value>& args) {
#if (defined _WIN32)
	Uninit_MainThread_RunLoop();
#else
	Uninit_MainThread_RunLoop();
#endif
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.CleanUPSDK();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeWrap::GetZoomSDKVersion(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING zn_zoomSDKVersion = _g_native_wrap.GetVersion();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(zn_zoomSDKVersion).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomNodeWrap::GetAuthObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeAuthWrap::NewInstance(args);
}
void ZoomNodeWrap::GetMeetingObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeMeetingWrap::NewInstance(args);
}
void ZoomNodeWrap::GetSetObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeSettingWrap::NewInstance(args);
}
void ZoomNodeWrap::GetPremeetingObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodePremeetingWrap::NewInstance(args);
}
void ZoomNodeWrap::GetCustomizedResourceObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeCustomizedResourceWrap::NewInstance(args);
}
void ZoomNodeWrap::GetVideoRawDataObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeVideoRawDataWrap::NewInstance(args);
}
void ZoomNodeWrap::GetAudioRawDataObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeAudioRawDataWrap::NewInstance(args);
}
void ZoomNodeWrap::GetShareRawDataObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeShareRawDataWrap::NewInstance(args);
}
void ZoomNodeWrap::GetRawDataLicenseObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeRawDataLicenseWrap::NewInstance(args);
}
void ZoomNodeWrap::GetSDKSMSHelperObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeSDKSMSHelperWrap::NewInstance(args);
}
////////////////////////////////////////////////////////////////////////////

ZoomNodeAuthWrap::ZoomNodeAuthWrap()
{
	_g_native_wrap.GetAuthServiceWrap().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_authServiceWrapSink);
}

ZoomNodeAuthWrap::~ZoomNodeAuthWrap()
{
	_g_native_wrap.GetAuthServiceWrap().SetSink(NULL);
}

void ZoomNodeAuthWrap::Auth(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZNAuthParam param;
	zoom_v8toc(args[0].As<v8::String>(), param.sdk_key);
	zoom_v8toc(args[1].As<v8::String>(), param.sdk_secret);

	ZNSDKError err = _g_native_wrap.GetAuthServiceWrap().AuthSDK(param);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::AuthWithJwtToken(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZNAuthContext zn_context;
	zoom_v8toc(args[0].As<v8::String>(), zn_context.sdk_jwt_token);

	ZNSDKError err = _g_native_wrap.GetAuthServiceWrap().AuthSDK(zn_context);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::Login(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) 
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	ZNLoginParam param;
	zoom_v8toc(args[0].As<v8::String>(), param.user_name);
	zoom_v8toc(args[1].As<v8::String>(), param.psw);

	if (args.Length() == 3)
	{
		zoom_v8toc(args[2].As<v8::Boolean>(), param.remember_me);
	}

	ZNSDKError err = _g_native_wrap.GetAuthServiceWrap().Login(param);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::LoginWithSSOToken(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	ZNLoginParam param;
	zoom_v8toc(args[0].As<v8::String>(), param.ssotoken);
	zoom_v8toc(args[1].As<v8::Boolean>(), param.remember_me);
	
	ZNSDKError err = _g_native_wrap.GetAuthServiceWrap().LoginWithSSOToken(param);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::Logout(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetAuthServiceWrap().Logout();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::GetAuthResult(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNAuthResult authResult = _g_native_wrap.GetAuthServiceWrap().GetAuthResult();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)authResult);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::GetLoginStatus(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNLOGINSTATUS loginStatus = _g_native_wrap.GetAuthServiceWrap().GetLoginStatus();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)loginStatus);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::SetLoginCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onLoginRet.Empty();		return;	}
	if (!args[0]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onLoginRet = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::SetLogoutCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onLogout.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onLogout = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::SetOnAuthReturnCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onAuthenticationReturn.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onAuthenticationReturn = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::SetOnZoomIdentityExpiredCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onZoomIdentityExpired.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onZoomIdentityExpired = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::SetOnZoomAuthIdentityExpiredCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onZoomAuthIdentityExpired.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onZoomAuthIdentityExpired = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::GetDirectShareHelperObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeDirectShareHelperWrap::NewInstance(args);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

ZoomNodeMeetingWrap::ZoomNodeMeetingWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_meetingServiceWrapSink);
}

ZoomNodeMeetingWrap::~ZoomNodeMeetingWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().SetSink(NULL);
}
void ZoomNodeMeetingWrap::Start(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 6)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsBoolean() ||
		!args[4]->IsBoolean() ||
		!args[5]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	ZNStartParam param;
	param.userType = ZNSDK_UT_NORMALUSER;
	param.meetingNumber = (unsigned long long)args[0]->NumberValue();
	zoom_v8toc(args[1].As<v8::String>(), param.hDirectShareAppWnd);
	zoom_v8toc(args[2].As<v8::String>(), param.participantId);
	zoom_v8toc(args[3].As<v8::Boolean>(), param.isVideoOff);
	zoom_v8toc(args[4].As<v8::Boolean>(), param.isAudioOff);
	zoom_v8toc(args[5].As<v8::Boolean>(), param.isDirectShareDesktop);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().Start(param);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWrap::Start_WithoutLogin(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 12)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsString() ||
		!args[4]->IsNumber() ||
		!args[5]->IsNumber() ||
		!args[6]->IsString() ||
		!args[7]->IsString() ||
		!args[8]->IsString() ||
		!args[9]->IsBoolean() ||
		!args[10]->IsBoolean() ||
		!args[11]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	ZNStartParam param;
	param.userType = ZNSDK_UT_WITHOUT_LOGIN;
	zoom_v8toc(args[0].As<v8::String>(), param.userId);
	zoom_v8toc(args[1].As<v8::String>(), param.userToken);
	zoom_v8toc(args[2].As<v8::String>(), param.userZAK);
	zoom_v8toc(args[3].As<v8::String>(), param.username);
	unsigned int nodeuserType = (unsigned int)args[4].As<v8::Integer >()->Value();
	switch (nodeuserType)
	{
	case 0:
		param.zoomUserType = ZNZoomUserType_APIUSER;
		break;
	case 1:
		param.zoomUserType = ZNZoomUserType_EMAIL_LOGIN;
		break;
	case 2:
		param.zoomUserType = ZNZoomUserType_FACEBOOK;
		break;
	case 3:
		param.zoomUserType = ZNZoomUserType_GoogleOAuth;
		break;
	case 4:
		param.zoomUserType = ZNZoomUserType_SSO;
		break;
	case 5:
		param.zoomUserType = ZNZoomUserType_Unknown;
		break;
	default:
		break;
	}
	param.meetingNumber = (unsigned long long)args[5]->NumberValue();
	zoom_v8toc(args[6].As<v8::String>(), param.sdkVanityID);
	zoom_v8toc(args[7].As<v8::String>(), param.hDirectShareAppWnd);
	zoom_v8toc(args[8].As<v8::String>(), param.participantId);
	zoom_v8toc(args[9].As<v8::Boolean>(), param.isDirectShareDesktop);
	zoom_v8toc(args[10].As<v8::Boolean>(), param.isVideoOff);
	zoom_v8toc(args[11].As<v8::Boolean>(), param.isAudioOff);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().Start_WithoutLogin(param);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWrap::Join(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 10)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsString() ||
		!args[4]->IsString() ||
		!args[5]->IsString() ||
		!args[6]->IsString() ||
		!args[7]->IsBoolean() ||
		!args[8]->IsBoolean() ||
		!args[9]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	ZNJoinParam param;
	param.userType = ZNSDK_UT_NORMALUSER;
	param.meetingNumber = (unsigned long long)args[0]->NumberValue();
	zoom_v8toc(args[1].As<v8::String>(), param.vanityID);
	zoom_v8toc(args[2].As<v8::String>(), param.username);
	zoom_v8toc(args[3].As<v8::String>(), param.psw);
	zoom_v8toc(args[4].As<v8::String>(), param.hDirectShareAppWnd);
	zoom_v8toc(args[5].As<v8::String>(), param.participantId);
	zoom_v8toc(args[6].As<v8::String>(), param.webinarToken);
	zoom_v8toc(args[7].As<v8::Boolean>(), param.isVideoOff);
	zoom_v8toc(args[8].As<v8::Boolean>(), param.isAudioOff);
	zoom_v8toc(args[9].As<v8::Boolean>(), param.isDirectShareDesktop);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().Join(param);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingWrap::Join_WithoutLogin(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 11)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsString() ||
		!args[4]->IsString() ||
		!args[5]->IsString() ||
		!args[6]->IsString() ||
		!args[7]->IsString() ||
		!args[8]->IsBoolean() ||
		!args[9]->IsBoolean() ||
		!args[10]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	ZNJoinParam param;
	param.userType = ZNSDK_UT_APIUSER;
	param.meetingNumber = (unsigned long long)args[0]->NumberValue();
	zoom_v8toc(args[1].As<v8::String>(), param.vanityID);
	zoom_v8toc(args[2].As<v8::String>(), param.username);
	zoom_v8toc(args[3].As<v8::String>(), param.psw);
	zoom_v8toc(args[4].As<v8::String>(), param.hDirectShareAppWnd);
	zoom_v8toc(args[5].As<v8::String>(), param.token4EnforceLogin);
	zoom_v8toc(args[6].As<v8::String>(), param.participantId);
	zoom_v8toc(args[7].As<v8::String>(), param.webinarToken);
	zoom_v8toc(args[8].As<v8::Boolean>(), param.isDirectShareDesktop);
	zoom_v8toc(args[9].As<v8::Boolean>(), param.isVideoOff);
	zoom_v8toc(args[10].As<v8::Boolean>(), param.isAudioOff);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().Join_WithoutLogin(param);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWrap::Leave(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool bEnd = false;
	zoom_v8toc(args[0].As<v8::Boolean>(), bEnd);
	
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().Leave(bEnd ? ZNEND_MEETING : ZNLEAVE_MEETING);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWrap::Lock(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().Lock();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWrap::Unlock(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().Unlock();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWrap::HandleZoomWebUriProtocolAction(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (!args[0]->IsString())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	ZoomSTRING zn_protocal_action;
	zoom_v8toc(args[0].As<v8::String>(), zn_protocal_action);
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().HandleZoomWebUriProtocolAction(zn_protocal_action);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWrap::SetMeetingStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onMeetingStatusChanged.Empty();		return;	}
	if (!args[0]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onMeetingStatusChanged = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWrap::GetMeetingInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeMeetingInfoWrap::NewInstance(args);
}
void ZoomNodeMeetingWrap::GetMeetingUICtrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeMeetingUICtrlWrap::NewInstance(args);
}
void ZoomNodeMeetingWrap::GetMeetingAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeMeetingAnnotationWrap::NewInstance(args);
}
void ZoomNodeMeetingWrap::GetMeetingAudioCtrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeMeetingAudioCtrlWrap::NewInstance(args);
}
void ZoomNodeMeetingWrap::GetMeetingVideoCtrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeMeetingVideoCtrlWrap::NewInstance(args);
}
void ZoomNodeMeetingWrap::GetMeetingParticipantsCtrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeMeetingParticipantsCtrlWrap::NewInstance(args);
}
void ZoomNodeMeetingWrap::GetMeetingShareCtrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeMeetingShareCtrlWrap::NewInstance(args);
}
void ZoomNodeMeetingWrap::GetMeetingH323Ctrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeMeetingH323CtrlWrap::NewInstance(args);
}
void ZoomNodeMeetingWrap::GetMeetingConfigCtrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeMeetingConfigCtrlWrap::NewInstance(args);
}


void ZoomNodeMeetingWrap::GetSharingConnQuality(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNConnectionQuality sharing_conn_quality = _g_native_wrap.GetMeetingServiceWrap().GetSharingConnQuality();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)sharing_conn_quality);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWrap::GetVideoConnQuality(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNConnectionQuality video_conn_quality = _g_native_wrap.GetMeetingServiceWrap().GetVideoConnQuality();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)video_conn_quality);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWrap::GetAudioConnQuality(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNConnectionQuality audio_conn_quality = _g_native_wrap.GetMeetingServiceWrap().GetAudioConnQuality();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)audio_conn_quality);
	args.GetReturnValue().Set(bret);
}
///////////////////////////////////////////////////////////////////////////////////////////////////

void ZoomNodeMeetingInfoWrap::GetMeetingTopic(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING meeting_topic = _g_native_wrap.GetMeetingServiceWrap().GetMeetingInfo().GetMeetingTopic();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(meeting_topic).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingInfoWrap::GetMeetingType(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNMeetingType type = _g_native_wrap.GetMeetingServiceWrap().GetMeetingInfo().GetMeetingType();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)type);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingInfoWrap::GetMeetingNumber(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	unsigned long long zn_meetingNumber = _g_native_wrap.GetMeetingServiceWrap().GetMeetingInfo().GetMeetingNumber();
	v8::Local<v8::Number> bret = v8::Number::New(isolate, (unsigned long long)zn_meetingNumber);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingInfoWrap::GetMeetingID(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING meeting_id = _g_native_wrap.GetMeetingServiceWrap().GetMeetingInfo().GetMeetingID();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(meeting_id).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingInfoWrap::GetInviteEmailTeamplate(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING invite_email_teamplate = _g_native_wrap.GetMeetingServiceWrap().GetMeetingInfo().GetInviteEmailTeamplate();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(invite_email_teamplate).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingInfoWrap::GetInviteEmailTitle(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING invite_email_title = _g_native_wrap.GetMeetingServiceWrap().GetMeetingInfo().GetInviteEmailTitle();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(invite_email_title).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingInfoWrap::GetJoinMeetingUrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING join_meeting_url = _g_native_wrap.GetMeetingServiceWrap().GetMeetingInfo().GetJoinMeetingUrl();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(join_meeting_url).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingInfoWrap::GetMeetingHostTag(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING meeting_host_tag = _g_native_wrap.GetMeetingServiceWrap().GetMeetingInfo().GetMeetingHostTag();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(meeting_host_tag).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingInfoWrap::CheckingIsInternalMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	bool bDisable = _g_native_wrap.GetMeetingServiceWrap().GetMeetingInfo().CheckingIsInternalMeeting();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, bDisable);
	args.GetReturnValue().Set(bret);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ZoomNodeMeetingUICtrlWrap::ZoomNodeMeetingUICtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_meetingUICtrlWrapSink);
}

ZoomNodeMeetingUICtrlWrap::~ZoomNodeMeetingUICtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().SetSink(NULL);
}
void ZoomNodeMeetingUICtrlWrap::ShowChatDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 5) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsString() ||
		!args[4]->IsString() 
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZNShowChatDlgParam param;
	zoom_v8toc(args[0].As<v8::String>(), param.hParent);
	zoom_v8toc(args[1].As<v8::String>(), param.rect_left);
	zoom_v8toc(args[2].As<v8::String>(), param.rect_top);
	zoom_v8toc(args[3].As<v8::String>(), param.rect_right);
	zoom_v8toc(args[4].As<v8::String>(), param.rect_bottom);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ShowChatDlg(param);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::HideChatDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().HideChatDlg();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::EnterFullScreen(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean() ||
		!args[1]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool bFirstView;
	bool bSecView;
	zoom_v8toc(args[0].As<v8::Boolean>(), bFirstView);
	zoom_v8toc(args[1].As<v8::Boolean>(), bSecView);
	
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().EnterFullScreen(bFirstView, bSecView);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::ExitFullScreen(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean() ||
		!args[1]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool bFirstView;
	bool bSecView;
	zoom_v8toc(args[0].As<v8::Boolean>(), bFirstView);
	zoom_v8toc(args[1].As<v8::Boolean>(), bSecView);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ExitFullScreen(bFirstView, bSecView);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SwitchToVideoWall(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().SwitchToVideoWall();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SwtichToAcitveSpeaker(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().SwtichToAcitveSpeaker();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::MoveFloatVideoWnd(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZoomSTRING left;
	ZoomSTRING top;
	zoom_v8toc(args[0].As<v8::String>(), left);
	zoom_v8toc(args[1].As<v8::String>(), top);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().MoveFloatVideoWnd(left, top);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::ShowSharingToolbar(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool b_show;
	zoom_v8toc(args[0].As<v8::Boolean>(), b_show);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ShowSharingToolbar(b_show);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SwitchFloatVideoToActiveSpkMod(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().SwitchFloatVideoToActiveSpkMod();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::ChangeFloatoActiveSpkVideoSize(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	unsigned int type = (unsigned int)args[0].As<v8::Integer >()->Value();
	ZNSDKFloatVideoType zn_sdk_float_video_type;
	switch (type)
	{
	case 0:
		zn_sdk_float_video_type = ZN_FLOATVIDEO_List;
		break;
	case 1:
		zn_sdk_float_video_type = ZN_FLOATVIDEO_Small;
		break;
	case 2:
		zn_sdk_float_video_type = ZN_FLOATVIDEO_Large;
		break;
	case 3:
		zn_sdk_float_video_type = ZN_FLOATVIDEO_Minimize;
		break;
	default:
		break;
	}

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ChangeFloatoActiveSpkVideoSize(zn_sdk_float_video_type);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SwitchFloatVideoToGalleryMod(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().SwitchFloatVideoToGalleryMod();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::ShowParticipantsListWnd(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool b_show;
	zoom_v8toc(args[0].As<v8::Boolean>(), b_show);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ShowParticipantsListWnd(b_show);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::ShowBottomFloatToolbarWnd(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool b_show;
	zoom_v8toc(args[0].As<v8::Boolean>(), b_show);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ShowBottomFloatToolbarWnd(b_show);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::ShowJoinAudioDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ShowJoinAudioDlg();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::HideJoinAudioDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().HideJoinAudioDlg();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::GetWallViewPageInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZNVideoWallPageInfoParam param;
	zoom_v8toc(args[0].As<v8::String>(), param.currentPage);
	zoom_v8toc(args[1].As<v8::String>(), param.totalPages);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().GetWallViewPageInfo(param);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "currentPage", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(param.currentPage).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
	node->Set(context, v8::String::NewFromUtf8(isolate, "totalPages", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(param.totalPages).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());

	
	args.GetReturnValue().Set(node);
}
void ZoomNodeMeetingUICtrlWrap::ShowPreOrNextPageVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool b_pageUp;
	zoom_v8toc(args[0].As<v8::Boolean>(), b_pageUp);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ShowPreOrNextPageVideo(b_pageUp);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::ShowSharingFrameWindows(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool b_show;
	zoom_v8toc(args[0].As<v8::Boolean>(), b_show);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ShowSharingFrameWindows(b_show);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::GetCurrentSplitScreenModeInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean() ||
		!args[1]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZNSplitScreenInfo info;
	zoom_v8toc(args[0].As<v8::Boolean>(), info.bZNSupportSplitScreen);
	zoom_v8toc(args[1].As<v8::Boolean>(), info.bZNInSplitScreenMode);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().GetCurrentSplitScreenModeInfo(info);

	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "bZNSupportSplitScreen", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, info.bZNSupportSplitScreen));
	node->Set(context, v8::String::NewFromUtf8(isolate, "bZNInSplitScreenMode", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, info.bZNInSplitScreenMode));

	args.GetReturnValue().Set(node);
}
void ZoomNodeMeetingUICtrlWrap::SwitchSplitScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool b_Split;
	zoom_v8toc(args[0].As<v8::Boolean>(), b_Split);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().SwitchSplitScreenMode(b_Split);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingUICtrlWrap::BackToMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().BackToMeeting();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::GetMeetingUIWnd(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZoomSTRING hFirstView;
	ZoomSTRING hSecondView;

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().GetMeetingUIWnd(hFirstView, hSecondView);

	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
#if (defined _WIN32)
	node->Set(context, v8::String::NewFromUtf8(isolate, "hFirstView", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(hFirstView).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
	node->Set(context, v8::String::NewFromUtf8(isolate, "hSecondView", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(hSecondView).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
#endif
	args.GetReturnValue().Set(node);
}
void ZoomNodeMeetingUICtrlWrap::SwitchMinimizeUIMode4FristScreenMeetingUIWnd(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZNSDKMinimizeUIMode mode;
	mode = (ZNSDKMinimizeUIMode)args[0].As<v8::Integer>()->Value();

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().SwitchMinimizeUIMode4FristScreenMeetingUIWnd(mode);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::IsMinimizeModeOfFristScreenMeetingUIWnd(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNSDKMinimizeUIMode mode = ZN_MinimizeUIMode_NONE;
	bool zn_bIsMinimizMode = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().IsMinimizeModeOfFristScreenMeetingUIWnd(mode);

	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "bIsMinimizMode", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_bIsMinimizMode));
#if (defined _WIN32)
	node->Set(context, v8::String::NewFromUtf8(isolate, "mode", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)mode));
#endif

	args.GetReturnValue().Set(node);
}
void ZoomNodeMeetingUICtrlWrap::SwapToShowShareViewOrVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bToDisplayShare;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bToDisplayShare);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().SwapToShowShareViewOrVideo(zn_bToDisplayShare);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::IsDisplayingShareViewOrVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	bool zn_bIsShare = false;
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().IsDisplayingShareViewOrVideo(zn_bIsShare);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "bIsShare", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_bIsShare));

	args.GetReturnValue().Set(node);
}
void ZoomNodeMeetingUICtrlWrap::CanSwapToShowShareViewOrVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	bool zn_bCan = false;
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().CanSwapToShowShareViewOrVideo(zn_bCan);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "bCan", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_bCan));

	args.GetReturnValue().Set(node);
}

void ZoomNodeMeetingUICtrlWrap::SetInviteButtonClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onInviteBtnClicked.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onInviteBtnClicked = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetonStartShareBtnClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onStartShareBtnClicked.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onStartShareBtnClicked = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetonEndMeetingBtnClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onEndMeetingBtnClicked.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onEndMeetingBtnClicked = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetonParticipantListBtnClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onParticipantListBtnClicked.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onParticipantListBtnClicked = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetonCustomLiveStreamMenuClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onCustomLiveStreamMenuClicked.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onCustomLiveStreamMenuClicked = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetonZoomInviteDialogFailedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onZoomInviteDialogFailed.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onZoomInviteDialogFailed = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetonCCBTNClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onCCBTNClicked.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onCCBTNClicked = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetonAudioBTNClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onAudioBtnClicked.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onAudioBtnClicked = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetonAudioMenuBTNClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onAudioMenuBtnClicked.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onAudioMenuBtnClicked = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
//////////////////////////////////////////////////////////////////////////////////////////
ZoomNodeSettingWrap::ZoomNodeSettingWrap()
{
	
}
ZoomNodeSettingWrap::~ZoomNodeSettingWrap()
{
	
}
void ZoomNodeSettingWrap::GetSettingVideoCtrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeSettingVideoCtrlWrap::NewInstance(args);
}
void ZoomNodeSettingWrap::GetSettingAudioCtrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeSettingAudioCtrlWrap::NewInstance(args);
}
void ZoomNodeSettingWrap::GetSettingGeneralCtrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeSettingGeneralCtrlWrap::NewInstance(args);
}
void ZoomNodeSettingWrap::GetSettingRecordingCtrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeSettingRecordingCtrlWrap::NewInstance(args);
}
void ZoomNodeSettingWrap::GetSettingUIStrategyCtrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeSettingUIStrategyCtrlWrap::NewInstance(args);
}

void ZoomNodeSettingWrap::GetSettingStatisticCtrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeSettingStatisticCtrlWrap::NewInstance(args);
}
void ZoomNodeSettingWrap::GetSettingAccessibilityCtrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeSettingAccessibilityCtrlWrap::NewInstance(args);
}
//
void ZoomNodeSettingWrap::ShowSettingDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 5) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsString() ||
		!args[4]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZNShowSettingDlgParam param;
	zoom_v8toc(args[0].As<v8::String>(), param.hParent);
	zoom_v8toc(args[1].As<v8::String>(), param.left);
	zoom_v8toc(args[2].As<v8::String>(), param.top);
	zoom_v8toc(args[3].As<v8::String>(), param.hSettingWnd);
	zoom_v8toc(args[4].As<v8::Boolean>(), param.bShow);

	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().ShowSettingDlg(param);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingWrap::HideSettingDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().HideSettingDlg();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ZoomNodePremeetingWrap::ZoomNodePremeetingWrap()
{
	_g_native_wrap.GetPremeetingServiecWrap().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_premeetingServiceWrapSink);
}
ZoomNodePremeetingWrap::~ZoomNodePremeetingWrap()
{
	_g_native_wrap.GetPremeetingServiecWrap().SetSink(NULL);
}

void ZoomNodePremeetingWrap::ScheduleMeetingWithWndParams(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 4) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsString())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZNWndPosition zn_position;
#if (defined _WIN32)
	zoom_v8toc(args[0].As<v8::String>(), zn_position.z_hSelfWnd);
	zoom_v8toc(args[1].As<v8::String>(), zn_position.z_hParent);
#else
	zoom_v8toc(args[0].As<v8::String>(), zn_position.z_height);
	zoom_v8toc(args[1].As<v8::String>(), zn_position.z_width);
#endif
	zoom_v8toc(args[2].As<v8::String>(), zn_position.z_left);
	zoom_v8toc(args[3].As<v8::String>(), zn_position.z_top);

	ZNSDKError err = _g_native_wrap.GetPremeetingServiecWrap().ScheduleMeeting(zn_position);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodePremeetingWrap::ScheduleMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetPremeetingServiecWrap().ScheduleMeeting();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodePremeetingWrap::EditMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	unsigned long long zn_meetingUniqueID;
	zn_meetingUniqueID = (unsigned long long)args[0]->NumberValue();

	ZNSDKError err = _g_native_wrap.GetPremeetingServiecWrap().EditMeeting(zn_meetingUniqueID);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodePremeetingWrap::EditMeetingWithWndParams(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 5) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsString() ||
		!args[4]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZNWndPosition zn_position;
#if (defined _WIN32)
	zoom_v8toc(args[0].As<v8::String>(), zn_position.z_hSelfWnd);
	zoom_v8toc(args[1].As<v8::String>(), zn_position.z_hParent);
#else
	zoom_v8toc(args[0].As<v8::String>(), zn_position.z_height);
	zoom_v8toc(args[1].As<v8::String>(), zn_position.z_width);
#endif
	zoom_v8toc(args[2].As<v8::String>(), zn_position.z_left);
	zoom_v8toc(args[3].As<v8::String>(), zn_position.z_top);

	unsigned long long zn_meetingUniqueID = (unsigned long long)args[4]->NumberValue();

	ZNSDKError err = _g_native_wrap.GetPremeetingServiecWrap().EditMeeting(zn_position, zn_meetingUniqueID);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodePremeetingWrap::ListMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetPremeetingServiecWrap().ListMeeting();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodePremeetingWrap::DeleteMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	unsigned long long zn_meetingUniqueID = (unsigned long long)args[0]->NumberValue();

	ZNSDKError err = _g_native_wrap.GetPremeetingServiecWrap().DeleteMeeting(zn_meetingUniqueID);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodePremeetingWrap::SetOnScheduleOrEditMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onScheduleOrEditMeeting.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onScheduleOrEditMeeting = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodePremeetingWrap::SetOnListMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onListMeeting.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onListMeeting = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodePremeetingWrap::SetOnDeleteMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onDeleteMeeting.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onDeleteMeeting = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}