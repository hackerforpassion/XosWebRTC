///////////////////////////////////////////////////////////////////////
/// Copyright 2013, Google Inc.
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
///   File: PeerWindow.hpp
///
/// Author: $author$
///   Date: 2/19/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_WEBRTC_CLIENT_CONSOLE_PEERWINDOW_HPP
#define _XOS_WEBRTC_CLIENT_CONSOLE_PEERWINDOW_HPP

#include "xos/webrtc/client/PeerWindow.hpp"
#include "xos/webrtc/client/console/VideoRenderer.hpp"

namespace xos {
namespace webrtc {
namespace client {
namespace console {

typedef client::PeerWindowImplement PeerWindowImplement;
typedef client::PeerWindow PeerWindowExtend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS PeerWindow: virtual public PeerWindowImplement, public PeerWindowExtend {
public:
    typedef PeerWindowImplement Implements;
    typedef PeerWindowExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    PeerWindow
    (const char* serverName=0, int serverPort=0,
     bool showConnectionState = XOS_WEBRTC_CLIENT_WINDOW_DEFAULT_SHOW_CONNECTION_STATE,
     bool handleButtonEvents = XOS_WEBRTC_CLIENT_WINDOW_DEFAULT_HANDLE_BUTTON_EVENTS,
     bool autoConnectToPeerOn = true, bool autoConnectToPeerAfterOn = true)
    : Extends(serverName, serverPort, showConnectionState, handleButtonEvents) {
        m_postButtonEventUIMessages = true;
        m_useUIMessageQueue = true;
        m_useOpenGLRenderer = false;
        m_autoConnectToPeerOn = autoConnectToPeerOn;
        m_autoConnectToPeerAfterOn = autoConnectToPeerAfterOn;
    }
    virtual ~PeerWindow() {
        client::VideoRenderer* renderer;
        if ((renderer = remote_video_.release())) ReleaseVideoRenderer(renderer);
        if ((renderer = local_video_.release())) ReleaseVideoRenderer(renderer);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual client::VideoRenderer* AcquireVideoRenderer
     (size_t width, size_t height, bool isRemote=false) { 
        client::VideoRenderer* renderer = new VideoRenderer(*this, width, height, isRemote);
        return renderer; 
    }
    virtual bool ReleaseVideoRenderer(client::VideoRenderer* renderer) { 
        if ((renderer))
        {
            delete renderer;
            return true;
        }
        return false; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool UpdateWindow() { return true; }
    virtual bool ValidateWindow() { return true; }
    virtual bool InvalidateWindow(bool eraseBackground = true) { return true; }
};

} // namespace console 
} // namespace client 
} // namespace webrtc 
} // namespace xos 

#endif // _XOS_WEBRTC_CLIENT_CONSOLE_PEERWINDOW_HPP 
