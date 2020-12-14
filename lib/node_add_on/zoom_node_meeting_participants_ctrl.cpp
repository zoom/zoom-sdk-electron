#include "zoom_node_meeting_participants_ctrl.h"

ZoomNodeMeetingParticipantsCtrlWrap::ZoomNodeMeetingParticipantsCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingParticipantsCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_meetingParticipantsWrapSink);
}

ZoomNodeMeetingParticipantsCtrlWrap::~ZoomNodeMeetingParticipantsCtrlWrap()
{

}
void ZoomNodeMeetingParticipantsCtrlWrap::SetMeetingUserJoinCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onUserJoin.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onUserJoin = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingParticipantsCtrlWrap::SetMeetingUserLeftCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onUserLeft.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onUserLeft = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingParticipantsCtrlWrap::SetMeetingHostChangeCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onHostChangeNotification.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onHostChangeNotification = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingParticipantsCtrlWrap::GetParticipantsList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNList<unsigned int> zn_userID_lst;
	zn_userID_lst = _g_native_wrap.GetMeetingServiceWrap().GetMeetingParticipantsCtrl().GetParticipantsList();

	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_userID_lst.size(); ++i) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "userid", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_userID_lst[i]));
		nodes->Set(context, i, node);
	}
	args.GetReturnValue().Set(nodes);
}
void ZoomNodeMeetingParticipantsCtrlWrap::GetUserInfoByUserID(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	com::electron::sdk::proto::GetUserInfoByUserIDParams proto_params;
	if (!SetProtoParam<com::electron::sdk::proto::GetUserInfoByUserIDParams >(args, proto_params))
	{
		return;
	}
	if (!proto_params.has_userid())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong proto params", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	unsigned int _zn_userID = proto_params.userid();

	ZNUserInfomation zn_userInfomation;
	zn_userInfomation = _g_native_wrap.GetMeetingServiceWrap().GetMeetingParticipantsCtrl().GetUserInfomationByUserID(_zn_userID);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "userName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_userInfomation.userName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
	node->Set(context, v8::String::NewFromUtf8(isolate, "isH323User", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfomation.isH323User));
	node->Set(context, v8::String::NewFromUtf8(isolate, "isHost", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfomation.isHost));
	node->Set(context, v8::String::NewFromUtf8(isolate, "userID", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_userInfomation.userID));
	node->Set(context, v8::String::NewFromUtf8(isolate, "isVideoOn", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfomation.isVideoOn));
	node->Set(context, v8::String::NewFromUtf8(isolate, "isAudioMuted", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfomation.isAudioMuted));
	node->Set(context, v8::String::NewFromUtf8(isolate, "isMySelf", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfomation.isMySelf));
	node->Set(context, v8::String::NewFromUtf8(isolate, "userRole", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_userInfomation.userRole));
	node->Set(context, v8::String::NewFromUtf8(isolate, "isPurePhoneUser", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfomation.isPurePhoneUser));
	node->Set(context, v8::String::NewFromUtf8(isolate, "WebinarAtendeeStatus", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfomation.webinarAttendeeStatus));
	node->Set(context, v8::String::NewFromUtf8(isolate, "userInfoType", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_userInfomation.userInfoType));
	node->Set(context, v8::String::NewFromUtf8(isolate, "participantID", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_userInfomation.participantID).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
#if (defined _WIN32)
	node->Set(context, v8::String::NewFromUtf8(isolate, "audioJoinType", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_userInfomation.audioJoinType));
	node->Set(context, v8::String::NewFromUtf8(isolate, "isInWaitingRoom", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfomation.isInWaitingRoom));
	node->Set(context, v8::String::NewFromUtf8(isolate, "isRaiseHand", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfomation.isRaiseHand));
	node->Set(context, v8::String::NewFromUtf8(isolate, "audioVoiceLevel", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_userInfomation.AudioVoiceLevel).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
	node->Set(context, v8::String::NewFromUtf8(isolate, "isClosedCaptionSender", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_userInfomation.isClosedCaptionSender));
#endif

	args.GetReturnValue().Set(node);
}



