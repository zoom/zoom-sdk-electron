
#include "zoom_node_addon.h"
#include "zoom_v8_to_c.h"
#include "zoom_node_meeting_annotation.h"
#include "zoom_node_meeting_audio_ctrl.h"
#include "zoom_node_meeting_video_ctrl.h"
#include "zoom_node_meeting_recording_ctrl.h"
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
#include "run_task_to_main_thread.h"
#include "zoom_node_sdk_sms_helper.h"
#include "zoom_node_setting_statistic_ctrl.h"
#include "zoom_node_setting_accessibility_ctrl.h"

#include "zoom_node_rawdata_api_ctrl.h"
#include "zoom_node_rawdata_helper_mgr_class.h"

ZNativeSDKWrap _g_native_wrap;

extern ZoomNodePipeServerMgr _g_video_pipe_server;
extern ZoomNodePipeServerMgr _g_share_pipe_server;
extern ZoomNodePipeServerMgr _g_audio_pipe_server;

static void CreateNodeObject(const v8::FunctionCallbackInfo<v8::Value>& args) {
	AddonData* data =
		reinterpret_cast<AddonData*>(args.Data().As<v8::External>()->Value());
	data->zoomNodeWrapInstance = ZoomNodeWrap::GetNewInstance(args);
	args.GetReturnValue().Set(data->zoomNodeWrapInstance);
}


NODE_MODULE_INIT(/* exports, module, context */) {
	v8::Isolate* isolate = context->GetIsolate();


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
	ZoomNodeMeetingRecordingCtrlWrap::Init(exports->GetIsolate());
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
	ZoomNodeSDKSMSHelperWrap::Init(exports->GetIsolate());
	ZoomNodeSettingStatisticCtrlWrap::Init(exports->GetIsolate());
	ZoomNodeSettingAccessibilityCtrlWrap::Init(exports->GetIsolate());
	ZoomNodeRawApiCtrlWrap::Init(exports->GetIsolate());


	AddonData* data = new AddonData(isolate);
	v8::Local<v8::External> external = v8::External::New(isolate, data);

	exports->Set(context,
		v8::String::NewFromUtf8(isolate, "exports", v8::NewStringType::kNormal)
		.ToLocalChecked(),
		v8::FunctionTemplate::New(isolate, CreateNodeObject, external)
		->GetFunction(context).ToLocalChecked()).FromJust();
}

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
v8::Persistent<v8::Function> ZoomNodeMeetingRecordingCtrlWrap::constructor;
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
v8::Persistent<v8::Function> ZoomNodeSDKSMSHelperWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeSettingStatisticCtrlWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeSettingAccessibilityCtrlWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeRawApiCtrlWrap::constructor;
///////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void ZoomNodeWrap::InitSDK(const v8::FunctionCallbackInfo<v8::Value>& args){
	
//#if (defined _WIN32)
//	Init_MainThread_RunLoop(GetCurrentThreadId());
//#else
//	Init_MainThread_RunLoop(0);
//#endif
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::InitSDKParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::InitSDKParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_path() ||
			!proto_params.has_domain()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNInitParam zn_initParams;
		zn_initParams.path = s2zs(proto_params.path());
		zn_initParams.domain = s2zs(proto_params.domain());

		if (proto_params.has_customizedlanguagename() && proto_params.has_customizedlanguageinfo() && proto_params.has_customizedlanguagetype())
		{
			zn_initParams.obConfigOpts.customizedLang.langName = s2zs(proto_params.customizedlanguagename());
			zn_initParams.obConfigOpts.customizedLang.langInfo = s2zs(proto_params.customizedlanguageinfo());
			int zn_customizedLanguageType = proto_params.customizedlanguagetype();
			switch (zn_customizedLanguageType)
			{
			case 0:
				zn_initParams.obConfigOpts.customizedLang.langType = ZN_CustomizedLanguage_None;
				break;
			case 1:
				zn_initParams.obConfigOpts.customizedLang.langType = ZN_CustomizedLanguage_FilePath;
				break;
			case 2:
				zn_initParams.obConfigOpts.customizedLang.langType = ZN_CustomizedLanguage_Content;
				break;
			default:
				break;
			}
		}

		if (proto_params.has_strsupporturl())
		{
			zn_initParams.strSupportUrl = s2zs(proto_params.strsupporturl());
		}
		if (proto_params.has_langid())
		{
			zn_initParams.langid = (ZNSDK_LANGUAGE_ID)proto_params.langid();
		}
		if (proto_params.has_enablelog())
		{
			convertBool(proto_params.enablelog(), zn_initParams.enable_log);
		}
		if (proto_params.has_applocale())
		{
			zn_initParams.locale = (ZNSDK_APP_Locale)proto_params.applocale();
		}
		if (proto_params.has_logfilesize())
		{
			zn_initParams.logFileSize = proto_params.logfilesize();
		}
		if (proto_params.has_enablegeneraldump())
		{
			convertBool(proto_params.enablegeneraldump(), zn_initParams.enableGeneratDump);
		}
		if (proto_params.has_permonitorawarenessmode())
		{
			convertBool(proto_params.permonitorawarenessmode(), zn_initParams.permonitor_awareness_mode);
		}
		if (proto_params.has_videorendermode())
		{
			zn_initParams.renderOpts.videoRenderMode = (ZNZoomSDKVideoRenderMode)proto_params.videorendermode();
		}
		if (proto_params.has_videocapturemethod())
		{
			zn_initParams.renderOpts.videoCaptureMethod = (ZNZoomSDKVideoCaptureMethod)proto_params.videocapturemethod();
		}
		if (proto_params.has_renderpostprocessing())
		{
			zn_initParams.renderOpts.renderPostProcessing = (ZNZoomSDKRenderPostProcessing)proto_params.renderpostprocessing();
		}
		if (proto_params.has_videorawdatamemorymode())
		{
			zn_initParams.rawdataOpts.videoRawdataMemoryMode = (ZNSDKRawDataMemoryMode)proto_params.videorawdatamemorymode();
		}
		if (proto_params.has_sharerawdatamemorymode())
		{
			zn_initParams.rawdataOpts.shareRawdataMemoryMode = (ZNSDKRawDataMemoryMode)proto_params.sharerawdatamemorymode();
		}
		if (proto_params.has_audiorawdatamemorymode())
		{
			zn_initParams.rawdataOpts.audioRawdataMemoryMode = (ZNSDKRawDataMemoryMode)proto_params.audiorawdatamemorymode();
		}
		if (proto_params.has_enablerawdataintermediatemode())
		{
			convertBool(proto_params.enablerawdataintermediatemode(), zn_initParams.rawdataOpts.enableRawdataIntermediateMode);
		}

		err = _g_native_wrap.InitSDK(zn_initParams);

	} while (false);
	

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeWrap::CleanUPSDK(const v8::FunctionCallbackInfo<v8::Value>& args) {
//#if (defined _WIN32)
//	Uninit_MainThread_RunLoop();
//#else
//	Uninit_MainThread_RunLoop();
//#endif
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
void ZoomNodeWrap::SetTeamIdentifier(const v8::FunctionCallbackInfo<v8::Value>& args) 
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetTeamIdentifierParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetTeamIdentifierParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_identifier())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING zn_identifier;
		zn_identifier = s2zs(proto_params.identifier());
		 _g_native_wrap.SetTeamIdentifier(zn_identifier);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
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

void ZoomNodeWrap::GetSDKSMSHelperObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeSDKSMSHelperWrap::NewInstance(args);
}

void ZoomNodeWrap::GetRawdataAPIWrap(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeRawApiCtrlWrap::NewInstance(args);
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::AuthParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::AuthParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_key() ||
			!proto_params.has_secret()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		ZNAuthParam zn_authParam;
		zn_authParam.sdk_key = s2zs(proto_params.key());
		zn_authParam.sdk_secret = s2zs(proto_params.secret());

		err = _g_native_wrap.GetAuthServiceWrap().AuthSDK(zn_authParam);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::AuthWithJwtToken(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::AuthWithJwtTokenParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::AuthWithJwtTokenParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_sdkjwttoken())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNAuthContext zn_authContext;
		zn_authContext.sdk_jwt_token = s2zs(proto_params.sdkjwttoken());
		err = _g_native_wrap.GetAuthServiceWrap().AuthSDK(zn_authContext);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::Login(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::LoginParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::LoginParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_psw() ||
			!proto_params.has_username()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNLoginParam zn_loginParam;
		zn_loginParam.user_name = s2zs(proto_params.username());
		zn_loginParam.psw = s2zs(proto_params.psw());

		if (proto_params.has_rememberme())
		{
			convertBool(proto_params.rememberme(), zn_loginParam.remember_me);
		}
		err = _g_native_wrap.GetAuthServiceWrap().Login(zn_loginParam);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::LoginWithSSOToken(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::LoginWithSSOTokenParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::LoginWithSSOTokenParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_ssotoken())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNLoginParam loginWithSsoParam;
		loginWithSsoParam.ssotoken = s2zs(proto_params.ssotoken());

		if (proto_params.has_rememberme())
		{
			convertBool(proto_params.rememberme(), loginWithSsoParam.remember_me);
		}
		err = _g_native_wrap.GetAuthServiceWrap().LoginWithSSOToken(loginWithSsoParam);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onLoginRet.Empty();			err = ZNSDKERR_INVALID_PARAMETER;			break;		}
		if (!args[0]->IsFunction()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onLoginRet = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::SetLogoutCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onLogout.Empty();			err = ZNSDKERR_INVALID_PARAMETER;			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onLogout = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::SetOnAuthReturnCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onAuthenticationReturn.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onAuthenticationReturn = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::SetOnZoomIdentityExpiredCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onZoomIdentityExpired.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onZoomIdentityExpired = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::SetOnZoomAuthIdentityExpiredCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onZoomAuthIdentityExpired.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onZoomAuthIdentityExpired = cb;

	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::StartMeetingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::StartMeetingParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_meetingnumber() ||
			!proto_params.has_hdirectshareappwnd() ||
			!proto_params.has_participantid() ||
			!proto_params.has_isvideooff() ||
			!proto_params.has_isaudiooff() ||
			!proto_params.has_isdirectsharedesktop()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNStartParam startMeetingParam;
		startMeetingParam.userType = ZNSDK_UT_NORMALUSER;
		startMeetingParam.meetingNumber = proto_params.meetingnumber();
		startMeetingParam.hDirectShareAppWnd = s2zs(proto_params.hdirectshareappwnd());
		startMeetingParam.participantId = s2zs(proto_params.participantid());
		convertBool(proto_params.isvideooff(), startMeetingParam.isVideoOff);
		convertBool(proto_params.isaudiooff(), startMeetingParam.isAudioOff);
		convertBool(proto_params.isdirectsharedesktop(), startMeetingParam.isDirectShareDesktop);

		err = _g_native_wrap.GetMeetingServiceWrap().Start(startMeetingParam);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWrap::Start_WithoutLogin(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::StartWithoutLoginParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::StartWithoutLoginParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid() ||
			!proto_params.has_userzak() ||
			!proto_params.has_username() ||
			!proto_params.has_nodeusertype() ||
			!proto_params.has_meetingnumber() ||
			!proto_params.has_sdkvanityid() ||
			!proto_params.has_hdirectshareappwnd() ||
			!proto_params.has_participantid() ||
			!proto_params.has_isdirectsharedesktop() ||
			!proto_params.has_isvideooff() ||
			!proto_params.has_isaudiooff()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNStartParam startWithoutLoginParam;
		startWithoutLoginParam.userType = ZNSDK_UT_WITHOUT_LOGIN;
		startWithoutLoginParam.userId = s2zs(proto_params.userid());
		startWithoutLoginParam.userZAK = s2zs(proto_params.userzak());
		startWithoutLoginParam.username = s2zs(proto_params.username());
		startWithoutLoginParam.zoomUserType = (ZNZoomUserType)proto_params.nodeusertype();
		startWithoutLoginParam.meetingNumber = proto_params.meetingnumber();
		startWithoutLoginParam.sdkVanityID = s2zs(proto_params.sdkvanityid());
		startWithoutLoginParam.hDirectShareAppWnd = s2zs(proto_params.hdirectshareappwnd());
		startWithoutLoginParam.participantId = s2zs(proto_params.participantid());
		convertBool(proto_params.isdirectsharedesktop(), startWithoutLoginParam.isDirectShareDesktop);
		convertBool(proto_params.isvideooff(), startWithoutLoginParam.isVideoOff);
		convertBool(proto_params.isaudiooff(), startWithoutLoginParam.isAudioOff);

	    err = _g_native_wrap.GetMeetingServiceWrap().Start_WithoutLogin(startWithoutLoginParam);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWrap::Join(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::JoinMeetingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::JoinMeetingParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_meetingnumber() ||
			!proto_params.has_vanityid() ||
			!proto_params.has_username() ||
			!proto_params.has_psw() ||
			!proto_params.has_hdirectshareappwnd() ||
			!proto_params.has_participantid() ||
			!proto_params.has_webinartoken() ||
			!proto_params.has_isdirectsharedesktop() ||
			!proto_params.has_isvideooff() ||
			!proto_params.has_isaudiooff()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNJoinParam joinMeetingParam;
		joinMeetingParam.userType = ZNSDK_UT_NORMALUSER;
		joinMeetingParam.meetingNumber = proto_params.meetingnumber();
		joinMeetingParam.vanityID = s2zs(proto_params.vanityid());
		joinMeetingParam.username = s2zs(proto_params.username());
		joinMeetingParam.psw = s2zs(proto_params.psw());
		joinMeetingParam.hDirectShareAppWnd = s2zs(proto_params.hdirectshareappwnd());
		joinMeetingParam.participantId = s2zs(proto_params.participantid());
		joinMeetingParam.webinarToken = s2zs(proto_params.webinartoken());
		convertBool(proto_params.isvideooff(), joinMeetingParam.isVideoOff);
		convertBool(proto_params.isaudiooff(), joinMeetingParam.isAudioOff);
		convertBool(proto_params.isdirectsharedesktop(), joinMeetingParam.isDirectShareDesktop);

		err = _g_native_wrap.GetMeetingServiceWrap().Join(joinMeetingParam);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingWrap::Join_WithoutLogin(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::JoinWithoutLoginParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::JoinWithoutLoginParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_meetingnumber() ||
			!proto_params.has_vanityid() ||
			!proto_params.has_username() ||
			!proto_params.has_psw() ||
			!proto_params.has_hdirectshareappwnd() ||
			!proto_params.has_userzak() ||
			!proto_params.has_participantid() ||
			!proto_params.has_webinartoken() ||
			!proto_params.has_isdirectsharedesktop() ||
			!proto_params.has_isvideooff() ||
			!proto_params.has_isaudiooff()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNJoinParam joinWithoutLoginParam;
		joinWithoutLoginParam.userType = ZNSDK_UT_WITHOUT_LOGIN;
		joinWithoutLoginParam.meetingNumber = proto_params.meetingnumber();
		joinWithoutLoginParam.vanityID = s2zs(proto_params.vanityid());
		joinWithoutLoginParam.username = s2zs(proto_params.username());
		joinWithoutLoginParam.psw = s2zs(proto_params.psw());
		joinWithoutLoginParam.hDirectShareAppWnd = s2zs(proto_params.hdirectshareappwnd());
		joinWithoutLoginParam.userZAK = s2zs(proto_params.userzak());
		joinWithoutLoginParam.participantId = s2zs(proto_params.participantid());
		joinWithoutLoginParam.webinarToken = s2zs(proto_params.webinartoken());
		convertBool(proto_params.isvideooff(), joinWithoutLoginParam.isVideoOff);
		convertBool(proto_params.isaudiooff(), joinWithoutLoginParam.isAudioOff);
		convertBool(proto_params.isdirectsharedesktop(), joinWithoutLoginParam.isDirectShareDesktop);

		err = _g_native_wrap.GetMeetingServiceWrap().Join_WithoutLogin(joinWithoutLoginParam);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWrap::Leave(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::LeaveMeetingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::LeaveMeetingParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bend())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		bool bEnd_ = false;
		convertBool(proto_params.bend(), bEnd_);

		err = _g_native_wrap.GetMeetingServiceWrap().Leave(bEnd_ ? ZNEND_MEETING : ZNLEAVE_MEETING);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::HandleZoomWebUriProtocolActionParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::HandleZoomWebUriProtocolActionParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_protocolaction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING zn_protocal_action_;
		zn_protocal_action_ = s2zs(proto_params.protocolaction());
		err = _g_native_wrap.GetMeetingServiceWrap().HandleZoomWebUriProtocolAction(zn_protocal_action_);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWrap::SetMeetingStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onMeetingStatusChanged.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onMeetingStatusChanged = cb;

	} while (false);
	
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
void ZoomNodeMeetingWrap::GetMeetingRecordingCtrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomNodeMeetingRecordingCtrlWrap::NewInstance(args);
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::ShowChatDlgParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ShowChatDlgParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_hparent() ||
			!proto_params.has_rectbottom() ||
			!proto_params.has_rectleft() ||
			!proto_params.has_rectright() ||
			!proto_params.has_recttop()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNShowChatDlgParam _param;
		_param.hParent = s2zs(proto_params.hparent());
		_param.rect_bottom = s2zs(proto_params.rectbottom());
		_param.rect_left = s2zs(proto_params.rectleft());
		_param.rect_right = s2zs(proto_params.rectright());
		_param.rect_top = s2zs(proto_params.recttop());

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ShowChatDlg(_param);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnterFullScreenParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnterFullScreenParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bfirstview() ||
			!proto_params.has_bsecview()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bFirstView = false;
		bool _bSecView = false;
		convertBool(proto_params.bfirstview(), _bFirstView);
		convertBool(proto_params.bsecview(), _bSecView);

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().EnterFullScreen(_bFirstView, _bSecView);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::ExitFullScreen(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::ExitFullScreenParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ExitFullScreenParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bfirstview() ||
			!proto_params.has_bsecview()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bFirstView = false;
		bool _bSecView = false;
		convertBool(proto_params.bfirstview(), _bFirstView);
		convertBool(proto_params.bsecview(), _bSecView);

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ExitFullScreen(_bFirstView, _bSecView);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::MoveFloatVideoWndParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::MoveFloatVideoWndParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_left() ||
			!proto_params.has_top()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING _left;
		ZoomSTRING _top;
		_left = s2zs(proto_params.left());
		_top = s2zs(proto_params.top());

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().MoveFloatVideoWnd(_left, _top);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::ShowSharingToolbar(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::ShowSharingToolbarParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ShowSharingToolbarParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bshow())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bShow = false;
		convertBool(proto_params.bshow(), _bShow);
		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ShowSharingToolbar(_bShow);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::ChangeFloatoActiveSpkVideoSizeParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ChangeFloatoActiveSpkVideoSizeParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_floatvideotype())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		int _type = proto_params.floatvideotype();
		ZNSDKFloatVideoType _zn_sdk_float_video_type;
		switch (_type)
		{
		case 0:
			_zn_sdk_float_video_type = ZN_FLOATVIDEO_List;
			break;
		case 1:
			_zn_sdk_float_video_type = ZN_FLOATVIDEO_Small;
			break;
		case 2:
			_zn_sdk_float_video_type = ZN_FLOATVIDEO_Large;
			break;
		case 3:
			_zn_sdk_float_video_type = ZN_FLOATVIDEO_Minimize;
			break;
		default:
			break;
		}

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ChangeFloatoActiveSpkVideoSize(_zn_sdk_float_video_type);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::ShowParticipantsListWndParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ShowParticipantsListWndParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bshow())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bShow = false;
		convertBool(proto_params.bshow(), _bShow);
		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ShowParticipantsListWnd(_bShow);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::ShowBottomFloatToolbarWnd(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::ShowBottomFloatToolbarWndParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ShowBottomFloatToolbarWndParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bshow())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bShow = false;
		convertBool(proto_params.bshow(), _bShow);
		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ShowBottomFloatToolbarWnd(_bShow);
	} while (false);
	
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

	ZNVideoWallPageInfoParam param;
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::ShowPreOrNextPageVideoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ShowPreOrNextPageVideoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bpageup())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bPageUP = false;
		convertBool(proto_params.bpageup(), _bPageUP);
		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ShowPreOrNextPageVideo(_bPageUP);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::ShowSharingFrameWindows(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::ShowSharingFrameWindowsParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ShowSharingFrameWindowsParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bshow())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bShow = false;
		convertBool(proto_params.bshow(), _bShow);
		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().ShowSharingFrameWindows(_bShow);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::GetCurrentSplitScreenModeInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNSplitScreenInfo info;
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SwitchSplitScreenModeParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SwitchSplitScreenModeParams >(args, proto_params))
		{
			err = ZNSDKERR_SUCCESS;
			break;
		}
		if (!proto_params.has_bsplit())
		{
			err = ZNSDKERR_SUCCESS;
			break;
		}
		bool _bSplit = false;
		convertBool(proto_params.bsplit(), _bSplit);
		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().SwitchSplitScreenMode(_bSplit);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SwitchMinimizeUIMode4FirstScreenMeetingUIWndParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SwitchMinimizeUIMode4FirstScreenMeetingUIWndParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_minimizeuimode())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNSDKMinimizeUIMode _mode;
		_mode = (ZNSDKMinimizeUIMode)proto_params.minimizeuimode();
		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().SwitchMinimizeUIMode4FristScreenMeetingUIWnd(_mode);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SwapToShowShareViewOrVideoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SwapToShowShareViewOrVideoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_btodisplayshare())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _zn_bToDisplayShare = false;
		convertBool(proto_params.btodisplayshare(), _zn_bToDisplayShare);
		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().SwapToShowShareViewOrVideo(_zn_bToDisplayShare);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onInviteBtnClicked.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onInviteBtnClicked = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetonStartShareBtnClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onStartShareBtnClicked.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onStartShareBtnClicked = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetonEndMeetingBtnClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onEndMeetingBtnClicked.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onEndMeetingBtnClicked = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetonParticipantListBtnClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onParticipantListBtnClicked.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onParticipantListBtnClicked = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetonCustomLiveStreamMenuClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onCustomLiveStreamMenuClicked.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onCustomLiveStreamMenuClicked = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetonZoomInviteDialogFailedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onZoomInviteDialogFailed.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onZoomInviteDialogFailed = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetonCCBTNClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onCCBTNClicked.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onCCBTNClicked = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetonAudioBTNClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onAudioBtnClicked.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onAudioBtnClicked = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetonAudioMenuBTNClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onAudioMenuBtnClicked.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onAudioMenuBtnClicked = cb;

	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::ShowSettingDlgParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ShowSettingDlgParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_hparent() ||
			!proto_params.has_bshow() ||
			!proto_params.has_hsettingwnd() ||
			!proto_params.has_left() ||
			!proto_params.has_top()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNShowSettingDlgParam _param;
		_param.hParent = s2zs(proto_params.hparent());
		_param.left = s2zs(proto_params.left());
		_param.top = s2zs(proto_params.top());
		_param.hSettingWnd = s2zs(proto_params.hsettingwnd());
		convertBool(proto_params.bshow(), _param.bShow);

		err = _g_native_wrap.GetSettingServiceWrap().ShowSettingDlg(_param);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::ScheduleMeetingWithWndParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ScheduleMeetingWithWndParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_hparent() ||
			!proto_params.has_hselfwnd() ||
			!proto_params.has_left() ||
			!proto_params.has_top()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNWndPosition _zn_position;
#if (defined _WIN32)
		_zn_position.z_hSelfWnd = s2zs(proto_params.hselfwnd());
		_zn_position.z_hParent = s2zs(proto_params.hparent());
#else
		_zn_position.z_height = s2zs(proto_params.hselfwnd());
		_zn_position.z_width = s2zs(proto_params.hparent());
#endif
		_zn_position.z_left = s2zs(proto_params.left());
		_zn_position.z_top = s2zs(proto_params.top());

		err = _g_native_wrap.GetPremeetingServiecWrap().ScheduleMeeting(_zn_position);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EditMeetingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EditMeetingParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_meetingnumber())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned long long _zn_meetingUniqueID;
		_zn_meetingUniqueID = proto_params.meetingnumber();

		err = _g_native_wrap.GetPremeetingServiecWrap().EditMeeting(_zn_meetingUniqueID);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodePremeetingWrap::EditMeetingWithWndParams(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EditMeetingWithWndParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EditMeetingWithWndParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_hparent() ||
			!proto_params.has_hselfwnd() ||
			!proto_params.has_left() ||
			!proto_params.has_top() ||
			!proto_params.has_meetingnumber()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNWndPosition _zn_position;
#if (defined _WIN32)
		_zn_position.z_hSelfWnd = s2zs(proto_params.hselfwnd());
		_zn_position.z_hParent = s2zs(proto_params.hparent());
#else
		_zn_position.z_height = s2zs(proto_params.hselfwnd());
		_zn_position.z_width = s2zs(proto_params.hparent());
#endif
		_zn_position.z_left = s2zs(proto_params.left());
		_zn_position.z_top = s2zs(proto_params.top());

		unsigned long long _zn_meetingUniqueID;
		_zn_meetingUniqueID = (unsigned long long)proto_params.meetingnumber();

		err = _g_native_wrap.GetPremeetingServiecWrap().EditMeeting(_zn_position, _zn_meetingUniqueID);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::DeleteMeetingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::DeleteMeetingParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_meetingnumber())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned long long _zn_meetingUniqueID;
		_zn_meetingUniqueID = (unsigned long long)proto_params.meetingnumber();
		err = _g_native_wrap.GetPremeetingServiecWrap().DeleteMeeting(_zn_meetingUniqueID);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodePremeetingWrap::SetOnScheduleOrEditMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onScheduleOrEditMeeting.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onScheduleOrEditMeeting = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodePremeetingWrap::SetOnListMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onListMeeting.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onListMeeting = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodePremeetingWrap::SetOnDeleteMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) 
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onDeleteMeeting.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onDeleteMeeting = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}