// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// control
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read/COR)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0 - enable ap_done interrupt (Read/Write)
//        bit 1 - enable ap_ready interrupt (Read/Write)
//        bit 5 - enable ap_local_deadlock interrupt (Read/Write)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0 - ap_done (COR/TOW)
//        bit 1 - ap_ready (COR/TOW)
//        bit 5 - ap_local_deadlock (COR/TOW)
//        others - reserved
// 0x10 : Data signal of mat_in
//        bit 31~0 - mat_in[31:0] (Read/Write)
// 0x14 : Data signal of mat_in
//        bit 31~0 - mat_in[63:32] (Read/Write)
// 0x18 : reserved
// 0x1c : Data signal of mat_out
//        bit 31~0 - mat_out[31:0] (Read/Write)
// 0x20 : Data signal of mat_out
//        bit 31~0 - mat_out[63:32] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of inchannels
//        bit 5~0 - inchannels[5:0] (Read/Write)
//        others  - reserved
// 0x2c : reserved
// 0x30 : Data signal of stride
//        bit 2~0 - stride[2:0] (Read/Write)
//        others  - reserved
// 0x34 : reserved
// 0x38 : Data signal of padding
//        bit 0  - padding[0] (Read/Write)
//        others - reserved
// 0x3c : reserved
// 0x40 : Data signal of kernel_size
//        bit 2~0 - kernel_size[2:0] (Read/Write)
//        others  - reserved
// 0x44 : reserved
// 0x48 : Data signal of mat_h
//        bit 5~0 - mat_h[5:0] (Read/Write)
//        others  - reserved
// 0x4c : reserved
// 0x50 : Data signal of mat_w
//        bit 5~0 - mat_w[5:0] (Read/Write)
//        others  - reserved
// 0x54 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XIM2COL_MAT_CONTROL_ADDR_AP_CTRL          0x00
#define XIM2COL_MAT_CONTROL_ADDR_GIE              0x04
#define XIM2COL_MAT_CONTROL_ADDR_IER              0x08
#define XIM2COL_MAT_CONTROL_ADDR_ISR              0x0c
#define XIM2COL_MAT_CONTROL_ADDR_MAT_IN_DATA      0x10
#define XIM2COL_MAT_CONTROL_BITS_MAT_IN_DATA      64
#define XIM2COL_MAT_CONTROL_ADDR_MAT_OUT_DATA     0x1c
#define XIM2COL_MAT_CONTROL_BITS_MAT_OUT_DATA     64
#define XIM2COL_MAT_CONTROL_ADDR_INCHANNELS_DATA  0x28
#define XIM2COL_MAT_CONTROL_BITS_INCHANNELS_DATA  6
#define XIM2COL_MAT_CONTROL_ADDR_STRIDE_DATA      0x30
#define XIM2COL_MAT_CONTROL_BITS_STRIDE_DATA      3
#define XIM2COL_MAT_CONTROL_ADDR_PADDING_DATA     0x38
#define XIM2COL_MAT_CONTROL_BITS_PADDING_DATA     1
#define XIM2COL_MAT_CONTROL_ADDR_KERNEL_SIZE_DATA 0x40
#define XIM2COL_MAT_CONTROL_BITS_KERNEL_SIZE_DATA 3
#define XIM2COL_MAT_CONTROL_ADDR_MAT_H_DATA       0x48
#define XIM2COL_MAT_CONTROL_BITS_MAT_H_DATA       6
#define XIM2COL_MAT_CONTROL_ADDR_MAT_W_DATA       0x50
#define XIM2COL_MAT_CONTROL_BITS_MAT_W_DATA       6

