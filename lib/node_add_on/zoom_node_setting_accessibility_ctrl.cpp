#include "zoom_node_setting_accessibility_ctrl.h"


ZoomNodeSettingAccessibilityCtrlWrap::ZoomNodeSettingAccessibilityCtrlWrap()
{

}

ZoomNodeSettingAccessibilityCtrlWrap::~ZoomNodeSettingAccessibilityCtrlWrap()
{

}
void ZoomNodeSettingAccessibilityCtrlWrap::EnableAlwaysShowMeetingControls(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableAlwaysShowMeetingControlsParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableAlwaysShowMeetingControlsParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _zn_bEnable = false;
		convertBool(proto_params.benable(), _zn_bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingAccessibilityCtrl().EnableAlwaysShowMeetingControls(_zn_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingAccessibilityCtrlWrap::IsAlwaysShowMeetingControlsEnable(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	bool zn_bEnable = false;
	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingAccessibilityCtrl().IsAlwaysShowMeetingControlsEnable(zn_bEnable);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "bEnable", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_bEnable));

	args.GetReturnValue().Set(node);
}

