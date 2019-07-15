#pragma once
#include "common_include.h"
#include <map>
#include <string>
BEGIN_ZOOM_SDK_NAMESPACE
class ICustomizedResourceHelperWrap : public ICustomizedResourceHelper
{
public:
	static ICustomizedResourceHelperWrap& GetInst() { static ICustomizedResourceHelperWrap inst; return inst; }; 
	virtual SDKError AddCustomizedPictureResource(const wchar_t* key_, const wchar_t* absolute_resource_path);
	virtual SDKError AddCustomizedStringResource(SDKCustomizedStringType customizedType, const wchar_t* customizedString);
	virtual SDKError AddCustomizedURLResource(SDKCustomizedURLType customizedType, const wchar_t* customizedUrl);

	void ApplyAll();
private:
	std::map<std::wstring, std::wstring> cache_customized_pic_map;
	std::map<SDKCustomizedStringType, std::wstring> cache_customized_str_map;
	std::map<SDKCustomizedURLType, std::wstring> cache_customized_url_map;
};
END_ZOOM_SDK_NAMESPACE