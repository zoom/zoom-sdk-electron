#include "zoom_node_meeting_recording_ctrl.h"

ZoomNodeMeetingRecordingCtrlWrap::ZoomNodeMeetingRecordingCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_meetingRecordingWrapSink);
}

ZoomNodeMeetingRecordingCtrlWrap::~ZoomNodeMeetingRecordingCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().SetSink(NULL);
}
void ZoomNodeMeetingRecordingCtrlWrap::StartRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	time_t _zn_startTimestamp = 0;
	ZoomSTRING _zn_recPath;
	do
	{
		com::electron::sdk::proto::StartRecordingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::StartRecordingParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_recpath())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		_zn_recPath = s2zs(proto_params.recpath());

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().StartRecording(_zn_startTimestamp, _zn_recPath);
	} while (false);
	
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "startTimestamp", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int64_t)_zn_startTimestamp));

	args.GetReturnValue().Set(node);
}
void ZoomNodeMeetingRecordingCtrlWrap::StopRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	
	time_t zn_stopTimestamp = 0;

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().StopRecording(zn_stopTimestamp);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "stopTimestamp", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int64_t)zn_stopTimestamp));

	args.GetReturnValue().Set(node);
}
void ZoomNodeMeetingRecordingCtrlWrap::CanStartRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::CanStartRecordingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::CanStartRecordingParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bcloudrecording() ||
			!proto_params.has_userid()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bCloudRecording = false;
		convertBool(proto_params.bcloudrecording(), _bCloudRecording);
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().CanStartRecording(_bCloudRecording, _zn_userid);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRecordingCtrlWrap::CanAllowDisAllowLocalRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().CanAllowDisAllowLocalRecording();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRecordingCtrlWrap::StartCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().StartCloudRecording();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRecordingCtrlWrap::StopCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().StopCloudRecording();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRecordingCtrlWrap::IsSupportLocalRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::IsSupportLocalRecordingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::IsSupportLocalRecordingParams >(args, proto_params))
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

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().IsSupportLocalRecording(_zn_userid);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRecordingCtrlWrap::AllowLocalRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::AllowLocalRecordingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::AllowLocalRecordingParams >(args, proto_params))
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

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().AllowLocalRecording(_zn_userid);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRecordingCtrlWrap::DisAllowLocalRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::DisAllowLocalRecordingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::DisAllowLocalRecordingParams >(args, proto_params))
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

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().DisAllowLocalRecording(_zn_userid);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRecordingCtrlWrap::RequestCustomizedLocalRecordingSource(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingRecordingCtrl().RequestCustomizedLocalRecordingSource();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRecordingCtrlWrap::SetonRecording2MP4DoneCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onRecording2MP4Done.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onRecording2MP4Done = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRecordingCtrlWrap::SetonRecording2MP4ProcessingCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onRecording2MP4Processing.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onRecording2MP4Processing = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRecordingCtrlWrap::SetonRecordingStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onRecordingStatus.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onRecordingStatus = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRecordingCtrlWrap::SetonCloudRecordingStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onCloudRecordingStatus.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onCloudRecordingStatus = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRecordingCtrlWrap::SetonRecordPriviligeChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onRecordPriviligeChanged.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onRecordPriviligeChanged = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingRecordingCtrlWrap::SetonCustomizedLocalRecordingSourceNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())
		{
			ZoomNodeSinkHelper::GetInst().onCustomizedLocalRecordingSourceNotification.Empty();
			err = ZNSDKERR_INVALID_PARAMETER;
			break;;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onCustomizedLocalRecordingSourceNotification = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}