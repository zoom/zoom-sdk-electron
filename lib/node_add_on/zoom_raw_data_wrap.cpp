#include "zoom_raw_data_wrap.h"
#ifdef _WIN32
#else
#import "../../sdk/mac/ZoomSDK/ZoomSDK.framework/Versions/A/Headers/zoom_sdk_raw_data_helper_interface.h"
#endif // _WIN32

SDKRawDataError Node_HasRawDataLicense()
{
#ifdef _WIN32
	typedef SDKRawDataError(*fnHasRawDataLicense)();
	static fnHasRawDataLicense pfnHasRawDataLicense = NULL;
	if (NULL == pfnHasRawDataLicense)
	{
		HMODULE hmod = GetModuleHandleA("sdk.dll");
		pfnHasRawDataLicense = (fnHasRawDataLicense)GetProcAddress(hmod, "HasRawDataLicense");
	}
	if (NULL == pfnHasRawDataLicense)
		return SDKRawDataError_UNINITIALIZED;

	return pfnHasRawDataLicense();
#else
	return HasRawDataLicense();
#endif
}
SDKRawDataError Node_RetrieveAudioRawDataChannel(IAudioRawDataChannel** pp_channel)
{
#ifdef _WIN32
	typedef SDKRawDataError(*fnRetrieveAudioRawDataChannel)(IAudioRawDataChannel** pp_channel);
	static fnRetrieveAudioRawDataChannel pfnRetrieveAudioRawDataChannel = NULL;
	if (NULL == pfnRetrieveAudioRawDataChannel)
	{
		HMODULE hmod = GetModuleHandleA("sdk.dll");
		pfnRetrieveAudioRawDataChannel = (fnRetrieveAudioRawDataChannel)GetProcAddress(hmod, "RetrieveAudioRawDataChannel");
	}
	if (NULL == pfnRetrieveAudioRawDataChannel)
		return SDKRawDataError_UNINITIALIZED;

	return pfnRetrieveAudioRawDataChannel(pp_channel);
#else
	return RetrieveAudioRawDataChannel(pp_channel);
#endif
}
SDKRawDataError Node_RetrieveVideoRawDataChannel(IVideoRawDataChannel** pp_channel)
{
#ifdef _WIN32
	typedef SDKRawDataError(*fnRetrieveVideoRawDataChannel)(IVideoRawDataChannel** pp_channel);
	static fnRetrieveVideoRawDataChannel pfnRetrieveVideoRawDataChannel = NULL;
	if (NULL == pfnRetrieveVideoRawDataChannel)
	{
		HMODULE hmod = GetModuleHandleA("sdk.dll");
		pfnRetrieveVideoRawDataChannel = (fnRetrieveVideoRawDataChannel)GetProcAddress(hmod, "RetrieveVideoRawDataChannel");
	}
	if (NULL == pfnRetrieveVideoRawDataChannel)
		return SDKRawDataError_UNINITIALIZED;

	return pfnRetrieveVideoRawDataChannel(pp_channel);
#else
	return RetrieveVideoRawDataChannel(pp_channel);
#endif
}
SDKRawDataError Node_RetrieveShareRawDataChannel(IShareRawDataChannel** pp_channel)
{
#ifdef _WIN32
	typedef SDKRawDataError(*fnRetrieveShareRawDataChannel)(IShareRawDataChannel** pp_channel);
	static fnRetrieveShareRawDataChannel pfnRetrieveShareRawDataChannel = NULL;
	if (NULL == pfnRetrieveShareRawDataChannel)
	{
		HMODULE hmod = GetModuleHandleA("sdk.dll");
		pfnRetrieveShareRawDataChannel = (fnRetrieveShareRawDataChannel)GetProcAddress(hmod, "RetrieveShareRawDataChannel");
	}
	if (NULL == pfnRetrieveShareRawDataChannel)
		return SDKRawDataError_UNINITIALIZED;

	return pfnRetrieveShareRawDataChannel(pp_channel);
#else
	return RetrieveShareRawDataChannel(pp_channel);
#endif
}
