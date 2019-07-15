#ifndef _ZOOM_NODE_CUSTOMIZED_RESOURCE_H_
#define _ZOOM_NODE_CUSTOMIZED_RESOURCE_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeCustomizedResourceWrap :
	public ZoomWrapObject<ZoomNodeCustomizedResourceWrap >
{
	friend class ZoomWrapObject<ZoomNodeCustomizedResourceWrap >;
private:
	ZoomNodeCustomizedResourceWrap();
	~ZoomNodeCustomizedResourceWrap();
public:
	static void AddCustomizedPictureResource(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void AddCustomizedStringResource(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void AddCustomizedURLResource(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeCustomizedResourceWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeCustomizedResourceWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "AddCustomizedPictureResource", ZoomNodeCustomizedResourceWrap::AddCustomizedPictureResource);
	NODE_SET_PROTOTYPE_METHOD(tpl, "AddCustomizedStringResource", ZoomNodeCustomizedResourceWrap::AddCustomizedStringResource);
	NODE_SET_PROTOTYPE_METHOD(tpl, "AddCustomizedURLResource", ZoomNodeCustomizedResourceWrap::AddCustomizedURLResource);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeCustomizedResourceWrap >() {
	return &ZoomNodeCustomizedResourceWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





#endif
