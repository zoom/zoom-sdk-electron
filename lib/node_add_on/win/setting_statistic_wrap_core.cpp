
#include "../setting_statistic_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "zoom_native_to_wrap.h"

ZSettingStatisticWrap::ZSettingStatisticWrap()
{
	
}
ZSettingStatisticWrap::~ZSettingStatisticWrap()
{
	Uninit();
}
void ZSettingStatisticWrap::Init()
{
	
}
void ZSettingStatisticWrap::Uninit()
{
	
}
ZNSDKError ZSettingStatisticWrap::QueryOverallStatisticInfo(ZNOverallStatisticInfo& info)
{
	ZOOM_SDK_NAMESPACE::OverallStatisticInfo sdk_info;
	ZNSDKError err = ZNSDKERR_UNKNOWN;
	ZOOM_SDK_NAMESPACE::IStatisticSettingContext* pStatisticSettingContext = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetStatisticSettings();
	if (pStatisticSettingContext)
	{
		err = Map2WrapDefine(pStatisticSettingContext->QueryOverallStatisticInfo(sdk_info));
		info.net_work_type = Map2WrapDefine(sdk_info.net_work_type_);
		info.connection_type = Map2WrapDefine(sdk_info.connection_type_);
		if (NULL == sdk_info.proxy_addr_)
		{
			info.proxy_addr = L"";
		}
		else
		{
			info.proxy_addr = sdk_info.proxy_addr_;
		}
	}
	
	return err;
}
ZNSDKError ZSettingStatisticWrap::QueryAudioStatisticInfo(ZNAudioSessionStatisticInfo& info)
{
	ZOOM_SDK_NAMESPACE::AudioSessionStatisticInfo sdk_info;
	ZNSDKError err = ZNSDKERR_UNKNOWN;
	ZOOM_SDK_NAMESPACE::IStatisticSettingContext* pStatisticSettingContext = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetStatisticSettings();
	if (pStatisticSettingContext)
	{
		err = Map2WrapDefine(pStatisticSettingContext->QueryAudioStatisticInfo(sdk_info));
		info.frequency_send = sdk_info.frequency_send_;
		info.frequency_recv = sdk_info.frequency_recv_;
		info.jitter_recv = sdk_info.jitter_recv_;
		info.jitter_send = sdk_info.jitter_send_;
		info.latency_recv = sdk_info.latency_recv_;
		info.latency_send = sdk_info.latency_send_;
		info.packetloss_recv = sdk_info.packetloss_recv_;
		info.packetloss_send = sdk_info.packetloss_send_;
	}

	return err;
}
ZNSDKError ZSettingStatisticWrap::QueryVideoStatisticInfo(ZNASVSessionStatisticInfo& info)
{
	ZOOM_SDK_NAMESPACE::ASVSessionStatisticInfo sdk_info;
	ZNSDKError err = ZNSDKERR_UNKNOWN;
	ZOOM_SDK_NAMESPACE::IStatisticSettingContext* pStatisticSettingContext = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetStatisticSettings();
	if (pStatisticSettingContext)
	{
		err = Map2WrapDefine(pStatisticSettingContext->QueryVideoStatisticInfo(sdk_info));
		info.fps_recv = sdk_info.fps_recv_;
		info.fps_send = sdk_info.fps_send_;
		info.jitter_recv = sdk_info.jitter_recv_;
		info.jitter_send = sdk_info.jitter_send_;
		info.latency_recv = sdk_info.latency_recv_;
		info.latency_send = sdk_info.latency_send_;
		info.packetloss_recv_avg = sdk_info.packetloss_recv_avg_;
		info.packetloss_recv_max = sdk_info.packetloss_recv_max_;
		info.packetloss_send_avg = sdk_info.packetloss_send_avg_;
		info.packetloss_send_max = sdk_info.packetloss_send_max_;
		info.resolution_recv = sdk_info.resolution_recv_;
		info.resolution_send = sdk_info.resolution_send_;
	}

	return err;
}
ZNSDKError ZSettingStatisticWrap::QueryShareStatisticInfo(ZNASVSessionStatisticInfo& info)
{
	ZOOM_SDK_NAMESPACE::ASVSessionStatisticInfo sdk_info;
	ZNSDKError err = ZNSDKERR_UNKNOWN;
	ZOOM_SDK_NAMESPACE::IStatisticSettingContext* pStatisticSettingContext = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetStatisticSettings();
	if (pStatisticSettingContext)
	{
		err = Map2WrapDefine(pStatisticSettingContext->QueryShareStatisticInfo(sdk_info));
		info.fps_recv = sdk_info.fps_recv_;
		info.fps_send = sdk_info.fps_send_;
		info.jitter_recv = sdk_info.jitter_recv_;
		info.jitter_send = sdk_info.jitter_send_;
		info.latency_recv = sdk_info.latency_recv_;
		info.latency_send = sdk_info.latency_send_;
		info.packetloss_recv_avg = sdk_info.packetloss_recv_avg_;
		info.packetloss_recv_max = sdk_info.packetloss_recv_max_;
		info.packetloss_send_avg = sdk_info.packetloss_send_avg_;
		info.packetloss_send_max = sdk_info.packetloss_send_max_;
		info.resolution_recv = sdk_info.resolution_recv_;
		info.resolution_send = sdk_info.resolution_send_;
	}

	return err;
}