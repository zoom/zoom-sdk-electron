#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class ISDKRendererCallbackWrap :public IZoomSDKPreProcessor, public IZoomSDKVideoSource
{
public:
	ISDKRendererCallbackWrap()
	{
		Reset();
	}
	~ISDKRendererCallbackWrap()
	{
		Reset();
	}
	virtual	void onInitialize(IZoomSDKVideoSender* sender, IList<VideoSourceCapability >* support_cap_list, VideoSourceCapability& suggest_cap)
	{
		if (m_pVideoSourceCB)
		{
			m_pVideoSourceCB->onInitialize(sender, support_cap_list, suggest_cap);
		}
	}
	virtual void onPropertyChange(IList<VideoSourceCapability >* support_cap_list, VideoSourceCapability suggest_cap)
	{
		if (m_pVideoSourceCB)
		{
			m_pVideoSourceCB->onPropertyChange(support_cap_list, suggest_cap);
		}
	}
	virtual void onStartSend()
	{
		if (m_pVideoSourceCB)
		{
			m_pVideoSourceCB->onStartSend();
		}
	}
	virtual void onStopSend()
	{
		if (m_pVideoSourceCB)
		{
			m_pVideoSourceCB->onStopSend();
		}
	}
	virtual void onUninitialized()
	{
		if (m_pVideoSourceCB)
		{
			m_pVideoSourceCB->onUninitialized();
		}
	}
	virtual void onPreProcessRawData(YUVProcessDataI420* rawData)
	{
		if (m_pPrecessorCB)
			m_pPrecessorCB->onPreProcessRawData(rawData);
	}

	void SetPreProcessorCB(IZoomSDKPreProcessor* pEvent)
	{
		m_pVideoSourceCB = NULL;
		if (pEvent)
		{
			m_pPrecessorCB = pEvent;
		}
	}
	void SetVideoSourceCB(IZoomSDKVideoSource* pEvent)
	{
		m_pPrecessorCB = NULL;
		if (pEvent)
		{
			m_pVideoSourceCB = pEvent;
		}
	}
private:
	void Reset()
	{
		m_pPrecessorCB = NULL;
		m_pVideoSourceCB = NULL;
	}
private:
	IZoomSDKPreProcessor* m_pPrecessorCB;
	IZoomSDKVideoSource* m_pVideoSourceCB;
};
END_ZOOM_SDK_NAMESPACE