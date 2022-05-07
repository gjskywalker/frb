// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xim2col_mat.h"

extern XIm2col_mat_Config XIm2col_mat_ConfigTable[];

XIm2col_mat_Config *XIm2col_mat_LookupConfig(u16 DeviceId) {
	XIm2col_mat_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XIM2COL_MAT_NUM_INSTANCES; Index++) {
		if (XIm2col_mat_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XIm2col_mat_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XIm2col_mat_Initialize(XIm2col_mat *InstancePtr, u16 DeviceId) {
	XIm2col_mat_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XIm2col_mat_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XIm2col_mat_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

