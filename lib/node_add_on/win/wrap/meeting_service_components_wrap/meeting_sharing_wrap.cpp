#include "meeting_sharing_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingShareController* InitIMeetingShareControllerFunc(IMeetingShareCtrlEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingShareController* pObj = pOwner->GetSDKObj()->GetMeetingShareController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingShareControllerFunc(IMeetingShareController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}
//virtual SDKError StartWhiteBoardShare() = 0;
IMPL_FUNC_0(IMeetingShareController, StartWhiteBoardShare, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError IsSupportAdvanceShareOption(AdvanceShareOption option_) = 0;
IMPL_FUNC_1(IMeetingShareController, IsSupportAdvanceShareOption, SDKError, AdvanceShareOption, option_, SDKERR_UNINITIALIZE)
//virtual SDKError StartShareFrame() = 0;
IMPL_FUNC_0(IMeetingShareController, StartShareFrame, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError StartSharePureComputerAudio() = 0;
IMPL_FUNC_0(IMeetingShareController, StartSharePureComputerAudio, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError StartShareCamera() = 0;
IMPL_FUNC_0(IMeetingShareController, StartShareCamera, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError ShowSharingAppSelectWnd() = 0;
//virtual SDKError StartAppShare(HWND hwndSharedApp) = 0;
IMPL_FUNC_1(IMeetingShareController, StartAppShare, SDKError, HWND, hwndSharedApp, SDKERR_UNINITIALIZE)
//virtual SDKError StartMonitorShare(const wchar_t* monitorID) = 0;
IMPL_FUNC_1(IMeetingShareController, StartMonitorShare, SDKError, const wchar_t*, monitorID, SDKERR_UNINITIALIZE)
//virtual SDKError StartAirPlayShare() = 0;
IMPL_FUNC_0(IMeetingShareController, StartAirPlayShare, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError ShowSharingAppSelectWnd() = 0;
IMPL_FUNC_0(IMeetingShareController, ShowSharingAppSelectWnd, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError StopShare() = 0;
IMPL_FUNC_0(IMeetingShareController, StopShare, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError BlockWindowFromScreenshare(bool bBlock, HWND hWnd) = 0;
IMPL_FUNC_3(IMeetingShareController, BlockWindowFromScreenshare, SDKError, bool, bBlock, HWND, hWnd, bool, bChangeWindowStyle, SDKERR_UNINITIALIZE)
//virtual SDKError LockShare() = 0;
IMPL_FUNC_0(IMeetingShareController, LockShare, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError UnlockShare() = 0;
IMPL_FUNC_0(IMeetingShareController, UnlockShare, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError SwitchToFitWindowModeWhenViewShare(SDKViewType type) = 0;
IMPL_FUNC_1(IMeetingShareController, SwitchToFitWindowModeWhenViewShare, SDKError, SDKViewType, type, SDKERR_UNINITIALIZE)
//virtual SDKError SwitchToOriginalSizeModeWhenViewShare(SDKViewType type) = 0;
IMPL_FUNC_1(IMeetingShareController, SwitchToOriginalSizeModeWhenViewShare, SDKError, SDKViewType, type, SDKERR_UNINITIALIZE)
//virtual SDKError PauseCurrentSharing() = 0;
IMPL_FUNC_0(IMeetingShareController, PauseCurrentSharing, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError ResumeCurrentSharing() = 0;
IMPL_FUNC_0(IMeetingShareController, ResumeCurrentSharing, SDKError, SDKERR_UNINITIALIZE)
//virtual IList<unsigned int >* GetViewableShareSourceList() = 0;
IMPL_FUNC_0(IMeetingShareController, GetViewableShareSourceList, IList<unsigned int >*, NULL)
//virtual SDKError GetViewabltShareSourceByUserID(unsigned int userid, ViewableShareSource& shareSource) = 0;
IMPL_FUNC_2(IMeetingShareController, GetViewabltShareSourceByUserID, SDKError, unsigned int, userid, ViewableShareSource&, shareSource, SDKERR_UNINITIALIZE)
//virtual SDKError ViewShare(unsigned int userid, SDKViewType type) = 0;
IMPL_FUNC_2(IMeetingShareController, ViewShare, SDKError, unsigned int, userid, SDKViewType, type, SDKERR_UNINITIALIZE)
//virtual SDKError ShowShareOptionDialog() = 0;
IMPL_FUNC_0(IMeetingShareController, ShowShareOptionDialog, SDKError, SDKERR_UNINITIALIZE)
//virtual bool CanStartShare() = 0;
IMPL_FUNC_0(IMeetingShareController, CanStartShare, bool, false)
//virtual SDKError IsShareLocked(bool& bLocked) = 0;
IMPL_FUNC_1(IMeetingShareController, IsShareLocked, SDKError, bool&, bLocked, SDKERR_UNINITIALIZE)
//virtual bool	 IsSupportEnableShareComputerSound(bool& bCurEnableOrNot) = 0;
IMPL_FUNC_1(IMeetingShareController, IsSupportEnableShareComputerSound, bool, bool&, bCurEnableOrNot, false)
//virtual bool	 IsSupportEnableOptimizeForFullScreenVideoClip(bool& bCurEnableOrNot) = 0;
IMPL_FUNC_1(IMeetingShareController, IsSupportEnableOptimizeForFullScreenVideoClip, bool, bool&, bCurEnableOrNot, false)
//virtual SDKError EnableShareComputerSound(bool bEnable) = 0;
IMPL_FUNC_1(IMeetingShareController, EnableShareComputerSound, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual SDKError EnableOptimizeForFullScreenVideoClip(bool bEnable) = 0;
IMPL_FUNC_1(IMeetingShareController, EnableOptimizeForFullScreenVideoClip, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual SDKError SetMultiShareSettingOptions(MultiShareOption shareOption) = 0;
IMPL_FUNC_1(IMeetingShareController, SetMultiShareSettingOptions, SDKError, MultiShareOption, shareOption, SDKERR_UNINITIALIZE)
//virtual SDKError GetMultiShareSettingOptions(MultiShareOption& shareOption) = 0;
IMPL_FUNC_1(IMeetingShareController, GetMultiShareSettingOptions, SDKError, MultiShareOption&, shareOption, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE