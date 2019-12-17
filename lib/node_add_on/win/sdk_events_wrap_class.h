#ifndef _sdk_events_wrap_class_h_
#define _sdk_events_wrap_class_h_
#include "wrap/sdk_wrap.h"
#include "zoom_native_to_wrap.h"
#include "../zoom_native_sdk_wrap_core_def.h"
#include "../zoom_native_sdk_wrap_core.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZAuthServiceWrapEvent : public ZOOM_SDK_NAMESPACE::IAuthServiceEvent
{
public:
	void SetOwner(ZAuthServiceWrap* obj) { owner_ = obj; }
	virtual void onAuthenticationReturn(ZOOM_SDK_NAMESPACE::AuthResult ret) {
		if (owner_) {
			if (ZOOM_SDK_NAMESPACE::AUTHRET_SUCCESS == ret)
			{
				_g_native_wrap.GetMeetingServiceWrap().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingParticipantsCtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingShareCtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().Init();
				_g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().Init();
				_g_native_wrap.GetSettingServiceWrap().Init();

			}
			owner_->onAuthenticationReturn(Map2WrapDefine(ret));

		}
	}
	virtual void onLoginRet(ZOOM_SDK_NAMESPACE::LOGINSTATUS ret, ZOOM_SDK_NAMESPACE::IAccountInfo* pAccountInfo) {
		if (owner_)
		{
			if (ZOOM_SDK_NAMESPACE::LOGIN_SUCCESS == ret)
			{
				_g_native_wrap.GetAuthServiceWrap().GetDirectShareHelper().Init();
				_g_native_wrap.GetPremeetingServiecWrap().Init();
			}
			owner_->onLoginRet(Map2WrapDefine(ret));
		}
	}
	virtual void onLogout() {
		if (owner_) {
			owner_->onLogout();
		}

	}
	virtual void onZoomIdentityExpired() {
		if (owner_) {
			owner_->onZoomIdentityExpired();
		}
	}
	virtual void onZoomAuthIdentityExpired() {
		if (owner_) {
			owner_->onZoomAuthIdentityExpired();
		}
	}
private:
	ZAuthServiceWrap* owner_;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingServiceWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingServiceEvent
{
public:
	void SetOwner(ZMeetingServiceWrap* obj) { owner_ = obj; }
	virtual void onMeetingStatusChanged(ZOOM_SDK_NAMESPACE::MeetingStatus status, int iResult)
	{
		if (owner_) {
			owner_->onMeetingStatusChanged(Map2WrapDefine(status), iResult);
		}
	}
	virtual void onMeetingStatisticsWarningNotification(ZOOM_SDK_NAMESPACE::StatisticsWarningType type)
	{

	}
	virtual void onMeetingSecureKeyNotification(const char* key, int len, ZOOM_SDK_NAMESPACE::IMeetingExternalSecureKeyHandler* pHandler)
	{

	}
	virtual void onMeetingParameterNotification(const ZOOM_SDK_NAMESPACE::MeetingParameter* pMeetingParam)
	{

	}
private:
	ZMeetingServiceWrap* owner_;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZPreMeetingServiceWrapEvent : public ZOOM_SDK_NAMESPACE::IPreMeetingServiceEvent
{
public:
	void SetOwner(ZPremeetingServiceWrap* obj) { owner_ = obj; }
	virtual void onScheduleOrEditMeeting(ZOOM_SDK_NAMESPACE::PremeetingAPIResult result, UINT64 meetingUniqueID)
	{
		if (owner_) {
			owner_->onScheduleOrEditMeeting(Map2WrapDefine(result), meetingUniqueID);
		}
	}
	virtual void onListMeeting(ZOOM_SDK_NAMESPACE::PremeetingAPIResult result, ZOOM_SDK_NAMESPACE::IList<UINT64 >* lstMeetingList)
	{
		if (owner_)
		{
			ZNList<unsigned long long> zlst_meeting_list;
			if (lstMeetingList && lstMeetingList->GetCount() > 0)
			{
				for (int i = 0; i < lstMeetingList->GetCount(); ++i)
				{
					unsigned long long meetingID = lstMeetingList->GetItem(i);
					zlst_meeting_list.push_back(meetingID);
				}
			}
			ZNPremeetingAPIResult z_premeeting_api_result = Map2WrapDefine(result);
			owner_->onListMeeting(z_premeeting_api_result, zlst_meeting_list);
		}
	}
	virtual void onDeleteMeeting(ZOOM_SDK_NAMESPACE::PremeetingAPIResult result)
	{
		if (owner_) {
			owner_->onDeleteMeeting(Map2WrapDefine(result));
		}
	}
private:
	ZPremeetingServiceWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingUIControllerWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingUIControllerEvent
{
public:
	void SetOwner(ZMeetingUICtrlWrap* obj) { owner_ = obj; }
	virtual void onInviteBtnClicked(bool& bHandled)
	{
		if (owner_) {
			owner_->onInviteBtnClicked(bHandled);
		}
	}
	virtual void onStartShareBtnClicked()
	{
		if (owner_)
		{
			owner_->onStartShareBtnClicked();
		}
	}
	virtual void onEndMeetingBtnClicked()
	{
		if (owner_)
		{
			owner_->onEndMeetingBtnClicked();
		}
	}
	virtual void onParticipantListBtnClicked()
	{
		if (owner_)
		{
			owner_->onParticipantListBtnClicked();
		}
	}
	virtual void onCustomLiveStreamMenuClicked()
	{
		if (owner_)
		{
			owner_->onCustomLiveStreamMenuClicked();
		}
	}
	virtual void onZoomInviteDialogFailed()
	{
		if (owner_)
		{
			owner_->onZoomInviteDialogFailed();
		}
	}
	virtual void onCCBTNClicked()
	{
		if (owner_)
		{
			owner_->onCCBTNClicked();
		}
	}
	virtual void onAudioBtnClicked(ZOOM_SDK_NAMESPACE::AudioBtnClickedCallbackInfo info)
	{
		if (owner_)
		{
			ZNAudioBtnClickedCallbackInfo zn_info;
			zn_info.userid_MuteUnmute = info.userid_MuteUnmute;
			zn_info.audio_clicked_action = Map2WrapDefine(info.audio_clicked_action);
			owner_->onAudioBtnClicked(zn_info);
		}
	}
	virtual void onAudioMenuBtnClicked()
	{
		if (owner_)
		{
			owner_->onAudioMenuBtnClicked();
		}
	}
private:
	ZMeetingUICtrlWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingAudioCtrlWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingAudioCtrlEvent
{
public:
	void SetOwner(ZMeetingAudioWrap* obj) { owner_ = obj; }
	virtual void onUserAudioStatusChange(ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IUserAudioStatus* >* lstAudioStatusChange, const wchar_t* strAudioStatusList)
	{
		if (owner_) {
			if (NULL == strAudioStatusList && lstAudioStatusChange && lstAudioStatusChange->GetCount() > 0)
			{
				//
				ZNList<ZNUserAudioStatus> audio_status_list;
				ZoomSTRING zn_strAudioStatusList = L"";
				for (int i = 0; i < lstAudioStatusChange->GetCount(); ++i)
				{
					ZOOM_SDK_NAMESPACE::IUserAudioStatus* pAudioStatus = lstAudioStatusChange->GetItem(i);
					ZNUserAudioStatus userAudioStatus;
					if (pAudioStatus)
					{
						userAudioStatus.userId = pAudioStatus->GetUserId();
						userAudioStatus.audioStauts = Map2WrapDefine(pAudioStatus->GetStatus());
					}

					audio_status_list.push_back(userAudioStatus);
				}
				owner_->onUserAudioStatusChange(audio_status_list, zn_strAudioStatusList);
			}
		}
	}
	virtual void onUserActiveAudioChange(ZOOM_SDK_NAMESPACE::IList<unsigned int >* plstActiveAudio)
	{
		if (owner_) {
			if (plstActiveAudio && plstActiveAudio->GetCount() > 0)
			{
				//
				ZNList<unsigned int> active_audio_list;
				for (int i = 0; i < plstActiveAudio->GetCount(); ++i)
				{
					unsigned int userid = plstActiveAudio->GetItem(i);
					active_audio_list.push_back(userid);
				}
				owner_->onUserActiveAudioChange(active_audio_list);
			}
		}
	}
	virtual void onHostRequestStartAudio(ZOOM_SDK_NAMESPACE::IRequestStartAudioHandler* handler_)
	{

	}
private:
	ZMeetingAudioWrap* owner_;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingVideoCtrlWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingVideoCtrlEvent
{
public:
	void SetOwner(ZMeetingVideoWrap* obj) { owner_ = obj; }
	virtual void onUserVideoStatusChange(unsigned int userId, ZOOM_SDK_NAMESPACE::VideoStatus status)
	{
		if (owner_) {

			owner_->onUserVideoStatusChange(userId, Map2WrapDefine(status));
		}
	}
	virtual void onSpotlightVideoChangeNotification(bool bSpotlight, unsigned int userid)
	{
		//
	}
	virtual void onHostRequestStartVideo(ZOOM_SDK_NAMESPACE::IRequestStartVideoHandler* handler_)
	{

	}
	virtual void onActiveSpeakerVideoUserChanged(unsigned int userid)
	{
		if (owner_) {
			owner_->onActiveSpeakerVideoUserChanged(userid);
		}
	}
	virtual void onActiveVideoUserChanged(unsigned int userid)
	{
		if (owner_) {
			owner_->onActiveVideoUserChanged(userid);
		}
	}
private:
	ZMeetingVideoWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingShareCtrlWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingShareCtrlEvent
{
public:
	void SetOwner(ZMeetingShareWrap* obj) { owner_ = obj; }
	virtual void onSharingStatus(ZOOM_SDK_NAMESPACE::SharingStatus status, unsigned int userId)
	{
		if (owner_) {

			owner_->onSharingStatus(Map2WrapDefine(status), userId);
		}

	}
	virtual void onLockShareStatus(bool bLocked)
	{

	}
	virtual void onShareContentNotification(ZOOM_SDK_NAMESPACE::ShareInfo& shareInfo)
	{

	}
	virtual void onMultiShareSwitchToSingleShareNeedConfirm(ZOOM_SDK_NAMESPACE::IShareSwitchMultiToSingleConfirmHandler* handler_)
	{

	}
private:
	ZMeetingShareWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingParticipantsCtrlEvent : public ZOOM_SDK_NAMESPACE::IMeetingParticipantsCtrlEvent
{
public:
	void SetOwner(ZMeetingParticipantsWrap* obj) { owner_ = obj; }
	virtual void onUserJoin(ZOOM_SDK_NAMESPACE::IList<unsigned int >* lstUserID, const wchar_t* strUserList)
	{
		if (owner_ && lstUserID) {
			ZNList<unsigned int> userId_list;
			ZoomSTRING zn_strUserList = L"";
			if (strUserList)
				zn_strUserList = strUserList;
			for (int i = 0; i < lstUserID->GetCount(); ++i)
			{

				unsigned int zn_userid;

				zn_userid = lstUserID->GetItem(i);

				userId_list.push_back(zn_userid);
			}

			owner_->onUserJoin(userId_list, zn_strUserList);

		}
	}
	virtual void onUserLeft(ZOOM_SDK_NAMESPACE::IList<unsigned int >* lstUserID, const wchar_t* strUserList)
	{
		if (owner_ && lstUserID) {
			ZNList<unsigned int> userId_list;
			ZoomSTRING zn_strUserList = L"";
			if (strUserList)
				zn_strUserList = strUserList;
			for (int i = 0; i < lstUserID->GetCount(); ++i)
			{

				unsigned int zn_userid;

				zn_userid = lstUserID->GetItem(i);

				userId_list.push_back(zn_userid);
			}

			owner_->onUserLeft(userId_list, zn_strUserList);

		}
	}
	virtual void onHostChangeNotification(unsigned int userId)
	{
		if (owner_) {

			owner_->onHostChangeNotification(userId);

		}
	}
	virtual void onLowOrRaiseHandStatusChanged(bool bLow, unsigned int userid)
	{

	}
	virtual void onUserNameChanged(unsigned int userId, const wchar_t* userName)
	{

	}
	virtual void onCoHostChangeNotification(unsigned int userId, bool isCoHost)
	{

	}
private:
	ZMeetingParticipantsWrap* owner_;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingH323CtrlWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingH323HelperEvent
{
public:
	void SetOwner(ZMeetingH323Wrap* obj) { owner_ = obj; }
	virtual void onCalloutStatusNotify(ZOOM_SDK_NAMESPACE::H323CalloutStatus status)
	{
		if (owner_) {
			owner_->onH323CalloutStatusNotify(Map2WrapDefine(status));
		}
	}
	virtual void onParingH323Result(ZOOM_SDK_NAMESPACE::H323ParingResult result, UINT64 meetingNumber)
	{
		//
	}
private:
	ZMeetingH323Wrap* owner_;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class FreeMeetingReminderHandler
{
public:
	static FreeMeetingReminderHandler& GetInst()
	{
		static FreeMeetingReminderHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::IFreeMeetingEndingReminderHandler *handler)
	{
		m_pHandler = handler;
	}
	ZNFreeMeetingEndingReminderType GetType()
	{
		ZOOM_SDK_NAMESPACE::IFreeMeetingEndingReminderHandler::FreeMeetingEndingReminderType winDefinedType = ZOOM_SDK_NAMESPACE::IFreeMeetingEndingReminderHandler::FreeMeetingEndingReminder_NONE;
		if (m_pHandler)
			winDefinedType = m_pHandler->GetType();
		return Map2WrapDefine(winDefinedType);
	}

	ZOOM_SDK_NAMESPACE::SDKError UpgradeMeeting()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USEAGE;
		if (m_pHandler)
			err = m_pHandler->UpgradeMeeting();
		m_pHandler = NULL;
		return err;
	}

	ZOOM_SDK_NAMESPACE::SDKError UpgradeAccount()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USEAGE;
		if (m_pHandler)
			err = m_pHandler->UpgradeAccount();
		m_pHandler = NULL;
		return err;
	}

	ZOOM_SDK_NAMESPACE::SDKError Cancel()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USEAGE;
		if (m_pHandler)
			err = m_pHandler->Cancel();
		m_pHandler = NULL;
		return err;
	}
private:
	FreeMeetingReminderHandler() {}
	ZOOM_SDK_NAMESPACE::IFreeMeetingEndingReminderHandler* m_pHandler;
};

class ZMeetingPasswordAndScreenNameHandler
{
public:
	static ZMeetingPasswordAndScreenNameHandler& GetInst()
	{
		static ZMeetingPasswordAndScreenNameHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::IMeetingPasswordAndScreenNameHandler *handler)
	{
		m_pHandler = handler;
	}

	ZNRequiredInfoType GetRequiredInfoType()
	{
		ZOOM_SDK_NAMESPACE::IMeetingPasswordAndScreenNameHandler::RequiredInfoType type = ZOOM_SDK_NAMESPACE::IMeetingPasswordAndScreenNameHandler::REQUIRED_INFO_TYPE_NONE;
		if (m_pHandler)
			type = m_pHandler->GetRequiredInfoType();
		return Map2WrapDefine(type);
	}

	bool InputMeetingPasswordAndScreenName(ZoomSTRING meetingPassword, ZoomSTRING screenName)
	{
		bool bret = false;
		if (m_pHandler)
			bret = m_pHandler->InputMeetingPasswordAndScreenName(meetingPassword.c_str(), screenName.c_str());
		m_pHandler = NULL;
		return bret;
	}
	bool InputMeetingIDAndScreenName(ZoomSTRING meetingID, ZoomSTRING screenName)
	{
		bool bret = false;
		if (m_pHandler)
			bret = m_pHandler->InputMeetingPasswordAndScreenName(meetingID.c_str(), screenName.c_str());
		m_pHandler = NULL;
		return bret;
	}
	bool InputMeetingScreenName(ZoomSTRING screenName)
	{
		bool bret = false;
		if (m_pHandler)
			bret = m_pHandler->InputMeetingScreenName(screenName.c_str());
		m_pHandler = NULL;
		return bret;
	}
	void Cancel()
	{
		if (m_pHandler)
			m_pHandler->Cancel();
		m_pHandler = NULL;
	}
private:
	ZMeetingPasswordAndScreenNameHandler() :m_pHandler(NULL) {}
	ZOOM_SDK_NAMESPACE::IMeetingPasswordAndScreenNameHandler* m_pHandler;
};
class ZWebinarNeedRegisterHandler
{
public:
	static ZWebinarNeedRegisterHandler& GetInst()
	{
		static ZWebinarNeedRegisterHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandler *handler)
	{
		m_pHandler = handler;
	}
	ZNWebinarNeedRegisterType GetWebinarNeedRegisterType()
	{
		ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandler::WebinarNeedRegisterType type = ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandler::WebinarReg_NONE;
		if (m_pHandler)
			type = m_pHandler->GetWebinarNeedRegisterType();
		return Map2WrapDefine(type);
	}
	ZoomSTRING GetWebinarRegisterUrl()
	{
		ZoomSTRING zn_url;
		if (m_pHandler)
		{
			ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandlerByUrl* m_pURL = (ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandlerByUrl*)m_pHandler;
			zn_url = m_pURL->GetWebinarRegisterUrl();
		}
		m_pHandler = NULL;
		return zn_url;
	}
	void Release()
	{
		if (m_pHandler)
		{
			ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandlerByUrl* m_pURL = (ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandlerByUrl*)m_pHandler;
			m_pURL->Release();
		}
		m_pHandler = NULL;
	}
	ZNSDKError InputWebinarRegisterEmailAndScreenName(ZoomSTRING email, ZoomSTRING screenName)
	{
		ZNSDKError zn_err = ZNSDKERR_UNKNOWN;
		if (m_pHandler)
		{
			ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandlerByEmail* m_pURL = (ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandlerByEmail*)m_pHandler;
			zn_err = Map2WrapDefine(m_pURL->InputWebinarRegisterEmailAndScreenName(email.c_str(), screenName.c_str()));
		}
		m_pHandler = NULL;
		return zn_err;
	}
	void Cancel()
	{
		if (m_pHandler)
		{
			ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandlerByEmail* m_pURL = (ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandlerByEmail*)m_pHandler;
			m_pURL->Cancel();
		}
		m_pHandler = NULL;
	}
private:
	ZWebinarNeedRegisterHandler() :m_pHandler(NULL) {}
	ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandler* m_pHandler;
};
class ZEndOtherMeetingToJoinMeetingHandler
{
public:
	static ZEndOtherMeetingToJoinMeetingHandler& GetInst()
	{
		static ZEndOtherMeetingToJoinMeetingHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::IEndOtherMeetingToJoinMeetingHandler *handler)
	{
		m_pHandler = handler;
	}
	bool EndOtherMeeting()
	{
		bool bret = false;
		if (m_pHandler)
		{
			bret = m_pHandler->EndOtherMeeting();
		}
		m_pHandler = NULL;
		return bret;
	}
	void Cancel()
	{
		if (m_pHandler)
		{
			m_pHandler->Cancel();
		}
		m_pHandler = NULL;
	}
private:
	ZEndOtherMeetingToJoinMeetingHandler() :m_pHandler(NULL) {}
	ZOOM_SDK_NAMESPACE::IEndOtherMeetingToJoinMeetingHandler* m_pHandler;
};


class ZMeetingConfigCtrlWrapFreeMeetingEvent : public ZOOM_SDK_NAMESPACE::IMeetingConfigurationEvent
{
public:
	void SetOwner(ZMeetingConfigWrap* obj) { owner_ = obj; }
	virtual void onFreeMeetingRemainTime(unsigned int leftTime)
	{
		if (owner_) {
			owner_->onFreeMeetingRemainTime(leftTime);
		}
	}
	virtual void onFreeMeetingRemainTimeStopCountDown()
	{
		if (owner_) {
			owner_->onFreeMeetingRemainTimeStopCountDown();
		}
	}
	virtual void onFreeMeetingEndingReminderNotification(ZOOM_SDK_NAMESPACE::IFreeMeetingEndingReminderHandler* handler_)
	{
		FreeMeetingReminderHandler::GetInst().SetHandler(handler_);
	}
	virtual void onFreeMeetingNeedToUpgrade(ZOOM_SDK_NAMESPACE::IMeetingConfigurationFreeMeetingEvent::FreeMeetingNeedUpgradeType type_, const wchar_t* gift_url)
	{
		if (owner_) {
			ZoomSTRING zn_gift_url = gift_url;
			owner_->onFreeMeetingNeedToUpgrade(Map2WrapDefine(type_), zn_gift_url);
		}
	}
	virtual void onFreeMeetingUpgradeToGiftFreeTrialStart()
	{
		if (owner_) {
			owner_->onFreeMeetingUpgradeToGiftFreeTrialStart();
		}
	}
	virtual void onFreeMeetingUpgradeToGiftFreeTrialStop()
	{
		if (owner_) {
			owner_->onFreeMeetingUpgradeToGiftFreeTrialStop();
		}
	}
	virtual void onFreeMeetingUpgradeToProMeeting()
	{
		if (owner_) {
			owner_->onFreeMeetingUpgradeToProMeeting();
		}
	}
	virtual void onInputMeetingPasswordAndScreenNameNotification(ZOOM_SDK_NAMESPACE::IMeetingPasswordAndScreenNameHandler* pHandler)
	{
		if (owner_ && pHandler) {
			ZMeetingPasswordAndScreenNameHandler::GetInst().SetHandler(pHandler);
			owner_->onInputMeetingPasswordAndScreenNameNotification();
		}
	}
	virtual void onAirPlayInstructionWndNotification(bool bShow, const wchar_t* airhostName)
	{
		if (owner_) {
			ZoomSTRING zn_airHostName = airhostName;
			owner_->onAirPlayInstructionWndNotification(bShow, zn_airHostName);
		}
	}
	virtual void onWebinarNeedRegisterNotification(ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandler* pHandler)
	{
		if (owner_ && pHandler) {
			ZWebinarNeedRegisterHandler::GetInst().SetHandler(pHandler);
			owner_->onWebinarNeedRegisterNotification();
		}
	}
	virtual void onEndOtherMeetingToJoinMeetingNotification(ZOOM_SDK_NAMESPACE::IEndOtherMeetingToJoinMeetingHandler* pHandler)
	{
		if (owner_ && pHandler) {
			ZEndOtherMeetingToJoinMeetingHandler::GetInst().SetHandler(pHandler);
			owner_->onEndOtherMeetingToJoinMeetingNotification();
		}
	}
private:
	ZMeetingConfigWrap* owner_;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZDirectShareViaMeetingIDOrPairingCodeHandler
{
public:
	static ZDirectShareViaMeetingIDOrPairingCodeHandler& GetInst()
	{
		static ZDirectShareViaMeetingIDOrPairingCodeHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::IDirectShareViaMeetingIDOrPairingCodeHandler *handler)
	{
		m_pHandler = handler;
	}

	ZNSDKError TryWithMeetingNumber(unsigned long long meetingNumber)
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USEAGE;
		if (m_pHandler)
			err = m_pHandler->TryWithMeetingNumber(meetingNumber);
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}

	ZNSDKError TryWithPairingCode(ZoomSTRING paringCode)
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USEAGE;
		if (m_pHandler)
			err = m_pHandler->TryWithPairingCode(paringCode.c_str());
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}

	ZNSDKError Cancel()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USEAGE;
		if (m_pHandler)
			err = m_pHandler->Cancel();
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}
private:
	ZDirectShareViaMeetingIDOrPairingCodeHandler() :m_pHandler(NULL) {}
	ZOOM_SDK_NAMESPACE::IDirectShareViaMeetingIDOrPairingCodeHandler* m_pHandler;
};

class ZDirectShareHelperWrapEvent : public ZOOM_SDK_NAMESPACE::IDirectShareServiceHelperEvent
{
public:
	void SetOwner(ZDirectShareHelperWrap* obj) { owner_ = obj; }
	virtual void OnDirectShareStatusUpdate(ZOOM_SDK_NAMESPACE::DirectShareStatus status, ZOOM_SDK_NAMESPACE::IDirectShareViaMeetingIDOrPairingCodeHandler* handler)
	{

		if (owner_) {

			if ((status == ZOOM_SDK_NAMESPACE::DirectShare_Need_MeetingID_Or_PairingCode) || (status == ZOOM_SDK_NAMESPACE::DirectShare_WrongMeetingID_Or_SharingKey))
			{
				ZDirectShareViaMeetingIDOrPairingCodeHandler::GetInst().SetHandler(handler);
			}
			owner_->OnDirectShareStatusUpdate(Map2WrapDefine(status));
		}
	}
private:
	ZDirectShareHelperWrap* owner_;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZoomRetrieveSMSVerificationCodeHandler
{
public:
	static ZoomRetrieveSMSVerificationCodeHandler& GetInst()
	{
		static ZoomRetrieveSMSVerificationCodeHandler inst;
		return inst;
	}
	void SetHandler(IZoomRetrieveSMSVerificationCodeHandler* handler)
	{
		m_pHandler = handler;
	}
	bool Retrieve(const zTCHAR* country_code, const zTCHAR* phone_number)
	{
		bool b_ret = false;
		if (m_pHandler)
		{
			b_ret = m_pHandler->Retrieve(country_code, phone_number);
		}
		m_pHandler = NULL;
		return b_ret;
	}
	bool CancelAndLeaveMeeting()
	{
		bool b_ret = false;
		if (m_pHandler)
		{
			b_ret = m_pHandler->CancelAndLeaveMeeting();
		}
		m_pHandler = NULL;
		return b_ret;
	}
private:
	ZoomRetrieveSMSVerificationCodeHandler() :m_pHandler(NULL) {}
	IZoomRetrieveSMSVerificationCodeHandler* m_pHandler;
};
class ZoomVerifySMSVerificationCodeHandler
{
public:
	static ZoomVerifySMSVerificationCodeHandler& GetInst()
	{
		static ZoomVerifySMSVerificationCodeHandler inst;
		return inst;
	}
	void SetHandler(IZoomVerifySMSVerificationCodeHandler* handler)
	{
		m_pHandler = handler;
	}
	bool Verify(const zTCHAR* country_code, const zTCHAR* phone_number, const zTCHAR* verification_code)
	{
		bool b_ret = false;
		if (m_pHandler)
		{
			b_ret = m_pHandler->Verify(country_code, phone_number, verification_code);
		}
		m_pHandler = NULL;
		return b_ret;
	}
	bool CancelAndLeaveMeeting()
	{
		bool b_ret = false;
		if (m_pHandler)
		{
			b_ret = m_pHandler->CancelAndLeaveMeeting();
		}
		m_pHandler = NULL;
		return b_ret;
	}
private:
	ZoomVerifySMSVerificationCodeHandler() :m_pHandler(NULL) {}
	IZoomVerifySMSVerificationCodeHandler* m_pHandler;
};

class ZZoomRealNameAuthMeetingWrapEvent : public IZoomRealNameAuthMeetingEvent
{
public:
	void SetOwner(ZSDKSMSHelperWrap* obj) { owner_ = obj; }
	virtual void onNeedRealNameAuthMeetingNotification(IVector<IZoomRealNameAuthCountryInfo* >* support_country_list, const zTCHAR* privacy_url, IZoomRetrieveSMSVerificationCodeHandler* handler)
	{
		if (owner_ && support_country_list && handler)
		{
			ZoomRetrieveSMSVerificationCodeHandler::GetInst().SetHandler(handler);
			ZNList<ZNZoomRealNameAuthCountryInfo> SMSCountryInfo_list;
			for (int i = 0; i < support_country_list->GetCount(); ++i)
			{
				ZNZoomRealNameAuthCountryInfo countryInfo;
				IZoomRealNameAuthCountryInfo* temp_pCountryInfo = support_country_list->GetItem(i);
				if (temp_pCountryInfo)
				{
					countryInfo.countryID = (const wchar_t*)temp_pCountryInfo->GetCountryID();
					countryInfo.countryName = (const wchar_t*)temp_pCountryInfo->GetCountryName();
					countryInfo.countryCode = (const wchar_t*)temp_pCountryInfo->GetCountryCode();
				}
				SMSCountryInfo_list.push_back(countryInfo);
			}
			ZoomSTRING zn_privacy_url;
			zn_privacy_url = (const wchar_t*)privacy_url;
			owner_->onNeedRealNameAuthMeetingNotification(SMSCountryInfo_list, zn_privacy_url);
		}
	}
	virtual void onRetrieveSMSVerificationCodeResultNotification(SMSVerificationCodeErr result, IZoomVerifySMSVerificationCodeHandler* handler)
	{
		if (owner_)
		{
			if (SMSVerificationCodeErr_Success == result)
			{
				ZoomVerifySMSVerificationCodeHandler::GetInst().SetHandler(handler);
			}
			owner_->onRetrieveSMSVerificationCodeResultNotification(Map2WrapDefine(result));
		}
	}
	virtual void onVerifySMSVerificationCodeResultNotification(SMSVerificationCodeErr result)
	{
		if (owner_)
		{
			owner_->onRetrieveSMSVerificationCodeResultNotification(Map2WrapDefine(result));
		}
	}
private:
	ZSDKSMSHelperWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZAudioSettingContextWrapEvent : public ZOOM_SDK_NAMESPACE::IAudioSettingContextEvent
{
public:
	void SetOwner(ZSettingAudioWrap* obj) { owner_ = obj; }
	virtual void onComputerMicDeviceChanged(ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IMicInfo*>* pMicLst)
	{
		if (owner_)
		{
			ZNList<ZNMicInfo> zn_mic_list;
			if (pMicLst && pMicLst->GetCount() > 0)
			{
				int count = pMicLst->GetCount();
				for (int i = 0; i < count; i++)
				{
					ZOOM_SDK_NAMESPACE::IMicInfo* pMicInfo = pMicLst->GetItem(i);
					ZNMicInfo zn_mic_info;
					if (NULL == pMicInfo)
						continue;

					if (pMicInfo->GetDeviceName())
					{
						zn_mic_info.deviceName = pMicInfo->GetDeviceName();
					}
					if (pMicInfo->GetDeviceId())
					{
						zn_mic_info.deviceId = pMicInfo->GetDeviceId();
					}
					zn_mic_info.isSelectedDevice = pMicInfo->IsSelectedDevice();
					zn_mic_list.push_back(zn_mic_info);
				}
			}
			owner_->onComputerMicDeviceChanged(zn_mic_list);
		}
	}
	virtual void onComputerSpeakerDeviceChanged(ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::ISpeakerInfo*>* pSpeakerLst)
	{
		if (owner_)
		{
			ZNList<ZNSpeakerInfo> zn_speaker_list;
			if (pSpeakerLst && pSpeakerLst->GetCount() > 0)
			{
				int count = pSpeakerLst->GetCount();
				for (int i = 0; i < count; i++)
				{
					ZOOM_SDK_NAMESPACE::ISpeakerInfo* pSpeakerInfo = pSpeakerLst->GetItem(i);
					ZNSpeakerInfo zn_speaker_info;
					if (NULL == pSpeakerInfo)
						continue;

					if (pSpeakerInfo->GetDeviceName())
					{
						zn_speaker_info.deviceName = pSpeakerInfo->GetDeviceName();
					}
					if (pSpeakerInfo->GetDeviceId())
					{
						zn_speaker_info.deviceId = pSpeakerInfo->GetDeviceId();
					}
					zn_speaker_info.isSelectedDevice = pSpeakerInfo->IsSelectedDevice();
					zn_speaker_list.push_back(zn_speaker_info);
				}
			}
			owner_->onComputerSpeakerDeviceChanged(zn_speaker_list);
		}
	}
	virtual void onDefaultMicDeviceChanged(const wchar_t* deviceId, const wchar_t* deviceName)
	{
		if (owner_)
		{
			ZoomSTRING zn_deviceId;
			ZoomSTRING zn_deviceName;
			if (deviceId)
			{
				zn_deviceId = deviceId;
			}
			if (deviceName)
			{
				zn_deviceName = deviceName;
			}
			owner_->onDefaultMicDeviceChanged(zn_deviceId, zn_deviceName);
		}
	}
	virtual void onDefaultSpeakerDeviceChanged(const wchar_t* deviceId, const wchar_t* deviceName)
	{
		if (owner_)
		{
			ZoomSTRING zn_deviceId;
			ZoomSTRING zn_deviceName;
			if (deviceId)
			{
				zn_deviceId = deviceId;
			}
			if (deviceName)
			{
				zn_deviceName = deviceName;
			}
			owner_->onDefaultSpeakerDeviceChanged(zn_deviceId, zn_deviceName);
		}
	}
private:
	ZSettingAudioWrap* owner_;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZVideoSettingContextWrapEvent : public ZOOM_SDK_NAMESPACE::IVideoSettingContextEvent
{
public:
	void SetOwner(ZSettingVideoWrap* obj) { owner_ = obj; }
	virtual void onComputerCamDeviceChanged(ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::ICameraInfo*>* pCameraList)
	{
		if (owner_)
		{
			ZNList<ZNCameraInfo> zn_camera_list;
			if (pCameraList && pCameraList->GetCount() > 0)
			{
				int count = pCameraList->GetCount();
				for (int i = 0; i < count; i++)
				{
					ZOOM_SDK_NAMESPACE::ICameraInfo* pCameraInfo = pCameraList->GetItem(i);
					ZNCameraInfo zn_camera_info;
					if (NULL == pCameraInfo)
						continue;

					if (pCameraInfo->GetDeviceName())
					{
						zn_camera_info.deviceName = pCameraInfo->GetDeviceName();
					}
					if (pCameraInfo->GetDeviceId())
					{
						zn_camera_info.deviceId = pCameraInfo->GetDeviceId();
					}
					zn_camera_info.isSelectedDevice = pCameraInfo->IsSelectedDevice();
					zn_camera_list.push_back(zn_camera_info);
				}
			}
			owner_->onComputerCamDeviceChanged(zn_camera_list);

		}
	}
	virtual void onDefaultCamDeviceChanged(const wchar_t* deviceId, const wchar_t* deviceName)
	{
		if (owner_)
		{
			ZoomSTRING zn_deviceId;
			ZoomSTRING zn_deviceName;
			if (deviceId)
			{
				zn_deviceId = deviceId;
			}
			if (deviceName)
			{
				zn_deviceName = deviceName;
			}
			owner_->onDefaultCamDeviceChanged(zn_deviceId, zn_deviceName);
		}
	}

private:
	ZSettingVideoWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZRecordingSettingContextWrapEvent : public ZOOM_SDK_NAMESPACE::IRecordingSettingContextEvent
{
public:
	void SetOwner(ZSettingRecordingWrap* obj) { owner_ = obj; }
	virtual void onCloudRecordingStorageInfo(INT64 storage_total_size, INT64 storage_used_size, bool allow_exceed_storage)
	{
		if (owner_)
		{

			owner_->onCloudRecordingStorageInfo(storage_total_size, storage_used_size, allow_exceed_storage);
		}
	}
private:
	ZSettingRecordingWrap* owner_;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class SDKEventWrapMgr
{
public:
	//auth_service_cb
	ZAuthServiceWrapEvent m_authServiceWrapEvent;

	//meeting_service_cb
	ZMeetingServiceWrapEvent m_meetingServiceWrapEvent;

	//premeeting_service_cb
	ZPreMeetingServiceWrapEvent m_premeetingServiceWrapEvent;

	//meeting_ui_ctrl_cb
	ZMeetingUIControllerWrapEvent m_meetingUICtrlWrapEvent;

	//meeting_audio_ctrl_cb
	ZMeetingAudioCtrlWrapEvent m_meetingAudioCtrlWrapEvent;
	
	//meeting_video_ctrl_cb
	ZMeetingVideoCtrlWrapEvent m_meetingVideoCtrlWrapEvent;

	//meeting_share_ctrl_cb
	ZMeetingShareCtrlWrapEvent m_meetingShareCtrlWrapEvent;

	//meeting_participants_ctrl_cb
	ZMeetingParticipantsCtrlEvent m_meetingParticipantsCtrlEvent;

	//meeting_h323_ctrl_cb
	ZMeetingH323CtrlWrapEvent m_meetingH323CtrlWrapEvent;

	//meeting_config_ctrl_cb
	ZMeetingConfigCtrlWrapFreeMeetingEvent m_meetingConfigCtrlWrapEvent;

	//direct_share_helper_cb
	ZDirectShareHelperWrapEvent m_directShareHelperWrapEvent;

	//sms_helper_cb
	ZZoomRealNameAuthMeetingWrapEvent m_zoomRealNameAuthMeetingWrapEvent;

	//audio_setting_context_cb
	ZAudioSettingContextWrapEvent m_audioSettingContextWrapEvent;

	//video_setting_context_cb
	ZVideoSettingContextWrapEvent m_videoSettingContextWrapEvent;

	//recording_setting_context_cb
	ZRecordingSettingContextWrapEvent m_recordingSettingContextWrapEvent;


	static SDKEventWrapMgr& GetInst()
	{
		static SDKEventWrapMgr inst;
		return inst;
	}
	~SDKEventWrapMgr() {}
private:
	SDKEventWrapMgr() {}
};
#endif // !_sdk_sinks_wrap_class_h_
