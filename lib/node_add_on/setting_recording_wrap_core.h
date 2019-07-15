#pragma once
#include "zoom_native_sdk_wrap_core_def.h"

class ZSettingRecordingWrap
{
public:
	ZSettingRecordingWrap();
	virtual ~ZSettingRecordingWrap();
	void Init();
	void Uninit();

	ZNSDKError SetRecordingPath(ZoomSTRING szPath);
	ZoomSTRING GetRecordingPath();

};
