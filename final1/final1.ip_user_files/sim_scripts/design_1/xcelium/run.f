-makelib xcelium_lib/xilinx_vip -sv \
  "D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
  "D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
  "D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
  "D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
  "D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
  "D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
  "D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/axi_vip_if.sv" \
  "D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/clk_vip_if.sv" \
  "D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/rst_vip_if.sv" \
-endlib
-makelib xcelium_lib/xpm -sv \
  "D:/vivado/Vivado/2021.2/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
  "D:/vivado/Vivado/2021.2/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \
-endlib
-makelib xcelium_lib/xpm \
  "D:/vivado/Vivado/2021.2/data/ip/xpm/xpm_VCOMP.vhd" \
-endlib
-makelib xcelium_lib/axi_infrastructure_v1_1_0 \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_vip_v1_1_11 -sv \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/63b7/hdl/axi_vip_v1_1_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/processing_system7_vip_v1_0_13 -sv \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl/processing_system7_vip_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_processing_system7_0_0/sim/design_1_processing_system7_0_0.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_ama_addmuladd_6s_6s_6s_17s_17_4_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_control_s_axi.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_flow_control_loop_pipe_sequential_init.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_gmem_m_axi.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_mul_5ns_6s_11_1_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_mul_6s_6s_12_1_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_mul_8ns_8ns_16_1_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_mul_8s_8s_16_1_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_mul_mul_11s_6s_16_4_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_pool_Pipeline_VITIS_LOOP_44_3_VITIS_LOOP_47_4.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_sdiv_7s_8s_6_11_seq_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_sdiv_19ns_16s_18_23_seq_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool.v" \
  "../../../bd/design_1/ip/design_1_pool_0_0/sim/design_1_pool_0_0.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_control_s_axi.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_flow_control_loop_pipe_sequential_init.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_gmem_m_axi.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_mac_muladd_7ns_8s_7ns_15_4_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_mac_muladd_8s_8s_18s_18_4_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_matmul_Pipeline_VITIS_LOOP_16_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_matmul_Pipeline_VITIS_LOOP_20_2_VITIS_LOOP_21_3_VITIS_LOOP_22_4.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_mul_7ns_8ns_15_1_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_mul_7ns_8s_15_1_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_mul_8ns_8ns_16_1_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_mul_mul_8ns_16ns_24_4_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul.v" \
  "../../../bd/design_1/ip/design_1_matmul_0_0/sim/design_1_matmul_0_0.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/069d/hdl/verilog/mat_add_control_s_axi.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/069d/hdl/verilog/mat_add_gmem_m_axi.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/069d/hdl/verilog/mat_add.v" \
  "../../../bd/design_1/ip/design_1_mat_add_0_0/sim/design_1_mat_add_0_0.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_control_s_axi.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_flow_control_loop_pipe_sequential_init.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_gmem_m_axi.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_im2col_mat_Pipeline_VITIS_LOOP_56_7.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mac_muladd_2ns_3ns_26ns_26_4_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mat_in_pad_V_RAM_AUTO_1R1W.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_3ns_3ns_6_1_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_3ns_32ns_35_2_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_5ns_6ns_11_1_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_6ns_3ns_9_1_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_6ns_35ns_41_2_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_6s_6s_12_1_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_7s_6s_11_1_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_9ns_3ns_12_1_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_9s_9s_18_1_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_18ns_41ns_59_2_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_mul_5ns_11s_11_4_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_mul_12s_6s_16_4_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_mul_15ns_12ns_26_4_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_sdiv_8s_3s_8_12_seq_1.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat.v" \
  "../../../bd/design_1/ip/design_1_im2col_mat_0_0/sim/design_1_im2col_mat_0_0.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/4c18/hdl/verilog/relu_control_s_axi.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/4c18/hdl/verilog/relu_gmem_m_axi.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/4c18/hdl/verilog/relu.v" \
  "../../../bd/design_1/ip/design_1_relu_0_0/sim/design_1_relu_0_0.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b8b3/hdl/verilog/quantization_control_s_axi.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b8b3/hdl/verilog/quantization_gmem_m_axi.v" \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b8b3/hdl/verilog/quantization.v" \
  "../../../bd/design_1/ip/design_1_quantization_0_0/sim/design_1_quantization_0_0.v" \
-endlib
-makelib xcelium_lib/generic_baseblocks_v2_1_0 \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_register_slice_v2_1_25 \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/e1e6/hdl/axi_register_slice_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/fifo_generator_v13_2_6 \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/8ae1/simulation/fifo_generator_vlog_beh.v" \
-endlib
-makelib xcelium_lib/fifo_generator_v13_2_6 \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/8ae1/hdl/fifo_generator_v13_2_rfs.vhd" \
-endlib
-makelib xcelium_lib/fifo_generator_v13_2_6 \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/8ae1/hdl/fifo_generator_v13_2_rfs.v" \
-endlib
-makelib xcelium_lib/axi_data_fifo_v2_1_24 \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/fa53/hdl/axi_data_fifo_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_crossbar_v2_1_26 \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ac57/hdl/axi_crossbar_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_xbar_0/sim/design_1_xbar_0.v" \
-endlib
-makelib xcelium_lib/axi_protocol_converter_v2_1_25 \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/8fe4/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_auto_pc_0/sim/design_1_auto_pc_0.v" \
-endlib
-makelib xcelium_lib/lib_cdc_v1_0_2 \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \
-endlib
-makelib xcelium_lib/proc_sys_reset_v5_0_13 \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_rst_ps7_0_50M_0/sim/design_1_rst_ps7_0_50M_0.vhd" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_xbar_1/sim/design_1_xbar_1.v" \
-endlib
-makelib xcelium_lib/axi_clock_converter_v2_1_24 \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/23c0/hdl/axi_clock_converter_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/blk_mem_gen_v8_4_5 \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/25a8/simulation/blk_mem_gen_v8_4.v" \
-endlib
-makelib xcelium_lib/axi_dwidth_converter_v2_1_25 \
  "../../../../final1.gen/sources_1/bd/design_1/ipshared/38b4/hdl/axi_dwidth_converter_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_auto_us_0/sim/design_1_auto_us_0.v" \
  "../../../bd/design_1/ip/design_1_auto_us_1/sim/design_1_auto_us_1.v" \
  "../../../bd/design_1/ip/design_1_auto_us_2/sim/design_1_auto_us_2.v" \
  "../../../bd/design_1/ip/design_1_auto_us_3/sim/design_1_auto_us_3.v" \
  "../../../bd/design_1/ip/design_1_auto_us_4/sim/design_1_auto_us_4.v" \
  "../../../bd/design_1/ip/design_1_auto_us_5/sim/design_1_auto_us_5.v" \
  "../../../bd/design_1/ip/design_1_auto_pc_1/sim/design_1_auto_pc_1.v" \
  "../../../bd/design_1/sim/design_1.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  glbl.v
-endlib

