// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xim2col_mat.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XIm2col_mat_CfgInitialize(XIm2col_mat *InstancePtr, XIm2col_mat_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XIm2col_mat_Start(XIm2col_mat *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_AP_CTRL) & 0x80;
    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XIm2col_mat_IsDone(XIm2col_mat *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XIm2col_mat_IsIdle(XIm2col_mat *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XIm2col_mat_IsReady(XIm2col_mat *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XIm2col_mat_EnableAutoRestart(XIm2col_mat *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XIm2col_mat_DisableAutoRestart(XIm2col_mat *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_AP_CTRL, 0);
}

void XIm2col_mat_Set_mat_in(XIm2col_mat *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_MAT_IN_DATA, (u32)(Data));
    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_MAT_IN_DATA + 4, (u32)(Data >> 32));
}

u64 XIm2col_mat_Get_mat_in(XIm2col_mat *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_MAT_IN_DATA);
    Data += (u64)XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_MAT_IN_DATA + 4) << 32;
    return Data;
}

void XIm2col_mat_Set_mat_out(XIm2col_mat *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_MAT_OUT_DATA, (u32)(Data));
    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_MAT_OUT_DATA + 4, (u32)(Data >> 32));
}

u64 XIm2col_mat_Get_mat_out(XIm2col_mat *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_MAT_OUT_DATA);
    Data += (u64)XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_MAT_OUT_DATA + 4) << 32;
    return Data;
}

void XIm2col_mat_Set_inchannels(XIm2col_mat *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_INCHANNELS_DATA, Data);
}

u32 XIm2col_mat_Get_inchannels(XIm2col_mat *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_INCHANNELS_DATA);
    return Data;
}

void XIm2col_mat_Set_stride(XIm2col_mat *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_STRIDE_DATA, Data);
}

u32 XIm2col_mat_Get_stride(XIm2col_mat *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_STRIDE_DATA);
    return Data;
}

void XIm2col_mat_Set_padding(XIm2col_mat *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_PADDING_DATA, Data);
}

u32 XIm2col_mat_Get_padding(XIm2col_mat *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_PADDING_DATA);
    return Data;
}

void XIm2col_mat_Set_kernel_size(XIm2col_mat *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_KERNEL_SIZE_DATA, Data);
}

u32 XIm2col_mat_Get_kernel_size(XIm2col_mat *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_KERNEL_SIZE_DATA);
    return Data;
}

void XIm2col_mat_Set_mat_h(XIm2col_mat *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_MAT_H_DATA, Data);
}

u32 XIm2col_mat_Get_mat_h(XIm2col_mat *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_MAT_H_DATA);
    return Data;
}

void XIm2col_mat_Set_mat_w(XIm2col_mat *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_MAT_W_DATA, Data);
}

u32 XIm2col_mat_Get_mat_w(XIm2col_mat *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_MAT_W_DATA);
    return Data;
}

void XIm2col_mat_InterruptGlobalEnable(XIm2col_mat *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_GIE, 1);
}

void XIm2col_mat_InterruptGlobalDisable(XIm2col_mat *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_GIE, 0);
}

void XIm2col_mat_InterruptEnable(XIm2col_mat *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_IER);
    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_IER, Register | Mask);
}

void XIm2col_mat_InterruptDisable(XIm2col_mat *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_IER);
    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_IER, Register & (~Mask));
}

void XIm2col_mat_InterruptClear(XIm2col_mat *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIm2col_mat_WriteReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_ISR, Mask);
}

u32 XIm2col_mat_InterruptGetEnabled(XIm2col_mat *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_IER);
}

u32 XIm2col_mat_InterruptGetStatus(XIm2col_mat *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XIm2col_mat_ReadReg(InstancePtr->Control_BaseAddress, XIM2COL_MAT_CONTROL_ADDR_ISR);
}

