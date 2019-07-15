

#include "../meeting_participants_wrap_core.h"
#include "../meeting_service_wrap_core.h"
#include "Header_include.h"
#include "sdk_native_error.h"

extern nativeErrorTypeHelp  Help_type;

ZMeetingParticipantsWrap &ZMeetingServiceWrap::GetMeetingParticipantsCtrl(){
    return m_meeting_participants_ctrl;
}


ZMeetingParticipantsWrap::ZMeetingParticipantsWrap(){
    m_pSink = 0;
}

ZMeetingParticipantsWrap::~ZMeetingParticipantsWrap(){
    m_pSink = 0;
    
}

void ZMeetingParticipantsWrap::Init(){
    
}

void ZMeetingParticipantsWrap::Uninit(){
    
}

void ZMeetingParticipantsWrap::SetSink(IZNativeSDKMeetingParticipantsWrapSink *pSink){
    
    m_pSink = pSink;
}


//callback
void ZMeetingParticipantsWrap::onHostChangeNotification(ZoomSTRING userId){
    
    if (m_pSink) {
        m_pSink->onHostChangeNotification(userId);
    }
}

void ZMeetingParticipantsWrap::onUserJoin(ZNList<ZoomSTRING> lstUserID, ZoomSTRING strUserList){
    
    if (m_pSink) {
        m_pSink->onUserJoin(lstUserID,strUserList);
    }
}


void ZMeetingParticipantsWrap::onUserLeft(ZNList<ZoomSTRING> lstUserID, ZoomSTRING strUserList){
    
    if (m_pSink) {
        m_pSink->onUserLeft(lstUserID,strUserList);
    }
}
