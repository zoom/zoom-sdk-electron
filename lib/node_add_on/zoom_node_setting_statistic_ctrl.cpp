#include "zoom_node_setting_statistic_ctrl.h"


ZoomNodeSettingStatisticCtrlWrap::ZoomNodeSettingStatisticCtrlWrap()
{

}

ZoomNodeSettingStatisticCtrlWrap::~ZoomNodeSettingStatisticCtrlWrap()
{
	//
}

void ZoomNodeSettingStatisticCtrlWrap::QueryOverallStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNOverallStatisticInfo zn_info;
	auto context = isolate->GetCurrentContext();
	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingStatisticCtrl().QueryOverallStatisticInfo(zn_info);

	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "networkType", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.net_work_type));
	node->Set(context, v8::String::NewFromUtf8(isolate, "connectionType", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.connection_type));
	node->Set(context, v8::String::NewFromUtf8(isolate, "proxyAddr", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_info.proxy_addr).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());

	args.GetReturnValue().Set(node);
}
void ZoomNodeSettingStatisticCtrlWrap::QueryAudioStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNAudioSessionStatisticInfo zn_info;
	auto context = isolate->GetCurrentContext();
	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingStatisticCtrl().QueryAudioStatisticInfo(zn_info);

	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "frequency_recv", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.frequency_recv));
	node->Set(context, v8::String::NewFromUtf8(isolate, "frequency_send", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.frequency_send));
	node->Set(context, v8::String::NewFromUtf8(isolate, "latency_recv", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.latency_recv));
	node->Set(context, v8::String::NewFromUtf8(isolate, "latency_send", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.latency_send));
	node->Set(context, v8::String::NewFromUtf8(isolate, "jitter_recv", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.jitter_recv));
	node->Set(context, v8::String::NewFromUtf8(isolate, "jitter_send", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.jitter_send));
	node->Set(context, v8::String::NewFromUtf8(isolate, "packetloss_recv", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Number::New(isolate, (double)zn_info.packetloss_recv));
	node->Set(context, v8::String::NewFromUtf8(isolate, "packetloss_send", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Number::New(isolate, (double)zn_info.packetloss_send));

	args.GetReturnValue().Set(node);
}
void ZoomNodeSettingStatisticCtrlWrap::QueryVideoStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNASVSessionStatisticInfo zn_info;
	auto context = isolate->GetCurrentContext();
	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingStatisticCtrl().QueryVideoStatisticInfo(zn_info);

	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "latency_send", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.latency_send));
	node->Set(context, v8::String::NewFromUtf8(isolate, "latency_recv", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.latency_recv));
	node->Set(context, v8::String::NewFromUtf8(isolate, "jitter_send", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.jitter_send));
	node->Set(context, v8::String::NewFromUtf8(isolate, "jitter_recv", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.jitter_recv));
	node->Set(context, v8::String::NewFromUtf8(isolate, "resolution_send", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.resolution_send));
	node->Set(context, v8::String::NewFromUtf8(isolate, "resolution_recv", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.resolution_recv));
	node->Set(context, v8::String::NewFromUtf8(isolate, "fps_send", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.fps_send));
	node->Set(context, v8::String::NewFromUtf8(isolate, "fps_recv", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.fps_recv));
	node->Set(context, v8::String::NewFromUtf8(isolate, "packetloss_send_max", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Number::New(isolate, (double)zn_info.packetloss_send_max));
	node->Set(context, v8::String::NewFromUtf8(isolate, "packetloss_recv_max", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Number::New(isolate, (double)zn_info.packetloss_recv_max));
	node->Set(context, v8::String::NewFromUtf8(isolate, "packetloss_send_avg", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Number::New(isolate, (double)zn_info.packetloss_send_avg));
	node->Set(context, v8::String::NewFromUtf8(isolate, "packetloss_recv_avg", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Number::New(isolate, (double)zn_info.packetloss_recv_avg));

	args.GetReturnValue().Set(node);
}
void ZoomNodeSettingStatisticCtrlWrap::QueryShareStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNASVSessionStatisticInfo zn_info;
	auto context = isolate->GetCurrentContext();
	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingStatisticCtrl().QueryShareStatisticInfo(zn_info);

	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "latency_send", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.latency_send));
	node->Set(context, v8::String::NewFromUtf8(isolate, "latency_recv", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.latency_recv));
	node->Set(context, v8::String::NewFromUtf8(isolate, "jitter_send", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.jitter_send));
	node->Set(context, v8::String::NewFromUtf8(isolate, "jitter_recv", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.jitter_recv));
	node->Set(context, v8::String::NewFromUtf8(isolate, "resolution_send", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.resolution_send));
	node->Set(context, v8::String::NewFromUtf8(isolate, "resolution_recv", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.resolution_recv));
	node->Set(context, v8::String::NewFromUtf8(isolate, "fps_send", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.fps_send));
	node->Set(context, v8::String::NewFromUtf8(isolate, "fps_recv", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.fps_recv));
	node->Set(context, v8::String::NewFromUtf8(isolate, "packetloss_send_max", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Number::New(isolate, (double)zn_info.packetloss_send_max));
	node->Set(context, v8::String::NewFromUtf8(isolate, "packetloss_recv_max", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Number::New(isolate, (double)zn_info.packetloss_recv_max));
	node->Set(context, v8::String::NewFromUtf8(isolate, "packetloss_send_avg", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Number::New(isolate, (double)zn_info.packetloss_send_avg));
	node->Set(context, v8::String::NewFromUtf8(isolate, "packetloss_recv_avg", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Number::New(isolate, (double)zn_info.packetloss_recv_avg));

	args.GetReturnValue().Set(node);
}