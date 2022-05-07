// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xmat_add.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMat_add_CfgInitialize(XMat_add *InstancePtr, XMat_add_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMat_add_Start(XMat_add *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMat_add_ReadReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_AP_CTRL) & 0x80;
    XMat_add_WriteReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMat_add_IsDone(XMat_add *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMat_add_ReadReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMat_add_IsIdle(XMat_add *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMat_add_ReadReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMat_add_IsReady(XMat_add *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMat_add_ReadReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMat_add_EnableAutoRestart(XMat_add *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMat_add_WriteReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XMat_add_DisableAutoRestart(XMat_add *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMat_add_WriteReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_AP_CTRL, 0);
}

void XMat_add_Set_mat_in1(XMat_add *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMat_add_WriteReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_MAT_IN1_DATA, (u32)(Data));
    XMat_add_WriteReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_MAT_IN1_DATA + 4, (u32)(Data >> 32));
}

u64 XMat_add_Get_mat_in1(XMat_add *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMat_add_ReadReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_MAT_IN1_DATA);
    Data += (u64)XMat_add_ReadReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_MAT_IN1_DATA + 4) << 32;
    return Data;
}

void XMat_add_Set_mat_in2(XMat_add *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMat_add_WriteReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_MAT_IN2_DATA, (u32)(Data));
    XMat_add_WriteReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_MAT_IN2_DATA + 4, (u32)(Data >> 32));
}

u64 XMat_add_Get_mat_in2(XMat_add *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMat_add_ReadReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_MAT_IN2_DATA);
    Data += (u64)XMat_add_ReadReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_MAT_IN2_DATA + 4) << 32;
    return Data;
}

void XMat_add_Set_mat_out(XMat_add *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMat_add_WriteReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_MAT_OUT_DATA, (u32)(Data));
    XMat_add_WriteReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_MAT_OUT_DATA + 4, (u32)(Data >> 32));
}

u64 XMat_add_Get_mat_out(XMat_add *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMat_add_ReadReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_MAT_OUT_DATA);
    Data += (u64)XMat_add_ReadReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_MAT_OUT_DATA + 4) << 32;
    return Data;
}

void XMat_add_Set_num(XMat_add *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMat_add_WriteReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_NUM_DATA, Data);
}

u32 XMat_add_Get_num(XMat_add *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMat_add_ReadReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_NUM_DATA);
    return Data;
}

void XMat_add_InterruptGlobalEnable(XMat_add *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMat_add_WriteReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_GIE, 1);
}

void XMat_add_InterruptGlobalDisable(XMat_add *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMat_add_WriteReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_GIE, 0);
}

void XMat_add_InterruptEnable(XMat_add *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMat_add_ReadReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_IER);
    XMat_add_WriteReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_IER, Register | Mask);
}

void XMat_add_InterruptDisable(XMat_add *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMat_add_ReadReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_IER);
    XMat_add_WriteReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_IER, Register & (~Mask));
}

void XMat_add_InterruptClear(XMat_add *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMat_add_WriteReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_ISR, Mask);
}

u32 XMat_add_InterruptGetEnabled(XMat_add *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMat_add_ReadReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_IER);
}

u32 XMat_add_InterruptGetStatus(XMat_add *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMat_add_ReadReg(InstancePtr->Control_BaseAddress, XMAT_ADD_CONTROL_ADDR_ISR);
}

