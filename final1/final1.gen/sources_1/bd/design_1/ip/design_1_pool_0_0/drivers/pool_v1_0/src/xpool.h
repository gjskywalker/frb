// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XPOOL_H
#define XPOOL_H

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
#include "xpool_hw.h"

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
} XPool_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XPool;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XPool_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XPool_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XPool_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XPool_ReadReg(BaseAddress, RegOffset) \
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
int XPool_Initialize(XPool *InstancePtr, u16 DeviceId);
XPool_Config* XPool_LookupConfig(u16 DeviceId);
int XPool_CfgInitialize(XPool *InstancePtr, XPool_Config *ConfigPtr);
#else
int XPool_Initialize(XPool *InstancePtr, const char* InstanceName);
int XPool_Release(XPool *InstancePtr);
#endif

void XPool_Start(XPool *InstancePtr);
u32 XPool_IsDone(XPool *InstancePtr);
u32 XPool_IsIdle(XPool *InstancePtr);
u32 XPool_IsReady(XPool *InstancePtr);
void XPool_EnableAutoRestart(XPool *InstancePtr);
void XPool_DisableAutoRestart(XPool *InstancePtr);

void XPool_Set_mat_in(XPool *InstancePtr, u64 Data);
u64 XPool_Get_mat_in(XPool *InstancePtr);
void XPool_Set_mat_out(XPool *InstancePtr, u64 Data);
u64 XPool_Get_mat_out(XPool *InstancePtr);
void XPool_Set_inchannels(XPool *InstancePtr, u32 Data);
u32 XPool_Get_inchannels(XPool *InstancePtr);
void XPool_Set_mat_h(XPool *InstancePtr, u32 Data);
u32 XPool_Get_mat_h(XPool *InstancePtr);
void XPool_Set_mat_w(XPool *InstancePtr, u32 Data);
u32 XPool_Get_mat_w(XPool *InstancePtr);
void XPool_Set_kh(XPool *InstancePtr, u32 Data);
u32 XPool_Get_kh(XPool *InstancePtr);
void XPool_Set_kw(XPool *InstancePtr, u32 Data);
u32 XPool_Get_kw(XPool *InstancePtr);
void XPool_Set_mode(XPool *InstancePtr, u32 Data);
u32 XPool_Get_mode(XPool *InstancePtr);

void XPool_InterruptGlobalEnable(XPool *InstancePtr);
void XPool_InterruptGlobalDisable(XPool *InstancePtr);
void XPool_InterruptEnable(XPool *InstancePtr, u32 Mask);
void XPool_InterruptDisable(XPool *InstancePtr, u32 Mask);
void XPool_InterruptClear(XPool *InstancePtr, u32 Mask);
u32 XPool_InterruptGetEnabled(XPool *InstancePtr);
u32 XPool_InterruptGetStatus(XPool *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
