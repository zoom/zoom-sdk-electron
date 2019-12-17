
#include "../setting_accessibility_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "zoom_native_to_wrap.h"

ZSettingAccessibilityWrap::ZSettingAccessibilityWrap()
{
	
}
ZSettingAccessibilityWrap::~ZSettingAccessibilityWrap()
{
	Uninit();
}
void ZSettingAccessibilityWrap::Init()
{
	
}
void ZSettingAccessibilityWrap::Uninit()
{
	
}
ZNSDKError ZSettingAccessibilityWrap::EnableAlwaysShowMeetingControls(bool bEnable)
{
	ZNSDKError err = ZNSDKERR_UNKNOWN;
	ZOOM_SDK_NAMESPACE::IAccessibilitySettingContext* pAccessibilitySettingContext = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetAccessibilitySettings();
	if (pAccessibilitySettingContext)
	{
		err = Map2WrapDefine(pAccessibilitySettingContext->EnableAlwaysShowMeetingControls(bEnable));
	}
	return err;
}
ZNSDKError ZSettingAccessibilityWrap::IsAlwaysShowMeetingControlsEnable(bool& bEnable)
{
	ZNSDKError err = ZNSDKERR_UNKNOWN;
	ZOOM_SDK_NAMESPACE::IAccessibilitySettingContext* pAccessibilitySettingContext = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetAccessibilitySettings();
	if (pAccessibilitySettingContext)
	{
		err = Map2WrapDefine(pAccessibilitySettingContext->IsAlwaysShowMeetingControlsEnable(bEnable));
	}
	return err;
}
