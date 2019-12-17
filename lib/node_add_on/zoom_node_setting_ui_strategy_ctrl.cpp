#include "zoom_node_setting_ui_strategy_ctrl.h"


ZoomNodeSettingUIStrategyCtrlWrap::ZoomNodeSettingUIStrategyCtrlWrap()
{

}

ZoomNodeSettingUIStrategyCtrlWrap::~ZoomNodeSettingUIStrategyCtrlWrap()
{

}
void ZoomNodeSettingUIStrategyCtrlWrap::DisableAdvancedFeatures4GeneralSetting(const v8::FunctionCallbackInfo<v8::Value>& args)
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

	bool zn_bDisable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bDisable);

	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetSettingServiceWrap().GetSettingStrategyCtrl().DisableAdvancedFeatures4GeneralSetting(zn_bDisable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingUIStrategyCtrlWrap::DisableAccountSettingTabPage(const v8::FunctionCallbackInfo<v8::Value>& args)
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

	bool zn_bDisable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bDisable);

	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetSettingServiceWrap().GetSettingStrategyCtrl().DisableAccountSettingTabPage(zn_bDisable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingUIStrategyCtrlWrap::ConfSettingDialogShownTabPage(const v8::FunctionCallbackInfo<v8::Value>& args)
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
	unsigned long zn_showOption = (unsigned long)args[0].As<v8::Integer >()->Value();

	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetSettingServiceWrap().GetSettingStrategyCtrl().ConfSettingDialogShownTabPage(zn_showOption);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
