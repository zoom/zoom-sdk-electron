#include "zoom_node_setting_video_ctrl.h"

ZoomNodeSettingVideoCtrlWrap::ZoomNodeSettingVideoCtrlWrap()
{
	_g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_videoSettingContextWrapSink);
}

ZoomNodeSettingVideoCtrlWrap::~ZoomNodeSettingVideoCtrlWrap()
{
	_g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().SetSink(NULL);
}
void ZoomNodeSettingVideoCtrlWrap::SelectVideoCamera(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SelectVideoCameraParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SelectVideoCameraParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_deviceid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING _zn_deviceId;
		_zn_deviceId = s2zs(proto_params.deviceid());

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().SelectCamera(_zn_deviceId);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsMirrorEffectEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bDisable = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsVideoMirrorEffectEnable();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bDisable);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::GetCameraList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNList<ZNCameraInfo> zn_cameraInfoLst = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().GetCameraList();

	v8::HandleScope scope(isolate);
	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_cameraInfoLst.size(); ++i) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(isolate->GetCurrentContext(), v8::String::NewFromUtf8(isolate, "deviceId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_cameraInfoLst[i].deviceId).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(isolate->GetCurrentContext(), v8::String::NewFromUtf8(isolate, "deviceName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_cameraInfoLst[i].deviceName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(isolate->GetCurrentContext(), v8::String::NewFromUtf8(isolate, "isSelected", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_cameraInfoLst[i].isSelectedDevice));
		nodes->Set(isolate->GetCurrentContext(), i, node);
	}

	args.GetReturnValue().Set(nodes);
}
void ZoomNodeSettingVideoCtrlWrap::EnableVideoMirrorEffect(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableVideoMirrorEffectParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableVideoMirrorEffectParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableVideoMirrorEffect(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableFaceBeautyEffect(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableFaceBeautyEffectParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableFaceBeautyEffectParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableFaceBeautyEffect(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsFaceBeautyEffectEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bDisable = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsFaceBeautyEffectEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bDisable);
	args.GetReturnValue().Set(bret);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ZoomNodeSettingVideoCtrlWrap::SetComputerCamDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onComputerCamDeviceChanged.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onComputerCamDeviceChanged = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::SetDefaultCamDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onDefaultCamDeviceChanged.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onDefaultCamDeviceChanged = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableHDVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableHDVideoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableHDVideoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableHDVideo(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsHDVideoEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsHDVideoEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableAlwaysShowNameOnVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableAlwaysShowNameOnVideoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableAlwaysShowNameOnVideoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableAlwaysShowNameOnVideo(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsAlwaysShowNameOnVideoEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsAlwaysShowNameOnVideoEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableVideoPreviewDialog(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableVideoPreviewDialogParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableVideoPreviewDialogParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableVideoPreviewDialog(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsVideoPreviewDialogEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsVideoPreviewDialogEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableAutoTurnOffVideoWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableAutoTurnOffVideoWhenJoinMeetingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableAutoTurnOffVideoWhenJoinMeetingParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableAutoTurnOffVideoWhenJoinMeeting(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsAutoTurnOffVideoWhenJoinMeetingEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsAutoTurnOffVideoWhenJoinMeetingEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableAlwaysUse16v9(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableAlwaysUse16v9Params proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableAlwaysUse16v9Params >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableAlwaysUse16v9(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsAlwaysUse16v9(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsAlwaysUse16v9();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableSpotlightSelf(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableSpotlightSelfParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableSpotlightSelfParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableSpotlightSelf(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsSpotlightSelfEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsSpotlightSelfEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableHardwareEncode(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableHardwareEncodeParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableHardwareEncodeParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable() ||
			!proto_params.has_encodetype()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);
		ZN_VIDEO_HARDWARE_ENCODE_TYPE _zn_encodeType = (ZN_VIDEO_HARDWARE_ENCODE_TYPE)proto_params.encodetype();

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableHardwareEncode(_bEnable, _zn_encodeType);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsHardwareEncodeEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = false;
	do
	{
		com::electron::sdk::proto::IsHardwareEncodeEnabledParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::IsHardwareEncodeEnabledParams >(args, proto_params))
		{
			isEnabled = false;
			break;
		}
		if (!proto_params.has_encodetype())
		{
			isEnabled = false;
			break;
		}
		ZN_VIDEO_HARDWARE_ENCODE_TYPE _zn_encodeType = (ZN_VIDEO_HARDWARE_ENCODE_TYPE)proto_params.encodetype();
		isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsHardwareEncodeEnabled(_zn_encodeType);
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::Enable49VideoesInGallaryView(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::Enable49VideoesInGallaryViewParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::Enable49VideoesInGallaryViewParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().Enable49VideoesInGallaryView(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::Is49VideoesInGallaryViewEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().Is49VideoesInGallaryViewEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableHideNoVideoUsersOnWallView(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableHideNoVideoUsersOnWallViewParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableHideNoVideoUsersOnWallViewParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableHideNoVideoUsersOnWallView(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsHideNoVideoUsersOnWallViewEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsHideNoVideoUsersOnWallViewEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}

