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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::DisableAdvancedFeatures4GeneralSettingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::DisableAdvancedFeatures4GeneralSettingParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bdisable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bDisable = false;
		convertBool(proto_params.bdisable(), _bDisable);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetSettingServiceWrap().GetSettingStrategyCtrl().DisableAdvancedFeatures4GeneralSetting(_bDisable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingUIStrategyCtrlWrap::DisableAccountSettingTabPage(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::DisableAccountSettingTabPageParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::DisableAccountSettingTabPageParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bdisable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bDisable = false;
		convertBool(proto_params.bdisable(), _bDisable);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetSettingServiceWrap().GetSettingStrategyCtrl().DisableAccountSettingTabPage(_bDisable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingUIStrategyCtrlWrap::ConfSettingDialogShownTabPage(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::ConfSettingDialogShownTabPageParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ConfSettingDialogShownTabPageParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_showoption())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned long _zn_showOption = proto_params.showoption();

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetSettingServiceWrap().GetSettingStrategyCtrl().ConfSettingDialogShownTabPage(_zn_showOption);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
