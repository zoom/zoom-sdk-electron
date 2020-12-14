#include "zoom_node_meeting_annotation.h"

void ZoomNodeMeetingAnnotationWrap::IsAnnoataionDisable(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool bDisable = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().IsAnnoataionDisable();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, bDisable);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAnnotationWrap::StartAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::StartAnnotationParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::StartAnnotationParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_viewtype() ||
			!proto_params.has_left() ||
			!proto_params.has_top()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		int _type = proto_params.viewtype();
		ZNSDKViewType _zn_sdk_view_type;
		switch (_type)
		{
		case 0:
			_zn_sdk_view_type = ZNSDK_FIRST_VIEW;
			break;
		case 1:
			_zn_sdk_view_type = ZNSDK_SECOND_VIEW;
			break;
		default:
			break;
		}
		ZoomSTRING _left;
		ZoomSTRING _top;
		_left = s2zs(proto_params.left());
		_top = s2zs(proto_params.top());

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().StartAnnotation(_zn_sdk_view_type, _left, _top);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAnnotationWrap::StopAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::StopAnnotationParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::StopAnnotationParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_viewtype())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		int _type = proto_params.viewtype();
		ZNSDKViewType _zn_sdk_view_type;
		switch (_type)
		{
		case 0:
			_zn_sdk_view_type = ZNSDK_FIRST_VIEW;
			break;
		case 1:
			_zn_sdk_view_type = ZNSDK_SECOND_VIEW;
			break;
		default:
			break;
		}
		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().StopAnnotation(_zn_sdk_view_type);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAnnotationWrap::SetTool(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetToolParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetToolParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_viewtype() ||
			!proto_params.has_tooltype()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNSDKViewType _zn_view_type = (ZNSDKViewType)proto_params.viewtype();
		ZNAnnotationToolType _zn_tool_type = (ZNAnnotationToolType)proto_params.tooltype();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().SetTool(_zn_view_type, _zn_tool_type);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAnnotationWrap::Clear(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::ClearAnnotationParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::ClearAnnotationParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_viewtype() ||
			!proto_params.has_cleartype()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNSDKViewType _zn_view_type = (ZNSDKViewType)proto_params.viewtype();
		ZNAnnotationClearType _zn_clear_type = (ZNAnnotationClearType)proto_params.cleartype();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().Clear(_zn_view_type, _zn_clear_type);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAnnotationWrap::SetColor(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetColorParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetColorParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_viewtype() ||
			!proto_params.has_color()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNSDKViewType _zn_view_type = (ZNSDKViewType)proto_params.viewtype();
		ZoomSTRING _color;
		_color = s2zs(proto_params.color());

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().SetColor(_zn_view_type, _color);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAnnotationWrap::SetLineWidth(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetLineWidthParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetLineWidthParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_viewtype() ||
			!proto_params.has_linewidth()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNSDKViewType _zn_view_type = (ZNSDKViewType)proto_params.viewtype();
		ZoomSTRING _linewith;
		_linewith = s2zs(proto_params.linewidth());

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().SetLineWidth(_zn_view_type, _linewith);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAnnotationWrap::Undo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::UndoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::UndoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_viewtype())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNSDKViewType _zn_view_type = (ZNSDKViewType)proto_params.viewtype();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().Undo(_zn_view_type);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAnnotationWrap::Redo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::UndoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::UndoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_viewtype())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNSDKViewType _zn_view_type = (ZNSDKViewType)proto_params.viewtype();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().Redo(_zn_view_type);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}


