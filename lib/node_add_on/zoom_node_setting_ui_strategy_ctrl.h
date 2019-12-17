#ifndef _ZOOM_NODE_SETTING_UI_STRATEGY_CTRL_H_
#define _ZOOM_NODE_SETTING_UI_STRATEGY_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeSettingUIStrategyCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingUIStrategyCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingUIStrategyCtrlWrap >;
private:
	ZoomNodeSettingUIStrategyCtrlWrap();
	~ZoomNodeSettingUIStrategyCtrlWrap();
public:
	/// \brief Hide the link to check the advanced settings on the General Setting page or not.
	/// \param 1.bDisable(bool) TRUE indicates to hide the link.
	static void DisableAdvancedFeatures4GeneralSetting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Hide the Account Setting page or not.
	/// \param 1.bDisable(bool) TRUE indicates to hide the account setting page.
	static void DisableAccountSettingTabPage(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Custome the tab page show or hide
	/// \param 1. settingDlgShowTabPageOption(number) Every bit indicates whether to show a certain tab page.
	/// Form right to left, every bit indicates as:
	/// bit 1: indicates whether to show virtual background page. "1" show, "0" not show.
	/// bit 2: indicates to whether to show video page. "1" show, "0" not show.
	/// bit 3: indicates to whether to show staticstics page. "1" show, "0" not show.
	/// bit 4: indicates to whether to show recording page. "1" show, "0" not show.
	/// bit 5: indicates to whether to show general page. "1" show, "0" not show.
	/// bit 6: indicates to whether to show feed back page. "1" show, "0" not show.
	/// bit 7: indicates to whether to show audio page. "1" show, "0" not show.
	/// bit 8: indicates to whether to show advance feature page. "1" show, "0" not show.
	/// bit 9: indicates to whether to show accessibility page. "1" show, "0" not show.
	static void ConfSettingDialogShownTabPage(const v8::FunctionCallbackInfo<v8::Value>& args);
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingUIStrategyCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingUIStrategyCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableAdvancedFeatures4GeneralSetting", ZoomNodeSettingUIStrategyCtrlWrap::DisableAdvancedFeatures4GeneralSetting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableAccountSettingTabPage", ZoomNodeSettingUIStrategyCtrlWrap::DisableAccountSettingTabPage);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ConfSettingDialogShownTabPage", ZoomNodeSettingUIStrategyCtrlWrap::ConfSettingDialogShownTabPage);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingUIStrategyCtrlWrap >() {
	return &ZoomNodeSettingUIStrategyCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
