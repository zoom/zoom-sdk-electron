#include "sdk_loader.h"
#include <string>

#define SDK_DLL _T("sdk.dll")
CSDKImpl::CSDKImpl()
{
	Reset();
}
CSDKImpl::~CSDKImpl()
{
	Reset();

#ifdef CSHARP_WRAP
	Uninit();
#endif
}

CSDKImpl& CSDKImpl::GetInst()
{
	static CSDKImpl ob;
	return ob;
}
void CSDKImpl::Reset()
{
	m_bInit = false;
	m_fnInitSDK = NULL;
	m_fnCleanUPSDK = NULL;
	m_fnCreateMeetingService = NULL;
	m_fnDestroyMeetingService = NULL;
	m_fnCreateAuthService = NULL;
	m_fnDestroyAuthService = NULL;
	m_fnCreateSettingService = NULL;
	m_fnDestroySettingService = NULL;
	m_fnCreateCalenderService = NULL;
	m_fnDestroyCalenderService = NULL;
	m_fnCreatePreMeetingService = NULL;
	m_fnDestroyPreMeetingService = NULL;
	m_fnCreateNetworkConnectionHelper = NULL;
	m_fnDestroyNetworkConnectionHelper = NULL;
	m_fnGetVersion = NULL;
	m_fnCreateEmbeddedBrowser = NULL;
	m_fnDestroyEmbeddedBrowser = NULL;
	m_fnRetrieveUIHooker = NULL;
	m_fnRetrieveCustomizedResouceHelper = NULL;
	m_fnCreateCustomizedUIMgr = NULL;
	m_fnDestroyCustomizedUIMgr = NULL;
	m_fnGetRawdataVideoSourceHelper = NULL;
	m_fnGetAudioRawdataHelper = NULL;
	m_fncreateRenderer = NULL;
	m_fndestroyRenderer = NULL;
	m_fnHasRawDataLicense = NULL;
	m_hSdk = NULL;
}

typedef BOOL (WINAPI *fnSetDllDirectoryW)(
	_In_opt_ const wchar_t* lpPathName
);

void dummyproc()
{
	int i = 0;
	int j = 100 / i;
	printf("%d", j);
}

bool CSDKImpl::ConfigSDKModule(std::wstring& path)
{
	do
	{
		if (m_bInit)
		{
			break;
		}
		fnSetDllDirectoryW pfnSetDllDirectory = (fnSetDllDirectoryW)GetProcAddress(GetModuleHandleA("kernel32.dll"), "SetDllDirectoryW");
		if (NULL == pfnSetDllDirectory)
		{
			pfnSetDllDirectory = (fnSetDllDirectoryW)GetProcAddress(GetModuleHandleA("kernelbase.dll"), "SetDllDirectoryW");
		}
		std::wstring strTmp(path);
		if (strTmp.empty())
		{
			strTmp.resize(MAX_PATH);
			HMODULE hSelfMod(NULL);
			GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCTSTR)dummyproc, &hSelfMod);
			GetModuleFileNameW(hSelfMod, const_cast<wchar_t*>(strTmp.c_str()), MAX_PATH);
			FreeLibrary(hSelfMod);
			strTmp.resize(strTmp.size());
// 			std::wstring::size_type pos = strTmp.find(L"\\\\?\\");
// 			if (0 == pos)
// 			{
// 				strTmp.erase(pos, 4);
// 			}
			
			myOutputDebugStringW(L"zoomsdk.node-path=%s", strTmp.c_str());
		}

		wchar_t drive[_MAX_DRIVE];
		wchar_t dir[_MAX_DIR];
		wchar_t fname[_MAX_FNAME];
		wchar_t ext[_MAX_EXT];
		_wsplitpath_s(strTmp.c_str(), drive, _MAX_DRIVE, dir, _MAX_DIR, fname, _MAX_FNAME, ext, _MAX_EXT);

		wchar_t szPath[MAX_PATH] = { 0 };
		_wmakepath_s(szPath, _MAX_PATH, drive, dir, NULL, NULL);
		if (pfnSetDllDirectory)
			pfnSetDllDirectory(szPath);
		
		wcscat_s(szPath, MAX_PATH, L"sdk.dll");
		m_hSdk = LoadLibraryW(szPath);
		if (NULL == m_hSdk)
		{
			myOutputDebugStringW(L"path=%s, loadlib error=%d", szPath, GetLastError());
			break;
		}

		m_fnInitSDK = (fnInitSDK)GetProcAddress(m_hSdk, "InitSDK");
		m_fnCleanUPSDK = (fnCleanUPSDK)GetProcAddress(m_hSdk, "CleanUPSDK");
		m_fnCreateMeetingService = (fnCreateMeetingService)GetProcAddress(m_hSdk, "CreateMeetingService");
		m_fnDestroyMeetingService = (fnDestroyMeetingService)GetProcAddress(m_hSdk, "DestroyMeetingService");
		m_fnCreateAuthService = (fnCreateAuthService)GetProcAddress(m_hSdk, "CreateAuthService");
		m_fnDestroyAuthService = (fnDestroyAuthService)GetProcAddress(m_hSdk, "DestroyAuthService");
		m_fnCreateSettingService = (fnCreateSettingService)GetProcAddress(m_hSdk, "CreateSettingService");
		m_fnDestroySettingService = (fnDestroySettingService)GetProcAddress(m_hSdk, "DestroySettingService");
		m_fnCreateCalenderService = (fnCreateCalenderService)GetProcAddress(m_hSdk, "CreateCalenderService");
		m_fnDestroyCalenderService = (fnDestroyCalenderService)GetProcAddress(m_hSdk, "DestroyCalenderService");

		m_fnCreatePreMeetingService = (fnCreatePreMeetingService)GetProcAddress(m_hSdk, "CreatePreMeetingService");
		m_fnDestroyPreMeetingService = (fnDestroyPreMeetingService)GetProcAddress(m_hSdk, "DestroyPreMeetingService");
		m_fnCreateNetworkConnectionHelper = (fnCreateNetworkConnectionHelper)GetProcAddress(m_hSdk, "CreateNetworkConnectionHelper");
		m_fnDestroyNetworkConnectionHelper = (fnDestroyNetworkConnectionHelper)GetProcAddress(m_hSdk, "DestroyNetworkConnectionHelper");
		m_fnGetVersion = (fnGetVersion)GetProcAddress(m_hSdk, "GetVersion");

		m_fnCreateEmbeddedBrowser = (fnCreateEmbeddedBrowser)GetProcAddress(m_hSdk, "CreateEmbeddedBrowser");
		m_fnDestroyEmbeddedBrowser = (fnDestroyEmbeddedBrowser)GetProcAddress(m_hSdk, "DestroyEmbeddedBrowser");
		m_fnRetrieveUIHooker = (fnRetrieveUIHooker)GetProcAddress(m_hSdk, "RetrieveUIHooker");
		m_fnRetrieveCustomizedResouceHelper = (fnRetrieveCustomizedResourceHelper)GetProcAddress(m_hSdk, "RetrieveCustomizedResourceHelper");
		
		m_fnCreateCustomizedUIMgr = (fnCreateCustomizedUIMgr)GetProcAddress(m_hSdk, "CreateCustomizedUIMgr");
		m_fnDestroyCustomizedUIMgr = (fnDestroyCustomizedUIMgr)GetProcAddress(m_hSdk, "DestroyCustomizedUIMgr");

		m_fnGetRawdataVideoSourceHelper = (fnGetRawdataVideoSourceHelper)GetProcAddress(m_hSdk, "GetRawdataVideoSourceHelper");
		m_fnGetAudioRawdataHelper = (fnGetAudioRawdataHelper)GetProcAddress(m_hSdk, "GetAudioRawdataHelper");
		m_fncreateRenderer = (fncreateRenderer)GetProcAddress(m_hSdk, "createRenderer");
		m_fndestroyRenderer = (fndestroyRenderer)GetProcAddress(m_hSdk, "destroyRenderer");
		m_fnHasRawDataLicense = (fnHasRawDataLicense)(GetProcAddress(m_hSdk, "HasRawdataLicense"));

		if (NULL == m_fnInitSDK
			|| NULL == m_fnCleanUPSDK
			|| NULL == m_fnCreateAuthService
			|| NULL == m_fnDestroyAuthService
			|| NULL == m_fnCreateMeetingService
			|| NULL == m_fnDestroyMeetingService
			|| NULL == m_fnCreateSettingService
			|| NULL == m_fnDestroySettingService
			|| NULL == m_fnCreateCalenderService
			|| NULL == m_fnDestroyCalenderService
			|| NULL == m_fnCreatePreMeetingService
			|| NULL == m_fnDestroyPreMeetingService
			|| NULL == m_fnCreateNetworkConnectionHelper
			|| NULL == m_fnDestroyNetworkConnectionHelper
			|| NULL == m_fnGetVersion
			|| NULL == m_fnCreateEmbeddedBrowser
			|| NULL == m_fnDestroyEmbeddedBrowser
			|| NULL == m_fnRetrieveUIHooker
			|| NULL == m_fnRetrieveCustomizedResouceHelper
			|| NULL == m_fnCreateCustomizedUIMgr
			|| NULL == m_fnDestroyCustomizedUIMgr
			|| NULL == m_fnGetRawdataVideoSourceHelper
			|| NULL == m_fnGetAudioRawdataHelper
			|| NULL == m_fncreateRenderer
			|| NULL == m_fndestroyRenderer
			|| NULL == m_fnHasRawDataLicense)
		{
			break;
		}
		m_bInit = true;
	} while (false);

	if (!m_bInit)
	{
		if (m_hSdk)
		{
			FreeLibrary(m_hSdk);
			Reset();
		}
	}

	return m_bInit;
}

void CSDKImpl::Uninit()
{
	myOutputDebugString("CSDKImpl::Uninit");
	if (m_hSdk)
	{
		FreeLibrary(m_hSdk);
	}
	Reset();
}

ZOOM_SDK_NAMESPACE::SDKError  CSDKImpl::InitSDK(ZOOM_SDK_NAMESPACE::InitParam& initParam)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnInitSDK)
	{
		ret = m_fnInitSDK(initParam);
	}

	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError CSDKImpl::CreateMeetingService(ZOOM_SDK_NAMESPACE::IMeetingService** ppMeetingService)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnCreateMeetingService)
	{
		ret = m_fnCreateMeetingService(ppMeetingService);
	}

	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError CSDKImpl::DestroyMeetingService(ZOOM_SDK_NAMESPACE::IMeetingService* pMeetingService)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnDestroyMeetingService)
	{
		ret = m_fnDestroyMeetingService(pMeetingService);
	}

	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError CSDKImpl::CreateAuthService(ZOOM_SDK_NAMESPACE::IAuthService** ppAuthService)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnCreateAuthService)
	{
		ret = m_fnCreateAuthService(ppAuthService);
	}

	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError CSDKImpl::DestroyAuthService(ZOOM_SDK_NAMESPACE::IAuthService* pAuthService)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnDestroyAuthService)
	{
		ret = m_fnDestroyAuthService(pAuthService);
	}

	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError CSDKImpl::CreateSettingService(ZOOM_SDK_NAMESPACE::ISettingService** ppSettingService)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnCreateSettingService)
	{
		ret = m_fnCreateSettingService(ppSettingService);
	}

	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError CSDKImpl::DestroySettingService(ZOOM_SDK_NAMESPACE::ISettingService* pSettingService)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnDestroySettingService)
	{
		ret = m_fnDestroySettingService(pSettingService);
	}

	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError CSDKImpl::CreateCalenderService(ZOOM_SDK_NAMESPACE::ICalenderService** ppCalenderService)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnCreateCalenderService)
	{
		ret = m_fnCreateCalenderService(ppCalenderService);
	}

	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError CSDKImpl::DestroyCalenderService(ZOOM_SDK_NAMESPACE::ICalenderService* pCalenderService)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnDestroyCalenderService)
	{
		ret = m_fnDestroyCalenderService(pCalenderService);
	}

	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError(CSDKImpl::CreatePreMeetingService)(ZOOM_SDK_NAMESPACE::IPreMeetingService** ppPreMeetingService)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnCreatePreMeetingService)
	{
		ret = m_fnCreatePreMeetingService(ppPreMeetingService);
	}

	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError(CSDKImpl::DestroyPreMeetingService)(ZOOM_SDK_NAMESPACE::IPreMeetingService* pPreMeetingService)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnDestroyPreMeetingService)
	{
		ret = m_fnDestroyPreMeetingService(pPreMeetingService);
	}

	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError(CSDKImpl::CreateNetworkConnectionHelper)(ZOOM_SDK_NAMESPACE::INetworkConnectionHelper** ppNetworkHelper)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnCreateNetworkConnectionHelper)
	{
		ret = m_fnCreateNetworkConnectionHelper(ppNetworkHelper);
	}

	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError(CSDKImpl::DestroyNetworkConnectionHelper)(ZOOM_SDK_NAMESPACE::INetworkConnectionHelper* pNetworkHelper)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnDestroyNetworkConnectionHelper)
	{
		ret = m_fnDestroyNetworkConnectionHelper(pNetworkHelper);
	}

	return ret;
}

const wchar_t*(CSDKImpl::GetVersion)()
{
	const wchar_t* ret(NULL);
	if (m_fnGetVersion)
	{
		ret = m_fnGetVersion();
	}

	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError CSDKImpl::CleanUPSDK()
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnCleanUPSDK)
	{
		ret = m_fnCleanUPSDK();
	}
	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError(CSDKImpl::CreateEmbeddedBrowser)(ZOOM_SDK_NAMESPACE::IEmbeddedBrowser** ppEmbeddedBrowser, HWND hwnd)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnCreateEmbeddedBrowser)
	{
		ret = m_fnCreateEmbeddedBrowser(ppEmbeddedBrowser, hwnd);
	}
	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError(CSDKImpl::DestroyEmbeddedBrowser)(ZOOM_SDK_NAMESPACE::IEmbeddedBrowser* pEmbeddedBrowser)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnDestroyEmbeddedBrowser)
	{
		ret = m_fnDestroyEmbeddedBrowser(pEmbeddedBrowser);
	}
	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError(CSDKImpl::RetrieveUIHooker)(ZOOM_SDK_NAMESPACE::IUIHooker** ppUIHooker)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnRetrieveUIHooker)
	{
		ret = m_fnRetrieveUIHooker(ppUIHooker);
	}
	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError(CSDKImpl::RetrieveCustomizedResourceHelper)(ZOOM_SDK_NAMESPACE::ICustomizedResourceHelper** ppCustomizedResourceHelper)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnRetrieveCustomizedResouceHelper)
	{
		ret = m_fnRetrieveCustomizedResouceHelper(ppCustomizedResourceHelper);
	}
	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError(CSDKImpl::CreateCustomizedUIMgr)(ZOOM_SDK_NAMESPACE::ICustomizedUIMgr** ppCustomizedUIMgr)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnCreateCustomizedUIMgr)
	{
		ret = m_fnCreateCustomizedUIMgr(ppCustomizedUIMgr);
	}
	return ret;
}

ZOOM_SDK_NAMESPACE::SDKError(CSDKImpl::DestroyCustomizedUIMgr)(ZOOM_SDK_NAMESPACE::ICustomizedUIMgr* pCustomizedUIMgr)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fnDestroyCustomizedUIMgr)
	{
		ret = m_fnDestroyCustomizedUIMgr(pCustomizedUIMgr);
	}
	return ret;
}

ZOOM_SDK_NAMESPACE::IZoomSDKVideoSourceHelper*(CSDKImpl::GetRawdataVideoSourceHelper)()
{
	if (m_fnGetRawdataVideoSourceHelper)
	{
		return m_fnGetRawdataVideoSourceHelper();
	}
	return NULL;
}
ZOOM_SDK_NAMESPACE::IZoomSDKAudioRawDataHelper* (CSDKImpl::GetAudioRawdataHelper)()
{
	if (m_fnGetAudioRawdataHelper)
	{
		return m_fnGetAudioRawdataHelper();
	}
	return NULL;
}
bool(CSDKImpl::HasRawDataLicense)()
{
	bool bHasLicence = false;
	if (m_fnHasRawDataLicense)
	{
		bHasLicence = m_fnHasRawDataLicense();
	}
	return bHasLicence;
}
ZOOM_SDK_NAMESPACE::SDKError(CSDKImpl::createRenderer)(ZOOM_SDK_NAMESPACE::IZoomSDKRenderer** ppRenderer, ZOOM_SDK_NAMESPACE::IZoomSDKRendererDelegate* pDelegate)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fncreateRenderer)
	{
		ret = m_fncreateRenderer(ppRenderer, pDelegate);
	}
	return ret;
}
ZOOM_SDK_NAMESPACE::SDKError(CSDKImpl::destroyRenderer)(ZOOM_SDK_NAMESPACE::IZoomSDKRenderer* pRenderer)
{
	ZOOM_SDK_NAMESPACE::SDKError ret(ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE);
	if (m_fndestroyRenderer)
	{
		ret = m_fndestroyRenderer(pRenderer);
	}
	return ret;
}

#if (!defined CSHARP_WRAP && !defined _LIB)
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		CSDKImpl::GetInst().Uninit();
		break;
	}
	return TRUE;
}
#endif