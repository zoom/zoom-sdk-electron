#include "../zoom_native_raw_api_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/sdk_loader.h"
#include "zoom_native_to_wrap.h"

ZNativeRawAPIWrap::ZNativeRawAPIWrap()
{
	
}
ZNativeRawAPIWrap::~ZNativeRawAPIWrap()
{
	std::map<unsigned long long, ZNativeRawRenderWrap*>::iterator iter;
	for (iter = m_rawdatarender_map.begin(); iter != m_rawdatarender_map.end(); )
	{
		delete iter->second;
		m_rawdatarender_map.erase(iter++);
	}
	m_rawdatarender_map.clear();
}
bool ZNativeRawAPIWrap::HasRawDataLicense()
{
	return CSDKImpl::GetInst().HasRawDataLicense();
}
ZNSDKError ZNativeRawAPIWrap::InitAudioRawDataHelper()
{
	ZNSDKError err = ZNSDKERR_INTELNAL_ERROR;

	do
	{
		ZOOM_SDK_NAMESPACE::IZoomSDKAudioRawDataHelper* pTempNativeAudioRawDataHelper = CSDKImpl::GetInst().GetAudioRawdataHelper();
		if (!pTempNativeAudioRawDataHelper)
		{
			break;
		}
		m_audiorawdatawrap.SetNativeHelper(pTempNativeAudioRawDataHelper);
		err = ZNSDKERR_SUCCESS;
	} while (false);

	return err;
}
void ZNativeRawAPIWrap::GetRawdataVideoSourceHelper()
{

}
ZNSDKError ZNativeRawAPIWrap::CreateRenderer(unsigned long long recv_handle)
{
	ZNSDKError err = ZNSDKERR_INTELNAL_ERROR;

	do
	{
		std::map<unsigned long long, ZNativeRawRenderWrap*>::iterator iter = m_rawdatarender_map.find(recv_handle);
		if (m_rawdatarender_map.end() != iter)
		{
			err = ZNSDKERR_SUCCESS;
			break;
		}
		ZNativeRawRenderWrap* pRawDataRenderWrap = new ZNativeRawRenderWrap;
		if (!pRawDataRenderWrap)
		{
			break;
		}
		pRawDataRenderWrap->SetRecvHandle(recv_handle);
		ZOOM_SDK_NAMESPACE::IZoomSDKRenderer* pTempNativeRender = NULL;
		err = Map2WrapDefine(CSDKImpl::GetInst().createRenderer(&pTempNativeRender, pRawDataRenderWrap));
		if (!pTempNativeRender)
		{
			delete pRawDataRenderWrap;
			break;
		}
		pRawDataRenderWrap->SetNativeRender(pTempNativeRender);
		m_rawdatarender_map.insert(std::make_pair(recv_handle, pRawDataRenderWrap));

	} while (false);

	return err;
}
ZNSDKError ZNativeRawAPIWrap::DestroyRenderer(unsigned long long recv_handle)
{
	ZNSDKError err = ZNSDKERR_INTELNAL_ERROR;
	do 
	{
		std::map<unsigned long long, ZNativeRawRenderWrap*>::iterator iter = m_rawdatarender_map.find(recv_handle);
		if (m_rawdatarender_map.end() == iter)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNativeRawRenderWrap* pTempRenderWrap = (*iter).second;
		if (!pTempRenderWrap)
		{
			break;
		}
		ZOOM_SDK_NAMESPACE::IZoomSDKRenderer* pTempNativeRender = NULL;
		pTempNativeRender = pTempRenderWrap->GetNativeRender();
		err = Map2WrapDefine(CSDKImpl::GetInst().destroyRenderer(pTempNativeRender));
		//to make sure the object is deleted
		iter = m_rawdatarender_map.find(recv_handle);
		pTempRenderWrap = NULL;
		if (m_rawdatarender_map.end() != iter)
		{
			pTempRenderWrap = (*iter).second;
			if (pTempRenderWrap)
			{
				delete pTempRenderWrap;
				pTempRenderWrap = NULL;
				m_rawdatarender_map.erase(recv_handle);
			}
		}
	} while (false);

	return err;
}
ZNSDKError ZNativeRawAPIWrap::Subscribe(uint32_t userId, ZNZoomSDKRawDataType type, unsigned long long recv_handle)
{
	ZNSDKError err = ZNSDKERR_INTELNAL_ERROR;

	do
	{
		std::map<unsigned long long, ZNativeRawRenderWrap*>::iterator iter = m_rawdatarender_map.find(recv_handle);
		if (m_rawdatarender_map.end() == iter)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		ZNativeRawRenderWrap* pTempRenderWrap = (*iter).second;
		if (!pTempRenderWrap)
		{
			break;
		}
		ZOOM_SDK_NAMESPACE::IZoomSDKRenderer* pTempNativeRender = pTempRenderWrap->GetNativeRender();
		if (!pTempNativeRender)
		{
			break;
		}
		pTempRenderWrap->SetRawDataType(type);
		err = Map2WrapDefine(pTempNativeRender->subscribe(userId, Map2SDKDefine(type)));
	} while (false);

	return err;
}
ZNSDKError ZNativeRawAPIWrap::UnSubscribe(unsigned long long recv_handle)
{
	ZNSDKError err = ZNSDKERR_INTELNAL_ERROR;

	do
	{
		std::map<unsigned long long, ZNativeRawRenderWrap*>::iterator iter = m_rawdatarender_map.find(recv_handle);
		if (m_rawdatarender_map.end() == iter)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		ZNativeRawRenderWrap* pTempRenderWrap = (*iter).second;
		if (!pTempRenderWrap)
		{
			break;
		}
		ZOOM_SDK_NAMESPACE::IZoomSDKRenderer* pTempNativeRender = pTempRenderWrap->GetNativeRender();
		if (!pTempNativeRender)
		{
			break;
		}
		err = Map2WrapDefine(pTempNativeRender->unSubscribe());
	} while (false);
	//
	return err;
}
ZNSDKError ZNativeRawAPIWrap::SetRawDataResolution(ZNZoomSDKResolution resolution, unsigned long long recv_handle)
{
	ZNSDKError err = ZNSDKERR_INTELNAL_ERROR;

	do
	{
		std::map<unsigned long long, ZNativeRawRenderWrap*>::iterator iter = m_rawdatarender_map.find(recv_handle);
		if (m_rawdatarender_map.end() == iter)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		ZNativeRawRenderWrap* pTempRenderWrap = (*iter).second;
		if (!pTempRenderWrap)
		{
			break;
		}
		ZOOM_SDK_NAMESPACE::IZoomSDKRenderer* pTempNativeRender = pTempRenderWrap->GetNativeRender();
		if (!pTempNativeRender)
		{
			break;
		}
		err = Map2WrapDefine(pTempNativeRender->setRawDataResolution(Map2SDKDefine(resolution)));
	} while (false);

	return err;
}
ZNSDKError ZNativeRawAPIWrap::GetResolution(ZNZoomSDKResolution& resolution, unsigned long long recv_handle)
{
	ZNSDKError err = ZNSDKERR_INTELNAL_ERROR;
	do
	{
		std::map<unsigned long long, ZNativeRawRenderWrap*>::iterator iter = m_rawdatarender_map.find(recv_handle);
		if (m_rawdatarender_map.end() == iter)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		ZNativeRawRenderWrap* pTempRenderWrap = (*iter).second;
		if (!pTempRenderWrap)
		{
			break;
		}
		ZOOM_SDK_NAMESPACE::IZoomSDKRenderer* pTempNativeRender = pTempRenderWrap->GetNativeRender();
		if (!pTempNativeRender)
		{
			break;
		}
		resolution = (ZNZoomSDKResolution)pTempNativeRender->getResolution();
		err = ZNSDKERR_SUCCESS;
	} while (false);
	return err;
}
ZNSDKError ZNativeRawAPIWrap::GetRawDataType(ZNZoomSDKRawDataType& type, unsigned long long recv_handle)
{
	ZNSDKError err = ZNSDKERR_INTELNAL_ERROR;
	do
	{
		std::map<unsigned long long, ZNativeRawRenderWrap*>::iterator iter = m_rawdatarender_map.find(recv_handle);
		if (m_rawdatarender_map.end() == iter)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		ZNativeRawRenderWrap* pTempRenderWrap = (*iter).second;
		if (!pTempRenderWrap)
		{
			break;
		}
		ZOOM_SDK_NAMESPACE::IZoomSDKRenderer* pTempNativeRender = pTempRenderWrap->GetNativeRender();
		if (!pTempNativeRender)
		{
			break;
		}
		type = (ZNZoomSDKRawDataType)pTempNativeRender->getRawDataType();
		err = ZNSDKERR_SUCCESS;
	} while (false);
	return err;
}
ZNSDKError ZNativeRawAPIWrap::GetUserId(uint32_t& user_id, unsigned long long recv_handle)
{
	ZNSDKError err = ZNSDKERR_INTELNAL_ERROR;
	do
	{
		std::map<unsigned long long, ZNativeRawRenderWrap*>::iterator iter = m_rawdatarender_map.find(recv_handle);
		if (m_rawdatarender_map.end() == iter)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		ZNativeRawRenderWrap* pTempRenderWrap = (*iter).second;
		if (!pTempRenderWrap)
		{
			break;
		}
		ZOOM_SDK_NAMESPACE::IZoomSDKRenderer* pTempNativeRender = pTempRenderWrap->GetNativeRender();
		if (!pTempNativeRender)
		{
			break;
		}
		user_id = pTempNativeRender->getUserId();
		err = ZNSDKERR_SUCCESS;
	} while (false);
	return err;
}

ZNSDKError ZNativeRawAPIWrap::SubscribeAudioRawdata()
{
	ZNSDKError err = m_audiorawdatawrap.SubScribe();
	return err;
}

ZNSDKError ZNativeRawAPIWrap::UnSubscribeAudioRawdata()
{
	ZNSDKError err = m_audiorawdatawrap.UnSubScribe();
	return err;
}
void ZNativeRawAPIWrap::HandleNativeRendererBeDestroyed(unsigned long long recv_handle)
{
	std::map<unsigned long long, ZNativeRawRenderWrap*>::iterator iter = m_rawdatarender_map.find(recv_handle);
	if (m_rawdatarender_map.end() != iter)
	{
		ZNativeRawRenderWrap* pTempRenderWrap = (*iter).second;
		if(pTempRenderWrap)
			delete pTempRenderWrap;
		pTempRenderWrap = NULL;
		m_rawdatarender_map.erase(recv_handle);
	}
	
}