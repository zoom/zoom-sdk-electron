#include "zoom_node_setting_audio_ctrl.h"


ZoomNodeSettingAudioCtrlWrap::ZoomNodeSettingAudioCtrlWrap()
{

}

ZoomNodeSettingAudioCtrlWrap::~ZoomNodeSettingAudioCtrlWrap()
{

}
void ZoomNodeSettingAudioCtrlWrap::SelectMic(const v8::FunctionCallbackInfo<v8::Value>& args)
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
	ZNList<ZNMicInfo> zn_micInfoLst = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().GetMicList();

	v8::HandleScope scope(isolate);
	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_micInfoLst.size(); ++i) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(v8::String::NewFromUtf8(isolate, "deviceId"), v8::String::NewFromUtf8(isolate, zs2s(zn_micInfoLst[i].deviceId).c_str()));
		node->Set(v8::String::NewFromUtf8(isolate, "deviceName"), v8::String::NewFromUtf8(isolate, zs2s(zn_micInfoLst[i].deviceName).c_str()));
		node->Set(v8::String::NewFromUtf8(isolate, "isSelected"), v8::Boolean::New(isolate, zn_micInfoLst[i].isSelectedDevice));
		nodes->Set(i, node);
	}

	args.GetReturnValue().Set(nodes);
}
void ZoomNodeSettingAudioCtrlWrap::SelectSpeaker(const v8::FunctionCallbackInfo<v8::Value>& args)
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
	ZNList<ZNSpeakerInfo> zn_speakerInfoLst = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().GetSpeakerList();

	v8::HandleScope scope(isolate);
	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_speakerInfoLst.size(); ++i) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(v8::String::NewFromUtf8(isolate, "deviceId"), v8::String::NewFromUtf8(isolate, zs2s(zn_speakerInfoLst[i].deviceId).c_str()));
		node->Set(v8::String::NewFromUtf8(isolate, "deviceName"), v8::String::NewFromUtf8(isolate, zs2s(zn_speakerInfoLst[i].deviceName).c_str()));
		node->Set(v8::String::NewFromUtf8(isolate, "isSelected"), v8::Boolean::New(isolate, zn_speakerInfoLst[i].isSelectedDevice));
		nodes->Set(i, node);
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
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableAutoAdjustMic(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}