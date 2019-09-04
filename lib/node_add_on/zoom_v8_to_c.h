#ifndef _v8_to_c_h_
#define _v8_to_c_h_
#include <string>
#include "zoom_node_common_include.h"
#if (defined BUILD_WIN)
#define ZNODESTRING std::wstring
#else
#define ZNODESTRING std::string
#endif
void zoom_v8toc(v8::Local<v8::String> v8string, ZNODESTRING& c_string);
void zoom_v8toc(v8::Local<v8::Boolean> v8boolean, bool& c_bool);
std::string zs2s(const ZNODESTRING& s);
#endif // !_v8_to_c_h_
