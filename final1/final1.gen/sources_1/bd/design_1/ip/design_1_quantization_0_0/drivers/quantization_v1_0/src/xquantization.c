// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xquantization.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XQuantization_CfgInitialize(XQuantization *InstancePtr, XQuantization_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XQuantization_Start(XQuantization *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQuantization_ReadReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_AP_CTRL) & 0x80;
    XQuantization_WriteReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XQuantization_IsDone(XQuantization *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQuantization_ReadReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XQuantization_IsIdle(XQuantization *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQuantization_ReadReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XQuantization_IsReady(XQuantization *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQuantization_ReadReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XQuantization_EnableAutoRestart(XQuantization *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQuantization_WriteReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XQuantization_DisableAutoRestart(XQuantization *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQuantization_WriteReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_AP_CTRL, 0);
}

void XQuantization_Set_mat_in(XQuantization *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQuantization_WriteReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_MAT_IN_DATA, (u32)(Data));
    XQuantization_WriteReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_MAT_IN_DATA + 4, (u32)(Data >> 32));
}

u64 XQuantization_Get_mat_in(XQuantization *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQuantization_ReadReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_MAT_IN_DATA);
    Data += (u64)XQuantization_ReadReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_MAT_IN_DATA + 4) << 32;
    return Data;
}

void XQuantization_Set_mat_out(XQuantization *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQuantization_WriteReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_MAT_OUT_DATA, (u32)(Data));
    XQuantization_WriteReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_MAT_OUT_DATA + 4, (u32)(Data >> 32));
}

u64 XQuantization_Get_mat_out(XQuantization *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQuantization_ReadReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_MAT_OUT_DATA);
    Data += (u64)XQuantization_ReadReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_MAT_OUT_DATA + 4) << 32;
    return Data;
}

void XQuantization_Set_num(XQuantization *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQuantization_WriteReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_NUM_DATA, Data);
}

u32 XQuantization_Get_num(XQuantization *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQuantization_ReadReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_NUM_DATA);
    return Data;
}

void XQuantization_Set_scale_n(XQuantization *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQuantization_WriteReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_SCALE_N_DATA, Data);
}

u32 XQuantization_Get_scale_n(XQuantization *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQuantization_ReadReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_SCALE_N_DATA);
    return Data;
}

void XQuantization_Set_zero_point(XQuantization *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQuantization_WriteReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_ZERO_POINT_DATA, Data);
}

u32 XQuantization_Get_zero_point(XQuantization *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XQuantization_ReadReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_ZERO_POINT_DATA);
    return Data;
}

void XQuantization_InterruptGlobalEnable(XQuantization *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQuantization_WriteReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_GIE, 1);
}

void XQuantization_InterruptGlobalDisable(XQuantization *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQuantization_WriteReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_GIE, 0);
}

void XQuantization_InterruptEnable(XQuantization *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XQuantization_ReadReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_IER);
    XQuantization_WriteReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_IER, Register | Mask);
}

void XQuantization_InterruptDisable(XQuantization *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XQuantization_ReadReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_IER);
    XQuantization_WriteReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_IER, Register & (~Mask));
}

void XQuantization_InterruptClear(XQuantization *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XQuantization_WriteReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_ISR, Mask);
}

u32 XQuantization_InterruptGetEnabled(XQuantization *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XQuantization_ReadReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_IER);
}

u32 XQuantization_InterruptGetStatus(XQuantization *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XQuantization_ReadReg(InstancePtr->Control_BaseAddress, XQUANTIZATION_CONTROL_ADDR_ISR);
}

