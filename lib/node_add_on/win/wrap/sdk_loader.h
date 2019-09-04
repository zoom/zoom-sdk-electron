#pragma once
#include "common_include.h"
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnInitSDK)(ZOOM_SDK_NAMESPACE::InitParam& initParam);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnCreateMeetingService)(ZOOM_SDK_NAMESPACE::IMeetingService** ppMeetingService);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnDestroyMeetingService)(ZOOM_SDK_NAMESPACE::IMeetingService* pMeetingService);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnCreateAuthService)(ZOOM_SDK_NAMESPACE::IAuthService** ppAuthService);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnDestroyAuthService)(ZOOM_SDK_NAMESPACE::IAuthService* pAuthService);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnCreateSettingService)(ZOOM_SDK_NAMESPACE::ISettingService** ppSettingService);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnDestroySettingService)(ZOOM_SDK_NAMESPACE::ISettingService* pSettingService);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnCreateCalenderService)(ZOOM_SDK_NAMESPACE::ICalenderService** ppCalenderService);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnDestroyCalenderService)(ZOOM_SDK_NAMESPACE::ICalenderService* pCalenderService);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnCreatePreMeetingService)(ZOOM_SDK_NAMESPACE::IPreMeetingService** ppPreMeetingService);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnDestroyPreMeetingService)(ZOOM_SDK_NAMESPACE::IPreMeetingService* pPreMeetingService);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnCreateNetworkConnectionHelper)(ZOOM_SDK_NAMESPACE::INetworkConnectionHelper** ppNetworkHelper);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnDestroyNetworkConnectionHelper)(ZOOM_SDK_NAMESPACE::INetworkConnectionHelper* pNetworkHelper);
typedef const wchar_t*(*fnGetVersion)();
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnCleanUPSDK)();
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnCreateEmbeddedBrowser)(ZOOM_SDK_NAMESPACE::IEmbeddedBrowser** ppEmbeddedBrowser, HWND hwnd);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnDestroyEmbeddedBrowser)(ZOOM_SDK_NAMESPACE::IEmbeddedBrowser* pEmbeddedBrowser);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnRetrieveUIHooker)(ZOOM_SDK_NAMESPACE::IUIHooker** ppUIHooker);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnRetrieveCustomizedResourceHelper)(ZOOM_SDK_NAMESPACE::ICustomizedResourceHelper** ppCustomizedResourceHelper);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnCreateCustomizedUIMgr)(ZOOM_SDK_NAMESPACE::ICustomizedUIMgr** ppCustomizedUIMgr);
typedef ZOOM_SDK_NAMESPACE::SDKError(*fnDestroyCustomizedUIMgr)(ZOOM_SDK_NAMESPACE::ICustomizedUIMgr* pCustomizedUIMgr);

typedef ZOOM_RAWDATA_NAMESPACE::SDKRawDataError(*fnRetrieveAudioRawDataChannel)(ZOOM_RAWDATA_NAMESPACE::IAudioRawDataChannel** ppAudioRawDataChannel);
typedef ZOOM_RAWDATA_NAMESPACE::SDKRawDataError(*fnRetrieveVideoRawDataChannel)(ZOOM_RAWDATA_NAMESPACE::IVideoRawDataChannel** ppVideoRawDataChannel);
typedef ZOOM_RAWDATA_NAMESPACE::SDKRawDataError(*fnRetrieveShareRawDataChannel)(ZOOM_RAWDATA_NAMESPACE::IShareRawDataChannel** ppShareRawDataChannel);
typedef ZOOM_RAWDATA_NAMESPACE::SDKRawDataError(*fnHasRawDataLicense)();

class CSDKImpl
{
public:
	virtual ~CSDKImpl();
	static CSDKImpl& GetInst();

	bool ConfigSDKModule(std::wstring& path);
	void Uninit();
	//
	virtual	ZOOM_SDK_NAMESPACE::SDKError InitSDK(ZOOM_SDK_NAMESPACE::InitParam& initParam);
	virtual ZOOM_SDK_NAMESPACE::SDKError CreateMeetingService(ZOOM_SDK_NAMESPACE::IMeetingService** ppMeetingService);
	virtual ZOOM_SDK_NAMESPACE::SDKError DestroyMeetingService(ZOOM_SDK_NAMESPACE::IMeetingService* pMeetingService);
	virtual ZOOM_SDK_NAMESPACE::SDKError CreateAuthService(ZOOM_SDK_NAMESPACE::IAuthService** ppAuthService);
	virtual ZOOM_SDK_NAMESPACE::SDKError DestroyAuthService(ZOOM_SDK_NAMESPACE::IAuthService* pAuthService);
	virtual ZOOM_SDK_NAMESPACE::SDKError CreateSettingService(ZOOM_SDK_NAMESPACE::ISettingService** ppSettingService);
	virtual ZOOM_SDK_NAMESPACE::SDKError DestroySettingService(ZOOM_SDK_NAMESPACE::ISettingService* pSettingService);
	virtual ZOOM_SDK_NAMESPACE::SDKError CreateCalenderService(ZOOM_SDK_NAMESPACE::ICalenderService** ppCalenderService);
	virtual ZOOM_SDK_NAMESPACE::SDKError DestroyCalenderService(ZOOM_SDK_NAMESPACE::ICalenderService* pCalenderService);
	virtual ZOOM_SDK_NAMESPACE::SDKError(CreatePreMeetingService)(ZOOM_SDK_NAMESPACE::IPreMeetingService** ppPreMeetingService);
	virtual ZOOM_SDK_NAMESPACE::SDKError(DestroyPreMeetingService)(ZOOM_SDK_NAMESPACE::IPreMeetingService* pPreMeetingService);
	virtual ZOOM_SDK_NAMESPACE::SDKError(CreateNetworkConnectionHelper)(ZOOM_SDK_NAMESPACE::INetworkConnectionHelper** ppNetworkHelper);
	virtual ZOOM_SDK_NAMESPACE::SDKError(DestroyNetworkConnectionHelper)(ZOOM_SDK_NAMESPACE::INetworkConnectionHelper* pNetworkHelper);
	virtual const wchar_t*(GetVersion)();
	virtual ZOOM_SDK_NAMESPACE::SDKError CleanUPSDK();
	virtual ZOOM_SDK_NAMESPACE::SDKError(CreateEmbeddedBrowser)(ZOOM_SDK_NAMESPACE::IEmbeddedBrowser** ppEmbeddedBrowser, HWND hwnd);
	virtual ZOOM_SDK_NAMESPACE::SDKError(DestroyEmbeddedBrowser)(ZOOM_SDK_NAMESPACE::IEmbeddedBrowser* pEmbeddedBrowser);
	virtual ZOOM_SDK_NAMESPACE::SDKError(RetrieveUIHooker)(ZOOM_SDK_NAMESPACE::IUIHooker** ppUIHooker);
	virtual ZOOM_SDK_NAMESPACE::SDKError(RetrieveCustomizedResourceHelper)(ZOOM_SDK_NAMESPACE::ICustomizedResourceHelper** ppCustomizedResourceHelper);
	virtual ZOOM_SDK_NAMESPACE::SDKError(CreateCustomizedUIMgr)(ZOOM_SDK_NAMESPACE::ICustomizedUIMgr** ppCustomizedUIMgr);
	virtual ZOOM_SDK_NAMESPACE::SDKError(DestroyCustomizedUIMgr)(ZOOM_SDK_NAMESPACE::ICustomizedUIMgr* pCustomizedUIMgr);

	virtual ZOOM_SDK_NAMESPACE::SDKError(RetrieveAudioRawDataChannel)(ZOOM_RAWDATA_NAMESPACE::IAudioRawDataChannel** ppAudioRawDataChannel);
	virtual ZOOM_SDK_NAMESPACE::SDKError(RetrieveVideoRawDataChannel)(ZOOM_RAWDATA_NAMESPACE::IVideoRawDataChannel** ppVideoRawDataChannel);
	virtual ZOOM_SDK_NAMESPACE::SDKError(RetrieveShareRawDataChannel)(ZOOM_RAWDATA_NAMESPACE::IShareRawDataChannel** ppShareRawDataChannel);
	virtual ZOOM_SDK_NAMESPACE::SDKError(HasRawDataLicense)();
private:
	CSDKImpl();
	void Reset();
private:
	bool m_bInit;
	HMODULE m_hSdk;
	fnInitSDK m_fnInitSDK;
	fnCleanUPSDK m_fnCleanUPSDK;
	fnCreateMeetingService m_fnCreateMeetingService;
	fnDestroyMeetingService m_fnDestroyMeetingService;
	fnCreateAuthService m_fnCreateAuthService;
	fnDestroyAuthService m_fnDestroyAuthService;
	fnCreateSettingService m_fnCreateSettingService;
	fnDestroySettingService m_fnDestroySettingService;
	fnCreateCalenderService m_fnCreateCalenderService;
	fnDestroyCalenderService m_fnDestroyCalenderService;
	fnCreatePreMeetingService m_fnCreatePreMeetingService;
	fnDestroyPreMeetingService m_fnDestroyPreMeetingService;
	fnCreateNetworkConnectionHelper m_fnCreateNetworkConnectionHelper;
	fnDestroyNetworkConnectionHelper m_fnDestroyNetworkConnectionHelper;
	fnGetVersion m_fnGetVersion;
	fnCreateEmbeddedBrowser m_fnCreateEmbeddedBrowser;
	fnDestroyEmbeddedBrowser m_fnDestroyEmbeddedBrowser;
	fnRetrieveUIHooker m_fnRetrieveUIHooker;
	fnRetrieveCustomizedResourceHelper m_fnRetrieveCustomizedResouceHelper;
	fnCreateCustomizedUIMgr m_fnCreateCustomizedUIMgr;
	fnDestroyCustomizedUIMgr m_fnDestroyCustomizedUIMgr;

	fnRetrieveAudioRawDataChannel m_fnRetrieveAudioRawDataChannel;
	fnRetrieveVideoRawDataChannel m_fnRetrieveVideoRawDataChannel;
	fnRetrieveShareRawDataChannel m_fnRetrieveShareRawDataChannel;
	fnHasRawDataLicense	m_fnHasRawDataLicense;
};