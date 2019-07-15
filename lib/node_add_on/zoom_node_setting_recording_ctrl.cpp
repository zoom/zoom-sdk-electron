#include "zoom_node_setting_recording_ctrl.h"


ZoomNodeSettingRecordingCtrlWrap::ZoomNodeSettingRecordingCtrlWrap()
{

}

ZoomNodeSettingRecordingCtrlWrap::~ZoomNodeSettingRecordingCtrlWrap()
{

}
void ZoomNodeSettingRecordingCtrlWrap::SetRecordingPath(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(recordingPath).c_str());
	args.GetReturnValue().Set(bret);
}