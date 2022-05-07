// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xmatmul.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMatmul_CfgInitialize(XMatmul *InstancePtr, XMatmul_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMatmul_Start(XMatmul *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_AP_CTRL) & 0x80;
    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMatmul_IsDone(XMatmul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMatmul_IsIdle(XMatmul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMatmul_IsReady(XMatmul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMatmul_EnableAutoRestart(XMatmul *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XMatmul_DisableAutoRestart(XMatmul *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_AP_CTRL, 0);
}

void XMatmul_Set_mat_A(XMatmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_MAT_A_DATA, (u32)(Data));
    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_MAT_A_DATA + 4, (u32)(Data >> 32));
}

u64 XMatmul_Get_mat_A(XMatmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_MAT_A_DATA);
    Data += (u64)XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_MAT_A_DATA + 4) << 32;
    return Data;
}

void XMatmul_Set_mat_B(XMatmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_MAT_B_DATA, (u32)(Data));
    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_MAT_B_DATA + 4, (u32)(Data >> 32));
}

u64 XMatmul_Get_mat_B(XMatmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_MAT_B_DATA);
    Data += (u64)XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_MAT_B_DATA + 4) << 32;
    return Data;
}

void XMatmul_Set_mat_C(XMatmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_MAT_C_DATA, (u32)(Data));
    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_MAT_C_DATA + 4, (u32)(Data >> 32));
}

u64 XMatmul_Get_mat_C(XMatmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_MAT_C_DATA);
    Data += (u64)XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_MAT_C_DATA + 4) << 32;
    return Data;
}

void XMatmul_Set_A_H(XMatmul *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_A_H_DATA, Data);
}

u32 XMatmul_Get_A_H(XMatmul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_A_H_DATA);
    return Data;
}

void XMatmul_Set_A_W(XMatmul *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_A_W_DATA, Data);
}

u32 XMatmul_Get_A_W(XMatmul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_A_W_DATA);
    return Data;
}

void XMatmul_Set_B_H(XMatmul *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_B_H_DATA, Data);
}

u32 XMatmul_Get_B_H(XMatmul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_B_H_DATA);
    return Data;
}

void XMatmul_Set_B_W(XMatmul *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_B_W_DATA, Data);
}

u32 XMatmul_Get_B_W(XMatmul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_B_W_DATA);
    return Data;
}

void XMatmul_InterruptGlobalEnable(XMatmul *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_GIE, 1);
}

void XMatmul_InterruptGlobalDisable(XMatmul *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_GIE, 0);
}

void XMatmul_InterruptEnable(XMatmul *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_IER);
    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_IER, Register | Mask);
}

void XMatmul_InterruptDisable(XMatmul *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_IER);
    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_IER, Register & (~Mask));
}

void XMatmul_InterruptClear(XMatmul *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatmul_WriteReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_ISR, Mask);
}

u32 XMatmul_InterruptGetEnabled(XMatmul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_IER);
}

u32 XMatmul_InterruptGetStatus(XMatmul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMatmul_ReadReg(InstancePtr->Control_BaseAddress, XMATMUL_CONTROL_ADDR_ISR);
}

