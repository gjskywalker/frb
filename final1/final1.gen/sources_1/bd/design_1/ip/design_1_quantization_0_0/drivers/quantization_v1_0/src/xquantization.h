// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XQUANTIZATION_H
#define XQUANTIZATION_H

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
#include "xquantization_hw.h"

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
} XQuantization_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XQuantization;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XQuantization_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XQuantization_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XQuantization_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XQuantization_ReadReg(BaseAddress, RegOffset) \
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
int XQuantization_Initialize(XQuantization *InstancePtr, u16 DeviceId);
XQuantization_Config* XQuantization_LookupConfig(u16 DeviceId);
int XQuantization_CfgInitialize(XQuantization *InstancePtr, XQuantization_Config *ConfigPtr);
#else
int XQuantization_Initialize(XQuantization *InstancePtr, const char* InstanceName);
int XQuantization_Release(XQuantization *InstancePtr);
#endif

void XQuantization_Start(XQuantization *InstancePtr);
u32 XQuantization_IsDone(XQuantization *InstancePtr);
u32 XQuantization_IsIdle(XQuantization *InstancePtr);
u32 XQuantization_IsReady(XQuantization *InstancePtr);
void XQuantization_EnableAutoRestart(XQuantization *InstancePtr);
void XQuantization_DisableAutoRestart(XQuantization *InstancePtr);

void XQuantization_Set_mat_in(XQuantization *InstancePtr, u64 Data);
u64 XQuantization_Get_mat_in(XQuantization *InstancePtr);
void XQuantization_Set_mat_out(XQuantization *InstancePtr, u64 Data);
u64 XQuantization_Get_mat_out(XQuantization *InstancePtr);
void XQuantization_Set_num(XQuantization *InstancePtr, u32 Data);
u32 XQuantization_Get_num(XQuantization *InstancePtr);
void XQuantization_Set_scale_n(XQuantization *InstancePtr, u32 Data);
u32 XQuantization_Get_scale_n(XQuantization *InstancePtr);
void XQuantization_Set_zero_point(XQuantization *InstancePtr, u32 Data);
u32 XQuantization_Get_zero_point(XQuantization *InstancePtr);

void XQuantization_InterruptGlobalEnable(XQuantization *InstancePtr);
void XQuantization_InterruptGlobalDisable(XQuantization *InstancePtr);
void XQuantization_InterruptEnable(XQuantization *InstancePtr, u32 Mask);
void XQuantization_InterruptDisable(XQuantization *InstancePtr, u32 Mask);
void XQuantization_InterruptClear(XQuantization *InstancePtr, u32 Mask);
u32 XQuantization_InterruptGetEnabled(XQuantization *InstancePtr);
u32 XQuantization_InterruptGetStatus(XQuantization *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
