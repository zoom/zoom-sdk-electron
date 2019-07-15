#pragma once
#include "zoom_native_sdk_wrap_core_def.h"

class ZCustomizedResourceWrap
{
public:
	ZCustomizedResourceWrap();
	virtual ~ZCustomizedResourceWrap();
	void Init();
	void Uninit();

	ZNSDKError AddCustomizedPictureResource(ZoomSTRING strPNGID, ZoomSTRING strPNGPath);
	ZNSDKError AddCustomizedStringResource(ZNSDKCustomizedStringType customizedType, ZoomSTRING strCustomizedString);
	ZNSDKError AddCustomizedURLResource(ZNSDKCustomizedURLType customizedType, ZoomSTRING strCustomizedURL);
};
