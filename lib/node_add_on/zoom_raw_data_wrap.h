#ifndef _ZOOM_RAW_DATA_WARP_H_
#define _ZOOM_RAW_DATA_WARP_H_
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "./win/h/zoom_sdk_raw_data_helper_interface.h"
#else
#import "../../sdk/mac/ZoomSDK/ZoomSDK.framework/Versions/A/Headers/zoom_sdk_raw_data_helper_interface.h"
#endif // _WIN32
#include <set>
USING_ZOOM_RAWDATA_NAMESPACE
#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus
	SDKRawDataError Node_HasRawDataLicense();
	SDKRawDataError Node_RetrieveAudioRawDataChannel(IAudioRawDataChannel** pp_channel);
	SDKRawDataError Node_RetrieveVideoRawDataChannel(IVideoRawDataChannel** pp_channel);
	SDKRawDataError Node_RetrieveShareRawDataChannel(IShareRawDataChannel** pp_channel);
#ifdef __cplusplus
};
#endif //__cplusplus


template<class T>
void ZNGetDefaultValue(T& tmp)
{
}

template<class T_PARAM>
class ParamRelease
{
public:
	virtual void release(T_PARAM& paRelease)
	{
	}
};

template<class T_PARAM>
class ParamRelease<T_PARAM*> : public ParamRelease<T_PARAM >
{
public:
	virtual void release(T_PARAM* paRelease)
	{
		if (NULL != paRelease)
		{
			delete paRelease;
			paRelease = NULL;
		}
	}
};

template<class T_PARAM>
class ParamRelease<IVector<T_PARAM* >* > : public ParamRelease<T_PARAM >
{
public:
	virtual void release(IVector<T_PARAM* >* paRelease)
	{
		if (paRelease)
		{
			int count_ = paRelease->GetCount();
			for (int i = 0; i < count_; i++)
			{
				T_PARAM* pDel = paRelease->GetItem(i);
				if (pDel)
				{
					delete pDel;
				}
			}
			delete paRelease;
		}
	}
};

template<class T>
class CZNodeSetImpl : public IVector<T >
{
public:
	CZNodeSetImpl()
	{

	}

	virtual ~CZNodeSetImpl()
	{
	}

	virtual int GetCount()
	{
		return m_List.size();
	}

	virtual T  GetItem(int index)
	{
		T elem;
		ZNGetDefaultValue<T>(elem);
		if (index >= 0
			&& index < (int)m_List.size())
		{
			typename std::set<T >::iterator itFind = m_List.begin();
			for (int i = 1; i <= index; i++)
			{
				++itFind;
				if (m_List.end() == itFind)
					return elem;

			}
			elem = *itFind;
		}

		return elem;
	}

	void Clear()
	{
		m_List.clear();
	}

public:
	std::set<T > m_List;
};
#endif
