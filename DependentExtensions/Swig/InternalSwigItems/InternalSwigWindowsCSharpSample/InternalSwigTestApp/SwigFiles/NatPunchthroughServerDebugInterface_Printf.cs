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

public class NatPunchthroughServerDebugInterface_Printf : NatPunchthroughServerDebugInterface {
  private HandleRef swigCPtr;

  internal NatPunchthroughServerDebugInterface_Printf(IntPtr cPtr, bool cMemoryOwn) : base(RakNetPINVOKE.NatPunchthroughServerDebugInterface_Printf_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(NatPunchthroughServerDebugInterface_Printf obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~NatPunchthroughServerDebugInterface_Printf() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          RakNetPINVOKE.delete_NatPunchthroughServerDebugInterface_Printf(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public override void OnServerMessage(string msg) {
    RakNetPINVOKE.NatPunchthroughServerDebugInterface_Printf_OnServerMessage(swigCPtr, msg);
  }

  public NatPunchthroughServerDebugInterface_Printf() : this(RakNetPINVOKE.new_NatPunchthroughServerDebugInterface_Printf(), true) {
  }

}

}
