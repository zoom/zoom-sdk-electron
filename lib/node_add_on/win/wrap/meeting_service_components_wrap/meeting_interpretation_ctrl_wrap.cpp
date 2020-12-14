#include "meeting_interpretation_ctrl_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingInterpretationController* InitIMeetingInterpretationControllerFunc(IMeetingInterpretationControllerEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingInterpretationController* pObj = pOwner->GetSDKObj()->GetMeetingInterpretationController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingInterpretationControllerFunc(IMeetingInterpretationController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual bool IsInterpretationEnabled() = 0;
IMPL_FUNC_0(IMeetingInterpretationController, IsInterpretationEnabled, bool, false)
//virtual bool IsInterpretationStarted() = 0;
IMPL_FUNC_0(IMeetingInterpretationController, IsInterpretationStarted, bool, false)
//virtual bool IsInterpreter() = 0;
IMPL_FUNC_0(IMeetingInterpretationController, IsInterpreter, bool, false)
//virtual IInterpretationLanguage* GetInterpretationLanguageByID(int lanID) = 0;
IMPL_FUNC_1(IMeetingInterpretationController, GetInterpretationLanguageByID, IInterpretationLanguage*, int, lanID, NULL)
//virtual IList<IInterpretationLanguage*>* GetAllLanguageList() = 0;
IMPL_FUNC_0(IMeetingInterpretationController, GetAllLanguageList, IList<IInterpretationLanguage*>*, NULL)
//virtual IList<IInterpreter*>* GetInterpreterList() = 0;
IMPL_FUNC_0(IMeetingInterpretationController, GetInterpreterList, IList<IInterpreter*>*, NULL)
//virtual SDKError AddInterpreter(unsigned int userID, int lanID1, int lanID2) = 0;
IMPL_FUNC_3(IMeetingInterpretationController, AddInterpreter, SDKError, unsigned int, userID, int, lanID1, int, lanID2, SDKERR_UNINITIALIZE)
//virtual SDKError RemoveInterpreter(unsigned int userID) = 0;
IMPL_FUNC_1(IMeetingInterpretationController, RemoveInterpreter, SDKError, unsigned int, userid, SDKERR_UNINITIALIZE)
//virtual SDKError ModifyInterpreter(unsigned int userID, int lanID1, int lanID2) = 0;
IMPL_FUNC_3(IMeetingInterpretationController, ModifyInterpreter, SDKError, unsigned int, userID, int, lanID1, int, lanID2, SDKERR_UNINITIALIZE)
//virtual SDKError StartInterpretation() = 0;
IMPL_FUNC_0(IMeetingInterpretationController, StartInterpretation, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError StopInterpretation() = 0;
IMPL_FUNC_0(IMeetingInterpretationController, StopInterpretation, SDKError, SDKERR_UNINITIALIZE)
//virtual IList<IInterpretationLanguage*>* GetAvailableLanguageList() = 0;
IMPL_FUNC_0(IMeetingInterpretationController, GetAvailableLanguageList, IList<IInterpretationLanguage*>*, NULL)
//virtual SDKError JoinLanguageChannel(int lanID) = 0;
IMPL_FUNC_1(IMeetingInterpretationController, JoinLanguageChannel, SDKError, int, lanID, SDKERR_UNINITIALIZE)
//virtual SDKError GetJoinedLanguageID(int& lanID) = 0;
IMPL_FUNC_1(IMeetingInterpretationController, GetJoinedLanguageID, SDKError, int&, lanID, SDKERR_UNINITIALIZE)
//virtual SDKError TurnOffMajorAudio() = 0;
IMPL_FUNC_0(IMeetingInterpretationController, TurnOffMajorAudio, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError TurnOnMajorAudio() = 0;
IMPL_FUNC_0(IMeetingInterpretationController, TurnOnMajorAudio, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError IsMajorAudioTurnOff(bool& bOff) = 0;
IMPL_FUNC_1(IMeetingInterpretationController, IsMajorAudioTurnOff, SDKError, bool&, bOff, SDKERR_UNINITIALIZE)
//virtual SDKError GetInterpreterLans(int& lanID1, int& lanID2) = 0;
IMPL_FUNC_2(IMeetingInterpretationController, GetInterpreterLans, SDKError, int&, landID1, int&, lanID2, SDKERR_UNINITIALIZE)
//virtual SDKError SetInterpreterActiveLan(int activeLanID) = 0;
IMPL_FUNC_1(IMeetingInterpretationController, SetInterpreterActiveLan, SDKError, int, activeLanID, SDKERR_UNINITIALIZE)
//virtual SDKError GetInterpreterActiveLan(int& lanID) = 0;
IMPL_FUNC_1(IMeetingInterpretationController, GetInterpreterActiveLan, SDKError, int&, lanID, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE