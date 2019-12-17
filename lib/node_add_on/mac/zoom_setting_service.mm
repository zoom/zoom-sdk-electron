#include "../meeting_service_wrap_core.h"
#include "../setting_service_wrap_core.h"
#import "Header_include.h"
#include "sdk_native_error.h"
#include "../setting_ui_strategy_wrap_core.h"
ZSettingServiceWrap::ZSettingServiceWrap()
{
    
}

ZSettingServiceWrap::~ZSettingServiceWrap()
{
    
}

ZSettingVideoWrap &ZSettingServiceWrap::GetSettingVideoCtrl()
{
    return m_setting_video_ctrl;
}

ZSettingAudioWrap &ZSettingServiceWrap::GetSettingAudioCtrl()
{
    return m_setting_audio_ctrl;
}

ZSettingGeneralWrap &ZSettingServiceWrap::GetSettingGeneralCtrl()
{
    return m_setting_general_ctrl;
}

ZSettingRecordingWrap &ZSettingServiceWrap::GetSettingRecordingCtrl()
{
    return m_setting_recording_ctrl;
}

ZSettingUIStrategyWrap &ZSettingServiceWrap::GetSettingStrategyCtrl()
{
    return m_setting_ui_strategy_ctrl;
}
ZSettingStatisticWrap& ZSettingServiceWrap::GetSettingStatisticCtrl()
{
    return m_setting_statistic_ctrl;
}
ZSettingAccessibilityWrap& ZSettingServiceWrap::GetSettingAccessibilityCtrl()
{
    return m_setting_accessibility_ctrl;
}
void ZSettingServiceWrap::Init()
{
    
}

void ZSettingServiceWrap::Uninit()
{
    
}


ZNSDKError ZSettingServiceWrap::ShowSettingDlg(ZNShowSettingDlgParam param)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (controller) {
        ZoomSDKError ret = [controller showMeetingComponent:MeetingComponent_Setting window:nil show:YES InPanel:YES frame:NSZeroRect];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return  ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZSettingServiceWrap::HideSettingDlg()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (controller) {
        ZoomSDKError ret = [controller showMeetingComponent:MeetingComponent_Setting window:nil show:NO InPanel:NO frame:NSZeroRect];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return  ZNSDKERR_SERVICE_FAILED;
}


//////////////////  ZSettingUIStrategyWrap  //////////////////
ZSettingUIStrategyWrap::ZSettingUIStrategyWrap()
{
    
}
ZSettingUIStrategyWrap::~ZSettingUIStrategyWrap()
{
    
}
void ZSettingUIStrategyWrap::Init()
{
    
}
void ZSettingUIStrategyWrap:: Uninit()
{
    
}

void ZSettingUIStrategyWrap::DisableAdvancedFeatures4GeneralSetting(bool bDisable)
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (setting) {
        ZoomSDKGeneralSetting *general = [setting getGeneralSetting];
        if (general) {
            [general hideSettingComponent:SettingComponent_AdvancedFeatureButton hide:bDisable];
        }
    }
}

void ZSettingUIStrategyWrap::DisableAccountSettingTabPage(bool bDisable)
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (setting) {
        ZoomSDKGeneralSetting *general = [setting getGeneralSetting];
        if (general) {
            [general hideSettingComponent:SettingComponent_AdvancedFeatureTab hide:bDisable];
        }
    }
}

void ZSettingUIStrategyWrap::ConfSettingDialogShownTabPage(unsigned long showOption)
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (setting)
    {
        ZoomSDKGeneralSetting *general = [setting getGeneralSetting];
        if (general)
        {
            [general hideSettingComponent:SettingComponent_VirtualBackgroundFeatureTab hide:(showOption & SETTING_DLG_SHOW_VIRTUAL_BACK_GROUND_TABPAGE)];
            [general hideSettingComponent:SettingComponent_VideoFeatureTab hide:(showOption & SETTING_DLG_SHOW_VIDEO_TABPAGE)];
            [general hideSettingComponent:SettingComponent_StatisticsFeatureTab hide:(showOption & SETTING_DLG_SHOW_STATISTICS_TABPAGE)];
            [general hideSettingComponent:SettingComponent_RecordingFeatureTab hide:(showOption & SETTING_DLG_SHOW_RECORDING_TABPAGE)];
            [general hideSettingComponent:SettingComponent_GeneralFeatureTab hide:(showOption & SETTING_DLG_SHOW_GENERAL_TABPAGE)];
            [general hideSettingComponent:SettingComponent_FeedbackFeatureTab hide:(showOption & SETTING_DLG_SHOW_FEEDBACK_TABPAGE)];
            [general hideSettingComponent:SettingComponent_AudioFeatureTab hide:(showOption & SETTING_DLG_SHOW_AUDIO_TABPAGE)];
            [general hideSettingComponent:SettingComponent_AdvancedFeatureTab hide:(showOption & SETTING_DLG_SHOW_ADVANCED_FEATURE_TABPAGE)];
            [general hideSettingComponent:SettingComponent_AccessibilityFeatureTab hide:(showOption & SETTING_DLG_SHOW_ACCESSIBILITY_TABPAGE)];
        }
    }
}
