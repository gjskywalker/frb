// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xrelu.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XRelu_CfgInitialize(XRelu *InstancePtr, XRelu_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XRelu_Start(XRelu *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRelu_ReadReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_AP_CTRL) & 0x80;
    XRelu_WriteReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XRelu_IsDone(XRelu *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRelu_ReadReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XRelu_IsIdle(XRelu *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRelu_ReadReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XRelu_IsReady(XRelu *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRelu_ReadReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XRelu_EnableAutoRestart(XRelu *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRelu_WriteReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XRelu_DisableAutoRestart(XRelu *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRelu_WriteReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_AP_CTRL, 0);
}

void XRelu_Set_mat_in(XRelu *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRelu_WriteReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_MAT_IN_DATA, (u32)(Data));
    XRelu_WriteReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_MAT_IN_DATA + 4, (u32)(Data >> 32));
}

u64 XRelu_Get_mat_in(XRelu *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRelu_ReadReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_MAT_IN_DATA);
    Data += (u64)XRelu_ReadReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_MAT_IN_DATA + 4) << 32;
    return Data;
}

void XRelu_Set_mat_out(XRelu *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRelu_WriteReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_MAT_OUT_DATA, (u32)(Data));
    XRelu_WriteReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_MAT_OUT_DATA + 4, (u32)(Data >> 32));
}

u64 XRelu_Get_mat_out(XRelu *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRelu_ReadReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_MAT_OUT_DATA);
    Data += (u64)XRelu_ReadReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_MAT_OUT_DATA + 4) << 32;
    return Data;
}

void XRelu_Set_num(XRelu *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRelu_WriteReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_NUM_DATA, Data);
}

u32 XRelu_Get_num(XRelu *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRelu_ReadReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_NUM_DATA);
    return Data;
}

void XRelu_InterruptGlobalEnable(XRelu *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRelu_WriteReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_GIE, 1);
}

void XRelu_InterruptGlobalDisable(XRelu *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRelu_WriteReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_GIE, 0);
}

void XRelu_InterruptEnable(XRelu *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XRelu_ReadReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_IER);
    XRelu_WriteReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_IER, Register | Mask);
}

void XRelu_InterruptDisable(XRelu *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XRelu_ReadReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_IER);
    XRelu_WriteReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_IER, Register & (~Mask));
}

void XRelu_InterruptClear(XRelu *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRelu_WriteReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_ISR, Mask);
}

u32 XRelu_InterruptGetEnabled(XRelu *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRelu_ReadReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_IER);
}

u32 XRelu_InterruptGetStatus(XRelu *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRelu_ReadReg(InstancePtr->Control_BaseAddress, XRELU_CONTROL_ADDR_ISR);
}

