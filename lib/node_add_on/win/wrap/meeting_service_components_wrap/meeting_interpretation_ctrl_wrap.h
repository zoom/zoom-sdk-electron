#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IMeetingInterpretationController* InitIMeetingInterpretationControllerFunc(IMeetingInterpretationControllerEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIMeetingInterpretationControllerFunc(IMeetingInterpretationController* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IMeetingInterpretationController, IMeetingInterpretationControllerEvent)
NORMAL_CLASS(IMeetingInterpretationController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IMeetingInterpretationController, IMeetingServiceWrap)
virtual SDKError SetEvent(IMeetingInterpretationControllerEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}

//virtual bool IsInterpretationEnabled() = 0;
DEFINE_FUNC_0(IsInterpretationEnabled, bool)
//virtual bool IsInterpretationStarted() = 0;
DEFINE_FUNC_0(IsInterpretationStarted, bool)
//virtual bool IsInterpreter() = 0;
DEFINE_FUNC_0(IsInterpreter, bool)
//virtual IInterpretationLanguage* GetInterpretationLanguageByID(int lanID) = 0;
DEFINE_FUNC_1(GetInterpretationLanguageByID, IInterpretationLanguage*, int, lanID)
//virtual IList<IInterpretationLanguage*>* GetAllLanguageList() = 0;
DEFINE_FUNC_0(GetAllLanguageList, IList<IInterpretationLanguage*>*)
//virtual IList<IInterpreter*>* GetInterpreterList() = 0;
DEFINE_FUNC_0(GetInterpreterList, IList<IInterpreter*>*)
//virtual SDKError AddInterpreter(unsigned int userID, int lanID1, int lanID2) = 0;
DEFINE_FUNC_3(AddInterpreter, SDKError, unsigned int, userID, int, lanID1, int, lanID2)
//virtual SDKError RemoveInterpreter(unsigned int userID) = 0;
DEFINE_FUNC_1(RemoveInterpreter, SDKError, unsigned int, userid)
//virtual SDKError ModifyInterpreter(unsigned int userID, int lanID1, int lanID2) = 0;
DEFINE_FUNC_3(ModifyInterpreter, SDKError, unsigned int, userID, int, lanID1, int, lanID2)
//virtual SDKError StartInterpretation() = 0;
DEFINE_FUNC_0(StartInterpretation, SDKError)
//virtual SDKError StopInterpretation() = 0;
DEFINE_FUNC_0(StopInterpretation, SDKError)
//virtual IList<IInterpretationLanguage*>* GetAvailableLanguageList() = 0;
DEFINE_FUNC_0(GetAvailableLanguageList, IList<IInterpretationLanguage*>*)
//virtual SDKError JoinLanguageChannel(int lanID) = 0;
DEFINE_FUNC_1(JoinLanguageChannel, SDKError, int, lanID)
//virtual SDKError GetJoinedLanguageID(int& lanID) = 0;
DEFINE_FUNC_1(GetJoinedLanguageID, SDKError, int&, lanID)
//virtual SDKError TurnOffMajorAudio() = 0;
DEFINE_FUNC_0(TurnOffMajorAudio, SDKError)
//virtual SDKError TurnOnMajorAudio() = 0;
DEFINE_FUNC_0(TurnOnMajorAudio, SDKError)
//virtual SDKError IsMajorAudioTurnOff(bool& bOff) = 0;
DEFINE_FUNC_1(IsMajorAudioTurnOff, SDKError, bool&, bOff)
//virtual SDKError GetInterpreterLans(int& lanID1, int& lanID2) = 0;
DEFINE_FUNC_2(GetInterpreterLans, SDKError, int&, landID1, int&, lanID2)
//virtual SDKError SetInterpreterActiveLan(int activeLanID) = 0;
DEFINE_FUNC_1(SetInterpreterActiveLan, SDKError, int, activeLanID)
//virtual SDKError GetInterpreterActiveLan(int& lanID) = 0;
DEFINE_FUNC_1(GetInterpreterActiveLan, SDKError, int&, lanID)


//virtual void OnInterpretationStart() = 0;
CallBack_FUNC_0(OnInterpretationStart)
//virtual void OnInterpretationStop() = 0;
CallBack_FUNC_0(OnInterpretationStop)
//virtual void OnInterpreterListChanged() = 0;
CallBack_FUNC_0(OnInterpreterListChanged)
//virtual void OnInterpreterRoleChanged(unsigned int userID, bool isInterpreter) = 0;
CallBack_FUNC_2(OnInterpreterRoleChanged, unsigned int, userID, bool, isInterpreter)
//virtual void OnInterpreterActiveLanguageChanged(unsigned int userID, int activeLanID) = 0;
CallBack_FUNC_2(OnInterpreterActiveLanguageChanged, unsigned int, userID, int, activeLanID)
//virtual void OnInterpreterLanguageChanged(int lanID1, int lanID2) = 0;
CallBack_FUNC_2(OnInterpreterLanguageChanged, int, lanID1, int, lanID2)
//virtual void OnAvailableLanguageListUpdated(IList<IInterpretationLanguage*>* pAvailableLanguageList) = 0;
CallBack_FUNC_1(OnAvailableLanguageListUpdated, IList<IInterpretationLanguage*>*, pAvailableLanguageList)

END_CLASS_DEFINE(IMeetingInterpretationController)
END_ZOOM_SDK_NAMESPACE