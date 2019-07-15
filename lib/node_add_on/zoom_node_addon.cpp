
#include "zoom_node_addon.h"
#include "zoom_v8_to_c.cpp"
#include "zoom_node_meeting_annotation.cpp"
#include "zoom_node_meeting_audio_ctrl.cpp"
#include "zoom_node_meeting_video_ctrl.cpp"
#include "zoom_node_meeting_participants_ctrl.cpp"
#include "zoom_node_meeting_share_ctrl.cpp"
#include "zoom_node_meeting_h323_ctrl.cpp"
#include "zoom_node_meeting_config_ctrl.cpp"
#include "zoom_node_setting_video_ctrl.cpp"
#include "zoom_node_setting_audio_ctrl.cpp"
#include "zoom_node_setting_general_ctrl.cpp"
#include "zoom_node_setting_recording_ctrl.cpp"
#include "zoom_node_customized_resource.cpp"


ZNativeSDKWrap _g_native_wrap;

void CreateObject(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeWrap::NewInstance(args);
}

void InitAll(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
	ZoomNodeWrap::Init(exports->GetIsolate());
	ZoomNodeAuthWrap::Init(exports->GetIsolate());
	ZoomNodeMeetingWrap::Init(exports->GetIsolate());
	ZoomNodeSettingWrap::Init(exports->GetIsolate());
	
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
	ZoomNodeSettingRecordingCtrlWrap::Init(exports->GetIsolate());
	
	NODE_SET_METHOD(module, "exports", CreateObject);
}

NODE_MODULE(zoomsdk, InitAll)

v8::Persistent<v8::Function> ZoomNodeWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeAuthWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeMeetingWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeSettingWrap::constructor;

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
v8::Persistent<v8::Function> ZoomNodeSettingRecordingCtrlWrap::constructor;

///////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void ZoomNodeWrap::InitSDK(const v8::FunctionCallbackInfo<v8::Value>& args){
	
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 6 || !args[0]->IsString()) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "ZoomNodeWrap::InitSDK-Wrong number of arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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

	if (args.Length() == 7)
	{
		zoom_v8toc(args[6].As<v8::Boolean>(), param.enable_log);
	}
	ZNSDKError err = _g_native_wrap.InitSDK(param);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeWrap::CleanUPSDK(const v8::FunctionCallbackInfo<v8::Value>& args) {
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.CleanUPSDK();
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

void ZoomNodeWrap::GetCustomizedResourceObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeCustomizedResourceWrap::NewInstance(args);
}
////////////////////////////////////////////////////////////////////////////
class ZNativeSDKAuthWrapSink : public IZNativeSDKAuthWrapSink
{
public:
	virtual void onAuthenticationReturn(ZNAuthResult authResult)
	{
		if (ZoomNodeSinkHelper::GetInst().onAuthenticationReturn.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_authresult = v8::Integer::New(isolate, (int32_t)authResult);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_authresult };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onAuthenticationReturn);

		fn->Call(context, global, argc, argv);
	}
	virtual void onLoginRet(ZNLOGINSTATUS ret)
	{
		if (ZoomNodeSinkHelper::GetInst().onLoginRet.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_loginstatus = v8::Integer::New(isolate, (int32_t)ret);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_loginstatus };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onLoginRet);
		fn->Call(context, global, argc, argv);
	}
	virtual void onLogout()
	{
		if (ZoomNodeSinkHelper::GetInst().onLogout.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onLogout);
		fn->Call(context, global, 0, NULL);
	}
	virtual void onZoomIdentityExpired()
	{
		if (ZoomNodeSinkHelper::GetInst().onZoomIdentityExpired.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onZoomIdentityExpired);
		fn->Call(context, global, 0, NULL);
	}
};

static ZNativeSDKAuthWrapSink _g_node_auth_cb;

ZoomNodeAuthWrap::ZoomNodeAuthWrap()
{
	_g_native_wrap.GetAuthServiceWrap().SetSink(&_g_node_auth_cb);
}

ZoomNodeAuthWrap::~ZoomNodeAuthWrap()
{
	_g_native_wrap.GetAuthServiceWrap().SetSink(NULL);
}

void ZoomNodeAuthWrap::Auth(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 3) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	ZNAuthParam param;
	zoom_v8toc(args[0].As<v8::String>(), param.sdk_key);
	zoom_v8toc(args[1].As<v8::String>(), param.sdk_secret);

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[2]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onAuthenticationReturn = cb;

	ZNSDKError err = _g_native_wrap.GetAuthServiceWrap().AuthSDK(param);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::Login(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 3) 
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}
	ZNLoginParam param;
	zoom_v8toc(args[0].As<v8::String>(), param.user_name);
	zoom_v8toc(args[1].As<v8::String>(), param.psw);

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[2]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onLoginRet = cb;

	if (args.Length() == 4)
	{
		zoom_v8toc(args[3].As<v8::Boolean>(), param.remember_me);
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}
	ZNLoginParam param;
	zoom_v8toc(args[0].As<v8::String>(), param.ssotoken);
	
	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[1]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onLoginRet = cb;

	if (args.Length() == 3)
	{
		zoom_v8toc(args[2].As<v8::Boolean>(), param.remember_me);
	}

	ZNSDKError err = _g_native_wrap.GetAuthServiceWrap().LoginWithSSOToken(param);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAuthWrap::Logout(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}
	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onLogout = cb;

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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onLogout = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingWrapSink : public IZNativeSDKMeetingWrapSink
{
public:
	virtual void onMeetingStatusChanged(ZNMeetingStatus meetingStatus, int iResult)
	{
		if (ZoomNodeSinkHelper::GetInst().onMeetingStatusChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer > v8_meeting_status = v8::Integer::New(isolate, (int32_t)meetingStatus);
		v8::Local<v8::Integer > v8_result = v8::Integer::New(isolate, (int32_t)iResult);
		int argc = 2;
		v8::Local<v8::Value> argv[2] = { v8_meeting_status, v8_result };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onMeetingStatusChanged);

		fn->Call(context, global, argc, argv);
	}
};

static ZNativeSDKMeetingWrapSink _g_node_meeting_cb;

ZoomNodeMeetingWrap::ZoomNodeMeetingWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().SetSink(&_g_node_meeting_cb);
}

ZoomNodeMeetingWrap::~ZoomNodeMeetingWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().SetSink(NULL);
}
void ZoomNodeMeetingWrap::Start(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 7)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsBoolean() ||
		!args[4]->IsBoolean() ||
		!args[5]->IsBoolean() ||
		!args[6]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}
	ZNStartParam param;
	param.userType = ZNSDK_UT_NORMALUSER;
	zoom_v8toc(args[0].As<v8::String>(), param.meetingNumber);
	zoom_v8toc(args[1].As<v8::String>(), param.hDirectShareAppWnd);
	zoom_v8toc(args[2].As<v8::String>(), param.participantId);
	zoom_v8toc(args[3].As<v8::Boolean>(), param.isVideoOff);
	zoom_v8toc(args[4].As<v8::Boolean>(), param.isAudioOff);
	zoom_v8toc(args[5].As<v8::Boolean>(), param.isDirectShareDesktop);


	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[6]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onMeetingStatusChanged = cb;

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().Start(param);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWrap::Start_WithoutLogin(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 13)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsString() ||
		!args[4]->IsNumber() ||
		!args[5]->IsString() ||
		!args[6]->IsString() ||
		!args[7]->IsString() ||
		!args[8]->IsString() ||
		!args[9]->IsBoolean() ||
		!args[10]->IsBoolean() ||
		!args[11]->IsBoolean() ||
		!args[12]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
	zoom_v8toc(args[5].As<v8::String>(), param.meetingNumber);
	zoom_v8toc(args[6].As<v8::String>(), param.sdkVanityID);
	zoom_v8toc(args[7].As<v8::String>(), param.hDirectShareAppWnd);
	zoom_v8toc(args[8].As<v8::String>(), param.participantId);
	zoom_v8toc(args[9].As<v8::Boolean>(), param.isDirectShareDesktop);
	zoom_v8toc(args[10].As<v8::Boolean>(), param.isVideoOff);
	zoom_v8toc(args[11].As<v8::Boolean>(), param.isAudioOff);


	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[12]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onMeetingStatusChanged = cb;

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().Start_WithoutLogin(param);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingWrap::Join(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 11)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsString() ||
		!args[4]->IsString() ||
		!args[5]->IsString() ||
		!args[6]->IsString() ||
		!args[7]->IsBoolean() ||
		!args[8]->IsBoolean() ||
		!args[9]->IsBoolean() ||
		!args[10]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}
	ZNJoinParam param;
	param.userType = ZNSDK_UT_NORMALUSER;
	zoom_v8toc(args[0].As<v8::String>(), param.meetingNumber);
	zoom_v8toc(args[1].As<v8::String>(), param.vanityID);
	zoom_v8toc(args[2].As<v8::String>(), param.username);
	zoom_v8toc(args[3].As<v8::String>(), param.psw);
	zoom_v8toc(args[4].As<v8::String>(), param.hDirectShareAppWnd);
	zoom_v8toc(args[5].As<v8::String>(), param.participantId);
	zoom_v8toc(args[6].As<v8::String>(), param.webinarToken);
	zoom_v8toc(args[7].As<v8::Boolean>(), param.isVideoOff);
	zoom_v8toc(args[8].As<v8::Boolean>(), param.isAudioOff);
	zoom_v8toc(args[9].As<v8::Boolean>(), param.isDirectShareDesktop);

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[10]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onMeetingStatusChanged = cb;

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().Join(param);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingWrap::Join_WithoutLogin(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 12)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsString() ||
		!args[4]->IsString() ||
		!args[5]->IsString() ||
		!args[6]->IsString() ||
		!args[7]->IsString() ||
		!args[8]->IsBoolean() ||
		!args[9]->IsBoolean() ||
		!args[10]->IsBoolean() ||
		!args[11]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}
	ZNJoinParam param;
	param.userType = ZNSDK_UT_WITHOUT_LOGIN;
	zoom_v8toc(args[0].As<v8::String>(), param.meetingNumber);
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
	

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[11]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onMeetingStatusChanged = cb;

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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}
	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
void ZoomNodeMeetingWrap::SetMeetingStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(meeting_topic).c_str());
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
	ZoomSTRING meeting_number = _g_native_wrap.GetMeetingServiceWrap().GetMeetingInfo().GetMeetingNumber();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(meeting_number).c_str());
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingInfoWrap::GetMeetingID(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING meeting_id = _g_native_wrap.GetMeetingServiceWrap().GetMeetingInfo().GetMeetingID();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(meeting_id).c_str());
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingInfoWrap::GetInviteEmailTeamplate(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING invite_email_teamplate = _g_native_wrap.GetMeetingServiceWrap().GetMeetingInfo().GetInviteEmailTeamplate();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(invite_email_teamplate).c_str());
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingInfoWrap::GetInviteEmailTitle(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING invite_email_title = _g_native_wrap.GetMeetingServiceWrap().GetMeetingInfo().GetInviteEmailTitle();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(invite_email_title).c_str());
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingInfoWrap::GetJoinMeetingUrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING join_meeting_url = _g_native_wrap.GetMeetingServiceWrap().GetMeetingInfo().GetJoinMeetingUrl();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(join_meeting_url).c_str());
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingInfoWrap::GetMeetingHostTag(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING meeting_host_tag = _g_native_wrap.GetMeetingServiceWrap().GetMeetingInfo().GetMeetingHostTag();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(meeting_host_tag).c_str());
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
class ZNativeSDKMeetingUICtrlWrapSink : public IZNativeSDKMeetingUICtrlWrapSink
{
public:
	virtual void onInviteBtnClicked(bool& bHandled)
	{
		if (ZoomNodeSinkHelper::GetInst().onInviteBtnClicked.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Boolean > v8_bHandled = v8::Boolean::New(isolate, bHandled);
		
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_bHandled };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onInviteBtnClicked);

		fn->Call(context, global, argc, argv);
	}
};

static ZNativeSDKMeetingUICtrlWrapSink _g_node_meetingUICtrl_cb;

ZoomNodeMeetingUICtrlWrap::ZoomNodeMeetingUICtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().SetSink(&_g_node_meetingUICtrl_cb);
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean() ||
		!args[1]->IsBoolean()
		
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean() ||
		!args[1]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean() 
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsNumber()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	ZNVideoWallPageInfoParam param;
	zoom_v8toc(args[0].As<v8::String>(), param.currentPage);
	zoom_v8toc(args[1].As<v8::String>(), param.totalPages);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().GetWallViewPageInfo(param);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(v8::String::NewFromUtf8(isolate, "err"), v8::Integer::New(isolate, (int32_t)err));
	node->Set(v8::String::NewFromUtf8(isolate, "currentPage"), v8::String::NewFromUtf8(isolate, zs2s(param.currentPage).c_str()));
	node->Set(v8::String::NewFromUtf8(isolate, "totalPages"), v8::String::NewFromUtf8(isolate, zs2s(param.totalPages).c_str()));

	
	args.GetReturnValue().Set(node);
}
void ZoomNodeMeetingUICtrlWrap::ShowPreOrNextPageVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean() ||
		!args[1]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	ZNSplitScreenInfo info;
	zoom_v8toc(args[0].As<v8::Boolean>(), info.bZNSupportSplitScreen);
	zoom_v8toc(args[1].As<v8::Boolean>(), info.bZNInSplitScreenMode);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().GetCurrentSplitScreenModeInfo(info);

	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(v8::String::NewFromUtf8(isolate, "err"), v8::Integer::New(isolate, (int32_t)err));
	node->Set(v8::String::NewFromUtf8(isolate, "bZNSupportSplitScreen"), v8::Boolean::New(isolate, info.bZNSupportSplitScreen));
	node->Set(v8::String::NewFromUtf8(isolate, "bZNInSplitScreenMode"), v8::Boolean::New(isolate, info.bZNInSplitScreenMode));

	args.GetReturnValue().Set(node);
}
void ZoomNodeMeetingUICtrlWrap::SwitchSplitScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	bool b_Split;
	zoom_v8toc(args[0].As<v8::Boolean>(), b_Split);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().SwitchSplitScreenMode(b_Split);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingUICtrlWrap::SetInviteButtonClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onInviteBtnClicked = cb;

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
void ZoomNodeSettingWrap::ShowSettingDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 5) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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

