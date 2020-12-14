#include "zoom_node_meeting_config_ctrl.h"


ZoomNodeMeetingConfigCtrlWrap::ZoomNodeMeetingConfigCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_meetingConfigWrapFreeMeetingSink);
}

ZoomNodeMeetingConfigCtrlWrap::~ZoomNodeMeetingConfigCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetSink(NULL);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableInviteButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableInviteButtonOnMeeitngUIParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableInviteButtonOnMeeitngUIParams >(args, proto_params))
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

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableInviteButtonOnMeetingUI(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetFloatVideoPos(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetFloatVideoPosParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetFloatVideoPosParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
#if (defined _WIN32)
		if (!proto_params.has_hparent() ||
			!proto_params.has_hselfwnd() ||
			!proto_params.has_left() ||
			!proto_params.has_top()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
#else
		if (!proto_params.has_left() ||
			!proto_params.has_top()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
#endif
		ZNWndPosition _zn_position;
		_zn_position.z_left = s2zs(proto_params.left());
		_zn_position.z_top = s2zs(proto_params.top());
#if (defined _WIN32)
		_zn_position.z_hParent = s2zs(proto_params.hparent());
		_zn_position.z_hSelfWnd = s2zs(proto_params.hselfwnd());
#endif

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetFloatVideoPos(_zn_position);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetBottomFloatToolbarWndVisibility(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetBottomFloatToolBarWndVisibilityParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetBottomFloatToolBarWndVisibilityParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bshow())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bShow = false;
		convertBool(proto_params.bshow(), _bShow);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetBottomFloatToolbarWndVisibility(_bShow);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetSharingToolbarVisibility(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetSharingToolBarVisibilityParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetSharingToolBarVisibilityParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bshow())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bShow = false;
		convertBool(proto_params.bshow(), _bShow);
		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetSharingToolbarVisibility(_bShow);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetDirectShareMonitorID(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetDirectShareMonitorIDParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetDirectShareMonitorIDParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_monitorid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING _zn_monitorID;
		_zn_monitorID = s2zs(proto_params.monitorid());

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetDirectShareMonitorID(_zn_monitorID);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetMeetingUIPos(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetMeetingUIPosParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetMeetingUIPosParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
#if (defined _WIN32)
		if (!proto_params.has_hparent() ||
			!proto_params.has_hselfwnd() ||
			!proto_params.has_left() ||
			!proto_params.has_top()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
#else
		if (!proto_params.has_left() ||
			!proto_params.has_top()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
#endif
		ZNWndPosition _zn_position;
		_zn_position.z_left = s2zs(proto_params.left());
		_zn_position.z_top = s2zs(proto_params.top());
#if (defined _WIN32)
		_zn_position.z_hParent = s2zs(proto_params.hparent());
		_zn_position.z_hSelfWnd = s2zs(proto_params.hselfwnd());
#endif

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetMeetingUIPos(_zn_position);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::DisableWaitingForHostDialog(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::DisableWaitingForHostDialogParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::DisableWaitingForHostDialogParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bdisable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bDisable = false;
		convertBool(proto_params.bdisable(), _bDisable);
		
		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisableWaitingForHostDialog(_bDisable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::DisablePopupMeetingWrongPSWDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::DisablePopupMeetingWrongPSWDlgParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::DisablePopupMeetingWrongPSWDlgParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bdisable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bDisable = false;
		convertBool(proto_params.bdisable(), _bDisable);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisablePopupMeetingWrongPSWDlg(_bDisable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableAutoEndOtherMeetingWhenStartMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableAutoEndOtherMeetingWhenStartMeetingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableAutoEndOtherMeetingWhenStartMeetingParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableAutoEndOtherMeetingWhenStartMeeting(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableLButtonDBClick4SwitchFullScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_INVALID_PARAMETER;
	do
	{
		com::electron::sdk::proto::EnableLButtonDBClick4SwitchFullScreenModeParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableLButtonDBClick4SwitchFullScreenModeParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableLButtonDBClick4SwitchFullScreenMode(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetFloatVideoWndVisibility(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetFloatVideoWndVisibilityParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetFloatVideoWndVisibilityParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bshow())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bShow = false;
		convertBool(proto_params.bshow(), _bShow);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetFloatVideoWndVisibility(_bShow);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::PrePopulateWebinarRegistrationInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::PrePopulateWebinarRegistrationInfoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::PrePopulateWebinarRegistrationInfoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_email() ||
			!proto_params.has_username()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING _zn_email;
		_zn_email = s2zs(proto_params.email());
		ZoomSTRING _zn_userName;
		_zn_userName = s2zs(proto_params.username());

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().PrePopulateWebinarRegistrationInfo(_zn_email, _zn_userName);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::Reset(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().Reset();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableAutoAdjustSpeakerVolumeWhenJoinAudio(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableAutoAdjustSpeakerVolumeWhenJoinAudioParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableAutoAdjustSpeakerVolumeWhenJoinAudioParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableAutoAdjustSpeakerVolumeWhenJoinAudio(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableAutoAdjustMicVolumeWhenJoinAudio(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableAutoAdjustMicVolumeWhenJoinAudioParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableAutoAdjustMicVolumeWhenJoinAudioParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableAutoAdjustMicVolumeWhenJoinAudio(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::ConfigDSCP(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::ConfigDSCPParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ConfigDSCPParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_breset() ||
			!proto_params.has_dscpaudio() ||
			!proto_params.has_dscpvideo()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		int _zn_dscpAudio = proto_params.dscpaudio();
		int _zn_dscpVideo = proto_params.dscpvideo();
		bool _zn_bReset = false;
		convertBool(proto_params.breset(), _zn_bReset);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().ConfigDSCP(_zn_dscpAudio, _zn_dscpVideo, _zn_bReset);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableHideFullPhoneNumber4PureCallinUser(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableHIdeFullPhoneNumber4PureCallinUserParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableHIdeFullPhoneNumber4PureCallinUserParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableHideFullPhoneNumber4PureCallinUser(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableLengthLimitationOfMeetingNumber(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableLengthLimitationOfMeetingNumberParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableLengthLimitationOfMeetingNumberParams >(args, proto_params))
		{
			
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

#if (defined _WIN32)
		err = ZNSDKERR_SUCCESS;
#else
		err = ZNSDKERR_NO_IMPL;
#endif 
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableLengthLimitationOfMeetingNumber(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableShareIOSDevice(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableShareIOSDeviceParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableShareIOSDeviceParams >(args, proto_params))
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

#if (defined _WIN32)
		err = ZNSDKERR_SUCCESS;
#else
		err = ZNSDKERR_NO_IMPL;
#endif 
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableShareIOSDevice(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableShareWhiteBoard(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableShareWhiteBoardParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableShareWhiteBoardParams >(args, proto_params))
		{
			err = ZNSDKERR_SUCCESS;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_SUCCESS;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

#if (defined _WIN32)
		err = ZNSDKERR_SUCCESS;
#else
		err = ZNSDKERR_NO_IMPL;
#endif 
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableShareWhiteBoard(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::ForceDisableMultiShare(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::ForceDisableMultiShareParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ForceDisableMultiShareParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bdisable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bDisable = false;
		convertBool(proto_params.bdisable(), _bDisable);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().ForceDisableMultiShare(_bDisable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableLocalRecordingConvertProgressBarDialog(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableLocalRecordingConverProgressBarDialogParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableLocalRecordingConverProgressBarDialogParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableLocalRecordingConvertProgressBarDialog(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetMaxDurationForOnlyHostInMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetMaxDurationForOnlyHostInMeetingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetMaxDurationForOnlyHostInMeetingParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
	}
		if (!proto_params.has_nduration())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		int _zn_nDuration = proto_params.nduration();

#if (defined _WIN32)
		err = ZNSDKERR_SUCCESS;
#else
		err = ZNSDKERR_NO_IMPL;
#endif 
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetMaxDurationForOnlyHostInMeeting(_zn_nDuration);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::GetReminderType(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNFreeMeetingEndingReminderType zn_type = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().GetReminderType();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)zn_type);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::UpgradeMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().UpgradeMeeting();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::UpgradeAccount(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().UpgradeAccount();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::CancelUpdate(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().CancelUpdate();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingNeedToUpgradeCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onFreeMeetingNeedToUpgrade.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onFreeMeetingNeedToUpgrade = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToGiftFreeTrialStartCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStart.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStart = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToGiftFreeTrialStopCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStop.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStop = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToProMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToProMeeting.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToProMeeting = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}


void ZoomNodeMeetingConfigCtrlWrap::EnableApproveRemoteControlDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableApproveRemoteControlDlgParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableApproveRemoteControlDlgParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableApproveRemoteControlDlg(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableDeclineRemoteControlResponseDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableDeclineRemoteControlResponseDlgParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableDeclineRemoteControlResponseDlgParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableDeclineRemoteControlResponseDlg(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableLeaveMeetingOptionForHost(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableLeaveMeetingOptionForHostParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableLeaveMeetingOptionForHostParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableLeaveMeetingOptionForHost(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableVideoButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableVideoButtonOnMeetingUIParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableVideoButtonOnMeetingUIParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableVideoButtonOnMeetingUI(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableAudioButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableAudioButtonOnMeetingUIParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableAudioButtonOnMeetingUIParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableAudioButtonOnMeetingUI(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableEnterAndExitFullScreenButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableEnterAndExitFullScreenButtonOnMeetingUIParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableEnterAndExitFullScreenButtonOnMeetingUIParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableEnterAndExitFullScreenButtonOnMeetingUI(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectClickShareBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::RedirectClickShareBTNEventParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::RedirectClickShareBTNEventParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bredirect())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bRedirect = false;
		convertBool(proto_params.bredirect(), _bRedirect);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectClickShareBTNEvent(_bRedirect);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectClickEndMeetingBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::RedirectClickEndMeetingBTNEventParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::RedirectClickEndMeetingBTNEventParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bredirect())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bRedirect = false;
		convertBool(proto_params.bredirect(), _bRedirect);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectClickEndMeetingBTNEvent(_bRedirect);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectFreeMeetingEndingReminderDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::RedirectFreeMeetingEndingReminderDlgParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::RedirectFreeMeetingEndingReminderDlgParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bredirect())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bRedirect = false;
		convertBool(proto_params.bredirect(), _bRedirect);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectFreeMeetingEndingReminderDlg(_bRedirect);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectClickCustomLiveStreamMenuEvent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::RedirectClickCustomLiveStreamMenuEventParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::RedirectClickCustomLiveStreamMenuEventParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bredirect())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bRedirect = false;
		convertBool(proto_params.bredirect(), _bRedirect);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectClickCustomLiveStreamMenuEvent(_bRedirect);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectClickParticipantListBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::RedirectClickParticipantListBTNEventParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::RedirectClickParticipantListBTNEventParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bredirect())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bRedirect = false;
		convertBool(proto_params.bredirect(), _bRedirect);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectClickParticipantListBTNEvent(_bRedirect);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectClickCCBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::RedirectClickCCBTNEventParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::RedirectClickCCBTNEventParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bredirect())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bRedirect = false;
		convertBool(proto_params.bredirect(), _bRedirect);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectClickCCBTNEvent(_bRedirect);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::RedirectClickAudioBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::RedirectClickAudioBTNEventParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::RedirectClickAudioBTNEventParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bredirect())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bRedirect = false;
		convertBool(proto_params.bredirect(), _bRedirect);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectClickAudioBTNEvent(_bRedirect);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::RedirectClickAudioMenuBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::RedirectClickAudioMenuBTNEventParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::RedirectClickAudioMenuBTNEventParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bredirect())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bRedirect = false;
		convertBool(proto_params.bredirect(), _bRedirect);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectClickAudioMenuBTNEvent(_bRedirect);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectMeetingWarningMsg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::RedirectMeetingWarningMsgParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::RedirectMeetingWarningMsgParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bredirectbadnetwork() ||
			!proto_params.has_bredirectwarnhighcpu()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNZoomRedirectWarningMsgOption _zn_RedirectOption;
		convertBool(proto_params.bredirectbadnetwork(), _zn_RedirectOption.bRedirectBadNetwork);
		convertBool(proto_params.bredirectwarnhighcpu(), _zn_RedirectOption.bRedirectWarnHighCPU);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectMeetingWarningMsg(_zn_RedirectOption);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableToolTipsShow(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableToolTipsShowParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableToolTipsShowParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableToolTipsShow(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableAirplayInstructionWindow(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableAirplayInstructionWindowParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableAirplayInstructionWindowParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableAirplayInstructionWindow(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableClaimHostFeature(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableClaimHostFeatureParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableClaimHostFeatureParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableClaimHostFeature(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableAutoHideJoinAudioDialog(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableAutoHideJoinAudioDialogParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableAutoHideJoinAudioDialogParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableAutoHideJoinAudioDialog(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::AlwaysShowIconOnTaskBar(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::AlwaysShowIconOnTaskBarParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::AlwaysShowIconOnTaskBarParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_balwaysshow())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bAlwaysShow = false;
		convertBool(proto_params.balwaysshow(), _bAlwaysShow);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().AlwaysShowIconOnTaskBar(_bAlwaysShow);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::DisableSplitScreenModeUIElements(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::DisableSplitScreenModeUIElementsParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::DisableSplitScreenModeUIElementsParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bdisable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bDisable = false;
		convertBool(proto_params.bdisable(), _bDisable);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisableSplitScreenModeUIElements(_bDisable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::SetShowAudioUseComputerSoundChkbox(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetShowAudioUseComputerSoundChkboxParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetShowAudioUseComputerSoundChkboxParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bshow())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bShow = false;
		convertBool(proto_params.bshow(), _bShow);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetShowAudioUseComputerSoundChkbox(_bShow);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::SetShowCallInTab(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetShowCallInTabParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetShowCallInTabParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bshow())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bShow = false;
		convertBool(proto_params.bshow(), _bShow);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetShowCallInTab(_bShow);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::SetShowCallMeTab(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetShowCallMeTabParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetShowCallMeTabParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bshow())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bShow = false;
		convertBool(proto_params.bshow(), _bShow);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetShowCallMeTab(_bShow);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::DisableTopMostAttr4SettingDialog(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::DisableTopMostAttr4SettingDialogParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::DisableTopMostAttr4SettingDialogParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bdisable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bDisable = false;
		convertBool(proto_params.bdisable(), _bDisable);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisableTopMostAttr4SettingDialog(_bDisable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableGrabShareWithoutReminder(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableGrabShareWithoutReminderParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableGrabShareWithoutReminderParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableGrabShareWithoutReminder(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableShowShareSwitchMultiToSingleConfirmDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableShowShareSwitchMultiToSingleConfirmDlgParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableShowShareSwitchMultiToSingleConfirmDlgParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableShowShareSwitchMultiToSingleConfirmDlg(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::DisableFreeMeetingRemainTimeNotify(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::DisableFreeMeetingRemainTimeNotifyParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::DisableFreeMeetingRemainTimeNotifyParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bdisable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bDisable = false;
		convertBool(proto_params.bdisable(), _bDisable);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisableFreeMeetingRemainTimeNotify(_bDisable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideChatItemOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::HideChatItemOnMeetingUIParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::HideChatItemOnMeetingUIParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bhide())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bHide = false;
		convertBool(proto_params.bhide(), _bHide);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideChatItemOnMeetingUI(_bHide);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideRecordItemOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::HideRecordItemOnMeetingUIParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::HideRecordItemOnMeetingUIParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bhide())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bHide = false;
		convertBool(proto_params.bhide(), _bHide);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideRecordItemOnMeetingUI(_bHide);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideUpgradeFreeMeetingButton(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::HideUpgradeFreeMeetingButtonParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::HideUpgradeFreeMeetingButtonParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bhide())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bHide = false;
		convertBool(proto_params.bhide(), _bHide);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideUpgradeFreeMeetingButton(_bHide);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::SetShowInviteDlgTabPage(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetShowInviteDlgTabPageParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetShowInviteDlgTabPageParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bshow() ||
			!proto_params.has_tabpage()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNSDKInviteDlgTabPage  _zn_TabPage = (ZNSDKInviteDlgTabPage)proto_params.tabpage();
		bool _zn_bShow = false;
		convertBool(proto_params.bshow(), _zn_bShow);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetShowInviteDlgTabPage(_zn_TabPage, _zn_bShow);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::SetShowH323SubTabPage(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetShowH323SubTabPageParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetShowH323SubTabPageParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bshow() ||
			!proto_params.has_tabpage()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNSDKH323TabPage  _zn_TabPage = (ZNSDKH323TabPage)proto_params.tabpage();
		bool _zn_bShow = false;
		convertBool(proto_params.bshow(), _zn_bShow);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetShowH323SubTabPage(_zn_TabPage, _zn_bShow);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideUpgradeWarningMsgForFreeUserWhenSchedule(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::HideUpgradeWarningMsgForFreeUserWhenScheduleParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::HideUpgradeWarningMsgForFreeUserWhenScheduleParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bhide())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bHide = false;
		convertBool(proto_params.bhide(), _bHide);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideUpgradeWarningMsgForFreeUserWhenSchedule(_bHide);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideSwitchCameraButton(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::HideSwitchCameraButtonParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::HideSwitchCameraButtonParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bhide())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bHide = false;
		convertBool(proto_params.bhide(), _bHide);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideSwitchCameraButton(_bHide);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideCopyUrlOnInviteWindow(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::HideCopyUrlOnInviteWindowParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::HideCopyUrlOnInviteWindowParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bhide())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bHide = false;
		convertBool(proto_params.bhide(), _bHide);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideCopyUrlOnInviteWindow(_bHide);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideCopyInvitationOnInviteWindow(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::HideCopyInvitationOnInviteWindowParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::HideCopyInvitationOnInviteWindowParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bhide())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bHide = false;
		convertBool(proto_params.bhide(), _bHide);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideCopyInvitationOnInviteWindow(_bHide);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideKeypadButtonOnMeetingWindow(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::HideKeypadButtonOnMeetingWindowParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::HideKeypadButtonOnMeetingWindowParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bhide())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bHide = false;
		convertBool(proto_params.bhide(), _bHide);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideKeypadButtonOnMeetingWindow(_bHide);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideRemoteControlOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::HideRemoteControlOnMeetingUIParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::HideRemoteControlOnMeetingUIParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bhide())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bHide = false;
		convertBool(proto_params.bhide(), _bHide);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideRemoteControlOnMeetingUI(_bHide);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideQAOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::HideQAOnMeetingUIParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::HideQAOnMeetingUIParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bhide())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bHide = false;
		convertBool(proto_params.bhide(), _bHide);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideQAOnMeetingUI(_bHide);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HidePollOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::HidePollOnMeetingUIParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::HidePollOnMeetingUIParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bhide())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bHide = false;
		convertBool(proto_params.bhide(), _bHide);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HidePollOnMeetingUI(_bHide);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableInputMeetingPasswordDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableInputMeetingPasswordDlgParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableInputMeetingPasswordDlgParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableInputMeetingPasswordDlg(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableInputMeetingScreenNameDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableInputMeetingScreenNameDlgParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableInputMeetingScreenNameDlgParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableInputMeetingScreenNameDlg(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectWebinarNeedRegister(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::RedirectWebinarNeedRegisterParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::RedirectWebinarNeedRegisterParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bredirect())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bRedirect = false;
		convertBool(proto_params.bredirect(), _bRedirect);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectWebinarNeedRegister(_bRedirect);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectEndOtherMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::RedirectEndOtherMeetingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::RedirectEndOtherMeetingParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bredirect())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bRedirect = false;
		convertBool(proto_params.bredirect(), _bRedirect);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectEndOtherMeeting(_bRedirect);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableForceAutoStartMyVideoWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableForceAutoStartMyVideoWhenJoinMeetingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableForceAutoStartMyVideoWhenJoinMeetingParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableForceAutoStartMyVideoWhenJoinMeeting(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableForceAutoStopMyVideoWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnableForceAutoStopMyVideoWhenJoinMeetingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableForceAutoStopMyVideoWhenJoinMeetingParams >(args, proto_params))
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

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableForceAutoStopMyVideoWhenJoinMeeting(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::DisableAutoShowSelectJoinAudioDlgWhenJoinMeetingParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::DisableAutoShowSelectJoinAudioDlgWhenJoinMeetingParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bdisable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bDisable = false;
		convertBool(proto_params.bdisable(), _bDisable);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting(_bDisable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::DisableShowJoinMeetingWnd(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::DisableShowJoinMeetingWndParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::DisableShowJoinMeetingWndParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bdisable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bDisable = false;
		convertBool(proto_params.bdisable(), _bDisable);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisableShowJoinMeetingWnd(_bDisable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::DisableConfidentialWatermark(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::DisableConfidentialWatermarkParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::DisableConfidentialWatermarkParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bdisable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bDisable = false;
		convertBool(proto_params.bdisable(), _bDisable);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisableConfidentialWatermark(_bDisable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::DisableRemoteCtrlCopyPasteFeature(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::DisableRemoteCtrlCopyPasteFeatureParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::DisableRemoteCtrlCopyPasteFeatureParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bdisable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bDisable = false;
		convertBool(proto_params.bdisable(), _bDisable);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisableRemoteCtrlCopyPasteFeature(_bDisable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::DisableToolbarInviteButtonClickOriginAction(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::DisableToolbarInviteButtonClickOriginActionParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::DisableToolbarInviteButtonClickOriginActionParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bdisable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bDisable = false;
		convertBool(proto_params.bdisable(), _bDisable);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisableToolbarInviteButtonClickOriginAction(_bDisable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetShowVideoOptimizeChkbox(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetShowVideoOptimizeChkboxParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetShowVideoOptimizeChkboxParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bshow())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bShow = false;
		convertBool(proto_params.bshow(), _bShow);

		err = ZNSDKERR_SUCCESS;
		_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetShowVideoOptimizeChkbox(_bShow);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::GetRequiredInfoType(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNRequiredInfoType zn_type = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().GetRequiredInfoType();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)zn_type);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::InputMeetingPasswordAndScreenName(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	do
	{
		com::electron::sdk::proto::InputMeetingPasswordAndScreenNameParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::InputMeetingPasswordAndScreenNameParams >(args, proto_params))
		{
			err = false;
			break;
		}
		if (!proto_params.has_psw() ||
			!proto_params.has_screenname()
			)
		{
			err = false;
			break;
		}
		ZoomSTRING _zn_meetingPassword;
		_zn_meetingPassword = s2zs(proto_params.psw());
		ZoomSTRING _zn_screenName;
		_zn_screenName = s2zs(proto_params.screenname());

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().InputMeetingPasswordAndScreenName(_zn_meetingPassword, _zn_screenName);
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::InputMeetingIDAndScreenName(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	do
	{
		com::electron::sdk::proto::InputMeetingIDAndScreenNameParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::InputMeetingIDAndScreenNameParams >(args, proto_params))
		{
			err = false;
			break;
		}
		if (!proto_params.has_meetingid() ||
			!proto_params.has_screenname()
			)
		{
			err = false;
			break;
		}
		ZoomSTRING _zn_meetingID;
		_zn_meetingID = s2zs(proto_params.meetingid());
		ZoomSTRING _zn_screenName;
		_zn_screenName = s2zs(proto_params.screenname());

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().InputMeetingIDAndScreenName(_zn_meetingID, _zn_screenName);
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::InputMeetingScreenName(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	do
	{
		com::electron::sdk::proto::InputMeetingScreenNameParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::InputMeetingScreenNameParams >(args, proto_params))
		{
			err = false;
			break;
		}
		if (!proto_params.has_screenname())
		{
			err = false;
			break;
		}
		ZoomSTRING _zn_screenName;
		_zn_screenName = s2zs(proto_params.screenname());

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().InputMeetingScreenName(_zn_screenName);
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::MeetingPasswordAndScreenNameHandler_Cancel(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().MeetingPasswordAndScreenNameHandler_Cancel();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::GetWebinarNeedRegisterType(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNWebinarNeedRegisterType zn_type = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().GetWebinarNeedRegisterType();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)zn_type);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::GetWebinarRegisterUrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING webinarRegisterUrl = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().GetWebinarRegisterUrl();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(webinarRegisterUrl).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::ReleaseRegisterWebinarByUrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().ReleaseRegisterWebinarByUrl();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::InputWebinarRegisterEmailAndScreenName(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::InputWebinarRegisterEmailAndScreenNameParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::InputWebinarRegisterEmailAndScreenNameParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_email() ||
			!proto_params.has_screenname()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING _zn_email;
		_zn_email = s2zs(proto_params.email());
		ZoomSTRING _zn_screenName;
		_zn_screenName = s2zs(proto_params.screenname());

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().InputWebinarRegisterEmailAndScreenName(_zn_email, _zn_screenName);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::CancelRegisterWebinarByEmail(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().CancelRegisterWebinarByEmail();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetInputMeetingPasswordAndScreenNameNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onInputMeetingPasswordAndScreenNameNotification.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onInputMeetingPasswordAndScreenNameNotification = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetAirPlayInstructionWndNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onAirPlayInstructionWndNotification.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onAirPlayInstructionWndNotification = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetonWebinarNeedRegisterNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onWebinarNeedRegisterNotification.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onWebinarNeedRegisterNotification = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetonEndOtherMeetingToJoinMeetingNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onEndOtherMeetingToJoinMeetingNotification.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onEndOtherMeetingToJoinMeetingNotification = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetonFreeMeetingRemainTimeCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			ZNSDKError err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onFreeMeetingRemainTime.Empty();			ZNSDKError err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			ZNSDKError err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onFreeMeetingRemainTime = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetonFreeMeetingRemainTimeStopCountDownCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onFreeMeetingRemainTimeStopCountDown.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onFreeMeetingRemainTimeStopCountDown = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetonFreeMeetingEndingReminderNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onFreeMeetingEndingReminderNotification.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onFreeMeetingEndingReminderNotification = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}


