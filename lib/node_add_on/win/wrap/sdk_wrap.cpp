#include "sdk_wrap.h"
#include "sdk_loader.h"
BEGIN_ZOOM_SDK_NAMESPACE
CSDKWrap& CSDKWrap::GetInst()
{
	static CSDKWrap wrap;
	return wrap;
}

SDKError CSDKWrap::InitSDK(const wchar_t* sdkpath, InitParam& initParam)
{
	SDKError sdkerr(SDKERR_MODULE_LOAD_FAILED);
	do 
	{
		std::wstring path = sdkpath ? sdkpath : L"";
		if (!CSDKImpl::GetInst().ConfigSDKModule(path))
		{
			break;
		}
		CSDKExtWrap::GetInst().GetCustomizedResourceHelperWrap().ApplyAll();
		sdkerr = CSDKImpl::GetInst().InitSDK(initParam);
	} while (false);

	return sdkerr;
}

SDKError CSDKWrap::CleanUPSDK()
{
	return CSDKImpl::GetInst().CleanUPSDK();
}

const wchar_t* CSDKWrap::GetVersion()
{
	return CSDKImpl::GetInst().GetVersion();
}

IAuthServiceWrap& CSDKWrap::GetAuthServiceWrap()
{
	return IAuthServiceWrap::GetInst();
}

IMeetingServiceWrap& CSDKWrap::GetMeetingServiceWrap()
{
	return IMeetingServiceWrap::GetInst();
}

ICalenderServiceWrap& CSDKWrap::GetCalenderServiceWrap()
{
	return ICalenderServiceWrap::GetInst();
}

IPreMeetingServiceWrap& CSDKWrap::GetPreMeetingServiceWrap()
{
	return IPreMeetingServiceWrap::GetInst();
}

ISettingServiceWrap& CSDKWrap::GetSettingServiceWrap()
{
	return ISettingServiceWrap::GetInst();
}

IZoomSDKVideoSourceHelperWrap& CSDKWrap::GetRawdataVideoSourceHelperWrap()
{
	return IZoomSDKVideoSourceHelperWrap::GetInst();
}

IZoomSDKAudioRawDataHelperWrap& CSDKWrap::GetAudioRawdataHelperWrap()
{
	return IZoomSDKAudioRawDataHelperWrap::GetInst();
}

INetworkConnectionHelperWrap& CSDKWrap::GetNetworkConnectionHelperWrap()
{
	return INetworkConnectionHelperWrap::GetInst();
}

CSDKWrap::CSDKWrap()
{
}
/////////////////////////////////////////////////////////////////////
CSDKExtWrap::CSDKExtWrap()
{

}

CSDKExtWrap& CSDKExtWrap::GetInst()
{
	static CSDKExtWrap inst;
	return inst;
}

IUIHookerWrap& CSDKExtWrap::GetUIHookerWrap()
{
	return IUIHookerWrap::GetInst();
}

IEmbeddedBrowserWrap* CSDKExtWrap::CreateEmbeddedBrowserWrap(HWND hwnd)
{
	IEmbeddedBrowserWrap* pObj(NULL);
	if (hwnd)
	{
		pObj = new IEmbeddedBrowserWrap;
		if (pObj)
		{
			pObj->Init(hwnd);
		}
	}
	
	return pObj;
}

void CSDKExtWrap::DestroyEmbeddedBrowserWrap(IEmbeddedBrowserWrap* pObj)
{
	if (pObj)
	{
		pObj->Uninit();
		delete pObj;
	}
}

ICustomizedResourceHelperWrap& CSDKExtWrap::GetCustomizedResourceHelperWrap()
{
	return ICustomizedResourceHelperWrap::GetInst();
}

/////////////////////////////////////////////////////////////////////
CSDKCustomizedUIWrap::CSDKCustomizedUIWrap()
{

}

CSDKCustomizedUIWrap& CSDKCustomizedUIWrap::GetInst()
{
	static CSDKCustomizedUIWrap inst;
	return inst;
}

ICustomizedUIMgrWrap& CSDKCustomizedUIWrap::GetCustomizedUIMgrWrap()
{
	return ICustomizedUIMgrWrap::GetInst();
}
/////////////////////////////////////////////////////////////////////////
CSDKRendererWrap::CSDKRendererWrap()
{

}

CSDKRendererWrap& CSDKRendererWrap::GetInst()
{
	static CSDKRendererWrap inst;
	return inst;
}

IZoomSDKRendererWrap& CSDKRendererWrap::GetRendererWrap()
{
	return IZoomSDKRendererWrap::GetInst();
}


END_ZOOM_SDK_NAMESPACE