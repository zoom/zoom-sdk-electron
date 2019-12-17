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
	///\brief Add the custom photo files, currently, support only PNG format.
	///\param 1. strPNGID(string) Resource ID corresponding to the custom resource.
	///\param 2. strPNGPath(string) The location of the customized resource file must be an absolute path and include the file name with suffix.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	/// \remarks You must call the function first before calling InitSDK(), or no, it won't work.
	static void AddCustomizedPictureResource(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Use the custom string to replace the specified string item.
	/// \param 1. customizedType(number) Specify the string item type. For more information, see \link ZNSDKCustomizedStringType \endlink enum.
	/// \param 2. customizedString(string) Specify the custom string.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	/// \remarks If customizedString is empty, the return value is ZNSDKERR_INVALID_PARAMETER.
	/// \remarks You must call the function first before calling InitSDK(), or no, it won't work.
	static void AddCustomizedStringResource(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Use the custom URL to replace the specified URL.
	/// \param 1. customizedType(number) Specify the URL type. For more information, see \link ZNSDKCustomizedURLType \endlink enum.
	/// \param 2. customizedUrl(string) Specify the custom URL. 
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	/// \remarks If customizedString is empty, the return value is ZNSDKERR_INVALID_PARAMETER.
	/// \remarks You must call the function first before calling InitSDK(), or no, it won't work.
	static void AddCustomizedURLResource(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeCustomizedResourceWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeCustomizedResourceWrap", v8::NewStringType::kInternalized).ToLocalChecked());
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
