///////////////////////////////////////////////////////////////////////
/// Copyright 2012, Google Inc.
///
/// Redistribution and use in source and binary forms, with or without
/// modification, are permitted provided that the following conditions are met:
/// 
///  1. Redistributions of source code must retain the above copyright notice,
///     this list of conditions and the following disclaimer.
///  2. Redistributions in binary form must reproduce the above copyright notice,
///     this list of conditions and the following disclaimer in the documentation
///     and/or other materials provided with the distribution.
///  3. The name of the author may not be used to endorse or promote products
///     derived from this software without specific prior written permission.
/// 
/// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
/// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
/// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
/// EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
/// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
/// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
/// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
/// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
/// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
/// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///
///   File: XosWebRtcClientVideoCodecMode.hpp
///
/// Author: $author$
///   Date: 12/8/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWEBRTCCLIENTVIDEOCODECMODE_HPP
#define _XOSWEBRTCCLIENTVIDEOCODECMODE_HPP

#define XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_NAME_CIF "CIF"
#define XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_NAME_4CIF "4CIF"
#define XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_NAME_QQVGA "QQVGA"
#define XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_NAME_QVGA "QVGA"
#define XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_NAME_VGA "VGA"
#define XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_NAME_SVGA "SVGA"
#define XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_NAME_HD "HD"
#define XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_NAME_FHD "FHD"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///    Enum: XosWebRtcClientVideoCodecMode
///
///  Author: $author$
///    Date: 12/8/2012
///////////////////////////////////////////////////////////////////////
typedef int XosWebRtcClientVideoCodecMode;
enum
{
    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_UNKNOWN = -1,
    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_NONE = 0,

    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_ROWS_BITS = 0,
    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_ROWS_MASK = 0x0FFF,

    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS_BITS = 12,
    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS_MASK = 0x0FFF000,

    //
    // Named modes
    //
    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_CIF = // 352x288
    ((352 << XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS_BITS) | 288),

    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_4CIF = // 704x576
    ((704 << XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS_BITS) | 576),

    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_QQVGA = // 160x120
    ((160 << XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS_BITS) | 120),

    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_QVGA = // 320x240
    ((320 << XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS_BITS) | 240),

    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_VGA = // 640x480
    ((640 << XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS_BITS) | 480),

    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_HD = // 1280x720
    ((1280 << XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS_BITS) | 720),

    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_FHD = // 1920x1080
    ((1920 << XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS_BITS) | 1080),

    //
    // Unnamed modes
    //
    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_80x60 = // 80x60
    ((80 << XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS_BITS) | 60),

    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_160x120 = // 160x120
    ((160 << XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS_BITS) | 120),

    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_800x600 = // 800x600
    ((800 << XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS_BITS) | 600),

    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_720x480 = // 720x480
    ((720 << XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS_BITS) | 480),

    XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_1440x1080 = // 1440x1080
    ((1440 << XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS_BITS) | 1080),
};

#define XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_ROWS(mode) \
    ((mode & XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_ROWS_MASK) \
     >> XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_ROWS_BITS)

#define XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS(mode) \
    ((mode & XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS_MASK) \
     >> XOS_WEBRTC_CLIENT_VIDEO_CODEC_MODE_COLS_BITS)

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWEBRTCCLIENTVIDEOCODECMODE_HPP 
        

