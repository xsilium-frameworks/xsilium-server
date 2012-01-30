/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.0
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace RakNet {

using System;
using System.Runtime.InteropServices;

public class RakNetListSortQuery : IDisposable {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal RakNetListSortQuery(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(RakNetListSortQuery obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~RakNetListSortQuery() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          RakNetPINVOKE.delete_RakNetListSortQuery(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

    public SortQuery this[int index]  
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

  public RakNetListSortQuery() : this(RakNetPINVOKE.new_RakNetListSortQuery__SWIG_0(), true) {
  }

  public RakNetListSortQuery(RakNetListSortQuery original_copy) : this(RakNetPINVOKE.new_RakNetListSortQuery__SWIG_1(RakNetListSortQuery.getCPtr(original_copy)), true) {
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
  }

  public RakNetListSortQuery CopyData(RakNetListSortQuery original_copy) {
    RakNetListSortQuery ret = new RakNetListSortQuery(RakNetPINVOKE.RakNetListSortQuery_CopyData(swigCPtr, RakNetListSortQuery.getCPtr(original_copy)), false);
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public SortQuery Get(uint position) {
    SortQuery ret = new SortQuery(RakNetPINVOKE.RakNetListSortQuery_Get(swigCPtr, position), false);
    return ret;
  }

  public void Push(SortQuery input, string file, uint line) {
    RakNetPINVOKE.RakNetListSortQuery_Push(swigCPtr, SortQuery.getCPtr(input), file, line);
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
  }

  public SortQuery Pop() {
    SortQuery ret = new SortQuery(RakNetPINVOKE.RakNetListSortQuery_Pop(swigCPtr), false);
    return ret;
  }

  public void Insert(SortQuery input, uint position, string file, uint line) {
    RakNetPINVOKE.RakNetListSortQuery_Insert__SWIG_0(swigCPtr, SortQuery.getCPtr(input), position, file, line);
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Insert(SortQuery input, string file, uint line) {
    RakNetPINVOKE.RakNetListSortQuery_Insert__SWIG_1(swigCPtr, SortQuery.getCPtr(input), file, line);
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Replace(SortQuery input, SortQuery filler, uint position, string file, uint line) {
    RakNetPINVOKE.RakNetListSortQuery_Replace__SWIG_0(swigCPtr, SortQuery.getCPtr(input), SortQuery.getCPtr(filler), position, file, line);
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Replace(SortQuery input) {
    RakNetPINVOKE.RakNetListSortQuery_Replace__SWIG_1(swigCPtr, SortQuery.getCPtr(input));
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
  }

  public void RemoveAtIndex(uint position) {
    RakNetPINVOKE.RakNetListSortQuery_RemoveAtIndex(swigCPtr, position);
  }

  public void RemoveAtIndexFast(uint position) {
    RakNetPINVOKE.RakNetListSortQuery_RemoveAtIndexFast(swigCPtr, position);
  }

  public void RemoveFromEnd(uint num) {
    RakNetPINVOKE.RakNetListSortQuery_RemoveFromEnd__SWIG_0(swigCPtr, num);
  }

  public void RemoveFromEnd() {
    RakNetPINVOKE.RakNetListSortQuery_RemoveFromEnd__SWIG_1(swigCPtr);
  }

  public uint Size() {
    uint ret = RakNetPINVOKE.RakNetListSortQuery_Size(swigCPtr);
    return ret;
  }

  public void Clear(bool doNotDeallocateSmallBlocks, string file, uint line) {
    RakNetPINVOKE.RakNetListSortQuery_Clear(swigCPtr, doNotDeallocateSmallBlocks, file, line);
  }

  public void Preallocate(uint countNeeded, string file, uint line) {
    RakNetPINVOKE.RakNetListSortQuery_Preallocate(swigCPtr, countNeeded, file, line);
  }

  public void Compress(string file, uint line) {
    RakNetPINVOKE.RakNetListSortQuery_Compress(swigCPtr, file, line);
  }

}

}
