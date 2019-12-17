#include "zoom_node_setting_audio_ctrl.h"


ZoomNodeSettingAudioCtrlWrap::ZoomNodeSettingAudioCtrlWrap()
{
	_g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_audioSettingContextWrapSink);
}

ZoomNodeSettingAudioCtrlWrap::~ZoomNodeSettingAudioCtrlWrap()
{
	_g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().SetSink(NULL);
}
void ZoomNodeSettingAudioCtrlWrap::SelectMic(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
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
	ZoomSTRING zn_deviceId;
	zoom_v8toc(args[0].As<v8::String>(), zn_deviceId);
	ZoomSTRING zn_deviceName;
	zoom_v8toc(args[1].As<v8::String>(), zn_deviceName);

	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().SelectMic(zn_deviceId, zn_deviceName);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeSettingAudioCtrlWrap::GetMicList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNList<ZNMicInfo> zn_micInfoLst = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().GetMicList();

	v8::HandleScope scope(isolate);
	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_micInfoLst.size(); ++i) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "deviceId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_micInfoLst[i].deviceId).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "deviceName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_micInfoLst[i].deviceName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "isSelected", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_micInfoLst[i].isSelectedDevice));
		nodes->Set(context, i, node);
	}

	args.GetReturnValue().Set(nodes);
}
void ZoomNodeSettingAudioCtrlWrap::SelectSpeaker(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
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
	ZoomSTRING zn_deviceId;
	zoom_v8toc(args[0].As<v8::String>(), zn_deviceId);
	ZoomSTRING zn_deviceName;
	zoom_v8toc(args[1].As<v8::String>(), zn_deviceName);

	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().SelectSpeaker(zn_deviceId, zn_deviceName);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeSettingAudioCtrlWrap::GetSpeakerList(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNList<ZNSpeakerInfo> zn_speakerInfoLst = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().GetSpeakerList();

	v8::HandleScope scope(isolate);
	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_speakerInfoLst.size(); ++i) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "deviceId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_speakerInfoLst[i].deviceId).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "deviceName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_speakerInfoLst[i].deviceName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "isSelected", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_speakerInfoLst[i].isSelectedDevice));
		nodes->Set(context, i, node);
	}

	args.GetReturnValue().Set(nodes);
}
void ZoomNodeSettingAudioCtrlWrap::IsAutoJoinAudioEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bDisable = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().IsAutoJoinAudioEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bDisable);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::IsAutoAdjustMicEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bDisable = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().IsAutoAdjustMicEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bDisable);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::EnableAutoJoinAudio(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableAutoJoinAudio(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::EnableAutoAdjustMic(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableAutoAdjustMic(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ZoomNodeSettingAudioCtrlWrap::SetComputerMicDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onComputerMicDeviceChanged.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onComputerMicDeviceChanged = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::SetComputerSpeakerDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onComputerSpeakerDeviceChanged.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onComputerSpeakerDeviceChanged = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::SetDefaultMicDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onDefaultMicDeviceChanged.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onDefaultMicDeviceChanged = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::SetDefaultSpeakerDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onDefaultSpeakerDeviceChanged.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onDefaultSpeakerDeviceChanged = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeSettingAudioCtrlWrap::EnableStereoAudio(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableStereoAudio(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::IsStereoAudioEnable(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().IsStereoAudioEnable();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::EnableMicOriginalInput(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableMicOriginalInput(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::IsMicOriginalInputEnable(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().IsMicOriginalInputEnable();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::EnableHoldSpaceKeyToSpeak(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableHoldSpaceKeyToSpeak(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::IsHoldSpaceKeyToSpeakEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().IsHoldSpaceKeyToSpeakEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::EnableAlwaysMuteMicWhenJoinVoip(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableAlwaysMuteMicWhenJoinVoip(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::IsAlwaysMuteMicWhenJoinVoipEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().IsAlwaysMuteMicWhenJoinVoipEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::EnableSuppressAudioNotify(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableSuppressAudioNotify(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::IsSuppressAudioNotifyEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().IsSuppressAudioNotifyEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::EnableEchoCancellation(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableEchoCancellation(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::IsEchoCancellationEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().IsEchoCancellationEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::SetMicVol(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	float zn_value;
	zn_value = (float)args[0]->NumberValue();

	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().SetMicVol(zn_value);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::GetMicVol(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	float zn_value;
	zn_value = (float)args[0]->NumberValue();

	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().GetMicVol(zn_value);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "MicVol", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Number::New(isolate, (double)zn_value));

	args.GetReturnValue().Set(node);
}
void ZoomNodeSettingAudioCtrlWrap::SetSpeakerVol(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	float zn_value;
	zn_value = (float)args[0]->NumberValue();

	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().SetSpeakerVol(zn_value);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::GetSpeakerVol(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	float zn_value;
	zn_value = (float)args[0]->NumberValue();

	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().GetSpeakerVol(zn_value);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "SpeakerVol", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Number::New(isolate, (double)zn_value));

	args.GetReturnValue().Set(node);;
}