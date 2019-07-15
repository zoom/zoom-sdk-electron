
#include "../setting_general_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "zoom_native_to_wrap.h"



ZSettingGeneralWrap::ZSettingGeneralWrap()
{
	
}
ZSettingGeneralWrap::~ZSettingGeneralWrap()
{
	Uninit();
}
void ZSettingGeneralWrap::Init()
{
	
}
void ZSettingGeneralWrap::Uninit()
{
	
}
ZNSDKError ZSettingGeneralWrap::EnableDualScreenMode(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetGeneralSettings()->EnableDualScreenMode(bEnable));
}
ZNSDKError ZSettingGeneralWrap::TurnOffAeroModeInSharing(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetGeneralSettings()->TurnOffAeroModeInSharing(bEnable));
}
ZNSDKError ZSettingGeneralWrap::EnableAutoFitToWindowWhenViewSharing(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetGeneralSettings()->EnableAutoFitToWindowWhenViewSharing(bEnable));
}
ZNSDKError ZSettingGeneralWrap::EnableAutoFullScreenVideoWhenJoinMeeting(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetGeneralSettings()->EnableAutoFullScreenVideoWhenJoinMeeting(bEnable));
}
ZNSDKError ZSettingGeneralWrap::EnableSplitScreenMode(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetGeneralSettings()->EnableSplitScreenMode(bEnable));
}
bool ZSettingGeneralWrap::IsDualScreenModeEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetGeneralSettings()->IsDualScreenModeEnabled();
}
bool ZSettingGeneralWrap::IsAeroModeInSharingTurnOff()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetGeneralSettings()->IsAeroModeInSharingTurnOff();
}
bool ZSettingGeneralWrap::IsAutoFitToWindowWhenViewSharingEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetGeneralSettings()->IsAutoFitToWindowWhenViewSharingEnabled();
}
bool ZSettingGeneralWrap::IsAutoFullScreenVideoWhenJoinMeetingEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetGeneralSettings()->IsAutoFullScreenVideoWhenJoinMeetingEnabled();
}
bool ZSettingGeneralWrap::IsSplitScreenModeEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetGeneralSettings()->IsSplitScreenModeEnabled();
}