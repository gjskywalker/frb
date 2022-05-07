// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XIM2COL_MAT_H
#define XIM2COL_MAT_H

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
#include "xim2col_mat_hw.h"

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
} XIm2col_mat_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XIm2col_mat;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XIm2col_mat_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XIm2col_mat_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XIm2col_mat_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XIm2col_mat_ReadReg(BaseAddress, RegOffset) \
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
int XIm2col_mat_Initialize(XIm2col_mat *InstancePtr, u16 DeviceId);
XIm2col_mat_Config* XIm2col_mat_LookupConfig(u16 DeviceId);
int XIm2col_mat_CfgInitialize(XIm2col_mat *InstancePtr, XIm2col_mat_Config *ConfigPtr);
#else
int XIm2col_mat_Initialize(XIm2col_mat *InstancePtr, const char* InstanceName);
int XIm2col_mat_Release(XIm2col_mat *InstancePtr);
#endif

void XIm2col_mat_Start(XIm2col_mat *InstancePtr);
u32 XIm2col_mat_IsDone(XIm2col_mat *InstancePtr);
u32 XIm2col_mat_IsIdle(XIm2col_mat *InstancePtr);
u32 XIm2col_mat_IsReady(XIm2col_mat *InstancePtr);
void XIm2col_mat_EnableAutoRestart(XIm2col_mat *InstancePtr);
void XIm2col_mat_DisableAutoRestart(XIm2col_mat *InstancePtr);

void XIm2col_mat_Set_mat_in(XIm2col_mat *InstancePtr, u64 Data);
u64 XIm2col_mat_Get_mat_in(XIm2col_mat *InstancePtr);
void XIm2col_mat_Set_mat_out(XIm2col_mat *InstancePtr, u64 Data);
u64 XIm2col_mat_Get_mat_out(XIm2col_mat *InstancePtr);
void XIm2col_mat_Set_inchannels(XIm2col_mat *InstancePtr, u32 Data);
u32 XIm2col_mat_Get_inchannels(XIm2col_mat *InstancePtr);
void XIm2col_mat_Set_stride(XIm2col_mat *InstancePtr, u32 Data);
u32 XIm2col_mat_Get_stride(XIm2col_mat *InstancePtr);
void XIm2col_mat_Set_padding(XIm2col_mat *InstancePtr, u32 Data);
u32 XIm2col_mat_Get_padding(XIm2col_mat *InstancePtr);
void XIm2col_mat_Set_kernel_size(XIm2col_mat *InstancePtr, u32 Data);
u32 XIm2col_mat_Get_kernel_size(XIm2col_mat *InstancePtr);
void XIm2col_mat_Set_mat_h(XIm2col_mat *InstancePtr, u32 Data);
u32 XIm2col_mat_Get_mat_h(XIm2col_mat *InstancePtr);
void XIm2col_mat_Set_mat_w(XIm2col_mat *InstancePtr, u32 Data);
u32 XIm2col_mat_Get_mat_w(XIm2col_mat *InstancePtr);

void XIm2col_mat_InterruptGlobalEnable(XIm2col_mat *InstancePtr);
void XIm2col_mat_InterruptGlobalDisable(XIm2col_mat *InstancePtr);
void XIm2col_mat_InterruptEnable(XIm2col_mat *InstancePtr, u32 Mask);
void XIm2col_mat_InterruptDisable(XIm2col_mat *InstancePtr, u32 Mask);
void XIm2col_mat_InterruptClear(XIm2col_mat *InstancePtr, u32 Mask);
u32 XIm2col_mat_InterruptGetEnabled(XIm2col_mat *InstancePtr);
u32 XIm2col_mat_InterruptGetStatus(XIm2col_mat *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
