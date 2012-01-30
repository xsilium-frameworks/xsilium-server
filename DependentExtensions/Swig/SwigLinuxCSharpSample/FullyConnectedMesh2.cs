/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace RakNet {

using System;
using System.Runtime.InteropServices;

public class FullyConnectedMesh2 : PluginInterface2 {
  private HandleRef swigCPtr;

  internal FullyConnectedMesh2(IntPtr cPtr, bool cMemoryOwn) : base(RakNetPINVOKE.FullyConnectedMesh2Upcast(cPtr), cMemoryOwn) {
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(FullyConnectedMesh2 obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~FullyConnectedMesh2() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          RakNetPINVOKE.delete_FullyConnectedMesh2(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public static FullyConnectedMesh2 GetInstance() {
    IntPtr cPtr = RakNetPINVOKE.FullyConnectedMesh2_GetInstance();
    FullyConnectedMesh2 ret = (cPtr == IntPtr.Zero) ? null : new FullyConnectedMesh2(cPtr, false);
    return ret;
  }

  public static void DestroyInstance(FullyConnectedMesh2 i) {
    RakNetPINVOKE.FullyConnectedMesh2_DestroyInstance(FullyConnectedMesh2.getCPtr(i));
  }

  public FullyConnectedMesh2() : this(RakNetPINVOKE.new_FullyConnectedMesh2(), true) {
  }

  public void SetConnectOnNewRemoteConnection(bool attemptConnection, RakString pw) {
    RakNetPINVOKE.FullyConnectedMesh2_SetConnectOnNewRemoteConnection(swigCPtr, attemptConnection, RakString.getCPtr(pw));
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
  }

  public RakNetGUID GetConnectedHost() {
    RakNetGUID ret = new RakNetGUID(RakNetPINVOKE.FullyConnectedMesh2_GetConnectedHost(swigCPtr), true);
    return ret;
  }

  public SystemAddress GetConnectedHostAddr() {
    SystemAddress ret = new SystemAddress(RakNetPINVOKE.FullyConnectedMesh2_GetConnectedHostAddr(swigCPtr), true);
    return ret;
  }

  public RakNetGUID GetHostSystem() {
    RakNetGUID ret = new RakNetGUID(RakNetPINVOKE.FullyConnectedMesh2_GetHostSystem(swigCPtr), true);
    return ret;
  }

  public bool IsHostSystem() {
    bool ret = RakNetPINVOKE.FullyConnectedMesh2_IsHostSystem(swigCPtr);
    return ret;
  }

  public bool IsConnectedHost() {
    bool ret = RakNetPINVOKE.FullyConnectedMesh2_IsConnectedHost(swigCPtr);
    return ret;
  }

  public void SetAutoparticipateConnections(bool b) {
    RakNetPINVOKE.FullyConnectedMesh2_SetAutoparticipateConnections(swigCPtr, b);
  }

  public void ResetHostCalculation() {
    RakNetPINVOKE.FullyConnectedMesh2_ResetHostCalculation(swigCPtr);
  }

  public void AddParticipant(RakNetGUID rakNetGuid) {
    RakNetPINVOKE.FullyConnectedMesh2_AddParticipant(swigCPtr, RakNetGUID.getCPtr(rakNetGuid));
    if (RakNetPINVOKE.SWIGPendingException.Pending) throw RakNetPINVOKE.SWIGPendingException.Retrieve();
  }

  public uint GetParticipantCount() {
    uint ret = RakNetPINVOKE.FullyConnectedMesh2_GetParticipantCount__SWIG_0(swigCPtr);
    return ret;
  }

  public void GetParticipantCount(out uint participantListSize) {
    RakNetPINVOKE.FullyConnectedMesh2_GetParticipantCount__SWIG_1(swigCPtr, out participantListSize);
  }

}

}
