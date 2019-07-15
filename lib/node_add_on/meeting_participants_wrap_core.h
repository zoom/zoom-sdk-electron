#pragma once
#include "zoom_native_sdk_wrap_core_def.h"

class IZNativeSDKMeetingParticipantsWrapSink
{
public:
	//
	virtual void onUserJoin(ZNList<ZoomSTRING> lstUserID, ZoomSTRING strUserList) = 0;
	virtual void onUserLeft(ZNList<ZoomSTRING> lstUserID, ZoomSTRING strUserList) = 0;

	virtual void onHostChangeNotification(ZoomSTRING userId) = 0;
};
class ZMeetingParticipantsWrap
{
public:
	ZMeetingParticipantsWrap();
	virtual ~ZMeetingParticipantsWrap();
	void Init();
	void Uninit();
	void SetSink(IZNativeSDKMeetingParticipantsWrapSink* pSink);


	//callback

	void onUserJoin(ZNList<ZoomSTRING> lstUserID, ZoomSTRING strUserList);
	void onUserLeft(ZNList<ZoomSTRING> lstUserID, ZoomSTRING strUserList);
	void onHostChangeNotification(ZoomSTRING userId);
private:
	IZNativeSDKMeetingParticipantsWrapSink* m_pSink;

};
