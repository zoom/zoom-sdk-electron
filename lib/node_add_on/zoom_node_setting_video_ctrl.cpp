#include "zoom_node_setting_video_ctrl.h"

ZoomNodeSettingVideoCtrlWrap::ZoomNodeSettingVideoCtrlWrap()
{

}

ZoomNodeSettingVideoCtrlWrap::~ZoomNodeSettingVideoCtrlWrap()
{

}
void ZoomNodeSettingVideoCtrlWrap::SelectVideoCamera(const v8::FunctionCallbackInfo<v8::Value>& args)
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
	ZoomSTRING zn_deviceId;
	zoom_v8toc(args[0].As<v8::String>(), zn_deviceId);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().SelectCamera(zn_deviceId);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsMirrorEffectEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bDisable = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsVideoMirrorEffectEnable();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bDisable);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::GetCameraList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNList<ZNCameraInfo> zn_cameraInfoLst = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().GetCameraList();

	v8::HandleScope scope(isolate);
	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_cameraInfoLst.size(); ++i) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(v8::String::NewFromUtf8(isolate, "deviceId"), v8::String::NewFromUtf8(isolate, zs2s(zn_cameraInfoLst[i].deviceId).c_str()));
		node->Set(v8::String::NewFromUtf8(isolate, "deviceName"), v8::String::NewFromUtf8(isolate, zs2s(zn_cameraInfoLst[i].deviceName).c_str()));
		node->Set(v8::String::NewFromUtf8(isolate, "isSelected"), v8::Boolean::New(isolate, zn_cameraInfoLst[i].isSelectedDevice));
		nodes->Set(i, node);
	}

	args.GetReturnValue().Set(nodes);
}
void ZoomNodeSettingVideoCtrlWrap::EnableVideoMirrorEffect(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableVideoMirrorEffect(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableFaceBeautyEffect(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableFaceBeautyEffect(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsFaceBeautyEffectEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bDisable = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsFaceBeautyEffectEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bDisable);
	args.GetReturnValue().Set(bret);
}


