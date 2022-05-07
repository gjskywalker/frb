// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XMATMUL_H
#define XMATMUL_H

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
#include "xmatmul_hw.h"

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
} XMatmul_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XMatmul;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMatmul_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMatmul_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMatmul_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMatmul_ReadReg(BaseAddress, RegOffset) \
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
int XMatmul_Initialize(XMatmul *InstancePtr, u16 DeviceId);
XMatmul_Config* XMatmul_LookupConfig(u16 DeviceId);
int XMatmul_CfgInitialize(XMatmul *InstancePtr, XMatmul_Config *ConfigPtr);
#else
int XMatmul_Initialize(XMatmul *InstancePtr, const char* InstanceName);
int XMatmul_Release(XMatmul *InstancePtr);
#endif

void XMatmul_Start(XMatmul *InstancePtr);
u32 XMatmul_IsDone(XMatmul *InstancePtr);
u32 XMatmul_IsIdle(XMatmul *InstancePtr);
u32 XMatmul_IsReady(XMatmul *InstancePtr);
void XMatmul_EnableAutoRestart(XMatmul *InstancePtr);
void XMatmul_DisableAutoRestart(XMatmul *InstancePtr);

void XMatmul_Set_mat_A(XMatmul *InstancePtr, u64 Data);
u64 XMatmul_Get_mat_A(XMatmul *InstancePtr);
void XMatmul_Set_mat_B(XMatmul *InstancePtr, u64 Data);
u64 XMatmul_Get_mat_B(XMatmul *InstancePtr);
void XMatmul_Set_mat_C(XMatmul *InstancePtr, u64 Data);
u64 XMatmul_Get_mat_C(XMatmul *InstancePtr);
void XMatmul_Set_A_H(XMatmul *InstancePtr, u32 Data);
u32 XMatmul_Get_A_H(XMatmul *InstancePtr);
void XMatmul_Set_A_W(XMatmul *InstancePtr, u32 Data);
u32 XMatmul_Get_A_W(XMatmul *InstancePtr);
void XMatmul_Set_B_H(XMatmul *InstancePtr, u32 Data);
u32 XMatmul_Get_B_H(XMatmul *InstancePtr);
void XMatmul_Set_B_W(XMatmul *InstancePtr, u32 Data);
u32 XMatmul_Get_B_W(XMatmul *InstancePtr);

void XMatmul_InterruptGlobalEnable(XMatmul *InstancePtr);
void XMatmul_InterruptGlobalDisable(XMatmul *InstancePtr);
void XMatmul_InterruptEnable(XMatmul *InstancePtr, u32 Mask);
void XMatmul_InterruptDisable(XMatmul *InstancePtr, u32 Mask);
void XMatmul_InterruptClear(XMatmul *InstancePtr, u32 Mask);
u32 XMatmul_InterruptGetEnabled(XMatmul *InstancePtr);
u32 XMatmul_InterruptGetStatus(XMatmul *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
