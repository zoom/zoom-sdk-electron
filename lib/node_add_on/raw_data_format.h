#ifndef _raw_data_format_h_
#define _raw_data_format_h_
#include "zoom_raw_data_wrap.h"
#include "uv_ipc_common.h"
#define TYPE_NONE  0
#define TYPE_VIDEO 1
#define TYPE_SHARE 2
#define TYPE_AUDIO 3
#if (defined _WIN32)
#define VIDEO_PIPE_NAME "\\\\.\\pipe\\videoPipe"
#define SHARE_PIPE_NAME "\\\\.\\pipe\\sharePipe"
#define AUDIO_PIPE_NAME "\\\\.\\pipe\\audioPipe"
#else
#define VIDEO_PIPE_NAME "/tmp/videoPipe"
#define SHARE_PIPE_NAME "/tmp/sharePipe"
#define AUDIO_PIPE_NAME "/tmp/audioPipe"
#endif
struct RawDataCommonHeader
{
	unsigned int type;
	RawDataCommonHeader()
	{
		type = TYPE_NONE;
	}
}
#ifdef _WIN32
;
#else
__attribute__((aligned(1)));
#endif 
struct VideoRawDataHeader
{
	RawDataCommonHeader common_header;
	unsigned int dataBufferLen;
	unsigned int recvHandleListCount;
	unsigned int isLimitedI420;
	unsigned int width;
	unsigned int height;
	unsigned int rotation;
	unsigned long long y_offset;
	unsigned long long u_offset;
	unsigned long long v_offset;
	unsigned int source_id;
	VideoRawDataHeader()
	{
		memset(this, 0, sizeof(*this));
	}
}
#ifdef _WIN32
;
#else
__attribute__((aligned(1)));
#endif 

struct AudioRawDataHeader
{
	RawDataCommonHeader common_header;
	unsigned int node_id;
	unsigned int dataBufferLen;
	unsigned int sampleRate;
	unsigned int channelNum;
	AudioRawDataHeader()
	{
		memset(this, 0, sizeof(*this));
	}
}
#ifdef _WIN32
;
#else
__attribute__((aligned(1)));
#endif 

UVIPCMessage* MakeUVIPCMsg(YUVRawDataI420* data_, IVector<unsigned long long >* recv_handle_list, unsigned int type);
UVIPCMessage* MakeUVIPCMsg(AudioRawData* data_, unsigned int node_id_, unsigned int type);
#endif // !_raw_data_format_h_
