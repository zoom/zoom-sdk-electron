
#include "../customized_resource_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "zoom_native_to_wrap.h"



ZCustomizedResourceWrap::ZCustomizedResourceWrap()
{
	
}
ZCustomizedResourceWrap::~ZCustomizedResourceWrap()
{
	Uninit();
}
void ZCustomizedResourceWrap::Init()
{
	
}
void ZCustomizedResourceWrap::Uninit()
{
	
}
ZNSDKError ZCustomizedResourceWrap::AddCustomizedPictureResource(ZoomSTRING strPNGID, ZoomSTRING strPNGPath)
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	ZOOM_SDK_NAMESPACE::ICustomizedResourceHelperWrap& customResourceWrap = ZOOM_SDK_NAMESPACE::CSDKExtWrap::GetInst().GetCustomizedResourceHelperWrap();
	sdkerr = customResourceWrap.GetInst().AddCustomizedPictureResource(strPNGID.c_str(), strPNGPath.c_str());
	return Map2WrapDefine(sdkerr);
}
ZNSDKError ZCustomizedResourceWrap::AddCustomizedStringResource(ZNSDKCustomizedStringType customizedType, ZoomSTRING strCustomizedString)
{
	ZOOM_SDK_NAMESPACE::SDKCustomizedStringType nCustomizedType = Map2SDKDefine(customizedType);
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	ZOOM_SDK_NAMESPACE::ICustomizedResourceHelperWrap& customResourceWrap = ZOOM_SDK_NAMESPACE::CSDKExtWrap::GetInst().GetCustomizedResourceHelperWrap();

	sdkerr = customResourceWrap.GetInst().AddCustomizedStringResource(nCustomizedType, strCustomizedString.c_str());
	return Map2WrapDefine(sdkerr);
}
ZNSDKError ZCustomizedResourceWrap::AddCustomizedURLResource(ZNSDKCustomizedURLType customizedType, ZoomSTRING strCustomizedURL)
{
	ZOOM_SDK_NAMESPACE::SDKCustomizedURLType nCustomizedType = Map2SDKDefine(customizedType);
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	ZOOM_SDK_NAMESPACE::ICustomizedResourceHelperWrap& customResourceWrap = ZOOM_SDK_NAMESPACE::CSDKExtWrap::GetInst().GetCustomizedResourceHelperWrap();

	sdkerr = customResourceWrap.GetInst().AddCustomizedURLResource(nCustomizedType, strCustomizedURL.c_str());
	return Map2WrapDefine(sdkerr);
}