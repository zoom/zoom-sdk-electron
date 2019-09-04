#ifndef _zoom_sinks_wrap_class_h_
#define _zoom_sinks_wrap_class_h_
#include "zoom_node_common_include.h"
#include "zoom_singleton_wrap_class.h"

class ZNativeSDKAuthWrapSink
{
public:
	/// \brief Authentication result callback.
	/// \param authResult Authentication result value.  For more details, see \link ZNAuthResult \endlink enum.
	virtual void onAuthenticationReturn(ZNAuthResult authResult)
	{
		if (ZoomNodeSinkHelper::GetInst().onAuthenticationReturn.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_authresult = v8::Integer::New(isolate, (int32_t)authResult);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_authresult };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onAuthenticationReturn);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback of login result.
	/// \param ret Login status. see \link ZNLOGINSTATUS \endlink enum.
	virtual void onLoginRet(ZNLOGINSTATUS ret)
	{
		if (ZoomNodeSinkHelper::GetInst().onLoginRet.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_loginstatus = v8::Integer::New(isolate, (int32_t)ret);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_loginstatus };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onLoginRet);
		fn->Call(context, global, argc, argv);
	}
	/// \brief Logout result callback.
	virtual void onLogout()
	{
		if (ZoomNodeSinkHelper::GetInst().onLogout.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onLogout);
		fn->Call(context, global, 0, NULL);
	}
	/// \brief Zoom identity has expired, please re-login or generate a new zoom access token.
	virtual void onZoomIdentityExpired()
	{
		if (ZoomNodeSinkHelper::GetInst().onZoomIdentityExpired.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onZoomIdentityExpired);
		fn->Call(context, global, 0, NULL);
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingWrapSink
{
public:
	/// \brief Meeting status changed callback.
	/// \param status The value of meeting. For more details, see \link ZNMeetingStatus \endlink.
	/// \param iResult Detailed reasons for special meeting status.
	///If the status is ZNMEETING_STATUS_FAILED, the value of iResult is one of those listed in \link ZNMeetingFailCode \endlink enum. 
	///If the status is ZNMEETING_STATUS_ENDED, the value of iResult is one of those listed in \link ZNMeetingEndReason \endlink enum.
	virtual void onMeetingStatusChanged(ZNMeetingStatus meetingStatus, int iResult)
	{
		if (ZoomNodeSinkHelper::GetInst().onMeetingStatusChanged.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer > v8_meeting_status = v8::Integer::New(isolate, (int32_t)meetingStatus);
		v8::Local<v8::Integer > v8_result = v8::Integer::New(isolate, (int32_t)iResult);
		int argc = 2;
		v8::Local<v8::Value> argv[2] = { v8_meeting_status, v8_result };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onMeetingStatusChanged);

		fn->Call(context, global, argc, argv);
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKPreMeetingWrapSink
{
public:
	/// \brief Schedule or edit meeting callback event.
	/// \param result The result of calling ScheduleMeeting, ScheduleMeetingWithWndParams, EditMeeting or EditMeetingWithWndParams. 
	///For more details, see \link ZNPremeetingAPIResult \endlink enum.
	/// \param meetingUniqueID The meeting ID to schedule or edit the meeting.
	virtual void onScheduleOrEditMeeting(ZNPremeetingAPIResult result, unsigned long long meetingUniqueID)
	{

		if (ZoomNodeSinkHelper::GetInst().onScheduleOrEditMeeting.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();


		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(v8::String::NewFromUtf8(isolate, "MeetingUniqueID"), v8::Number::New(isolate, (unsigned long long)meetingUniqueID));
		node->Set(v8::String::NewFromUtf8(isolate, "PremeetingAPIResult"), v8::Integer::New(isolate, (int32_t)result));

		//
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onScheduleOrEditMeeting);

		fn->Call(context, global, argc, argv);
	}
	/// \brief List meeting callback event.
	/// \param result The result of calling ListMeeting. For more details, see \link ZNPremeetingAPIResult \endlink enum.
	/// \param lst_meeting_list A list of meeting ID. 
	virtual void onListMeeting(ZNPremeetingAPIResult result, ZNList<unsigned long long> lst_meeting_list)
	{
		if (ZoomNodeSinkHelper::GetInst().onListMeeting.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Object> bret = v8::Object::New(isolate);

		v8::Local<v8::Array> nodes = v8::Array::New(isolate);
		v8::Local<v8::Value> arrayname = v8::String::NewFromUtf8(isolate, "meeting_list", v8::NewStringType::kInternalized).ToLocalChecked();
		for (unsigned int i = 0; i < lst_meeting_list.size(); ++i) {
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(v8::String::NewFromUtf8(isolate, "meetingID"), v8::Number::New(isolate, (unsigned long long)lst_meeting_list[i]));
			nodes->Set(i, node);
		}

		v8::Local<v8::Value> resultname = v8::String::NewFromUtf8(isolate, "premeeting_api_result", v8::NewStringType::kInternalized).ToLocalChecked();
		v8::Local<v8::Integer> zn_result = v8::Integer::New(isolate, (int32_t)result);

		bret->Set(isolate->GetCurrentContext(), resultname, zn_result);
		bret->Set(isolate->GetCurrentContext(), arrayname, nodes);


		//
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { bret };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onListMeeting);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Delete meeting callback.
	/// \param result The result of calling DeleteMeeting. For more details, see \link ZNPremeetingAPIResult \endlink enum.
	virtual void onDeleteMeeting(ZNPremeetingAPIResult result)
	{

		if (ZoomNodeSinkHelper::GetInst().onDeleteMeeting.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();


		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(v8::String::NewFromUtf8(isolate, "PremeetingAPIResult"), v8::Integer::New(isolate, (int32_t)result));

		//
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onDeleteMeeting);

		fn->Call(context, global, argc, argv);
	}
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingUICtrlWrapSink
{
public:
	/// \brief Callback event to click the INVITE button.
	/// \param [out] bHandled True indicates to show the user's own custom dialog interface. Default value: FALSE.
	/// \remarks If the value of bHandled is not set to TRUE, the default interface will pop up. 
	virtual void onInviteBtnClicked(bool& bHandled)
	{
		if (ZoomNodeSinkHelper::GetInst().onInviteBtnClicked.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Boolean > v8_bHandled = v8::Boolean::New(isolate, bHandled);

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_bHandled };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onInviteBtnClicked);

		fn->Call(context, global, argc, argv);
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingAudioWrapSink
{
public:
	/// \brief User's audio status changed callback.
	/// \param lstAudioStatusChange List of the user information with audio status changed. The list will be emptied once the function calls end. 
	///For more user audio status infomation, see \link ZNAudioStatus \endlink enum.
	virtual void onUserAudioStatusChange(ZNList<ZNUserAudioStatus> lstAudioStatusChange, ZoomSTRING strAudioStatusList)
	{

		if (ZoomNodeSinkHelper::GetInst().onUserAudioStatusChange.IsEmpty())
		{
			return;
		}


		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Array> nodes = v8::Array::New(isolate);
		for (unsigned int i = 0; i < lstAudioStatusChange.size(); ++i) {
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(v8::String::NewFromUtf8(isolate, "userid"), v8::Integer::New(isolate, (int32_t)lstAudioStatusChange[i].userId));
			node->Set(v8::String::NewFromUtf8(isolate, "audioStauts"), v8::Integer::New(isolate, (int32_t)lstAudioStatusChange[i].audioStauts));
			nodes->Set(i, node);
		}
		//
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { nodes };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onUserAudioStatusChange);

		fn->Call(context, global, argc, argv);
	}
	/// \brief The callback event that users whose audio is active changed.
	/// \param lstActiveAudio List to store the ID of user whose audio is active.
	virtual void onUserActiveAudioChange(ZNList<unsigned int > lstActiveAudio)
	{

		if (ZoomNodeSinkHelper::GetInst().onUserActiveAudioChange.IsEmpty())
		{
			return;
		}

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Array> nodes = v8::Array::New(isolate);
		for (unsigned int i = 0; i < lstActiveAudio.size(); ++i) {
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(v8::String::NewFromUtf8(isolate, "userid"), v8::Integer::New(isolate, (int32_t)lstActiveAudio[i]));
			nodes->Set(i, node);
		}
		//
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { nodes };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onUserActiveAudioChange);

		fn->Call(context, global, argc, argv);
	}
};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ZNativeSDKMeetingVideoWrapSink
{
public:
	/// \brief Callback event of the user video status changes.
	/// \param userId The user ID whose video status changes
	/// \param status New video status. For more details, see \link ZNVideoStatus \endlink enum.
	virtual void onUserVideoStatusChange(unsigned int userId, ZNVideoStatus status)
	{
		if (ZoomNodeSinkHelper::GetInst().onUserVideoStatusChange.IsEmpty())
		{
			return;
		}

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(v8::String::NewFromUtf8(isolate, "userId"), v8::Integer::New(isolate, (int32_t)userId));
		node->Set(v8::String::NewFromUtf8(isolate, "videoStatus"), v8::Integer::New(isolate, (int32_t)status));

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onUserVideoStatusChange);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback event of the active speaker video user changes. 
	/// \param userid The ID of user who becomes the new active speaker.
	virtual void onActiveSpeakerVideoUserChanged(unsigned int userId)
	{
		if (ZoomNodeSinkHelper::GetInst().onActiveSpeakerVideoUserChanged.IsEmpty())
		{
			return;
		}
		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();
		v8::Local<v8::Integer> zn_userid = v8::Integer::New(isolate, (int32_t)userId);

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { zn_userid };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onActiveSpeakerVideoUserChanged);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback event of the active video user changes. 
	/// \param userid The ID of user who becomes the new active speaker.
	virtual void onActiveVideoUserChanged(unsigned int userId)
	{
		if (ZoomNodeSinkHelper::GetInst().onActiveVideoUserChanged.IsEmpty())
		{
			return;
		}
		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();
		v8::Local<v8::Integer> zn_userid = v8::Integer::New(isolate, (int32_t)userId);

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { zn_userid };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onActiveVideoUserChanged);

		fn->Call(context, global, argc, argv);
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingShareWrapSink
{
public:
	/// \brief Callback event of the changed sharing status. 
	/// \param status The values of sharing status. For more details, see \link ZNShareStatus \endlink enum.
	/// \param userId Sharer ID. 
	/// \remarks The userId changes according to the status value. When the status value is the ZN_Sharing_Self_Send_Begin or ZN_Sharing_Self_Send_End, the userId is the user own ID. Otherwise, the value of userId is the sharer ID.
	virtual void onSharingStatus(ZNShareStatus status, unsigned int userId)
	{
		if (ZoomNodeSinkHelper::GetInst().onSharingStatus.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();


		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(v8::String::NewFromUtf8(isolate, "userId"), v8::Integer::New(isolate, (int32_t)userId));
		node->Set(v8::String::NewFromUtf8(isolate, "ShareStatus"), v8::Integer::New(isolate, (int32_t)status));

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onSharingStatus);

		fn->Call(context, global, argc, argv);
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingParticipantsWrapSink
{
public:
	/// \brief Callback event of notification of users who are in the meeting.
	/// \param lstUserID List of the user ID. 
	/// \param strUserList List of user in json format. This function is currently invalid, hereby only for reservations.
	virtual void onUserJoin(ZNList<unsigned int> lstUserID, ZoomSTRING strUserList)
	{

		if (ZoomNodeSinkHelper::GetInst().onUserJoin.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Array> nodes = v8::Array::New(isolate);
		for (unsigned int i = 0; i < lstUserID.size(); ++i) {
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(v8::String::NewFromUtf8(isolate, "userid"), v8::Integer::New(isolate, (int32_t)lstUserID[i]));
			nodes->Set(i, node);
		}
		//
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { nodes };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onUserJoin);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback event of notification of user who leaves the meeting.
	/// \param lstUserID List of the user ID who leaves the meeting.
	/// \param strUserList List of the user in json format. This function is currently invalid, hereby only for reservations.
	virtual void onUserLeft(ZNList<unsigned int> lstUserID, ZoomSTRING strUserList)
	{

		if (ZoomNodeSinkHelper::GetInst().onUserLeft.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Array> nodes = v8::Array::New(isolate);
		for (unsigned int i = 0; i < lstUserID.size(); ++i) {
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(v8::String::NewFromUtf8(isolate, "userid"), v8::Integer::New(isolate, (int32_t)lstUserID[i]));
			nodes->Set(i, node);
		}
		//
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { nodes };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onUserLeft);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback event of notification of the new host. 
	/// \param userId Specify the ID of the new host.
	virtual void onHostChangeNotification(unsigned int userId)
	{

		if (ZoomNodeSinkHelper::GetInst().onHostChangeNotification.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_userid = v8::Integer::New(isolate, (int32_t)userId);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_userid };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onHostChangeNotification);

		fn->Call(context, global, argc, argv);
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingH323WrapSink
{
public:
	/// \brief Callback event when the calling status of H.323 device changes.
	/// \param status H.323 device calling out status value. For more details, see \link ZNH323CalloutStatus \endlink enum.
	virtual void onH323CalloutStatusNotify(ZNH323CalloutStatus status)
	{
		if (ZoomNodeSinkHelper::GetInst().onH323CalloutStatusNotify.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_h323CalloutStatus = v8::Integer::New(isolate, (int32_t)status);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_h323CalloutStatus };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onH323CalloutStatusNotify);

		fn->Call(context, global, argc, argv);
	}
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingConfigWrapFreemeetingSink
{
public:
	/// \brief The callback of upgrading the free meeting.
	/// \param type Type of upgrading the free meeting, see \link ZNFreeMeetingNeedUpgradeType \endlink enum.
	/// \param gift_url Upgrade the free meeting by the gift link. When and only when the value of type is ZN_FreeMeetingNeedUpgradeType_BY_GIFTURL, this parameter is meaningful.
	virtual void onFreeMeetingNeedToUpgrade(ZNFreeMeetingNeedUpgradeType type, ZoomSTRING gift_url)
	{
		if (ZoomNodeSinkHelper::GetInst().onFreeMeetingNeedToUpgrade.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(v8::String::NewFromUtf8(isolate, "giftUrl"), v8::String::NewFromUtf8(isolate, zs2s(gift_url).c_str()));
		node->Set(v8::String::NewFromUtf8(isolate, "freeMeetingNeedUpgradeType"), v8::Integer::New(isolate, (int32_t)type));

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onFreeMeetingNeedToUpgrade);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback function of starting to upgrade the free meeting by the gift link.
	virtual void onFreeMeetingUpgradeToGiftFreeTrialStart()
	{
		if (ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStart.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		int32_t temp = 0;
		v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)temp);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { bret };

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStart);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback function of ending upgrade the free meeting by the gift link.
	virtual void onFreeMeetingUpgradeToGiftFreeTrialStop()
	{
		if (ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStop.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		int32_t temp = 0;
		v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)temp);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { bret };

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStop);

		fn->Call(context, global, argc, argv);
	}
	/// \brief Callback function of free meting upgrades successfully.
	virtual void onFreeMeetingUpgradeToProMeeting()
	{
		if (ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToProMeeting.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		int32_t temp = 0;
		v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)temp);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { bret };

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToProMeeting);

		fn->Call(context, global, argc, argv);
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKDirectShareHelperWrapSink
{
public:
	/// \brief The callback event will be triggered if the status of direct sharing changes.
	/// \param status Specifies the status of direct sharing. For more details, see \link ZNDirectShareStatus \endlink enum.
	///When the value of status is ZN_DirectShare_Need_MeetingID_Or_PairingCode, the SDK user must set the value of 
	///the _paring_code or _meeting_number via the functions TryWithPairingCode or TryWithMeetingNumber to start direct sharing.
	virtual void OnDirectShareStatusUpdate(ZNDirectShareStatus status)
	{
		if (ZoomNodeSinkHelper::GetInst().OnDirectShareStatusUpdate.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();


		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(v8::String::NewFromUtf8(isolate, "DirectShareStatus"), v8::Integer::New(isolate, (int32_t)status));

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().OnDirectShareStatusUpdate);

		fn->Call(context, global, argc, argv);


	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZoomNodeSinkWrapMgr
{
public:
	//auth_service_cb
	ZNativeSDKAuthWrapSink m_authServiceWrapSink;

	//meeting_service_cb
	ZNativeSDKMeetingWrapSink m_meetingServiceWrapSink;

	//premeeting_service_cb
	ZNativeSDKPreMeetingWrapSink m_premeetingServiceWrapSink;

	//meeting_ui_ctrl_cb
	ZNativeSDKMeetingUICtrlWrapSink m_meetingUICtrlWrapSink;

	//meeting_audio_ctrl_cb
	ZNativeSDKMeetingAudioWrapSink m_meetingAudioCtrlWrapSink;
	
	//meeting_video_ctrl_cb
	ZNativeSDKMeetingVideoWrapSink m_meetingVideoWrapSink;

	//meeting_share_ctrl_cb
	ZNativeSDKMeetingShareWrapSink m_meetingShareWrapSink;

	//meeting_participants_ctrl_cb
	ZNativeSDKMeetingParticipantsWrapSink m_meetingParticipantsWrapSink;

	//meeting_h323_ctrl_cb
	ZNativeSDKMeetingH323WrapSink m_meetingH323WrapSink;

	//meeting_config_ctrl_cb
	ZNativeSDKMeetingConfigWrapFreemeetingSink m_meetingConfigWrapFreeMeetingSink;

	//direct_share_helper_cb
	ZNativeSDKDirectShareHelperWrapSink m_directShareHelperWrapSink;


	static ZoomNodeSinkWrapMgr& GetInst()
	{
		static ZoomNodeSinkWrapMgr inst;
		return inst;
	}
	~ZoomNodeSinkWrapMgr() {}
private:
	ZoomNodeSinkWrapMgr() {}
};
#endif // !_zoom_sinks_wrap_class_h_
