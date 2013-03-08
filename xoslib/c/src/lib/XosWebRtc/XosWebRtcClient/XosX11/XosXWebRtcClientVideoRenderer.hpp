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
///   File: XosXWebRtcClientVideoRenderer.hpp
///
/// Author: $author$
///   Date: 7/4/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXWEBRTCCLIENTVIDEORENDERER_HPP
#define _XOSXWEBRTCCLIENTVIDEORENDERER_HPP

#include "XosWebRtcClientBaseWindow.hpp"
#include "XosWebRtcClientVideoRenderer.hpp"
#include "XosPThreadMutex.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosXWebRtcClientVideoRendererExtend
///
///  Author: $author$
///    Date: 7/4/2012
///////////////////////////////////////////////////////////////////////
typedef XosWebRtcClientVideoRenderer
XosXWebRtcClientVideoRendererExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXWebRtcClientVideoRenderer
///
/// Author: $author$
///   Date: 7/4/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXWebRtcClientVideoRenderer
: public XosXWebRtcClientVideoRendererExtend
{
public:
    typedef XosXWebRtcClientVideoRendererExtend Extends;

    XosWebRtcClientBaseWindow& m_wnd;
    XosPThreadMutex buffer_lock_;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXWebRtcClientVideoRenderer
    ///
    ///       Author: $author$
    ///         Date: 7/4/2012
    ///////////////////////////////////////////////////////////////////////
    XosXWebRtcClientVideoRenderer
    (XosWebRtcClientBaseWindow& wnd, 
     size_t width, size_t height, bool isRemote=false)
    : Extends(width, height, isRemote),
      m_wnd(wnd)
    {
        buffer_lock_.Create();
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosXWebRtcClientVideoRenderer
    ///
    ///      Author: $author$
    ///        Date: 7/4/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosXWebRtcClientVideoRenderer()
    {
        buffer_lock_.Destroy();
    }

    virtual void UpdateVisibleFrame() 
    { 
        if (cricket::FOURCC_ABGR != (RenderImageFormat()))
            ConvertARGBToABGR();

        m_wnd.OnInvalidateWindow(false);
    }
    virtual void Lock() { buffer_lock_.Lock(); }
    virtual void Unlock() { buffer_lock_.Unlock(); }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSXWEBRTCCLIENTVIDEORENDERER_HPP 
        

