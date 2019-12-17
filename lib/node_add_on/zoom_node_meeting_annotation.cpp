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
	if (args.Length() < 3) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() ||
		!args[1]->IsString() ||
		!args[2]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	unsigned int type = (unsigned int)args[0].As<v8::Integer >()->Value();
	ZNSDKViewType zn_sdk_view_type;
	switch (type)
	{
	case 0:
		zn_sdk_view_type = ZNSDK_FIRST_VIEW;
		break;
	case 1:
		zn_sdk_view_type = ZNSDK_SECOND_VIEW;
		break;
	default:
		break;
	}
	ZoomSTRING left;
	ZoomSTRING top;
	zoom_v8toc(args[1].As<v8::String>(), left);
	zoom_v8toc(args[2].As<v8::String>(), top);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().StartAnnotation(zn_sdk_view_type, left, top);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAnnotationWrap::StopAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	unsigned int type = (unsigned int)args[0].As<v8::Integer >()->Value();
	ZNSDKViewType zn_sdk_view_type;
	switch (type)
	{
	case 0:
		zn_sdk_view_type = ZNSDK_FIRST_VIEW;
		break;
	case 1:
		zn_sdk_view_type = ZNSDK_SECOND_VIEW;
		break;
	default:
		break;
	}
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().StopAnnotation(zn_sdk_view_type);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAnnotationWrap::SetTool(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() ||
		!args[1]->IsNumber()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	unsigned int viewType = (unsigned int)args[0].As<v8::Integer >()->Value();
	ZNSDKViewType zn_view_type;
	switch (viewType)
	{
	case 0:
		zn_view_type = ZNSDK_FIRST_VIEW;
		break;
	case 1:
		zn_view_type = ZNSDK_SECOND_VIEW;
		break;
	default:
		break;
	}
	unsigned int toolType = (unsigned int)args[1].As<v8::Integer >()->Value();
	ZNAnnotationToolType zn_tool_type = (ZNAnnotationToolType)toolType;
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().SetTool(zn_view_type, zn_tool_type);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAnnotationWrap::Clear(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() ||
		!args[1]->IsNumber()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	unsigned int viewType = (unsigned int)args[0].As<v8::Integer >()->Value();
	ZNSDKViewType zn_view_type;
	switch (viewType)
	{
	case 0:
		zn_view_type = ZNSDK_FIRST_VIEW;
		break;
	case 1:
		zn_view_type = ZNSDK_SECOND_VIEW;
		break;
	default:
		break;
	}
	unsigned int clearType = (unsigned int)args[1].As<v8::Integer >()->Value();
	ZNAnnotationClearType zn_clear_type = (ZNAnnotationClearType)clearType;
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().Clear(zn_view_type, zn_clear_type);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAnnotationWrap::SetColor(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() ||
		!args[1]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	unsigned int type = (unsigned int)args[0].As<v8::Integer >()->Value();
	ZNSDKViewType zn_sdk_view_type;
	switch (type)
	{
	case 0:
		zn_sdk_view_type = ZNSDK_FIRST_VIEW;
		break;
	case 1:
		zn_sdk_view_type = ZNSDK_SECOND_VIEW;
		break;
	default:
		break;
	}
	ZoomSTRING color;
	zoom_v8toc(args[1].As<v8::String>(), color);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().SetColor(zn_sdk_view_type, color);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAnnotationWrap::SetLineWidth(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() ||
		!args[1]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	unsigned int type = (unsigned int)args[0].As<v8::Integer >()->Value();
	ZNSDKViewType zn_sdk_view_type;
	switch (type)
	{
	case 0:
		zn_sdk_view_type = ZNSDK_FIRST_VIEW;
		break;
	case 1:
		zn_sdk_view_type = ZNSDK_SECOND_VIEW;
		break;
	default:
		break;
	}
	ZoomSTRING lineWidth;
	zoom_v8toc(args[1].As<v8::String>(), lineWidth);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().SetLineWidth(zn_sdk_view_type, lineWidth);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAnnotationWrap::Undo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	unsigned int type = (unsigned int)args[0].As<v8::Integer >()->Value();
	ZNSDKViewType zn_sdk_view_type;
	switch (type)
	{
	case 0:
		zn_sdk_view_type = ZNSDK_FIRST_VIEW;
		break;
	case 1:
		zn_sdk_view_type = ZNSDK_SECOND_VIEW;
		break;
	default:
		break;
	}
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().Undo(zn_sdk_view_type);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAnnotationWrap::Redo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	unsigned int type = (unsigned int)args[0].As<v8::Integer >()->Value();
	ZNSDKViewType zn_sdk_view_type;
	switch (type)
	{
	case 0:
		zn_sdk_view_type = ZNSDK_FIRST_VIEW;
		break;
	case 1:
		zn_sdk_view_type = ZNSDK_SECOND_VIEW;
		break;
	default:
		break;
	}
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAnnotation().Redo(zn_sdk_view_type);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}


