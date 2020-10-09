#include "../zoom_native_audio_rawdata_wrap_core.h"

ZNativeAudioRawDataWrap::ZNativeAudioRawDataWrap()
{
	m_pNativeAudioRawDataHelper = NULL;
}
ZNativeAudioRawDataWrap::~ZNativeAudioRawDataWrap()
{
	m_pNativeAudioRawDataHelper = NULL;
}

ZOOM_SDK_NAMESPACE::IZoomSDKAudioRawDataHelper* ZNativeAudioRawDataWrap::GetNativeHelper()
{
	return m_pNativeAudioRawDataHelper;
}
void ZNativeAudioRawDataWrap::SetNativeHelper(ZOOM_SDK_NAMESPACE::IZoomSDKAudioRawDataHelper* nativeHelper)
{
	m_pNativeAudioRawDataHelper = nativeHelper;
}

ZNSDKError ZNativeAudioRawDataWrap::SubScribe()
{
	ZNSDKError err = ZNSDKERR_INTELNAL_ERROR;

	do
	{
		if (!m_pNativeAudioRawDataHelper)
		{
			err = ZNSDKERR_WRONG_USEAGE;
			break;
		}
		err = Map2WrapDefine(m_pNativeAudioRawDataHelper->subscribe(this));
	} while (false);

	return err;
}
ZNSDKError ZNativeAudioRawDataWrap::UnSubScribe()
{
	ZNSDKError err = ZNSDKERR_INTELNAL_ERROR;

	do
	{
		if (!m_pNativeAudioRawDataHelper)
		{
			err = ZNSDKERR_WRONG_USEAGE;
			break;
		}
		err = Map2WrapDefine(m_pNativeAudioRawDataHelper->unSubscribe());
	} while (false);

	return err;
}


//
void ZNativeAudioRawDataWrap::onMixedAudioRawDataReceived(AudioRawData* data_)
{
	ZoomNodeRawDataHelperMgr::GetInst().onMixedAudioRawDataReceived(data_);
}

void ZNativeAudioRawDataWrap::onOneWayAudioRawDataReceived(AudioRawData* data_, uint32_t node_id)
{
	ZoomNodeRawDataHelperMgr::GetInst().onOneWayAudioRawDataReceived(data_, node_id);
}