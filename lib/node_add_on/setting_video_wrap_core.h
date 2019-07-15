#pragma once
#include "zoom_native_sdk_wrap_core_def.h"

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

};
