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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SelectMicParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SelectMicParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_deviceid() ||
			!proto_params.has_devicename()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING _zn_deviceId;
		_zn_deviceId = s2zs(proto_params.deviceid());
		ZoomSTRING _zn_deviceName;
		_zn_deviceName = s2zs(proto_params.devicename());

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().SelectMic(_zn_deviceId, _zn_deviceName);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SelectSpeakerParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SelectSpeakerParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_deviceid() ||
			!proto_params.has_devicename()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING _zn_deviceId;
		_zn_deviceId = s2zs(proto_params.deviceid());
		ZoomSTRING _zn_deviceName;
		_zn_deviceName = s2zs(proto_params.devicename());

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().SelectSpeaker(_zn_deviceId, _zn_deviceName);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableAutoJoinAudioParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableAutoJoinAudioParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableAutoJoinAudio(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::EnableAutoAdjustMic(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableAutoAdjustMicParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableAutoAdjustMicParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableAutoAdjustMic(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ZoomNodeSettingAudioCtrlWrap::SetComputerMicDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onComputerMicDeviceChanged.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onComputerMicDeviceChanged = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::SetComputerSpeakerDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onComputerSpeakerDeviceChanged.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onComputerSpeakerDeviceChanged = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::SetDefaultMicDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onDefaultMicDeviceChanged.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onDefaultMicDeviceChanged = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::SetDefaultSpeakerDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onDefaultSpeakerDeviceChanged.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onDefaultSpeakerDeviceChanged = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeSettingAudioCtrlWrap::EnableStereoAudio(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableStereoAudioParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableStereoAudioParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableStereoAudio(_bEnable);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableMicOriginalInputParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableMicOriginalInputParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableMicOriginalInput(_bEnable);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableHoldSpaceKeyToSpeakParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableHoldSpaceKeyToSpeakParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableHoldSpaceKeyToSpeak(_bEnable);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableAlwaysMuteMicWhenJoinVoipParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableAlwaysMuteMicWhenJoinVoipParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableAlwaysMuteMicWhenJoinVoip(_bEnable);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableSuppressAudioNotifyParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableSuppressAudioNotifyParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableSuppressAudioNotify(_bEnable);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableEchoCancellationParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableEchoCancellationParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().EnableEchoCancellation(_bEnable);
	} while (false);
	
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetMicVolParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetMicVolParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_value())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		float _zn_value;
		_zn_value = proto_params.value();

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().SetMicVol(_zn_value);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::GetMicVol(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	float zn_value = 0;
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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetSpeakerVolParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetSpeakerVolParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_value())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		float _zn_value;
		_zn_value = proto_params.value();

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().SetSpeakerVol(_zn_value);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAudioCtrlWrap::GetSpeakerVol(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	float zn_value = 0;
	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().GetSpeakerVol(zn_value);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "SpeakerVol", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Number::New(isolate, (double)zn_value));

	args.GetReturnValue().Set(node);;
}