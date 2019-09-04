
#include "../setting_recording_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "zoom_native_to_wrap.h"

ZSettingRecordingWrap::ZSettingRecordingWrap()
{

}
ZSettingRecordingWrap::~ZSettingRecordingWrap()
{
	Uninit();
}
void ZSettingRecordingWrap::Init()
{

}
void ZSettingRecordingWrap::Uninit()
{

}
ZNSDKError ZSettingRecordingWrap::SetRecordingPath(ZoomSTRING szPath)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().SetRecordingPath(szPath.c_str()));
}
ZoomSTRING ZSettingRecordingWrap::GetRecordingPath()
{
	ZoomSTRING zn_szPath;
	zn_szPath = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().GetRecordingPath();
	return zn_szPath;
}