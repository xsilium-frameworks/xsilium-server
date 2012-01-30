/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.1
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace RakNet {

using System;
using System.Runtime.InteropServices;

public class RakNetListRakNetSmartPtrRakNetSocket : IDisposable {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal RakNetListRakNetSmartPtrRakNetSocket(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(RakNetListRakNetSmartPtrRakNetSocket obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~RakNetListRakNetSmartPtrRakNetSocket() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          RakNetPINVOKE.delete_RakNetListRakNetSmartPtrRakNetSocket(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

    public RakNetSmartPtrRakNetSocket this[int index]  
    {  
        get   
        {
            return Get((uint)index); // use indexto retrieve and return another value.    
        }  
        set   
        {
            Replace(value, value, (uint)index, "Not used", 0);// use index and value to set the value somewhere.   
        }  
    } 

  public RakNetListRakNetSmartPtrRakNetSocket() : this(RakNetPINVOKE.new_RakNetListRakNetSmartPtrRakNetSocket__SWIG_0(), true) {
  }

  public RakNetListRakNetSmartPtrRakNetSocket(RakNetListRakNetSmartPtrRakNetSocket original_copy) : this(RakNetPINVOKE.new_RakNetListRakNetSmartPtrRakNetSocket__SWIG_1(RakNetListRakNetSmartPtrRakNetSocket.getCPtr(original_copy)), true) {
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
  }

  public RakNetListRakNetSmartPtrRakNetSocket CopyData(RakNetListRakNetSmartPtrRakNetSocket original_copy) {
    RakNetListRakNetSmartPtrRakNetSocket ret = new RakNetListRakNetSmartPtrRakNetSocket(RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_CopyData(swigCPtr, RakNetListRakNetSmartPtrRakNetSocket.getCPtr(original_copy)), false);
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t Get(uint position) {
    SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t ret = new SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t(RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_Get(swigCPtr, position), false);
    return ret;
  }

  public void Push(SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t input, string file, uint line) {
    RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_Push(swigCPtr, SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t.getCPtr(input), file, line);
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
  }

  public SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t Pop() {
    SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t ret = new SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t(RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_Pop(swigCPtr), false);
    return ret;
  }

  public void Insert(SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t input, uint position, string file, uint line) {
    RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_Insert__SWIG_0(swigCPtr, SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t.getCPtr(input), position, file, line);
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Insert(SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t input, string file, uint line) {
    RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_Insert__SWIG_1(swigCPtr, SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t.getCPtr(input), file, line);
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Replace(SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t input, SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t filler, uint position, string file, uint line) {
    RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_Replace__SWIG_0(swigCPtr, SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t.getCPtr(input), SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t.getCPtr(filler), position, file, line);
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Replace(SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t input) {
    RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_Replace__SWIG_1(swigCPtr, SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t.getCPtr(input));
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
  }

  public void RemoveAtIndex(uint position) {
    RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_RemoveAtIndex(swigCPtr, position);
  }

  public void RemoveAtIndexFast(uint position) {
    RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_RemoveAtIndexFast(swigCPtr, position);
  }

  public void RemoveFromEnd(uint num) {
    RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_RemoveFromEnd__SWIG_0(swigCPtr, num);
  }

  public void RemoveFromEnd() {
    RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_RemoveFromEnd__SWIG_1(swigCPtr);
  }

  public uint GetIndexOf(SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t input) {
    uint ret = RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_GetIndexOf(swigCPtr, SWIGTYPE_p_RakNet__RakNetSmartPtrT_RakNet__RakNetSocket_t.getCPtr(input));
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public uint Size() {
    uint ret = RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_Size(swigCPtr);
    return ret;
  }

  public void Clear(bool doNotDeallocateSmallBlocks, string file, uint line) {
    RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_Clear(swigCPtr, doNotDeallocateSmallBlocks, file, line);
  }

  public void Preallocate(uint countNeeded, string file, uint line) {
    RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_Preallocate(swigCPtr, countNeeded, file, line);
  }

  public void Compress(string file, uint line) {
    RakNetPINVOKE.RakNetListRakNetSmartPtrRakNetSocket_Compress(swigCPtr, file, line);
  }

}

}
