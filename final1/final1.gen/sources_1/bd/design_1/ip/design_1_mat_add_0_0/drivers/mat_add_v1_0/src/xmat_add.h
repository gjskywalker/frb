// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XMAT_ADD_H
#define XMAT_ADD_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xmat_add_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_BaseAddress;
} XMat_add_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XMat_add;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMat_add_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMat_add_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMat_add_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMat_add_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XMat_add_Initialize(XMat_add *InstancePtr, u16 DeviceId);
XMat_add_Config* XMat_add_LookupConfig(u16 DeviceId);
int XMat_add_CfgInitialize(XMat_add *InstancePtr, XMat_add_Config *ConfigPtr);
#else
int XMat_add_Initialize(XMat_add *InstancePtr, const char* InstanceName);
int XMat_add_Release(XMat_add *InstancePtr);
#endif

void XMat_add_Start(XMat_add *InstancePtr);
u32 XMat_add_IsDone(XMat_add *InstancePtr);
u32 XMat_add_IsIdle(XMat_add *InstancePtr);
u32 XMat_add_IsReady(XMat_add *InstancePtr);
void XMat_add_EnableAutoRestart(XMat_add *InstancePtr);
void XMat_add_DisableAutoRestart(XMat_add *InstancePtr);

void XMat_add_Set_mat_in1(XMat_add *InstancePtr, u64 Data);
u64 XMat_add_Get_mat_in1(XMat_add *InstancePtr);
void XMat_add_Set_mat_in2(XMat_add *InstancePtr, u64 Data);
u64 XMat_add_Get_mat_in2(XMat_add *InstancePtr);
void XMat_add_Set_mat_out(XMat_add *InstancePtr, u64 Data);
u64 XMat_add_Get_mat_out(XMat_add *InstancePtr);
void XMat_add_Set_num(XMat_add *InstancePtr, u32 Data);
u32 XMat_add_Get_num(XMat_add *InstancePtr);

void XMat_add_InterruptGlobalEnable(XMat_add *InstancePtr);
void XMat_add_InterruptGlobalDisable(XMat_add *InstancePtr);
void XMat_add_InterruptEnable(XMat_add *InstancePtr, u32 Mask);
void XMat_add_InterruptDisable(XMat_add *InstancePtr, u32 Mask);
void XMat_add_InterruptClear(XMat_add *InstancePtr, u32 Mask);
u32 XMat_add_InterruptGetEnabled(XMat_add *InstancePtr);
u32 XMat_add_InterruptGetStatus(XMat_add *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
