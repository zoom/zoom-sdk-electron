#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"

class ZSettingVideoWrap
{
public:
	ZSettingVideoWrap();
	virtual ~ZSettingVideoWrap();
	void Init();
	void Uninit();

	ZNSDKError SelectCamera(ZoomSTRING deviceId);
	ZNList<ZNCameraInfo> GetCameraList();
	ZNSDKError EnableVideoMirrorEffect(bool bEnable);
	ZNSDKError EnableFaceBeautyEffect(bool bEnable);
	bool IsVideoMirrorEffectEnable();
	bool IsFaceBeautyEffectEnabled();

	////////////////////////////////////////////////////////////////////////////////
	void SetSink(ZNativeSDKVideoSettingContextWrapSink* pSink);
	ZNSDKError EnableHDVideo(bool bEnable);
	bool IsHDVideoEnabled();
	ZNSDKError EnableAlwaysShowNameOnVideo(bool bEnable);
	bool IsAlwaysShowNameOnVideoEnabled();
	ZNSDKError EnableAutoTurnOffVideoWhenJoinMeeting(bool bEnable);
	bool IsAutoTurnOffVideoWhenJoinMeetingEnabled();
	ZNSDKError EnableAlwaysUse16v9(bool bEnable);
	bool IsAlwaysUse16v9();
	ZNSDKError EnableSpotlightSelf(bool bEnable);
	bool IsSpotlightSelfEnabled();
	ZNSDKError EnableHardwareEncode(bool bEnable);
	bool IsHardwareEncodeEnabled();
	ZNSDKError Enable49VideoesInGallaryView(bool bEnable);
	bool Is49VideoesInGallaryViewEnabled();
	ZNSDKError EnableHideNoVideoUsersOnWallView(bool bEnable);
	bool IsHideNoVideoUsersOnWallViewEnabled();

	//callback
	void onComputerCamDeviceChanged(ZNList<ZNCameraInfo> newCameraList);
	void onDefaultCamDeviceChanged(ZoomSTRING deviceId, ZoomSTRING deviceName);

private:
	ZNativeSDKVideoSettingContextWrapSink* m_pSink;
};
