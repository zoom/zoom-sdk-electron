#include "../setting_statistic_wrap_core.h"
#include "Header_include.h"
#include "sdk_native_error.h"
ZSettingStatisticWrap::ZSettingStatisticWrap()
{}
ZSettingStatisticWrap::~ZSettingStatisticWrap()
{}
void ZSettingStatisticWrap::Init()
{
    
}
void ZSettingStatisticWrap::Uninit()
{
    
}

ZNSDKError ZSettingStatisticWrap::QueryOverallStatisticInfo(ZNOverallStatisticInfo& info_)
{
    return ZNSDKERR_NO_IMPL;
}

ZNSDKError ZSettingStatisticWrap::QueryAudioStatisticInfo(ZNAudioSessionStatisticInfo& info_)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKStatisticsSetting *staticSetting = [service getStatisticsSetting];
    if (!staticSetting) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKAudioStatisticsInfo *statistInfo = [staticSetting getAudioStatisticsInfo];
    info_.frequency_send = [statistInfo getFrequency:YES];
    info_.frequency_recv = [statistInfo getFrequency:NO];
    info_.latency_send = [statistInfo getLatency:YES];
    info_.latency_recv = [statistInfo getLatency:NO];
    info_.jitter_send = [statistInfo getJitter:YES];
    info_.jitter_recv = [statistInfo getJitter:NO];
    info_.packetloss_send = [statistInfo getPackageLoss:YES Max:NO];
    info_.packetloss_recv = [statistInfo getPackageLoss:NO Max:NO];
    return ZNSDKERR_SUCCESS;
}

ZNSDKError ZSettingStatisticWrap::QueryVideoStatisticInfo(ZNASVSessionStatisticInfo& info_)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKStatisticsSetting *staticSetting = [service getStatisticsSetting];
    if (!staticSetting) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoASStatisticsInfo *videoAS = [staticSetting getVideoASStatisticsInfo:YES];
    info_.latency_send = [videoAS getLatency:YES];
    info_.latency_recv = [videoAS getLatency:NO];
    info_.jitter_send = [videoAS getJitter:YES];
    info_.jitter_recv = [videoAS getJitter:NO];
    info_.packetloss_send_max = [videoAS getPackageLoss:YES Max:YES];
    info_.packetloss_recv_max = [videoAS getPackageLoss:NO Max:YES];
    info_.packetloss_send_avg = [videoAS getPackageLoss:YES Max:NO];
    info_.packetloss_recv_avg= [videoAS getPackageLoss:NO Max:NO];
    info_.resolution_send = [videoAS getResolution:YES];
    info_.resolution_recv = [videoAS getResolution:NO];
    info_.fps_send = [videoAS getFPS:YES];
    info_.fps_recv = [videoAS getFPS:NO];
    return ZNSDKERR_SUCCESS;
}

ZNSDKError ZSettingStatisticWrap::QueryShareStatisticInfo(ZNASVSessionStatisticInfo& info_)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKStatisticsSetting *staticSetting = [service getStatisticsSetting];
    if (!staticSetting) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoASStatisticsInfo *videoAS = [staticSetting getVideoASStatisticsInfo:NO];
    info_.latency_send = [videoAS getLatency:YES];
    info_.latency_recv = [videoAS getLatency:NO];
    info_.jitter_send = [videoAS getJitter:YES];
    info_.jitter_recv = [videoAS getJitter:NO];
    info_.packetloss_send_max = [videoAS getPackageLoss:YES Max:YES];
    info_.packetloss_recv_max = [videoAS getPackageLoss:NO Max:YES];
    info_.packetloss_send_avg = [videoAS getPackageLoss:YES Max:NO];
    info_.packetloss_recv_avg= [videoAS getPackageLoss:NO Max:NO];
    info_.resolution_send = [videoAS getResolution:YES];
    info_.resolution_recv = [videoAS getResolution:NO];
    info_.fps_send = [videoAS getFPS:YES];
    info_.fps_recv = [videoAS getFPS:NO];
    return ZNSDKERR_SUCCESS;
}
