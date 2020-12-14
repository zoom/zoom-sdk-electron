#include "zoom_node_meeting_video_ctrl.h"

ZoomNodeMeetingVideoCtrlWrap::ZoomNodeMeetingVideoCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_meetingVideoWrapSink);
}

ZoomNodeMeetingVideoCtrlWrap::~ZoomNodeMeetingVideoCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().SetSink(NULL);
}
void ZoomNodeMeetingVideoCtrlWrap::MuteVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::MuteVideoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::MuteVideoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().MuteVideo(_zn_userid);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::UnMuteVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::UnMuteVideoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::UnMuteVideoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().UnMuteVideo(_zn_userid);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::PinVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::PinVideoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::PinVideoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bfirstview() ||
			!proto_params.has_bpin() ||
			!proto_params.has_userid()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bPin = false;
		convertBool(proto_params.bpin(), _bPin);
		bool _bFirstView = false;
		convertBool(proto_params.bfirstview(), _bFirstView);
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().PinVideo(_bPin, _bFirstView, _zn_userid);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::SpotlightVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SpotlightVideoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SpotlightVideoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bspotlight() ||
			!proto_params.has_userid()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bSpotlight = false;
		convertBool(proto_params.bspotlight(), _bSpotlight);
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().SpotlightVideo(_bSpotlight, _zn_userid);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::HideOrShowNoVideoUserOnVideoWall(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::HideOrShowNoVideoUserOnVideoWallParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::HideOrShowNoVideoUserOnVideoWallParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bhide())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bHide;
		convertBool(proto_params.bhide(), _bHide);

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().HideOrShowNoVideoUserOnVideoWall(_bHide);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::SetMeetingVideoStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onUserVideoStatusChange.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onUserVideoStatusChange = cb;

		ZNSDKError err = ZNSDKERR_SUCCESS;
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::SetActiveSpeakerVideoUserChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onActiveSpeakerVideoUserChanged.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onActiveSpeakerVideoUserChanged = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::SetActiveVideoUserChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onActiveVideoUserChanged.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onActiveVideoUserChanged = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
