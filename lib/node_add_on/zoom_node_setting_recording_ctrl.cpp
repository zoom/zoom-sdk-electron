#include "zoom_node_setting_recording_ctrl.h"


ZoomNodeSettingRecordingCtrlWrap::ZoomNodeSettingRecordingCtrlWrap()
{
	_g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_recordingSettingContextWrapSink);
}

ZoomNodeSettingRecordingCtrlWrap::~ZoomNodeSettingRecordingCtrlWrap()
{
	_g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().SetSink(NULL);
}
void ZoomNodeSettingRecordingCtrlWrap::SetRecordingPath(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	ZoomSTRING zn_szPath;
	zoom_v8toc(args[0].As<v8::String>(), zn_szPath);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().SetRecordingPath(zn_szPath);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingRecordingCtrlWrap::GetRecordingPath(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	//
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING recordingPath = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().GetRecordingPath();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(recordingPath).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ZoomNodeSettingRecordingCtrlWrap::SetonCloudRecordingStorageInfoCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onCloudRecordingStorageInfo.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onCloudRecordingStorageInfo = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingRecordingCtrlWrap::CanGetCloudRecordingStorageInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool bCan = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().CanGetCloudRecordingStorageInfo();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, bCan);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingRecordingCtrlWrap::GetCloudRecordingStorageInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().GetCloudRecordingStorageInfo();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingRecordingCtrlWrap::GetRecordingManagementURL(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	//
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING recordingManagementURL = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().GetRecordingManagementURL();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(recordingManagementURL).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingRecordingCtrlWrap::CanGetRecordingManagementURL(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
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

	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().CanGetRecordingManagementURL(zn_bEnable);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "bCan", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_bEnable));

	args.GetReturnValue().Set(node);
}
void ZoomNodeSettingRecordingCtrlWrap::EnableSelectRecordFileLocationAfterMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().EnableSelectRecordFileLocationAfterMeeting(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingRecordingCtrlWrap::IsSelectRecordFileLocationAfterMeetingEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().IsSelectRecordFileLocationAfterMeetingEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingRecordingCtrlWrap::EnableMultiAudioStreamRecord(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().EnableMultiAudioStreamRecord(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingRecordingCtrlWrap::IsMultiAudioStreamRecordEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().IsMultiAudioStreamRecordEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingRecordingCtrlWrap::EnableAddTimestampWatermark(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().EnableAddTimestampWatermark(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingRecordingCtrlWrap::IsAddTimestampWatermarkEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().IsAddTimestampWatermarkEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingRecordingCtrlWrap::EnableOptimizeFor3rdPartyVideoEditor(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().EnableOptimizeFor3rdPartyVideoEditor(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingRecordingCtrlWrap::IsOptimizeFor3rdPartyVideoEditorEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().IsOptimizeFor3rdPartyVideoEditorEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingRecordingCtrlWrap::EnableShowVideoThumbnailWhenShare(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().EnableShowVideoThumbnailWhenShare(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingRecordingCtrlWrap::IsShowVideoThumbnailWhenShareEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().IsShowVideoThumbnailWhenShareEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingRecordingCtrlWrap::EnablePlaceVideoNextToShareInRecord(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().EnablePlaceVideoNextToShareInRecord(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingRecordingCtrlWrap::IsPlaceVideoNextToShareInRecordEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().IsPlaceVideoNextToShareInRecordEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnabled);
	args.GetReturnValue().Set(bret);
}